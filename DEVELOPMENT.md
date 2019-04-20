4/19/19 8pm-12am
Fixed debug-lib problem by reinstalling openframeworks. Discuvered bug in project generator that was causing project to be built
without proper library dependencies. Replaced old version of openframeworks and noww the proper libraries are there. Also
downloaded ofxJSON, the JSON.cpp wrapper for openframeworks.
4/20/19 5am - 7am
Wrote getter and setter methods for the user class to access parts of habit struct.
Wrote habitCreator, trackCurrentDay, createJson, fileExists and getUserName. File exsits and get user name were 
code taken from naive bayes mp. Roadblock in back end - cannot figure out how to write to a json file. Switching to work on
GUI for a bit because currently is just the GUI example fro ofxGUI. May usse ofxDATGUI. 