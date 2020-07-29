#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //バッファーのサイズを指定
    bufSize = 256;
    //画面の基本設
    ofBackground(0,0,0);
    ofSetColor(0,0,255);
    //サウンドストリームの初期化
    ofSoundStreamSetup(0,2,this, 44100, bufSize, 4); //左右チャンネル音声の波形を格納する配列
    left = new float[bufSize];
    right = new float[bufSize];
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofDrawLine(i*phaseDiff, audioHeight/2, i*phaseDiff,
               audioHeight/2+left[i]*audioHeight);
    }
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofDrawLine(i*phaseDiff, audioHeight/2*3, i*phaseDiff,
               audioHeight/2*3+right[i]*audioHeight);
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

//--------------------------------------------------------------
void ofApp::audioReceived(float *input, int bufferSize, int nChannels){
    //音声入力を配列に格納
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}



