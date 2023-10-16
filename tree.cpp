#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a value into the binary tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to delete a value from the binary tree
    void remove(int value) {
        root = removeRec(root, value);
    }

    // Perform inorder traversal of the binary tree
    void inorderTraversal() {
        inorderTraversal(root);
    }

    // Perform postorder traversal of the binary tree
    void postorderTraversal() {
        postorderTraversal(root);
    }

    // Perform preorder traversal of the binary tree
    void preorderTraversal() {
        preorderTraversal(root);
    }

private:
    TreeNode* root;

    TreeNode* insertRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->data) {
            root->left = insertRec(root->left, value);
        } else if (value > root->data) {
            root->right = insertRec(root->right, value);
        }

        return root;
    }

    TreeNode* removeRec(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = removeRec(root->left, value);
        } else if (value > root->data) {
            root->right = removeRec(root->right, value);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = removeRec(root->right, temp->data);
        }

        return root;
    }

    TreeNode* findMinValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void postorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }

    void preorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal();
    cout << "\n";

    cout << "Postorder Traversal: ";
    tree.postorderTraversal();
    cout << "\n";

    cout << "Preorder Traversal: ";
    tree.preorderTraversal();
    cout << "\n";

    tree.remove(20);

    cout << "Inorder Traversal after deletion: ";
    tree.inorderTraversal();
    cout << "\n";

    return 0;
}

