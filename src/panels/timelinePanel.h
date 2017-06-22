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

#endif /* timelinePanel_h */



struct kf {
    int frm;
    int val;
};

struct timlineData{
    vector<kf> keys;
    int selected_key;
    float clampL;
    float clampH;
    
    bool snap;
    bool drive;
    bool osc;
    
};


class timelinePanel : public Panel{

public:
    
    void setup(int x, int y, int width, int height, ofBaseApp* appPtr);
    void update();
    void draw();
    void exit(){};
    
    void keyPressed(int key);
   
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
private:
    
    ofTrueTypeFont	verdana;
    ofColor bordCol;
    int bordWidth;


};
