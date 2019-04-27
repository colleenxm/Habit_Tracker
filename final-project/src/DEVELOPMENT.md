##4/19/19 
* Fixed debug-lib problem by reinstalling openframeworks. 
* Discovered bug in project generator that was causing project to be built without proper library dependencies. 
* Replaced old version of openframeworks and now the proper libraries are there.
* Also downloaded ofxJSON, the JSON.cpp wrapper for openframeworks.
##4/20/19 
* Wrote getter and setter methods for the user class to access parts of habit struct.
* Wrote habitCreator, trackCurrentDay, createJson, fileExists and getUserName. 
* File exsits and get user name were code taken from naive bayes mp. 
* Roadblock in back end - cannot figure out how to write to a json file. 
* Switching to work on GUI for a bit because currently is just the GUI example from ofxGUI. May use ofxDATGUI. 
##4/23/19
* Added enum to ofApp.h in order to switch game states based on user input.
* Planned out the different windows for the code. 
##4/25/19
* Fixed the file structure so that it appears more clean on github. 
* Deleted some commented out code that was no longer relevant and had been fixed. 
##4/26/19
* Worked on graphics - adding buttons for new and old user. Ultimately created rectangles and checked for mouse in them like in Pacman.
* Loaded new fonts for subtitles and buttons. 
* Unsure of purpose of bool values for buttons clicked. 
* Struggling to create input text field - trying SystemDialog from piazza
##4/27/19
* Buttons work, added semi-permanent next button to progress through states but currently stuck because it skips a few states in the middle
* Centered text
* Using parameter  and gui panel to get inputfield but panel is moveable and not aesthetic
* Cannot translate back end methods into update() function easily - have user as part of ofApp but causes issues. 