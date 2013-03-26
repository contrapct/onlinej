#include<cstdio>
#include<string>
#include<vector>
using namespace std;

FILE * f;
char t[1000];
char s[1000];
int n;
int a[1000][31];
void Solve(){
	for(int i=strlen(t)-1;i>=0;--i){
		for(int j =0;j<=30;++j){
			a[i][j]=a[i+1][j];
		}
		a[i][t[i]-'a']=i+1;
	}
	for(int i=0;i<strlen(t);i++){
		for(int j=0;j<=30;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
void ReadData(){
	scanf("%d\n",&n);
	scanf("%s",&t);
	Solve();
	for(int i=1;i<=n;++i){
		scanf("%s",&s);
		int ok = 1,j;
		int poz = 0;
		for(j=0;s[j]!='\0' && ok ==1;++j){
			if(a[poz][s[j]-'a']==0) ok = 0;
			else
				poz = a[poz][s[j]-'a'];
		}
		if(ok == 1){
			printf("YES\n");
		}
		else {printf("NO\n");}
	}
}


int main(){
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	ReadData();
	return 0;
}