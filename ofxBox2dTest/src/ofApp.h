#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{
    private:
        ofxBox2d world2d;
        ofPolyline groundLine, cupLine;
        vector <ofPtr<ofxBox2dCircle> > circles;
        vector <ofPtr<ofxBox2dRect> > boxes;
        ofPtr<ofxBox2dPolygon> cup;

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
		
};
