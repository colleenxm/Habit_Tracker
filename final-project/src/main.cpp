#include "ofMain.h"
#include "HabitTracker.h"

//========================================================================
int main() {

	ofSetupOpenGL(800, 600, OF_WINDOW);
	ofRunApp(new HabitTracker());
}