#include <iostream>

using namespace std;

void REVERSE(int y, int x, int** p)
{
	for(int List_i=y;List_i<y+3;List_i++)
		for (int Just_j = x; Just_j < x+3; Just_j++)
		{
			
				p[List_i][Just_j] = 1- p[List_i][Just_j];
		}
}
int main(void)
{
	string s;
	int x, y;
	cin >> y >> x;
	/*
		if (x < 3 || y < 3)
	{
		cout << -1;
		return 0;
	}
	 이코드 떄문에 1시간넘게 오류찾음 후 너넨 생각없이 코딩하지마라 뒤진다.*/
	int** p = new int* [y];
	for (int List_i = 0; List_i < y; List_i++)
		p[List_i] = new int[x];
	int** _p = new int* [y];
	for (int List_i = 0; List_i < y; List_i++)
		_p[List_i] = new int[x];

	int** c = new int* [y];
	for (int List_i = 0; List_i < y; List_i++)
		c[List_i] = new int[x];

	for (int List_i = 0; List_i < y; List_i++)
	{
		cin >> s;
		for (int Just_j = 0; Just_j < x; Just_j++)
		{
			p[List_i][Just_j] = s[Just_j];
		}
	
	}
	for (int List_i = 0; List_i < y; List_i++)
	{
		cin >> s;
		for (int Just_j = 0; Just_j < x; Just_j++)
		{
			_p[List_i][Just_j] = s[Just_j];
			if (_p[List_i][Just_j] == p[List_i][Just_j])
				c[List_i][Just_j] = 1;
			else
				c[List_i][Just_j] = 0;
		}

	}
	int count = 0;
	for (int List_i = 0; List_i < y - 2; List_i++)
	{
		for (int Just_j = 0; Just_j < x - 2; Just_j++)
		{
			if (c[List_i][Just_j] == 0)
			{
				count++;
				REVERSE(List_i, Just_j, c);
			}
		}
	
	}

	for (int List_i = 0; List_i < y ; List_i++)
	{
		for (int Just_j = 0; Just_j < x; Just_j++)
		{
			if (c[List_i][Just_j] != 1)
			{
				cout <<-1;
				return 0;
			}
		}

	}

	cout << count;
	return 0;

}