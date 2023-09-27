#include <iostream>
#include <limits>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
} * head;

class BSearchTree
{
public:
    BSearchTree()
    {
        head = NULL;
    }

    void add()
    {
        int data = _getUserInput("add what? ");

        if (data != -1)
        {
            Node *node = new Node;
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            _addNode(node);
        }
        else
            _showMessage("invalid input");
    }

    void remove()
    {
        int data = _getUserInput("remove what? ");

        if (data != -1)
        {
            int pos = _searchNode(data);

            if (pos != 0)
                _removeNode(data);
        }
        else
            _showMessage("invalid input");
    }

    void search()
    {
        int data = _getUserInput("search what? ");

        if (data != -1)
        {
            int pos = _searchNode(data);

            if (pos > 0)
            {
                string msg = to_string(data) + " found at pos " + to_string(pos);
                _showMessage(msg);
            }
        }
        else
            _showMessage("invalid input");
    }

    void display(Node *node = head)
    {
        if (node == NULL)
        {
            return;
        }
        display(node->left);
        cout << node->data << " ";
        display(node->right);
    }

private:
    int _getUserInput(string msg) const
    {
        int data;
        cout << msg;
        try
        {
            cin >> data;
            if (cin.good())
                return data;
            else
                throw runtime_error("invalid");
        }
        catch (const std::exception &e)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
    }

    bool _isTreeEmpty()
    {
        return head == NULL;
    }

    void _showMessage(string msg)
    {
        cout << msg << endl;
    }

    Node *_findMinimum(Node *node)
    {
        if (node->left != NULL)
            return _findMinimum(node->left);
        else
            return node;
    }

    void _addNode(Node *node, Node *flag = head)
    {
        if (_isTreeEmpty())
        {
            head = node;
        }
        else
        {
            if (node->data < flag->data)
            {
                bool haveleftChild = flag->left != NULL;
                if (haveleftChild)
                {
                    _addNode(node, flag->left);
                }
                else
                {
                    flag->left = node;
                }
            }
            else if (node->data >= flag->data)
            {
                bool haveRightChild = flag->right != NULL;
                if (haveRightChild)
                {
                    _addNode(node, flag->right);
                }
                else
                {
                    flag->right = node;
                }
            }
        }
    }

    void _removeNode(int data, Node *flag = head, Node *parent = head, int pos = 1)
    {
        if (_isTreeEmpty())
        {
            _showMessage("tree empty");
            return;
        }
        else if (flag == NULL)
        {
            _showMessage("node not found");
            return;
        }
        else
        {
            if (data == flag->data)
            {
                bool haveNoChild = flag->left == NULL && flag->right == NULL;
                bool haveOneChild = (flag->left != NULL && flag->right == NULL) || (flag->left == NULL && flag->right != NULL);
                bool haveTwoChild = flag->left != NULL && flag->right != NULL;

                if (haveNoChild)
                {
                    if (flag == head)
                    {
                        head = NULL;
                    }
                    else if (parent->left == flag)
                    {
                        parent->left = NULL;
                    }
                    else if (parent->right == flag)
                    {
                        parent->right = NULL;
                    }
                    free(flag);
                }
                else if (haveOneChild)
                {
                    Node *child = (flag->left) ? flag->left : flag->right;

                    if (flag == head)
                        head = child;
                    else if (parent->left == flag)
                        parent->left = child;
                    else if (parent->right == flag)
                        parent->right = child;
                    free(flag);
                }
                else if (haveTwoChild)
                {
                    Node *min = _findMinimum(flag->right);
                    int val = min->data;
                    _removeNode(min->data, head, head, 1);
                    flag->data = val;
                }
                cout << data << " removed, pos " << pos << endl;
            }
            else if (data < flag->data)
                _removeNode(data, flag->left, flag, 2 * pos);
            else if (data > flag->data)
                _removeNode(data, flag->right, flag, 2 * pos + 1);
        }
    }

    int _searchNode(int data, int pos = 1, Node *flag = head)
    {
        if (_isTreeEmpty())
        {
            _showMessage("tree empty");
            return -1;
        }
        else if (flag == NULL)
        {
            _showMessage("node not found");
            return -1;
        }
        else
        {
            if (data == flag->data)
                return pos;
            else if (data < flag->data)
                _searchNode(data, 2 * pos, flag->left);
            else if (data > flag->data)
                _searchNode(data, 2 * pos + 1, flag->right);
        }
    }
};

int main()
{
    BSearchTree bst = BSearchTree();
    bst.add();
    bst.add();
    bst.add();
    bst.add();
    bst.add();
    bst.display();

    bst.remove();

    bst.display();
    bst.remove();
    bst.display();
    bst.remove();
    bst.display();
    return 0;
}