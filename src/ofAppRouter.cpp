#include "ofApp.h"


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
    
    if(timePanel.data.getNumOfChannelsOnPage() > 0) {
        
        selTrackOnPage = timePanel.data.getSelectedChannelName(timePanel.data.getSelectedChannel());
        
    } else {
        
        selTrackOnPage = "NULL";
    }
    
    string breadcrumbMsg = "CLIP " + ofToString(timePanel.data.getClip()+1) + " > PAGE " + ofToString(timePanel.data.getPage()+1) + " > " + ofToString(selTrackOnPage);
    
    headerPanel.mainUI.breadcrumb->setLabel(breadcrumbMsg);
    
}

//--------------------------------------------------------------
void ofApp::addTLTrack(string name, int type){
    
    timePanel.data.addtlTrack(name, type);
    
}

//--------------------------------------------------------------
void ofApp::remTLTrack(){
    
    if(timePanel.data.getNumOfChannelsOnPage()> 0){
        
        timePanel.data.remtlTrack();
        
    }
}

//--------------------------------------------------------------
void ofApp::nextKey(){
    timePanel.data.setNextKey();
}

//--------------------------------------------------------------
void ofApp::prevKey(){
    timePanel.data.setPrevKey();
}

//--------------------------------------------------------------
void ofApp::setKeyVal(int _val){
    timePanel.data.setSelectedKeyValue(_val);
    
}
