//
//  main.cpp
//  素数环
//
//  Created by 李行之 on 2020/7/28.
//  Copyright © 2020 李行之. All rights reserved.
//  题记--写注释真是个好东西

#include <bits/stdc++.h>
using namespace std;
//定义
const int NoAns=-1;
int n=0,ans[55];
bool vis[55],isprime[55],isAns=false;
//输出
void print()
    {for(int i=1;i<=n;i++)printf("%d ",ans[i]);    printf("\n");}
//深搜
void dfs(int x)
{
    if(x==n+1 && isprime[ans[n]+ans[1]])
        {print();isAns=true;return;}//判断输出
    for(int i=1;i<=n;i++)
    {
        if(!vis[i] && (isprime[ans[x-1]+i] || x==1))
        {
            vis[i]=true;//打标记
            ans[x]=i;//记录
//            print(); //调试专用
            dfs(x+1);//递归
            vis[i]=false;//回溯
            
        }
    }
    
    
   
}
int main(int argc, const char * argv[]) {
    scanf("%d",&n);//输入
    memset(vis,0,sizeof vis);//初始化
    memset(isprime,0,sizeof isprime);
    //省时间精髓
    isprime[2]=isprime[3]=isprime[5]=isprime[7]=isprime[11]=isprime[13]=isprime[17]=isprime[19]=isprime[23]=isprime[29]=isprime[31]=true;//手打判断质数
    //省时间精髓
    //n(2≤n≤12) 相邻两个数最大合为 11+12=23
    //P.S 打到31是保险起见
    
    //判断并输出
    dfs(1);
    if(!isAns)
        printf("%d\n",NoAns);
    return 0;
}
