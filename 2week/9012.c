#include <bits/stdc++.h> 
using namespace std;

int N;
string s;
bool chk(string s){
    stack<char> st;
	for(char c : s){
		if(c == '(')st.push(c); 
		else{
			if(!st.empty()) st.pop(); 
			else return false; 
		}
	}

    return st.empty();
}

int main(void){

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> s;

        if(chk(s))  cout << "yes\n";
        else cout << "no\n";

    }

    return 0;
}