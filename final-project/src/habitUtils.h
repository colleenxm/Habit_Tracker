#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>  
#include "user.h"

class habitUtils { //make namespace, not class
public:

	/**
	Use iostream to get the user's name
	*/
	std::string getUserName(const std::string& user_message); //pass all as const references

	/**
	See if json fie with given user name exists already
	*/
	bool doesFileExists(std::string& file_name);

	/**
	Create new json file from existing user
	*/
	void createJson(std::string file_name);

	/**
	Send changes from user class to the user's json file
	*/
	void updateJson();

	/**
	Loop through user's habits and print done or not
	*/
	void prettyPrint();

	/**
	Ask if each habit was done today and update habit array
	*/
	void trackCurrentDay(User& user);

	/**
	Loop through and create habits
	*/
	void habitCreator(User& user); //create habit
};

