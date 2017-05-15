//
//
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int getRand();
double getSRand();
void displayInfo( int n, double ta );

class Square
{
	private:
		double lenght;
	
	public:
		Square(double _lenght)
		{
			lenght = _lenght;
		}
		
		double getArea()
		{
			return lenght * lenght;
		}
};

const int RAND_VALUE = 50;

int main(int argc, char *argv[])
{
	setlocale( LC_ALL, "Russian" );
	srand( time(nullptr) );
	
	int n = getRand(), totalArea;
	
	std::vector<Square> squares;
	
	for ( int i = 0; i < n; ++i )
		squares.push_back( Square( getSRand() ) );
	
	for (auto i : squares)
		totalArea += i.getArea();
		
		
	displayInfo( n, totalArea );
	
	std::cin.get();
	
}

int getRand()
{
	return (rand() % RAND_VALUE ) + 1;
}

double getSRand()
{
	return getRand() + getRand() / ( RAND_VALUE + 1 ); 
}

void displayInfo( int n, double ta )
{
	std::cout << "Всего квадратов: " << n << std::endl;
	std::cout << "Покрываемая площадь равна: " << ta << std::endl;
}

/*
Всего квадратов: 19
Покрываемая площадь равна: 15701

*/
