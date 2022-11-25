#include <bits/stdc++.h> 
using namespace std;

int arr[101][101];
int H, W;
string s;

int main( void ){
    cin >> H >> W;

    for(int i = 0; i < H; i++){
        cin >> s;
        for(int j = 0; j < W; j++) {
            if(s[j] == '.') arr[i][j] = -1;
            else arr[i][j] = 0;
        }
    }

    for(int i = 0; i < H ; i++){
        for(int j = 0; j < W; j++){
            if(arr[i][j] == 0) {
                int cnt = 1;
                while(arr[i][j+1] == -1){
                    arr[i][j+1] = cnt++;
                    j++;
                }

            }
        }
    }

    for(int i = 0; i < H ; i++){
        for(int j = 0; j < W; j++){
            cout << arr[i][j] << " " ;
        }
        cout << "\n";
    }

    return 0;
}