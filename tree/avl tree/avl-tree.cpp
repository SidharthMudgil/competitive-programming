#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    int key;
    int height;
    Node *left;
    Node *right;
    Node *parent;
} * head;

class AVLTree
{
public:
    AVLTree()
    {
        head = NULL;
    }

    void insert()
    {
        int data = input("add what? ");

        if (data != -1)
        {
            Node *node = createNode(data);
            _insertNode(node);
        }
        else
            showMessage("invalid input");
    }

    void remove()
    {
        int data = input("remove what? ");

        if (data != -1)
            _removeNode(data);
        else
            showMessage("invalid input");
    }

    void search()
    {
        int data = input("search what? ");

        if (data != -1)
        {
            int pos = _searchNode(data);

            if (pos > 0)
            {
                string msg = to_string(data) + " found at pos " + to_string(pos);
                showMessage(msg);
            }
        }
        else
            showMessage("invalid input");
    }

    void display()
    {
        printTree(head, "", true);
    }

protected:
    int input(string msg = "key? ")
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

    void showMessage(string msg)
    {
        cout << msg << endl;
    }

    bool isTreeEmpty()
    {
        return head == NULL;
    }

    Node *createNode(int val)
    {
        Node *node = new Node;
        node->key = val;
        node->left = NULL;
        node->right = NULL;
        node->parent = NULL;

        return node;
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int left = getHeight(node->left);
            int right = getHeight(node->right);
            return 1 + max(left, right);
        }
    }

    void printTree(Node *node, string indent, bool last)
    {
        if (node != NULL)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            int parent = -1;
            if (node->parent != NULL)
                parent = node->parent->key;
            cout << node->key << " " << parent << endl;
            printTree(node->left, indent, false);
            printTree(node->right, indent, true);
        }
    }

private:
    Node *_findMinimum(Node *node)
    {
        if (node->left != NULL)
            return _findMinimum(node->left);
        else
            return node;
    }

    Node *rotateLeft(Node *node)
    {
        Node *parent = node->parent;
        Node *child = node->left;
        Node *temp = child->right;

        node->parent = child;
        node->left = child->right;
        if (child->right != NULL)
            child->right->parent = node;
        child->right = node;
        child->parent = parent;

        if (parent != NULL)
        {
            if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
        }

        return child;
    }

    Node *rotateRight(Node *node)
    {
        Node *parent = node->parent;
        Node *child = node->right;
        Node *child_left = child->left;

        node->parent = child;
        node->right = child_left;
        if (child_left != NULL)
            child_left->parent = node;
        child_left = node;
        child->parent = parent;

        if (parent != NULL)
        {
            if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
        }

        return child;
    }

    void rebalance(Node *node)
    {
        // cout << "balancing... " << node->key << endl;
        int difference = getHeight(node->left) - getHeight(node->right);

        if (difference > 1)
        {
            if (getHeight(node->left->left) >= getHeight(node->left->right))
            {
                node = rotateLeft(node);
            }
            else
            {
                node = rotateRight(node->left);
                rotateLeft(node->parent);
            }
        }
        else if (difference < -1)
        {
            if (getHeight(node->right->right) >= getHeight(node->right->left))
            {
                node = rotateRight(node);
            }
            else
            {
                node = rotateLeft(node->right);
                rotateRight(node->parent);
            }
        }

        if (node->parent == NULL)
            head = node;
    }

    void _insertNode(Node *node, Node *parent = head)
    {
        if (isTreeEmpty())
        {
            head = node;
        }
        else
        {
            if (node->key < parent->key)
            {
                if (parent->left == NULL)
                {
                    parent->left = node;
                    node->parent = parent;
                }
                else
                    _insertNode(node, parent->left);

                rebalance(parent);
            }
            else if (node->key >= parent->key)
            {
                if (parent->right == NULL)
                {
                    parent->right = node;
                    node->parent = parent;
                }
                else
                    _insertNode(node, parent->right);

                rebalance(parent);
            }
        }
    }
    void _removeNode(int data, Node *flag = head, int pos = 1)
    {
        if (isTreeEmpty())
        {
            showMessage("tree empty");
            return;
        }
        else if (flag == NULL)
        {
            showMessage("node not found");
            return;
        }
        else
        {
            if (data == flag->key)
            {
                bool haveNoChild = flag->left == NULL && flag->right == NULL;
                bool haveOneChild = (flag->left != NULL && flag->right == NULL) || (flag->left == NULL && flag->right != NULL);
                bool haveTwoChild = flag->left != NULL && flag->right != NULL;
                Node *parent = flag->parent;

                if (haveNoChild)
                {
                    Node *parent = flag->parent;

                    if (parent == NULL)
                        head = NULL;
                    else if (parent->left == flag)
                        parent->left = NULL;
                    else if (parent->right == flag)
                        parent->right = NULL;

                    flag->parent = NULL;
                    free(flag);
                }
                else if (haveOneChild)
                {
                    Node *parent = flag->parent;
                    Node *child = (flag->left) ? flag->left : flag->right;

                    if (parent == NULL)
                        head = child;
                    else if (parent->left == flag)
                        parent->left = child;
                    else if (parent->right == flag)
                        parent->right = child;

                    child->parent = parent;
                    flag->parent = NULL;
                    free(flag);
                }
                else if (haveTwoChild)
                {
                    Node *min = _findMinimum(flag->right);
                    int val = min->key;
                    _removeNode(min->key, head, 1);
                    flag->key = val;
                }
                cout << data << " removed, pos " << pos << endl;
                rebalance(parent);
            }
            else if (data < flag->key)
                _removeNode(data, flag->left, 2 * pos);
            else if (data > flag->key)
                _removeNode(data, flag->right, 2 * pos + 1);
        }
    }

    int _searchNode(int data, int pos = 1, Node *flag = head)
    {
        if (isTreeEmpty())
        {
            showMessage("tree empty");
            return -1;
        }
        else if (flag == NULL)
        {
            showMessage("node not found");
            return -1;
        }
        else
        {
            if (data == flag->key)
                return pos;
            else if (data < flag->key)
                _searchNode(data, 2 * pos, flag->left);
            else if (data > flag->key)
                _searchNode(data, 2 * pos + 1, flag->right);
        }
    }
};

int main()
{
    AVLTree avl = AVLTree();
    avl.insert();
    avl.insert();
    avl.insert();
    avl.insert();
    avl.insert();
    avl.insert();
    avl.display();
    avl.remove();
    return 0;
}