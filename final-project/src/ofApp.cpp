#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	curr_game_state_ = SHOW_INTRO; // Init this to your first state
	ofSetWindowTitle("HABIT TRACKER");
	ofBackground(255, 255, 255);
	title_font_.load("title_font_.ttf", 72);
	subtitle_font_.load("subtitle_font_.ttf", 18);
	button_font_.load("subtitle_font_.ttf", 13);
	SetUpButtons();
	name.set("Name: ");
}

void ofApp::SetUpButtons() {
	new_user_button_message_ = "New User";
	old_user_button_message_ = "Returning User";

	new_user_button_width = 200;
	new_user_button_height = 100;

	old_user_button_width = 200;
	old_user_button_height = 100;

	new_user_button_.set((ofGetWidth()/2 - (new_user_button_width / 2)), 200, new_user_button_width, new_user_button_height);
	old_user_button_.set((ofGetWidth() / 2 - (new_user_button_width / 2)), 310, old_user_button_width, old_user_button_height);

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
		title_font_.drawStringCentered("Habit Tracker", ofGetWidth()/2, ofGetHeight()/8);
		subtitle_font_.drawStringCentered("Are you a new or returning user?", ofGetWidth()/2, ((ofGetHeight()/8) + 85));
		ofSetColor(new_user_button_color_); 
		ofDrawRectRounded(new_user_button_, 10);
		ofSetColor(old_user_button_color_);
		ofDrawRectRounded(old_user_button_, 10);
		ofSetColor(0);
		button_font_.drawStringCentered(new_user_button_message_, ofGetWidth() / 2, 243);
		button_font_.drawStringCentered(old_user_button_message_, ofGetWidth() / 2, 353);
		break;
	case NEW_USER:
		ofSetColor(0);
		subtitle_font_.drawStringCentered("What is your name?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		name.get();
		break;
	case OLD_USER:
		ofSetColor(0);
		subtitle_font_.drawStringCentered("Enter your username:", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
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
	if (new_user_button_.inside(x, y)) {
		is_new_user_button_clicked = true;
		curr_game_state_ = NEW_USER;
	}
	if (old_user_button_.inside(x, y)) {
		is_old_user_button_clicked = true;
		curr_game_state_ = OLD_USER;
	}
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