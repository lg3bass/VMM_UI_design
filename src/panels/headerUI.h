//
//  headerUI.h
//  VMM_UI_design
//
//  Created by Robert White III on 6/19/17.
//
//
#pragma once

#ifndef headerUI_h
#define headerUI_h

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxDatGuiThemesVMM.h"

#endif /* headerUI_h */


class headerUI {
    
public:
    
    
    void setup(ofBaseApp* appPtr);
    void update();
    void draw();
    
    void setupGUI();
    void updateGUI();
    void drawGUI();
    
    int add_type;
    string add_name;
    
    //S1
    ofTrueTypeFont font;
    ofxDatGuiMatrix* tracks;
    ofxDatGuiMatrix* pages;
    ofxDatGuiMatrix* clips;
    
    //S2
    //ROW1
    ofxDatGuiLabel* breadcrumb;
    
    //ROW2
    ofxDatGuiLabel* selKey;
    ofxDatGuiButton* selPrev;
    ofxDatGuiButton* selNext;
    ofxDatGuiTextInput* keyVal;
    ofxDatGuiButton* clamp;
    
    //ROW3
    //save/load dropdowns
    vector<string> saveOptions;
    vector<string> loadOptions;
    ofxDatGuiDropdown* saveDropdown;
    ofxDatGuiDropdown* loadDropdown;
    
    //S3
    //ROW 1
    //set global timing.
    ofxDatGuiTextInput* measures;
    ofxDatGuiTextInput* bpm;
    ofxDatGuiTextInput* fps;
    ofxDatGuiTextInput* loop;
    
    //ROW 2
    ofxDatGuiTextInput* clampL;
    ofxDatGuiTextInput* clampH;
    ofxDatGuiTextInput* setIn;
    ofxDatGuiTextInput* setOut;
    
    //ROW 3
    ofxDatGuiButton* addTr;
    ofxDatGuiButton* remTr;
    vector<string> trackOptions;
    ofxDatGuiDropdown* trackDropdown;
    ofxDatGuiTextInput* trackName;
    
    
    //S4
    
    //ROW 1
    ofxDatGuiTextInput* meter;
    ofxDatGuiTextInput* barBeatFrame;
    
    //ROW 2
    ofxDatGuiButton* quantize;
    ofxDatGuiButton* snap;
    ofxDatGuiButton* focus;
    ofxDatGuiButton* showAll;
    ofxDatGuiButton* drive;
    
    //ROW 3
    ofxDatGuiTextInput* host;
    ofxDatGuiTextInput* port;
    ofxDatGuiButton* osc;
    
    //S5
    ofxDatGuiSlider* linkSlider;
    
    void onTrackMatrixInputEvent(ofxDatGuiMatrixEvent e);
    void onPageMatrixInputEvent(ofxDatGuiMatrixEvent e);
    void onClipMatrixInputEvent(ofxDatGuiMatrixEvent e);
    
    void onDDInputEvent(ofxDatGuiDropdownEvent e);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);
    void onButtonEvent(ofxDatGuiButtonEvent e);

    void onSliderEvent(ofxDatGuiSliderEvent e);

    //
    void resetTrackDropdown();
    
    
    
};
