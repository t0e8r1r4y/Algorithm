#include<bits/stdc++.h>
using namespace std;
#define prev kundol
int n, o, A, B, asum, bsum;
string s, prev; 
string print(int a){ 
    string d = "00" + to_string(a / 60); 
    string e = "00" + to_string(a % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2); 
}
int changeToInt(string a){
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}
void go(int &sum, string s){ 
    sum += (changeToInt(s) - changeToInt(prev)); 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL); 
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> o >> s; 
        if(A > B)go(asum, s);
        else if(B > A)go(bsum, s);
		o == 1 ? A++ : B++;
        prev = s; 
    } 
    if(A > B)go(asum, "48:00");
    else if(B > A)go(bsum, "48:00"); 
    cout << print(asum) << "\n"; 
    cout << print(bsum) << "\n";
}