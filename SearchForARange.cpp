class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> sol;
        int st = 0, dr = n-1,m;
        while(st<=dr){
            m = st + (dr-st)/2;
            if( A[m] < target ){
                st = m+1;
            }else
            if(A[m] > target) {
                dr = m-1;
            }else
            if(A[m] == target){
                st=dr =m;
                while(A[st] == target){
                    st--;
                }
                st++;
                while(A[dr]==target){
                    dr++;
                }
                dr--;
                sol.push_back(st);
                sol.push_back(dr);
              dr = -1; st = 1;
            }
        }
        
        if(sol.size() ==0 ) {
            sol.push_back(-1);
            sol.push_back(-1);
        }
        return sol;
        
    }
};