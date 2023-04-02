#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int n,a[100001],rk1[100001];
double rk[100001];
int inf=1e9;
int bf(int p,double m){
    int l=-inf,r=inf,mid;
    while(l<=r){
        mid=(l+r)/2;
        double rk=1;
        for(int i=1;i<=n;i++){
            if(i==p)continue;
            rk+=1.0/(1.0+pow(10,(mid-a[i])/400.0));
        }
        if(rk>m)l=mid+1;
        else r=mid-1;
    }
    return mid;
}
signed main()
{
    //freopen("1.in","r",stdin);
    //freopen("2.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&rk1[i],&a[i]);
    }
    fill(rk+1,rk+n+1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i)continue;
            rk[i]+=1.0/(1.0+pow(10,(a[i]-a[j])/400.0));
        }
    }
    for(int i=1;i<=n;i++){
        double m=sqrt(rk1[i]*rk[i]);
        printf("%5d %5d %c%-5d %-5d\n",rk1[i],a[i],((a[i]+(bf(i,m)-a[i])/2)-a[i]>=0?'+':'-'),abs(a[i]+(bf(i,m)-a[i])/2-a[i]),a[i]+(bf(i,m)-a[i])/2);
    }
}
