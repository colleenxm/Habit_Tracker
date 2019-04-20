#include "habitUtils.h"

habitUtils::habitUtils()
{
}

habitUtils::~habitUtils()
{
}

std::string habitUtils::getUserName(std::string question) {
	std::string input = "";
	std::cout << question;
	std::getline(std::cin, input);
	while (!fileExists(input)) {
		std::cout << "Invalid file name! Try again.\n";
		std::getline(std::cin, input);
	}
	std::cout << "Valid file name!\n";
	return input;
}
bool habitUtils::fileExists(std::string& file_name) {
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
void habitUtils::trackCurrentDay(user user) {
	for (int i = 0; i < user.getNumOfHabits(); i++) {
		//ask if habit done
		std::string input = "";
		std::cout << "Did you complete: " << user.getHabitName(user.getUserHabits.at(i)) << " today?";
		std::getline(std::cin, input);
		//appead either true or false to 
		if (input == "Yes" || input == "yes" || input == "true") {
			user.setHabitArray(user.getUserHabits.at(i), true);
		}
		else {
			user.setHabitArray(user.getUserHabits.at(i), false);
		}
	}
}
void habitUtils::habitCreator(user user) {
	for (int i = 0; i < user.getNumOfHabits(); i++) {
		std::string input = "";
		std::cout << "What would you like to name this habit?";
		std::getline(std::cin, input);
		user.setHabitName(user.getUserHabits.at(i), input);
	}
}
