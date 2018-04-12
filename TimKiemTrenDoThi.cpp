#include<bits/stdc++.h>
#include<queue>
#include<stack>
#define Nmax 5800
using namespace std;
bool c[Nmax],ok;
int n,l,f;
string a[Nmax];
int pre[Nmax];

queue<int> que;
stack<int> sres;


void Input(){
string x;
string x1,y1;
f=-1;
l=-1;
cout<<"Nhap 2 tu \n";
cin>>x1;
cin>>y1;

ifstream ifs("int.txt");
    while(!ifs.eof()){
   
    ifs>>x;
    if(x1==x) f=n+1;
    if(y1==x) l=n+1;
    a[n+1]=x;
     n++;
	}
}

bool Check(string x,string y){
	for(int i=0;i<x.length();i++)
		for(int j=0;j<y.length();j++) {
			if(x[i]==y[j]) {
				x[i]='0';
				y[j]='0';
				break;
			}
		}
	int d=0;
	 for(int i=0;i<x.length();i++)
	 if(x[i]!='0') d++;
	 for(int j=0;j<y.length();j++)
	 if(y[j]!='0') d++;
	 if(d<=2) return true;else return false;
	 

}

void BFS(int f1){
	que.push(f1);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		
			for(int i=1;i<=n;i++)
				if(!c[i] and Check(a[u],a[i])){
					
				
					c[i]=true;
					que.push(i);
					
				}
	}
	
}

void BFS1(int f1){
	que.push(f1);
	while(!que.empty()){
		int u=que.front();
		que.pop();
		
		
			for(int i=1;i<=n;i++)
				if(c[i] and Check(a[u],a[i])){
					
				
					c[i]=false;
					que.push(i);
					pre[i]=u;
					if(i==f) {
						ok=true;
						return;
					}
					
				}
	}
	
}
void Program(){
int Res=0;
	for(int i=1;i<=n;i++){
		if(!c[i]){
			
			c[i]=true;
			BFS(i);
			Res++;
		}
	}
	cout<<"so thanh phan lien thong "<<Res<<"\n";
	BFS1(l);
	if(ok==true){
		while(l!=f){
			cout<<a[f]<<" ";
			f=pre[f];
		}
		cout<<a[l];
	}
	else cout<<"Khong lien thong";
	
	
}

main(){
	
Input();
Program();
}

