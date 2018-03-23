#include<bits/stdc++.h>
#include<list>
#define Nmax int(1e5)
using namespace std;
int step[Nmax];
list<int> a[Nmax];
int n;

void   Init(){
int x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		step[x]++;
		step[y]++;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
void   Program(){
int i;
	for( i=1;i<=n;i++){
		if(step[i]==1){
			step[i]--;
			step[*a[i].begin()]--;
			cout<<*a[i].begin()<<" ";
			a[*a[i].begin()].remove(i);
			break;
		}
	}
	if(i<=n) Program();else exit(0);
}

main(){
	Init();
	Program();
}
