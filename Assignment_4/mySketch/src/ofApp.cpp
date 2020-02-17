#include "ofApp.h"

float windowWidth, windowHeight;

ofVec2f center;

float eyebrowWidth, eyebrowHeight;

ofVec2f pleftEyebrow1, pleftEyebrow2, prightEyebrow1, prightEyebrow2, pmouth;
ofVec2f leftEyebrow1p, leftEyebrow2p, rightEyebrow1p, rightEyebrow2p, mouthp;

ofVec2f leftEyebrow1, leftEyebrow2, rightEyebrow1, rightEyebrow2;
ofVec2f offset1, offset2, offset3, offset4;

ofVec2f mouth;
ofVec2f offsetmouth;

bool start;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowShape(400, 400);
    ofSetCircleResolution(50);
    
    windowWidth = ofGetWindowWidth();
    windowHeight = ofGetWindowHeight();
    
    center.set(windowWidth*0.5, windowHeight*0.5);
    
    eyebrowWidth = 50;
    eyebrowHeight = 5;
    
    offsetmouth.set(0,10);
    
    start = false;
    setInitialPositions();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()>120){
        start = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(start == false){
        drawShapes();
    }
    
    if(start == true){
        Relocate();
        
        int num = ((ofGetFrameNum()-120)/120)%4;
        
        if(num == 0){
           setHappinessPosition();
            Move();
            drawHappiness();
        } else if(num == 1){
            setSadnessPosition();
            Move();
            drawSadness();
        } else if(num == 2){
            setSurprisePosition();
            Move();
            drawSurprise();
        } else if(num == 3){
            setAngerPosition();
            Move();
            drawAnger();
        }
    }
    
}

void ofApp::setInitialPositions(){
    leftEyebrow1.set(ofRandom(windowWidth), ofRandom(windowHeight));
    leftEyebrow2.set(ofRandom(windowWidth), ofRandom(windowHeight));
    rightEyebrow1.set(ofRandom(windowWidth), ofRandom(windowHeight));
    rightEyebrow2.set(ofRandom(windowWidth), ofRandom(windowHeight));
    mouth.set(ofRandom(windowWidth), ofRandom(windowHeight));
}

void ofApp::drawShapes(){
    ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofDrawRectangle(leftEyebrow1, eyebrowWidth, eyebrowHeight);
    ofDrawRectangle(leftEyebrow2, eyebrowWidth, eyebrowHeight);
    ofDrawRectangle(rightEyebrow1, eyebrowWidth, eyebrowHeight);
    ofDrawRectangle(rightEyebrow2, eyebrowWidth, eyebrowHeight);
    
    ofPath path;
//    mouth = center+offsetmouth;
    ofDrawRectangle(mouth - offsetmouth, 80, 20);
    path.arc(mouth, 40, 40, 0, 180);
    path.draw();
    
    
    //    ofDrawCircle(center,10);
}

void ofApp::Relocate(){
    pleftEyebrow1 = leftEyebrow1;
    pleftEyebrow2 = leftEyebrow2;
    prightEyebrow1 = rightEyebrow1;
    prightEyebrow2 = rightEyebrow2;
    pmouth = mouth;
}


void ofApp::setHappinessPosition(){
    offset1.set(-40,-60);
    offset2.set(-40,-40);
    offset3.set(40,-60);
    offset4.set(40,-40);
    
    leftEyebrow1p = center + offset1;
    leftEyebrow2p = center + offset2;
    rightEyebrow1p = center + offset3;
    rightEyebrow2p = center + offset4;
    mouthp = center+offsetmouth;
}

void ofApp::setSadnessPosition(){
    offset1.set(-40,-60);
    offset2.set(-40,-35);
    offset3.set(40,-60);
    offset4.set(40,-35);
    
    leftEyebrow1p = center + offset1;
    leftEyebrow2p = center + offset2;
    rightEyebrow1p = center + offset3;
    rightEyebrow2p = center + offset4;
    mouthp = center+2*offsetmouth;
}

