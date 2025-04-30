#include<bits/stdc++.h>
using namespace std;

string a,b;
void check(char a){
    if(a=='A'||a=='a'||a=='O'||a=='o'||a=='Y'||a=='y'||a=='E'||a=='e'||a=='U'||a=='u'||a=='I'||a=='i') return;
    b+='.';
    if(a>='A'&&a<='Z') b+=a+'a'-'A';
    else b+=a;
}

int main(){
    cin>>a;
    int len=a.length();
    for(int i=0;i<len;i++){
        check(a[i]);
    }
    cout<<b;
}