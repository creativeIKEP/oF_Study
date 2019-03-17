#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<location.size(); i++){
        location[i] += velocity[i];
        if(location[i].x < 0 || location[i].x > ofGetWidth()){
            velocity[i].x *= -1;
        }
        if(location[i].y < 0 || location[i].y > ofGetHeight()){
            velocity[i].y *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<location.size(); i++){
        ofSetColor(0, 0, 255);
        ofDrawCircle(location[i], 25);
    }
    
    ofSetColor(255);
    ofDrawBitmapString("num=" + ofToString(location.size()), 20, 20);
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
    if(location.size() > max){
        location.erase(location.begin());
        velocity.erase(velocity.begin());
    }
    
    location.push_back(ofVec2f(x, y));
    velocity.push_back(ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)));
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
