#include <iostream>
#include <limits>

using namespace std;

namespace cases
{
    enum rcase
    {
        NO_CHILD = 1,
        ONE_CHILD = 2,
        TWO_CHILD = 3
    };
}

class BSearchTree
{
    const int _size;
    int tree[100];

    int _getData(string msg = "enter data(-1 to cancel): ")
    {
        int data;
        cout << msg;
        try
        {
            cin >> data;
            if (cin.good())
                return data;
            else
                throw runtime_error("data cancelled");
        }
        catch (const exception &err)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return -1;
        }
    }

    bool _treeEmpty()
    {
        return tree[1] == -1;
    }

    const int _getCase(int pos)
    {
        if (tree[2 * pos] == -1 && tree[2 * pos + 1] == -1)
        {
            return 1;
        }
        else if (tree[2 * pos] != -1 && tree[2 * pos + 1] != -1)
        {
            return 3;
        }
        else
        {
            return 2;
        }
    }

    int _getInorderSuccessor(int pos)
    {
        int flag = 2 * (2 * pos + 1);
        bool isEmpty = false;

        if (tree[flag] != -1)
        {
            while (true)
            {
                flag = 2 * flag;
                if (tree[2 * flag] == -1)
                {
                    break;
                }
            }
            return flag;
        }
        else
        {
            return 2 * pos;
        }
    }

    void _add(int data, int pos = 1)
    {
        if (_treeEmpty())
        {
            cout << data << " added at pos: " << pos << endl;
            tree[pos] = data;
        }
        else if (pos > _size)
        {
            return;
        }
        else
        {
            if (tree[pos] != -1)
            {
                if (data < tree[pos])
                {
                    _add(data, 2 * pos);
                }
                else if (data >= tree[pos])
                {
                    _add(data, 2 * pos + 1);
                }
            }
            else
            {
                tree[pos] = data;
                cout << data << " added at pos: " << pos << endl;
                return;
            }
        }
    }

    void _remove(int pos)
    {
        if (pos > _size)
            return;
        else
        {
            int rcase = _getCase(pos);

            switch (rcase)
            {
            case cases::NO_CHILD:
            {
                cout << tree[pos] << " deleted with flag " << pos << endl;
                tree[pos] = -1;
                break;
            }

            case cases::ONE_CHILD:
            {
                int mPos;

                if (tree[2 * pos] != -1)
                {
                    mPos = 2 * pos;
                }
                else if (tree[2 * pos + 1] != -1)
                {
                    mPos = 2 * pos + 1;
                }
                cout << tree[pos] << " deleted" << endl;
                tree[pos] = tree[mPos];
                tree[mPos] = -1;
                break;
            }

            case cases::TWO_CHILD:
            {
                int in_successor = _getInorderSuccessor(pos);
                cout << tree[pos] << " deleted" << endl;
                tree[pos] = tree[in_successor];
                tree[in_successor] = -1;
                break;
            }

            default:
                cout << "something went wrong" << endl;
                break;
            }
        }
    }

    int _search(int data, int pos = 1)
    {
        if (_treeEmpty())
        {
            cout << "tree empty" << endl;
            return -1;
        }
        else if (pos > _size)
        {
            cout << "node not found" << endl;
            return -1;
        }
        else
        {
            if (tree[pos] != -1)
            {
                if (tree[pos] == data)
                {
                    return pos;
                }
                else if (data < tree[pos])
                {
                    _search(data, 2 * pos);
                }
                else if (data >= tree[pos])
                {
                    _search(data, 2 * pos + 1);
                }
            }
        }
    }

public:
    BSearchTree(int m) : _size(m + 1)
    {
        fill(tree, tree + 101, -1);
    }

    void add()
    {
        int data = _getData();

        if (data == -1)
            cout << "data cancelled" << endl;
        else
            _add(data);
    }

    void add(int data)
    {
        _add(data);
    }

    void remove()
    {
        int data = _getData("remove what? ");

        if (data == -1)
            cout << "invalid input" << endl;
        else
        {
            int flag = _search(data);
            if (flag == -1)
                cout << "either empty_tree or node_not_found" << endl;

            _remove(flag);
        }
    }

    void search()
    {
        int data = _getData("search what? ");

        if (data == -1)
            cout << "invalid input" << endl;
        else
        {
            int pos = _search(data);

            if (pos != -1)
                cout << data << " found at pos: " << pos << endl;
        }
    }

    void display()
    {
        cout << endl;
        for (int i = 1; i <= _size; i++)
        {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BSearchTree bst = BSearchTree(15);

    int data[15] = {45, 15, 79, 90, 10, 55, 12, 20, 50, 27, 74, 99, 84, 5, 11};

    for (int val : data)
    {
        bst.add(val);
    }

    bst.display();
    bst.remove();
    bst.display();
    bst.remove();
    bst.display();
    bst.remove();
    bst.display();
    bst.remove();
    bst.display();
    bst.remove();
    bst.display();

    return 0;
}
