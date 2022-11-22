#include <stdio.h>
#include <string.h>

int main(void){

    int N = 0;
    char str[30];
    int answer[26] = {0,};
    char arr[26] = {0,};
    int index = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        memset(str,0,strlen(str));
        scanf("%s", str, sizeof(str));

        answer[str[0]-'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(answer[i] < 5) continue;

        arr[index++] = 'a' + i;
    }

    if(strlen(arr)){
        for(int i = 0; i < strlen(arr); i++){
            printf("%c", arr[i]);
        }
    } else {
        printf("%s", "PREDAJA");
    }


    return 0;
}