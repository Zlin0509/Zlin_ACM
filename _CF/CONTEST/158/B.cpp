#include<bits/stdc++.h>
using namespace std;
int sum[5];
int main(){
    int a, n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a;
        sum[a] ++;
    }
    ans += sum[4];
    if(sum[1] <= sum[3]){
        ans = ans + sum[3];
        ans = ans + ceil(1.0 * sum[2] / 2);
    }
    else{
        ans += sum[3];
        sum[1] -= sum[3];
        ans += sum[2] / 2;
        sum[2] %= 2;
        if(sum[2]) ans ++ , sum[1] -= 2;
        if(sum[1] > 0) ans += ceil(1.0 * sum[1] / 4);
    }
    cout << ans;
    return 0;
}