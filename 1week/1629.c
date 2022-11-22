#include <bits/stdc++.h> 
using namespace std;


typedef long long ll;

ll a, b, c;

ll next(ll a, ll b){
    if(b == 1) return a %c;

    ll ret = next(a, b/2);
    ret = (ret * ret) %c;
    if(b%2) ret = (ret * a)%c; // 홀수일때 한번더

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  
    cin >> a >> b >> c;
    cout << next(a,b) << "\n";
    return 0;
}

// 아래 코드는 시간 초과가 발생한다.
// int main(void){

//     int A, B, C;

//     cin >> A >> B >> C;

//     long long result = 1;

//     // 최대 범위를 고려했을 때 아래처럼 생각하면 절대 안된다.
//     // 재귀적으로 계산해야 된다.
//     for(int i = 0; i < B; i++){
//         result = result * A;
//         result %= C;
//     }

//     cout << result;

//     return 0;
// }