#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "127.0.0.1"
#define PORT 7401

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void drawVisual();
    ofxOscReceiver receiver;
    vector <float> pitchs;
    vector <float> velocitys;
};
