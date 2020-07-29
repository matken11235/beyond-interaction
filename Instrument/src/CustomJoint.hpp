//
//  CustomJoint.hpp
//  Instrument
//
//  Created by KEN on 2017/03/21.
//
//

#ifndef CustomJoint_hpp
#define CustomJoint_hpp

#include <stdio.h>
#include "ofxBox2d.h"

class CustomJoint : public ofxBox2dJoint {
public:
    //「ばね」を描画
    void draw();
};

#endif /* CustomJoint_hpp */
