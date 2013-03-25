class Solution {
public:
    TreeNode *sortedListToBST(ListNode *&head,int st, int dr){
        if(head == NULL) return NULL;
        if(st > dr) return NULL;
        int m = st +(dr-st)/2;
        TreeNode * leftChild = sortedListToBST(head,st,m-1);
        TreeNode * root = new TreeNode (head->val);
        head  = head -> next;
        TreeNode * rightChild = sortedListToBST(head,m+1,dr);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        int n = 0;
        ListNode * p = head; 
        while(p!=NULL){
            p =p->next; 
            ++n;
        }
        sortedListToBST(head,0,n-1);
        
    }
};