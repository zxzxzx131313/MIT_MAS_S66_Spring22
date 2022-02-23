#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    font.load("framd.ttf", 100, true, true, true);
    ofBackground(0,0,0);
    ofSetFrameRate(60);

    //allocate our fbos.
    //providing the dimensions and the format for the,
    
    #ifdef TARGET_OPENGLES
    rgbaFboFloat.allocate(1024, 768, GL_RGBA ); // with alpha, 8 bits red, 8 bits green, 8 bits blue, 8 bits alpha, from 0 to 255 in 256 steps
        ofLogWarning("ofApp") << "GL_RGBA32F_ARB is not available for OPENGLES.  Using RGBA.";
    #else
        rgbaFboFloat.allocate(1024, 768, GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
    #endif
    
    rgbaFboFloat.begin();
    ofClear(255,255,255, 0);
    rgbaFboFloat.end();

}

//--------------------------------------------------------------
void ofApp::update(){

    ofEnableAlphaBlending();

    //lets draw some graphics into our two fbos

    rgbaFboFloat.begin();
        drawFboTest();
    rgbaFboFloat.end();
}

void ofApp::drawFboTest(){

    //some different alpha values for fading the fbo
    //the lower the number, the longer the trails will take to fade away.
    fadeAmnt = 30;


    //1 - Fade Fbo

    //this is where we fade the fbo
    //by drawing a rectangle the size of the fbo with a small alpha value, we can slowly fade the current contents of the fbo.

    ofFill();
    ofSetColor(255,255,255, fadeAmnt);
    ofDrawRectangle(0,0,1024,768);
    
    
    ofNoFill();
    ofSetColor(255,255,255);

    ofSeedRandom(mouseX*1000);

    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector <char> characters(s.begin(), s.end());
    vector <vector <ofPath>> char_paths;

    for (char &c : characters) {
        string s(1, c);
        vector < ofPath > paths = font.getStringAsPoints(s);
        char_paths.push_back(paths);
    }

    int char_idx_rad = ofRandom(0,23);

    char_paths[char_idx_rad][0].draw(mouseX, mouseY);


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255,255,255);
    rgbaFboFloat.draw(0,0);
    
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
