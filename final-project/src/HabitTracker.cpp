#include "HabitTracker.h"

//--------------------------------------------------------------
void HabitTracker::setup() {
	mySound.load(kBackground_music_file_name_);
	mySound.play();

	curr_game_state_ = SHOW_INTRO;
	ofSetWindowTitle("HABIT TRACKER");
	ofBackground(255, 255, 255);

	title_font_.load("title_font_.ttf", 72);
	subtitle_font_.load("subtitle_font_.ttf", 18);
	button_font_.load("button_font_.ttf", 13);

	input_text_box_.setup();
	input_text_box_.add(input_text_);
	input_text_box_.setPosition(kInput_x_position_, kInput_y_position_);

	input_int_box_.setup();
	input_int_box_.add(input_int_.setup("number of habits: ", kDefault_num_habits_, kMin_num_habits_, kMax_num_habits_));
	input_int_box_.setPosition(kInput_x_position_, kInput_y_position_ + kDefault_button_height_);

	SetUpButtons();

	num_ = 0;
}

void HabitTracker::SetUpButtons() {
	SetUpNewUserButton();
	SetUpOldUserButton();
	SetUpNextButton();
	SetUpHabitCompletedButton();
	SetUpHabitNotCompletedButton();
	SetUpNameHabitButton();
}

void HabitTracker::SetUpNewUserButton() {
	new_user_button_message_ = "New User";
	new_user_button_width_ = kDefault_button_width_;;
	new_user_button_height_ = kDefault_button_height_;

	new_user_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), kDefault_button_width_,
		new_user_button_width_, new_user_button_height_);

	is_new_user_button_clicked_ = false;
}

void HabitTracker::SetUpOldUserButton() {
	old_user_button_message_ = "Returning User";
	old_user_button_width_ = kDefault_button_width_;
	old_user_button_height_ = kDefault_button_height_;

	old_user_button_.set((ofGetWidth() / 2 - (old_user_button_width_ / 2)), 310,
		old_user_button_width_, old_user_button_height_);

	is_old_user_button_clicked_ = false;
}

void HabitTracker::SetUpNextButton() {
	next_button_message_ = "Next ->";
	next_button_width_ = kDefault_button_width_;;
	next_button_height_ = kDefault_button_height_;

	next_button_.set((ofGetWidth() / 2 - (next_button_width_ / 2)), 425, next_button_width_, next_button_height_);

	next_button_clicked_ = false;
}

void HabitTracker::SetUpHabitCompletedButton() {
	habit_completed_button_message_ = "Yes!";
	habit_completed_button_width_ = kDefault_button_width_;;
	habit_completed_button_height_ = kDefault_button_height_;

	habit_completed_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), kDefault_button_width_,
		habit_completed_button_width_, habit_completed_button_height_);

	habit_completed_ = false;
}

void HabitTracker::SetUpHabitNotCompletedButton() {
	habit_not_completed_button_message_ = "No :(";
	habit_not_completed_button_width_ = kDefault_button_width_;;
	habit_not_completed_button_height_ = kDefault_button_height_;

	habit_not_completed_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 310,
		habit_not_completed_button_width_, habit_not_completed_button_height_);
	habit_not_completed_ = false;
}

void HabitTracker::SetUpNameHabitButton() {
	name_habit_button_message_ = "Name this habit";
	name_habit_button_width_ = kDefault_button_width_;;
	name_habit_button_height_ = kDefault_button_height_;
	name_habit_clicked_ = false;
	name_habit_button_.set((ofGetWidth() / 2 - (new_user_button_width_ / 2)), 310,
		name_habit_button_width_, name_habit_button_height_);
}

void HabitTracker::UpdateNextButtonClicked() {
	if (next_button_clicked_) {
		switch (curr_game_state_) {
		case NEW_USER:
			current_user_.setUserName(input_text_);
			current_user_.setHabitNum(input_int_);
			json_file_name_ = current_user_.getUserName() + ".json";
			curr_game_state_ = ADD_HABITS;
			break;
		case OLD_USER:
			current_user_.setUserName(input_text_);
			json_file_name_ = current_user_.getUserName() + ".json";
			loadUserFromFile();
			curr_game_state_ = CHECK_HABIT_DONE;
			break;
		case ADD_HABITS:
			curr_game_state_ = CHECK_HABIT_DONE;
			break;
		case CHECK_HABIT_DONE:
			curr_game_state_ = DISPLAY_HABITS;
			updateFile();
			break;
		case DISPLAY_HABITS:
			curr_game_state_ = DISPLAY_HABITS;
			break;
		}
		num_ = 0;
		next_button_clicked_ = false;
	}
}

