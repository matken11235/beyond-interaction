#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
    
    //ビデオ取り込み初期化
    vidGrabber.initGrabber(320,240);
    //解析用の画像の領域確保
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    //背景画像を記憶しているかどうか
    bLearnBakground = true;
    //閾値
    threshold = 20;
    //輪郭線の単純さ
    simpleAmount = 1.0;
    //輪郭線を繋ぐ順序
    bReversePoints = false;
    
    //Box2D初期設定
    box2d.init();
    box2d.setGravity(0,20);
    box2d.createBounds();
    box2d.setFPS(30.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    //Box2Dを更新
    box2d.update();
    //新規にフレームを取り込んだかを判定する変数
    bool bNewFrame = false;
    //1フレーム映像を取り込み
    vidGrabber.update();
    //最後に取り込んだフレームから変化があったかを判定
    bNewFrame = vidGrabber.isFrameNew();
    
    //新規のフレームの場合とりこみ実行
    if (bNewFrame){
        
        //OpenCVで解析するカラー画像領域に、カメラから取得した映像を格納
        colorImg.setFromPixels(vidGrabber.getPixels());
        //取り込んだカラー映像をグレースケールに変換
        grayImage = colorImg;
        
        //新規に背景を学習する場合
        if (bLearnBakground == true){
            
            //現在の取り込んだグレースケールイメージを記憶
            grayBg = grayImage;
            //背景の学習をしないモードに戻す
            bLearnBakground = false;
        }
        
        //背景画像と現在の画像の差分の絶対値を取得
        grayDiff.absDiff(grayBg, grayImage);
        //差分画像を設定した閾値を境に二値化
        grayDiff.threshold(threshold);
        //二値化した差分画像から、輪郭を抽出する
        contourFinder.findContours(grayDiff, 40, (340*240), 40, true);
        
        //もし物体が1つ以上検出されたら処理を実行
        if(contourFinder.nBlobs > 0){
            
            //輪郭線を単純化する
            contourAnalysis.simplify(contourFinder.blobs[0].pts, simpleCountour, simpleAmount);
            //線分の頂点座標
            ofPoint p;
            //線の連なりをBox2Dの世界に配置
            // lineStrip.setWorld(box2d.getWorld());
            lineStrip.create(box2d.getWorld());
            //前回使用した線を破棄
            lineStrip.clear();
            
            //指定した方向に、輪郭線をなぞる
            if(bReversePoints) {
                //逆回り
                for(int i=simpleCountour.size()-1; i>0; i--) {
                    
                    //単純化した輪郭線の頂点の座標を取得
                    p.x = simpleCountour[i].x*ofGetWidth()/320;
                    p.y = simpleCountour[i].y*ofGetHeight()/240;
                    //線分の連なりに、頂点の座標を追加
                    // lineStrip.addPoint(p.x, p.y);
                    lineStrip.addAttractionPoint(p.x, p.y);
                }
            }
            else {
                //通常回り
                for(int i=0; i<simpleCountour.size(); i++) {
                    
                    //単純化した輪郭線の頂点の座標を取得
                    p.x = simpleCountour[i].x*ofGetWidth()/320;
                    p.y = simpleCountour[i].y*ofGetHeight()/240;
                    //線分の連なりに、頂点の座標を追加
                    // lineStrip.addPoint(p.x, p.y);
                    lineStrip.addAttractionPoint(p.x, p.y);
                }
            }
            //線分の連なった形態の生成
            // lineStrip.createShape();
            lineStrip.draw();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //カメラから入力された映像を描画
    colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    //輪郭線を描く
    lineStrip.draw();
    
    //circlesに格納された全ての図形を描画
    for(int i=0; i<circles.size(); i++) {
        circles[i].draw();
    }
    
    //ログを表示
    ofSetColor(255, 255, 255);
    string info = "FPS: "+ofToString(ofGetFrameRate());
    info += "¥nThreshold: "+ofToString(threshold);
    info += "¥nNumber of Blobs: "+ofToString(contourFinder.nBlobs);
    info += "¥nSimple Amount: "+ofToString(simpleAmount);
    info += "¥npress [r] to toggle points direction." + ofToString(bReversePoints);
    info += "¥nPress [space] to capture background.";
    info += "¥nPress [+/-] to change threshold";
    info += "¥nPress [1/2] to change simple amount";
    ofDrawBitmapString(info, 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key){
            
        case ' ': //スペースキーで背景をとりこみ
            bLearnBakground = true;
            break;
        case '+': //[+]キーで背景の閾値のレベルを上げる(最大255)
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-': //[-]キーで背景の閾値のレベルを下げる(最小0)
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
        case '1': //[1]キーで輪郭線をより複雑に
            simpleAmount -= 0.01;
            break;
        case '2': //[2]キーで輪郭線をより単純に
            simpleAmount += 0.01;
            break;
        case 'r': //[r]キーで輪郭線を繋ぐ向きを逆転
            bReversePoints = !bReversePoints;
            break;
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
    //マウスをクリックすると新規にパーティクルを追加
    float r = ofRandom(10, 20); //半径を設定
    CustomCircle c; //CustomCircleクラスをインスタンス化
    c.setPhysics(0.00001, 0.9, 0.001); //物理パラメータを設定
    c.setup(box2d.getWorld(), mouseX, mouseY, r); //マウスの位置に円を設定
    circles.push_back(c); //生成した円をcirclesベクターに追加
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
