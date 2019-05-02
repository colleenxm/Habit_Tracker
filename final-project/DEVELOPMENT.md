# DOCUMENTATION
## 4/19/19 
* Fixed debug-lib problem by reinstalling openframeworks. 
* Discovered bug in project generator that was causing project to be built without proper library dependencies. 
* Replaced old version of openframeworks and now the proper libraries are there.
* Also downloaded ofxJSON, the JSON.cpp wrapper for openframeworks.
## 4/20/19 
* Wrote getter and setter methods for the user class to access parts of habit struct.
* Wrote habitCreator, trackCurrentDay, createJson, fileExists and getUserName. 
* File exsits and get user name were code taken from naive bayes mp. 
* Roadblock in back end - cannot figure out how to write to a json file. 
* Switching to work on GUI for a bit because currently is just the GUI example from ofxGUI. May use ofxDATGUI. 
## 4/23/19
* Added enum to ofApp.h in order to switch game states based on user input.
* Planned out the different windows for the code. 
## 4/25/19
* Fixed the file structure so that it appears more clean on github. 
* Deleted some commented out code that was no longer relevant and had been fixed. 
## 4/26/19
* Worked on graphics - adding buttons for new and old user. Ultimately created rectangles and checked for mouse in them like in Pacman.
* Loaded new fonts for subtitles and buttons. 
* Unsure of purpose of bool values for buttons clicked. 
* Struggling to create input text field - trying SystemDialog from piazza
## 4/27/19
* Buttons work, added semi-permanent next button to progress through states but currently stuck because it skips a few states in the middle
* Centered text
* Using parameter  and gui panel to get inputfield but panel is moveable and not aesthetic
* Cannot translate back end methods into update() function easily - have user as part of ofApp but causes issues. 
* Adjusted code/structure to better fit critiques from code review.
* Plan on fixing user input and adding JSON capability so code saves user data.
* Plan to add music
## 4/30/19
* Changed number input section into slider for convinience
* Got input_text_box_ to take user input and store it on the user model.
* Fixed issues with adding habits to code by tracking how many times add habit button was pushed to avoid the issue of listeners, which was creating too many habits. Did same for CHECK_HABIT_DONE state to avoid too many checks.
## 5/1/19
* Set up JSON parsing using ofxJSON wrapper for JSONCPP, created load from file method. 
* Allowed for user to input file name to access pre-existing JSON file
* Used Json vecotr from ofxJSON to append new user data about habits into file that existed already.
* Used sound player to add music for background
* Fixed prettyprint to display boxes accurately and line up with habits
* Cleaned up extraneous code, fixed comments, broke up large methods into smaller ones. Debatec moving some methods into habitUtils but based on discussion in code review, habitUtils does not represent anything new and therefore a new class is not needed nor useful. Would ultimately just be extra code that makes it more confusing, not less.
* Adjusted boxes so that for days where habit wa snot completed, it shows a black outline of a box. 
* Removed all magic numbers.
