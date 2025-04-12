TreeNode* deleteDominated(TreeNode* root, Point p) {
    operations++;
    if (root == NULL)
        return NULL;

    // Traverse left and right subtrees first
    root->left = deleteDominated(root->left, p);
    root->right = deleteDominated(root->right, p);

    // Check if the current node is dominated
    if (root->p.y < p.y && root->p.z < p.z) {
        TreeNode* temp;
        if (root->left == NULL) {
            // Case 1: Node has only right child or no children
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 2: Node has only left child
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        // Find the inorder successor (smallest in the right subtree)
        temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;

        // Replace the current node's data with the successor's data
        root->p = temp->p;

        // Recursively delete the successor from the right subtree
        root->right = deleteDominated(root->right, temp->p);
    }

    // Update the height of the current node
    root->height = 1 + (height(root->left) > height(root->right) ? height(root->left) : height(root->right));

    // Get the balance factor of this node to check if it is unbalanced
    int balance = getBalance(root);

    // Balance the tree based on the balance factor

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}