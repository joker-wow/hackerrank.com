#include<cstdio>
#include<iostream>

using namespace std;

int vals[100003];
long long mem[100005];

long long mini(long long a,long long b,long long c)
{
    long long tc=a<b?a:b;
    return c<tc?c:tc;
}
long long maxi(long long a,long long b,long long c)
{
    long long tc=a>b?a:b;
    return c>tc?c:tc;
}


long long dp(int n)
{
    if(n<=0) return 0;
    if(mem[n]!=-1) return mem[n];
    long long val1=mini(dp(n-2),dp(n-3),dp(n-4))+vals[n];
    long long val2=-1,val3=-1;
    if(n-1>0)
    val2=mini(dp(n-3),dp(n-4),dp(n-5))+vals[n]+vals[n-1];
    if(n-2>0)
    val3=mini(dp(n-4),dp(n-5),dp(n-6))+vals[n]+vals[n-1]+vals[n-2];
    mem[n]=maxi(val1,val2,val3);
    return mem[n];
}

int main()
{
    //freopen("play_game.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=n;i>0;i--)
        {
            scanf("%d",&vals[i]);
            mem[i]=-1;
        }
        mem[0]=0;
        long long sol=dp(n);
        printf("%lld\n",sol);
    }
}
