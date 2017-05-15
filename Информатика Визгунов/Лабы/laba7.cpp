//
//
//

#include <iostream>
#include <ctime>
#include <cstdlib>

int getRand();
const int RAND_VALUE = 50;

class PriorityQ
{
	private:
		int maxSize;
		int *queArray;
		int nItems;
		
	public:
		PriorityQ(int s)
		{
			maxSize = s;
			queArray = new int[maxSize];
			nItems = 0;
		}
		
		~PriorityQ()
		{
			delete[] queArray;
		}
		
		//Вставка элемента
		void insert(int item)
		{	
			int j;
			if (nItems == 0)
				queArray[nItems++] = item;
			else {
				for (j = nItems - 1; j >= 0; j-- ) {
					if ( item > queArray[j] )
						queArray[j+1] = queArray[j];
					else
						break;
				}
				queArray[j+1] = item;
				nItems++;
			}
		}
		
		// Извлечение минимального элемента
		int remove()
		{	
			return queArray[--nItems];
		}
		
		// Чтение минимального элемента
		int peekMin()
		{
			return queArray[nItems-1];
		}
		
		bool isEmpty()
		{
			return ( nItems == 0 );
		}
		
		bool isFull()
		{
			return ( nItems == maxSize );
		}
};

int main(int argc, char *argv[])
{
	setlocale( LC_ALL, "Russian" );
	srand( time(nullptr) );
	
	PriorityQ thePQ(10);
	
	while ( !thePQ.isFull() ) {
		int arg = getRand();
		
		thePQ.insert( arg );
		
		std::cout << "thePQ.insert(" << arg << ");" << std::endl;
	} 
	
	std::cout << std::endl;
	
	while ( !thePQ.isEmpty() ) {
		int val = thePQ.remove();
		std::cout << val << " = thePQ.remove();" << std::endl;
	}
	
	std::cin.get();
}

int getRand()
{
	return (rand() % RAND_VALUE ) + 1;
}

/*
thePQ.insert(6);
thePQ.insert(36);
thePQ.insert(33);
thePQ.insert(18);
thePQ.insert(20);
thePQ.insert(42);
thePQ.insert(34);
thePQ.insert(21);
thePQ.insert(23);
thePQ.insert(35);

6 = thePQ.remove();
18 = thePQ.remove();
20 = thePQ.remove();
21 = thePQ.remove();
23 = thePQ.remove();
33 = thePQ.remove();
34 = thePQ.remove();
35 = thePQ.remove();
36 = thePQ.remove();
42 = thePQ.remove();
*/
