#include<bits/stdc++.h>
using namespace std;
const int MX=0x3f3f3f3f; 
int 
f[55][55][2],//f[i][j][1]��ʾ�ص�[i][j]�ĵƺ�,����վ���Ҷ˵㣨i(0)Ϊ��˵㣬j(1)Ϊ�Ҷ˵㣩
sum[55],
n,//��ʾ·�Ƶ�����
c;//��������λ�õ�·�ƺ�
struct Light
{
	int Loc,/*λ��*/  W; /*����*/
}Li[55];
inline int mn(int a,int b){return a<b?a:b;}
inline int mx(int a,int b){return a>b?a:b;}
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) 
	{cin>>Li[i].Loc>>Li[i].W;sum[i]=sum[i-1]+Li[i].W;}
	//for(int a=0;a<55;a++)for(int b=0;b<55;b++)for(int c=0;c<55;c++)f[a][b][c]=MX;
	memset(f,127,sizeof(f));
	f[c][c][0]=f[c][c][1]=0;
	for(int l=2;l<=n;l++)
		for(int i=1;i+l-1<=n;i++)
		{
			int j=i+l-1;
			f[i][j][0]=mn(f[i+1][j][0]+(Li[i+1].Loc-Li[i].Loc)*(sum[i]+sum[n]-sum[j]),f[i+1][j][1]+(Li[j].Loc-Li[i].Loc)*(sum[i]+sum[n]-sum[j]));
			f[i][j][1]=mn(f[i][j-1][0]+(Li[j].Loc-Li[i].Loc)*(sum[i-1]+sum[n]-sum[j-1]),f[i][j-1][1]+(Li[j].Loc-Li[j-1].Loc)*(sum[i-1]+sum[n]-sum[j-1]));
		}
	cout<<mn(f[1][n][0],f[1][n][1]);
}

