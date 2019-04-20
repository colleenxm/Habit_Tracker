#include "user.h"
//class for parsing JSON file

//default constructor
user::user() {
	user_name_ = "";
}
user::user(std::string name, int habit_number) {
	user_name_ = name;
	num_habits_ = habit_number;
	for (int i = 0; i < habit_number; i++) {
		Habit random;
		user_habits_.push_back(random);
	}
}

std::string user::getUserName() { //make all getters const
	return user_name_;
}
std::vector<user::Habit> user::getUserHabits() {
	return user_habits_;
}
int user::getNumOfHabits() {
	return num_habits_;
}
std::string user::getHabitName(Habit habit) {
	return habit.name;
}
void user::setHabitArray(Habit habit, bool is_done) {
	habit.habit_done.push_back(is_done);
}

void user::setHabitName(Habit habit, std::string input) {
	habit.name = input;
}