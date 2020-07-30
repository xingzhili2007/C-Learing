//
//  main.cpp
//  P4677 山区建小学
//
//  Created by 李行之 on 2020/7/30.
//  Copyright © 2020 李行之. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f,MAXN=520;
int dp[MAXN][MAXN];
int dis[MAXN][MAXN];//从i到j距离
int d[MAXN];
int s[MAXN][MAXN];
int n,m;
int fdM(int i,int j)
{
    int x=0;
    int mid=(i+j)/2;
    for(int k=i;k<=j;k++)
          x+=dis[k][mid];
    return x;
}
int main()
{
    cin>>m>>n;
    int i,j,x;
    for(i=2;i<=m;i++)
    {
        cin>>x;
        d[i]=d[i-1]+x;
    }
    for(i=1;i<=m;i++)
          for(j=1;j<=m;j++)
          {
              if(i==j)dis[i][j]=0;
              else dis[i][j]=dis[j][i]=abs(d[j]-d[i]);
          }
    for(i=1;i<=m;i++)
          for(j=1;j<=m;j++)
            s[i][j]=fdM(i,j);
    for(i=1;i<=m;i++)
          for(j=1;j<=m;j++)
            dp[i][j]=inf;
    for(i=1;i<=m;i++) dp[i][i]=0;
    for(i=1;i<=m;i++) dp[i][1]=s[1][i];
    for(i=2;i<=m;i++)
        for(j=2;j<=min(i,n);j++)
            for(int k=j-1;k<=i-1;k++)
                if(i!=j) dp[i][j]=min(dp[i][j],dp[k][j-1]+s[k+1][i]);
    cout<<dp[m][n]<<endl;
}
