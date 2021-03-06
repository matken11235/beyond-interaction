#include "ofApp.h"
#define NUM 1000 // 円の数を表す定数NUMを1000と定義

float loc_x[NUM]; //円のx座標
float loc_y[NUM]; //円のy座標
float speed_x[NUM]; //x軸方向のスピード
float speed_y[NUM]; //y軸方向のスピード
float radius[NUM]; //円の半径
int red[NUM]; //Red成分
int green[NUM]; //Green成分
int blue[NUM]; //Blue成分
bool mouse_pressed; //マウスはクリックされているか?

float x, y; // 真っ黒の円の中心座標
float s_x, s_y; // 真っ黒の円のスピード

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0); //背景色の設定
    ofSetFrameRate(60); //フレームレートの設定
    ofSetCircleResolution(64); //円の解像度設定
    ofEnableAlphaBlending(); //アルファチャンネルを有効に
    
    mouse_pressed = false; //マウス状態を「クリックされていない」に
    
    //NUMの数だけ初期値の生成を繰り返す
    for(int i = 0; i < NUM; i++){
        loc_x[i] = ofRandom(0, ofGetWidth()); //円のx座標初期位置
        loc_y[i] = ofRandom(0, ofGetHeight()); //円のy座標初期位置
        speed_x[i] = ofRandom(-5, 5); //x軸方向スピード初期値
        speed_y[i] = ofRandom(-5, 5); //y軸方向スピード初期値
        radius[i] = ofRandom(4, 40); //円の半径を設定
        red[i] = ofRandom(0, 255); //Red成分を設定
        green[i] = ofRandom(0, 255); //Green成分を設定
        blue[i] = ofRandom(0, 255); //Blue成分を設定
    }
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());
    s_x = ofRandom(-5, 5);
    s_y = ofRandom(-5, 5);
}

//--------------------------------------------------------------
void ofApp::update(){
    //NUMの数だけ座標の更新を繰り返す
    for(int i = 0; i < NUM; i++){
        
        //もしマウスがクリックされていたらマウスに集まってくる
        if(mouse_pressed){
            //マウスの現在位置から円のスピードを再計算
            speed_x[i] = (mouseX - loc_x[i]) / 8.0; //マウスのx座標と円のx 座標の距離の1/8だけ接近
            speed_y[i] = (mouseY - loc_y[i]) / 8.0; //マウスのy座標と円のy 座標の距離の1/8だけ接近
        }
        
        loc_x[i] = loc_x[i] + speed_x[i]; //円のx座標を更新
        loc_y[i] = loc_y[i] + speed_y[i]; //円のy座標を更新
        
        //円の跳ね返り条件
        if(loc_x[i] < 0){
            speed_x[i] = speed_x[i] * -1;
        }
        if(loc_x[i] > ofGetWidth()){
            speed_x[i] = speed_x[i] * -1;
        }
        if(loc_y[i] < 0){
            speed_y[i] = speed_y[i] * -1;
        }
        if(loc_y[i] > ofGetHeight()){
            speed_y[i] = speed_y[i] * -1;
        }
    }
    
    x += s_x;
    y += s_y;
    if(x < 0){
        s_x *= -1;
    }
    if(x > ofGetWidth()){
        s_x = s_x * -1;
    }
    if(y < 0){
        s_y = s_y * -1;
    }
    if(y > ofGetHeight()){
        s_y = s_y * -1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //NUMの数だけ円を描画する
    for(int i = 0; i < NUM; i++){
        ofSetColor(red[i], green[i], blue[i], 127); //描画色の設定
        ofDrawCircle(loc_x[i], loc_y[i], radius[i]); //円を描画
    }
    ofSetColor(0, 0, 0, 187);
    ofDrawCircle(x, y, 30);
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
    mouse_pressed = true; //マウスが押されている状態に
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouse_pressed = false; //マウスが押されていない状態に
    
    //円のスピードを再初期化
    for(int i = 0; i < NUM; i++){
        speed_x[i] = ofRandom(-5, 5); //x軸方向スピード初期値
        speed_y[i] = ofRandom(-5, 5); //y軸方向スピード初期値
    }
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
