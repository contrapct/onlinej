class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1)
            return 0;
            
        int cur=0,ret=0;
            
        int i=0;
        while (i<n-1) {
            cur=i+A[i]; ++ret;
            
            if (cur>=n-1)
                return ret;
            
            if (!A[i])
                return 0;
            
            int tmp=0;
            for (int j=i+1; j<=cur; ++j)
                if (j+A[j]>tmp) {
                    tmp=j+A[j];
                    i=j;
                }   
        }
        
        return ret;
    }           
};