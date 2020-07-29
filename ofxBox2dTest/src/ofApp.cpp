#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //  window
    ofBackground(0, 0, 0);
    ofSetWindowShape(640, 480);
    
    //  box2d
    world2d.init();
    world2d.setFPS(60.0);
    world2d.registerGrabbing();
    
    //  ground
    world2d.createGround(100, 400, 540, 400);
    groundLine.addVertex(100, 400);
    groundLine.addVertex(540, 400);
    
    //  make a cup
    cupLine.addVertex(200, 200);
    cupLine.addVertex(210, 200);
    cupLine.addVertex(210, 390);
    cupLine.addVertex(430, 390);
    cupLine.addVertex(430, 200);
    cupLine.addVertex(440, 200);
    cupLine.addVertex(440, 400);
    cupLine.addVertex(200, 400);
    cupLine.close();
    cup = ofPtr<ofxBox2dPolygon>(new ofxBox2dPolygon);
    cup.get()->addVertexes(cupLine);
    cup.get()->triangulatePoly(10);
    cup.get()->setPhysics(0.0, 0.5, 0.1);
    cup.get()->create(world2d.getWorld());
}

//--------------------------------------------------------------
void ofApp::update(){
    world2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //  draw the ground and cup
    ofSetColor(255, 255, 255);
    groundLine.draw();
    cupLine.draw();
    
    //  draw each circle
    ofSetColor(255, 150, 150);
    for (int i = 0; i < circles.size(); i++)
        circles[i].get()->draw();
    
    //  draw each box
    ofSetColor(150, 255, 150);
    for (int i = 0; i < boxes.size(); i++)
        boxes[i].get()->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        //  create a new circle
        ofPtr<ofxBox2dCircle> circle = ofPtr<ofxBox2dCircle>(new ofxBox2dCircle);
        //  set attributes to this circle (density, bounce, friction)
        circle.get()->setPhysics(1.0, 0.5, 0.1);
        circle.get()->setup(world2d.getWorld(), mouseX, mouseY, ofRandom(10, 20));
        //  add this circle to "circles" vector
        circles.push_back(circle);
    }
    else if (key == 'b') {
        //  create a new box
        ofPtr<ofxBox2dRect> box = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
        //  set attributes to this box (density, bounce, friction)
        box.get()->setPhysics(1.0, 0.5, 0.1);
        box.get()->setup(world2d.getWorld(), mouseX, mouseY, ofRandom(20, 40), ofRandom(20, 40));
        //  add this circle to "circles" vector
        boxes.push_back(box);
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
