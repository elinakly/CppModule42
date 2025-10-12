#include <iostream>

int main(int ac, char *ag[]){

	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; ag[i][j]; j++)
		std::cout << (char)std::toupper(ag[i][j]);
	}
	std::cout << std::endl;
	return 0;
}