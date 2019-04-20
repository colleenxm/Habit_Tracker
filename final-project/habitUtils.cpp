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
		std::cout << "Invalid file name! Try again.";
		std::getline(std::cin, input);
	}
	std::cout << "Valid file name!\n";
	return input;
	
}
bool habitUtils::fileExists(std::string& file_name) {
	std::ifstream infile(file_name);
	return infile.good();
}
void habitUtils::createJson() {

}
void habitUtils::updateJson() {

}
void habitUtils::prettyPrint() {

}
void habitUtils::trackCurrentDay() {

}
void habitUtils::habitCreator() {

}
