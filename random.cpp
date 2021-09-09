#include <iostream>
#include <cstdlib>
#include <ctime>

int main (int argc, char** argv)
{
	int zahlen;
	int i;
	int randomzahl;
	srand(time(NULL));

	std::cout << "Gebe an wie viele Zufallszahlen ausgegeben werden sollen: " << std::endl;
	std::cin >> zahlen;

	for(i=1; i<=zahlen; i=i+1)
	{
		randomzahl=rand() %7+1;
		std::cout << randomzahl << std::endl;
	}
}
