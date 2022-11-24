#include <bits/stdc++.h>
using namespace std;  

// 문자열에서 숫자와 연산자 구분
vector<int> num; 
vector<char> op; 

// 입력
int n = 0;
string s; 

// 출력
int ret = -987654321; // 내가 틀렸던 부분

int oper(char o, int b, int c){
    if(o == '+') return b + c; 
    if(o == '-') return b - c; 
    if(o == '*') return b * c;  
    return 0;
} 

void dfs(int here, int now){

    if(here == num.size() - 1){ 
        ret = max(ret, now); 
        return;
    }  
    dfs(here + 1, oper(op[here], now, num[here + 1]));

    if(here + 2 <= num.size() - 1){
        int temp = oper(op[here + 1], num[here + 1], num[here + 2]); 
        dfs(here + 2, oper(op[here], now, temp));  
    } 
    return;
} 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   

    cin >> n;  
    cin >> s; 
    // 숫자와 연산자 분리, 아래의 경우에는 딱 맞는 수식만 주어지기 때문에 짝수 홀수 index로만 숫자와 연산자 구분이 가능함
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    } 
    
    dfs(0, num[0]);  
    cout << ret << "\n";
    return 0;
} 


    // 누적합을 기반으로 해야된다.
    // 완탐을 할때는 index를 기반으로 풀 생각을 해야된다. -> DAG라는 것이 내포되어 있다. => 방향성이 있고 사이클이 없다.
    // 숫자와 기호를 나눠서 생각해야 한다.

    // 기저 사례를 세워라  -> 끝까지 왔을 때 리턴하라.

    // 해당 문제를 나타내면 
    // 3   8   5 
    //   X   +
    // num[0] x  (num[1] + num[2])와
    // (num[0] x num[1]) + num[2]





// 0 : 3
// 1 : 11
// 2 : 77
// 3 : 68
// 4 : 136
// 4 : 59
// 3 : -22
// 4 : -44
// 2 : 59
// 3 : 50
// 4 : 100
// 4 : 41

     //  3
     //  11
     //  77 59  ( 3 8 7)
     //  68 -22 50
     //  136 59 -44 100 41