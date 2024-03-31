﻿#include <iostream>
#include <vector>
#include "algorithm"
void inputArr(std::vector <int>& arr, int count, int k)
{
	int x;
	for (int i = 0; i < count; i++)
	{
		std::cin >> x;
		arr.push_back(x);
	}
}
int main()
{
	int k, n, m; //k - начальный этаж, n - данные перемещений между этажами, m - перемещение на n этажей
	int differenceStops;
	int i = 0;
	std::cin >> k >> n >> m;
	std::vector<int> ElevatorStops, StopsMovement;
	ElevatorStops.push_back(k); //перемещения между этажами // список перемещений на n этажей
	inputArr(ElevatorStops, n, k);
	inputArr(StopsMovement, m, k);
	auto iter = std::max_element(begin(StopsMovement), end(StopsMovement));
	std::vector <int> MovementNums(*iter + 1);
	std::vector <int>::iterator itMove = ElevatorStops.begin();
	while (i < n + 1)
	{
		if (i + 1 != n + 1)
		{
			differenceStops = abs(ElevatorStops[i] - ElevatorStops[i + 1]);
			if (differenceStops < MovementNums.size())
				MovementNums[differenceStops]++;
		}
		i++;
	}
	for (auto iterStops = StopsMovement.begin(); iterStops < StopsMovement.end(); iterStops++)
	{
		std::cout << MovementNums[*iterStops] << std::endl;
	}
	return 0;
}