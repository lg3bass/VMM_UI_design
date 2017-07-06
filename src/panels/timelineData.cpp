//
//  timelineData.cpp
//  VMM_UI_design
//
//  Created by Robert White III on 7/2/17.
//
//

#include "timelineData.h"

//-------------------------------------------------
timelineData::timelineData(){
    for(int i = 0;i<NUMBER_OF_TRACKS;i++){              //add blank tracks
        //add a track
        vmmTrack mytrack;
        mytrack.cuedToPlay = false;
        
        //add blank pages
        for(int p = 0;p<10;p++){
            
            page myPage;                                //add pages
            myPage.name = "PAGE_"+ofToString(p);
            myPage.selected_channel = 0;
            
            mytrack.tlPages.push_back(myPage);
            
            
        }
        
        //add test keys
        for(int k=0;k<3;k++){
            key kf;
            kf.frm = k*15;
            kf.val = 0;
            TL.keyframes.keys.push_back(kf);
        }
        
        
        TL.tracks.push_back(mytrack);
        
    }
}

//-------------------------------------------------
int timelineData::getTrack(){
    return TL.selected_track;
}

//-------------------------------------------------
void timelineData::setTrack(int _track){
    TL.selected_track = _track;
    
}

//-------------------------------------------------
int timelineData::getClip(int _track){
    return TL.tracks[_track].selected_clip;
}

//-------------------------------------------------
int timelineData::getClip(){
    return TL.tracks[getTrack()].selected_clip;
}

//-------------------------------------------------
void timelineData::setClip(int _clip){
    TL.tracks[getTrack()].selected_clip = _clip;
}

//-------------------------------------------------
int timelineData::getPage(int _track){
    return TL.tracks[_track].selected_page;
}

//-------------------------------------------------
int timelineData::getPage(){
    return TL.tracks[getTrack()].selected_page;
}

//-------------------------------------------------
void timelineData::setPage(int _page){
    TL.tracks[getTrack()].selected_page = _page;
}

//-------------------------------------------------
bool timelineData::getCuedToPlay(int _track){
    return TL.tracks[_track].cuedToPlay;
}

//-------------------------------------------------
bool timelineData::getCuedToPlay(){
    return TL.tracks[getTrack()].cuedToPlay;
}

//-------------------------------------------------
void timelineData::addtlTrack(string _name, int _type){
    
    channel newTrack;
    newTrack.name = _name;
    newTrack.type = channelType(_type);
    
    TL.tracks[getTrack()].tlPages[getPage()].tlChannels.push_back(newTrack);
    
}

//-------------------------------------------------
void timelineData::remtlTrack(){
    //note: currently this removes the current selected timeline and then selects index 0.
    int currentTrackOnPage = TL.tracks[getTrack()].tlPages[getPage()].selected_channel;
    
    //erase at index. (source: //stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index)
    TL.tracks[getTrack()].tlPages[getPage()].tlChannels.erase(TL.tracks[getTrack()].tlPages[getPage()].tlChannels.begin()+currentTrackOnPage);
    TL.tracks[getTrack()].tlPages[getPage()].selected_channel = 0;  //set selected to 0;
}


//-------------------------------------------------
int timelineData::getSelectedChannel(){
    return TL.tracks[getTrack()].tlPages[getPage()].selected_channel;
}

//-------------------------------------------------
void timelineData::setSelectedChannel(int _page){
    TL.tracks[getTrack()].tlPages[getPage()].selected_channel = _page;
    
    
    ofLog() << "Selected - Page " << ofToString(getPage()) << " Timeline " << getSelectedChannelName(_page);
    
}

//-------------------------------------------------
string timelineData::getSelectedChannelName(int _pageIndex){
    return TL.tracks[getTrack()].tlPages[getPage()].tlChannels[_pageIndex].name;
}


//-------------------------------------------------
int timelineData::getNumOfChannelsOnPage(){
    
    int currentTrack = TL.selected_track;
    
    int num_tracks_on_page = TL.tracks[getTrack()].tlPages[getPage()].tlChannels.size();
        
    return num_tracks_on_page;
    
}
