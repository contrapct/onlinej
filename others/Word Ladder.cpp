class Solution {
public:

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start==end) return 0;
        queue<pair<string,int >> coada;
        pair<string,int > curent;
        int n,i;
        coada.push(make_pair(start,1));
        dict.erase(start);
        
        while(coada.empty()==false){
            curent = coada.front();  
            coada.pop();
    		n = curent.first.length()-1;
			string aux = curent.first;
            for(i=0;i<=n;++i){
                char c;
				c=aux[i];
                for(int j='a';j<='z';++j){                    
                    aux[i]=j;
					if(aux.compare(end)==0) {
						return curent.second+1;
					}
                    if(dict.find(aux)!=dict.end()){ 
                        dict.erase(aux);
						coada.push(make_pair(aux,curent.second+1));
                    }
                    
                }
				aux[i]=c;
            }
        }
        return 0;
    }

};