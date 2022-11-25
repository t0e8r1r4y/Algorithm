#include <bits/stdc++.h> 
using namespace std;

int N, M;
int arr[100001];
int result[100001];
int cnt = 0;

void dfs(int i){
    if(arr[i] == 0) return;
    cnt++;
    dfs(arr[i]);
}

int main( void ){
    int max = -1;
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        arr[y] = x;
    }

    for(int i = 1; i <= N; i++){
        if( arr[i] != i) {
            dfs(i);
            if(max < cnt) max = cnt;
            result[i] = cnt;
        }
        cnt  = 0;
    }

    for(int i = 1; i <= N; i++){
        if(result[i] == max) {
            cout << i << " ";
        }
    }

    return 0;
}