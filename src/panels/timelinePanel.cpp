//
//  timelinePanel.cpp
//  PATTERN_shared_ptr
//
//  Created by Robert White III on 6/8/17.
//
//

#include "timelinePanel.h"
#include "ofApp.h"

ofApp* bMainApp;

//-------------------------------------------------
void timelinePanel::setup(int x, int y, int width, int height, ofBaseApp* appPtr){
    
    bMainApp = dynamic_cast<ofApp*>(appPtr);
    
    _x = x;
    _y = y;
    _w = width;
    _h = height;
    
    //colors
    setBackgroundColor(ofColor::darkGray);
    setBorderColor(ofColor::mediumOrchid);
    setBorderWidth(2);
    
    
    verdana9.load("verdana.ttf", 7, true, true);


}

//-------------------------------------------------
void timelinePanel::update(){
    
    
}

//-------------------------------------------------
void timelinePanel::draw(){
    
    drawPanel();
    
    drawTrackData();
    
}

//-------------------------------------------------
void timelinePanel::keyPressed(int key){
    
    if(key & OF_KEY_MODIFIER){
        if(key >= OF_KEY_F1 && key <= OF_KEY_F12){

            switch(key){
                case 257:
                    
                    //decrement
                    if(data.getNumOfChannelsOnPage() > 1){
                        
                        
                        int selected_page = data.getSelectedChannel();
                        
                        if(selected_page > 0){
                            selected_page--;
                        } else {
                            selected_page = data.getNumOfChannelsOnPage()-1;
                        }
                        data.setSelectedChannel(selected_page);
                        
                        cout << "F1 pressed - decrement track selection" << endl;
                        
                    } else {
                        
                        cout << "F1 pressed - not enough timelines on page" << endl;
                    }
                    
                    break;
                case 258:
                    
                    //increment
                    if(data.getNumOfChannelsOnPage() > 1){
                        
                        
                        int selected_page = data.getSelectedChannel();
                        
                        if(selected_page < data.getNumOfChannelsOnPage()-1){
                            selected_page++;
                        } else {
                            selected_page = 0;
                        }
                        data.setSelectedChannel(selected_page);
                        
                        cout << "F2 pressed - increment track selection" << endl;
                    } else {
                        
                        cout << "F2 pressed - not enough timelines on page" << endl;
                    }
                    
                    break;
                case 259:
                    
                    cout << "F3 pressed" << endl;
                    break;
            
            }//end switch
            
        }else{
            
            switch(key){
                case OF_KEY_LEFT_SUPER:
                    cout << "Left Apple Pressed" << endl;
                    
                    break;
                case OF_KEY_RIGHT_SUPER:
                    cout << "Right Apple Pressed" << endl;
                   
                    break;
                case OF_KEY_CONTROL:
                    cout << "Control Pressed" << endl;
                    
                    break;
                case OF_KEY_RIGHT_ALT:
                    cout << "Right Alt/Opt Pressed" << endl;
                                    
                    break;
                case OF_KEY_RIGHT_SHIFT:
                    cout << "Right Shift Pressed" << endl;

                    break;
                case OF_KEY_LEFT_ALT:
                    cout << "Left Alt/Opt Pressed" << endl;

                    break;
                    
            }//switch
        }//if-else
    }//if
}//func

//-------------------------------------------------
void timelinePanel::keyReleased(int key){
    if(key & OF_KEY_MODIFIER){
        if(key >= OF_KEY_F1 && key <= OF_KEY_F12){

            switch(key){
                case 257:
                    //cout << "F1 released" << endl;
                    
                    
                    break;
                case 258:
                    //cout << "F2 released" << endl;
                    
                    
                    break;
                case 259:
                    
                    //cout << "F3 released" << endl;
                    break;
                    
            }//end switch
        }else{
            
            switch(key){
                case OF_KEY_LEFT_SUPER:
                    cout << "Left Apple Released" << endl;
                    
                    break;
                case OF_KEY_RIGHT_SUPER:
                    cout << "Right Apple Released" << endl;
                    
                    break;
                case OF_KEY_CONTROL:
                    cout << "Control Released" << endl;
                    
                    break;
                case OF_KEY_RIGHT_ALT:
                    cout << "Right Alt/Opt Released" << endl;
                
                    break;
                case OF_KEY_RIGHT_SHIFT:
                    cout << "Right Shift Released" << endl;
                    
                    break;
                case OF_KEY_LEFT_ALT:
                    cout << "Left Alt/Opt Released" << endl;

                    break;
                    
            }
        }
    }
}

