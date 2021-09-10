#include <iostream>
#include <vector>
#include <string>

void gebe_feld_aus(std::vector<int> feld)
{
{
	int i=0;
	std::vector<std::string> feld2 = {{" "," "," "," "," "," "," "," "," "}};
	
while(i<=8)
{
	if(feld[i] == 1)
	{
		feld2[i] = "X";
	}
		else if (feld[i] == 2)
		{
			feld2[i] = "O";
		}
i=i+1;
}

std::cout << "     \u2502     \u2502     " << std::endl;
std::cout << "  " << feld2[0] << "  \u2502  " << feld2[1] << "  \u2502  "<< feld2[2] << "   " << std::endl;
std::cout << "     \u2502     \u2502     " << std::endl;
std::cout << "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500" << std::endl;
std::cout << "     \u2502     \u2502     " << std::endl;
std::cout << "  " << feld2[3] << "  \u2502  " << feld2[4] << "  \u2502  "<< feld2[5] << "   " << std::endl;
std::cout << "     \u2502     \u2502     " << std::endl;
std::cout << "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500" << std::endl;
std::cout << "     \u2502     \u2502     " << std::endl;
std::cout << "  " << feld2[6] << "  \u2502  " << feld2[7] << "  \u2502  "<< feld2[8] << "   " << std::endl;
std::cout << "     \u2502     \u2502     " << std::endl;
}

}
	

int gewinnerin(std::vector<int> feld)
{
	int i=0;
	
	while(i<=8)
	{
		if(feld[i]==0)
		{
			feld[i] = 100;
		}
	i=i+1;
	}
//Check Reihe
		if(feld[0] + feld[1] + feld[2] == 3)
		{
			return 1;
		}
			else if(feld[0] + feld[1] + feld[2] == 6)
			{
				return 2;
			}
		if(feld[3] + feld[4] + feld[5] == 3)
		{
			return 1;
		}
			else if(feld[3] + feld[4] + feld[5] == 6)
			{
				return 2;
			}
		if(feld[6] + feld[7] + feld[8] == 3)
		{
			return 1;
		}
			else if(feld[6] + feld[7] + feld[8] == 6)
			{
				return 2;
			}
//Check Reihe ende

//Check Spalte
		if(feld[0] + feld[3] + feld[6] == 3)
		{
			return 1;
		}
			else if(feld[0] + feld[3] + feld[6] == 6)
			{
				return 2;
			}
		if(feld[1] + feld[4] + feld[7] == 3)
		{
			return 1;
		}
			else if(feld[1] + feld[4] + feld[7] == 6)
			{
				return 2;
			}
		if(feld[2] + feld[5] + feld[8] == 3)
		{
			return 1;
		}
			else if(feld[2] + feld[5] + feld[8] == 6)
			{
				return 2;
			}
//Check Spalte ende
	
//Check Diagonale	
		if(feld[0] + feld[4] + feld[8] == 3)
		{
			return 1;
		}
			else if(feld[0] + feld[4] + feld[8] == 6)
			{
				return 2;
			}
		if(feld[2] + feld[4] + feld[6] == 3)
		{
			return 1;
		}
			else if(feld[2] + feld[4] + feld[6] == 6)
			{
				return 2;
			}
//Check Diagonale ende

//Check unentschieden

	if(feld[0] + feld[1] + feld[2] + feld[3] + feld[4] + feld[5] + feld[6] + feld[7] + feld[8] == 13)
	{
		return 3;
	}
//Check unentschieden ende
return 0;
}
int frage_feld_nummer(std::vector<int> feld)
{
	int feldnummer;
	std::cout << "Gebe eine Feldnummer (0-8) ein." << std::endl;
	std::cin >> feldnummer;
	
	while(feldnummer < 0 || feldnummer > 8)
	{
		std::cout << "Fehler! Gebe eine Feldnummer im Zahlenbereich 0-8 ein!" << std::endl;
		std::cin >> feldnummer;
	}
		while(feld[feldnummer] != 0)
		{
			std::cout << "Feld ist bereits besetzt! Gebe eine andere Feldnummer ein." << std::endl;
			std::cin >> feldnummer;
		}
return feldnummer;	
}

int main() {
    std::vector<int> spielfeld = {{ 0,0,0,0,0,0,0,0,0 }};
    
    int eingabe_feld;
    
    std::string spieler1;
    std::string spieler2;
    
    std::cout << "Gebe den Namen von Spieler1 an: " << std::endl;
    std::cin >> spieler1;
    std::cout << "Gebe den Namen von Spieler2 an: " << std::endl;
    std::cin >> spieler2;
    
    
    while (true) 
    {
			std::cout << spieler1 << " ist drann und hat das Symbol X!" << std::endl;
			eingabe_feld = frage_feld_nummer(spielfeld);
			
			spielfeld[eingabe_feld] = 1;
			
            if(gewinnerin(spielfeld) == 1)
            {
				std::cout << spieler1 << " hat gewonnen!" << std::endl;
				gebe_feld_aus(spielfeld);
				return 0;
			}
				else if (gewinnerin(spielfeld) == 2)
				{
					std::cout << spieler2 << " hat gewonnen!" << std::endl;
					gebe_feld_aus(spielfeld);
					return 0;
				}	
					else if (gewinnerin(spielfeld) == 3)
					{
						std::cout << "Das Spiel endet unentschieden!"<< std::endl;
						gebe_feld_aus(spielfeld);
						return 0;
					}
				
			gebe_feld_aus(spielfeld);

			std::cout << spieler2 << " ist drann und hat das Symbol O!" << std::endl;
			eingabe_feld = frage_feld_nummer(spielfeld);
			
			spielfeld[eingabe_feld] = 2;
            
			if(gewinnerin(spielfeld) == 1)
            {
				std::cout << spieler1 << " hat gewonnen!" << std::endl;
				gebe_feld_aus(spielfeld);
				return 0;
			}
				else if (gewinnerin(spielfeld) == 2)
				{
					std::cout << spieler2 << " hat gewonnen!" << std::endl;
					gebe_feld_aus(spielfeld);
					return 0;
				}	
					else if (gewinnerin(spielfeld) == 3)
					{
						std::cout << "Das Spiel endet unentschieden!"<< std::endl;
						gebe_feld_aus(spielfeld);
						return 0;
					}
			gebe_feld_aus(spielfeld);
	}
return 0;
}