void HabitTracker::AddHabits() {
	subtitle_font_.drawStringCentered("What would you like to name this habit?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
	if (num_ < current_user_.getNumOfHabits()) {
		if (name_habit_clicked_) {
			current_user_.addHabit(input_text_);
			num_++;
			name_habit_clicked_ = false;
		}
		else {
			subtitle_font_.drawStringCentered("Click 'Name habit' when ready.", ofGetWidth() / 2, ((ofGetHeight() / 8) + 175));
		}
	}
	else {
	  subtitle_font_.drawStringCentered("All habits added. Click next to continue.", ofGetWidth() / 2, ((ofGetHeight() / 8) + 175));
	}
}

void HabitTracker::CheckHabitsDone() {
	if (num_ < current_user_.getNumOfHabits()) {
		curr_habit = current_user_.getUserHabits().at(num_);
		question_ = "Did you " + curr_habit.name_ + " today?";
		subtitle_font_.drawStringCentered(question_, ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
		if (habit_completed_) {
			current_user_.setHabitDone(num_, true);
			num_++;
		}
		else if (habit_not_completed_) {
			current_user_.setHabitDone(num_, false);
			num_++;
		}
		habit_completed_ = false;
		habit_not_completed_ = false;
	}
	else {
		subtitle_font_.drawStringCentered("All habits checked. Click next to continue.", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
	}
}

//--------------------------------------------------------------
void HabitTracker::update() {
	UpdateNextButtonClicked();
	switch (curr_game_state_) {
	case ADD_HABITS: AddHabits();
		break;
	case CHECK_HABIT_DONE: CheckHabitsDone();
		break;
	}
}

void HabitTracker::DrawIntro() {
	ofSetColor(0);
	title_font_.drawStringCentered("Habit Tracker", ofGetWidth() / 2, ofGetHeight() / 8);
	subtitle_font_.drawStringCentered("Are you a new or returning user?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));

	ofSetColor(new_user_button_color_);
	ofDrawRectRounded(new_user_button_, 10);

	ofSetColor(old_user_button_color_);
	ofDrawRectRounded(old_user_button_, 10);

	ofSetColor(0);
	button_font_.drawStringCentered(new_user_button_message_, ofGetWidth() / 2, kUpper_button_message_position);
	button_font_.drawStringCentered(old_user_button_message_, ofGetWidth() / 2, 353);
}

void HabitTracker::DrawNewUser() {
	ofSetColor(0);
	title_font_.drawStringCentered("Welcome " + current_user_.getUserName(), ofGetWidth() / 2, (ofGetHeight() / 8));
	subtitle_font_.drawStringCentered("What is your name?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
	input_text_box_.draw();
	subtitle_font_.drawStringCentered("How many habits would you like to track?", ofGetWidth() / 2, ((ofGetHeight() / 8) + 175));
	input_int_box_.draw();
	DrawNextButton();
	update();
}

void HabitTracker::DrawOldUser() {
	ofSetColor(0);
	title_font_.drawStringCentered("Welcome Back!", ofGetWidth() / 2, (ofGetHeight() / 8));
	subtitle_font_.drawStringCentered("Enter your username:", ofGetWidth() / 2, ((ofGetHeight() / 8) + 85));
	input_text_box_.draw();
	DrawNextButton();
	update();
}

void HabitTracker::DrawAddHabits() {
	ofSetColor(0);
	title_font_.drawStringCentered("Add habits: ", ofGetWidth() / 2, (ofGetHeight() / 8));
	input_text_box_.draw();
	ofSetColor(name_habit_button_color_);
	ofDrawRectRounded(name_habit_button_, 10);
	ofSetColor(0);
	button_font_.drawStringCentered(name_habit_button_message_, ofGetWidth() / 2, kLower_button_message_position);
	DrawNextButton();
	update();
}

void HabitTracker::DrawCheckHabits() {
	ofSetColor(0);
	title_font_.drawStringCentered("Habit Checklist: ", ofGetWidth() / 2, (ofGetHeight() / 8));
	DrawNextButton();

	ofSetColor(habit_completed_button_color_);
	ofDrawRectRounded(habit_completed_button_, 10);

	ofSetColor(habit_not_completed_button_color_);
	ofDrawRectRounded(habit_not_completed_button_, 10);

	ofSetColor(0);
	button_font_.drawStringCentered(habit_completed_button_message_, ofGetWidth() / 2, kUpper_button_message_position);
	button_font_.drawStringCentered(habit_not_completed_button_message_, ofGetWidth() / 2, kLower_button_message_position + 10);
	update();
}

void HabitTracker::DrawDisplay() {
	ofSetColor(0);
	title_font_.drawStringCentered("Habit Tracker", ofGetWidth() / 2, (ofGetHeight() / 8));
	prettyPrintProgress();
}

//--------------------------------------------------------------
void HabitTracker::draw() {
	switch (curr_game_state_) {
	case SHOW_INTRO:
		DrawIntro();
		break;
	case NEW_USER:
		DrawNewUser();
		break;
	case OLD_USER:
		DrawOldUser();
		break;
	case ADD_HABITS:
		DrawAddHabits();
		break;
	case CHECK_HABIT_DONE:
		DrawCheckHabits();
		break;
	case DISPLAY_HABITS:
		DrawDisplay();
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
	if (curr_game_state_ == ADD_HABITS && name_habit_button_.inside(x, y)) {
		name_habit_clicked_ = true;
	}
	if (curr_game_state_ == CHECK_HABIT_DONE) {
		if (habit_completed_button_.inside(x, y)) {
			habit_completed_ = true;
		} else if (habit_not_completed_button_.inside(x, y)) {
			habit_not_completed_ = true;
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

void HabitTracker::updateFile() {
	result_.open(json_file_name_);
	result_["user_name_"] = current_user_.getUserName();
	result_["num_habits_"] = current_user_.getNumOfHabits();
	for (int i = 0; i < current_user_.getNumOfHabits(); i++) {
		result_["user_habits_"][i]["name"] = current_user_.getUserHabits().at(i).name_;
	}
	int j = 0;
	for (User::Habit current_habit_ : current_user_.getUserHabits()) {
		for (int i = 0; i < current_habit_.habit_done_.size(); i++) {
			result_["user_habits_"][j]["habit_done"].append(Json::Value(current_habit_.habit_done_.at(i)));
		}
		j++;
	}
	result_.save(json_file_name_);
}

void HabitTracker::PrettyPrintHabitNames() {
	int title_spacing_ = 100;
	for (int i = 0; i < current_user_.getNumOfHabits(); i++) {
		ofSetColor(0);
		std::string habit_name = current_user_.getUserHabits().at(i).name_;
		subtitle_font_.drawStringCentered(habit_name, ofGetWidth() / 6, ((ofGetHeight() / 8) + title_spacing_));
		title_spacing_ += 75;
	}
}

void HabitTracker::PrettyPrintHabitBoxes() {
	int y_spacing_ = 70;
	for (int i = 0; i < current_user_.getNumOfHabits(); i++) {
		int x_spacing_ = 55;
		for (int j = 0; j < result_["user_habits_"][i]["habit_done"].size(); j++) {
			x_spacing_ += 85;
			if (result_["user_habits_"][i]["habit_done"][j].asBool()) {
				switch (i) {
				case 0: ofSetColor(red_);
					break;
				case 1: ofSetColor(orange_);
					break;
				case 2:	ofSetColor(yellow_);
					break;
				case 3: ofSetColor(green_);
					break;
				case 4: ofSetColor(blue_);
					break;
				}
				ofFill();
				habit_display_.set((ofGetWidth() / 6) + x_spacing_, (ofGetHeight() / 8) + y_spacing_, 55, 55);
				ofDrawRectRounded(habit_display_, 10);
			} else {
				ofSetColor(0);
				ofNoFill();
				habit_display_.set((ofGetWidth() / 6) + x_spacing_, (ofGetHeight() / 8) + y_spacing_, 55, 55);
				ofDrawRectRounded(habit_display_, 10);
			}
		}
		y_spacing_ += 75;
	}
}

void HabitTracker::prettyPrintProgress() {
	PrettyPrintHabitNames();
	PrettyPrintHabitBoxes();
}

void HabitTracker::loadUserFromFile() {
	bool parsingSuccessful = result_.open(json_file_name_);
	if (parsingSuccessful) {
		current_user_.setHabitNum(result_["num_habits_"].asInt());
		for (int i = 0; i < current_user_.getNumOfHabits(); i++) {
			current_user_.addHabit(result_["user_habits_"][i]["name"].asString());
		}
	} else {
		std::cout << "Parsing unsuccessful.";
	}
	
}
