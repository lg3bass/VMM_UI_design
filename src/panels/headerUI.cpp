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
}

//--------------------------------------------------------------
void headerUI::onPageMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
}

//--------------------------------------------------------------
void headerUI::onClipMatrixInputEvent(ofxDatGuiMatrixEvent e){
    
}


