#include <iostream>
#include <vector>
#include "algorithm"
void inputVector(std::vector<int>& Objects, int& n) //вводим вектор
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> Objects[i];
	}
}
int main()
{
	int n; //кол-во записей Евлампия
	long long count = 0; //подсчёт
	bool flag = false; //флаг (показывает прочитано ли или нет)
	std::cin >> n;
	std::vector<int> ArtObjects(n);
	inputVector(ArtObjects, n); //заполянем вектор
	auto MoveIter = ArtObjects.begin(); //итератор будет по массиву последовательно двигаться
	for (int i = 1; i <= n; i++)
	{
		auto iter = std::find(begin(ArtObjects), end(ArtObjects), i); //итератор поиска 
		int diff = iter - MoveIter; //разница между двумя итераторами
		if (diff > 0) //двигаемся по буклету назад
		{
			if (flag == true) //показывает прочитана ли страница
			{
				count--;
				flag = false;
			}
			count += diff; //листаем
			MoveIter = iter; //переприсваиваем позицию двигающемуся итератору
		}
		else if (diff < 0) //если меньше нуля (то есть двигаемся по буклету назад)
		{
			count += abs(diff) + 1; //модуль перевернувшихся листьев и +1 потому что будем читать с начала страницы
			MoveIter = iter; //переприсваиваем 
		}
		count++; //Прочитка страницы буклета (соответсвенно переворот)
		flag = true; //прочитали - тру
	}
	std::cout << count;
	return 0;
}