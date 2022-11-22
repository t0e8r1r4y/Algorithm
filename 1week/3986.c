#include <bits/stdc++.h>
using namespace std;

int N;
string s;
int main(void){

    int ans = 0;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s;

        stack<char> st;
        for(int j = 0; j < s.length(); j++){
            if(st.empty()) st.push(s[j]);
            else {
                if( st.top() == s[j] ){
                    st.pop();
                } else {
                    st.push(s[j]);
                }
            }
        }

        if(st.empty()) ans++;
    }

    cout << ans;

    return 0;
}