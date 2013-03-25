#include<cstdio>
#include<string>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<map>
using namespace std;

   vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > ret;
        unordered_map<string,string> previous;
     
        queue<pair<string,int> > coada;
        coada.push(make_pair(start,0));
		dict.erase(start);
		dict.erase(end);
        if(start==end && dict.empty()==true ) 
            return ret;
        pair<string,int> curent;
		previous[start]="###";
        int n;
		int lungime = 0;
        while(coada.empty()==false){
			curent = coada.front();
			coada.pop();
			if(lungime !=0 ){
				if(curent.second+1 !=lungime) break;
			}
            n = curent.first.length()-1;
            string aux = curent.first;
            char c ;
            for(int i=0;i<=n;++i){
                c = aux[i];
                for(int j='a';j<='z';++j){
                    aux[i]=j;
                    if(curent.first == aux) continue;
                    if(aux==end){
                        vector<string> forret;
                        forret.push_back(end);
						forret.push_back(curent.first);
						string prev = previous[curent.first];
						
						while(prev!="###"){
							forret.push_back(prev);
							prev = previous[prev];
						}
						reverse(forret.begin(),forret.end());
						ret.push_back(forret);
						lungime = curent.second+1;
                    }else
                    if(dict.find(aux)!=dict.end()){
                        coada.push(make_pair(aux,curent.second+1));
						previous[aux]=curent.first;
						dict.erase(aux);
                    }
                }
				 aux[i] = c;
            }
        }
		
        return ret;
    }
	int main(){
	unordered_set<string> myset;
	myset.insert("ted");
	myset.insert("tex");
	myset.insert("red");
	myset.insert("tax");
	myset.insert("tad");
	myset.insert("den");
	myset.insert("rex");
	myset.insert("pee");
	findLadders("red","tax",myset);
	return 0;
}