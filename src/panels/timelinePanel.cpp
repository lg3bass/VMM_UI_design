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
    
    
    verdana9.load("verdana.ttf", 7, true, true);


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
    

    
}

//-------------------------------------------------
void timelinePanel::mousePressed(int x, int y, int button){
    if(y > _y && y < _y+_h){

        
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

    float ml = 60;
    float mt = 80;

    float h_unit = 105;
    float v_unit = 15;
    

    verdana9.drawString("TRACK:"     , 0, _y+mt+v_unit*0);
    verdana9.drawString("clip:"      , 0, _y+mt+v_unit*1);
    verdana9.drawString("page:"      , 0, _y+mt+v_unit*2);
    verdana9.drawString("cue:"       , 0, _y+mt+v_unit*3);
    verdana9.drawString("keys:", 0, _y+mt+v_unit*4);


    for(int i=0; i<NUMBER_OF_TRACKS;i++){

        verdana9.drawString(ofToString(i+1), i*100+ml, _y+mt+v_unit*0);
        verdana9.drawString(ofToString(getClip(i)+1), i*100+ml, _y+mt+v_unit*1);
        verdana9.drawString(ofToString(getPage(i)+1), i*100+ml, _y+mt+v_unit*2);
        verdana9.drawString(getCuedToPlay(i) ? "true" : "false", i*100+ml, _y+mt+v_unit*3);
        
        //data.timeline.keyframes.keys.size()
        
        
        string ky;
        for(int k=0; k<3;k++){
            
            
            ky += "["+ofToString(data.timeline.keyframes.keys[k].frm)+","+ofToString(data.timeline.keyframes.keys[k].val)+"],";
            
        }
        verdana9.drawString(ky, i*100+ml, _y+mt+v_unit*4);
        
    }

    drawTrackData(getTrack());
    
}

//-------------------------------------------------
void timelinePanel::drawTrackData(int _track){
    
    float ml = 60;
    float mt = 200;
    
    float h_unit = 105;
    float v_unit = 15;
    
    string tlt = "Timeline tracks in track " + ofToString(_track) + ":  " + ofToString(data.timeline.tracks[_track].tlTracks.size());
    
    verdana9.drawString(tlt, _x+ml, _y+mt);
    
    //cout << "Timeline tracks in track " << _track << ":  " << data.timeline.tracks[_track].tlTracks.size() << endl;
    
    
}



//-------------------------------------------------
int timelinePanel::getTrack(){
    return data.timeline.selected_track;
}

//-------------------------------------------------
void timelinePanel::setTrack(int _track){
    data.timeline.selected_track = _track;
}

//-------------------------------------------------
int timelinePanel::getClip(int _track){
    return data.timeline.tracks[_track].selected_clip;
}

//-------------------------------------------------
int timelinePanel::getClip(){
    return data.timeline.tracks[getTrack()].selected_clip;
}

//-------------------------------------------------
void timelinePanel::setClip(int _clip){
    data.timeline.tracks[getTrack()].selected_clip = _clip;
}

//-------------------------------------------------
int timelinePanel::getPage(int _track){
    return data.timeline.tracks[_track].selected_page;
}

//-------------------------------------------------
int timelinePanel::getPage(){
    return data.timeline.tracks[getTrack()].selected_page;
}

//-------------------------------------------------
void timelinePanel::setPage(int _page){
    data.timeline.tracks[getTrack()].selected_page = _page;
}

//-------------------------------------------------
bool timelinePanel::getCuedToPlay(int _track){
    return data.timeline.tracks[_track].cuedToPlay;
}

//-------------------------------------------------
bool timelinePanel::getCuedToPlay(){
    return data.timeline.tracks[getTrack()].cuedToPlay;
}

//-------------------------------------------------
void timelinePanel::addtlTrack(int _track){
    
    timelineData::track newTrack;
    newTrack.name = "test";
    newTrack.type = timelineData::trackType(2);
    
    data.timeline.tracks[_track].tlTracks.push_back(newTrack);
    
}
