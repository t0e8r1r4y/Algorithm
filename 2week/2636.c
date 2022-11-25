#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> p;
int M, N;
int arr[101][101];
int v[101][101];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int t;

queue<p> del;

void bfs(int x, int y){
    queue< p > q;
    q.push(make_pair(x,y));
    v[x][y] = 1;

    while(q.size()){
        p temp = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++){
            int nX = temp.first + dx[i];
            int nY = temp.second + dy[i];

            if(nX < 0 || nX > M || nY < 0 || nY > N) continue;

            if(v[nX][nY] == 0 && arr[nX][nY] == 0) {
                v[nX][nY] = 1;
                q.push(make_pair(nX, nY));
            } else if(v[nX][nY] == 0 && arr[nX][nY] == 1) {
                del.push(make_pair(nX,nY));
                v[nX][nY] = 1;
            }
        }
    }
}

void printArr(){
    cout << "+++++++++++++++++++++++++++++\n";
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= N; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "+++++++++++++++++++++++++++++\n";
}


int main(void) {

    cin >> M >> N;
    t = M*N;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0) t--;
        }
    }

    int res = 0;
    int before = 0;
    while(t != 0){
        memset(v, 0, sizeof(v));
        bfs(0,0); // 순회해서 치즈 겉에 확인
        before = del.size();
        while(del.size()){
            p tmp = del.front();
            del.pop();
            arr[tmp.first][tmp.second] = 0;
            v[tmp.first][tmp.second] = 0;
            t--;
        }
        res++;
    }


    cout << res << "\n";
    cout << before << "\n";


    return 0;
}