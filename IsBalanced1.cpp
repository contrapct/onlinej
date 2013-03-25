class Solution {    
public:
    bool isBalanced (TreeNode *root,int &height) {
        if (root==NULL)
            return 1;
        
        int heightLeft=0,heightRight=0;
        bool isLeft=1,isRight=1;
                
        if (root->left)
            isLeft=isBalanced (root->left,heightLeft);
        if (root->right)
            isRight=isBalanced (root->right,heightRight);
        
        height=max (heightLeft,heightRight)+1;
        if (abs (heightLeft-heightRight)<=1)
            return isLeft&isRight;
        return 0;
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth;
        return isBalanced (root,depth);        
    }
};