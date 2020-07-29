#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); // 背景色の設定
    ofEnableAlphaBlending(); // 透明度(アルファチャンネル)を有効にする
    ofSetColor(31, 127, 255, 12); // 描画色の設定
    ofSetCircleResolution(64); // 円の解像度を設定
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float x; // 円のx座標
    float y; // 円のy座標
    float radius; // 円の半径
    int i; // for文のカウンタ変数
    
    x = ofGetWidth() / 2; // x座標を画面の中心に
    y = ofGetHeight() / 2; // y座標を画面の中心に
    radius = 30; // 半径の初期値を設定
    
    for (i = 0; i < 50; i++){
        x += 2;
        y += 3;
        radius += 4;
        ofDrawCircle(x, y, radius); // 円を描く
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
