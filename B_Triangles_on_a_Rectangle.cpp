#include<bits/stdc++.h>
using namespace std;
#define lol long long int
#define nl "\n"
#define eee ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//sort(a.begin(), a.end(), greater<int>());
int const N=1000005;

lol divisors[N];



int main()
{
    eee;
    int t;
    cin>>t;
     while(t--){
        long long int w,k;
 
        cin>>w>>k;
        int x,x1;
        cin>>x;
        vector<int>a(x);
        for(int i=0;i<x;i++)cin>>a[i];
        cin>>x1;
        vector<int>b(x1);
        for(int i=0;i<x1;i++)cin>>b[i];
        int mx;
        mx=max(a[x-1]-a[0],b[x1-1]-b[0]);
 
        int y,y1;
        cin>>y;
        vector<int>c(y);
        for(int i=0;i<y;i++)cin>>c[i];
        cin>>y1;
        vector<int>d(y1);
        for(int i=0;i<y1;i++)cin>>d[i];
        int mx1;
        mx1=max( c[y-1] - c[0] , d[y1-1] - d[0] );
 
        lol ans;
        ans=(max(mx*k,mx1*w));
        cout<<ans<<nl;
 
 
    }


    return 0;

}