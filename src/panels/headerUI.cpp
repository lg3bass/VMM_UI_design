//
//  headerUI.cpp
//  VMM_UI_design
//
//  Created by Robert White III on 6/19/17.
//
//

#include "headerUI.h"
#include "ofApp.h"

ofApp* uiMainApp;

//--------------------------------------------------------------
void headerUI::setup(ofBaseApp* appPtr){
    uiMainApp = dynamic_cast<ofApp*>(appPtr);
    
    setupGUI();

}

//--------------------------------------------------------------
void headerUI::update(){
    updateGUI();
    
}

//--------------------------------------------------------------
void headerUI::draw(){
    drawGUI();
    
}


//EVENTS
//--------------------------------------------------------------
void headerUI::onTrackMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
    uiMainApp->setControllerData(e.target->getName(), e.child);
    resetTrackDropdown();
    

}

//--------------------------------------------------------------
void headerUI::onPageMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
    uiMainApp->setControllerData(e.target->getName(), e.child);
    cout << "onPageMatrixInputEvent" << endl;
}

//--------------------------------------------------------------
void headerUI::onClipMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
    uiMainApp->setControllerData(e.target->getName(), e.child);
    cout << "onClipMatrixInputEvent" << endl;
}

//--------------------------------------------------------------
void headerUI::onDDInputEvent(ofxDatGuiDropdownEvent e){
    
    cout << "DD index selected: " << e.child << endl;
    add_type = e.child;
    
}

//--------------------------------------------------------------
void headerUI::onTextInputEvent(ofxDatGuiTextInputEvent e){
    
    cout << "text: " << e.text << endl;
    add_name = e.text;
    
}

//--------------------------------------------------------------
void headerUI::onButtonEvent(ofxDatGuiButtonEvent e){
    
    if(e.target->getName() == "+"){
        
        if(add_type > 0){
            if(add_name == "<<ENTER NAME>>") {
                cout << "you must enter a name." << endl;
            } else {
                uiMainApp->addTLTrack(add_name, add_type);
                resetTrackDropdown();
            }

        } else {
            cout << "you must select a track type." << endl;
            
            
            
            
        }

        
    } else if (e.target->getName() == "-"){
        cout << "remove track pressed" << endl;
        
        uiMainApp->remTLTrack();
        
    }
    
}

//--------------------------------------------------------------
void headerUI::resetTrackDropdown(){
    
    add_name = "<<ENTER NAME>>";
    add_type = 0;
    
    trackDropdown->select(add_type);
    trackName->setText(add_name);
    
    
}


