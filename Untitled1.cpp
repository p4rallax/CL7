#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int multinv(int a , int b)
{
	int x0= 0 ,x1 =1 ,b0= b, q ,t;
	if(b==1)
	return 1;
	
	while(a>1)
	{
		q=a/b;
		t=b;
		b=a%b;
		a=t;
		t=x0;
		x0=x1 - q*x0;
		x1=t;
	}
	
	if(x1<0)
	x1=x1+b0;
	
	return x1;
}


int main(){
	int i,j , x[10], T[10] , M=1 , m[10] , a[10] , n , finans ,z=0;
	
	cout<<"Enter number of equations\n";
	cin>>n;
	
	cout<<"Enter values of a\n";
	for(i =0 ; i<n;i++)
	cin>>a[i];
	
	cout<<"Enter values of m\n";
	for(i=0;i<n;i++)
	{
		cin>>m[i];
	}
	
	
	for(i=0;i<n;i++)
	M=M*m[i];
	
	for(i=0;i<n;i++)
	x[i] = M/m[i];
	
	for(i=0;i<n;i++)
	T[i]= multinv(x[i], m[i]);
	
	for(i=0;i<n;i++)
	z= z + x[i]*a[i] *T[i];
	
	finans = fmod(z,M);
	cout<<"ifansifnasf"<<finans;

}
