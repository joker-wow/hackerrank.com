#include<cstdio>
#include<iostream>

using namespace std;

long long mem[3010][3010];
long long nums[3010];

long long maxi(long long a, long long b)
{
    if(a>b)return a;
    return b;
}

int main()
{
    freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        mem[i][i]=0;
    }
    for(int len=1;len<n;len++)
    {
        for(int i=0;i<n-len;i++)
        {

            int j=i+len;

            if(i+1<=j-1)
            {
                mem[i][j]=maxi(mem[i+1][j-1]+nums[i]*nums[j],nums[i]*nums[j]);
            }
            else
            {
                mem[i][j]= nums[i]*nums[j];
            }
            if(mem[i][j]<0)
            {
                mem[i][j]=0;
            }
            //cout<<i<<" to "<<j<<" "<<mem[i][j]<<endl;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mem[i][j]>ans)
            {
                ans=mem[i][j];
            }
        }
    }
    cout<<ans<<endl;
}
