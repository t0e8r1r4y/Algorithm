#include <bits/stdc++.h>
using namespace std;

string s;
string result;
int cnt[26];
int main(void){

    cin >> s;
    
    // 팰린드롬 만들수 있는지?
    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'A']++;
    }

    int check = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i]%2 == 1) check++;

        if(check > 1) {
            cout << "I'm Sorry Hansoo" << "\n";
            return 0;
        }
    }

    // 팰린드롬을 만든다.
    char middle;
    for(int i = 25; i >= 0; i--){
        if(cnt[i]) {
            if(cnt[i]%2 == 1) {
                middle = char('A'+i);
                cnt[i]--;
            } 
            
            for(int j = 0; j < cnt[i]; j += 2){
                result = char('A'+i ) + result;
                result += char('A'+i );
            }
            
        }
    }

    if(middle) result.insert(result.begin() + result.size() /2, middle );

    cout << result;

    return 0;
}