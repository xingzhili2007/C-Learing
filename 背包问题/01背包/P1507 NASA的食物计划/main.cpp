#include<bits/stdc++.h>
using namespace std;
int 
	MXv,//最大体积 
	MXq,//最大质量 
	N,//食品总数 
	dp[510][510];
struct FOOD
{
	int 
		v,//体积
		q,//质量
		k;//卡路里	
}food[55];
int main()
{
	
	cin>>MXv>>MXq;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>food[i].v>>food[i].q>>food[i].k;
	}
	for(int n=1;n<=N;n++)
		for(int i=MXv;i>=0;i--)
			for(int j=MXq;j>=0;j--)
			if(food[n].v<=i && food[n].q<=j)
				dp[i][j]=max(dp[i][j],dp[i-food[n].v][j-food[n].q]+food[n].k);
	cout<<dp[MXv][MXq]<<endl;
}
