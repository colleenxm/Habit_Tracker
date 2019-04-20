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
	user();
	~user();
private:
	std::vector<Habit> user_habits;
};



