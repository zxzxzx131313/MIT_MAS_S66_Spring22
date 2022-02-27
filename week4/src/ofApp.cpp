#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(800,800);
    ofBackground(255);
    ofSetFrameRate(20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

void ofApp::intersection(ofPoint a, ofPoint b, ofPoint c, ofPoint d, float off, float depth, ofPoint* p_int) {
    
    float a1 = b.y - a.y;
    float b1 = a.x - b.x;
    float c1 = a1*a.x + b1*a.y;
    
    float a3 = d.y - c.y;
    float b3 = c.x - d.x;
    float c3 = a3*c.x + b3*c.y;
    
    float a2 = a3;
    float b2 = b3;
    float c2 = c3+off;
    
    float det = a1*b2 - a2*b1;
    
    
    float x_int = (b2*c1 - b1*c2)/det;
    float y_int = (a1*c2 - a2*c1)/det;
    ofPoint p(x_int, y_int, depth);
    *p_int = p;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    
    cam.begin();
    
    float xorig = 0;
    float yorig = 0;

    
    if (sin(ofGetElapsedTimef()) > 0.95) {
        x_offset = ofRandom(-20, 20);
    } else if (sin(ofGetElapsedTimef()) < -0.95){
        y_offset = ofRandom(-20, 20);
    }
    

    float x, y;
    if (trail.getVertices().size() > 0) {
        ofPoint last = trail.getVertices()[trail.size()-1];
        x = last.x;
        y = last.y;
    } else {
        x = xorig;
        y = yorig;
    }

    x += x_offset;
    y += y_offset;

    ofPoint p(x,y, 0);

    if (x > 200) {
        x -= abs(2*x_offset);
        x_offset = -20.0;
    } else if (x < -200) {
        x += abs(2*x_offset);
        x_offset = 20.0;
    }
    if (y > 200) {
        y -= abs(2*y_offset);
        y_offset = -20.0;
    } else if (y < -200) {
        y += abs(2*y_offset);
        y_offset = 20.0;
    }
    

    float depth = 0.0;
    for (auto it = trail.getVertices().begin(); it != trail.getVertices().end(); ++it) {
        // draw circle along line
//        ofDrawCircle(it->x, it->y, 1);
//        unsigned int closest_idx = 101;
//        trail.getClosestPoint(p, &closest_idx);
//        if (closest_idx != trail.size()-1 and trail.size() > 3 and p.distance(trail.getVertices()[closest_idx]) < 1) {
//            trail.getVertices().erase(trail.getVertices().begin()+closest_idx-1, trail.getVertices().begin()+closest_idx+2);
//        }
        if (it+1 != trail.getVertices().end()) {
            float seg_x_min = min(it->x, (it+1)->x);
            float seg_x_max = max(it->x, (it+1)->x);
            float seg_y_min = min(it->y, (it+1)->y);
            float seg_y_max = max(it->y, (it+1)->y);
            if (seg_x_min < p.x < seg_x_max and seg_y_min < p.y < seg_y_max) {
                // intersect
                
                trail.getVertices()[trail.size()-1].z += 1.0;
                depth = trail.getVertices()[trail.size()-1].z;
            }
        }
    }
    
    trail.addVertex(x,y, 0);
    ofSetLineWidth(2);
    
    if (trail.size() > 1) {
        float dx = x - trail.getVertices()[trail.size()-2].x;
        float dy = y - trail.getVertices()[trail.size()-2].y;
        ofPoint norm1(-dy, dx);
        ofPoint norm2(dy, -dx);
        
        ofPoint v_left;
        intersection(norm1, p, p, trail.getVertices()[trail.size()-2], -10, depth, &v_left);
        
        ofPoint v_m;
        intersection(norm1, p, p, trail.getVertices()[trail.size()-2], 0, depth, &v_m);
        
        ofPoint v_right;
        intersection(norm2, p, p, trail.getVertices()[trail.size()-2], 10, depth, &v_right);
        
        trail_left.addVertex(v_left);
        trail_right.addVertex(v_right);
        trail_m.addVertex(v_m);
        
        if (trail.size() > 600){
            trail.getVertices().erase(trail.getVertices().begin());
            trail_left.getVertices().erase(trail_left.getVertices().begin());
            trail_right.getVertices().erase(trail_right.getVertices().begin());
            trail_m.getVertices().erase(trail_m.getVertices().begin());
        }
        trail = trail.getSmoothed(3);
        trail_left = trail_left.getSmoothed(3);
        trail_right = trail_right.getSmoothed(3);
        trail_m = trail_right.getSmoothed(3);
        
        ofEnableAlphaBlending();
        
        ofSetColor(131, 38, 26, 80);

        trail_left.draw();
        ofSetColor(176,56,30, 255);
        
        trail_m.draw();
        ofSetColor(92,16,1, 80);

        trail_right.draw();
    }
    cam.end();
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
