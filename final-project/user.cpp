#include "user.h"
//class for parsing JSON file

//default constructor
user::user() {
	user_name = "";
}
user::user(std::string name, int habit_number) {
	user_name = name;
	num_of_habits = habit_number;
}
user::~user() {
}
std::string user::getUserName() {
	return user_name;
}
std::vector<user::Habit> user::getUserHabits() {
	return user_habits;
}
int user::getNumOfHabits() {
	return num_of_habits;
}
std::string user::getHabitName(Habit habit) {
	return habit.name;
}
void user::setHabitArray(Habit habit, bool is_done) {
	habit.habit_done.push_back(is_done);
}

