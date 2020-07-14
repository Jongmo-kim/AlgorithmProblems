// 백준 1969번 DNA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*문제
문제
DNA란 어떤 유전물질을 구성하는 분자이다.이 DNA는 서로 다른 4가지의 뉴클레오티드로 이루어져 있다(Adenine, Thymine, Guanine, Cytosine).우리는 어떤 DNA의 물질을 표현할 때, 이 DNA를 이루는 뉴클레오티드의 첫글자를 따서 표현한다.만약에 Thymine - Adenine - Adenine - Cytosine - Thymine - Guanine - Cytosine - Cytosine - Guanine - Adenine - Thymine로 이루어진 DNA가 있다고 하면, “TAACTGCCGAT”로 표현할 수 있다.그리고 Hamming Distance란 길이가 같은 두 DNA가 있을 때, 각 위치의 뉴클오티드 문자가 다른 것의 개수이다.만약에 “AGCAT"와 ”GGAAT"는 첫 번째 글자와 세 번째 글자가 다르므로 Hamming Distance는 2이다.

우리가 할 일은 다음과 같다.n개의 길이가 같은 DNA가 주어져 있을 때(이 DNA를 a1a2a3a4...이라고 하자) Hamming Distance의 합이 가장 작은 DNA s를 구하는 것이다.즉, s와 a1의 Hamming Distance + s와 a2의 Hamming Distance + s와 a3의 Hamming Distance ... 의 합이 최소가 된다는 의미이다.

입력
첫 줄에 DNA의 수 N과 문자열의 길이 M이 주어진다.그리고 둘째 줄부터 N + 1번째 줄까지 N개의 DNA가 주어진다.N은 1, 000보다 작거나 같은 자연수이고, M은 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 Hamming Distance의 합이 가장 작은 DNA 를 출력하고, 둘째 줄에는 그 Hamming Distance의 합을 출력하시오.그러한 DNA가 여러 개 있을 때에는 사전순으로 가장 앞서는 것을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calHammingDistance(const string& des,const string& ori)
{
    int HammingDistance = 0;
    for (int List_i = 0; List_i < des.size(); ++List_i)
        if (des[List_i] == ori[List_i])
            HammingDistance++;

    return HammingDistance;
}
int main()
{
    int NumOfDNA, STRLEN;
    cin >> NumOfDNA >> STRLEN;
    vector<string> DNAs;
    vector<int> HammingDistance;
    for (int List_i = 0; List_i < NumOfDNA; ++List_i)
    {
        string temp;
        cin >> temp;
        DNAs.push_back(temp);
    }//입력받기

    

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
