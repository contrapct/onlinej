#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> G[100];
int dist[100][100],plecare,pozi,k;
int m,n;
int pleaca[100];
void ReadData(){
	freopen("1.in","r",stdin);
	scanf("%d %d %d %d",&n,&m,&plecare,&k);
	int a,b;
	for(int i=1;i<=m;++i){
		scanf("%d %d",&a,&b);
		G[b].push_back(a);
		G[a].push_back(b);
	}
}
void BFS(int start){
	vector<int> viz ;
	viz.resize(n+1);
	queue<int>coada;
	viz[start]=1;
	for(coada.push(start);coada.empty()==false;coada.pop()){
		int curent = coada.front();
		for( auto it = G[curent].begin(); it!=G[curent].end(); ++it){
			if(viz[*it]==0){
				coada.push(*it);
				dist[start][*it]=dist[start][curent]+1;
				viz[*it]=1;
			}
		}
	}
}
void Solve(){
	int ok = 1,maxx =0;
	for(int it=1;ok ==1 && it<=n;++it){
		if(dist[plecare][it]>k)ok = 0;
		else maxx = max(maxx, dist[plecare][it]);
	}
	
	if(ok == 1 ){  
		printf("%d",maxx);
		return;
	}
	int s = 0 ;
	//cainele se muta din "plecare";

	for(int it=1; it<=n;++it){
		s=0;
		if(dist[plecare][it]==0) continue;
		s+=dist[plecare][it];//  calculez distata de la nodu initial al cainelui la intermediar
		//calculez cat trebuie sa astept pana sare iepurele
		s+= dist[plecare][it]%k;
		//calculez unde a sarit iepurele
		maxx=0;
		for(int k=1;k<=n;++k){
			if(dist[it][k]==0){continue;}
			else if(maxx<dist[it][k]){ 
				maxx = dist[it][k]; 
				pozi = k;
			}
		}
		if(maxx !=0 && dist[it][pozi]<=k) s+=k;else s=-1;
		pleaca[it]=s;
	}
	int min = 100*100;
	for(int i=1;i<=n;++i){
		if(pleaca[i]!=-1 && min<pleaca[i])
			min = pleaca[i];
	}
}
int main(){
	ReadData();
	freopen("1.out","w",stdout);
	for(int i=1;i<=n;++i){
		BFS(i);
	}
	pozi = plecare +1;
	Solve();
	return 0;
}