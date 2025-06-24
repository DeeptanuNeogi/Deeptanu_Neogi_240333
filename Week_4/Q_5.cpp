#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    if (value < root->val) {
        root->left = insertBST(root->left, value);
    } else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

TreeNode* buildBST() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;

    TreeNode* root = nullptr;
    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insertBST(root, value);
    }

    return root;
}

int nextGreater(TreeNode* root, int B) {
    TreeNode* successor = nullptr;

    while (root) {
        if (root->val > B) {
            successor = root; 
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor ? successor->val : -1;
}

int main() {
    cout << "Build the BST:\n";
    TreeNode* root = buildBST();

    cout << "Enter the target value (B): ";
    int B;
    cin >> B;

    int result = nextGreater(root, B);
    if (result == -1) {
        cout << "No next greater number found.\n";
    } else {
        cout << "The next greater number is: " << result << endl;
    }

    return 0;
}
