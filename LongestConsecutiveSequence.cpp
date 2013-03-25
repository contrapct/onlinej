class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,pair<int,int> > h;
        int min,max;
        for(auto & it : num){
            if(h.find(it)==h.end()){
                max = min=it;
                if(h.find(it-1)!=h.end()){min=h[it-1].first;}
                if(h.find(it+1)!=h.end()){max=h[it+1].second;}
                h[min]=h[max]=h[it]=make_pair(min,max);                
            }
        }
        max =0;
        for(auto & it : h){
            if(it.second.second - it.second.first> max){
                max = it.second.second - it.second.first;
            }
        }
        max = max+1;
        return max;
    }
};