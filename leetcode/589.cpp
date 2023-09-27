// USER: SIDHARTH MUDGIL
// DATE: Sunday 22, Jan 2023
// TASK: 589. N-ary Tree Preorder Traversal

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<int> preorder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    vector<int> res;

    while (!st.empty() && st.top())
    {
        Node *node = st.top();
        st.pop();
        res.push_back(node->val);

        for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
            if (*it != nullptr)
                st.push(*it);
    }

    return res;
}

int main()
{
    return 0;
}