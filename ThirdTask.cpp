#include <iostream>
#include <vector>
#include "algorithm"
void inputVector(std::vector<int>& Books, int& n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> Books[i];
	}
}
int main()
{
	int n; //кол-во записей Евлампия
	std::cin >> n; //ввод
	int count = 0; //счётчик уникальных номеров
	std::vector<int> BooksNums(n);
	inputVector(BooksNums, n); //вводим массив
	std::sort(BooksNums.begin(), BooksNums.end()); //сортируем
	for (int i = 0; i < BooksNums.size(); i++) //от 0 до сайзового значения
	{
		if ((BooksNums[i] != BooksNums[i + 1]) && (i != BooksNums.size())) //если след номер другой, то он новый уникальный
		{
			count++; //значит прибавляем
		}
	}
	std::cout << count; //вывод
	return 0;
}