#include <bits/stdc++.h>
using namespace std;

int sum[35],sum1[35];
int m,op,x,w;
bool Output;

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            sum[x]++;
        }else{
            scanf("%d",&w);
            Output=false;
            for(int i=0;i<=31;i++) sum1[i]=sum[i]; //1.分离临时数组
            for(int i=0;i<=31;i++){                //2.从小到大枚举二进制位
                int flag=w&(1<<i);                 //3.检查当前位是否需要元素
                if(flag){
                    if(sum1[i]==0){ //需要，但是没有
                        puts("NO");
                        Output=true;
                        break;
                    }else{          //否则就用掉
                        sum1[i]--;
                    }
                }
                sum1[i+1]+=sum1[i]/2;              //4.“进位”
            }
            if(!Output) puts("YES");
        }
    }
    return 0;
}