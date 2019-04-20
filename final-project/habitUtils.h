#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <vector>  
#include "user.h"
class habitUtils
{
public:
	/**
	Empty constructor 
	*/
	habitUtils();

	~habitUtils();
	/**
	Use iostream to get the user's name
	*/
	std::string getUserName(std::string user_message);

	/**
	See if json fie with given user name exists already
	*/
	bool fileExists(std::string& file_name);

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
	void trackCurrentDay(user user);

	/**
	Loop through and create habits
	*/
	void habitCreator(user user);
};

