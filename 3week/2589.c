#include <bits/stdc++.h> 
using namespace std;

typedef pair<int,int> NODE;
int bfs(int x, int y);

int M, N;
int arr[51][51];
int v[51][51];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int result = -1;
int main(void){

    cin >> M >> N;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            char c;
            cin >> c;
            if(c == 'W') {
                arr[i][j] = 0;
                v[i][j] = 1;
            } else {
                arr[i][j] = 1;
                v[i][j] = 0;
            }
        }
    }

    // 입력 끝

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(v[i][j] == 0 && arr[i][j] == 1){
                bfs(i,j);
            }
        }
    }

    cout << result-1;

    return 0;
}

int bfs(int x, int y){
    int cnt = 0;
    queue<NODE> q;
    int visited[51][51];
    memset(visited,0,sizeof(visited));
    q.push(make_pair(x,y));
    visited[x][y] = 1;

    while(q.size()){

        NODE t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nX = t.first + dx[i];
            int nY = t.second + dy[i];

            if(nX < 0 || nX >= M || nY < 0 || nY >= N ) continue;
            if( visited[nX][nY]  ) continue;
            if( arr[nX][nY] == 0) continue;
            
            visited[nX][nY] = visited[t.first][t.second]+1;
            q.push(make_pair(nX,nY));
            result = max(result, visited[nX][nY]);
        }

    }

    return cnt;
}

