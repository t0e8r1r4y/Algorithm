// 약간 이 문제는 외워야 되겠는데...

#include <bits/stdc++.h>
using namespace std;

int N, C;
int arr[1001];
vector<pair<int, int> > v;
map<int, int> mp, mpOrder;

bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){
		return mpOrder[a.second] < mpOrder[b.second];
	}
	return a.first > b.first;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    int orderNum = 1;

    cin >> N >> C;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        mp[arr[i]]++;
        if(mpOrder[arr[i]] == 0 ) mpOrder[arr[i]] = orderNum++;
    }

    for(auto iter : mp) {
        v.push_back(make_pair(iter.second, iter.first));
    }

    sort(v.begin(), v.end(), cmp);
	for(auto i : v){
		for(int j = 0; j < i.first; j++){
			cout << i.second << " ";
		}
	} 

    return 0;
}