void ofApp::setSurprisePosition(){
    offset1.set(-40,-70);
    offset2.set(-40,-30);
    offset3.set(40,-70);
    offset4.set(40,-30);
    
    leftEyebrow1p = center + offset1;
    leftEyebrow2p = center + offset2;
    rightEyebrow1p = center + offset3;
    rightEyebrow2p = center + offset4;
    mouthp = center + 2*offsetmouth;
}

void ofApp::setAngerPosition(){
    offset1.set(-40,-60);
    offset2.set(-10,-60);
    offset3.set(40,-60);
    offset4.set(10,-60);
    
    leftEyebrow1p = center + offset1;
    leftEyebrow2p = center + offset2;
    rightEyebrow1p = center + offset3;
    rightEyebrow2p = center + offset4;
    mouthp = center + offsetmouth;
}

void ofApp::drawHappiness(){
    ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(leftEyebrow1);
    ofRotateZDeg(15);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(leftEyebrow2);
    ofRotateZDeg(-15);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow1);
    ofRotateZDeg(-15);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow2);
    ofRotateZDeg(15);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPath path;
    ofDrawRectangle(center, 80, 20);
    
    path.arc(mouth, 40, 40, 0, 180);
    path.draw();
    
    
    //    ofDrawCircle(center,10);
}

void ofApp::drawSadness(){
    ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(leftEyebrow1);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(leftEyebrow2);
    ofRotateZDeg(-90);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow1);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow2);
    ofRotateZDeg(90);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPath path;
    ofDrawRectangle(mouth+offsetmouth, 80, 20);
    
    path.arc(mouth, 40, 40, 180, 360);
    path.draw();
    
    
    //    ofDrawCircle(center,10);
}

void ofApp::drawSurprise(){
    ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(leftEyebrow1);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(leftEyebrow2);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow1);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow2);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofDrawEllipse(mouth, 50, 80);
    
    ofVec2f leftEye,rightEye;
    leftEye.set(leftEyebrow1.x, 0.5 * (leftEyebrow1.y + leftEyebrow2.y));
    rightEye.set(rightEyebrow1.x, 0.5 * (rightEyebrow1.y + rightEyebrow2.y));
    ofDrawCircle(leftEye, 9);
    ofDrawCircle(rightEye, 9);
    
    
    //    ofDrawCircle(center,10);
}
void ofApp::drawAnger(){
    ofSetColor(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    ofTranslate(leftEyebrow1);
    ofRotateZDeg(30);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(leftEyebrow2);
    ofRotateZDeg(-90);
    ofDrawRectangle(0, 0, eyebrowWidth * 0.3, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow1);
    ofRotateZDeg(-30);
    ofDrawRectangle(0, 0, eyebrowWidth, eyebrowHeight);
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(rightEyebrow2);
    ofRotateZDeg(90);
    ofDrawRectangle(0, 0, eyebrowWidth * 0.3, eyebrowHeight);
    ofPopMatrix();
    
    ofDrawEllipse(mouth, 60, 70);
    
    
    //    ofDrawCircle(center,10);
}

void ofApp::Move(){
    leftEyebrow1.x += 0.1 * (leftEyebrow1p.x - leftEyebrow1.x);
    leftEyebrow1.y += 0.1 * (leftEyebrow1p.y - leftEyebrow1.y);
    
    leftEyebrow2.x += 0.1 * (leftEyebrow2p.x - leftEyebrow2.x);
    leftEyebrow2.y += 0.1 * (leftEyebrow2p.y - leftEyebrow2.y);
    
    rightEyebrow1.x += 0.1 * (rightEyebrow1p.x - rightEyebrow1.x);
    rightEyebrow1.y += 0.1 * (rightEyebrow1p.y - rightEyebrow1.y);
    
    rightEyebrow2.x += 0.1 * (rightEyebrow2p.x - rightEyebrow2.x);
    rightEyebrow2.y += 0.1 * (rightEyebrow2p.y - rightEyebrow2.y);
    
    mouth.x += 0.1 * (mouthp.x - mouth.x);
    mouth.y += 0.1 * (mouthp.y - mouth.y);

    
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
