#include <stdio.h>

int main(void){

    int A, B, C;
    int answer[100] = {0, };
    int sum = 0;

    scanf("%d %d %d", &A, &B, &C);

    for(int i = 0; i < 3; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        for(int j = x-1; j < y-1; j++){
            answer[j]++;
        }
    }

    for(int i = 0; i < 100; i++) {
        if(answer[i] == 1) {
            sum += A;
        } else if(answer[i] == 2) {
            sum += B*2;
        } else if(answer[i] == 3) {
            sum += C*3;
        }
    }

    printf("%d", sum);

    return 0;
}