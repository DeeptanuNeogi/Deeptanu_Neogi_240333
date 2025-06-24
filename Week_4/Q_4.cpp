#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

bool find(TreeNode* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    return find(root->left, val) || find(root->right, val);
}

TreeNode* findLCA(TreeNode* root, int B, int C) {
    if (!root) return nullptr;

    if (root->val == B || root->val == C) return root;

    TreeNode* leftLCA = findLCA(root->left, B, C);
    TreeNode* rightLCA = findLCA(root->right, B, C);

    if (leftLCA && rightLCA) return root;

    return leftLCA ? leftLCA : rightLCA;
}

int lca(TreeNode* root, int B, int C) {
    if (!find(root, B) || !find(root, C)) return -1;

    TreeNode* lcaNode = findLCA(root, B, C);
    return lcaNode ? lcaNode->val : -1;
}

int main() {
    cout << "Build the binary tree:\n";
    TreeNode* root = buildTree();

    int B, C;
    cout << "Enter the two node values to find their LCA: ";
    cin >> B >> C;

    int result = lca(root, B, C);
    if (result == -1) {
        cout << "One or both nodes are not present in the tree.\n";
    } else {
        cout << "The Least Common Ancestor of " << B << " and " << C << " is: " << result << endl;
    }

    return 0;
}
