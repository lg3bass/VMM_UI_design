//
//  timelineData.h
//  VMM_UI_design
//
//  Created by White, Bob on 6/22/17.
//
//
#pragma once

#define NUMBER_OF_TRACKS 10

#include "ofMain.h"

class timelineData{
    
public:
    
    
    enum trackType {tlCurves,tlKeyframes,tlMarkers};
    
    struct track {
        string name;
        trackType type;
    };
    
    struct page {
        string name;
        vector<track> tlTracks;
        int selected_track;
    };
    
    struct vmmTrack {
        vector<page> tlPages;
        int selected_clip = 0;
        int selected_page = 0;
        bool cuedToPlay;
    };

    struct key {
        int frm;
        float val;
    };
    
    struct tlData {
        int selected_track = 0;
        vector<vmmTrack> tracks;
        int measures = 4;
        int bpm = 120;
        int fps = 30;
        int loop = 300;
        int mBeats = 4;
        int mUnits = 4;
        int bar = 0;
        int beat = 0;
        int frame = 0;
        
        bool snap = false;
        bool drive = false;
        bool osc = false;
        struct keys{
            vector<key> keys;
            int selected_key;
            float clampL = 0.0;
            float clampH = 100.0;
        } keyframes;
        
    } timeline;
    
    
    //constuctor
    timelineData();
    
    //TODO - move all the data functions within.
    
    int getTrack();
    void setTrack(int _track);
    
    int getClip(int _track);
    int getClip();
    void setClip(int _clip);
    
    int getPage(int _track);
    int getPage();
    void setPage(int _page);
    
    int getSelectedPage();
    void setSelectedPage(int _page);
    string getSelectedTimelineOnPage(int _pageIndex);
    
    
    int getNumOfTimelinesInPage();
    
    
    
    

    

    
};
