//
//  main.cpp
//  组合
//
//  Created by 李行之 on 2020/7/28.
//  Copyright © 2020 李行之. All rights reserved.
//


#include<bits/stdc++.h>
using namespace std;
int r,ans[100],n;
void dfs(int x){
    
    if(x>r){
        for(int i=1;i<=r;i++)
            cout<<setw(3)<<ans[i];
        cout<<endl;
        return;
    }
    for(int i=ans[x-1]+1;i<=n;i++){
        ans[x]=i;
        dfs(x+1);
    }
}
int main()
{
    cin>>n>>r;
    dfs(1);
    return 0;
}
