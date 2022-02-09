#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofDrawCircle();
    //ofDrawRectangle();
    
    ofBackground(0);
    
    ofSeedRandom(mouseX*1000);
    
    ofColor purple;
    purple.r = 92;
    purple.g = 76;
    purple.b = 149;
    
    ofColor red;
    red.r = 171;
    red.g = 41;
    red.b = 53;
    
    ofColor yellow;
    yellow.r = 211;
    yellow.g = 192;
    yellow.b = 1;
    
    ofColor green;
    green.r = 81;
    green.g = 134;
    green.b = 20;
    
    ofColor blue;
    blue.r = 128;
    blue.g = 193;
    blue.b = 249;
    
    ofColor white;
    white.r = 255;
    white.g = 255;
    white.b = 255;
    
    ofColor colors[6] = {purple, red, yellow, green, blue, white};
    ofNoFill();
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            float x = ofMap(i, 0, 6, 150, 750);
            float y = ofMap(j, 0, 6, 150, 750);

            ofSetColor(colors[int(ofRandom(6))]);

            for (int k = 0; k < 10; k++){
                float offset = ofMap(k, 0, 10, 10, 30);
                float width = ofMap(k,0, 10, 20, 50);
                ofBeginShape();
                ofVertex(x - width + ofRandom(-offset,offset),y - width + ofRandom(-offset,offset));
                ofVertex(x + width + ofRandom(-offset,offset),y - width + ofRandom(-offset,offset));
                ofVertex(x + width + ofRandom(-offset,offset),y + width + ofRandom(-offset,offset));
                ofVertex(x - width + ofRandom(-offset,offset),y + width + ofRandom(-offset,offset));
                ofEndShape(true);
                
            }
        }
    }
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
