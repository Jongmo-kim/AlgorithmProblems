#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int NumberOfRopes, WeightToCarryWithRopes=0,TempToPushBack;
	vector<int> Ropes;
	vector<int>::const_iterator iter;
	cin >> NumberOfRopes;
	for (int List_i = 0; List_i < NumberOfRopes; List_i++)
	{
		cin >> TempToPushBack;
		Ropes.push_back(TempToPushBack);
	}
	sort(Ropes.begin(), Ropes.end());
	iter = Ropes.begin();
	for (int List_i = NumberOfRopes; List_i >0; List_i--)
		WeightToCarryWithRopes= max(WeightToCarryWithRopes, (*iter++) * List_i);
	
	cout << WeightToCarryWithRopes;
	return 0;
}