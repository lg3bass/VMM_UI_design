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
    

    saveOptions.push_back("SAVE");
    saveOptions.push_back("SAVE ALL");
    saveOptions.push_back("SAVE AS");
    loadOptions.push_back("LOAD");
    loadOptions.push_back("LOAD ALL");
    
    
    
    //save/load dropdowns
    saveDropdown = new ofxDatGuiDropdown("SAVE",saveOptions);
    saveDropdown->setTheme(new ofxDatGuiThemeVMM);
    saveDropdown->setWidth(100.0,60.0);
    saveDropdown->setHeight(tracks->getHeight());
    saveDropdown->setPosition(tracks->getWidth(), 0);
    
    
    loadDropdown = new ofxDatGuiDropdown("LOAD",loadOptions);
    loadDropdown->setTheme(new ofxDatGuiThemeVMM);
    loadDropdown->setWidth(100.0);
    loadDropdown->setHeight(tracks->getHeight());
    loadDropdown->setPosition(tracks->getWidth()+saveDropdown->getWidth(), 0);
    
    
    //discrete save/load buttons
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
    
    load = new ofxDatGuiButton("LOAD");
    load->setTheme(new ofxDatGuiThemeVMM);
    load->setWidth(50);
    load->setHeight(tracks->getHeight());
    load->setPosition(tracks->getWidth()+save->getWidth()+saveAll->getWidth(), 0);
    load->setLabelMargin(0);
    load->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    loadAll = new ofxDatGuiButton("LOAD ALL");
    loadAll->setTheme(new ofxDatGuiThemeVMM);
    loadAll->setWidth(50);
    loadAll->setHeight(tracks->getHeight());
    loadAll->setPosition(tracks->getWidth()+save->getWidth()+saveAll->getWidth()+loadAll->getWidth(), 0);
    loadAll->setLabelMargin(0);
    loadAll->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    
    //
    
    ofVec2f timingPanelPos = ofVec2f(tracks->getWidth()+saveDropdown->getWidth()+loadDropdown->getWidth(),0);
    
    measures = new ofxDatGuiTextInput("MEASURES", "8");
    measures->setTheme(new ofxDatGuiThemeVMM);
    measures->setWidth(75,50.0);
    measures->setHeight(tracks->getHeight());
    measures->setPosition(timingPanelPos.x, timingPanelPos.y);
    measures->setLabelMargin(0);
    measures->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    bpm = new ofxDatGuiTextInput("BPM", "120");
    bpm->setTheme(new ofxDatGuiThemeVMM);
    bpm->setWidth(75,30.0);
    bpm->setHeight(tracks->getHeight());
    bpm->setPosition(timingPanelPos.x+measures->getWidth(), timingPanelPos.y);
    bpm->setLabelMargin(0);
    bpm->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    fps = new ofxDatGuiTextInput("FPS", "30");
    fps->setTheme(new ofxDatGuiThemeVMM);
    fps->setWidth(75,30.0);
    fps->setHeight(tracks->getHeight());
    fps->setPosition(timingPanelPos.x+measures->getWidth()+bpm->getWidth(), timingPanelPos.y);
    fps->setLabelMargin(0);
    fps->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    loop = new ofxDatGuiTextInput("LOOP", "30");
    loop->setTheme(new ofxDatGuiThemeVMM);
    loop->setWidth(75,30.0);
    loop->setHeight(tracks->getHeight());
    loop->setPosition(timingPanelPos.x+measures->getWidth()+bpm->getWidth()+fps->getWidth(), timingPanelPos.y);
    loop->setLabelMargin(0);
    loop->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    //
    
    ofVec2f hud = ofVec2f(timingPanelPos.x+measures->getWidth()+bpm->getWidth()+fps->getWidth(),0);
    
    
    BBF = new ofxDatGuiLabel("Bar|Beat|Frame");
    BBF->setTheme(new ofxDatGuiThemeVMM);
    BBF->setWidth(100);
    BBF->setHeight(tracks->getHeight());
    BBF->setPosition(hud.x, hud.y);
    BBF->setLabelMargin(0);
    BBF->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    bar = new ofxDatGuiTextInput("","8");
    bar->setTheme(new ofxDatGuiThemeVMM);
    bar->setWidth(50, 0.0);
    bar->setHeight(tracks->getHeight());
    bar->setPosition(hud.x+BBF->getWidth(), hud.y);
    bar->setLabelMargin(0);
    bar->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    beat = new ofxDatGuiTextInput("","3");
    beat->setTheme(new ofxDatGuiThemeVMM);
    beat->setWidth(50, 0.0);
    beat->setHeight(tracks->getHeight());
    beat->setPosition(hud.x+BBF->getWidth()+bar->getWidth(), hud.y);
    beat->setLabelMargin(0);
    beat->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    
    
    frame = new ofxDatGuiTextInput("","234");
    frame->setTheme(new ofxDatGuiThemeVMM);
    frame->setWidth(50, 0.0);
    frame->setHeight(tracks->getHeight());
    frame->setPosition(hud.x+BBF->getWidth()+bar->getWidth()+beat->getWidth(), hud.y);
    frame->setLabelMargin(0);
    frame->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    ofVec2f linkHud = ofVec2f(hud.x+BBF->getWidth()+bar->getWidth()+beat->getWidth()+frame->getWidth(), 0);
    
    linkSlider = new ofxDatGuiSlider("LINK",0.0,1.0,0.65);
    linkSlider->setWidth(ofGetWidth()-linkHud.x-100, 10);
    linkSlider->setTheme(new ofxDatGuiThemeVMM);
    linkSlider->setPosition(linkHud.x,linkHud.y);
    
    
    
    //not used anymore.
    
    selTrack = new ofxDatGuiTextInput("TRACK","G Rotate X");
    selTrack->setTheme(new ofxDatGuiThemeVMM);
    selTrack->setWidth(200, 50.0);
    selTrack->setHeight(tracks->getHeight());
    selTrack->setPosition(hud.x, hud.y+BBF->getHeight());
    selTrack->setLabelMargin(0);
    selTrack->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    selKeys = new ofxDatGuiTextInput("KEYS","0,15,30,45,60,75");
    selKeys->setTheme(new ofxDatGuiThemeVMM);
    selKeys->setWidth(200, 50.0);
    selKeys->setHeight(tracks->getHeight());
    selKeys->setPosition(hud.x, hud.y+BBF->getHeight()+selTrack->getHeight());
    selKeys->setLabelMargin(0);
    selKeys->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    selValues = new ofxDatGuiTextInput("VALUES","0.0,100.0,100.0,45.0,0.0,0.0");
    selValues->setTheme(new ofxDatGuiThemeVMM);
    selValues->setWidth(200, 50.0);
    selValues->setHeight(tracks->getHeight());
    selValues->setPosition(hud.x, hud.y+BBF->getHeight()+selTrack->getHeight()+selKeys->getHeight());
    selValues->setLabelMargin(0);
    selValues->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
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
    

    
//    save->update();
//    saveAll->update();
//    load->update();
//    loadAll->update();
    
    measures->update();
    bpm->update();
    fps->update();
    loop->update();

    
    saveDropdown->update();
    loadDropdown->update();
    
    BBF->update();
    bar->update();
    beat->update();
    frame->update();
    
    linkSlider->update();
    
//    selTrack->update();
//    selKeys->update();
//    selValues->update();
    
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
    
//    save->draw();
//    saveAll->draw();
//    load->draw();
//    loadAll->draw();

    measures->draw();
    bpm->draw();
    fps->draw();
    loop->draw();
    
    saveDropdown->draw();
    loadDropdown->draw();
    
    BBF->draw();
    bar->draw();
    beat->draw();
    frame->draw();
    
    linkSlider->draw();
    
//    selTrack->draw();
//    selKeys->draw();
//    selValues->draw();

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
