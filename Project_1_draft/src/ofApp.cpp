#include "ofApp.h"

bool scene1, scene2, scene3, scene4,scene5, scene6, scene7;
bool transition23;
bool aliensPosition;
bool drawCircles, drawCircles2;
bool fkeyPressed;

ofTrueTypeFont ArvoRegular, ArvoItalic, ArvoBold, Results;
ofTrueTypeFont ButtonText;

ofVec2f center;
ofVec2f earthTarget, sunTarget;
ofVec2f earth, moon, orbit, sun;
ofVec2f button1, button2;

int count1, count2, count3, count4;
float BGMVolume;
float textAlpha;
int aliensX[15];
int aliensY[15];
int aliensSize[15];
int aliensOriginalSize[15];
float steps[15];
float earthSize,sunSize,earthTargetSize,sunTargetSize;
float shrink1,shrink2;
float degrees;
float enlarge,alpha;
float aliens;
float earthAlpha;
float fading;


ofImage doublequote1, doublequote2;
ofImage earthImage, moonImage, sunImage;

ofSoundPlayer BGM, radioSignal;

//ofFbo fbo;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200, 700);
    
    ArvoRegular.load("fonts/Arvo-Regular.ttf",30);
    ArvoItalic.load("fonts/Arvo-Italic.ttf",30);
    ArvoBold.load("fonts/Arvo-Bold.ttf",50);
    Results.load("fonts/Arvo-Bold.ttf",150);
    
    doublequote1.load("images/dq1.png");
    doublequote2.load("images/dq2.png");
    earthImage.load("images/earth.png");
    moonImage.load("images/moon.png");
    sunImage.load("images/sun.png");
    
    BGM.load("sound/Shepard Tone.wav");
    BGM.setLoop(true);
    BGM.setVolume(0.2);
    BGM.play();
    
    radioSignal.load("sound/Radio Signal Sound Effect.mp3");
    
    scene1 = true;
    scene2 = false;
    scene3 = false;
    scene4 = false;
    scene5 = false;
    transition23 = false;
    aliensPosition = false;
    
    count1 = 0;
    count2 = 0;
    count3 = 0;
    count4 = 0;
    
    BGMVolume = 0.2;
    
    textAlpha = 255;
    
    degrees = 0;
    
    center.set(ofGetWindowWidth()*0.5,ofGetWindowHeight()*0.5);
    button1.set(60,120);
    button2.set(60,190);
    
    shrink1 = 1;
    shrink2 = 1;
    
    drawCircles = false;
    drawCircles2 = false;
    
    enlarge = 1.5;
    alpha = 255;
    
    earthAlpha = 255;
    
    fading = 0;
    
    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(!count2){
        count1++;
    }
    if(count1>900){
        count2++;
    }
    
    degrees++;
    
    if(fkeyPressed == true){
        fading += 1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(scene1){
        drawScene1();
    }
    
    if(BGMVolume < 0 && transition23 == false){
        drawScene2();
    }
    
    if(transition23 == true && scene3 == false){
        drawTransition23();
        scene2 = false;
    }
    
    if(scene3){
        drawScene3();
    }
    
    if(scene3 == true && drawCircles == false){
        if(scene4){
            drawScene4();
        } else if(scene5){
            drawScene5();
        } else if(scene6){
            drawScene6();
        } else if(scene7){
            drawScene7();
        } else{
        }
    }
    
    if(fkeyPressed){
        ofSetColor(255,fading);
        ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    }
}

