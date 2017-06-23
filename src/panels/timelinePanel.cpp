//
//  timelinePanel.cpp
//  PATTERN_shared_ptr
//
//  Created by Robert White III on 6/8/17.
//
//

#include "timelinePanel.h"
#include "ofApp.h"

ofApp* bMainApp;

//-------------------------------------------------
void timelinePanel::setup(int x, int y, int width, int height, ofBaseApp* appPtr){
    
    bMainApp = dynamic_cast<ofApp*>(appPtr);
    
    _x = x;
    _y = y;
    _w = width;
    _h = height;
    
    //colors
    setBackgroundColor(ofColor::darkGray);
    setBorderColor(ofColor::mediumOrchid);
    setBorderWidth(2);
    
    

    
    //data.timeline.tracks[0].selected_page = 2;

}

//-------------------------------------------------
void timelinePanel::update(){
    
    
}

//-------------------------------------------------
void timelinePanel::draw(){
    
    drawPanel();
    
    drawData();
    
}

//-------------------------------------------------
void timelinePanel::keyPressed(int key){
    
    ofLog() << "BODY";
    
}

//-------------------------------------------------
void timelinePanel::mousePressed(int x, int y, int button){
    if(y > _y && y < _y+_h){
        //ofLog() << "body pressed";
        //setBackgroundColor(ofColor::yellow);
        
        bMainApp->myAppData.selected_panel_name = "BODY";
        bMainApp->myAppData.txt_color = ofColor::darkKhaki;
    }
    
    
}

//-------------------------------------------------
void timelinePanel::mouseReleased(int x, int y, int button){

    //ofLog() << "body released";
    //setBackgroundColor(ofColor::darkGray);

    
}

//-------------------------------------------------
void timelinePanel::drawData(){

    float ml = 80;
    float mt = 100;

    float h_unit = 100;
    float v_unit = 15;

    ofDrawBitmapString("TRACK:"     , 0, _y+mt+v_unit*0);
    ofDrawBitmapString("clip:"      , 0, _y+mt+v_unit*1);
    ofDrawBitmapString("page:"      , 0, _y+mt+v_unit*2);
    ofDrawBitmapString("cue:"       , 0, _y+mt+v_unit*3);
    ofDrawBitmapString("keys:", 0, _y+mt+v_unit*4);


    for(int i=0; i<NUMBER_OF_TRACKS;i++){

        ofDrawBitmapString(ofToString(i), i*100+ml, _y+mt+v_unit*0);
        ofDrawBitmapString(data.timeline.tracks[i].selected_clip, i*100+ml, _y+mt+v_unit*1);
        ofDrawBitmapString(data.timeline.tracks[i].selected_clip, i*100+ml, _y+mt+v_unit*2);
        ofDrawBitmapString(data.timeline.tracks[i].cuedToPlay ? "true" : "false", i*100+ml, _y+mt+v_unit*3);
        
        //data.timeline.keyframes.keys.size()
        
        for(int k=0; k<4;k++){
            string ky = "["+ofToString(data.timeline.keyframes.keys[k].frm)+","+ofToString(data.timeline.keyframes.keys[k].val)+"],";
            
            ofDrawBitmapString(ky, i*100+ml, _y+mt+v_unit*4);
            
        }
        
    }

    
}

//-------------------------------------------------
