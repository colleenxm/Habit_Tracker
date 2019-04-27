#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	curr_game_state_ = SHOW_INTRO; // Init this to your first state
	ofSetWindowTitle("HABIT TRACKER");
	ofBackground(255, 255, 255);

	title_font_.load("title_font_.ttf", 72);
	subtitle_font_.load("subtitle_font_.ttf", 18);
	button_font_.load("button_font_.ttf", 13);
	font_.load("ofxbraitsch/fonts/Verdana.ttf", 24);

	SetUpButtons();
	/**
	input_field = new ofxDatGuiTextInputField();
	ofColor green(0, 255, 0);
	input_field->setBackgroundColor(green);
	input_field->setPosition(150, 150);
	input_field->setWidth(200);
	
	
	ofSetWindowShape(1920, 1080);
	ofSetWindowPosition(ofGetScreenWidth() / 2 - ofGetWidth() / 2, 0);

	input = new ofxDatGuiTextInput("TEXT INPUT", "Type Something Here");
	input->onTextInputEvent(this, &ofApp::onTextInputEvent);
	input->setFocused(true);
	input->setWidth(800, .2);
	input->setPosition(ofGetWidth() / 2 - input->getWidth() / 2, 240); */
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	font_.drawString("Field test", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
}

void ofApp::SetUpButtons() {
	next_button_clicked_ = false;

	new_user_button_message_ = "New User";
	old_user_button_message_ = "Returning User";
	next_button_message_ = "Next ->";

	new_user_button_width_ = 200;
	new_user_button_height_ = 100;

	old_user_button_width_ = 200;
	old_user_button_height_ = 100;

	next_button_width_ = 200;
	next_button_height_ = 100;

	new_user_button_.set((ofGetWidth()/2 - (new_user_button_width_ / 2)), 200, new_user_button_width_, new_user_button_height_);
	old_user_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 310, old_user_button_width_, old_user_button_height_);
	next_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 385, old_user_button_width_, old_user_button_height_);

	is_new_user_button_clicked_ = false;
	is_old_user_button_clicked_ = false;
	next_button_clicked_ = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	switch (curr_game_state_) {
	case NEW_USER:
		current_user_.setUserName("Colleen");
		current_user_.setHabitNum(6);
		button_font_.drawStringCentered(current_user_.getUserName(), ofGetWidth() / 2, ((ofGetHeight() / 8) + 125));
		button_font_.drawStringCentered(std::to_string(current_user_.getNumOfHabits()), ofGetWidth() / 2, ((ofGetHeight() / 8) + 205));
		break;
	case OLD_USER:
		current_user_.setUserName("Colleen");
		current_user_.setHabitNum(6);
		break;
		/**
		case ADD_HABITS:
			//loop thru habits and add them
			break;

		case CHECK_HABIT_DONE:
			//check if each ahbit was done that day
			break;

		case DISPLAY_HABITS:
			//pretty print each of the habits in nice graphical form
			break;
		}*/
	}
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
		subtitle_font_.drawStringCentered("How many habits would you like to track?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 175));
		DrawNextButton();
		update(); //get name and num of habits and load user class
		break;

	case OLD_USER:
		ofSetColor(0);
		subtitle_font_.drawStringCentered("Enter your username:", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		DrawNextButton();
		update(); //get user name and load user class from json file
		break;

	case ADD_HABITS:
		ofSetColor(0);
		title_font_.drawStringCentered("Add habits: ", ofGetWidth() / 2, (ofGetHeight() / 8));
		DrawNextButton();
		update(); //Loop thru num of habits and ask user to input habit name
		break;

	case CHECK_HABIT_DONE:
		ofSetColor(0);
		title_font_.drawStringCentered("Habit Checklist: ", ofGetWidth() / 2, (ofGetHeight() / 8));
		DrawNextButton();
		update(); //loop thru habits and ask if each habit is done
		break;

	case DISPLAY_HABITS:
		ofSetColor(0);
		title_font_.drawStringCentered("Habit Tracker", ofGetWidth() / 2, (ofGetHeight() / 8));
		break;

	}
}

void ofApp::DrawNextButton() {
	ofSetColor(next_button_color_);
	ofDrawRectRounded(next_button_, 10);
	ofSetColor(0);
	button_font_.drawStringCentered(next_button_message_, ofGetWidth() / 2, 435);
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
		//is_new_user_button_clicked_ = true;
		curr_game_state_ = NEW_USER;
	}

	if (old_user_button_.inside(x, y)) {
		//is_old_user_button_clicked_ = true;
		curr_game_state_ = OLD_USER;
	}

	if ((curr_game_state_ = NEW_USER) && next_button_clicked_) {
		curr_game_state_ = ADD_HABITS;
		next_button_clicked_ = false;
	} else if ((curr_game_state_ = OLD_USER) && next_button_clicked_) {
		curr_game_state_ = CHECK_HABIT_DONE;
		next_button_clicked_ = false;
	} else if ((curr_game_state_ = ADD_HABITS) && next_button_clicked_) {
		curr_game_state_ = CHECK_HABIT_DONE;
		next_button_clicked_ = false;
	} else if ((curr_game_state_ = CHECK_HABIT_DONE) && next_button_clicked_) {
		curr_game_state_ = DISPLAY_HABITS;
		next_button_clicked_ = false;
	} else if (next_button_.inside(x, y)) {
		next_button_clicked_ = true;
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