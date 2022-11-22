#include <stdio.h>
#include <string.h>

int main(void){

    char str[100];
    int answer[26] = {0,};
    int len = 0;

    scanf("%s", str, sizeof(str));

    len = strlen(str);

    for(int i = 0 ; i < len; i++){
        answer[str[i]-'a']++;
    }

    for(int i = 0; i < 26;i++){
        printf("%d ", answer[i]);
    }
    printf("\r\n");


    return 0;
}