void ofApp::drawScene1(){
    if(count1>0 && count1<=900){
        ofSetColor(255);
        ArvoBold.setLetterSpacing(1.3);
        ArvoBold.drawString("DARK  FOREST  THEORY", 150, 110);
        ArvoItalic.setLineHeight(60);
        ArvoItalic.drawString("         The universe is a dark forest. Every civilization \nis an armed hunter stalking through the trees like \na ghost, gently pushing aside branches that block \nthe path and trying to tread without sound. Even \nbreathing is done with care. The hunter has to be \ncareful, because everywhere in the forest are \nstealthy hunters like him. If he finds other life,",100,220);
        
        doublequote1.draw(100,160,91,55);
        
        
        for(int i = 0; i < 8; i++){
            if(count1/120 == i){
                int alpha = 240-(count1 % 120)*2;
                ofSetColor(0,alpha);
            } else if(count1/120 > i){
                ofSetColor(0,0);
            } else {
                ofSetColor(0,255);
            }
            ofDrawRectangle(0, 160+i*63, ofGetWidth(), 63);
        }
    }
    
    if(count2>0 && count2<960){
        ofSetColor(255);
        ArvoBold.setLetterSpacing(1.3);
        ArvoBold.drawString("DARK  FOREST  THEORY", 150, 110);
        ArvoItalic.setLineHeight(60);
        ArvoItalic.drawString("another hunter, an angel or a demon, a delicate, \ninfant or a tottering old man, a fairy or a demigod, \nthere’s only one thing he can do: open fire and \neliminate them. In this forest, hell is other people. \nAn eternal threat that any life that exposes its own \nexistence will be swiftly wiped out. This is the picture \nof cosmic civilization. It’s the explanation for the \nFermi Paradox.” ",100,200);
        
        doublequote2.draw(430,570,91,55);
        
        for(int i = 0; i < 8; i++){
            if(count2/120 == i){
                int alpha = 240-(count2 % 120)*2;
                ofSetColor(0,alpha);
            } else if(count2/120 > i){
                ofSetColor(0,0);
            } else {
                ofSetColor(0,255);
            }
            ofDrawRectangle(0, 150+i*60, ofGetWidth(), 63);
        }
    }
    
    if(count2 >= 960){
        ofSetColor(255,textAlpha);
        ArvoRegular.setLineHeight(60);
        ArvoRegular.drawString("According to the Dark Forest theory by Liu Cixin, \nwe are not able to know if there is any other intelligent \ncreature outside the Milky Way galaxy.",100,250);
        
        BGMVolume -= 0.0005;
        BGM.setVolume(BGMVolume);
        
        if(BGMVolume < 0.08){
            textAlpha -= 2;
        }
    }
}

void ofApp::drawScene2(){
    scene1 = false;
    scene2 = true;
    
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(!aliensPosition){
        for(int i = 0; i<15; i++){
            aliensX[i] = rand()%1200;
            aliensY[i] = rand()%700;
            aliensOriginalSize[i] = aliensSize[i] = rand()%50;
            steps[i] = ofRandom(-2,2);
        }
        aliensPosition = true;
    }
    
    for(int j = 0; j<15; j++){
        if(aliensSize[j]+steps[j]>aliensOriginalSize[j]*1.5){
            steps[j] *= -1;
        }
        if(aliensSize[j]+steps[j]<aliensOriginalSize[j]*0.5){
            steps[j] *= -1;
        }
        aliensSize[j] += steps[j];
        float alpha;
        alpha = ofMap(aliensSize[j],aliensOriginalSize[j]*0.5,aliensOriginalSize[j]*1.5,0,255);
        ofSetColor(25,alpha);
        ofDrawCircle(aliensX[j], aliensY[j], aliensSize[j]);
    }
    
    earthSize = 700;
    sunSize = 150;
    earthTargetSize = 160;
    sunTargetSize = 1176;
    earth.set(ofGetWidth()*0.5-earthSize/2,ofGetHeight()-(earthSize/2-100));
    sun.set(1000,80);
    earthTarget.set(center-80);
    sunTarget.set(ofGetWindowWidth()-600, ofGetWindowHeight()-500);
    
    ofFill();
    ofSetColor(0, 0, 200);
    earthImage.draw(earth,earthSize,earthSize);
    ofSetColor(255);
    sunImage.draw(sun,sunSize,sunSize);
    
    count3++;
    if(count3>180){
        ofSetColor(255);
        ArvoRegular.setLineHeight(60);
        ArvoRegular.drawString("Let's assume that there already are intelligent aliens \nliving on a planet that is not very far from the earth, \nbut we don’t know whether they are friendly or hostile. \n(Say the possibility of they are looking for peaceful \nco-existence is 50%.) What would you do?", 100, 200);
        ofPath arrow;
        
        arrow.moveTo(1130,600);
        arrow.lineTo(1160,620);
        arrow.lineTo(1130,640);
        
        arrow.close();
        arrow.setStrokeColor(255);
        arrow.setStrokeWidth(4);
        arrow.setFilled(true);
        arrow.draw();
        
        ofSetColor(255);
        ofDrawRectangle(1100,615,30,10);
    }
}

