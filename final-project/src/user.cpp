#include "user.h"
//class for parsing JSON file

//default constructor
User::User() {
	user_name_ = "";
}
User::User(std::string name, int habit_number) {
	user_name_ = name;
	
}
void User::setUserName(std::string name) {
	user_name_ = name;
}
void User::checkHabit(int habit_num, bool done) {
	user_habits_[habit_num].habit_done.push_back(done);
}
void User::setHabitNum(int num) {
	num_habits_ = num;
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

void User::setHabitName(Habit habit, std::string input) {
	habit.name = input;
}
void User::addHabit(std::string habit_name) {
	Habit to_add_;
	to_add_.name = habit_name;
	to_add_.habit_done = {};
	user_habits_.push_back(to_add_);
}

std::vector<bool> User::getHabitDone(Habit habit) {
	return habit.habit_done;
}
