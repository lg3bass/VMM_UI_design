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

    
    // setup a resolution for a grid //
    numCols = 1;
    numRows = 10;
    ofSetWindowPosition(0, 0);
    font.load("ofxbraitsch/fonts/Verdana.ttf", 12);
    
    // instantiate a matrix with a button for each box in our grid //
    tracks = new ofxDatGuiMatrix("TRACK", numCols*numRows, true);
    pages = new ofxDatGuiMatrix("PAGE", numCols*numRows, true);
    clips = new ofxDatGuiMatrix("CLIP", numCols*numRows, true);
    
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
    
    tracks->setWidth(260.0, 60.0);
    pages->setWidth(260.0, 60.0);
    clips->setWidth(260.0, 60.0);

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
        verdana30.drawString(msg, ofGetWidth()/2-bounds.width/2, ofGetHeight()/2-bounds.height/2);
    ofPopStyle();
    
    tracks->draw();
    pages->draw();
    clips->draw();
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
