///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-1-ga36064b9)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/filepicker.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/button.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("KML to KMZ"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,400 ), long style = wxCAPTION|wxDEFAULT_FRAME_STYLE|wxFRAME_SHAPED|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MainPanel
///////////////////////////////////////////////////////////////////////////////
class MainPanel : public wxPanel
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxPanel* panel_kml;
		wxStaticText* m_staticText3;
		wxPanel* panel_koordinat;
		wxStaticText* m_staticText31;

	public:
		wxTextCtrl* text_label;
		wxNotebook* m_notebook1;
		wxFilePickerCtrl* m_kml_file;
		wxTextCtrl* m_koordinat_text;
		wxDirPickerCtrl* m_dir_output;
		wxButton* btn_submit;

		MainPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,400 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~MainPanel();

};

