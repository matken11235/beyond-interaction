//
//  ofBlob.hpp
//  NEWoF3-3
//
//  Created by KEN on 2017/03/20.
//
//

#ifndef ofBlob_hpp
#define ofBlob_hpp

#include "ofMain.h"

class ofBlob {
private:
    ofPoint pos; // 円の位置
    float dim; // 円の半径
    ofPoint speed; //円の移動スピード
    float phase; //円の伸縮運動の位相
    float phaseSpeed; //円の伸縮スピード
    float movedDim; //伸縮した結果の半径
    
public:
    ofBlob(); // コンストラクタ
    
    void draw(); //円を描く
    void update(); //円の移動
    
    void setDim(float dim); //dimセッター
    float getDim(); //dimゲッター
    void setPos(ofPoint pos); //posセッター
    ofPoint getPos(); //posゲッター
    void setSpeed(ofPoint speed); //speedセッター
    ofPoint getSpeed(); //speedゲッター
};

#endif /* ofBlob_hpp */
