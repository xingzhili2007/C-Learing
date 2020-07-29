#include<bits/stdc++.h>
using namespace std;
int n,a[1002],i,j,ans,p;
int main(){
    cin >> n;
    for (i = n; i; i--)
        for (j = i; j <= n; j++)
            {
                cin >> p;
                a[j] = max(a[j], a[j + 1]) + p;
            }
    for (i = 1; i <= n; i++)
        ans=max(ans,a[i]);
    cout << ans;
    return 0;
}