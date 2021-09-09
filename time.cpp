#include <iostream>
#include <ctime>

int main (int argc, char** argv)
{
	time_t timer;
//	timer = time(NULL);
	std::cout << time(&timer) << std::endl;
}
