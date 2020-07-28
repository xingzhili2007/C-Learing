//
//  main.cpp
//  P1273 有线电视网
//
//  Created by 李行之 on 2020/7/26.
//  Copyright © 2020 李行之. All rights reserved.
//


#include <bits/stdc++.h>
using namespace std;
const int MAXN=3010;
int n,m,cnt=0;
int dp[MAXN][MAXN],val[MAXN],a[MAXN],t[MAXN];
struct Edge{
    int to,w,next;
}e[MAXN*MAXN];
void add(int u,int v,int w);
int dfs(int u);


int main(){
    //输入
    cin>>n>>m;
    for (int u=1;u<=n-m;u++){
        int size;
        cin>>size;
        for (int j=1;j<=size;j++){
            int v,w;
            cin>>v>>w;
            add(u,v,w);
        }
    }
    for (int i=n-m+1;i<=n;i++)
    cin>>val[i];
    //初始化
    memset(dp,~0x3f3f3f3f,sizeof(dp));
    for (int i=1;i<=n;i++)
        dp[i][0]=0;
    //计算
    dfs(1);
    //输出
    for (int i=m;i>0;i--)
        if (dp[1][i]>=0){
            cout<<i<<endl;
            break;
        }
    return 0;
}
 
int dfs(int u){
    if (u>n-m){
        dp[u][1]=val[u];
        return 1;
    }
    int ans=0;
    for (int p=a[u];p;p=e[p].next){
        int v=e[p].to;
        int tk=dfs(v);
        for (int j=0;j<=ans;j++)t[j]=dp[u][j];
        for (int j=0;j<=ans;j++)
            for (int k=0;k<=tk;k++)
                dp[u][j+k]=max(dp[u][j+k],t[j]+dp[v][k]-e[p].w);
        ans+=tk;
    }
    return ans;
}

void add(int u,int v,int w){
    int p=++cnt;
    e[p].to=v;e[p].w=w;e[p].next=a[u];
    a[u]=p;
}
