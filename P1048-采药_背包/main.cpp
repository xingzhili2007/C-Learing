#include <bits/stdc++.h>
using namespace std;
int 
totT,//总共能够用来采药的时间
totNum,//山洞里的草药的数目
tme[105],//tme[i]表示采摘第i株草药的时间
value[105],//value[i]表示第i株草药的价值
dp[105][1005]
;

int main(int argc, char *argv[])
{
	cin>>totT>>totNum;
	for(int i=1;i<=totNum;i++)
		cin>>tme[i]>>value[i];
		
	for(int i=1;i<=totNum;i++)
		for(int j=1;j<=totT;j++)
			if(j>=tme[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-tme[i]]+value[i]);
			else
				dp[i][j]=dp[i-1][j];
	
	cout<<dp[totNum][totT];
	
 } 
