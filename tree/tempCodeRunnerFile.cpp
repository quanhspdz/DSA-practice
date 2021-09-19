struct Node {
//     int data;
//     Node *leftNode;
//     Node *rightNode;
// } root;

// typedef Node NodeTree;

// void freeNode(NodeTree *root) {
//     if (root != NULL) {
//         freeNode(root->rightNode);
//         freeNode(root->leftNode);
//         free(root);
//     }
// }

// bool leftOf(int value, NodeTree *root) {
//     return value < root->data;
// }
// bool rightOf(int value, NodeTree *root) {
//     return value > root->data;
// }

// void insertNode(int value, NodeTree *root) {
//     if (leftOf(value, root)) insertNode(value, root->leftNode);
//     else if (rightOf(value, root)) insertNode(value, root->rightNode);
//     else if (root == NULL) {
//         root->data = value;
//         root->leftNode = NULL;
//         root->rightNode = NULL;
//     }
// }