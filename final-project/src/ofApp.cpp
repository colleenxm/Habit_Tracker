#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(185,224,217,255);
	ofSetVerticalSync(true);
	ofTrueTypeFont::setGlobalDpi(72);
	bertilda.load("bertilda.ttf", 14, true, true);
	bertilda.setLineHeight(18.0f);
	bertilda.setLetterSpacing(1.037);
	bFirst = true;
	typeStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n0123456789,:&!?";
}

//--------------------------------------------------------------
void ofApp::exit() {
	ringButton.removeListener(this, &ofApp::ringButtonPressed);
}

//--------------------------------------------------------------
void ofApp::circleResolutionChanged(int &circleResolution) {
	ofSetCircleResolution(circleResolution);
}

//--------------------------------------------------------------
void ofApp::ringButtonPressed() {
	ring.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetCircleResolution(circleResolution);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(225);
	bertilda.drawString("Habit Tracker", 30, 35);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'h') {
		//bHide = !bHide;
	}
	else if (key == 's') {
		gui.saveToFile("settings.xml");
	}
	else if (key == 'l') {
		gui.loadFromFile("settings.xml");
	}
	else if (key == ' ') {
		color = ofColor(255);
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
	screenSize = ofToString(w) + "x" + ofToString(h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
