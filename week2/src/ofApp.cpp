#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofColor red;
    red.r = 171;
    red.g = 41;
    red.b = 53;
    
    ofColor blue;
    blue.r = 128;
    blue.g = 193;
    blue.b = 249;
    
    ofColor white;
    white.r = 255;
    white.g = 255;
    white.b = 255;
    
    ofColor colors[3] = {red, blue, white};
    
    for (int i = 0; i < 1000; i++){
        float xorig = 400;
        float yorig = 400;
        float adder = ofMap(i, 0, 1000, 0.001, 0.01);
        scale += adder;
//        cout << i << endl;
//        cout << " : " << endl;
//        cout << scale << endl;
//        scale = ofMap(scale, 0, scale, 2, 12);
        float dis = 2*cos(scale) * 100;
        if (i == 999) {
            scale = 0;
        }
        float rad = ofGetElapsedTimef() * ofMap(i, 0, 1000, 1, 100);
        float r = 2*cos(2*rad) + dis;

        for (int j = 0; j < 10; j++){
            float offset = PI*int(j/5);
            float x = xorig + dis * cos(rad +offset);
            float y = yorig + dis * sin(rad +offset);
            ofSetColor(colors[int(ofRandom(3))]);
            ofDrawCircle(x,y, 2);
        }
        
//        for
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//    if (key == ' '){
//        trail.clear();
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
