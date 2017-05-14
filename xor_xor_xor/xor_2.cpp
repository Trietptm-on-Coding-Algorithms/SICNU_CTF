#include<iostream>
using namespace std;

void xor_(void)
{
	string f;
	cin>>f;
	f[0]=102;
	string key="b5c554f1847015d7ad5f2a891df2749df2a897";
	int len=f.length();
	char a[len+1];
	a[0]=f[0]^0x1;
	for(int i=1;i<len;i++)
	{
		a[i]=f[i]^a[i-1];
	}
	for(int i=0;i<len-1;i++)
	{
		a[i]=a[i]^a[i+1]^0x34;
	}
	for(int i=0;i<len-1;i++)
	{
		a[i]=a[i]^key[i+1]^0x56;
	}
	for(int i=1;i<len-1;i++)
	{
		a[i]=a[i]^key[i]^0x78;
	}
	for(int i=1;i<38;i++)
	{
		key[i]=key[i-1]^key[i]^f[(i-1)%5]^f[(i-1)%7];
	}
	for(int i=0;i<38;i++)
	{
		a[i]=a[i]^key[i];
	}
	char re[]={89,122,31,96,76,122,74,121,19,115,93,104,75,125,64,48,12,106,1,43,5,58,84,107,2,121,86,108,11,97,78,36,26,51,92,114,92,9};
	for(int i=0;i<len;i++)
	{
		if(a[i]!=re[i])
		{
			cout<<"failed"<<endl;
			return ;
		}
	}
	cout<<"success"<<endl;
	return;
}
int main()
{
	while(1){
		xor_();
	}
	return 0;
}
