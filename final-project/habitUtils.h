#pragma once
class habitUtils
{
public:

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
private:

};

