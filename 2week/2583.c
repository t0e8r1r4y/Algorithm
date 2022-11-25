#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string.h>
#include <vector>
using namespace std;

typedef pair<int, int> NODE;


int M,N,K;
int map[101][101];
int v[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int  x, y;

int chk(int x, int y){
    if( x > -1 && x < M && y > -1 && y < N) return 1;
    return 0;
}

int bfs(int x, int y){
    queue< NODE > queue;
    int cnt = 0;

    NODE s;
    s.first = x;
    s.second = y;
    v[x][y] = 1;
    queue.push(s);
    

    while(!queue.empty()){
        NODE t = queue.front();
        queue.pop();
        cnt++;
        
        x = t.first;
        y = t.second;

        int nX = 0;
        int nY = 0;

        for(int i = 0; i < 4; i ++) {
            nX = x + dx[i];
            nY = y + dy[i];

            if(chk(nX, nY) && v[nX][nY] == 0 && map[nX][nY] == 0){
                v[nX][nY] = 1;
                queue.push( make_pair(nX, nY) );
            }
        }

    }

    return cnt;
}

int main(void){
    vector< int > q;
    int cnt = 0;

    scanf("%d %d %d", &M, &N, &K);

    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int j = y1; j < y2; j++) {
            for(int k = x1; k < x2; k++) { 
                map[j][k] = 1;
                v[j][k] = 1;
            }
        }
    }

    for(int i =  0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(v[i][j] == 0) {
                q.push_back(bfs(i,j));
                cnt++;
            }
        }
    }

    sort(q.begin(), q.end());

    printf("%d\n", cnt);
    for(int i = 0; i < q.size(); i++){
        if(i == q.size()-1 ) printf("%d", q[i]);
        else printf("%d ", q[i]);
    }

    return 0;
}


    // printf("%d\r\n", cnt);
    // while(!q.empty()){
    //     printf("%d ", q.front());
    //     q.pop();
    // }
    // printf("\r\n");

    // for(int i =  0; i < M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         printf("%d ", v[i][j]);
    //     }
    //     printf("\r\n");
    // }

    // printf("\r\n");

    // for(int i =  0; i < M; i++) {
    //     for(int j = 0; j < N; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\r\n");
    // }