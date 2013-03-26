class Solution {
public:
    int jump(int A[], int n) {
           int viz[n];
	int i;
	for(i=0;i<n;++i){
		viz[i]=0;
	}
	viz[0]=1;
	for(i=0;i<n;++i){
		if(viz[i]>=1){
			for(int k=1;i<n && k<=A[i];++k){
				if(viz[i+k] == 0 || viz[i+k] > viz[i]+1)
					viz[i+k]=viz[i]+1;
					if(i+k >= n-1) return viz[n-1]-1;
			}
		}
	}
	return viz[n-1]-1;
    }
    
};