#include <iostream>
#include <algorithm>
#include <vector>
/*
acmicpc.net/problem/1543
세준이는 영어로만 이루어진 어떤 문서를 검색하는 함수를 만들려고 한다. 
이 함수는 어떤 단어가 총 몇 번 등장하는지 세려고 한다.
 그러나, 세준이의 함수는 중복되어 세는 것은 빼고 세야 한다. 
 예를 들어, 문서가 abababa이고, 그리고 찾으려는 ababa라면, 
 세준이의 이 함수는 이 단어를 0번부터 찾을 수 있고, 2번부터도 찾을 수 있다. 
 그러나 동시에 셀 수는 없다.

세준이는 문서와 검색하려는 단어가 주어졌을 때, 
그 단어가 최대 몇 번 중복되지 않게 등장하는지 구하는 프로그램을 작성하시오.

//해결 방안
문서에서 찾으려는 단어를 찾을때 맨 처음 부터 찾는다고 하자.
그후 단어의 길이만큼의 배열을 문서에서 잘라와서 비교한다.
만약 맞다면 처음 시작했던 위치에서 단어의 배열만큼 움직이고 이전 프로세스를 반복한다.
그렇게 끝까지 움직인다면 문제에서 요구한 단어검색을 완료할수 있겠다. 

//첫번쨰 접근 실패 이유
Document 에 aaaaaaaaaa
WordToFind 에 a를 대입할시 5가나온다 그 이유는 
WordToFind == ExtractSubString 조건문에서 참이 되는데 
그후 list_i에 1만큼 더해지고 이후 for문의 ++List_i  때문에 총 List_i가 2번 증가한다.
따라서 오답.
그래서 if else 조건분기문을 만들고 for문의 ++List_i 연산자를 지웠다. 
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
				List_i+=WordToFind.length(); // Word의 length 만큼 값을증가시켜 그만큼 뛰어넘는다 
			} else
			{
				++List_i;
			}
		}
		cout << WordCount; 
	return 0;
}

