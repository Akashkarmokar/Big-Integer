// Optimization:
// We can avoid the first two string reverse operations 
// by traversing them from end. Below is optimized solution

#include<bits/stdc++.h>
using namespace std;

string add(string s1,string s2)
{
    if(s1.length()>s2.length())
        swap(s1,s2);
    int n1=s1.length();
    int n2=s2.length();
    string str="";
    int dif = n2 - n1;
    int carry = 0 ;
    for(int i = n1-1;i>=0;i--)
    {
        int sum = (s1[i]-'0')+(s2[i+dif]-'0')+carry;
        str.push_back(sum%10+'0');
        carry = sum/10;
    }
    for(int i = dif-1;i>=0;i--)
    {
        int sum = (s2[i]-'0')+carry;
        str.push_back(sum%10+'0');
        carry= sum /10;
    }
    if(carry)
        str.push_back(carry+'0');
    reverse(str.begin(),str.end());

    return str;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    string s1,s2;
    cin>>s1>>s2;
    // string addition
    cout<<add(s1,s2)<<endl;
    return 0;
}