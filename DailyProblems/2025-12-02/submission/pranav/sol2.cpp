#include<bits/stdc++.h>
using namespace std;
int reverse_string(string s ,int st,int end){
    int i=st;
    int j=end;
    if(i>=j)return;
    swap(s[st],s[end]);
    return reverse_string(s,st+1,end-1);
}
int main(int argc, char const *argv[])
{
    string s;
    getline(cin , s);
    int n= s.size();
    reverse_string(s,0,n-1);
    cout<<s;
    return 0;
}
