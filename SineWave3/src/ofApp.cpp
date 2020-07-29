#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetVerticalSync(true);
    ofSetCircleResolution(64);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false); // 軌跡を残す
    
    radius = 0; //円の半径
    mySound.load("1085.mp3"); //サウンドファイルの読込み
    mySound.setLoop(true); //ループ再生をONに
}

//--------------------------------------------------------------
void ofApp::update(){
    float * val = ofSoundGetSpectrum(1); //再生中のサウンドの音量を取得
    radius = val[0] * 800.0; //円の半径に適用
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 63, 255, 180);
    ofDrawCircle(mouseX, mouseY, radius);
    
    //全画面を半透明の黒でフェード
    ofSetColor(0, 0, 0, 23);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
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
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f);
    //再生スピード変更
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*1.0f);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //パンの設定
    mySound.setPan(x / (float)ofGetWidth() * 2 - 1.0f); //再生スピード設定
    mySound.setSpeed( 0.5f + ((float)(ofGetHeight() - y) / (float)
                              ofGetHeight())*1.0f);
    //サウンド再生開始
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mySound.stop(); //サウンド再生終了
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
