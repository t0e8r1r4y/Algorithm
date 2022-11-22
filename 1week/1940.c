#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std; 

int main(void){

    int M = 0, N = 0;
    scanf("%d", &N);
    scanf("%d", &M);

    int arr[15001] = {0, };
    int cnt = 0;

    for(int i = 0; i < N ; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++) {

            if(arr[i] + arr[j] == M) cnt++;

        }
    }

    printf("%d", cnt);

    return 0;
}