#include<bits/stdc++.h>
#include<string>
#include<list>
#define Nmax int(3e4)
using namespace std;
int n,res,num[Nmax],low[Nmax],dfscount;
bool c[Nmax];
int kt[27],l,pre[Nmax];
vector<int> vt;
list<int> a[Nmax];
string b[Nmax];
string s;
queue<int> que;
bool ok;


bool Check(string x,string y){	
int j;
    for(int i=x.length()-1;i>=x.length()-4;i--){
    	for( j=0;j<y.length();j++)
			if(x[i]==y[j]){
				y[j]='0';
				break;
			} 
    	if(j==y.length()) return false;
		
	}
		   	
	return true;
}

void Input(){

string s;	
int j;
int d=0;
ifstream ifs("int.txt");
	
	for( n=1;n<=5757;n++){
		getline(ifs,s);
		b[n]=s;
		for(j=1;j<n-1;j++){
		  if(Check(b[j],s)) a[j].push_back(n);
		  if(Check(s,b[j])) a[n].push_back(j);
		}
		
	}
	
	n--;
				
}

void Tarjan(int u){
	c[u]=true;
	vt.push_back(u);
	num[u]=low[u]=++dfscount;
list<int>:: iterator  v1=a[u].begin();
	for(;v1!=a[u].end();v1++){
	    int v=*v1;
	  	if(num[v]==0) Tarjan(v);
	  	if(c[v]==true) low[u]=min(low[v],num[u]);
	  }
	  
	  if(low[u]==num[u]){
		res++;
		while(1){
			int v=vt.back();
			c[v]=false;
			vt.pop_back();
			if(v==u) break;
		}
	}
	  
	  
	
}

void Tarjan1(int u){
	c[u]=true;
	vt.push_back(u);
	num[u]=low[u]=++dfscount;
list<int>:: iterator  v1=a[u].begin();
	for(;v1!=a[u].end();v1++){
	    int v=*v1;
	  	if(num[v]==0) Tarjan(v);
	  	if(c[v]==true) low[u]=min(low[v],num[u]);
	  }
	  
	  if(low[u]==num[u]){
		res++;
		while(1){
			int v=vt.back();
			c[v]=false;
			if(b[u]==s)
			 cout<<b[v]<<" ";
			vt.pop_back();
			if(v==u) break;
		}
	}
	  
	  
	
}
int Find(string s){
	for(int i=1;i<=n;i++)
	  if(b[i]==s) return i;
	  return 0;
}

void BFS(int f){
	que.push(f);
	c[f]=true;	
	while(!que.empty()){
		int u=que.front();
		
			que.pop();
		    list<int> ::iterator i = a[u].begin();					
				for(;i!=a[u].end();i++)
				if(!c[*i])
				{
					c[*i]=true;
					que.push(*i);
					pre[*i]=u;
					if(*i==l) {
						ok=true;
						return;
					}
					
				}
	}
	
}

void Program(){
	int select;
	cout<<"Menu:\n\tchon 1: Tinh So luong thanh phan lien thong\n\tchon 2: Tim cac thanh phan lien thong voi 1 xau nhap vao \n\tchon 3: Tim duong ngan nhat toi giua 2 xau\n";
	cin>>select;	
	switch(select){
 
	case 1:
			for(int i=1;i<=n;i++)
				if(num[i]==0) Tarjan(i); 	
	
			cout<<res;
			break; 
	
	case 2: 
			cout<<"Nhap xau can tim"<<"\n";
			cin>>s;
			if(Find(s)==0) cout<<"Khong ton tai tu"<<s<<"\n";
			else{
			
			cout<<"Cac thanh phan lien thong manh voi tu xau "<<s<<" :\n";
			Tarjan1(Find(s));
			}
			break;
	case 3:
		    string x,y;
			cout<<"Nhap 2 tu can tim:\n";
			cin>>x;
			cin>>y;
			l=Find(x);
			int f=Find(y);
			BFS(f);
			if(ok==false) cout<<"Khong co duong di";
			else{
				cout<<"Duong di giua 2 xau "<<x<<" "<<y<<" la:\n";
				while(l!=f){
					cout<<b[l]<<"->";
					l=pre[l];
				}
				cout<<b[f];
			}
			break;
		
	}
}

main(){
Input();
Program();

}

