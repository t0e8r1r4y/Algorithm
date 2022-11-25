#include <bits/stdc++.h>
using namespace std;

string s;

bool include(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool check(string s) {
    bool result = true;
    int cnt = 0; // 모음 연속 3개
    int cnt2 = 0;  // 자음 연속 3개
    bool isInclude = false;
    char prev = 0x20;

    for(int i = 0; i < s.length(); i++) {
        char t = s[i];

        if(include(t)) {
            cnt++;
            isInclude = true;
            cnt2 = 0;
        } else {
            cnt2++;
            cnt = 0;
        }
        // 연속 모음 혹은 자음이 3개 이상인 경우
        if(cnt >= 3 || cnt2 >= 3) {
            result = false;
            break;
        }

        // 연속 같은 문자 오면 안됨
        if( i >= 1 && (prev == t) && (t != 'e' && t != 'o') ){
            result = false;
            break;
        }

        prev = t;
    }
    if(!isInclude) result = false;
    return result;
}

int main( void ) {

    while(true){
        bool flag = false;
        // 입력
        cin >> s;
        if(s == "end") break;

        flag = check(s);

        // 판단 후 출력
        if(flag) cout << "<" << s << ">" << " is acceptable." << "\r\n";
        else cout << "<" << s << ">" << " is not acceptable." << "\r\n";
    }

    return 0;
}