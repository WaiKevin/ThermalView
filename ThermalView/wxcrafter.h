//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef WXCRAFTER_BASE_CLASSES_H
#define WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include "wximageview.h"
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/arrstr.h>

class MainDialogBaseClass : public wxDialog
{
protected:
    wxImageView* m_picture;
    wxImageView* m_gradient;
    wxButton* m_button_connect;
    wxButton* m_button_stop;
    wxButton* m_button_take_one;
    wxButton* m_button_get_cal;
    wxCheckBox* m_check_use_extra_cal;
    wxChoice* m_lb_profile;
    wxButton* m_button_save;
    wxChoice* m_lb_sizes;

protected:
    virtual void OnButton_connectButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButton_stopButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButton_take_oneButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButton_get_calButtonClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnCheck_use_extra_calCheckboxClicked(wxCommandEvent& event) { event.Skip(); }
    virtual void OnLb_profileChoiceSelected(wxCommandEvent& event) { event.Skip(); }
    virtual void OnButton_saveButtonClicked(wxCommandEvent& event) { event.Skip(); }

public:
    MainDialogBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Thermal View"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(615,400), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX);
    virtual ~MainDialogBaseClass();
};

#endif
