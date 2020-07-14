#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int countequal(string _A, string _B)
{
	int count1=100, count2=0;
	for (int List_i = 0; List_i <= _B.size()-_A.size(); List_i++)
	{
		for (int Just_j = 0; Just_j < _A.size(); Just_j++)
		{
			if (_A[Just_j] != _B[Just_j + List_i])
				count2++;
		}
		count1 = min(count1, count2);
		count2 = 0;
	}
	return count1;
}
int main(void)
{
	string A, B; 
	cin >> A;
	cin >> B;


	cout << countequal(A, B);
	return 0;
}