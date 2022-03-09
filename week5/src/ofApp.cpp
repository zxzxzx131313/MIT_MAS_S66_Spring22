#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    img.load("Knowlton-Ken.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    ofSetLineWidth(2);
    
    int width = 20;
    
    for (int i = 0; i < img.getWidth(); i+=width){
        for (int j = 0; j < img.getHeight(); j+=width){
            ofColor color = img.getColor(i, j);
            
            float brightness = color.getBrightness();
            
            float radius = ofMap(brightness, 0, 255, 1,5);
            ofSetColor(color);
            ofDrawRectangle(i,j, width, width);
            ofSetColor(255);
            int r = (i + j + 20) % 6;
            if (r == 0.0) {
                ofDrawCircle(i+width/2, j+width/2, 2);
            } else if (r == 1.0) {
                ofDrawCircle(i+width/2+5, j+width/2-5, 2);
                ofDrawCircle(i+width/2-5, j+width/2+5, 2);
            } else if (r == 2.0) {
                ofDrawCircle(i+width/2+5, j+width/2+5, 2);
                ofDrawCircle(i+width/2-5, j+width/2-5, 2);
                ofDrawCircle(i+width/2, j+width/2, 2);
            } else if (r == 3.0) {
                ofDrawCircle(i+width/2+5, j+width/2-5, 2);
                ofDrawCircle(i+width/2-5, j+width/2+5, 2);
                ofDrawCircle(i+width/2+5, j+width/2+5, 2);
                ofDrawCircle(i+width/2-5, j+width/2-5, 2);
            } else if (r == 4.0) {
                ofDrawCircle(i+width/2+5, j+width/2-5, 2);
                ofDrawCircle(i+width/2-5, j+width/2+5, 2);
                ofDrawCircle(i+width/2+5, j+width/2+5, 2);
                ofDrawCircle(i+width/2-5, j+width/2-5, 2);
                ofDrawCircle(i+width/2, j+width/2, 2);
            } else if (r == 5.0) {
                ofDrawCircle(i+width/2-5, j+width/2-5, 2);
                ofDrawCircle(i+width/2+5, j+width/2-5, 2);
                ofDrawCircle(i+width/2, j+width/2-5, 2);
                ofDrawCircle(i+width/2-5, j+width/2+5, 2);
                ofDrawCircle(i+width/2, j+width/2+5, 2);
                ofDrawCircle(i+width/2+5, j+width/2+5, 2);
            }
        }
    }
    ofSetColor(255);
    img.draw(500,0);
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
