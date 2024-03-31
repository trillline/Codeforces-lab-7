#include <iostream>
#include <vector>
#include "algorithm"
void Search(long long Element, std::vector<int>& Power, std::vector<int>& UniqumNums)
{
	if (Element == 0) //если элемент это нуль
		UniqumNums.push_back(1); //просто пушбечим рандом цифру, в моём случае 1 (главное чтоб массив был размером 1)
	while (Element != 0)
	{ //рубим элемент
		int Cifra = Element % 10; //откусываем цифру
		Element /= 10; //рубим число
		auto iter = std::find(begin(UniqumNums), end(UniqumNums), Cifra); //итератор ищет в массиве с уникальными похожие
		if (iter == end(UniqumNums) || UniqumNums.size() == 0) //если похожих нет (то есть число уникальное) и итератор смотрит в конец, то пушбечим в массив
		{ //ну или если вначале размер массива нуль то тоже пушбечим первую уникальную цифру
			UniqumNums.push_back(Cifra);
		}
	}
	Power[UniqumNums.size() - 1]++; //прибавляем к категориям по цифре уникальной (размерность массива уникальных выбирает категорию мощи)
}

void inputVector(std::vector<long long>& Numbers, int& n)
{
	for (int i = 0; i < n; i++) //заполнение массива с числами
	{
		std::cin >> Numbers[i];
	}
}
int main()
{
	int n; //кол-во цифр	
	std::cin >> n; //вводим
	std::vector<long long> Numbers(n); //массив с числами
	std::vector<int> PowerNums = { 0,0,0,0,0,0,0,0,0,0 }; //оценочный массив для вывода (здесь 10 категорий мощи)
	std::vector<int> UniqumNums; //массив для уникальных чисел
	inputVector(Numbers, n); //вводим массив с числами
	for (int i = 0; i < n; i++)
	{
		Search(Numbers[i], PowerNums, UniqumNums); //ищем в каждом из чисел уникальные цифры
		UniqumNums.clear(); //очищаем массив с уникальными цифрами
	}
	for (int i = 0; i < 10; i++)
		std::cout << PowerNums[i] << " "; //вывод значений категорий мощи
}