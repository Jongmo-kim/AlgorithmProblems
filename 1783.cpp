#include <iostream>

using namespace std;

int main(void)
{
	int row, column, count = 1;//ó��������ġ�� 1�� ����.
	cin >> column >> row;

	if (column >= 3)//���ΰ� 3���� ũ�ų� ���ٸ� �� ����Ʈ ������ ���Ʒ��� �����ϼ��ִ� �ּ�����
	{
		if (row <=4)//���ΰ� 4���� �۰ų� ���ٸ� �� ������ 4ȸ ���� ������ �϶�.
		{
			count = row;
		}
		else if (row ==5)//���ΰ�  5��� �̵�Ƚ�� �������� ���� -1
		{
			count = row - 1;
		}
		else// ���������� 2������ ����
		{
			count = row - 2;
		}
	}
	else if(column==2)//���ΰ� 3�̸��̸� ���ǿ� ���õ� �̵��� ���� 4���� ��츦 �������� ���ϹǷ� �ִ� 2�� �����ϼ�����
	{
		if (row < 3)//���ΰ� 3�̸��̶� ���������� �����ϼ�����
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
	else//���ΰ� 1�̶� �����ϼ�����.
	{
		count = 1;
	}

	cout << count;
}