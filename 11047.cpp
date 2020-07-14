#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{
	int NumberOfKindOfCoins, HowMuchWeNeedMoney, HowManyCoinAdd = 0,KindofCoin,WhatWeHaveMoney=0;
	vector<int> KindofCoins;
	vector<int>::const_iterator iter;
	cin >> NumberOfKindOfCoins >> HowMuchWeNeedMoney;

	for (int List_i = 0; List_i < NumberOfKindOfCoins; List_i++)
	{
		cin >> KindofCoin;
		KindofCoins.push_back(KindofCoin);
	}
	iter = (KindofCoins.end() - 1);
	while (1)
	{
		WhatWeHaveMoney += (*iter);
		if (WhatWeHaveMoney > HowMuchWeNeedMoney)
			WhatWeHaveMoney -= (*iter--);
		else
		{
			HowManyCoinAdd++;
		}
		if (WhatWeHaveMoney == HowMuchWeNeedMoney)
			break;
	}
	cout << HowManyCoinAdd;
	return 0;
}