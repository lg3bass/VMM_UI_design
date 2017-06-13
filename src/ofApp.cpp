#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //panels setup
    int headerH =   HEADER_PANEL_HEIGHT * ofGetHeight();
    int bodyH =     BODY_PANEL_HEIGHT * ofGetHeight();
    int footerH =   FOOTER_PANEL_HEIGHT * ofGetHeight();
    
    headerPanel.setup(0, 0, ofGetWidth(), headerH, ofGetAppPtr());
    bodyPanel.setup(0, headerH, ofGetWidth(), bodyH, ofGetAppPtr());
    footerPanel.setup(0,headerH+bodyH,ofGetWidth(), footerH, ofGetAppPtr());
    
    myAppData.selected_panel_name = "NONE";
    myAppData.txt_color = ofColor::brown;
    
    verdana30.load("verdana.ttf", 30, true, true);
    verdana30.setLineHeight(34.0f);
    verdana30.setLetterSpacing(1.035);
    
    // instantiate a matrix with a button for each box in our grid //
    tracks = new ofxDatGuiMatrix("TRACK", 10, true);
    pages = new ofxDatGuiMatrix("PAGE", 10, true);
    clips = new ofxDatGuiMatrix("CLIP", 10, true);
    
    //set the theme
    tracks->setTheme(new ofxDatGuiThemeVMM());
    pages->setTheme(new ofxDatGuiThemeVMM());
    clips->setTheme(new ofxDatGuiThemeVMM());
    
    // matrices can also function as radio buttons (only 1 on at a time)
    tracks->setRadioMode(true);
    pages->setRadioMode(true);
    clips->setRadioMode(true);
    
    // reduce the component opacity so it's easier to see behind it //
    tracks->setOpacity(.75);
    pages->setOpacity(.75);
    clips->setOpacity(.75);
    
    float matrixWidth = 250.0;
    
    tracks->setWidth(matrixWidth, 60.0);
    pages->setWidth(matrixWidth, 60.0);
    clips->setWidth(matrixWidth, 60.0);
    
    tracks->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    pages->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    clips->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    //tracks->setLabelMargin(10.0);
    
    
    save = new ofxDatGuiButton("SAVE");
    save->setTheme(new ofxDatGuiThemeVMM);
    save->setWidth(50);
    save->setHeight(tracks->getHeight());
    save->setPosition(tracks->getWidth(), 0);
    save->setLabelMargin(0);
    save->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    saveAll = new ofxDatGuiButton("SAVE ALL");
    saveAll->setTheme(new ofxDatGuiThemeVMM);
    saveAll->setWidth(50);
    saveAll->setHeight(tracks->getHeight());
    saveAll->setPosition(tracks->getWidth()+save->getWidth(), 0);
    saveAll->setLabelMargin(0);
    saveAll->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    load = new ofxDatGuiButton("SAVE");
    load->setTheme(new ofxDatGuiThemeVMM);
    load->setWidth(50);
    load->setHeight(tracks->getHeight());
    load->setPosition(tracks->getWidth()+save->getWidth()+saveAll->getWidth(), 0);
    load->setLabelMargin(0);
    load->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    loadAll = new ofxDatGuiButton("SAVE ALL");
    loadAll->setTheme(new ofxDatGuiThemeVMM);
    loadAll->setWidth(50);
    loadAll->setHeight(tracks->getHeight());
    loadAll->setPosition(tracks->getWidth()+save->getWidth()+saveAll->getWidth()+loadAll->getWidth(), 0);
    loadAll->setLabelMargin(0);
    loadAll->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    measures = new ofxDatGuiTextInput("MM", "8");
    measures->setTheme(new ofxDatGuiThemeVMM);
    measures->setWidth(50,20.0);
    measures->setHeight(tracks->getHeight());
    measures->setPosition(tracks->getWidth(), tracks->getHeight());
    measures->setLabelMargin(0);
    measures->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    

}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    
    //panels
    headerPanel.update();
    bodyPanel.update();
    footerPanel.update();
    
    tracks->setPosition(0, 0);
    tracks->update();
    pages->setPosition(0, tracks->getHeight());
    pages->update();
    clips->setPosition(0, tracks->getHeight()+pages->getHeight());
    clips->update();
    
    save->update();
    saveAll->update();
    load->update();
    loadAll->update();
    
    measures->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("fps: "+ofToString(ofGetFrameRate())+" - "+ofToString(ofGetWidth())+","+ofToString(ofGetHeight()));
    
    
    //panels
    headerPanel.draw();
    bodyPanel.draw();
    footerPanel.draw();
    
    string msg = "SELECTED PANEL:" + myAppData.selected_panel_name;
    
    ofRectangle bounds = verdana30.getStringBoundingBox(msg, 0, 0);
    
    ofPushStyle();
        ofSetColor(myAppData.txt_color);
        //verdana30.drawString(msg, ofGetWidth()/2-bounds.width/2, ofGetHeight()/2-bounds.height/2);
    ofPopStyle();
    
    tracks->draw();
    pages->draw();
    clips->draw();
    
    save->draw();
    saveAll->draw();
    load->draw();
    loadAll->draw();

    measures->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    headerPanel.keyPressed(key);
    bodyPanel.keyPressed(key);
    footerPanel.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    headerPanel.mousePressed(x, y, button);
    bodyPanel.mousePressed(x, y, button);
    footerPanel.mousePressed(x, y, button);
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    headerPanel.mouseReleased(x, y, button);
    bodyPanel.mouseReleased(x, y, button);
    footerPanel.mouseReleased(x, y, button);
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
