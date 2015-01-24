#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground( 255, 255, 255 );
    
    for( int i = 0; i < 3; i++ ){
        pitchs.push_back( 0 );
        velocitys.push_back( 0 );
    }
    
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    string msg = "";
    msg += "FPS: " + ofToString( ofGetFrameRate() ) + "\n";
    msg += "receiver: " + ofToString( receiver.hasWaitingMessages() ) + "\n";
    
//    pitchs.clear();
//    velocitys.clear();
    
    // OSCの個数分繰り返す
    int index = 0;
    while(receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        string address = m.getAddress();
        vector <string> splitAddress = ofSplitString(address, "/");
        int ch = ofToInt(splitAddress[1]);
        string type = splitAddress[2];
        float value = ofToFloat(splitAddress[3]);
        
        msg += "ch: " + ofToString(ch) + ", type: " + type + ", value: " + ofToString(value) + "\n";
        
        if( type == "pitch" ){
            pitchs[ch] = value;
        }
        
        if( type == "velocity" ){
            velocitys[ch] = value;
        }
        
        index++;
    }
    
    // ビジュアライズ
    drawVisual();
    
    ofSetColor( 0, 0, 0, 255 );
    ofDrawBitmapString( msg, 30, 30 );
}

//--------------------------------------------------------------
void ofApp::drawVisual(){
    
    float ww = ofGetWidth();
    float wh = ofGetHeight();
    
    
    for( int i = 0; i < 3; i++ ){
        ofCircle( ww * 0.5 - 200 + 200 * i, wh * 0.5 - 100, pitchs[i] );
        ofCircle( ww * 0.5 - 200 + 200 * i, wh * 0.5 + 100, velocitys[i] );
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}