#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    x = 100;
    y = 100;
    xx = 10;
    yy = 5;
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    mainOutputSyphonServer.setName("Screen Outputh");
    mClient.setup();
    mClient.setApplicationName("Simple Serverh");
    mClient.setServerName("");
}

//--------------------------------------------------------------
void ofApp::update(){
    x = x + xx;
    y = y + yy;
    
    if (x < 100 or ofGetWidth() - 100 < x) {
        xx = -xx;
    }
    if (y < 100 or ofGetHeight() - 100 < y) {
        yy = -yy;
    }
    
    if (backgroundcolor > 15){
        backgroundcolor = backgroundcolor - 5;
    } else if (backgroundcolor <= 15){
        backgroundcolor = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(backgroundcolor);
    ofSetColor(255,0,0,255);
    
    ofSetLineWidth(2);
    
    for (int i = 0; i <= 15; i++) {
        ofLine(128*i, 0, 128*i, 768);
    }
    for (int i = 0; i<= 15; i++) {
        ofLine(0,128*i, 1024, 128*i);
    }
    
    ofSetColor(255,180,100);
    ofCircle(x, y, 100);
    /*    ofSetColor(120,200,100);
     ofRect(512, 256, 200, 200);
     
     ofFill();
     ofTriangle(300, 500, 270, 650, 300, 650);
     ofEllipse(128, 384, 100, 600);
     */
    /*    ofBeginShape();
     ofVertex(<#float x#>, <#float y#>);
     ofEndShape();
     */
    
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a'){
        xx = xx * 2;
        yy = yy * 2;
    }if (key == 'b'){
        xx = xx / 2;
        yy = yy / 2;
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
void ofApp::mousePressed(int _x, int _y, int button){
    if(pow((mouseX-x),2)+pow((mouseY-y),2)<=10000){
        xx = -xx;
        yy = -yy;
        backgroundcolor = 255;
    }
    
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
