#pragma once

#include "ofMain.h"
#include "user.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofxGui.h"
#include "ofxJSON.h"
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
	// Enum to represent the current state of the game
	enum GameState {
		SHOW_INTRO = 0,
		NEW_USER, //GET USER NAME AND CREATE FILE
		OLD_USER, //ASK FOR USERNAME TO LOAD INFO
		ADD_HABITS, //ADD HABIT SCREEN 
		CHECK_HABIT_DONE, //SHOW IF HABIT IS DONE
		DISPLAY_HABITS, //DISPLAY ALL USER HABITS AND WHETHER HABIT IS DONE OR NOT
	};

	//SETUP BUTTONS
	void SetUpNewUserButton();
	void SetUpOldUserButton();
	void SetUpNextButton();
	void SetUpHabitCompletedButton();
	void SetUpHabitNotCompletedButton();
	void SetUpNameHabitButton();

	void UpdateNextButtonClicked();
	void AddHabits();
	void CheckHabitsDone();
	/**
	Quick setup method to define dimensions and positions of buttons
	*/
	void SetUpButtons();

	/**
	Method draws next button that is in multiple screens
	*/
	void DrawNextButton();

	/**
	Update the JSON file to represent the updated user data
	*/
	void updateFile();

	/**
	Creates file if not existing already and sets user data in game equal to saved user data
	*/
	void loadUserFromFile();

	/**
	Draws the progress of the user including which habits were completed on each day
	*/
	void prettyPrintProgress();

	//BUTTONS & BUTTON MESSAGES - using ofxCenteredTrueTypeFont and the bounding rectangle
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

	ofRectangle habit_display_;

	//BUTTONS CLICKED BOOL
	bool is_new_user_button_clicked_;
	bool is_old_user_button_clicked_;
	bool next_button_clicked_;
	bool habit_completed_;
	bool habit_not_completed_;
	bool name_habit_clicked_;

	//BUTTON COLORS
	ofColor default_ = ofColor(147, 112, 219, 155);
	ofColor new_user_button_color_ = default_; //init in ofApp.cpp & comment what color it is
	ofColor old_user_button_color_ = default_;
	ofColor next_button_color_ = default_;
	ofColor habit_completed_button_color_ = default_;
	ofColor habit_not_completed_button_color_ = default_;
	ofColor name_habit_button_color_ = default_;
	
	//BOX COLORS
	ofColor red_ = ofColor(250, 128, 114, 255);
	ofColor orange_ = ofColor(250, 181, 112, 255);
	ofColor yellow_ = ofColor(250, 250, 112, 255);
	ofColor green_ = ofColor(112, 250, 147, 255);
	ofColor blue_ = ofColor(112, 250, 250, 255);

	//BUTTON DIMENSIONS
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

	//user - stores habits and habit_done_ during app running
	User current_user_;
	//Gamestate local to instance of app
	GameState curr_game_state_; 

	//FONTS
	ofxCenteredTrueTypeFont title_font_; 
	ofxCenteredTrueTypeFont subtitle_font_;
	ofxCenteredTrueTypeFont button_font_;

	//INPUT FIELDS
	ofxGuiGroup input_text_box_;
	ofxGuiGroup input_int_box_;
	ofParameter<std::string> input_text_;
	ofxIntSlider input_int_;

	//HABIT ARRAY FOR ITERATING
	std::vector<User::Habit> habits;
	User::Habit curr_habit;

	//Variables for convinience 
	std::string question_;
	size_t num_;

	//JSON PARSING ELEMENTS
	ofxJSONElement result_;
	std::string json_file_name_;

	//MUSIC
	std::string kBackground_music_file_name_ = "backgroundMusic.mp3";
	ofSoundPlayer mySound;
};