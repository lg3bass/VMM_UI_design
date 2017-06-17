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
    
    

    
    //section S1 - width 250
    ofVec2f S1 = ofVec2f(0,0);
    
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
 
    
    float rowH = tracks->getHeight();
    
    //section S2 - width 200 (250-450)
    ofVec2f S2 = ofVec2f(250,0);
    //ofVec2f S2 = ofVec2f(S1.x+tracks->getWidth(),0);

    //ROW 1
    breadcrumb = new ofxDatGuiLabel("SETTINGS > Clip 2 > Matcap");
    breadcrumb->setTheme(new ofxDatGuiThemeVMM);
    breadcrumb->setWidth(200);
    breadcrumb->setHeight(rowH);
    breadcrumb->setPosition(S2.x, rowH*0);
    breadcrumb->setLabelMargin(10);
    breadcrumb->setLabelAlignment(ofxDatGuiAlignment::LEFT);
    
    //ROW 2
    selKey = new ofxDatGuiLabel("SEL KEY");
    selKey->setTheme(new ofxDatGuiThemeVMM);
    selKey->setWidth(50);
    selKey->setHeight(rowH);
    selKey->setPosition(S2.x, rowH*1);
    selKey->setLabelMargin(10);
    selKey->setLabelAlignment(ofxDatGuiAlignment::LEFT);
    
    selPrev = new ofxDatGuiButton("<");
    selPrev->setTheme(new ofxDatGuiThemeVMM);
    selPrev->setWidth(25);
    selPrev->setHeight(rowH);
    selPrev->setPosition(S2.x+selKey->getWidth(), rowH*1);
    selPrev->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    selNext = new ofxDatGuiButton(">");
    selNext->setTheme(new ofxDatGuiThemeVMM);
    selNext->setWidth(25);
    selNext->setHeight(rowH);
    selNext->setPosition(S2.x+selKey->getWidth()+selPrev->getWidth(), rowH*1);
    selNext->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    keyVal = new ofxDatGuiTextInput("", "45.0");
    keyVal->setTheme(new ofxDatGuiThemeVMM);
    keyVal->setWidth(50,0.0);
    keyVal->setHeight(rowH);
    keyVal->setPosition(S2.x+selKey->getWidth()+selPrev->getWidth()+selNext->getWidth(), rowH*1);
    keyVal->setLabelMargin(0);
    keyVal->setLabelAlignment(ofxDatGuiAlignment::CENTER);

    clamp = new ofxDatGuiLabel("CLAMP");
    clamp->setTheme(new ofxDatGuiThemeVMM);
    clamp->setWidth(50);
    clamp->setHeight(rowH);
    clamp->setPosition(S2.x+selKey->getWidth()+selPrev->getWidth()+selNext->getWidth()+keyVal->getWidth(), rowH*1);
    clamp->setLabelMargin(0);
    clamp->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    //ROW 3
    saveOptions.push_back("SAVE");
    saveOptions.push_back("SAVE ALL");
    saveOptions.push_back("SAVE AS");
    loadOptions.push_back("LOAD");
    loadOptions.push_back("LOAD ALL");
    
    //save/load dropdowns
    saveDropdown = new ofxDatGuiDropdown("SAVE",saveOptions);
    saveDropdown->setTheme(new ofxDatGuiThemeVMM);
    saveDropdown->setWidth(100.0,60.0);
    saveDropdown->setHeight(rowH);
    saveDropdown->setPosition(S2.x, rowH*2);
    
    
    loadDropdown = new ofxDatGuiDropdown("LOAD",loadOptions);
    loadDropdown->setTheme(new ofxDatGuiThemeVMM);
    loadDropdown->setWidth(100.0);
    loadDropdown->setHeight(rowH);
    loadDropdown->setPosition(S2.x+saveDropdown->getWidth(), rowH*2);
    
    
    //section S3 - width 300 (450-750)
    ofVec2f S3 = ofVec2f(450,0);
    
    //ROW 1
    measures = new ofxDatGuiTextInput("MEASURES", "8");
    measures->setTheme(new ofxDatGuiThemeVMM);
    measures->setWidth(75,50.0);
    measures->setHeight(tracks->getHeight());
    measures->setPosition(S3.x, S3.y);
    measures->setLabelMargin(0);
    measures->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    bpm = new ofxDatGuiTextInput("BPM", "120");
    bpm->setTheme(new ofxDatGuiThemeVMM);
    bpm->setWidth(75,30.0);
    bpm->setHeight(tracks->getHeight());
    bpm->setPosition(S3.x+measures->getWidth(), S3.y);
    bpm->setLabelMargin(0);
    bpm->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    fps = new ofxDatGuiTextInput("FPS", "30");
    fps->setTheme(new ofxDatGuiThemeVMM);
    fps->setWidth(75,30.0);
    fps->setHeight(tracks->getHeight());
    fps->setPosition(S3.x+measures->getWidth()+bpm->getWidth(), S3.y);
    fps->setLabelMargin(0);
    fps->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    loop = new ofxDatGuiTextInput("LOOP", "30");
    loop->setTheme(new ofxDatGuiThemeVMM);
    loop->setWidth(75,30.0);
    loop->setHeight(tracks->getHeight());
    loop->setPosition(S3.x+measures->getWidth()+bpm->getWidth()+fps->getWidth(), S3.y);
    loop->setLabelMargin(0);
    loop->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    //
    
    
    ofVec2f S4 = ofVec2f(750,0);

    
    BBF = new ofxDatGuiLabel("Bar|Beat|Frame");
    BBF->setTheme(new ofxDatGuiThemeVMM);
    BBF->setWidth(100);
    BBF->setHeight(tracks->getHeight());
    BBF->setPosition(S4.x, S4.y);
    BBF->setLabelMargin(0);
    BBF->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    bar = new ofxDatGuiTextInput("","8");
    bar->setTheme(new ofxDatGuiThemeVMM);
    bar->setWidth(50, 0.0);
    bar->setHeight(tracks->getHeight());
    bar->setPosition(S4.x+BBF->getWidth(), S4.y);
    bar->setLabelMargin(0);
    bar->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    beat = new ofxDatGuiTextInput("","3");
    beat->setTheme(new ofxDatGuiThemeVMM);
    beat->setWidth(50, 0.0);
    beat->setHeight(tracks->getHeight());
    beat->setPosition(S4.x+BBF->getWidth()+bar->getWidth(), S4.y);
    beat->setLabelMargin(0);
    beat->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    
    
    
    frame = new ofxDatGuiTextInput("","234");
    frame->setTheme(new ofxDatGuiThemeVMM);
    frame->setWidth(50, 0.0);
    frame->setHeight(tracks->getHeight());
    frame->setPosition(S4.x+BBF->getWidth()+bar->getWidth()+beat->getWidth(), S4.y);
    frame->setLabelMargin(0);
    frame->setLabelAlignment(ofxDatGuiAlignment::CENTER);
    
    ofVec2f S5 = ofVec2f(1000,0);

    
    linkSlider = new ofxDatGuiSlider("LINK",0.0,1.0,0.65);
    linkSlider->setTheme(new ofxDatGuiThemeVMM);
    linkSlider->setWidth(ofGetWidth()-S5.x, 0);
    linkSlider->setHeight(tracks->getHeight());
    linkSlider->setPosition(S5.x,S5.y);
    
    
    

    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    
    //panels
    headerPanel.update();
    bodyPanel.update();
    footerPanel.update();
    
    //S1
    tracks->setPosition(0, 0);
    tracks->update();
    pages->setPosition(0, tracks->getHeight());
    pages->update();
    clips->setPosition(0, tracks->getHeight()+pages->getHeight());
    clips->update();
    
    //S2
    breadcrumb->update();
    selKey->update();
    selPrev->update();
    selNext->update();
    keyVal->update();
    clamp->update();
    
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
    
    //S1
    
    tracks->draw();
    pages->draw();
    clips->draw();
    
    //S2
    breadcrumb->draw();
    selKey->draw();
    selPrev->draw();
    selNext->draw();
    keyVal->draw();
    clamp->draw();
    
    
    
    //S3

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
