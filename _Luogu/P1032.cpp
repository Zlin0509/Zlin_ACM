#include <bits/stdc++.h>
using namespace std;

int cnt=0,num=0;
string s1, s2;
string before[7]{}, after[7]{};
int Next[7][22]{};
map<string, int> used;

inline void  GetNext(string x,int q)
{
    int len = x.length();
    int j = 0;
    int k = -1;
    Next[q][0] = -1;
    while(j<len-1)
    {
        if(k==-1||x[j]==x[k])
        {
            ++k;
            ++j;
            if(x[k]!=x[j])
                Next[q][j] = k;
            else
                Next[q][j] = Next[q][k];
        }
        else
        {
            k = Next[q][k];
        }
    }
}

inline string Kmp(string a,int q)
{
    int alen = a.length();
    int blen = before[q].length();
    int i = 0;
    int j = 0;
    while(i<alen&&j<blen)
    {
        if(a[i]==before[q][i])
        {
            ++i;
            ++j;
        }
        else
        {
            j = Next[q][j];
        }
    }
    if(j==blen)
    {
        string ans;
        ans = a.substr(0, i - j + 1);
        ans += after[q];
        ans += a.substr(i,alen-i);
        cout << ans << '\n';
        return ans;
    }
    return "-1";
}

queue<string> s;

inline void bfs()
{
    if(num>10||s.empty())
    {
        cout << "NO ANSWER!" << '\n';
        return;
    }
    ++num;
    queue<string> x;
    string z,ans;
    while(!s.empty())
    {
        z = s.front();
        s.pop();
        if(used[z]!=0)
            continue;
        ++used[z];
        for (int i = 0; i < cnt;i++)
        {
            ans = Kmp(z, i);
            if(ans!="-1")
            {
                if (ans == s1)
                {
                    cout << num << '\n';
                    return;
                }
                x.push(ans);
            }
        }
    }
    s = x;
    bfs();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;
    string a, b;
    while (cin >> a >> b)
    {
        before[cnt] = a;
        after[cnt] = b;
        ++cnt;
    }
    for (int i = 0; i < cnt;i++)
        GetNext(before[i], i);
    s.push(s1);
    bfs();
}