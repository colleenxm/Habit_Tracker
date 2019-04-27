#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	curr_game_state_ = SHOW_INTRO; // Init this to your first state
	ofSetWindowTitle("HABIT TRACKER");
	ofBackground(185, 224, 217, 255);
	title_font_.load("title_font_.ttf", 72);
}

void ofApp::SetUpButtons() {
	new_user_button_message_ = "New User";
	old_user_button_message_ = "Old User";

	new_user_button_width = 200;
	new_user_button_height = 150;

	old_user_button_width = 200;
	old_user_button_height = 150;

	new_user_button_.set(100, 100, new_user_button_width, new_user_button_height);
	old_user_button_.set(100, 250, old_user_button_width, old_user_button_height);

	is_new_user_button_clicked = false;
	is_old_user_button_clicked = false;
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (curr_game_state_) {
	case SHOW_INTRO:
		ofSetColor(0);
		title_font_.drawString("Habit Tracker", 200, 150);
		break;
	case NEW_USER:
		ofSetColor(0);
		
		break;
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}