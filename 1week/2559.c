#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[100001];
int t;


int main(void){
    int ans = -1000000;
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> t;
        arr[i] = arr[i-1] + t;
    }

    for(int i = K; i <= N; i++){
        ans = max(ans, arr[i] - arr[i-K]);
    }

    cout << ans;

    return 0;
}