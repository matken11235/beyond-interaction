#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); // 背景色の設定
    ofEnableAlphaBlending(); // 透明度を使用可能に
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float x;
    float y;
    float w;
    float h;
    int i, j;
    
    x = 0;
    y = 0;
    w = ofGetWidth() / 30.0 + 1;
    h = ofGetHeight() / 20.0 + 1;
    
    for(j = 0; j < 20; j++){
        for(i = 0; i < 30; i++){
            ofSetColor(255 / 20 * j, 127, 255 / 30 * i, 127);
            // 塗りの色を変化させる
            x = ofGetWidth() / 30.0 * i;
            y = ofGetHeight() / 20.0 * j;
            ofDrawRectangle(x, y, w, h);
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
