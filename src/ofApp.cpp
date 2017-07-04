#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //panels setup
    int headerH =   HEADER_PANEL_HEIGHT * ofGetHeight();
    int bodyH =     BODY_PANEL_HEIGHT * ofGetHeight();
    int footerH =   FOOTER_PANEL_HEIGHT * ofGetHeight();
    
    headerPanel.setup(0, 0, ofGetWidth(), headerH, ofGetAppPtr());
    timePanel.setup(0, headerH, ofGetWidth(), bodyH, ofGetAppPtr());
    footerPanel.setup(0,headerH+bodyH,ofGetWidth(), footerH, ofGetAppPtr());
    
    myAppData.selected_panel_name = "NONE";
    myAppData.txt_color = ofColor::brown;
    
    //initialize myCtrlData
    resetControllerData();
    
    
    verdana30.load("verdana.ttf", 30, true, true);
    verdana30.setLineHeight(34.0f);
    verdana30.setLetterSpacing(1.035);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //panels
    headerPanel.update();
    timePanel.update();
    footerPanel.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("fps: "+ofToString(ofGetFrameRate())+" - "+ofToString(ofGetWidth())+","+ofToString(ofGetHeight()));
    
    
    //panels
    headerPanel.draw();
    timePanel.draw();
    footerPanel.draw();
    
    string msg = "SELECTED PANEL:" + myAppData.selected_panel_name;
    
    ofRectangle bounds = verdana30.getStringBoundingBox(msg, 0, 0);
    
    ofPushStyle();
        ofSetColor(myAppData.txt_color);
        //verdana30.drawString(msg, ofGetWidth()/2-bounds.width/2, ofGetHeight()/2-bounds.height/2);
    ofPopStyle();
    
    setBreadcrumb();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    headerPanel.keyPressed(key);
    timePanel.keyPressed(key);
    footerPanel.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    timePanel.keyReleased(key);    
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
    timePanel.mousePressed(x, y, button);
    footerPanel.mousePressed(x, y, button);
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    headerPanel.mouseReleased(x, y, button);
    timePanel.mouseReleased(x, y, button);
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



//--------------------------------------------------------------
void ofApp::setControllerData(string name, int data){
    
    if (name == "TRACK") {

        timePanel.data.setTrack(data);
        headerPanel.setClip(timePanel.data.getClip(data));
        headerPanel.setPage(timePanel.data.getPage(data));
        
    } else if(name == "PAGES") {
        timePanel.data.setPage(data);
    } else if(name == "CLIP"){
        timePanel.data.setClip(data);
    }    
    
}

//--------------------------------------------------------------
void ofApp::setBreadcrumb(){
    
    string selTrackOnPage = "";
    
    if(timePanel.data.getNumOfTimelinesInPage() > 0) {
        
        selTrackOnPage = timePanel.data.getSelectedTimelineOnPage(timePanel.data.getSelectedPage());
        
    } else {
        
        selTrackOnPage = "NULL";
    }
    
    string breadcrumbMsg = "CLIP " + ofToString(timePanel.data.getClip()+1) + " > PAGE " + ofToString(timePanel.data.getPage()+1) + " > " + ofToString(selTrackOnPage);

    headerPanel.mainUI.breadcrumb->setLabel(breadcrumbMsg);
    
}

//--------------------------------------------------------------
void ofApp::addTLTrack(string name, int type){
    
    timePanel.addtlTrack(name, type);
    
}

//--------------------------------------------------------------
void ofApp::resetControllerData(){
    myCtrlData.selected_track = 1;
    myCtrlData.selected_clip = 1;
    myCtrlData.selected_page = 1;
    
    myCtrlData.measures = 4;
    myCtrlData.bpm = 120;
    myCtrlData.fps = 30;
    myCtrlData.loop = 300;
    myCtrlData.mBeats = 4;
    myCtrlData.mUnits = 4;
    myCtrlData.bar = 0;
    myCtrlData.beat = 0;
    myCtrlData.frame = 0;
    
    myCtrlData.snap = true;
    myCtrlData.drive = true;
    myCtrlData.osc = true;
    
}
