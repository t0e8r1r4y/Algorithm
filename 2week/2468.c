#include <stdio.h>
#include<iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

typedef pair<int, int> NODE;


int N;
int map[101][101] = {{0,}, };
int v[101][101] = {{0,}, };
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int  x, y;

int chk(int x, int y){
    if( x > -1 && x < N && y > -1 && y < N) return 1;
    return 0;
}

void bfs(int x, int y){
    queue< NODE > queue;

    NODE s;
    s.first = x;
    s.second = y;
    v[x][y] = 0;
    queue.push(s);

    while(!queue.empty()){
        NODE t = queue.front();
        queue.pop();

        x = t.first;
        y = t.second;

        int nX = 0;
        int nY = 0;

        for(int i = 0; i < 4; i ++) {
            nX = x + dx[i];
            nY = y + dy[i];

            if(chk(nX, nY) && v[nX][nY] == 1){
                v[nX][nY] = 0;
                queue.push( make_pair(nX, nY) );
            }
        }

    }
}

int main(void){

    int cnt = 0;
    int h = 0, t = 0;
    int max = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++ ){
        for(int j = 0; j < N; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] > h) h = map[i][j];
        }
    }

    while(t != h) {

        for(int i = 0; i < N; i++ ){
            for(int j = 0; j < N; j++){
                if(map[i][j] > t) v[i][j] = 1;
            }
        }

        for(int i = 0; i < N; i++ ){
            for(int j = 0; j < N; j++){
                if(v[i][j] == 1) {
                    bfs(i,j);
                    ++cnt;
                }
            }
        }

        if(max < cnt) max = cnt;
        memset(v, 0, sizeof(int) * 101 * 101);

        cnt = 0;

        ++t;
    }


    printf("%d", max);

    return 0;
}