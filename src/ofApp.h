#pragma once

#include "ofMain.h"

//panels
#include "HeaderPanel.h"
#include "timelinePanel.h"
#include "FooterPanel.h"

#define HEADER_PANEL_HEIGHT 0.16
#define BODY_PANEL_HEIGHT 0.74
#define FOOTER_PANEL_HEIGHT 0.1

struct appData {
    string selected_panel_name;
    ofColor txt_color;
};



class ofApp : public ofBaseApp{

	public:
        appData myAppData;

        //ofApp.cpp
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
    
    
        //ofAppRouter.cpp
        void setControllerData(string name, int data);
        void setBreadcrumb();
        void addTLTrack(string name, int type);
        void remTLTrack();
        
        void nextKey();
        void prevKey();
        void setKeyVal(int _val);
    

    
    private:
    

    
        //panels
        HeaderPanel headerPanel;
        timelinePanel timePanel;
        FooterPanel footerPanel;
    
        ofTrueTypeFont	verdana30;
    
		
};
