#算法分析过程 
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a;
    a = "flag{c2df6facc79fb9c477312fd27f7adbbe}";
	string key="b5c554f1847015d7ad5f2a891df2749df2a897";
	int l=a.length();
	char b[l+1];
	b[0]=a[0]^0x1;
	for(int i=1;i<l;i++)
	{
		char c=a[i]^b[i-1];         // a[i+1]=0x34^e[i]^key[i]  a[i]=b[i]^b[i-1]
		b[i]=c;
	}
	for(int i=0;i<l-1;i++)           //e[i]^key[i]^key[i+1]^0x56=b[i]^b[i+1]^0x34
	{
		char c=b[i]^b[i+1];          //b[i]=b[i]^b[i+1]^0x34
		c=c^0x34;
		b[i]=c;
	}
	for(int i=0;i<l-1;i++)               //b[i]=e[i]^key[i]^key[i+1]^0x56
	{
		char c=b[i]^key[i+1];            //e[i]^key[i]=b[i]^key[i+1]^0x56
		c=c^0x56;
		b[i]=c;
	}
	for(int i=1;i<l-1;i++)             //b[i+1]=b[i+1]^key[i+1]^0x78
	{
		b[i]=b[i]^key[i]^0x78;
	}
	for(int i=1;i<38;i++)
	{
		key[i]=key[i-1]^key[i]^a[(i-1)%7]^a[(i-1)%9];   //key[i+1]=k[i]^k[i+1]^a[i%7]^a[i%9]
	}
	for(int i=0;i<38;i++)
	{
		b[i]=b[i]^key[i];             // e[i]=b[i]^key[i]   b[i]=e[i]^key[i] 
	}
	for(int i=0;i<38;i++)
	{
		cout<<(int)b[i]<<",";
	}
	return 0;
	char e[]={93,101,0,41,4,97,81,98,8,102,81,104,67,38,5,104,83,105,7,43,21,39,26,54,6,99,24,121,31,112,21,33,94,114,66,43,10,18};
}
