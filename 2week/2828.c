// https://www.acmicpc.net/problem/2828 규칙 찾기 같은 부분

#include <bits/stdc++.h>
using namespace std;

int M, N, J;
int main( void ){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int result = 0;

    cin >> N >> M;
    cin >> J;
    // M 바구니 크기
    // N 스크린 크기
    int s = 1;
    int e = M;
    for(int i = 0; i < J; i++){
        int temp;
        cin >> temp;

        if(temp < s){
            result += (s-temp);
            s = temp;
            e = s + M -1; 
        } else if(temp > e) {
            result += (temp - e);
            s = s + (temp - e);
            e = temp;
        } else if( temp >= s && temp <= e) {
            // 움직이지 않음
        }
    }


    cout << result;


    return 0;
}