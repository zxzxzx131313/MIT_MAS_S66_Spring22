#pragma once

#include "ofMain.h"

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
    
    void intersection(ofPoint a, ofPoint b, ofPoint c, ofPoint d, float off, float depth, ofPoint* p_int);
    
    ofPolyline trail;
    ofPolyline trail_left;
    ofPolyline trail_right;
    ofPolyline trail_m;
    ofEasyCam cam;
    float x_offset = 1;
    float y_offset = 1;
    
};
