#include<cstdio>
#include<iostream>

#define MAX 100000000
using namespace std;
int mem[1005];
int vals[10004];
int coins[3]={1,2,5};
int main()
{
    freopen("Equal.txt","r",stdin);
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=1000;i++)
    {
        mem[i]=MAX;
        for(int j=0;j<3;j++)
        {
            if(i-coins[j]>=0 && mem[i-coins[j]]+1 < mem[i])
            {
                mem[i]=mem[i-coins[j]]+1;
            }
        }
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int min=MAX;
        for(int i=0;i<n;i++)
        {
            cin>>vals[i];
            if(min>vals[i])
            {
                min=vals[i];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=mem[vals[i]-min];
        }
        cout<<ans<<endl;
    }
}
