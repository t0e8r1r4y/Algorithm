#include <bits/stdc++.h> 
using namespace std;
#define prev aaa
#define next aaaa
int N, K;
int max_r = 100000;
int min_r = 0;
int v[200004];
int prev[200004];
queue<int> q;
int res = 0;

vector<int> result; 


int main( void ){

    cin >> N >> K;
    v[N] = 1;
    q.push(N);

    while(q.size()){
        int here = q.front();
        q.pop();

        if(here == K) {
            res = v[K];
            break;
        }

        int temp[] = {here + 1, here - 1, here * 2};

        for(int i = 0; i < 3; i++){
            int next = temp[i];
            if(next > max_r || next < min_r || v[next] ) continue;

            v[next] = v[here]+1;
            prev[next] = here;
            q.push(next);
        }

    }

    // 시작
    // 시작+1 시작 -1 시작*2
    cout << v[K]-1 <<  "\n";

    for(int i = K; i != N; i = prev[i]){
        result.push_back(i);
    }
    
    result.push_back(N);
    reverse(result.begin(), result.end());

    for(int i = 0; i < result.size();i ++){
        cout << result[i] << " ";
    }

    return 0;
}