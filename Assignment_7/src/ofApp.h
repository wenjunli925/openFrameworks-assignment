#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void exit();
    
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
    
    void playPressed();
    void stopPressed();
    
    ofxPanel gui;
    
    ofSoundPlayer soundPlayer1, soundPlayer2, soundPlayer3, soundPlayer4;
    ofSoundPlayer music;

    
    ofxColorSlider color;
    
    ofxVec3Slider position;
    ofxFloatSlider scale;
    
    ofxLabel emotion;
    ofxIntSlider yaw;
    ofxIntSlider pitch;
    ofxIntSlider roll;
    
    ofxButton happy,sad,surprised,angry;
    ofxFloatSlider voiceVolume;
    
    ofxLabel backgroundMusic;
    ofxButton play;
    ofxButton stop;
    ofxFloatSlider musicVolume;
    
};
