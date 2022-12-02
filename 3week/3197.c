// 시간 초과 코드

#include <bits/stdc++.h> 
using namespace std;

typedef pair<int,int> POS;

int R, C;
char arr[1501][1501];
int v[1501][1501];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<POS> swan; // 백조는 딱 두마리인가?
queue<POS> ice;

bool bfs(int x, int y){
    memset(&v, 0, sizeof(v));
    bool findRes = false;
    queue<POS> q;
    q.push(make_pair(x,y));

    while(q.size()){
        POS t = q.front();
        q.pop();
        v[t.first][t.second] = 1;

        for(int i = 0; i < 4; i++) {
            int nX = t.first + dx[i];
            int nY = t.second + dy[i];

            if(nX < 0 || nX >= R || nY < 0 || nY >= C ) continue;
            if(v[nX][nY] == 1) continue;

            if(arr[nX][nY] == 'L') {
                findRes = true;
                return findRes;
            } else if(arr[nX][nY] == '.') {
                v[nX][nY] = 1;
                q.push(make_pair(nX,nY));
            }

        }
    }

    return findRes;
}

bool checkSwan(){
    POS t = swan[0];
    if( bfs(t.first, t.second) ) return true;
    return false;
}

void meltIce(){
    queue<POS> notMelt, melt;
    while(ice.size()){
        POS p = ice.front();
        ice.pop();

        int i = 0;
        for(i = 0; i < 4;i++){
            int nX = p.first + dx[i];
            int nY = p.second + dy[i];
            if(arr[nX][nY] == '.'){
                break;
            }
        }

        if(i == 4) notMelt.push(p);
        else melt.push(p);
    }

    while(melt.size()){
        POS p = melt.front();
        melt.pop();
        arr[p.first][p.second] = '.';
    }

    while(notMelt.size()){
        ice.push(notMelt.front());
        notMelt.pop();
    }
}

void printArr(){

    for(int i = 0; i< R; i++){
        for(int j = 0; j < C; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return;
}

int main(void){
    cin >> R >> C;

    for(int i = 0; i< R; i++){
        for(int j = 0; j < C; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'L') {
                swan.push_back(make_pair(i,j));
            }
            if(arr[i][j] == 'X') {
                ice.push(make_pair(i,j));
            }
        }
    }

    int cnt = 0;
    while(!checkSwan()) {
        meltIce();
        cnt++;
    }

    cout << cnt;

    return 0;
}