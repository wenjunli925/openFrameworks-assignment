#include "ofApp.h"

//ofVec3f corner;

int a;
bool fhappy, fsad, fsurprised, fangry;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1600, 900);
    ofSetVerticalSync(true);
    
    gui.setup();
//    gui.setDefaultWidth(300);
    
    gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    
    gui.add(position.setup("position", {ofGetWidth()*.5, ofGetHeight()*.5, 0}, {0, 0, 100}, {ofGetWidth(), ofGetHeight(), -200}));
    gui.add(scale.setup("scale",1,0,2));
    gui.add(yaw.setup("yaw", 0, -45, 45));
    gui.add(pitch.setup("pitch", 0, -45, 45));
    gui.add(roll.setup("roll", 0, -45, 45));
    
    gui.add(emotion.setup("emotions","happy/sad/surprised/angry"));
    
    gui.add(happy.setup("happy"));
    gui.add(sad.setup("sad"));
    gui.add(surprised.setup("surprised"));
    gui.add(angry.setup("angry"));
    gui.add(voiceVolume.setup("voice volume",2.0,0.0,4.0));
    
    gui.add(backgroundMusic.setup("music","Electric Loop"));
    
    play.addListener(this, &ofApp::playPressed);
    stop.addListener(this, &ofApp::stopPressed);
    gui.add(play.setup("play"));
    gui.add(stop.setup("stop"));
     gui.add(musicVolume.setup("music volume",2.0,0.0,4.0));
    
    //    corner.set(ofGetWidth()*0.4, ofGetHeight()*0.35,0);
    
    a = 0;
    
    fhappy = false;
    fsad = false;
    fsurprised = false;
    fangry = false;
    
    soundPlayer1.load("happy.mp3");
    soundPlayer2.load("sad.mp3");
    soundPlayer3.load("surprised.mp3");
    soundPlayer4.load("angry.mp3");
    
    music.load("electronic loop.wav");
    music.setLoop(true);
}

void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()%6 == 0){
        a++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::whiteSmoke,ofColor::grey);
    gui.draw();
    soundPlayer1.setVolume(voiceVolume);
    soundPlayer2.setVolume(voiceVolume);
    soundPlayer3.setVolume(voiceVolume);
    soundPlayer4.setVolume(voiceVolume);
    music.setVolume(musicVolume);
    
    
    ofTranslate(position);
    
    ofRotateYDeg(yaw);
    ofRotateXDeg(pitch);
    ofRotateZDeg(roll);
    
    int b;
    b = a % 6;
    
    ofScale(scale,scale,scale);
    
    if(happy){
        fhappy = true;
        fsad = false;
        fsurprised = false;
        fangry = false;
        
        soundPlayer1.play();
    }
    if(sad){
        fhappy = false;
        fsad = true;
        fsurprised = false;
        fangry = false;
        soundPlayer2.play();
    }
    if(surprised){
        fhappy = false;
        fsad = false;
        fsurprised = true;
        fangry = false;
        soundPlayer3.play();
    }
    if(angry){
        fhappy = false;
        fsad = false;
        fsurprised = false;
        fangry = true;
        soundPlayer4.play();
    }
    
    if(fhappy){
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k <6; k++){
                    if((i == 1 || i ==4) &&  j == 1 && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else if(((i == 0 && j == 3) || (i == 1 && j == 4) || (i == 2 && j == 5) || (i == 3 && j == 5) || (i == 4 && j == 4) || (i == 5 && j == 3)) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else{
                        ofNoFill();
                        ofSetColor(color);
                    }
                    ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                }
            }
        }
        ofPopMatrix();
    }
    
    if(fsad){
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k <6; k++){
                    if((i == 1 || i ==4) &&  j == 1 && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else if(((i == 0 && j == 5) || (i == 1 && j == 4) || (i == 2 && j == 4) || (i == 3 && j == 4) || (i == 4 && j == 4) || (i == 5 && j == 5)) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else{
                        ofNoFill();
                        ofSetColor(color);
                    }
                    ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                }
            }
        }
        ofPopMatrix();
    }
    
    if(fsurprised){
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k <6; k++){
                    if((i == 1 || i ==4) &&  j == 0 && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else if((((i == 2 || i == 3) && (j == 2 || j == 5)) || ((i == 1 || i == 4) && (j == 3 || j ==4))) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else{
                        ofNoFill();
                        ofSetColor(color);
                    }
                    ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                }
            }
        }
        ofPopMatrix();
    }
    if(fangry){
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k <6; k++){
                    if((((i == 0 || i ==5) &&  j == 0) || ((i == 1 || i == 4) &&  j == 1)) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else if((((i == 2 || i == 3) && (j == 2 || j == 5)) || ((i == 1 || i == 4) && (j == 3 || j ==4))) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else{
                        ofNoFill();
                        ofSetColor(color);
                    }
                    ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                }
            }
        }
        ofPopMatrix();
    }
    
    else{
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
                   for(int j = 0; j < 6; j++){
                       for(int k = 0; k <6; k++){
                           ofNoFill();
                           ofSetColor(color);
                           ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                       }
                   }
        }
        ofPopMatrix();
    }
    
    if(fangry){
        ofPushMatrix();
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                for(int k = 0; k <6; k++){
                    if((((i == 0 || i ==5) &&  j == 0) || ((i == 1 || i == 4) &&  j == 1)) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else if((((i == 2 || i == 3) && (j == 2 || j == 5)) || ((i == 1 || i == 4) && (j == 3 || j ==4))) && k == b){
                        ofFill();
                        ofSetColor(255,0,0,150);
                    } else{
                        ofNoFill();
                        ofSetColor(color);
                    }
                    ofDrawBox(-225+80*i,-225+80*j, -255+80*k, 50, 50, 50);
                }
            }
        }
        ofPopMatrix();
    }
    
    
}

void ofApp::playPressed(){
    music.play();
}

void ofApp::stopPressed(){
    music.stop();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
