#include "ofApp.h"
#include "ofxJSON.h"

#include <time.h>

ofxJSONElement root;

ofImage window;

ofSoundPlayer wind;


//--------------------------------------------------------------
void ofApp::setup(){
    std::string url = "https://api.darksky.net/forecast/API_KEY/42.3601,-71.0589";

    // Now parse the JSON
    bool parsingSuccessful = root.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << root.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }

    
    gui.setup();
    gui.add(Time.setup("Time(hour)",22.35,0,24));
    gui.add(Temperature.setup("Temperature",42.01,0,100));
    gui.add(WindSpeed.setup("Wind Speed",11.42,0,20));
    gui.add(SunriseTime.setup("Sunrise Time(hour)",6,0,12));
    gui.add(SunsetTime.setup("Sunset Time(hour)",19,13,24));
    gui.add(light.setup("Light"));
    
    ofSetWindowShape(1600, 900);
    
    window.load("images/window.png");
    wind.load("sound/wind.mp3");
    wind.setLoop(true);
    wind.setMultiPlay(true);
    wind.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    wind.setVolume(WindSpeed/40);
}

std::ostringstream text;
float phase;  // moon phase

//--------------------------------------------------------------
void ofApp::draw(){
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
    
    
    ofColor lightYellow = ofColor(255,255,243);
    ofColor orange = ofColor(255,147,39);
    ofColor red = ofColor(255,0,0);
    ofColor white = ofColor(255,255,255);
    ofColor black = ofColor(0,0,0);
    ofColor grey = ofColor(70,70,70);
    ofColor lightGrey = ofColor(220,220,220);
    ofColor lightGrey_ = ofColor(180,180,180);
    
    
    if(Time>=0 && Time<=12){
        if(Time<SunriseTime){
            ofSetColor(0);
        } else if(Time>=SunriseTime && Time<=(SunriseTime+2)){
            ofColor daytimeLerp = black.lerp(lightGrey,(Time-SunriseTime)*0.5f);
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
        else if(Time>=(SunsetTime-3) && Time<=(SunsetTime-1)){
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
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());


    if(Time>=0 && Time<=12){
        if(Time<SunriseTime){
            ofSetColor(0);
        } else if(Time>=SunriseTime && Time<=(SunriseTime+2)){
            ofColor daytimeLerp = black.lerp(lightYellow,(Time-SunriseTime)*0.5f);
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
            ofColor nighttimeLerp = orange.lerp(grey,(Time-(SunsetTime-1))*0.5);
            ofSetColor(nighttimeLerp);
        }
        else{
            ofSetColor(grey);
        }
    }

    ofDrawRectangle(270, 100, 350, 620);
    ofDrawRectangle(1039, 100, 350, 620);
    
    
    ofSetColor(0,255);
    window.draw(350,150,120);
    window.draw(1000,150,120);
    
   
    gui.draw();
    
//    ofSetColor(12,255,100);
//    ofDrawBitmapString("Date: ", 20,720);
//    ofDrawBitmapString(month, 70,720);
//    ofDrawBitmapString("/", 80,720);
//    ofDrawBitmapString(day, 90,720);
//    ofDrawBitmapString("/", 110,720);
//    ofDrawBitmapString(year, 120,720);
//    ofDrawBitmapString("Current Time: ", 20,740);
//    ofDrawBitmapString(hour, 130,740);
//    ofDrawBitmapString(":", 145,740);
//    ofDrawBitmapString(minute, 155,740);
//    ofDrawBitmapString("Current Temperature: ", 20,760);
//    ofDrawBitmapString(temp, 190,760);
//    ofDrawBitmapString("Current Wind Speed: ", 20,780);
//    ofDrawBitmapString(windSpeed, 180,780);
//    ofDrawBitmapString("Sunrise Time: ", 20,800);
//    ofDrawBitmapString(sunriseHour, 130,800);
//    ofDrawBitmapString(":", 140,800);
//    ofDrawBitmapString(sunriseMinute, 150,800);
//    ofDrawBitmapString("Sunset Time: ", 20,820);
//    ofDrawBitmapString(sunsetHour, 125,820);
//    ofDrawBitmapString(":", 140,820);
//    ofDrawBitmapString(sunsetMinute, 150,820);
    
       if (ofGetFrameNum() == 1){

           text<<"Date: " << month << "/" << day << "/" << year << endl;
           text<<"Time: " << hour << ":" << minute << endl;
           text<<"Temperature: " << temp << endl;
           text<<"Wind Speed: " << windSpeed << endl;
           text<<"Sunrise Time: " << sunriseHour << ":" << sunriseMinute << endl;
           text<<"Sunset Time: " << sunsetHour << ":" << sunsetMinute << endl;

       }
       ofDrawBitmapString(text.str(), 20, 200);
       
    
    wind.setVolume(WindSpeed);
    

   
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
