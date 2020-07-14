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
		index = distance(HowTall.begin(),iter); // ã���� ��ġ
		for (int Just_j = 0; Just_j <index; Just_j++)
		{
			if (HowTall[index] < HowTall[Just_j])//�տ��մ°����� ã�������� ũ�ٸ� 
			{
				count++;
				if (count > WhatSee[List_i-1])//������ ū����� �տ� �ִ� ��찡 �־����ͺ��� Ŀ���ٸ�
				{
					return false; // ���ǿ� ���� �����Ƿ� ����
				}	
			}
			
		}
		if (count < WhatSee[List_i - 1])//���� �۾Ƶ� �ȵ�
			return false;
		count = 0;//���������� ���� �ʱ�ȭ
	}
	//��� ������ �ٵ������Ƿ� ��������
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