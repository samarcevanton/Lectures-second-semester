//
//
//

#include <iostream>
#include <list>
#include <string>

namespace BackpackTask
{
	class Item
	{
		public:
			std::string name;
			double weight;
			double price;
			
		public:
			Item( std::string _name, double _weight, double _price );
	};
}

namespace BackpackTask
{
	class Backpack
	{
		private:
			std::list<Item> bestItems;
			double maxW;
			double bestPrice;
		
		private:
			// Вычисляет общий вес набора предметов
			double CalcWeight( std::list<Item> items );
			
			// Вычисляет общую стоимость набора предметов
			double CalcPrice(std::list<Item> items);
			
			// Проверка, является ли данный набор лучшим решением задачи
			void CheckSet(std::list<Item> items);
			
		public:
			Backpack( double _maxW );
			
			// Создание всех наборов перестановок значений
			void MakeAllSets(std::list<Item> items);
			
			// Возвращает решение задачи (набор предметов)
			std::list<Item> GetBestSet();
	};
}

namespace BackpackTask
{
	class SandBox
	{
		private:
			std::list<Item> items;
			
		private:
			void AddItems();
			void ShowItems( std::list<Item> _items );
			void Solve();
			
		public:
			SandBox();
	};
}

BackpackTask::Item::Item( std::string _name, double _weight, double _price )
{
	name = _name;
    weight = _weight;
    price = _price;
}

BackpackTask::Backpack::Backpack( double _maxW )
{
	maxW = _maxW;
}

// Вычисляет общий вес набора предметов
double BackpackTask::Backpack::CalcWeight( std::list<BackpackTask::Item> items )
{
	double sumW = 0;
	
	for (BackpackTask::Item i : items)
		sumW += i.weight;
	
	return sumW;
}

// Вычисляет общую стоимость набора предметов
double BackpackTask::Backpack::CalcPrice( std::list<BackpackTask::Item> items )
{
	double sumPrice = 0;
	
	for (BackpackTask::Item i : items)
		sumPrice += i.price;
	
	return sumPrice;
}

// Проверка, является ли данный набор лучшим решением задачи
void BackpackTask::Backpack::CheckSet( std::list<BackpackTask::Item> items )
{
	if ( bestItems.empty() ) {
		if ( CalcWeight(items) <= maxW ) {
			bestItems = items;
		}
	} else {
		if ( CalcWeight(items) <= maxW && CalcPrice(items) > bestPrice ) {
			bestItems = items;
			bestPrice = CalcPrice(items);
		}
	}
}

// Создание всех наборов перестановок значений
void BackpackTask::Backpack::MakeAllSets( std::list<BackpackTask::Item> items )
{
	if ( items.size() > 0 )
		CheckSet(items);
		
	for (auto iter = items.begin(); iter != items.end(); iter++) {
		std::list<BackpackTask::Item> newSet(items);
		newSet.erase(iter);
	//std::cout << "Метка n 174\n";
		MakeAllSets(newSet);
	}
}

std::list<BackpackTask::Item> BackpackTask::Backpack::GetBestSet()
{
	return bestItems;
}

BackpackTask::SandBox::SandBox()
{
	std::cout << "Шаг первый 141 конструктор SandBox" << std::endl; 
	AddItems();
	ShowItems(items);
	Solve();
}

void BackpackTask::SandBox::AddItems()
{
	items.push_back( BackpackTask::Item("Книга", 1, 600) );
	items.push_back( BackpackTask::Item("Бинокль", 2, 5000) );
	items.push_back( BackpackTask::Item("Аптечка", 4, 15000) );
	items.push_back( BackpackTask::Item("Ноутбук", 2, 40000) );
	items.push_back( BackpackTask::Item("Котелок", 1, 500) );
}

void BackpackTask::SandBox::ShowItems(std::list<BackpackTask::Item> _items)
{
	std::cout << "Содержимое, вес, ценность:" << std::endl;
	std::cout << "----------------------------\n";
	for (BackpackTask::Item i : items) {
		std::cout << i.name << " " << i.weight << " " << i.price << std::endl;
	}
	std::cout << std::endl;
}

void BackpackTask::SandBox::Solve()
{
	int maxW;
	std::cout << "Введите максимальный размер рюкзака: ";
	std::cin >> maxW;
	
	BackpackTask::Backpack bp( maxW );
	
	std::cout << "Метка 1 174\n";
	
	bp.MakeAllSets(items);
	
	std::cout << "Метка 2 178\n";
	
	std::list<BackpackTask::Item> slove = bp.GetBestSet();
	
	std::cout << "Метка 3 174\n";
	
	if( slove.empty() )
		std::cout << std::endl << "Нет решения!" << std::endl;
	else {
		ShowItems(slove);
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	
	BackpackTask::SandBox sb;
	
	std::cin.get();
	return 0;
}

/*
Содержимое, вес, ценность:
--------------------------
Книга 1 600
Бинокль 2 5000
Аптечка 4 15000
Ноутбук 2 40000
Котелок 1 500

Введите максимальный размер рюкзака: 8

Бинокль 2 5000
Аптечка 4 15000
Ноутбук 2 40000

*/
