#pragma once

#include "ofMain.h"

//panels
#include "HeaderPanel.h"
#include "BodyPanel.h"
#include "FooterPanel.h"

#include "ofxDatGui.h"
#include "ofxDatGuiThemesVMM.h"

#define HEADER_PANEL_HEIGHT 0.2
#define BODY_PANEL_HEIGHT 0.6
#define FOOTER_PANEL_HEIGHT 0.2


struct appData {
    string selected_panel_name;
    ofColor txt_color;
};


class ofApp : public ofBaseApp{

	public:
    
        appData myAppData;
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //panels
        HeaderPanel headerPanel;
        BodyPanel bodyPanel;
        FooterPanel footerPanel;
    
        ofTrueTypeFont	verdana30;
    
        //S1
        int numCols;
        int numRows;
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
            ofxDatGuiLabel* clamp;
        
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
    
        ofxDatGuiLabel* BBF;
        ofxDatGuiTextInput* bar;
        ofxDatGuiTextInput* beat;
        ofxDatGuiTextInput* frame;
    
        ofxDatGuiSlider* linkSlider;
    
        //not used anymore
        ofxDatGuiTextInput* selTrack;
        ofxDatGuiTextInput* selKeys;
        ofxDatGuiTextInput* selValues;
    
		
};
