#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1; cin>>t;
	while(t--){
	    int n; cin>>n;
	    string s1,s2,s3; cin>>s1>>s2>>s3;
	    int t;
	    if(s2[0]<s1[0]) t=s2[0]+26-s1[0];
	    else t=s2[0]-s1[0];
	    string s;
	    for(int i=0;i<n;i++){
	        s+=(s3[i]-'a'+t)%26+'a';
	    }
	    string s4=s;
	    cout<<s<<endl;
	}
}
Given a string S consisting only of :, (, and ) (colon, right parenthesis, and left parenthesis).
We define a Schrödinger's Smiley as any positive number of right parenthesis between two colons. For example, :):, :))):, and :))))): are Schrödinger's smileys while :))(:, :(:, ::): and :: are not.
Find the total number of substrings in S that are Schrödinger Smileys.
A substring is obtained by deleting any (possibly zero) number of characters from the beginning and any (possibly zero) number of characters from the end of the string.
Input Format
The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains an integer N, the length of the string S.
The next line contains the string S.
Output Format
For each test case, output on a new line, the total number of substrings in S that are Schrödinger Smileys.