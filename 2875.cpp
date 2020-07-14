#include<iostream>
using namespace std;
int CountTeam(int _Male, int _Female)
{
	if (_Male >= (_Female * 2))
		return _Female ;
	else if (_Male < (_Female * 2))
		while (1)
			if (_Male > 2 * (--_Female))
				return _Female ;
}
int main(void)
{
	int Male, Female, Intern;
	cin >> Male >> Female>> Intern;

	while (1)
	{
		if (Intern == 0)
		{
			cout << CountTeam(Male, Female);
			return 0;
		}
		if (Male >= (Female * 2))
		{
			Male--;
			Intern--;
		}
		else
		{
			Female--;
			Intern--;
		}
	}
}
