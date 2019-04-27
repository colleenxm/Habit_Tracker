#include "user.h"
//class for parsing JSON file

//default constructor
User::User() {
	user_name_ = "";
}
User::User(std::string name, int habit_number) {
	user_name_ = name;
	num_habits_ = habit_number;
	for (int i = 0; i < habit_number; i++) {
		Habit random;
		user_habits_.push_back(random);
	}
}
void User::setUserName(std::string name) {
	user_name_ = name;
}

void User::setHabitNum(int num) {
	num_habits_ = num;
	user_habits_.clear();
	for (int i = 0; i < num; i++) {
		Habit random;
		user_habits_.push_back(random);
	}
}

std::string User::getUserName() { //make all getters const
	return user_name_;
}
std::vector<User::Habit> User::getUserHabits() {
	return user_habits_;
}
int User::getNumOfHabits() {
	return num_habits_;
}
std::string User::getHabitName(Habit habit) {
	return habit.name;
}
void User::setHabitArray(Habit habit, bool is_done) {
	habit.habit_done.push_back(is_done);
}

void User::setHabitName(Habit habit, std::string input) {
	habit.name = input;
}