#include<cstdio>
#include<vector>
using namespace std;
vector<int> G[100];
int nrc=1;
void DFS(int node,int lv){
	static int Level[100];
	Level[node]=lv+1;
	//printf("%d %d\n",node,lv);
	for( auto it = G[node].begin(); it != G[node].end() ; ++it){
		if( Level[*it] != 0) {
			if(lv > Level[*it]){
				nrc*= ( lv+1 - Level[*it] +1);		
			} 
		}
		else {
			DFS(*it, lv+1);
		}
	}
}
int m,n;
void ReadData(){
	freopen("1.in","r",stdin);
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a,&b);
		G[b].push_back(a);
		G[a].push_back(b);
	}
}

int main(){
	ReadData();
	freopen("1.out","w",stdout);
	DFS(1,0);	
	printf("%d\n",nrc);
	return 0;
}