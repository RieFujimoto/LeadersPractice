#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    private :
    int divX = 30;
    int divY = 22;
    int x_line = 0;
    int y_line = 0;
    int size_circle = 10;
    float dis_x; //= x_line - ofGetWidth()/2;
    float dis_y; //= y_line - ofGetHeight()/2;
    float ofSetX = ofGetWidth()/divX;
    float ofSetY = ofGetHeight()/divY;
    bool vib;
    float r;
    
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
