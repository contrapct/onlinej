class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        map<int,vector<pair<int, int> > >  hashh;
        int n = num.size();
        vector<vector<int> > sol;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                hashh[(num[i]+num[j])].push_back(make_pair(i,j));
            }
        }
        map<int,vector<pair<int,int> > > :: iterator it;
        vector<pair<int,int> > :: iterator itv ;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                it = hashh.find(target-(num[i]+num[j]));
                if( it != hashh.end()){
                    for(itv = hashh[target-(num[i]+num[j])].begin(); itv!=hashh[target-(num[i]+num[j])].end(); itv++){
                         set <int> index;
                        index.insert (i);
                        index.insert (j);
                        index.insert (itv->first);
                        index.insert (itv->second);
                    
                        if (index.size ()!=4)
                            continue;
                        
                        vector<int> per;
                        per.push_back(num[i]);
                        per.push_back(num[j]);
                        per.push_back(num[itv->first]);
                        per.push_back(num[itv->second]);                        
                        sort (per.begin (),per.end ());
                        sol.push_back(per);
                    }
                }
            }
        }
         sort (sol.begin (),sol.end ());
         //unique (sol.begin (),sol.end ());
         sol.erase (unique (sol.begin (),sol.end ()),sol.end ());
         
        return sol;
    }
};