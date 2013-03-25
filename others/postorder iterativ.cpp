void postOrderTraversalIterative(BinaryTree *root) {
  if (!root) return;
  stack<BinaryTree*> s;
  s.push(root);
  BinaryTree *prev = NULL;
  while (!s.empty()) {
    BinaryTree *curr = s.top();
    // we are traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // we are traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;  // record previously traversed node
  }
}