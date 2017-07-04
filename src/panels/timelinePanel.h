//
//  timelinePanel.h
//  PATTERN_shared_ptr
//
//  Created by Robert White III on 6/8/17.
//
//
#pragma once

#ifndef timelinePanel_h
#define timelinePanel_h

#include "ofMain.h"
#include "Panel.h"
#include "timelineData.h"

#endif /* timelinePanel_h */

class timelinePanel : public Panel{

public:

    
    void setup(int x, int y, int width, int height, ofBaseApp* appPtr);
    void update();
    void draw();
    void exit(){};
    
    void keyPressed(int key);
    void keyReleased(int key);
   
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void drawData();
    void drawTrackData(int _track);
    
    timelineData data;
    
    //GETTERS & SETTERS
    //int getTrack();
    //void setTrack(int _track);
    
    //int getClip(int _track);
    //int getClip();
    //void setClip(int _clip);
    
    //int getPage(int _track);
    //int getPage();
    //void setPage(int _page);
    
    bool getCuedToPlay(int _track);
    bool getCuedToPlay();
    void setCuedToPlay(int _track);
    
    void addtlTrack(string _name, int _type);
    
    void setPageTrack(int _tl);
    int getPageTrack(int _track);
    int getPageTrack();
    
private:
    
    ofTrueTypeFont	verdana9;
    
    
    ofColor bordCol;
    int bordWidth;


};
