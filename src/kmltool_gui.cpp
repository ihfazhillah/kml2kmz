#include <wx/wx.h>
#include <iostream>
#include <string>

#include "../lib/ui/kmltool.h"
#include <wx/event.h>
#include "reader.h"

class KMLToolController {
    public:
        MainFrame * view;
        KMLToolController(MainFrame*);
        void OnSubmit(wxCommandEvent &);

        void show(){
            this->view->Show(true);
        }
};


class KMLToolApp: public wxApp{
    public: 
        KMLToolController *controller;
        bool OnInit() override;
};


wxIMPLEMENT_APP(KMLToolApp);

bool KMLToolApp::OnInit(){
    MainFrame * view = new MainFrame(nullptr);
    this->controller = new KMLToolController(view);
    this->controller->show();
    return true;
}

KMLToolController::KMLToolController(MainFrame * view){
    this->view = view;
    this->view->btn_submit->Bind(wxEVT_BUTTON, &KMLToolController::OnSubmit, this);
}


void KMLToolController::OnSubmit(wxCommandEvent &event){
    std::string label = this->view->text_label->GetValue().ToStdString();
    std::string output_dir = this->view->m_dir_output->GetTextCtrlValue().ToStdString();
    int notebook_selection = this->view->m_notebook1->GetSelection();

    if (notebook_selection == 0)
    {
        // kml -> kmz
        std::string kml_path = this->view->m_kml_file->GetTextCtrlValue().ToStdString();
        coordinates coordinate_items = get_coordinates(kml_path);
        mkdir(label.c_str(), 0777);
        for (int i = 0; i < coordinate_items.size; i++)
        {
            wxYield();
            std::string compiled_coordinate = compile_coordinate(coordinate_items.items[i]);
            save_coordinate(
                compiled_coordinate,
                label,
                output_dir,
                i
            );
        }
        
    } else {
        // coordinate -> kmz

        int index = 0;
        std::string coordinate = this->view->m_koordinat_text->GetValue().ToStdString();
        save_coordinate(
            coordinate,
            label,
            output_dir,
            index
        );
    }
    

    std::cout << this->view->text_label->GetValue() << std::endl;
    std::cout << this->view->m_kml_file->GetTextCtrlValue() << std::endl;  
    std::cout << this->view->m_dir_output->GetTextCtrlValue() << std::endl;  
    std::cout << this->view->m_notebook1->GetSelection() << std::endl;  


    
    std::cout << "Hello world" << std::endl;

}
