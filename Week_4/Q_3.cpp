#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;

    
    inorderTraversal(root->left, result);


    result.push_back(root->val);

    inorderTraversal(root->right, result);
}

TreeNode* buildTree() {
    cout << "Enter the root value: ";
    int rootValue;
    cin >> rootValue;

    if (rootValue == -1) return nullptr; 

    TreeNode* root = new TreeNode(rootValue);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftValue, rightValue;
        cout << "Enter left child of " << current->val << " (-1 for null): ";
        cin >> leftValue;
        if (leftValue != -1) {
            current->left = new TreeNode(leftValue);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->val << " (-1 for null): ";
        cin >> rightValue;
        if (rightValue != -1) {
            current->right = new TreeNode(rightValue);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    cout << "Build the binary tree:\n";
    TreeNode* root = buildTree();

    vector<int> result;
    inorderTraversal(root, result);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
