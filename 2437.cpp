#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int numofSW;
	vector<int> scaleweights;
	cin >> numofSW;

	for (int List_i = 0; List_i < numofSW; List_i++)
	{
		int temp;
		cin >> temp;
		scaleweights.push_back(temp);
	}
	sort(scaleweights.begin(), scaleweights.end());
	int Sum=0;
	if (*scaleweights.begin() != 1)
	{
		cout << 1;
	}
	else
	{
		for (vector<int>::iterator iter = scaleweights.begin(); iter != scaleweights.end(); iter++)
		{
			if (Sum + 1 < *iter)//�������� ���� ������ Ŀ���ٸ� 
			{
				break;
			}
			else
				Sum += *iter;
		}
		cout << Sum + 1;
	}
	return 0;
}