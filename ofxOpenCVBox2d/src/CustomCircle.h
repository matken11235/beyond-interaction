//
//  CustomCircle.h
//  ofxOpenCVBox2d
//
//  Created by KEN on 2017/03/21.
//
//

#pragma once

#include "ofxBox2d.h"

//ofxBox2dCircleを継承したクラスCustomCircleを定義
class CustomCircle : public ofxBox2dCircle {
public:
    void draw(); //円を描画する
};
