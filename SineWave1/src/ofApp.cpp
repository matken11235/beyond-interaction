#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sampleRate = 44100; //サンプリング周波数
    bufSize = 256;
    amp = 0.5; //音量
    pan = 0.5; //左右の定位
    phase = 0; //位相
    frequency = 440; //周波数
    waveShape = 1; //波形
    ofSetFrameRate(30);
    ofBackground(32, 32, 32);
    ofSoundStreamSetup(2, 0, this); //サウンドストリームの準備、左右2ch
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    float audioHeight = ofGetHeight()/2.0f;
    float phaseDiff = ofGetWidth()/float(bufSize);
    
    ofSetColor(0,0,255);
    
    //左チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofDrawLine(i*phaseDiff, audioHeight/2, i*phaseDiff,
               audioHeight/2+lAudio[i]*audioHeight);
    }
    //右チャンネル波形を描画
    for (int i = 0; i < bufSize; i++){
        ofDrawLine(i*phaseDiff, audioHeight/2*3, i*phaseDiff,
               audioHeight/2*3+rAudio[i]*audioHeight);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //キー入力によって波形選択と音量調整
    switch(key){
        case '-': //音量下げる
            amp -= 0.05;
            amp = MAX(amp, 0);
            break;
        case '+': //音量上げる
            amp += 0.05;
            amp = MIN(amp, 1);
            break;
        case '1': //sin波
            waveShape = 1;
            break;
        case '2': //ノコギリ波
            waveShape = 2;
            break;
        case '3': //矩形波
            waveShape = 3;
            break;
        case '4': //三角波
            waveShape = 4;
            break;
        case '5': //ホワイトノイズ
            waveShape = 5;
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    pan = (float)x / (float)ofGetWidth();
    float heightPct = (float(ofGetHeight()-y) / float(ofGetHeight()));
    
    frequency = 4000.0f * heightPct;
    
    if(frequency < 20){
        frequency = 20;
    }
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
void ofApp::audioRequested(float *output, int bufferSize, int nChannels){
    float sample; //出力する音のサンプル
    float phaseDiff; //位相の変化
    
    //1サンプルあたりの位相の変化を計算
    phaseDiff = TWO_PI * frequency / sampleRate;
    
    //バッファのサイズ分の波形を生成
    for (int i = 0; i < bufferSize; i++){
        //位相を更新
        phase += phaseDiff; while (phase > TWO_PI){
            phase -= TWO_PI;
        }
        // 波形を選択
        switch (waveShape) {
            case 1: // Sin波
                sample = sin(phase); break;
            case 2: // ノコギリ波
                sample = - phase / PI + 1; break;
            case 3: // 矩形波
                sample = (phase < PI) ? -1 : 1;
                break;
            case 4: // 三角波
                sample = (phase < PI) ? -2 / PI * phase + 1 : 2 / PI * phase - 3;
                break;
            case 5: // ホワイトノイズ
                sample = ofRandom(-1, 1);
        }
        // オーディオアウト、左右2ch
        lAudio[i] = output[i * nChannels] = sample * pan * amp;
        rAudio[i] = output[i * nChannels + 1] = sample * (1.0 - pan) * amp;
    }
}






