#pragma once

#include "ofMain.h"
#include "user.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofxGui.h"
#include "ofxOscParameterSync.h"
#include "ofxDatGuiTextInput.h"

class ofApp : public ofBaseApp {

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
	void DrawNextButton();
	bool bFirst;
private:
	enum GameState {
		SHOW_INTRO = 0,
		NEW_USER, //GET USER NAME AND CREATE FILE
		OLD_USER, //ASK FOR USERNAME TO LOAD INFO
		ADD_HABITS, //ADD HABIT SCREEN 
		CHECK_HABIT_DONE, //SHOW IF HABIT IS DONE
		DISPLAY_HABITS, //DISPLAY ALL USER HABITS AND WHETHER HABIT IS DONE OR NOT
	};
	void SetUpButtons();
	
	std::string new_user_button_message_;
	ofRectangle new_user_button_;

	std::string old_user_button_message_;
	ofRectangle old_user_button_;

	std::string next_button_message_;
	ofRectangle next_button_;

	bool is_new_user_button_clicked;
	bool is_old_user_button_clicked;
	bool next_button_clicked;

	ofColor new_user_button_color_ = ofColor(185, 224, 217, 255);
	ofColor old_user_button_color_ = ofColor(185, 224, 217, 255);
	ofColor next_button_color_ = ofColor(185, 224, 217, 255);

	int new_user_button_width;
	int new_user_button_height;

	int old_user_button_width;
	int old_user_button_height;

	int next_button_width;
	int next_button_height;

	User current_user;
	GameState curr_game_state_;
	ofxDatGuiTextInput* myInput;
	ofxInputField<std::string> user_name;
	ofxCenteredTrueTypeFont title_font_; //changed to ofxcentered true type font
	ofxCenteredTrueTypeFont subtitle_font_;
	ofxCenteredTrueTypeFont button_font_;
};