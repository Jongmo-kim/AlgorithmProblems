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
		if (s[List_i] == '+') // ��ȣ +�� �Ŀ��� ��������
		{
			if (CurrentSign == Sign::Plus) 
			{								//���� ��ȣ�� �÷�����
				CurrentSum += CurrentNumber;

			}
			else
			{								//�����ȣ�� ���̳ʽ���
				CurrentSum -= CurrentNumber;
				//��ȣ ������ ���� ���� ���� ��ȣ�� ���̳ʽ��� �Ǿտ� ��ȣ�� �Ʊ⶧����
			}
			CurrentNumber = 0;				//�ʱ�ȭ
		}
		else if (s[List_i] == '-')  // ��ȣ - �� ��������
		{
			if (CurrentSign == Sign::Plus)
			{								//���� ��ȣ�� �÷�����
				CurrentSum += CurrentNumber;// ���� ���� Sum�� ����
				CurrentSign = Sign::Minus;		// ���̳ʽ��� ����
				
			}
			else
			{								// ���̳ʽ���
				CurrentSum -= CurrentNumber;
			}
			CurrentNumber = 0; // ��ȣ�� �������Ƿ� �ʱ�ȭ
		}
		else //�����ΰ�� 
		{
			CurrentNumber *= 10; // 10�� ���Ͽ� �ڸ����� �ϳ��� �ø�
			CurrentNumber += static_cast<int>(s[List_i] - 48);// static_cast�� ���� char���� int�� ����ȯ ��Ű�� ������ �ƽ�Ű�ڵ�(?)�� -38�� ���� ���� 1���� ���۵ȴ�. �ƽ�Ű�ڵ�ǥ�� 38���� ����1�� �����°� ����.
		}
		
	}
	if (CurrentSign == Sign::Plus) // for���� ������ 1���� ���ƾ��ϴµ� ���� ���ϹǷ� ���� ����
		CurrentSum += CurrentNumber;
	else
		CurrentSum -= CurrentNumber;
	cout << CurrentSum;
	return 0;
}