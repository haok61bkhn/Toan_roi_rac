#include<bits/stdc++.h>
#define Nmax (10005)
using namespace std;
int sccCount,dfsCount,n,low[Nmax],num[Nmax];
bool a[Nmax][Nmax];
bool c[Nmax];
vector<int> vt1;

void Input(){
freopen("int.txt","r",stdin);
int m;	
	cin>>n>>m;
	for(int i=0;i<m;i++)
	 	{ int x;int y;
	 	cin>>x>>y;
	 	a[x][y]=true;
		 
		 }
}

void Tarjan(int u){
	c[u]=true;
	vt1.push_back(u);
	low[u]=num[u]= ++dfsCount;

	for(int v=1;v<=n;v++)
		if(a[u][v]){
		if(num[v]==0) Tarjan(v); 
		if(c[v]) low[u]=min(low[u],low[v]);
	
	}
	
	if(num[u]==low[u]){
	
		++sccCount;
	   while(1){
	   	int v=vt1.back();
	   	vt1.pop_back();
	   	cout<<v<<" ";
	   	if(v==u){
	   		cout<<"\n";
	   		break;
		   }
	   	
	   }
	}
		
	

}

main(){
Input();
for(int i=1;i<=n;i++)
 if(num[i]==0) Tarjan(i);
 cout<<sccCount;
}

