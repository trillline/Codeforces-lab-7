#include <iostream>
#include <vector>
#include "algorithm"

int main()
{
	int n, p, d; //n - кол во друзей p - сила евлампия в начале d - разность сил при которых будет расти сила евлампия
	std::cin >> n >> p >> d;
	int count = 0;
	int EvlampiPower = p;
	std::vector<int> FriendPower(n); //сила друзьяшек
	std::vector<int>::iterator iter;
	for (int i = 0; i < n; i++) //заполняем силу друзьяшек
	{
		std::cin >> FriendPower[i];
	}
	for (int i = 1; i <= d;) //здесь крч пробегаемся по диапазону нужной силы d (от p до p+d)
	{
		iter = std::find(begin(FriendPower), end(FriendPower), p + i); //если не находит 
		if (iter == end(FriendPower)) //то  итератор указывает на конец 
			i++; //и мы прибавляем шаг и ищем след число силы
		else //если находит число в этом диапазоне то прибавляем Евлампию силу
		{
			count = std::count(begin(FriendPower), end(FriendPower), p + i); //считаем сколько раз это число фигурирует
			for (int j = 1; j <= count; j++) //считаем от 1 до n раза
			{//тут две переменных чтобы сравнивать увеличенную силу и ту которую была
				if (EvlampiPower != (p + i)) //нам нельзя выйти за диапазон p+i
					EvlampiPower++;
			}
			std::vector<int>::iterator iterDelete = std::remove(begin(FriendPower), end(FriendPower), p + i); //ремуваем все похожие числа
			FriendPower.erase(iterDelete, end(FriendPower)); //и удаляем их (чтобы не мешалось)
			p = EvlampiPower; //присваиваем p фактическую силу, чтобы сравнивать дальше
			i = 1;  //откатываем шаг диапазона в начало
		}
	}
	std::cout << p; //вывод
	return 0;
}