void ofApp::drawScene3(){
    scene1 = false;
    scene2 = false;
    scene3 = true;
    
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(drawCircles){
        ofSetColor(255,alpha);
        ofSetLineWidth(2);
        ofNoFill();
        ofDrawCircle(earth+earthSize/2, 10*enlarge);
        ofDrawCircle(earth+earthSize/2, 20*enlarge);
        ofDrawCircle(earth+earthSize/2, 30*enlarge);
        ofDrawCircle(earth+earthSize/2, 40*enlarge);
        ofDrawCircle(earth+earthSize/2, 50*enlarge);
        ofDrawCircle(earth+earthSize/2, 60*enlarge);
        ofDrawCircle(earth+earthSize/2, 70*enlarge);
        
        enlarge += 0.2;
        alpha -= 2;
    }
    
    if(10*enlarge>350){
        drawCircles = false;
        enlarge = 0;
        alpha = 255;
    }
    
    
    ofSetColor(0, 0, 200);
    ofFill();
    earthImage.draw(earth,160,160);
    moon = (earth+earthSize/2)+120;
    orbit = moon.rotate(degrees, (earth+earthSize/2));
    ofSetColor(150);
    moonImage.draw(moon-20,40,40);
    sunImage.draw(sun,1176,1176);
    
    
    ofSetColor(255);
    ArvoRegular.drawString("Make A Decision",60,80);
    
    ofRectangle b1,b2;
    ofSetColor(200,225);
    b1.x = button1.x+5;
    b1.y = button1.y+5;
    b2.x = button2.x+5;
    b2.y = button2.y+5;
    b1.width = 200*shrink1;
    b1.height = 45*shrink1;
    b2.width = 200*shrink2;
    b2.height = 45*shrink2;
    ofDrawRectRounded(b1, 8);
    ofDrawRectRounded(b2, 8);
    
    b1.x = button1.x;
    b1.y = button1.y;
    b2.x = button2.x;
    b2.y = button2.y;
    ofSetColor(255,225);
    ofDrawRectRounded(b1, 8);
    ofDrawRectRounded(b2, 8);
    
    ofSetColor(0);
    ButtonText.load("fonts/RobotoMono-Regular.ttf", 15*shrink1);
    ButtonText.drawString(" Send A Message", b1.x+10*shrink1, b1.y+30*shrink1);
    ButtonText.load("fonts/RobotoMono-Regular.ttf", 15*shrink2);
    ButtonText.drawString(" Keep Quiet", b2.x+10*shrink1, b2.y+30*shrink2);
    
}

