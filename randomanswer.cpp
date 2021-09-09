#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


int main (int argc, char** argv)
{
	srand(time(NULL));
	std::string answer;
	int ans_possible;
	int i=1;
	
	std::vector<std::string> vec_answer;
	
	std::cout << "Wie viele Antwortmöglichkeiten brauchst du? " << std::endl;
	std::cin >> ans_possible;
	std::cin.ignore();
	
	while(i <= ans_possible)
	{
		std::cout << "Gebe die " << i << ". Antwort ein: " << std::endl;
		getline(std::cin, answer);
		vec_answer.push_back(answer);
		i=i+1;
	}
	
	std::cout << "Deine zufällig erstellte Antwort lautet: " << std::endl;
	std::cout << vec_answer[rand() % ans_possible] << std::endl;
}
