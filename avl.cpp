#include <iostream>
#include <algorithm>

using namespace std;  // Add this line

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree() {
        root = nullptr;
    }

    // Function to insert a value into the AVL tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to delete a value from the AVL tree
    void remove(int value) {
        root = removeRec(root, value);
    }

    // Function to search for a value in the AVL tree
    bool search(int value) {
        return searchRec(root, value);
    }

private:
    TreeNode* root;

    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(TreeNode* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else {
            return node; // Duplicate values are not allowed
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // Left heavy
        if (balance > 1) {
            if (value < node->left->data) {
                return rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        // Right heavy
        if (balance < -1) {
            if (value > node->right->data) {
                return leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    TreeNode* removeRec(TreeNode* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = removeRec(node->left, value);
        } else if (value > node->data) {
            node->right = removeRec(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                TreeNode* temp = (node->left) ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                TreeNode* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = removeRec(node->right, temp->data);
            }
        }

        if (node == nullptr) return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1) {
            if (balanceFactor(node->left) >= 0) {
                return rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (balance < -1) {
            if (balanceFactor(node->right) <= 0) {
                return leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    bool searchRec(TreeNode* node, int value) {
        if (node == nullptr) return false;

        if (value == node->data) return true;

        if (value < node->data) {
            return searchRec(node->left, value);
        } else {
            return searchRec(node->right, value);
        }
    }
};

int main() {
    AVLTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Is 60 in the AVL tree? " << (tree.search(60) ? "Yes" : "No") << "\n";
    cout << "Is 90 in the AVL tree? " << (tree.search(90) ? "Yes" : "No") << "\n";

    tree.remove(20);
    tree.remove(30);

    cout << "Is 20 in the AVL tree after deletion? " << (tree.search(20) ? "Yes" : "No") << "\n";

    return 0;
}
