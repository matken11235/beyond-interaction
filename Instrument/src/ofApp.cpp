#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面の書き換えタイミングと同期
    ofSetVerticalSync(true);
    //背景色
    ofBackground(0, 0, 0);
    //円の解像度
    ofSetCircleResolution(64);
    //フレームレートの設定
    ofSetFrameRate(30);
    
    //毎回異なる乱数を発生させる
    ofSeedRandom();
    
    //ofxBox2dの初期設定
    //物理エンジンを初期化
    box2d.init();
    //重力は使用しない
    box2d.setGravity(0,0);
    //Box2D側のフレームレートを設定
    box2d.setFPS(30.0);
    
    //画面の中心に1つめのパーティクルを生成
    //CustomCircleクラスをインスタンス化
    CustomCircle *c =new CustomCircle(circles.size());
    //物理パラメータを設定
    c->setPhysics(1.0, 0, 0);
    //ワールドに追加
    c->setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, 10, true);
    //衝突判定はしない
    c->disableCollistion();
    //ベクター circlesに追加
    circles.push_back(c);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
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
