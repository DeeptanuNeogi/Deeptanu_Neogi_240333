#include <iostream>
#include <vector>
#include<queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> inorderIndexMap;

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);


        int inIndex = inorderIndexMap[rootVal];

        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndexMap[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1; 
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }
};


void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current) {
            cout << current->val << " ";
            q.push(current->left);
            q.push(current->right);
        }
    }
    cout << endl;
}

int main() {
    Solution solution;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    cout << "Enter the postorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    TreeNode* root = solution.buildTree(inorder, postorder);

    cout << "Level order traversal of the constructed tree: ";
    printLevelOrder(root);

    return 0;
}
