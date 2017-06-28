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
void headerUI::onMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
    uiMainApp->setControllerData(e.target->getName(), e.child);
    add_type = -1;
    add_name = "";
}

//--------------------------------------------------------------
void headerUI::onPageMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
    
}

//--------------------------------------------------------------
void headerUI::onClipMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
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
        cout << "add track pressed" << endl;
        uiMainApp->addTLTrack("STINKBUT", 1);
        
    } else if (e.target->getName() == "-"){
        cout << "remove track pressed" << endl;
    }
    
}
