#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std; 

int N;
int arr[1000001];
int ans[1000001];
stack<int> s;

void printStack(stack s){
    
}

int main( void ) {

    memset(ans, -1, sizeof(ans));
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        while(s.size() && arr[s.top()] < arr[i] ) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    // 시간 초과가 난다면 받으면서 바로바로 처리해야 한다.    
    // for(int i = 0; i < N; i++) {

    //     if( i == N-1){
    //         ans[i] = -1;
    //         continue;
    //     }

    //     for(int j = i; j < N; j++) {
    //         if(arr[i] < arr[j]) {
    //             ans[i] = arr[j];
    //             break;
    //         }
    //     }

    //     if(ans[i] == 0) ans[i] = -1;
    // }


    for(int i = 0; i < N; i++) {
        if( i == N-1) printf("%d", ans[i]);
        else printf("%d ", ans[i]);
    }


    return 0;
}