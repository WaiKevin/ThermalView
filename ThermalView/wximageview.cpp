/* The MIT License (MIT)
 *
 * Copyright (c) 2015 Razvan C. Cojocariu (code@dumb.ro)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "wximageview.h"
#include <wx/dcbuffer.h>

IMPLEMENT_DYNAMIC_CLASS(wxImageView, wxControl);

BEGIN_EVENT_TABLE(wxImageView, wxControl)
	EVT_ERASE_BACKGROUND(wxImageView::OnEraseBackground)
	EVT_PAINT(wxImageView::OnPaint)
	EVT_SIZE(wxImageView::OnSize)
END_EVENT_TABLE()

wxImageView::wxImageView()
{
	m_zoom_type = ZOOM_KEEP_RATIO;
	m_quality = wxIMAGE_QUALITY_NORMAL;
}

wxImageView::wxImageView(wxWindow * parent, wxWindowID id)
	: wxControl(parent, id)
{
	m_zoom_type = ZOOM_KEEP_RATIO;
	m_quality = wxIMAGE_QUALITY_NORMAL;
}

wxImageView::~wxImageView()
{
}

void wxImageView::setImage(const wxImage & img)
{
	m_img = img;
	
	updateView();
}

void wxImageView::clearImage()
{
	m_img.Destroy();
	
	updateView();
}

void wxImageView::setZoomType(ZoomType zoom_type)
{
	m_zoom_type = zoom_type;
	
	updateView();
}

void wxImageView::setQuality(wxImageResizeQuality resize_quality)
{
	m_quality = resize_quality;

	updateView();
}

void wxImageView::OnSize(wxSizeEvent & event)
{
	if (m_img.IsOk())
	{
		updateView();
	}
}

void wxImageView::OnEraseBackground(wxEraseEvent & event)
{
	if (m_img.IsOk())
		return;			// Don't do any erasing if the image is ok, we'll take care of it during the paint event
	else
		event.Skip();
}

void wxImageView::OnPaint(wxPaintEvent & event)
{
	// If we don't have an image, don't paint it
	if (m_img.IsOk())
	{
		wxBufferedPaintDC dc(this);

		// Erase background
		dc.SetBackground(wxBrush(GetBackgroundColour(), wxSOLID));
		dc.Clear();
		
		// Get the client size
		int client_width;
		int client_height;

		GetClientSize(&client_width, &client_height);
		
		// Get the image size
		wxSize img_sz = m_img_scaled.GetSize();
		
		int padding_left = (client_width - img_sz.GetWidth()) / 2;
		int padding_top = (client_height - img_sz.GetHeight()) / 2;
		
		dc.DrawBitmap(m_img_scaled, padding_left, padding_top);
	}
	else
		event.Skip();
}


void wxImageView::updateView()
{
	if (m_img.IsOk())
	{
		// Get the client area
		int client_width;
		int client_height;

		GetClientSize(&client_width, &client_height);

		
		if (m_zoom_type == ZOOM_KEEP_RATIO)
		{
			// Figure out the size of the new image
			wxSize bsz = m_img.GetSize();

			int sz_x;
			int sz_y;
			
			// If the height would fit in, when the width would FILL the client width
			if ( bsz.GetHeight() * (static_cast<float>(client_width) / bsz.GetWidth()) <= client_height )
			{
				sz_x = client_width;
				sz_y = bsz.GetHeight() * (static_cast<float>(client_width) / bsz.GetWidth());
			}
			else
			{
				sz_x = bsz.GetWidth() * (static_cast<float>(client_height) / bsz.GetHeight());
				sz_y = client_height;
			}

			// Scale the image
			m_img_scaled = wxBitmap(m_img.Scale(sz_x, sz_y, m_quality));
		}
		else
		{
			m_img_scaled = wxBitmap(m_img.Scale(client_width, client_height, m_quality));
		}
	}
	
	// Refresh the control
	Refresh();
}