///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-1-ga36064b9)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "kmltool.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 250,400 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("KML to KMZ"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );
	m_staticText2->SetMinSize( wxSize( -1,30 ) );

	bSizer1->Add( m_staticText2, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Label") ), wxVERTICAL );

	text_label = new wxTextCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( text_label, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( sbSizer6, 1, wxALL|wxEXPAND, 5 );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	panel_kml = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( panel_kml, wxID_ANY, wxT("KML File"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL, 5 );

	m_kml_file = new wxFilePickerCtrl( panel_kml, wxID_ANY, wxEmptyString, wxT("Pilih KML File"), wxT("*.kml"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_USE_TEXTCTRL );
	bSizer6->Add( m_kml_file, 0, wxALIGN_TOP|wxALL|wxEXPAND, 5 );


	panel_kml->SetSizer( bSizer6 );
	panel_kml->Layout();
	bSizer6->Fit( panel_kml );
	m_notebook1->AddPage( panel_kml, wxT("KML"), true );
	panel_koordinat = new wxPanel( m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );

	m_staticText31 = new wxStaticText( panel_koordinat, wxID_ANY, wxT("Koordinat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer61->Add( m_staticText31, 0, wxALL, 5 );

	m_koordinat_text = new wxTextCtrl( panel_koordinat, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer61->Add( m_koordinat_text, 2, wxALL|wxEXPAND, 5 );


	panel_koordinat->SetSizer( bSizer61 );
	panel_koordinat->Layout();
	bSizer61->Fit( panel_koordinat );
	m_notebook1->AddPage( panel_koordinat, wxT("Koordinat"), false );

	bSizer1->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Output Folder") ), wxVERTICAL );

	m_dir_output = new wxDirPickerCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Tentukan folder output"), wxDefaultPosition, wxDefaultSize, wxDIRP_USE_TEXTCTRL );
	m_dir_output->SetToolTip( wxT("Tentukan Folder Output") );
	m_dir_output->SetHelpText( wxT("Tentukan Folder Output") );

	sbSizer1->Add( m_dir_output, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( sbSizer1, 0, wxALL|wxEXPAND, 5 );


	bSizer1->Add( 0, 0, 0, wxEXPAND, 5 );

	btn_submit = new wxButton( this, wxID_ANY, wxT("Proses"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1->Add( btn_submit, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer1->Add( 0, 0, 1, wxEXPAND, 5 );

	wxStaticText* m_version_text;
	m_version_text = new wxStaticText( this, wxID_ANY, wxT("v1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_version_text->Wrap( -1 );
	bSizer1->Add( m_version_text, 0, wxALIGN_CENTER, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxVERTICAL );
}

MainFrame::~MainFrame()
{
}
