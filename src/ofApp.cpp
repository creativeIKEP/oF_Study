#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    receiver.setup(PORT);
    mouseButtonState="";
}

//--------------------------------------------------------------
void ofApp::update(){
    // 現在順番待ちのOSCメッセージがある間は受信を続ける
    while(receiver.hasWaitingMessages()){
        //次のメッセージを取得
        ofxOscMessage m;
        receiver.getNextMessage(m);
        // メッセージが /mouse/position ならマウスの位置を取得
        if (m.getAddress() == "/mouse/position"){
            remoteMouse.x = m.getArgAsInt32(0);
            remoteMouse.y = m.getArgAsInt32(1);
        }
        // メッセージが /mouse/button ならマウスボタンの状態を取得
        else if (m.getAddress() == "/mouse/button"){
            mouseButtonState = m.getArgAsString(0) ;
        }
        //OSCメッセージをそのままコンソールに出力
        dumpOSC(m);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    int radius;
    // マウスボタンが押されていたら、赤い円を描画
    if (mouseButtonState == "down") {
        radius = 20;
        ofSetColor(255, 127, 0);
    } else {
        // そうでなければ、青い円を描画
        radius = 10;
        ofSetColor(0, 127, 255);
    }
    ofDrawCircle(remoteMouse.x, remoteMouse.y, radius);
}
    
// OSCメッセージをコンソールに出力する関数
void ofApp::dumpOSC(ofxOscMessage m) {
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
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
