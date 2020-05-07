#include "ofApp.h"
#include "ofxJSON.h"
#include <time.h>

ofxJSONElement root;

ofImage window1, window2;
ofSoundPlayer wind;

ofVec2f p1,p2,p3,p4,p5,p6,p7,p8;

float fading;


//--------------------------------------------------------------
void ofApp::setup(){
    //Get the weather data
    std::string url = "https://api.darksky.net/forecast/API_KEY/42.3601,-71.0589";
    bool parsingSuccessful = root.open(url);
    if(parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    //GUI panel
    gui.setup();
    gui.add(Time.setup("Time/hour",0,0,24));
    gui.add(Temperature.setup("Temperature",0,0,100));
    gui.add(WindSpeed.setup("Wind Speed",0,0,20));
    gui.add(SunriseTime.setup("Sunrise Time/hour",6,0,12));
    gui.add(SunsetTime.setup("Sunset Time/hour",19,13,24));
    gui.add(light.setup("Light"));
    
    //Set window size
    ofSetWindowShape(2880, 1750);
    
    //Load files
    window1.load("images/window1.png");
    window2.load("images/window2.png");
    wind.load("sound/wind.mp3");
    wind.setMultiPlay(true);
    wind.setLoop(true);
    wind.play();
    
    p1.set(235, 240);
    p2.set(300, ofGetHeight());
    p3.set(700, ofGetHeight());
    p4.set(815, 240);
    p5.set(880, ofGetHeight());
    p6.set(1280, ofGetHeight());
    
    fading = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    wind.setVolume(WindSpeed/60);

}

//--------------------------------------------------------------
void ofApp::draw(){
    //Pick up variables that are needed
    std::string summary = root["currently"]["summary"].asString();
    int sample = root["currently"]["time"].asInt(); // get sample epoch
    float temp = root["currently"]["temperature"].asFloat();
    float windSpeed = root["currently"]["windSpeed"].asFloat();
    int sunriseTime = root["daily"]["data"][0]["sunriseTime"].asInt();
    int sunsetTime = root["daily"]["data"][0]["sunsetTime"].asInt();
    
    int year = sample/31556926+1970;
    int month = (sample%31556926)/2629743+1;
    int day = (sample%2629743)/86400+2;
    int hour = (sample%86400)/3600-4;
    if(hour<0){
        hour += 24;
        day -= 1;
    }
    int minute = (sample%3600)/60;
    
    int sunriseHour = (sunriseTime%86400)/3600-4;
    if(sunriseHour<0){
        sunriseHour += 24;
    }
    int sunriseMinute = (sunriseTime%3600)/60;
    
    int sunsetHour = (sunsetTime%86400)/3600-4;
    if(sunsetHour<0){
        sunsetHour += 24;
    }
    int sunsetMinute = (sunsetTime%3600)/60;
    
    //Room Light
    ofColor lightYellow = ofColor(255,255,243);
    ofColor orange = ofColor(237,176,53);
    ofColor white = ofColor(255,255,255);
    ofColor black = ofColor(0);
    ofColor grey = ofColor(50);
    ofColor lightGrey = ofColor(220);
    ofColor lightGrey_ = ofColor(180);
    ofColor darkGrey = ofColor(30);
    
    if(Time>=0 && Time<=12){
        if(Time<SunriseTime-1){
            ofSetColor(0);
        } else if(Time>=(SunriseTime-1) && Time<SunriseTime){
            ofColor dawnLerp = black.lerp(grey,1-(SunriseTime-Time));
            ofSetColor(dawnLerp);
        }else if(Time>=SunriseTime && Time<(SunriseTime+2)){
            ofColor daytimeLerp = grey.lerp(lightGrey,(Time-SunriseTime)*0.5f);
            ofSetColor(daytimeLerp);
        }
        else{
            ofSetColor(lightGrey);
        }
    }
    
    if(Time > 12 && Time <=24){
        if(Time<(SunsetTime-2)){
            ofSetColor(lightGrey);
        }
        else if(Time>=(SunsetTime-2) && Time<=(SunsetTime-1)){
            ofColor sunsetLerp = lightGrey.lerp(lightGrey_,Time-(SunsetTime-2));
            ofSetColor(sunsetLerp);
        } else if (Time>=(SunsetTime-1) && Time<=(SunsetTime+1)){
            ofColor nighttimeLerp = lightGrey_.lerp(black,(Time-(SunsetTime-1))*0.5);
            ofSetColor(nighttimeLerp);
        }
        else{
            ofSetColor(black);
        }
    }
    
    if(light){
        ofSetColor(250,255);
    }
    
    //Background
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    
    //Window Light
    if(Time>=0 && Time<=12){
        if(Time<SunriseTime-1){
            ofSetColor(0);
        }
        else if(Time>=(SunriseTime-1) && Time<SunriseTime){
            ofColor dawnLerp = black.lerp(grey,1-(SunriseTime-Time));
            ofSetColor(dawnLerp);
        }
        else if(Time>=SunriseTime && Time<=(SunriseTime+2)){
            ofColor daytimeLerp = grey.lerp(lightYellow,(Time-SunriseTime)*0.5f);
            ofSetColor(daytimeLerp);
        }
        else{
            ofSetColor(lightYellow);
        }
    }
    
    if(Time > 12 && Time <=24){
        if(Time<(SunsetTime-2)){
            ofSetColor(lightYellow);

        }
        else if(Time>=(SunsetTime-3) && Time<=(SunsetTime-1)){
            ofColor sunsetLerp = lightYellow.lerp(orange,Time-(SunsetTime-2));
            ofSetColor(sunsetLerp);

        } else if (Time>=(SunsetTime-1) && Time<=(SunsetTime+1)){
            ofColor nighttimeLerp = orange.lerp(darkGrey,(Time-(SunsetTime-1))*0.5);
            ofSetColor(nighttimeLerp);
        }
        else{
            if(Time>23.5){
                if(fading<1){
                    fading = fading + 0.005;
                }
            }
            ofColor fadingLerp = darkGrey.lerp(black, fading);
            ofSetColor(fadingLerp);
            
            cout<<fading<<endl;
        }
    }

    ofDrawRectangle(270,200,320,500);
    ofDrawRectangle(800,200,320,500);
    
    //Draw two windows
    ofSetColor(0,255);
   
    window1.draw(220,150,370,580);
    window2.draw(800,150,370,580);
    
    
    //Draw the room outline
    ofPath room;
    
    room.moveTo(ofGetWidth()-200,50);
    room.lineTo(ofGetWidth(),0);
    room.moveTo(0,50);
    room.lineTo(ofGetWidth()-200,50);
    room.lineTo(ofGetWidth()-200,ofGetHeight()-100);
    room.lineTo(ofGetWidth(),ofGetHeight());
    room.moveTo(0,ofGetHeight()-100);
    room.lineTo(ofGetWidth()-200,ofGetHeight()-100);
    
    room.setFilled(false);
    room.setStrokeColor(0);
    room.setStrokeWidth(2);
    room.draw();
    
    //Draw the sunlight
    float d = SunsetTime - Time;
    float sunlightalpha;
    sunlightalpha = 150;
    
    if(d>=0 && d<1){
    sunlightalpha = ofMap(1-d, 0, 1, 150, 0);
    }
    
    ofColor lightYellowlight = ofColor(255,250,153,sunlightalpha);
     ofColor yellowlight = ofColor(255,250,87,sunlightalpha);
     ofColor orangelight = ofColor(232,171,35,sunlightalpha);
     ofColor sunlightColor;
    
     
     if(Time > 12 && Time <=24){
         if(Time>=(SunsetTime-2) && Time<=SunsetTime){
         ofColor sunsetLerp = lightYellowlight.lerp(orangelight,(2-(SunsetTime-Time))*0.5f);
         ofSetColor(sunsetLerp);
         sunlightColor = sunsetLerp;
         }
     }
    
    if(d>=0 && d<2){
        float d1 = ofMap(d, 0, 2, 450, 0);
        float d2 = ofMap(d, 0, 2, -65, 0);
        float d3 = ofMap(d, 0, 2, 550, 0);
        float d4 = ofMap(d, 0, 2, -25, 0);
        
        
            p1.set(280, 240+d1);
            p2.set(345+d2, ofGetHeight());
            p3.set(745+d3, ofGetHeight());
            p4.set(305+d4,ofGetHeight()-100);
            p5.set(815, 240+d1);
            p6.set(880+d2, ofGetHeight());
            p7.set(1280+d3, ofGetHeight());
            p8.set(840+d4,ofGetHeight()-100);
        
    
        ofPath sunlight;
        
        sunlight.moveTo(280,210);
        sunlight.lineTo(p1);
        sunlight.lineTo(p4);
        sunlight.lineTo(p2);
    
        sunlight.lineTo(p3);
        sunlight.lineTo(575,210);
        sunlight.close();
        
        sunlight.setFilled(true);
        sunlight.setFillColor(sunlightColor);
        sunlight.setStrokeWidth(0);
        sunlight.draw();
        
        ofPath sunlight1;
        
        sunlight1.moveTo(815,210);
        sunlight1.lineTo(p5);
        sunlight1.lineTo(p8);
        sunlight1.lineTo(p6);
        sunlight1.lineTo(p7);
        sunlight1.lineTo(1110,210);
        sunlight1.close();
        
        sunlight1.setFilled(true);
        sunlight1.setFillColor(sunlightColor);
        sunlight1.setStrokeWidth(0);
        sunlight1.draw();
        
    }
        
    //Draw the GUI panel
    gui.draw();
    
    
    
    //Print out the information
    if (ofGetFrameNum() == 1){
        text<<"Current Time: "<<endl;
        text<<"Date: " << month << "/" << day << "/" << year << endl;
        text<<"Time: " << hour << ":" << minute << endl;
        text<<"Temperature: " << temp << endl;
        text<<"Wind Speed: " << windSpeed << endl;
        text<<"Sunrise Time: " << sunriseHour << ":" << sunriseMinute << endl;
        text<<"Sunset Time: " << sunsetHour << ":" << sunsetMinute << endl;
    }
    ofSetColor(0,255,0);
    ofDrawBitmapString(text.str(), 1300, 800);
    
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
