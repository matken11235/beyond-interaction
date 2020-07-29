#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面の設定
    ofBackground(0, 0, 0);
    ofSetCircleResolution(32);
    ofEnableAlphaBlending();
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    //blobsに格納されたofBlobのインスタンスの数だけupdate()をくりかえす
    for (int i=0; i<blobs.size(); i++) {
        blobs[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //blobsに格納されたofBlobのインスタンスの数だけdraw()をくりかえす
    for (int i=0; i<blobs.size(); i++) {
        blobs[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) { //タイプしたキーを判定
        case 'f': //入力したキーが「f」なら、フルスクリーン表示に切り替える
            ofToggleFullscreen();
            break;
        case 'r': //入力したキーが「r」なら、全ての円をクリア
            blobs.clear();
    }
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
    int bSize = blobs.size(); //blobsの要素数をbSizeに格納
    
    if (bSize < 1) { //もしまだ一つもなければ、新規にofBlobを追加
        ofBlob b = ofBlob(); //インスタンス化
        float dim = ofGetHeight()/3; //大きさを画面サイズの1/3に
        b.setDim(dim); //大きさを設定
        b.setSpeed(ofPoint(0,0)); //スピードは0で設定
        b.setPos(ofPoint(mouseX, mouseY)); //位置は画面の中心に設定
        blobs.push_back(b); //動的配列blobsにofBlobのインスタンスbを追加
    }
    
    //もし画面に1つでも円が表示されていたら、クリックした円を4つに分裂させる
    for (int i=0; i<bSize; i++) { //要素の数だけくりかえし
        ofPoint pos = blobs[i].getPos(); //円の位置を取得してposに代入
        
        float dim = blobs[i].getDim(); //円の大きさを取得してdimに代入
        float dist = ofDist(pos.x, pos.y, mouseX, mouseY); //マウスの位置と円の位置の距離を測定
        
        if(dist < dim){ //もしクリックした場所が円の内部だったら、分裂させる
            
            //円1:自分自身を縮小し、左に移動
            blobs[i].setDim(dim*0.6); blobs[i].setPos(ofPoint(pos.x-dim*0.7,pos.y));
            blobs[i].setSpeed(ofPoint(ofRandom(-dim/150,dim/150), ofRandom(-dim/150,dim/150)));
            
            //円2:新規にofBlobを生成し、右に配置
            ofBlob b1 = ofBlob();
            b1.setDim(dim*0.6); b1.setPos(ofPoint(pos.x+dim*0.7,pos.y));
            b1.setSpeed(ofPoint(ofRandom(-dim/150,dim/150), ofRandom(-dim/150,dim/150)));
            blobs.push_back(b1);
            
            //円3:新規にofBlobを生成し、上に配置
            ofBlob b2 = ofBlob();
            b2.setDim(dim*0.6); b2.setPos(ofPoint(pos.x,pos.y-dim*0.7));
            b2.setSpeed(ofPoint(ofRandom(-dim/150,dim/150), ofRandom(-dim/150,dim/150)));
            blobs.push_back(b2);
            
            //円4:新規にofBlobを生成し、下に配置
            ofBlob b3 = ofBlob();
            b3.setDim(dim*0.6); b3.setPos(ofPoint(pos.x,pos.y+dim*0.7));
            b3.setSpeed(ofPoint(ofRandom(-dim/150,dim/150), ofRandom(-dim/150,dim/150)));
            blobs.push_back(b3);
        }
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
