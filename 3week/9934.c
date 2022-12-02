#include <bits/stdc++.h> 
using namespace std;

int K;
int arr[1025];
vector<int> q;
int main(void){
    cin >> K;

    int numCnt = ((int)pow(2,K)-1);;

    for(int i = 1; i <= numCnt; i++){
        cin >> arr[i];
    }

    // 입력 완료

    int n = (numCnt/2) + 1;
    int d = 1;

    while(true){
        for(int i = 0; i < n; i++){
            int t = (numCnt+1) - (d + (i*(2*d)));
            q.push_back(t);
        }

        if(d == ((numCnt/2) + 1)) break;

        n /= 2;
        d *= 2;
    }

    reverse(q.begin(), q.end());

    int idx = 0;
    d = 1;
    for(int i = 1; i <= K; i++){
        for(int j = 0; j < d; j++ ){
            cout << arr[q[idx++]] << " ";
        }
        cout << "\n";
        d *= 2;
    }
    

    return 0;
}

//           3
//    6             2
//  1    4       5     7
// 3 9 11 21   13 14 15 16

// (전체 숫자의 개수 / 2) + 1  => 8번쨰
//          8번째
//    4번째       12번째
// 2번째 6번째   10번째  14번째
// 1,3  5,7

// 1 + 2 + 2^2 = 7

// 1 3 5 7
//  2   6
//    4