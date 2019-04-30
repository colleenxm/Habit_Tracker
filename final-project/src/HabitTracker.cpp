#include "HabitTracker.h"

//--------------------------------------------------------------
void HabitTracker::setup() {
	curr_game_state_ = SHOW_INTRO;
	ofSetWindowTitle("HABIT TRACKER");
	ofBackground(255, 255, 255);

	title_font_.load("title_font_.ttf", 72);
	subtitle_font_.load("subtitle_font_.ttf", 18);
	button_font_.load("button_font_.ttf", 13);

	input_text_box_.setup();
	input_text_box_.add(input_text_);
	input_text_box_.setPosition(300, 180);

	input_int_box_.setup();
	input_int_box_.add(input_int_.setup("number of habits: ", 3, 1, 5));
	input_int_box_.setPosition(300, 280);
	SetUpButtons();
}

void HabitTracker::SetUpButtons() {
	new_user_button_message_ = "New User";
	new_user_button_width_ = 200;
	new_user_button_height_ = 100;
	new_user_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 200, new_user_button_width_, new_user_button_height_);
	is_new_user_button_clicked_ = false;
	
	old_user_button_message_ = "Returning User";
	old_user_button_width_ = 200;
	old_user_button_height_ = 100;
	old_user_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 310, old_user_button_width_, old_user_button_height_);
	is_old_user_button_clicked_ = false;

	next_button_message_ = "Next ->";
	next_button_width_ = 200;
	next_button_height_ = 100;
	next_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 425, old_user_button_width_, old_user_button_height_);
	next_button_clicked_ = false;

	habit_completed_button_message_ = "Yes!";
	habit_completed_button_width_ = 200;
	habit_completed_button_height_ = 100;
	habit_completed_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 200, habit_completed_button_width_, habit_completed_button_height_);
	habit_completed_ = false;

	habit_not_completed_button_message_ = "No :(";
	habit_not_completed_button_width_ = 200;
	habit_not_completed_button_height_ = 100;
	habit_not_completed_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 310, habit_not_completed_button_width_, habit_not_completed_button_height_);
}

//--------------------------------------------------------------
void HabitTracker::update() {
	if (next_button_clicked_) {
		switch (curr_game_state_) {
		case NEW_USER:
			curr_game_state_ = ADD_HABITS;
			break;
		case OLD_USER:
			curr_game_state_ = CHECK_HABIT_DONE;
			break;
		case ADD_HABITS:
			curr_game_state_ = CHECK_HABIT_DONE;
			break;
		case CHECK_HABIT_DONE:
			curr_game_state_ = DISPLAY_HABITS;
			break;
		case DISPLAY_HABITS:
			curr_game_state_ = DISPLAY_HABITS;
			break;
		}
		next_button_clicked_ = false;
	}
	std::vector<User::Habit> habits = current_user_.getUserHabits();
	switch (curr_game_state_) {
	case NEW_USER:
		current_user_.setUserName(input_text_);
		current_user_.setHabitNum(input_int_);
		break;
	case OLD_USER:
		current_user_.setUserName(input_text_);
		//load user from json file
		break;
	case ADD_HABITS:
		for (const auto& curr_habit : habits) {
			subtitle_font_.drawStringCentered("What would you like to name this habit?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
			current_user_.setHabitName(curr_habit, input_text_);
		}
		break;
	case CHECK_HABIT_DONE:
		for (const auto& curr_habit : habits) {
			habit_completed_ = false;
			std::string question = "Did you complete " + current_user_.getHabitName(curr_habit) + " today?";
			subtitle_font_.drawStringCentered(question, ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
			if (habit_completed_) { 
				current_user_.setHabitArray(curr_habit, true);
			} else {
				current_user_.setHabitArray(curr_habit, false);
			}
		}
		break;

	case DISPLAY_HABITS:
		for (const auto& curr_habit : habits) {
			//subtitle_font_.drawStringCentered(, ofGetWidth() / 2, ((ofGetHeight() / 8) + 125));
		}
		break;
	}
}

//--------------------------------------------------------------
void HabitTracker::draw() {
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
		title_font_.drawStringCentered("Welcome!", ofGetWidth() / 2, (ofGetHeight() / 8));
		subtitle_font_.drawStringCentered("What is your name?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		input_text_box_.draw();
		subtitle_font_.drawStringCentered("How many habits would you like to track?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 175));
		input_int_box_.draw();
		DrawNextButton();
		update(); //get name and num of habits and load user class
		break;

	case OLD_USER:
		ofSetColor(0);
		title_font_.drawStringCentered("Welcome Back!", ofGetWidth() / 2, (ofGetHeight() / 8));
		subtitle_font_.drawStringCentered("Enter your username:", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		input_text_box_.draw();
		DrawNextButton();
		update(); //get user name and load user class from json file
		break;

	case ADD_HABITS:
		ofSetColor(0);
		title_font_.drawStringCentered("Add habits: ", ofGetWidth() / 2, (ofGetHeight() / 8));
		input_text_box_.draw();
		DrawNextButton();
		update(); //Loop thru num of habits and ask user to input habit name
		break;

	case CHECK_HABIT_DONE:
		ofSetColor(0);
		title_font_.drawStringCentered("Habit Checklist: ", ofGetWidth() / 2, (ofGetHeight() / 8));
		DrawNextButton();

		ofSetColor(habit_completed_button_color_);
		ofDrawRectRounded(habit_completed_button_, 10);

		ofSetColor(habit_not_completed_button_color_);
		ofDrawRectRounded(habit_not_completed_button_, 10);

		ofSetColor(0);
		button_font_.drawStringCentered(habit_completed_button_message_, ofGetWidth() / 2, 243);
		button_font_.drawStringCentered(habit_not_completed_button_message_, ofGetWidth() / 2, 353);
		update(); //loop thru habits and ask if each habit is done

		break;

	case DISPLAY_HABITS:
		ofSetColor(0);
		title_font_.drawStringCentered("Habit Tracker", ofGetWidth() / 2, (ofGetHeight() / 8));
		break;

	}
}

void HabitTracker::DrawNextButton() {
	ofSetColor(next_button_color_);
	ofDrawRectRounded(next_button_, 10);
	ofSetColor(0);
	button_font_.drawStringCentered(next_button_message_, ofGetWidth() / 2, 475);
}
//--------------------------------------------------------------
void HabitTracker::keyPressed(int key) {

}

//--------------------------------------------------------------
void HabitTracker::keyReleased(int key) {

}

//--------------------------------------------------------------
void HabitTracker::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void HabitTracker::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void HabitTracker::mousePressed(int x, int y, int button) {
	if (curr_game_state_ == SHOW_INTRO) {
		if (new_user_button_.inside(x, y)) {
			curr_game_state_ = NEW_USER;
		} else if (old_user_button_.inside(x, y)) {
			curr_game_state_ = OLD_USER;
		}
	}
	if (curr_game_state_ == CHECK_HABIT_DONE) {
		if (habit_completed_button_.inside(x, y)) {
			habit_completed_ = true;
			subtitle_font_.drawStringCentered("Good job!", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		} else {
			subtitle_font_.drawStringCentered("Do better next time!", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		}
	}
	if (next_button_.inside(x, y)) {
		next_button_clicked_ = true;
	}
}

//--------------------------------------------------------------
void HabitTracker::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void HabitTracker::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void HabitTracker::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void HabitTracker::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void HabitTracker::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void HabitTracker::dragEvent(ofDragInfo dragInfo) {

}