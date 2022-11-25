// https://www.acmicpc.net/problem/2870

#include <bits/stdc++.h> 
using namespace std;

int N;
string s;
vector<string> q;

void convert(string s){
    while(true){
        if(s.length() && s[0] == '0') {
            s.erase(s.begin());
        } else {
            break;
        }
    }

    if(s.length() == 0) q.push_back("0");
    else q.push_back(s);
    
    return;
}

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main(void){
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s;
        string t;

        for(int j = 0; j < s.length(); j++) {
            if(s[j] >= '0' && s[j] <= '9'){
                // 숫자일 경우에
                t += s[j];
            } else {
                // 문자일 경우
                if(t.length() != 0) {
                    convert(t);
                    t = "";
                }
            }
        }

        if(t.length() != 0) {
            convert(t);
            t = "";
        }

    }

    sort(q.begin(), q.end(), cmp);

    for(int i = 0; i < q.size(); i++){
        cout << q[i] << "\n";
    }

    return 0;
}



    // for(int i = 0; i < q.size(); i++){
    //     cout << stoi(q[i]) << "\n";
    // }