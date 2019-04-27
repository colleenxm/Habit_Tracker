#pragma once
#include <string>
#include <iostream> 
#include <vector> 
class User
{
public: //add documentation
	struct Habit {
		std::string name;
		std::vector<bool> habit_done;
	};
	//default constructor
	User();
	//constructor with username
	User(std::string name, int habit_number);

	std::string getUserName();

	std::vector<Habit> getUserHabits();

	int getNumOfHabits();

	std::string getHabitName(Habit habit);

	void setUserName(std::string name); //make habits references or const refs

	void setHabitNum(int num);

	void setHabitArray(Habit habit, bool is_done); //make habits references or const refs

	void setHabitName(Habit habit, std::string input);

private:
	std::string user_name_;
	int num_habits_;
	std::vector<Habit> user_habits_;
};



