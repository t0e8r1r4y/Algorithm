#include <bits/stdc++.h>
using namespace std;

int M, N;
string s;

map<string, int> dic;
map<int, string> dic2;

int main( void ){
    // 이 문제가 시간 초과가 발생할 수 있는 흥미로운 부분은 아래 두줄이다.
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;

    for(int i = 1; i <= M; i++ ){
        cin >> s;
        dic[s] = i;
        dic2[i] = s;
    }

    for(int i = 0; i < N; i++ ){
        cin >> s;
        if(atoi(s.c_str()) == 0){
            cout << dic[s] << "\n";
        } else {
            cout << dic2[atoi(s.c_str())] << "\n";
        }
    }

    return 0;
}

// 시간 초과 코드
// typedef pair<int, string> NODE;

// int M, N;
// string s;

// vector<NODE> dic;

// string findPoki(int num){
//     for(int i = 0; i < dic.size(); i++){
//         if(dic[i].first == num) return dic[i].second;
//     }

//     return "";
// }

// int findPokiByName(string name){
//     for(int i = 0; i < dic.size(); i++){
//         if(dic[i].second == name) return dic[i].first;
//     }

//     return 0;
// }

// int main(void) {

//     cin >> M >> N;

//     for(int i = 1; i <= M; i++ ){
//         cin >> s;
//         dic.push_back(make_pair(i,s));
//     }

//     for(int i = 0; i < N; i++){
//         cin >> s;
        
//         if(s[0] >= '0' && s[0] <= '9') {
//             cout << findPoki(stoi(s)) << "\n";
//         } else {
//             cout << findPokiByName(s) << "\n";
//         }
//     }

//     return 0;
// }