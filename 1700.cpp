#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool IsAllPluged(int* Multitap,int MultitapSize)
{
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
	{
		if (Multitap[List_i] == 0)//���� �μ����ϳ��� 0�̶�� �� �������� �ʴٸ�
			return false;
	}
	return true;//������ �ٵ��� �����ִ°� �����Ƿ� 
}
int FindUsingPlug(int* Multitap, int FindNum, int MultitapSize)
{

}
int FindLastUsedPlug(int* Multitap, const vector<int>& Order,int first,int MultitapSize)
{
	int LastUsedIndex=0;//�÷����� �ΰ��̻��� �Ⱦ��� ��츦 ���� ���� �ۿ��� ����
	bool* ptr = new bool[MultitapSize];
	for (int List_i = 0; List_i < MultitapSize; ++List_i)
		ptr[List_i] = false;//���� ����ϴ°��� true�� ����� ���� ���߿� ����ϴ°� false�� ����� ���� false�� �ʱ�ȭ
	for (int List_i = first + 1; List_i < MultitapSize; ++List_i)//first+1���� �˻�����
	{
		int index=FindUsingPlug(Multitap, Order[List_i], MultitapSize);
		ptr[index] = true;
		LastUsedIndex = -1;// ���ܻ�Ȳ Ȯ���� ���� -1�� �ʱ�ȭ
		int count=0;
		for (int Just_j = 0; Just_j < MultitapSize; ++Just_j)//bool �迭�� 1���̻��� false�� �ִ��� Ȯ���ϴ� ����
		{
			if (ptr[Just_j] == false)
			{
				LastUsedIndex = Just_j;
				if (count++ == 2)//2���̻��� false�� ������ ���� ��ã�����Ƿ� ���� ����
					break;
			}
		}
		if (count == 1)//count�� 1�� ���� Just������ ����Ǿ��ٸ� �̴� 1���� ������ false�̰� �̴� ���� ���߿� ���Ǵ°� �ǹ��ϹǷ�
		{
			delete[] ptr; //�����Ҵ�� �޸� �ʱ�ȭ
			return LastUsedIndex;
		}
	}
	//���� ���� �������� �Լ��� ���ϵ��� �ʾҴٸ� �������� 2���̻��� �÷��׿��� �Ⱦ��δٴ� ��Ⱑ �ȴ�  �׷��Ƿ� 
	//LastUsedIndex�� �����Ѵ�. �׾��� ������ �������. ������ 2���̻��� �÷��׿��� �Ⱦ��̹Ƿ� 
	delete[] ptr; //�����Ҵ�� �޸� �ʱ�ȭ
	return LastUsedIndex;
}

void PlugCurrentNum(int* Multitap, int CurrentNum, int MultitapSize)
{

}
int main(void)
{
	int NumofHoles, FrequencyOfUse;
	vector<int> OrderOfUse;
	cin >> NumofHoles >> FrequencyOfUse;
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		int TempToPush;
		cin >> TempToPush;
		OrderOfUse.push_back(TempToPush);
	}//�������� ������ �Է� �ޱ�
	//��Ƽ�� ����
	int* Multitap = new int[NumofHoles];
	for (int List_i = 0; List_i < NumofHoles; List_i++)
		Multitap[List_i] = 0;//0(�������� ����)���� �ʱ�ȭ

	//Ǯ�� ����
	int PlugCount = 0;//�÷��׸� ���� Ƚ��
	for (int List_i = 0; List_i < FrequencyOfUse; ++List_i)
	{
		if (FindUsingPlug(Multitap,OrderOfUse[List_i],NumofHoles))//���� �������� ��ȣ�� �÷��׿� �����ִ� ���¸�
		{
			continue;//������ ������ �̵� 
		}//�� �ƴϰ�
		else if (IsAllPluged(Multitap,NumofHoles))//��� �÷��װ� �����ִٸ�
		{
			int LastUsedPlug=FindLastUsedPlug(Multitap, OrderOfUse, List_i,NumofHoles);//���� ���߿� ���̴� �÷��� ã��.
			Multitap[LastUsedPlug] = OrderOfUse[List_i];//���� ���߿� ���̴� �÷��׸� �̰� ���� �� �÷��׸� �ȴ´�.
			++PlugCount; //�÷��׸� �̾����Ƿ� ī��Ʈ ����
		}
		else // �÷��װ� �� Ȥ�� �� �����ְ� ���� �������� ��ȣ�� �÷��׿� �������� �ʴٸ�
		{
			PlugCurrentNum(Multitap, OrderOfUse[List_i], NumofHoles);//�÷��׸� �ȴ´�.
		}
	} 
	//��� ����
	cout << PlugCount;

	//���α׷� ���ᱸ��
	delete[] Multitap;
	return 0;
}