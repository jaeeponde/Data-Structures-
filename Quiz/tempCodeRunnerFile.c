void split_tree(Node* node) {
    int mid = 3;
    int mid_key = node->keys[mid];

    // Create new nodes for the split
    Node* left_node = create_node();
    Node* right_node = create_node();

    // copy keys to the left node
    for (int i = 0; i < mid; i++) {
        left_node->keys[i] = node->keys[i];
        left_node->num_keys++;
    }

    // copy keys to the right node
    for (int i = mid + 1,j=0; i < (2 * t - 1); i++,j++) {
        right_node->keys[j] = node->keys[i];
        right_node->num_keys++;
    }

    // copy children to the left node if node is not a leaf
    if (!node->is_leaf) {
        for (int i = 0; i <= mid; i++) {
            left_node->children[i] = node->children[i];
        }
    }

    // Copy children to the right node if node is not a leaf
    if (!node->is_leaf) {
        for (int i = mid + 1; i <= (2 * t); i++) {
            right_node->children[i - mid - 1] = node->children[i];
        }
    }

    // Set the middle key to the parent node
    node->keys[0] = mid_key;
    node->keys[1] = EMPTY;
    node->keys[2] = EMPTY;
    node->keys[3] = EMPTY;
    node->keys[4] = EMPTY;
    node->num_keys = 1;

    // Update node's children pointers
    node->children[0] = left_node;
    node->children[1] = right_node;
    node->is_leaf = false;}