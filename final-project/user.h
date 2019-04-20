#pragma once
#include <string>
#include <iostream> 
#include <vector> 
class user
{
	struct Habit {
		std::string name;
		std::vector<bool> habit_done;
	};
public:
	//default constructor
	user();
	//constructor with username
	user(std::string name);
	~user();
private:
	std::string user_name;
	std::vector<Habit> user_habits;
};



