#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //grabber.listDevices();
    //grabber.setDeviceID(1);
    grabber.initGrabber(2000, 768);
    
    camGray.allocate(grabber.getWidth(),
                     grabber.getHeight(),
                     OF_IMAGE_GRAYSCALE);
    
    bgGray.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    diffImg.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    
    threshImg.allocate(grabber.getWidth(),
                      grabber.getHeight(),
                      OF_IMAGE_GRAYSCALE);
    
    bRecordBg = true;
    font.load("framd.ttf", char_pt_size, true, true, true);
    
    
    vector <char> characters(s.begin(), s.end());
    
    ofSetColor(255,255,255);
    for (char &c : characters) {
        string s(1, c);
        vector < ofPath > paths = font.getStringAsPoints(s);
        char_paths.push_back(paths);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    
    grabber.update();
    if (grabber.isFrameNew()){
        convertColor(grabber,camGray, CV_RGB2GRAY );
        camGray.update();
        
        if (bRecordBg){
            bgGray.setFromPixels(camGray.getPixels());
            bgGray.update();
            bRecordBg = false;
        }
        
        absdiff(camGray, bgGray, diffImg);
        diffImg.update();
        
        threshImg.setFromPixels(diffImg.getPixels());
        threshold(threshImg, 40);
        threshImg.update();
        
        finder.setSortBySize(true);
        //finder.setMinArea(10);
        
        finder.findContours(threshImg);


    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofScale(0.5, 0.5);
    ofSetColor(80);
    grabber.draw(0,0);
    ofSetColor(255);
//    camGray.draw(grabber.getWidth(), 0);
//    bgGray.draw(0, grabber.getHeight());
//    diffImg.draw(grabber.getWidth(), grabber.getHeight());
    threshImg.draw(grabber.getWidth(), 0);
    
    if (finder.size() > 0){
        finder.getPolyline(0).draw();
        
        ofPolyline line = finder.getPolyline(0);  
        ofPoint top;
        for (int i = 0; i < line.size(); i++){
            if (i == 0){
                top = line[i];
            } else if (line[i].y < top.y){
                top = line[i];
            }
        }
        
        if (top.y < (char_top+char_pt_size-10) and had_left) {
            if (top.x > char_left and top.x < char_left+char_paths.size()*char_pt_size) {
                 
                had_left = false;
                
                int idx = (int)(top.x - char_left) / char_pt_size;
                if (last_idx == -1) {
                    last_idx = idx;
                } else {
//                    if (idx != last_idx) {
                        if (idx == char_paths.size()-1 and write_char_paths.size() > 0) {
                            write_char_paths.pop_back();
                        } else if (idx == 0) {
                            string st(1, ' ');
                            vector < ofPath > paths = font.getStringAsPoints(st);
                            write_char_paths.push_back(paths);
                        }else {
                            write_char_paths.push_back(char_paths[idx]);
                        }
                        last_idx = idx;
//                    }
                }
            }
        } else if (top.y > (char_top+char_pt_size)){
            had_left = true;
        }
        
    }
    for (int i = 0; i < char_paths.size(); i++) {
        char_paths[i][0].draw(grabber.getWidth() + i*char_pt_size + char_left, char_top);
    }
    
    if (write_char_paths.size() > 0) {
        for (int i = 0; i < write_char_paths.size(); i++) {
            write_char_paths[i][0].draw(grabber.getWidth() + i*char_pt_size + char_left, char_top+100);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ' ){
        bRecordBg = true;
    }
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
