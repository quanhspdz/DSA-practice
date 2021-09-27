else if (leftOrRightNode(root, data) == -1) {
        root->rightNode = insertNode(root->rightNode, data);
    }
    else if (leftOrRightNode(root, data) == 1) {
        root->leftNode = insertNode(root->leftNode, data);
    }