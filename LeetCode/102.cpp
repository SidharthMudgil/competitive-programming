// USER: SIDHARTH MUDGIL
// DATE: Monday 23, Jan 2023
// TASK: 102. Binary Tree Level Order Traversal

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode *root, int depth, vector<vector<int>> &res)
{
    if (root == NULL)
        return;
    if (res.size() == depth)
        res.push_back({});

    res[depth].push_back(root->val);

    if (root->left)
        traverse(root->left, depth + 1, res);
    if (root->right)
        traverse(root->right, depth + 1, res);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    traverse(root, 0, res);
    return res;
}

int main()
{
    return 0;
}