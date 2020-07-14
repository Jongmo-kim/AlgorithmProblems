#include <iostream>

using namespace std;

int main(void)
{
	int TotalPrice, ReturnMoney,CountKindOfCoin=0;

	cin >> TotalPrice;
	ReturnMoney = 1000 - TotalPrice;

	while (1)
	{
		if (ReturnMoney >= 500)
		{
			ReturnMoney -= 500;
			CountKindOfCoin++;

		}
		else if (ReturnMoney >= 100)
		{
			ReturnMoney -= 100;
			CountKindOfCoin++;

		}
		else if (ReturnMoney >= 50)
		{
			ReturnMoney -= 50;
			CountKindOfCoin++;

		}
		else if (ReturnMoney >= 10)
		{
			ReturnMoney -= 10;
			CountKindOfCoin++;

		}
		else if (ReturnMoney >= 5)
		{
			ReturnMoney -= 5;
			CountKindOfCoin++;

		}
		else if (ReturnMoney >= 1)
		{
			ReturnMoney -= 1;
			CountKindOfCoin++;

		}

		if (ReturnMoney == 0)
		{
			cout << CountKindOfCoin;
			return 0;
		}

		
	}
}