void ofApp::drawScene4(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(earthAlpha>50){
        earthAlpha -= 0.5;
    }
    earth.set(center-80);
    ofSetColor(0, 0, 200,earthAlpha);
    ofFill();
    earthImage.draw(earth,160,160);
    
    
    for(int j = 0; j<15; j++){
        if(aliensSize[j]+steps[j]>aliensOriginalSize[j]*1.5){
            steps[j] *= -1;
        }
        if(aliensSize[j]+steps[j]<aliensOriginalSize[j]*0.5){
            steps[j] *= -1;
        }
        aliensSize[j] += steps[j];
        float alpha;
        alpha = ofMap(aliensSize[j],aliensOriginalSize[j]*0.5,aliensOriginalSize[j]*1.5,0,255);
        ofSetColor(25,alpha);
        ofDrawCircle(aliensX[j], aliensY[j], aliensSize[j]);
    }
    
    if(earthAlpha == 50){
        count4++;
        
        ofSetColor(255);
        if(count4<150){
            ArvoBold.setLetterSpacing(1.0);
            ArvoBold.drawString("They are friendly!",280,350);
        } else{
            ofSetColor(0,255,0);
            Results.setLetterSpacing(1.3);
            Results.drawString("SURVIVED",30,450);
            
            drawArrow2();
        }
    }
}

void ofApp::drawScene5(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(earthAlpha>50){
        earthAlpha -= 0.5;
    }
    earth.set(center-80);
    ofSetColor(0, 0, 200,earthAlpha);
    ofFill();
    earthImage.draw(earth,160,160);
    
    
    for(int j = 0; j<15; j++){
        if(aliensSize[j]+steps[j]>aliensOriginalSize[j]*1.5){
            steps[j] *= -1;
        }
        if(aliensSize[j]+steps[j]<aliensOriginalSize[j]*0.5){
            steps[j] *= -1;
        }
        aliensSize[j] += steps[j];
        float alpha;
        alpha = ofMap(aliensSize[j],aliensOriginalSize[j]*0.5,aliensOriginalSize[j]*1.5,0,255);
        if(j == 8){
            ofSetColor(255,0,0);
        } else{
            ofSetColor(25,alpha);
        }
        ofDrawCircle(aliensX[j], aliensY[j], aliensSize[j]);
    }
    
    if(earthAlpha == 50){
        count4++;
        
        ofSetColor(255);
        if(count4<150){
            ArvoBold.setLetterSpacing(1.0);
            ArvoBold.drawString("They are hostile!",280,350);
            ArvoBold.drawString("But you are keeping quiet.",200,430);
        } else{
            ofSetColor(0,255,0);
            Results.setLetterSpacing(1.3);
            Results.drawString("SURVIVED",30,450);
            
            drawArrow2();
        }
    }
}

void ofApp::drawScene6(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(earthAlpha>50){
        earthAlpha -= 0.5;
    }
    earth.set(center-80);
    ofSetColor(0, 0, 200);
    ofFill();
    earthImage.draw(earth,160,160);
    
    
    for(int j = 0; j<15; j++){
        if(aliensSize[j]+steps[j]>aliensOriginalSize[j]*1.5){
            steps[j] *= -1;
        }
        if(aliensSize[j]+steps[j]<aliensOriginalSize[j]*0.5){
            steps[j] *= -1;
        }
        aliensSize[j] += steps[j];
        float alpha;
        alpha = ofMap(aliensSize[j],aliensOriginalSize[j]*0.5,aliensOriginalSize[j]*1.5,0,255);
        ofSetColor(25,alpha);
        ofFill();
        ofDrawCircle(aliensX[j], aliensY[j], aliensSize[j]);
    }
    
    
    if(drawCircles2){
        ofSetColor(255,alpha);
        ofSetLineWidth(2);
        ofNoFill();
        ofDrawCircle(earth+earthSize/2, 10*enlarge);
        ofDrawCircle(earth+earthSize/2, 20*enlarge);
        ofDrawCircle(earth+earthSize/2, 30*enlarge);
        ofDrawCircle(earth+earthSize/2, 40*enlarge);
        ofDrawCircle(earth+earthSize/2, 50*enlarge);
        ofDrawCircle(earth+earthSize/2, 60*enlarge);
        ofDrawCircle(earth+earthSize/2, 70*enlarge);
        
        enlarge += 0.2;
        alpha -= 2;
    }
    
    if(10*enlarge == 17){
        radioSignal.play();
    }
    
    if(10*enlarge>350){
        drawCircles = false;
        enlarge = 0;
        alpha = 255;
    }
    
    if(70*enlarge>2200){
        drawCircles2 = true;
        enlarge = 1.5;
        alpha = 255;
    }
    
    if(earthAlpha == 50){
        count4++;
        
        ofSetColor(255);
        if(count4<150){
            ArvoBold.setLetterSpacing(1.0);
            ArvoBold.drawString("They are friendly!",280,350);
        } else{
            ofSetColor(0,255,0);
            Results.setLetterSpacing(1.3);
            Results.drawString("SURVIVED",30,450);
            
            drawArrow2();
        }
    }
    
    
}

