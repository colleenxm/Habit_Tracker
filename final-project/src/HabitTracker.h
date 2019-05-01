#pragma once

#include "ofMain.h"
#include "user.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofxGui.h"
#include "ofColor.h"
#include "ofxDatGuiTextInput.h"


class HabitTracker : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	void createFile(std::string file_name);

	enum GameState {
		SHOW_INTRO = 0,
		NEW_USER, //GET USER NAME AND CREATE FILE
		OLD_USER, //ASK FOR USERNAME TO LOAD INFO
		ADD_HABITS, //ADD HABIT SCREEN 
		CHECK_HABIT_DONE, //SHOW IF HABIT IS DONE
		DISPLAY_HABITS, //DISPLAY ALL USER HABITS AND WHETHER HABIT IS DONE OR NOT
	};
	
	void SetUpButtons();

	void DrawNextButton();
	
	std::string new_user_button_message_;
	ofRectangle new_user_button_;

	std::string old_user_button_message_;
	ofRectangle old_user_button_;

	std::string next_button_message_;
	ofRectangle next_button_;

	std::string habit_completed_button_message_;
	ofRectangle habit_completed_button_;

	std::string habit_not_completed_button_message_;
	ofRectangle habit_not_completed_button_;

	std::string name_habit_button_message_;
	ofRectangle name_habit_button_;

	bool is_new_user_button_clicked_;
	bool is_old_user_button_clicked_;
	bool next_button_clicked_;
	bool habit_completed_;
	bool habit_not_completed;
	bool name_habit_clicked_;

	ofColor new_user_button_color_ = ofColor(185, 224, 217, 255); //init in ofApp.cpp & comment what color it is
	ofColor old_user_button_color_ = ofColor(185, 224, 217, 255);
	ofColor next_button_color_ = ofColor(185, 224, 217, 255);
	ofColor habit_completed_button_color_ = ofColor(185, 224, 217, 255);
	ofColor habit_not_completed_button_color_ = ofColor(185, 224, 217, 255);
	ofColor name_habit_button_color_ = ofColor(185, 224, 217, 255);
	ofColor light_up_color = ofColor(185, 224, 217, 105);
	size_t new_user_button_width_;
	size_t new_user_button_height_;

	size_t old_user_button_width_;
	size_t old_user_button_height_;

	size_t next_button_width_;
	size_t next_button_height_;

	size_t habit_completed_button_width_;
	size_t habit_completed_button_height_;

	size_t habit_not_completed_button_width_;
	size_t habit_not_completed_button_height_;

	size_t name_habit_button_width_;
	size_t name_habit_button_height_;

	User current_user_;
	GameState curr_game_state_; 

	ofxCenteredTrueTypeFont title_font_; 
	ofxCenteredTrueTypeFont subtitle_font_;
	ofxCenteredTrueTypeFont button_font_;

	ofxGuiGroup input_text_box_;
	ofxGuiGroup input_int_box_;
	ofParameter<std::string> input_text_;
	ofxIntSlider input_int_;

	std::vector<User::Habit> habits;
	User::Habit curr_habit;
	std::string question;
	int num;
};