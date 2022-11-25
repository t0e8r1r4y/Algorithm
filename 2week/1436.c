//https://www.acmicpc.net/problem/1436

#include <bits/stdc++.h> 
using namespace std;

int N;
int main( void ){
    cin >> N;
    string f = "666";
    int  cnt = 0;
    int result = 0;

    for(int i = 1;; i++){
        if(to_string(i).find(f) != string::npos) cnt++;
        if(cnt==N){
            result = i;
            break;
        }
    }

    cout << result;

    return 0;
}