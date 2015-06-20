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

#ifndef wxImageView_H
#define wxImageView_H

#include <wx/wx.h>

class wxImageView : public wxControl
{
public:
	enum ZoomType { ZOOM_KEEP_RATIO, ZOOM_STRETCH };
	
private:
	wxImage m_img;
	wxBitmap m_img_scaled;
	ZoomType m_zoom_type;

public:
	DECLARE_DYNAMIC_CLASS(wxImageView);
	
	wxImageView();
	wxImageView(wxWindow * parent, wxWindowID id);
	virtual ~wxImageView();
	
	void setImage(const wxImage & img);
	void clearImage();
	
	void setZoomType(ZoomType zoom_type);
	
	void OnPaint(wxPaintEvent & event);
	void OnSize(wxSizeEvent & event);
	
	DECLARE_EVENT_TABLE();
	
private:
	void updateView();
};

#endif // wxImageView_H
