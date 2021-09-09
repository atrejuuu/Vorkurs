#include <iostream>
#include <vector>

std::vector<int> vectorcheck(std::vector<int> x, int y)
{
	int i=0;
	while(i < x.size())
	{
		if(x[i] == y)
		{
			i=i+1;
			continue;
		} 
		else if(x[i] == 0)
		{
			i=i+1;
			continue;
		}else{
				if(x[i]%y == 0)
				{
				x[i] = 0;
				i=i+1;
				}else{
						i=i+1;
					 }	
			 }
	}
return x;
}

int main ( int argc, char** argv )
{
	std::vector<int> vec_zahlen;
	int zahlen;
	int i=2;
	std::cout << "Gebe an wie viele Zahlen nach Primzahlen überprüft werden sollen: " << std::endl;
	std::cin >> zahlen;
	
	while(i <= zahlen)
	{
		vec_zahlen.push_back(i);
		i = i+1;
	}
	
	i=2;
	
	while(i <= zahlen)
	{
		vec_zahlen = vectorcheck(vec_zahlen,i);
		i=i+1;
	}
	
	for (int entry : vec_zahlen)
	std::cout << entry << std::endl;
}
