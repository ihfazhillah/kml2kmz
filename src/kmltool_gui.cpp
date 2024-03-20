#include <wx/wx.h>
#include <iostream>
#include <string>
#include <filesystem>

#include "../lib/ui/kmltool.h"
#include <wx/event.h>
#include "reader.h"

class KMLToolController {
    public:
        MainPanel * view;
        KMLToolController(MainPanel*);
        void OnSubmit(wxCommandEvent &);

        void show(){
            this->view->Show(true);
        }
};


class KMLToolApp: public wxApp{
    public: 
        KMLToolController *controller;
        bool OnInit() override;
        virtual int OnExit() override;
};


wxIMPLEMENT_APP(KMLToolApp);

bool KMLToolApp::OnInit(){
    MainFrame * view = new MainFrame(nullptr);
    MainPanel * panel = new MainPanel(view);
    this->controller = new KMLToolController(panel);

    // default directory
    std::string curdir = std::filesystem::current_path().string();
    panel->m_dir_output->SetDirName(wxFileName(curdir));

    this->controller->show();
    return true;
}

int KMLToolApp::OnExit(){
    delete this->controller;
    return 0;
}

KMLToolController::KMLToolController(MainPanel * view){
    this->view = view;
    this->view->btn_submit->Bind(wxEVT_BUTTON, &KMLToolController::OnSubmit, this);
}


void KMLToolController::OnSubmit(wxCommandEvent &event){
    std::string label = this->view->text_label->GetValue().ToStdString();

    if (label.empty())
    {
        wxMessageBox("Label tidak boleh kosong.", "Error", wxOK | wxICON_ERROR, this->view);
        return;
    }

    std::string output_dir = this->view->m_dir_output->GetTextCtrlValue().ToStdString();
    if (output_dir.empty())
    {
        wxMessageBox("Output directory tidak boleh kosong.", "Error", wxOK | wxICON_ERROR, this->view);
        return;
    }

    int notebook_selection = this->view->m_notebook1->GetSelection();

    if (notebook_selection == 0)
    {

        // kml -> kmz
        std::string kml_path = this->view->m_kml_file->GetTextCtrlValue().ToStdString();
        if (kml_path.empty())
        {
            wxMessageBox("KML file tidak boleh kosong.", "Error", wxOK | wxICON_ERROR, this->view);
            return;
        }

        coordinates coordinate_items = get_coordinates(kml_path);

        #ifdef _WIN32
        mkdir(label.c_str());
        #else 
        mkdir(label.c_str(), 0777);
        #endif
        
        for (int i = 0; i < coordinate_items.size; i++)
        {
            wxYield();
            std::string compiled_coordinate = compile_coordinate(coordinate_items.items[i]);
            save_coordinate(
                compiled_coordinate,
                label,
                output_dir,
                i);
        }
    }
    else
    {
        // coordinate -> kmz

        int index = 0;
        std::string coordinate = this->view->m_koordinat_text->GetValue().ToStdString();
        if (coordinate.empty())
        {
            wxMessageBox("coordinate tidak boleh kosong.", "Error", wxOK | wxICON_ERROR, this->view);
            return;
        }
        save_coordinate(
            coordinate,
            label,
            output_dir,
            index);
    }

    wxMessageBox("Konversi Sukses",
                 "Sukses", wxOK | wxICON_INFORMATION, this->view);
}
