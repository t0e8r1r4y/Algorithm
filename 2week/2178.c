#include <stdio.h>
#include<iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef pair<int, int> NODE;

int M, N;
int map[101][101] = {0, };
int v[101][101] = { 0,};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cnt = 0;
int  x, y;

int chk(int x, int y){
    if( x > -1 && x < N && y > -1 && y < M) return 1;
    return 0;
}

void bfs(){
    queue< NODE > queue;

    NODE s;
    s.first = 0;
    s.second = 0;
    v[0][0] = 1;
    queue.push(s);

    while(!queue.empty()){
        NODE t = queue.front();
        queue.pop();

        x = t.first;
        y = t.second;
        
        if(x == N-1 && y == M-1) break;

        int nX = 0;
        int nY = 0;

        for(int i = 0; i < 4; i ++) {
            nX = x + dx[i];
            nY = y + dy[i];

            if(chk(nX, nY) && v[nX][nY] == 0 && map[nX][nY] == 1){
                v[nX][nY] = v[x][y]+1;
                queue.push( make_pair(nX, nY) );
            }
        }

    }


}

int main(void){

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    // 0,0 -> N-1. M-1
    bfs();

    printf("%d\r\n", v[N-1][M-1]);


    return 0;
}