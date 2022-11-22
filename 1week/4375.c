#include <bits/stdc++.h> 
using namespace std;

// 이렇게 풀면 overflow가 발생한다.
// int는 21억인데 금방 넘어감
long long makeNum(int index){
    long long num = 0;

    for(int i = 0; i < index; i++){
        num = num*10 + 1;
    }

    return num;
}


int n;
int main(){ 
	while(scanf("%d", &n) != EOF){
		int cnt = 1, ret = 1; 
		while(true){
			if(cnt % n == 0){
				cout << ret << "\n";
				break;
			}else{
				cnt = (cnt * 10) + 1; 
				cnt %= n; 
				ret++;
			}
		} 
	}  
	return 0;
}