#include <bits/stdc++.h>
using namespace std;

int N;
string p;
string s;
string separator = "*";
int main( void ){

    cin >> N;
    cin >> p;
    int pos = 0;
    pos = p.find(separator);
    string first = p.substr(0, pos);
    string second = p.substr(pos+1);

    for(int i = 0 ; i < N; i++){
        cin >> s;
        
        if(s.size() < first.size() + second.size()) {
            cout << "NE\n";
            continue;
        }

        if( first == s.substr(0, first.length()) &&
            second == s.substr(s.length() - second.length() , s.length())
        ) {
            cout << "DA" << "\n";
        } else {
            cout << "NE" << "\n";
        }
    }

    return 0;
}