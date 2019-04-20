#include "user.h"
//class for parsing JSON file

//default constructor
user::user()
{
	user_name = "";
}
user::user(std::string name)
{
	user_name = name;
}
user::~user()
{
}
