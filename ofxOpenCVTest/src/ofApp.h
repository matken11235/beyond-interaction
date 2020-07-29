#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofVideoGrabber vidGrabber; //ビデオ入力
        ofxCvColorImage colorImg; //OpenCVで扱うカラーイメージ
        ofxCvGrayscaleImage grayImage; //OpenCVで扱うグレースケールイメージ
        ofxCvGrayscaleImage grayBg; //背景のグレースケールイメージ
        ofxCvGrayscaleImage grayDiff; //背景との差分のグレースケールイメージ
        ofxCvContourFinder contourFinder; //輪郭抽出のためのインスタンス
    
        bool bLearnBakground; //背景を記録したかどうか
        int threshold; //背景の差分の閾値
};
