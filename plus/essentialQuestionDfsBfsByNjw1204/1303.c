#include <bits/stdc++.h>
using namespace std;


int N, M;
char arr[101][101];
int v[101][101];
int W, B;

int dx[4]  = {1,-1,0,0};
int dy[4]  = {0,0,1,-1};

typedef pair<int, int> p;

int bfs(int x, int y){
    int res = 1;
    char c = arr[x][y];

    queue<p> q;
    q.push(make_pair(x,y));
    v[x][y] = 1;
    
    while(!q.empty()){
        p temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nX = dx[i] + temp.first;
            int nY = dy[i] + temp.second;

            if(nX < 0 || nY < 0 || nX >= M || nY >= N) continue;
            if(v[nX][nY] == 1) continue;
            if(arr[nX][nY] != c) continue;

            q.push(make_pair(nX,nY));
            v[nX][nY] = 1;
            res++;
        }

    }

    return res*res;
}

int main(void) {

    cin >> N >> M;

    for(int i = 0; i< M; i++){
        cin >> arr[i];
    }

    // 입력 완료
    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++) {
            if(v[i][j] == 0) {
                // 방문안한 경우에만 진행
                if(arr[i][j] == 'W') W += bfs(i,j);
                else if(arr[i][j] == 'B') B += bfs(i,j);
            }
        }
    }

    cout << W << " " << B;


    return 0;
}