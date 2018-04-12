#include<bits/stdc++.h>
using namespace std;


main(){
int a[]={1,2,3,4,5,6,7};
int b,*p=a+1;
b=*p++;*p+=b;
b=(*p)++;*p+=b;
for(int i=0;i<7;i++)
cout<<a[i]<<" ";
}

