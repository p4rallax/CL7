#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
//#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
int prime(long int pr)
{
	int i,j;
	j = sqrt(pr);
	for(i=2;i<=j;i++)
	{
		if(pr % i == 0)
			return 0;
	}
	return 1;
}

int gcd(int e, int fn)
{
		if(e==0)
			return fn;
		else
			return gcd(fn%e,e);
}

int main()
{
	int p,q,flag=0,fn,i,x,e,n;
	long double d;
	long double c, plain, cipher,decipher,dec;
	while(flag == 0)
	{
		cout<<"Enter 1st prime number: ";
		cin>>p;
		flag = prime(p);
		if(flag == 0)
			{
				cout<<"Number entered is non prime\n";
				cout<<"Enter again\n";
			}
	}
	
	cout<<"Enter 2nd prime : ";
	cin>>q;
	flag = prime(q);
	while(flag == 0 || q==p)
	{
		cout<<"Wrong input, enter again :";
		cin>>q;
		flag = prime(q);
	}
	
	cout<<"The numbers are : "<<p <<" and "<<q;
	
	n = p*q;
	fn = (p-1)*(q-1);
	
	cout<<"\nEnter the value to be encrypted : ";
	cin>>plain;
	cout<<"n is "<<n<<" and fn is "<<fn;
	for(e=2;e<fn;e++)
	{
		if(gcd(e,fn)==1)
			break;
	}
	cout<<"\npublic key e is "<<e;
		
	for(i=1;i<=9;i++)
	{
		x = fn*i + 1;
		if(x%e == 0)
		{
			d = x/e;
			cout<<"\nprivate key d is "<<d;
			break;
		}
	}
	
	c = pow(plain,e);
	cipher = fmod(c,n);
	cout<<"\nciphertext is "<<cipher;
	cout<<"\n...decyphering...\n";
	dec = pow(cipher,d);
	decipher = fmod(dec,n);
	cout<<"\nDeciphered value is.. "<<decipher;
}
