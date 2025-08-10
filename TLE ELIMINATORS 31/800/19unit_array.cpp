//https://codeforces.com/problemset/problem/1834/A
#include <bits/stdc++.h>
using namespace std;

void solve(){
	 int n;
	 cin>>n;
	 
	 int cnt1=0;
	 int cnt_1=0;
	 
	 for(int i=0; i<n; i++){
		 int x;
		 cin>>x;
		 if(x==1)cnt1++;
		 else cnt_1++;
	 
	 }
	 int ans=0;
	 if(cnt_1%2==1){
		 ans+=1;
		 cnt_1--;
		 cnt1++;
	 }
	 
	 while(cnt_1>cnt1){
		 cnt1+=2;
		 cnt_1-=2;
		 ans+=2;
	 }
	 cout<<ans<<endl;
}

int main()
{
	 int t;
	 cin>>t;
	 while(t--)solve();

	 return 0;
}