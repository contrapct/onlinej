class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack <pair <int,int> > st;
        int ret;
        
        ret=0; st.push(make_pair ('#',0));
        for (int i=1; i<=s.length (); ++i) {
            
            if (s[i-1]=='(')
                st.push (make_pair ('(',i));
            else {
                if (st.top ().first=='(')
                    st.pop ();
                else
                    st.push (make_pair (')',i));
            }
            ret=max (ret,i-st.top ().second);
        }
        
        return ret;
    }
};