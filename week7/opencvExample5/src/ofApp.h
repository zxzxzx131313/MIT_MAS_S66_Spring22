#pragma once

#include "ofMain.h"
#include "ofxCv.h"


using namespace ofxCv;

class ofApp : public ofBaseApp{

	public:
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
    
    
        ofVideoGrabber grabber;
        ofImage camGray;
        ofImage bgGray;
        ofImage diffImg;
        ofImage threshImg;
    ContourFinder finder;
    ofTrueTypeFont font;
    
    vector <vector <ofPath>> char_paths;
    vector <vector <ofPath>> write_char_paths;
    int char_pt_size = 40;
    string s = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ<";
    int char_top = 50;
    int char_left = 50;
    string s_write = "";
    int last_idx = -1;
    bool had_left = true;
        bool bRecordBg = false;
    
		
};
