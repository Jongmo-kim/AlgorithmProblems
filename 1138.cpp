#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
bool vaild(vector<int>& HowTall, vector<int>& WhatSee)
{
	vector<int>::iterator iter;
	int index = 0;
	int count = 0;

	for (int List_i = 1; List_i <= HowTall.size(); List_i++)
	{
		iter=find(HowTall.begin(), HowTall.end(), List_i);
		index = distance(HowTall.begin(),iter); // 찾은값 위치
		for (int Just_j = 0; Just_j <index; Just_j++)
		{
			if (HowTall[index] < HowTall[Just_j])//앞에잇는값들이 찾은값보다 크다면 
			{
				count++;
				if (count > WhatSee[List_i-1])//나보다 큰사람이 앞에 있는 경우가 주어진것보다 커진다면
				{
					return false; // 조건에 맞지 않으므로 거짓
				}	
			}
			
		}
		if (count < WhatSee[List_i - 1])//값이 작아도 안됨
			return false;
		count = 0;//다음루프를 위한 초기화
	}
	//모든 루프를 다돌았으므로 문제없음
	return true;

}
int main(void)
{
	vector<int> HowTall;
	vector<int> WhatSee;
	int NumOfThem;

	cin >> NumOfThem;
	for (int List_i = 1; List_i <= NumOfThem; List_i++)
		HowTall.push_back(List_i);
	int temp;
	for (int List_i = 0; List_i < NumOfThem; List_i++)
	{
		cin >> temp;
		WhatSee.push_back(temp);
	}
	
	while (1)
	{
 
		
		if (vaild(HowTall,WhatSee))
			break;
		prev_permutation(HowTall.begin(),HowTall.end());
	}
	copy(HowTall.begin(), HowTall.end(), ostream_iterator<int>(cout, " "));
	return 0;
}