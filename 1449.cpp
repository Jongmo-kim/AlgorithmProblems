#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void)
{

	int NumOfLeak, Tape, TempToFor;
	vector<int> LeakPlace;
	cin >> NumOfLeak >> Tape;
	if (NumOfLeak == 0)
		cout << 0;
	for (int List_i = 0; List_i < NumOfLeak; List_i++)
	{
		cin >> TempToFor;
		LeakPlace.push_back(TempToFor);
	}
	sort(LeakPlace.begin(), LeakPlace.end());
	int count = 1;
	for (vector<int>::iterator iter = LeakPlace.begin(); iter != LeakPlace.end(); ++iter)
	{

		for (vector<int>::iterator iter2 = iter + 1; iter2 != LeakPlace.end(); ++iter2)
		{

			if ((*iter2 - *iter) + 1 > Tape)
			{
				count++;
				iter = iter2 - 1;//1�� ������ iter++�� �����Ƿ� 1�� ���� �����Ѵ�.
				break;
			}
		}
	}

	cout << count;
	return 0;
}