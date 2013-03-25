class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end){
            return 0;
        }
        
        unordered_map < string,int> dist;
        dist[start]=1;
        queue<string> q;
        q.push(start);
        string current ; 
        while(q.empty()==false){
            current =q.front();
            q.pop();
            int n = current.length();
            int dcurrent = dist[current];
            for(int i=0;i<n;++i){
                char c = current[i];
                for(char j='a';j<='z';++j){
                    current[i]=j;
                    if(current == end){
                            return dcurrent+1;
                    }
                    if(dict.find(current)!=dict.end()){
                        int d = dist[current];
                        if(d==0){
                            dist[current]= dcurrent +1 ;
                            q.push(current);                        
                        }                        
                    }
                }
                current[i]=c;
            }            
        }
        return 0;
    }
};