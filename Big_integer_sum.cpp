#include<bits/stdc++.h>
using namespace std;

string add(string s1,string s2)
{
    if(s1.length()>s2.length())
        swap(s1,s2);
    string str = "";
    int n1 = s1.length();
    int n2 = s2.length();

    // reverse both string 
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    
    int carry = 0;
    for(int i = 0 ;i<n1;i++)
    {
        int sum = (s1[i]-'0')+(s2[i]-'0')+carry;
        str.push_back((sum%10)+'0');
        carry = sum/10;
    }
    // adding remaing digit of the large number 
    for(int i = n1;i<n2;i++)
    {
        int sum = (s2[i]-'0')+carry;
        str.push_back((sum%10)+'0');
        carry = sum/10;
    }
    if(carry)
    {
        str.push_back(carry+'0');
    }
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
    
    // String addition //
    cout<<add(s1,s2)<<endl;
    return 0;
}