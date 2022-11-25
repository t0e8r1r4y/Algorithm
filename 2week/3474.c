#include <bits/stdc++.h>
using namespace std;

int T, N;
int main( void ) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;

        // N!의 끝자리 0은 결국 2, 5 두개의 곱으로 구하는 부분임 
        int two =0;
        for(int j = 2; j <= N; j *=2) {
            two += N/j;
        }

        int five =0;
        for(int j = 5; j <= N; j *=5) {
            five += N/j;
        }

        cout  << min(two, five) << "\n";
    }

    return 0;
}