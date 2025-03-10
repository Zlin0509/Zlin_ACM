#include<bits/stdc++.h>
using namespace std;
long long T,n,a,sum,num;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n),sum=num=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a),sum+=a,num+=a%2;//统计总和和奇数个数
            if(i==1) printf("%lld ",sum); //如果是第一个，直接就是答案，不需要考虑奇数
            else printf("%lld ",sum-num/3-(num%3==1));
        }
        puts("");
    }
    return 0;
}