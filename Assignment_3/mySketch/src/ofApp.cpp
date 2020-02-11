#include "ofApp.h"
int drawingMode;

int startTime;
int currentTime;
int interval;
int num = -1;
bool finishDrawing = false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
        finishDrawing = false;
        
        if(drawingMode == 1){
            ofSetColor(255);
            ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 3);
        }
        
        if(drawingMode == 2){
            ofSetColor(255);
            ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 20);
        }
        
        if(drawingMode == 3){
            ofSetColor(255);
            ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 30, 30);
        }
        
        if(drawingMode == 4){
            ofSetColor(255);
            ofDrawTriangle(ofGetMouseX(), ofGetMouseY(),ofGetMouseX()-15, ofGetMouseY()+30,ofGetMouseX()+15, ofGetMouseY()+30);
        }
    }
    
    
    if(ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)){
        startTime = ofGetFrameNum();
        finishDrawing = true;
    }
    
    currentTime = ofGetFrameNum();
    
    if(finishDrawing == true){
        interval = currentTime - startTime;
        if(interval >= 120){
            ofBackground(0);
            if (interval % 120 == 0){
                num++;
            }
            
            if(num % 3 == 0){
                for(int i = 0; i<50; i++){
                    ofNoFill();
                    ofSetLineWidth(2);
                    ofDrawCircle(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5, i*20);
                }
            }
            if(num % 3 == 1){
                for(int i = 0; i<70; i++){
                    ofNoFill();
                    ofSetLineWidth(2);
                    ofSetRectMode(OF_RECTMODE_CENTER);
                    ofDrawRectangle(ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5, i*30, i*30);
                }
            }
            if(num % 3 == 2){
                ofDrawBitmapString("Don't Cry", ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5);
            }
        }
        
        
    }
    
    cout<<interval<<endl;
    cout<<finishDrawing<<endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        drawingMode = 1;
    }
    if(key == 's'){
        drawingMode = 2;
    }
    if(key == 'd'){
        drawingMode = 3;
    }
    if(key == 'f'){
        drawingMode = 4;
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
