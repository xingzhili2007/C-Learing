#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int MAXN=20010;
struct peopleSave{
  int s,p,l;
  void input(){
    cin>>l>>p>>s;
  }
}a[110];
bool cmp(peopleSave a,peopleSave b){
    return a.s<b.s;
}
int dp[110][MAXN];
struct node{
    int id;
    int val;
}q[MAXN];
int main(){
    int n,k;
    int cas=0;
    while(scanf("%d%d",&n,&k)!=EOF){
        if(k==0){
            puts("0");
            continue;
        }
        int head,tail;
        for(int i=1;i<=k;i++){
            a[i].input();
            for(int j=1;j<=n;j++)
                dp[i][j]=0;
        }
        sort(a+1,a+k+1,cmp);
        for(int i=1;i<=k;i++){
            head=tail=0;
            int s=a[i].s,l=a[i].l,p=a[i].p;
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(j<s)
                    dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
            head=tail=0;
            for(int j=0;j<=n;j++){
                if(j)
                    dp[i][j]=max(dp[i][j],dp[i][j-1]);
                while(tail>head&&(q[head].id<j-l||q[head].id>=s))
                    head++;
                if(head<tail&&j>=s){
                    dp[i][j]=max(dp[i][j],q[head].val+j*p);
                }
                int x=dp[i-1][j]-j*p;
                if(j<s){
                    while(tail>head&&q[tail-1].val<x){
                        tail--;
                    }
                    q[tail].id=j;
                    q[tail++].val=x;
                }
            }
       
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[k][i]);
        }
        cout<<ans<<endl;
    }
}



