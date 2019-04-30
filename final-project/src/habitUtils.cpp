#include "habitUtils.h"


std::string habitUtils::getUserName(const std::string& question) {
	std::string input = "";
	std::cout << question;
	std::getline(std::cin, input);
	while (!doesFileExists(input)) {
		std::cout << "Invalid file name! Try again.\n";
		std::getline(std::cin, input);
	}
	std::cout << "Valid file name!\n";
	return input;
}

bool habitUtils::doesFileExists(std::string& file_name) { 
	std::ifstream infile(file_name);
	return infile.good();
}
void habitUtils::createJson(std::string file_name) {
	std::ofstream file{ 
		file_name + ".json"
	};
}
void habitUtils::updateJson() {

}
void habitUtils::prettyPrint() {

}
void habitUtils::trackCurrentDay(User& user) {
	std::vector<User::Habit> habits = user.getUserHabits();

	for (const auto& curr_habit : habits) {
		std::string input = "";
		std::cout << "Did you complete: " << user.getHabitName(curr_habit) << " today?";
		std::getline(std::cin, input);
		//append either true or false to habit array
		if (input == "Yes" || input == "yes" || input == "true") {
			user.setHabitArray(curr_habit, true);
		} else {
			user.setHabitArray(curr_habit, false);
		}
	}
}
void habitUtils::habitCreator(User& user) {
	std::vector<User::Habit> habits = user.getUserHabits();
	for (const auto& curr_habit : habits) {
		std::string input = "";
		std::cout << "What would you like to name this habit?";
		std::getline(std::cin, input);
		user.setHabitName(curr_habit, input);
	}
}
