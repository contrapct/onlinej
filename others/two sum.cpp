class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> sol;
        map<int,int> haspmap;
        int i=0;
    	for(vector<int>::iterator it= numbers.begin();it!=numbers.end();++it,++i){
           haspmap[*it]=i;
        }
		i=0;
        for(auto it= numbers.begin();it!=numbers.end();++it,++i){
            int chestie = haspmap[target-(*it)];
            if(chestie != NULL){
                sol.push_back(i+1);
                sol.push_back(chestie+1);
                return sol;
            }
        }
        return sol;
    
    }
       
};