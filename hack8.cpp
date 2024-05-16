#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int num;
	cin >> num;
	while(num--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		// if(s[0]=='0'){
		// 	for(int i = 1; i < n; i++){
		// 		if(s[i]=='1' && i%2==0) {cnt++;}
		// 		if(s[i]=='0' && i%2==1) {cnt++;}
 		// 	}
		// }
		// else{
		// 	for(int i = 1; i < n; i++){
		// 		if(s[i]=='1' && i%2==1) {cnt++;}
		// 		if(s[i]=='0' && i%2==0) {cnt++;}
		// 	}
		// }
        // if(cnt==n-1)
		// cout << 1 << endl;
        // else cout << cnt << endl;
        string s1, s2;
        for(int i = 0; i < n; i++){
            s1.push_back(i%2==0?'0':'1');
            s2.push_back(i%2==0?'1':'0');
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i]!=s1[i]) cnt1++;
            if(s[i]!=s2[i]) cnt2++;
        }
        cout << min(cnt1, cnt2) << endl;
	}
}
