#include <iostream>

using namespace std;
enum class Sign
{
	Plus = 0,Minus
};
int main(void)
{
	string s;
	cin >> s;

	Sign CurrentSign=Sign::Plus;
	int CurrentNumber = 0,CurrentSum=0;

	for (int List_i = 0; List_i < s.size(); List_i++)
	{
		if (s[List_i] == '+') // 부호 +를 식에서 만났을때
		{
			if (CurrentSign == Sign::Plus) 
			{								//현재 부호가 플러스면
				CurrentSum += CurrentNumber;

			}
			else
			{								//현재부호가 마이너스면
				CurrentSum -= CurrentNumber;
				//부호 변경을 하지 않음 현재 부호가 마이너스면 맨앞에 괄호를 쳤기때문에
			}
			CurrentNumber = 0;				//초기화
		}
		else if (s[List_i] == '-')  // 부호 - 를 만났을때
		{
			if (CurrentSign == Sign::Plus)
			{								//현재 부호가 플러스면
				CurrentSum += CurrentNumber;// 현재 값을 Sum에 저장
				CurrentSign = Sign::Minus;		// 마이너스로 설정
				
			}
			else
			{								// 마이너스면
				CurrentSum -= CurrentNumber;
			}
			CurrentNumber = 0; // 부호를 만났으므로 초기화
		}
		else //숫자인경우 
		{
			CurrentNumber *= 10; // 10을 곱하여 자릿수를 하나씩 올림
			CurrentNumber += static_cast<int>(s[List_i] - 48);// static_cast를 통해 char형을 int로 형변환 시키고 숫자의 아스키코드(?)에 -38을 빼면 숫자 1부터 시작된다. 아스키코드표는 38부터 숫자1이 나오는것 같다.
		}
		
	}
	if (CurrentSign == Sign::Plus) // for문이 끝날때 1번더 돌아야하는데 돌지 못하므로 따로 설정
		CurrentSum += CurrentNumber;
	else
		CurrentSum -= CurrentNumber;
	cout << CurrentSum;
	return 0;
}