class Solution {
public:

void Flatten(TreeNode *root){
    if(root== NULL) return;
	if(root->left == NULL && root->right ==NULL) return;
	if(root->left == NULL) {
		Flatten(root->right);
		return;
	}
	if(root->right==NULL){
		root->right = root->left;
		root->left = NULL;
		Flatten(root->right);
		return;
	}
	TreeNode * p = root->right;
	root->right = root->left;
	root->left = NULL;
	TreeNode * q = root->right;
	while(q!= NULL && q->right!=NULL){
		q=q->right;
	}
	q->right = p;
	Flatten(root);
}
void flatten(TreeNode *root) {
	if(root==NULL) return;
	Flatten(root);        
}
};
