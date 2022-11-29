#include <bits/stdc++.h> 
using namespace std;

typedef pair<int,int> NODE;

int M, N;
char arr[1001][1001];
int fireChk[1001][1001];
int v[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int x, y;
const int INF = 987654321;

bool in(int a,int b){
	return 0 <= a && a < M && 0 <= b && b < N;
}

int main(){
    queue<NODE> q;
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
    cin >> M >> N;

    fill(&fireChk[0][0], &fireChk[0][0] + 1001 * 1001, INF);

    for(int i = 0; i< M; i++){
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'J'){
                x = i;
                y = j;
            }
            if(arr[i][j] == 'F'){
                q.push(make_pair(i,j));
                fireChk[i][j] = 1;
            }
        }
    }

    // 일단 불체크 현재 1 -> 번지는 것은 1씩 증가하면서
    while(q.size()){
        NODE t = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nX = t.first + dx[i];
            int nY = t.second + dy[i];

            if(!in(nX,nY)) continue;
            if( fireChk[nX][nY] != INF ) continue;
            if(arr[nX][nY] == '#') continue;
            fireChk[nX][nY] = fireChk[t.first][t.second] + 1;
            q.push(make_pair(nX,nY));
        }
    }

    // 사람 체크
    v[x][y] = 1;
    q.push(make_pair(x,y));

    int result = 0;
    while(q.size()) {
        NODE t = q.front();
        q.pop();

        // 끝에 도달
        if( t.first == M-1 || t.first == 0 || t.second == N-1 || t.second == 0) {
            result = v[t.first][t.second];
            break; 
        }

        for(int i = 0; i < 4; i++){
            int nX = t.first + dx[i];
            int nY = t.second + dy[i];
            if(!in(nX,nY)) continue;
            if(v[nX][nY]) continue;
            if(arr[nX][nY] == '#') continue;
            if(fireChk[nX][nY] <= v[t.first][t.second] + 1) continue;

            v[nX][nY] = v[t.first][t.second] + 1;
            q.push(make_pair(nX,nY));
        }

    }

    // for(int i = 0; i < M; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    if(result != 0) cout << result << "\n";
	else cout << "IMPOSSIBLE \n";

    return 0;
}
