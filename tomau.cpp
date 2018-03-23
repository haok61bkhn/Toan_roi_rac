#include<bits/stdc++.h>
#include<list>
#define Nmax int(1e5)
using namespace std;
list<int> a[Nmax];
int n,m,deg[Nmax],Res[Nmax],b[Nmax];
int c[2*Nmax];
string color[9]={"","""red","yellow","blue","green","black","white","pink","orange"};
void Input(){
int x,y;
freopen("dothi.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
		deg[x]++;
		deg[y]++;	
		c[i*2]=x;
		c[i*2+1]=y;
	}	
	for(int i=0;i<n;i++)
		b[i]=i+1;
	
}

void Qsort(int f,int l){
int i=f,j=l,mid=deg[b[(f+l)/2]];
	while(i<=j){
		while(deg[b[i]]<mid) i++;
		while(deg[b[j]]>mid) j--;
		 if(i<=j){
		 	swap(b[i],b[j]);
		 	i++;
		 	j--;
		 }
	}
if(i<l) Qsort(i,l);
if(j>f) Qsort(f,j);
}

void Find_color(int x){
	if(x>=n) return;
	if(Res[b[x]]!=0) Find_color(x+1);
		else{
			int k=1;
			while(1!=0){
				list<int>::iterator  y = a[b[x]].begin();
				for(;y!=a[b[x]].end();y++)
					if (Res[*y]==k) break;
				if(y==a[b[x]].end()) break;
				k++;	
			}
			Res[b[x]]=k;
			Find_color(x+1);
			
		}
	
}

void Output(){
	freopen("dothimau.dot","w",stdout);
	cout<<"graph dothi\n";
	cout<<"{\n";
	for(int i=0;i<n;i++)
		cout<<"\t"<<b[i]<<" ["<<"fillcolor="<<color[Res[b[i]]]<<", style=filled];\n";
	for(int i=0;i<n;i++)
	cout<<"\t"<<c[2*i]<<" -- "<<c[2*i+1]<<";\n";
	cout<<"}";
}

main(){
Input();
Qsort(0,n-1);
Find_color(0);
Output();
}

