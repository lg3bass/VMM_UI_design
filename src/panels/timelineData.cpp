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
            myPage.selected_tlTrack = 0;
            
            mytrack.tlPages.push_back(myPage);
            
            
        }
        
        //add test keys
        for(int k=0;k<3;k++){
            key kf;
            kf.frm = k*15;
            kf.val = 0;
            timeline.keyframes.keys.push_back(kf);
        }
        
        
        timeline.tracks.push_back(mytrack);
        
    }
}

//-------------------------------------------------
int timelineData::getTrack(){
    return timeline.selected_track;
}

//-------------------------------------------------
void timelineData::setTrack(int _track){
    timeline.selected_track = _track;
    
}

//-------------------------------------------------
int timelineData::getClip(int _track){
    return timeline.tracks[_track].selected_clip;
}

//-------------------------------------------------
int timelineData::getClip(){
    return timeline.tracks[getTrack()].selected_clip;
}

//-------------------------------------------------
void timelineData::setClip(int _clip){
    timeline.tracks[getTrack()].selected_clip = _clip;
}

//-------------------------------------------------
int timelineData::getPage(int _track){
    return timeline.tracks[_track].selected_page;
}

//-------------------------------------------------
int timelineData::getPage(){
    return timeline.tracks[getTrack()].selected_page;
}

//-------------------------------------------------
void timelineData::setPage(int _page){
    timeline.tracks[getTrack()].selected_page = _page;
}

//-------------------------------------------------
bool timelineData::getCuedToPlay(int _track){
    return timeline.tracks[_track].cuedToPlay;
}

//-------------------------------------------------
bool timelineData::getCuedToPlay(){
    return timeline.tracks[getTrack()].cuedToPlay;
}

//-------------------------------------------------
void timelineData::addtlTrack(string _name, int _type){
    
    channel newTrack;
    newTrack.name = _name;
    newTrack.type = channelType(_type);
    
    timeline.tracks[getTrack()].tlPages[getPage()].tlTracks.push_back(newTrack);
    
}

//-------------------------------------------------
void timelineData::remtlTrack(){
    //note: currently this removes the current selected timeline and then selects index 0.
    int currentTrackOnPage = timeline.tracks[getTrack()].tlPages[getPage()].selected_tlTrack;
    
    //erase at index. (source: //stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index)
    timeline.tracks[getTrack()].tlPages[getPage()].tlTracks.erase(timeline.tracks[getTrack()].tlPages[getPage()].tlTracks.begin()+currentTrackOnPage);
    timeline.tracks[getTrack()].tlPages[getPage()].selected_tlTrack = 0;  //set selected to 0;
}

//TODO - change these functions getSelectedPage, setSelectedPage
//-------------------------------------------------
int timelineData::getSelectedPage(){
    return timeline.tracks[getTrack()].tlPages[getPage()].selected_tlTrack;
}

//-------------------------------------------------
void timelineData::setSelectedPage(int _page){    
    timeline.tracks[getTrack()].tlPages[getPage()].selected_tlTrack = _page;
    
    
    ofLog() << "Selected - Page " << ofToString(getPage()) << " Timeline " << getSelectedTimelineOnPage(_page);
    
}

//-------------------------------------------------
string timelineData::getSelectedTimelineOnPage(int _pageIndex){
    return timeline.tracks[getTrack()].tlPages[getPage()].tlTracks[_pageIndex].name;
}


//-------------------------------------------------
int timelineData::getNumOfTimelinesInPage(){
    
    int currentTrack = timeline.selected_track;
    
    int num_tracks_on_page = timeline.tracks[getTrack()].tlPages[getPage()].tlTracks.size();
        
    return num_tracks_on_page;
    
}
