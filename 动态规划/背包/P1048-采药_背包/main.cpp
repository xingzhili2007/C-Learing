#include <bits/stdc++.h>
using namespace std;
int 
totT,//�ܹ��ܹ�������ҩ��ʱ��
totNum,//ɽ����Ĳ�ҩ����Ŀ
tme[105],//tme[i]��ʾ��ժ��i���ҩ��ʱ��
value[105],//value[i]��ʾ��i���ҩ�ļ�ֵ
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
