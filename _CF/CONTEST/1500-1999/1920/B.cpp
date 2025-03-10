#include<iostream>
#include<algorithm>
using namespace std;
int t,n,k,x,a[400005];
bool cmp(int c,int d){return c>d;}
int main(){
    scanf("%d",&t);
    while(t--){
        int sum=0,an=0,s;
        scanf("%d%d%d",&n,&k,&x);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+n+1,cmp);
        int l=1,r=x;
        for(int i=1;i<=x;i++)an+=-2*a[i];
        s=an;
        for(;l<=k;l++,r++){
            s=s+a[l]-a[r+1<=n?r+1:0]*2;
            an=max(an,s);
        }
        printf("%d\n",sum+an);
    }
    return 0;
}