//-------------------------------------------------
void timelinePanel::mousePressed(int x, int y, int button){
    if(y > _y && y < _y+_h){

        
        bMainApp->myAppData.selected_panel_name = "BODY";
        bMainApp->myAppData.txt_color = ofColor::darkKhaki;
    }
    
    
}

//-------------------------------------------------
void timelinePanel::mouseReleased(int x, int y, int button){

    //ofLog() << "body released";
    //setBackgroundColor(ofColor::darkGray);

    
}

//-------------------------------------------------
void timelinePanel::drawTrackData(){

    float ml = 60;
    float mt = 80;

    float h_unit = 105;
    float v_unit = 15;
    

    verdana9.drawString("TRACK:"     , 0, _y+mt+v_unit*0);
    verdana9.drawString("page:"      , 0, _y+mt+v_unit*1);
    verdana9.drawString("clip:"      , 0, _y+mt+v_unit*2);
    verdana9.drawString("cue:"       , 0, _y+mt+v_unit*3);
    verdana9.drawString("keys:", 0, _y+mt+v_unit*4);


    for(int i=0; i<NUMBER_OF_TRACKS;i++){

        verdana9.drawString(ofToString(i+1), i*100+ml, _y+mt+v_unit*0);
        verdana9.drawString(ofToString(data.getPage(i)+1), i*100+ml, _y+mt+v_unit*1);
        verdana9.drawString(ofToString(data.getClip(i)+1), i*100+ml, _y+mt+v_unit*2);
        verdana9.drawString(data.getCuedToPlay(i) ? "true" : "false", i*100+ml, _y+mt+v_unit*3);
        

        
        
//        string ky;
//        for(int k=0; k<3;k++){
//            
//            
//            ky += "["+ofToString(data.TL.keyframes.keys[k].frm)+","+ofToString(data.TL.keyframes.keys[k].val)+"],";
//            
//        }
//        verdana9.drawString(ky, i*100+ml, _y+mt+v_unit*4);
        
    }

    drawPageData();
    
}

//-------------------------------------------------
void timelinePanel::drawPageData(){
    
    float ml = 60;
    float mt = 200;
    
    float h_unit = 105;
    float v_unit = 15;
    
    int num_tracks_on_page = data.TL.tracks[data.getTrack()].tlPages[data.getPage()].tlChannels.size();
    string selectedPageChannel = "";
    
    if (data.getNumOfChannelsOnPage() > 0){
        
    } else {
        
    }
    
    string tlt = "TRACK " + ofToString(data.getTrack()+1) + " > PAGE " + ofToString(data.getPage()+1) + "[" + ofToString(data.getNumOfChannelsOnPage()) + "] - " ;
    
    tlt += "(";
    
    for(int i=0;i<num_tracks_on_page;i++){
        
        tlt += "[" + ofToString(data.TL.tracks[data.getTrack()].tlPages[data.getPage()].tlChannels[i].name) + ",";
        tlt += ofToString(data.TL.tracks[data.getTrack()].tlPages[data.getPage()].tlChannels[i].type) + "]";
        if(i<num_tracks_on_page-1){
            tlt += ", ";
        }
    }
    
    tlt += ")";
    verdana9.drawString(tlt, _x+ml, _y+mt);
    
    string keyframeTxt = "KEYS: ";
    string selKeyTxt = "SELECTED KEY: ";
    
    int kf;
    float kv;
    
    
    
    if (data.getNumOfChannelsOnPage() > 0){
        
        //int keysInChannel = data.TL.tracks[data.getTrack()].tlPages[data.getPage()].tlChannels[data.getSelectedChannel()].keyframes.keys.size();
        //int selectedKeyIndex = data.TL.tracks[data.getTrack()].tlPages[data.getPage()].tlChannels[data.getSelectedChannel()].selected_key;
        
        int keysInChannel = data.getNumOfKeysInChannel();
        int selectedKeyIndex = data.getSelectedKeyIndex();
        
        for(int j=0; j< keysInChannel;j++){
            
            keyframeTxt += "(" + ofToString(data.getSelectedKeyValue(j).x) + ":" + ofToString(data.getSelectedKeyValue(j).y) + ")";
            
            if(j<keysInChannel-1){
                keyframeTxt += ", ";
            }
        }

        selKeyTxt += ofToString(data.getSelectedKeyIndex()) + " - (" + ofToString(data.getSelectedKeyValue(selectedKeyIndex).x) + ":" + ofToString(data.getSelectedKeyValue(selectedKeyIndex).y) + ")";
        
        
    }
    verdana9.drawString(keyframeTxt, _x+ml, _y+mt+v_unit*1);
    verdana9.drawString(selKeyTxt, _x+ml, _y+mt+v_unit*2);
    
}

