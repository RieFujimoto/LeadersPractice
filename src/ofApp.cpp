#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetCircleResolution(100);
    ofSetFrameRate(100);
}

//--------------------------------------------------------------
void ofApp::update(){
    dis_x = mouseX - ofGetWidth()/2.0;
    dis_y = mouseY - ofGetHeight()/2.0;
    
    if(vib == true){
        r = sqrt( dis_x * dis_x + dis_y * dis_y ) + ofRandom(-10, 10);
    }else{
        r = sqrt( dis_x * dis_x + dis_y * dis_y );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < divX; i++){
        ofDrawLine(ofSetX*i, 0, ofSetX*i, ofGetHeight());
    }
    
    for(int i = 0; i < divY; i++){
        ofDrawLine(0, ofSetY*i, ofGetWidth(), ofSetY*i);
    }
    
    ofPushStyle();
    ofSetColor(70, 70, 70, 100);
    // 十字の交差線の表示
    ofDrawLine(0, y_line, ofGetWidth(), y_line);
    ofDrawLine(x_line, 0, x_line, ofGetHeight());
    // 中心と的を結ぶ直線
    ofDrawLine(ofGetWidth()/2, ofGetHeight()/2, x_line, y_line);
    ofPopStyle();
    
    float radian = atan2(dis_x, dis_y);
    float degree = radian*180.0/PI;
    float change_color = ofMap(degree, -180, 180, 0, 255);
    ofSetColor(ofColor::fromHsb(change_color, 225, 225));

    // 円（塗りつぶし）の表現
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, r/4);
    // 円（枠線のみ）の表現
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, r);
    cout << r << endl;
    ofPopStyle();
    
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0);
    
    
    float theta = atan2(-dis_y, dis_x); // -pi ~ pi
    float _theta = theta + PI; // 範囲を変換 0 ~ 2pi
    float div = 100.0;
    
    if(vib == true){
    ofBeginShape();
    ofSetColor(10, 10, 10, 100);
    ofVertex(0, 0);
    for(int i = 0; i < div; i++){
        float x = r * cos((_theta/div)*i);
        float y = -r * sin((_theta/div)*i);
        ofVertex(x, y);
    }
    ofEndShape();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        vib = !vib;
//        cout << vib << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // マウスの動きの反映
    x_line = x;
    y_line = y;
    
//
//    ofVec2f mouse;
//    mouse.set(x, y);
//
    
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