void ofApp::drawScene7(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    if(earthAlpha>50){
        earthAlpha -= 0.5;
    }
    earth.set(center-80);
    ofSetColor(0, 0, 200);
    ofFill();
    earthImage.draw(earth,160,160);
    
    
    for(int j = 0; j<15; j++){
        if(aliensSize[j]+steps[j]>aliensOriginalSize[j]*1.5){
            steps[j] *= -1;
        }
        if(aliensSize[j]+steps[j]<aliensOriginalSize[j]*0.5){
            steps[j] *= -1;
        }
        aliensSize[j] += steps[j];
        float alpha;
        alpha = ofMap(aliensSize[j],aliensOriginalSize[j]*0.5,aliensOriginalSize[j]*1.5,0,255);
        if(j == 8){
            ofSetColor(255,0,0);
        } else{
            ofSetColor(25,alpha);
        }
        ofDrawCircle(aliensX[j], aliensY[j], aliensSize[j]);
    }
    
    
    if(drawCircles2){
        ofSetColor(255,alpha);
        ofSetLineWidth(2);
        ofNoFill();
        ofDrawCircle(earth+earthSize/2, 10*enlarge);
        ofDrawCircle(earth+earthSize/2, 20*enlarge);
        ofDrawCircle(earth+earthSize/2, 30*enlarge);
        ofDrawCircle(earth+earthSize/2, 40*enlarge);
        ofDrawCircle(earth+earthSize/2, 50*enlarge);
        ofDrawCircle(earth+earthSize/2, 60*enlarge);
        ofDrawCircle(earth+earthSize/2, 70*enlarge);
        
        enlarge += 0.2;
        alpha -= 2;
    }
    
    if(10*enlarge == 17){
        radioSignal.play();
    }
    
    if(10*enlarge>350){
        drawCircles = false;
        enlarge = 0;
        alpha = 255;
    }
    
    if(70*enlarge>2200){
        drawCircles2 = true;
        enlarge = 1.5;
        alpha = 255;
    }
    
    if(earthAlpha == 50){
        count4++;
        
        ofSetColor(255);
        if(count4<150){
            ArvoBold.setLetterSpacing(1.0);
            ArvoBold.drawString("They are hostile!",280,350);
            ArvoBold.drawString("And you are not keeping quiet.",100,430);
        } else{
            ofSetColor(255,0,0);
            Results.setLetterSpacing(1.3);
            Results.drawString("YOU DIED",50,450);
            
            drawArrow2();
        }
        
    }
}

void ofApp::drawTransition23(){
    ofSetColor(0);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    earth += 0.1 * (earthTarget-earth);
    sun += 0.1 * (sunTarget-sun);
    earthSize += 0.1 * (earthTargetSize-earthSize);
    sunSize += 0.1 * (sunTargetSize -sunSize);
    
    ofSetColor(0, 0, 200);
    ofFill();
    earthImage.draw(earth,earthSize,earthSize);
    ofSetColor(255);
    sunImage.draw(sun,sunSize,sunSize);
    
    if(earth.distance(earthTarget) < 0.1 && sun.distance(sunTarget) < 0.1){
        scene3 = true;
    }
}


