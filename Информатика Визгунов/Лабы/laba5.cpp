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
			// ��������� ����� ��� ������ ���������
			double CalcWeight( std::list<Item> items );
			
			// ��������� ����� ��������� ������ ���������
			double CalcPrice(std::list<Item> items);
			
			// ��������, �������� �� ������ ����� ������ �������� ������
			void CheckSet(std::list<Item> items);
			
		public:
			Backpack( double _maxW );
			
			// �������� ���� ������� ������������ ��������
			void MakeAllSets(std::list<Item> items);
			
			// ���������� ������� ������ (����� ���������)
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

// ��������� ����� ��� ������ ���������
double BackpackTask::Backpack::CalcWeight( std::list<BackpackTask::Item> items )
{
	double sumW = 0;
	
	for (BackpackTask::Item i : items)
		sumW += i.weight;
	
	return sumW;
}

// ��������� ����� ��������� ������ ���������
double BackpackTask::Backpack::CalcPrice( std::list<BackpackTask::Item> items )
{
	double sumPrice = 0;
	
	for (BackpackTask::Item i : items)
		sumPrice += i.price;
	
	return sumPrice;
}

// ��������, �������� �� ������ ����� ������ �������� ������
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

// �������� ���� ������� ������������ ��������
void BackpackTask::Backpack::MakeAllSets( std::list<BackpackTask::Item> items )
{
	if ( items.size() > 0 )
		CheckSet(items);
		
	for (auto iter = items.begin(); iter != items.end(); iter++) {
		std::list<BackpackTask::Item> newSet(items);
		newSet.erase(iter);
	//std::cout << "����� n 174\n";
		MakeAllSets(newSet);
	}
}

std::list<BackpackTask::Item> BackpackTask::Backpack::GetBestSet()
{
	return bestItems;
}

BackpackTask::SandBox::SandBox()
{
	std::cout << "��� ������ 141 ����������� SandBox" << std::endl; 
	AddItems();
	ShowItems(items);
	Solve();
}

void BackpackTask::SandBox::AddItems()
{
	items.push_back( BackpackTask::Item("�����", 1, 600) );
	items.push_back( BackpackTask::Item("�������", 2, 5000) );
	items.push_back( BackpackTask::Item("�������", 4, 15000) );
	items.push_back( BackpackTask::Item("�������", 2, 40000) );
	items.push_back( BackpackTask::Item("�������", 1, 500) );
}

void BackpackTask::SandBox::ShowItems(std::list<BackpackTask::Item> _items)
{
	std::cout << "����������, ���, ��������:" << std::endl;
	std::cout << "----------------------------\n";
	for (BackpackTask::Item i : items) {
		std::cout << i.name << " " << i.weight << " " << i.price << std::endl;
	}
	std::cout << std::endl;
}

void BackpackTask::SandBox::Solve()
{
	int maxW;
	std::cout << "������� ������������ ������ �������: ";
	std::cin >> maxW;
	
	BackpackTask::Backpack bp( maxW );
	
	std::cout << "����� 1 174\n";
	
	bp.MakeAllSets(items);
	
	std::cout << "����� 2 178\n";
	
	std::list<BackpackTask::Item> slove = bp.GetBestSet();
	
	std::cout << "����� 3 174\n";
	
	if( slove.empty() )
		std::cout << std::endl << "��� �������!" << std::endl;
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
����������, ���, ��������:
--------------------------
����� 1 600
������� 2 5000
������� 4 15000
������� 2 40000
������� 1 500

������� ������������ ������ �������: 8

������� 2 5000
������� 4 15000
������� 2 40000

*/
