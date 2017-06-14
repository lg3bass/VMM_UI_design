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
    
    
        int numCols;
        int numRows;
        ofTrueTypeFont font;
        ofxDatGuiMatrix* tracks;
        ofxDatGuiMatrix* pages;
        ofxDatGuiMatrix* clips;
 
        //save/load dropdowns
        vector<string> saveOptions;
        vector<string> loadOptions;
        ofxDatGuiDropdown* saveDropdown;
        ofxDatGuiDropdown* loadDropdown;
    
    
        //discrete save/load buttons
        ofxDatGuiButton* save;
        ofxDatGuiButton* saveAll;
        ofxDatGuiButton* load;
        ofxDatGuiButton* loadAll;
    
        //set global timing.
        ofxDatGuiTextInput* measures;
        ofxDatGuiTextInput* bpm;
        ofxDatGuiTextInput* fps;
        ofxDatGuiTextInput* loop;
    
        ofxDatGuiLabel* BBF;
        ofxDatGuiTextInput* bar;
        ofxDatGuiTextInput* beat;
        ofxDatGuiTextInput* frame;
    
        ofxDatGuiTextInput* selTrack;
        ofxDatGuiTextInput* selKeys;
        ofxDatGuiTextInput* selValues;
    
		
};
