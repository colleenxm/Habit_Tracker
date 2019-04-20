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
	user(std::string name, int habit_number);
	~user();
	std::string getUserName();
	std::vector<Habit> getUserHabits();
	int getNumOfHabits();
	std::string getHabitName(Habit habit);
	void setHabitArray(Habit habit, bool is_done);
	void setHabitName(Habit habit, std::string input);
private:
	std::string user_name;
	int num_of_habits;
	std::vector<Habit> user_habits;
};



