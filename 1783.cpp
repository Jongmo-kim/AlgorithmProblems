#include <iostream>

using namespace std;

int main(void)
{
	int row, column, count = 1;//처음시작위치도 1로 포함.
	cin >> column >> row;

	if (column >= 3)//세로가 3보다 크거나 같다면 즉 나이트 조건중 위아래로 움직일수있는 최소조건
	{
		if (row <=4)//가로가 4보다 작거나 같다면 즉 조건중 4회 이하 움직임 일때.
		{
			count = row;
		}
		else if (row ==5)//가로가  5라면 이동횟수 제한으로 인해 -1
		{
			count = row - 1;
		}
		else// 나머지경우는 2를뺴면 성립
		{
			count = row - 2;
		}
	}
	else if(column==2)//세로가 3미만이면 조건에 제시된 이동에 관한 4가지 경우를 충족하지 못하므로 최대 2번 움직일수있음
	{
		if (row < 3)//가로가 3미만이라 오른쪽으로 움직일수있음
			count = 1;
		else if (row <=4)
		{
			count = 2;
		}
		else if (row <= 6)
		{
			count = 3;
		}
		else
		{
			count = 4;
		}
			
	}
	else//세로가 1이라 움직일수없음.
	{
		count = 1;
	}

	cout << count;
}