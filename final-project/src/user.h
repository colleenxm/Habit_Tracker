#pragma once
#include <string>
#include <iostream> 
#include <vector> 
class User
{
public: 
	/**
	Struct to contain habit - two fields, name of habit and boolean array of whether or not habit was done each day
	*/
	struct Habit {
		std::string name_;
		std::vector<bool> habit_done_;
	};

	/**
	Default constructor
	*/
	User();

	/**
	Constructor of username and number of habits the user plans on tracking
	*/
	User(std::string& name, size_t& habit_number);

	/**
	Getter for user name
	*/
	const std::string getUserName();

	/**
	Getter for user's array of Habits
	*/
	const std::vector<Habit> getUserHabits();

	/**
	Getter for the number of habits a user has
	*/
	const int getNumOfHabits();

	/**
	Getter for the name of the habit, parameter is habit that you are getting name of
	*/
	const std::string getHabitName(Habit& habit);

	/**
	Getter of  habit passed as parameter's done array, which tracks how many habits were done each day
	*/
	const std::vector<bool> getHabitDone(Habit& habit);

	/**
	Sets the user name of user
	*/
	void setUserName(std::string name); 

	/**
	Sets the number of habits 
	*/
	void setHabitNum(int num);
	
	/**
	Sets whether or not habit given habit's point in user habit array, was done or not
	*/
	void setHabitDone(int habit_num, bool done);
	
	/**
	Sets the name of given habit given input
	*/
	void setHabitName(Habit& habit, std::string input);

	/**
	Adds new habit
	*/
	void addHabit(std::string habit_name);

private:
	/**
	Name of user
	*/
	std::string user_name_;

	/**
	Number of habits user has
	*/
	int num_habits_;

	/**
	Array of habits user has
	*/
	std::vector<Habit> user_habits_;
};



