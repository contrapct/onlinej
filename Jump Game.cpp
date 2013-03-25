class Solution {
public:
    bool canJump(int A[], int n) {
        int viz[n];
        int i;
        for(i=0;i<n;++i)
            viz[i]=0; 
        viz[0]=1;
        for(i=0;i<n;++i){
            if(viz[i]==1){
                if(i+A[i]>=n-1) return true;
                viz[i+A[i]]=1;
            }
        }
        return false;
    }
};