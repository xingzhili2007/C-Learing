#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int n,x,y,ans=-2147483647;
int main()
{
	cin>>n;
	x=n/2;y=n/2;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=i;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		if(i<=x){
           for(int j=1;j<=i;j++){
               a[i][j]=max(a[i-1][j]+a[i][j],a[i-1][j-1]+a[i][j]);
           }
       	}
       	else
		{
           if(i==x+1)
		   {
               a[i][y]=a[x][y]+a[i][y];
               a[i][y+1]=a[x][y]+a[i][y+1];
           }
           else
		   {
               for(int j=y;j<=i;j++)
                   a[i][j]=max(a[i-1][j]+a[i][j],a[i-1][j-1]+a[i][j]);
               
           }
       } 

	}
	for(int i=y;i<=n;++i) ans=max(ans,a[n][i]);
  	printf("%d",ans);
   	return 0;
 } 
