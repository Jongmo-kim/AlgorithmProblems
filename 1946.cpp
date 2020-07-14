#include <iostream>
#include <vector>

using namespace std;

int Count(vector<pair<int, int>>& v)
{
	int Count = 0;
	int* Check = new int[v.size()];
	for (int List_i = 0; List_i < v.size(); List_i++)
		Check[List_i] = 0;


	for (int List_i = 0; List_i < v.size(); List_i++)
	{
		for (int Just_j = List_i + 1; Just_j < v.size(); Just_j++)
		{
			if (v[List_i].first < v[Just_j].first && v[List_i].second < v[Just_j].second)
			{
				Check[List_i] = 1;
				break;
			}
		}
	}
	for (int List_i = 0; List_i < v.size(); List_i++)
		if (Check[List_i] != 0)
			Count++;
	

	delete[] Check;
	return Count;
}
int main(void)
{
	vector<pair<int, int>> v;
	vector<int> c;
	int TestCase, NumOfParticipater, TempToPair1, TempToPair2;
	cin >> TestCase;
	for (int List_i = 0; List_i < TestCase; List_i++)
	{
		cin >> NumOfParticipater;
		for (int Just_j = 0; Just_j < NumOfParticipater; Just_j++)
		{
			cin >> TempToPair1 >> TempToPair2;
			v.push_back(make_pair(TempToPair1, TempToPair2));
		}
		c.push_back(Count(v));
		v.clear();
	}
	
	for (vector<int>::iterator iter = c.begin(); iter != c.end(); iter++)
		cout << *iter << endl;
}