void ofApp::drawArrow2(){
    ofPath arrow;
    
    arrow.moveTo(1110,600);
    arrow.lineTo(1080,620);
    arrow.lineTo(1110,640);
    
    arrow.close();
    arrow.setStrokeColor(255);
    arrow.setStrokeWidth(4);
    arrow.setFilled(true);
    arrow.draw();
    
    ofSetColor(255);
    ofFill();
    ofDrawRectangle(1110,615,30,10);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    if(key == '1'){
//        scene1 = true;
//        scene2 = false;
//        scene3 = false;
//        scene4 = false;
//        scene5 = false;
//        scene6 = false;
//        scene7 = false;
//        transition23 = false;
//
//        count1 = 0;
//    }
//
//    if(key == '2'){
//        scene1 = false;
//        scene2 = true;
//        scene3 = false;
//        scene4 = false;
//        scene5 = false;
//        scene6 = false;
//        scene7 = false;
//        transition23 = false;
//
//        count3 = 0;
//    }
//
//    if(key == '3'){
//        scene1 = false;
//        scene2 = false;
//        scene3 = true;
//        scene4 = false;
//        scene5 = false;
//        scene6 = false;
//        scene7 = false;
//        transition23 = false;
//    }
//
//    if(key == '4'){
//        scene1 = false;
//        scene2 = false;
//        scene3 = false;
//        scene4 = true;
//        scene5 = false;
//        scene6 = false;
//        scene7 = false;
//        transition23 = false;
//    }
//
//    if(key == '5'){
//        scene1 = false;
//        scene2 = false;
//        scene3 = false;
//        scene4 = false;
//        scene5 = true;
//        scene6 = false;
//        scene7 = false;
//        transition23 = false;
//    }
//
//    if(key == '6'){
//        scene1 = false;
//        scene2 = false;
//        scene3 = false;
//        scene4 = false;
//        scene5 = false;;
//        scene6 = true;
//        scene7 = false;
//        transition23 = false;
//
//        drawCircles = true;
//    }
//
//    if(key == '7'){
//        scene1 = false;
//        scene2 = false;
//        scene3 = false;
//        scene4 = false;
//        scene5 = false;;
//        scene6 = false;
//        scene7 = true;
//        transition23 = false;
//
//        drawCircles = true;
//    }
    
    
    //    if(key == 's'){
    //        scene1 = false;
    //        scene2 = false;
    //        scene3 = false;
    //        scene4 = false;
    //        transition23 = true;
    //    }
    
    if(key == 'f'){
        fkeyPressed = true;
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
    earth.set(x-80,y-80);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
        if (ofGetMouseX()>=1100 && ofGetMouseX()<=1160 && ofGetMouseY()>=600 && ofGetMouseY()<=640){
            if(scene2){
            transition23 = true;
            scene2 = false;
            }
            
            if(scene4 || scene5 || scene6 || scene7){
                scene3 = true;
                scene4 = false;
                scene5 = false;
                scene6 = false;
                scene7 = false;
            }
        }

    if (scene3){
        if(ofGetMouseX()>=button1.x && ofGetMouseX()<=(button1.x+200) && ofGetMouseY()>=button1.y && ofGetMouseY()<=(button1.y+45)){
            shrink1*=0.9;
            drawCircles = true;
            
            radioSignal.play();
            
            aliens = ofRandom(0,2);
            if(aliens >= 1){
                scene6 = true;
                
            }else{
                scene7 = true;
            }
            drawCircles2 = true;
            count4 = 0;
            earthAlpha = 255;
        }
        if(ofGetMouseX()>=button2.x && ofGetMouseX()<=(button2.x+200) && ofGetMouseY()>=button2.y && ofGetMouseY()<=(button2.y+45)){
            shrink2*=0.9;
            
            aliens = ofRandom(0,2);
            if(aliens >= 1){
                scene4 = true;
            }else{
                scene5 = true;
            }
            count4 = 0;
            earthAlpha = 255;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    shrink1 = 1;
    shrink2 = 1;
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
