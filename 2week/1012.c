#include <stdio.h>
#include<iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;

typedef pair<int, int> NODE;

int T;


int M, N, K;
int map[51][51] = {{0,}, };
int v[51][51] = {{0,}, };
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cnt = 0;
int  x, y;

int chk(int x, int y){
    if( x > -1 && x < N && y > -1 && y < M) return 1;
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
        
        if(x == N-1 && y == M-1) break;

        int nX = 0;
        int nY = 0;

        for(int i = 0; i < 4; i ++) {
            nX = x + dx[i];
            nY = y + dy[i];

            if(chk(nX, nY) && v[nX][nY] == 1 && map[nX][nY] == 1){
                v[nX][nY] = 0;
                queue.push( make_pair(nX, nY) );
            }
        }

    }
}

int main(void){

    queue<int> q;
    scanf("%d", &T);

    while(T!=0){
        scanf("%d %d %d", &N, &M, &K);

        for(int i = 0; i < K; i++){
            int x = 0;
            int y = 0;

            scanf("%d %d", &x,&y);

            map[x][y] = 1;
            v[x][y] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++){
                if(map[i][j] == 1 && v[i][j] == 1) {
                    bfs(i,j);
                    ++cnt;
                }
            }
        }

        q.push(cnt);
        T--;

        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(v, 0, sizeof(v));
        
    }

    while(!q.empty()){

        if(q.size() > 1) {
            printf("%d\r\n", q.front());
        } else if( q.size() == 1){
            printf("%d", q.front());
        }
        q.pop();
    }

    return 0;
}