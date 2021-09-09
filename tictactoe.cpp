#include <iostream>
#include <vector>
#include <string>
extern int frage_feld_nummer(std::vector<int> feld);
extern void gebe_feld_aus(std::vector<int> feld);
extern int gewinnerin(std::vector<int> feld);

// Fügt hier die anderen Funktionen ein

int main() {
	std::vector<int> spielfeld={{0,0,0,0,0,0,0,0,0}};
	
	std::string spieler1;
	std::string spieler2;

	int eingabe_feld;
	int turn=0;

	std::cout << "Gebe den Name von Spieler1 ein: " << std::endl;
	std::cin >> spieler1;
	std::cout << "Gebe den Name von Spieler2 ein: " << std::endl;
	std::cin >> spieler2;

    while (true) {
	    
	if(turn==0)
	{
		std::cout << spieler1 << " hat das Symbol X und ist drann!" << std::endl;
		
		eingabe_feld=frage_feld_nummer(spielfeld);
        	spielfeld[eingabe_feld] = 1;
		if(gewinnerin(spielfeld) == 1)
		{
			std::cout << spieler1 << " hat gewonnen!" << std::endl;
			gebe_feld_aus(spielfeld);
			return 0;
		}
			else if(gewinnerin(spielfeld) == 2)
			{
				std::cout << spieler2 << " hat gewonnen!" << std::endl;
				gebe_feld_aus(spielfeld);
				return 0;
			}
				else if(gewinnerin(spielfeld) == 3)
				{
					std::cout << "Das Spiel endet unentschieden" << std::endl;
					gebe_feld_aus(spielfeld);
					return 0;
				}

		gebe_feld_aus(spielfeld);
		turn = turn+1;
	} else {
		std::cout << spieler2 << " hat das Symbol O und ist drann!" << std::endl;

		eingabe_feld=frage_feld_nummer(spielfeld);
		spielfeld[eingabe_feld] = 2;

		if(gewinnerin(spielfeld) == 1)
		{
			std::cout << spieler1 << " hat gewonnen!" << std::endl;
			gebe_feld_aus(spielfeld);
			return 0;
		}
			else if(gewinnerin(spielfeld) == 2)
			{
				std::cout << spieler2 << " hat gewonnen!" << std::endl;
				gebe_feld_aus(spielfeld);
				return 0;
			}
				else if(gewinnerin(spielfeld) == 3)
				{
					std::cout << "Das Spiel endet unentschieden" << std::endl;
					gebe_feld_aus(spielfeld);
					return 0;
				}

		gebe_feld_aus(spielfeld);
		turn = turn-1;
    	}
}
    std::cout << "sind hier"<< std::endl;
    return 0;
}

