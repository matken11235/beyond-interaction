//
//  CustomCircle.hpp
//  Instrument
//
//  Created by KEN on 2017/03/21.
//
//

#ifndef CustomCircle_hpp
#define CustomCircle_hpp

#include <stdio.h>
#include "ofxBox2d.h"

//ofxBox2dCircleを継承したクラスCustomCircleを定義
class CustomCircle : public ofxBox2dCircle {
public:
    CustomCircle(int num);
    void update(); //設定の更新
    void draw(); //パラメータを描画する
    int num; //パーティクルの番号
    ofSoundPlayer mySound; //音の再生クラスofSoundPlayerをインスタンス化
    float radius; //半径
    float soundSpeed; //音の再生スピード(ピッチ)
};

#endif /* CustomCircle_hpp */
