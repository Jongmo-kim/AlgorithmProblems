#include <iostream>
#include <algorithm>
#include <vector>
/*
acmicpc.net/problem/1543
�����̴� ����θ� �̷���� � ������ �˻��ϴ� �Լ��� ������� �Ѵ�. 
�� �Լ��� � �ܾ �� �� �� �����ϴ��� ������ �Ѵ�.
 �׷���, �������� �Լ��� �ߺ��Ǿ� ���� ���� ���� ���� �Ѵ�. 
 ���� ���, ������ abababa�̰�, �׸��� ã������ ababa���, 
 �������� �� �Լ��� �� �ܾ 0������ ã�� �� �ְ�, 2�����͵� ã�� �� �ִ�. 
 �׷��� ���ÿ� �� ���� ����.

�����̴� ������ �˻��Ϸ��� �ܾ �־����� ��, 
�� �ܾ �ִ� �� �� �ߺ����� �ʰ� �����ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//�ذ� ���
�������� ã������ �ܾ ã���� �� ó�� ���� ã�´ٰ� ����.
���� �ܾ��� ���̸�ŭ�� �迭�� �������� �߶�ͼ� ���Ѵ�.
���� �´ٸ� ó�� �����ߴ� ��ġ���� �ܾ��� �迭��ŭ �����̰� ���� ���μ����� �ݺ��Ѵ�.
�׷��� ������ �����δٸ� �������� �䱸�� �ܾ�˻��� �Ϸ��Ҽ� �ְڴ�. 

//ù���� ���� ���� ����
Document �� aaaaaaaaaa
WordToFind �� a�� �����ҽ� 5�����´� �� ������ 
WordToFind == ExtractSubString ���ǹ����� ���� �Ǵµ� 
���� list_i�� 1��ŭ �������� ���� for���� ++List_i  ������ �� List_i�� 2�� �����Ѵ�.
���� ����.
�׷��� if else ���Ǻб⹮�� ����� for���� ++List_i �����ڸ� ������. 
*/
using namespace std;

int main(int argc, char** argv) {
	int WordCount = 0;
	string Document;
	getline(cin,Document);
	
	string WordToFind;
	getline(cin,WordToFind);
	string ExtractSubString;

	 
	
		for(int List_i = 0;List_i<Document.length();)
		{
			ExtractSubString = Document.substr(List_i,WordToFind.length());
		
			if(WordToFind == ExtractSubString)
			{
				++WordCount;
				List_i+=WordToFind.length(); // Word�� length ��ŭ ������������ �׸�ŭ �پ�Ѵ´� 
			} else
			{
				++List_i;
			}
		}
		cout << WordCount; 
	return 0;
}

