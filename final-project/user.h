#pragma once
#include <string>
#include <iostream> 
#include <vector> 
class user
{
	struct Habit;
public:
	struct Habit {
		std::string name;
		std::vector<bool> habit_done;
	};
	//default constructor
	user();
	//constructor with username
	user(std::string name, int habit_number);

	~user();

	std::string getUserName();

	std::vector<Habit> getUserHabits();

	int getNumOfHabits();

	std::string getHabitName(Habit habit);

	void setHabitArray(Habit habit, bool is_done); //make habits references or const refs

	void setHabitName(Habit habit, std::string input);

private:
	std::string user_name_;
	int num_habits_;
	std::vector<Habit> user_habits_;
};



