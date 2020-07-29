#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面の基本設定
    ofBackground(0,0,0);
    ofEnableSmoothing();
    
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    
    //キャプチャするムービーのサイズを指定
    camWidth = 480;
    camHeight = 320;
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    //ムービーをカメラからキャプチャする
    // vidGrabber.grabFrame();
    vidGrabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xffffff);
    vidGrabber.draw(20,20); //ムービーのビットマップデータを解析し、配列に格納
    unsigned char * pixels = vidGrabber.getPixels().getData(); //画像を10ピクセルごとにスキャン
    for (int i = 0; i < camWidth; i+=10){
        for (int j = 0; j < camHeight; j+=10){
            //RGBそれぞれのピクセルの明度を取得
            unsigned char r = pixels[(j * camWidth + i)*3];
            unsigned char g = pixels[(j * camWidth + i)*3+1];
            unsigned char b = pixels[(j * camWidth + i)*3+2];
            //取得したRGB値をもとに、円を描画
            //取得したピクセルの明るさを、円の半径に対応させている
            ofSetColor(255, 0, 0, 100);
            ofDrawCircle(camWidth+40 + i,20+j,20.0*(float)r/255.0);
            ofSetColor(0, 255, 0, 100);
            ofDrawCircle(camWidth+40 + i,20+j,20.0*(float)g/255.0);
            ofSetColor(0, 0, 255, 100);
            ofDrawCircle(camWidth+40 + i,20+j,20.0*(float)b/255.0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //「s」キーを押すと、ビデオ取り込みの設定画面を表示
    if (key == 's' || key == 'S'){
        vidGrabber.videoSettings();
    }
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
