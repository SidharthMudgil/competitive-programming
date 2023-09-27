/*
[1] Degree(t) of B-tree defines (max and min) no. of keys for a particular node. Degree is defined as minimum degree of B-tree.
[2] Predecessor of B-tree will be left most node in right subtree
[3] Successor of B-tree will be left most node in right subtree
*/
#include <iostream>

class Node
{
private:
    int *keys;      // pointer-array to store keys
    Node **childs;  // pointer-array to store pointer to the child
    int no_of_keys; // current number of keys
    int t;          // minimum degree of btree  [1]
    bool leaf;      // boolean to tell if it's leaf node or not

    void split(int i, Node *child)
    {
        Node *r_child = new Node(child->t, child->leaf); // create a new r_child
        r_child->no_of_keys = t - 1;
        for (int j = 0; j < t - 1; j++) // copy all the keys from median to r_child node
            r_child->keys[j] = child->keys[j + t];

        if (!leaf) // if child is not leaf copy all the childs from median to r_child
            for (int j = 0; j < t; j++)
                r_child->childs[j] = child->childs[j + t];

        child->no_of_keys = t - 1;

        for (int j = no_of_keys; j > i; j--) // move all childs after pos i one step ahead
            childs[j + 1] = childs[j];

        childs[i + 1] = r_child; // add r_child to childs

        for (int j = no_of_keys - 1; j >= i; j--) // // move all keys after pos i one step ahead
            keys[j + 1] = keys[j];

        keys[i] = child->keys[t - 1]; // add median of the child as key
        no_of_keys++;
    }

    int get_predecessor(int pos)
    {
        Node *curr = childs[pos];
        while (!curr->leaf)
            curr = curr->childs[curr->no_of_keys];

        return curr->keys[curr->no_of_keys - 1];
    }

    int get_successor(int pos)
    {
        Node *curr = childs[pos];
        while (!curr->leaf)
            curr = curr->childs[0];

        return curr->keys[0];
    }

    void remove_from_leaf(int pos)
    {
        while (pos < no_of_keys - 1)
        {
            keys[pos] = keys[pos + 1];
            pos++;
        }
        no_of_keys--;
    }

    void fill(int pos)
    {
        if (pos != 0 && childs[pos - 1]->no_of_keys >= t) // borrow from previous
        {
            Node *child = childs[pos];
            Node *sibling = childs[pos - 1];

            for (int i = child->no_of_keys; i > 0; i--)
                child->keys[i] = child->keys[i - 1];
            child->keys[0] = keys[pos - 1];

            if (!child->leaf)
                for (int i = child->no_of_keys + 1; i > 0; i--)
                    child->childs[i] = child->childs[i - 1];
            child->childs[0] = sibling->childs[sibling->no_of_keys];

            keys[pos - 1] = sibling->keys[sibling->no_of_keys - 1];

            sibling->no_of_keys--;
            child->no_of_keys++;
        }
        else if (pos != no_of_keys && childs[pos + 1]->no_of_keys >= t) // borrow from next
        {
            Node *child = childs[pos];
            Node *sibling = childs[pos + 1];

            child->keys[no_of_keys] = keys[pos];

            if (!child->leaf)
                child->childs[child->no_of_keys + 1] = sibling->childs[0];

            keys[pos] = sibling->keys[0];

            for (int i = 0; i < sibling->no_of_keys - 1; i++)
                sibling->keys[i] = sibling->keys[i + 1];

            if (!sibling->leaf)
                for (int i = 0; i < sibling->no_of_keys; i++)
                    sibling->childs[i] = sibling->childs[i + 1];

            sibling->no_of_keys--;
            child->no_of_keys++;
        }
        else
        {
            if (pos != no_of_keys)
                merge(pos);
            else
                merge(pos - 1);
        }
    }

    void merge(int pos)
    {
        Node *child = childs[pos];
        Node *sibling = childs[pos + 1];

        child->keys[no_of_keys] = keys[pos];
        child->no_of_keys++;

        for (int i = 0; i < sibling->no_of_keys; i++)
        {
            child->keys[i + t] = sibling->keys[i];
            child->no_of_keys++;
        }

        if (!child->leaf)
            for (int i = 0; i < sibling->no_of_keys + 1; i++)
                child->childs[i + t] = sibling->childs[i];

        for (int i = pos; i < no_of_keys - 1; i++)
            keys[i] = keys[pos + 1];

        for (int i = pos + 1; i < no_of_keys; i++)
            child[i] = child[pos + 1];

        no_of_keys--;
    }

    void remove_from_nonLeaf(int pos)
    {
        if (childs[pos]->no_of_keys > t - 1) // if left child have more than minimum no. of keys [2]
        {
            int k = get_predecessor(pos);
            keys[pos] = k;
            childs[pos]->remove(k);
        }
        else if (childs[pos + 1]->no_of_keys > t - 1) // if right child have more than minimum no. of keys [3]
        {
            int k = get_successor(pos + 1);
            keys[pos] = k;
            childs[pos + 1]->remove(k);
        }
        else // if none have minimum number of keys
        {
            int k = keys[pos];
            merge(pos);
            childs[pos]->remove(k);
        }
    }

public:
    Node(int _t, int isLeaf) : t(_t), leaf(isLeaf)
    {
        keys = new int[2 * t - 1];  // maximum keys = 2 * t - 1
        childs = new Node *[2 * t]; // maximum childs = 2 * t
        no_of_keys = 0;
    }

    void traverse()
    {
        int i;
        for (i = 0; i < no_of_keys; i++)
        {
            if (!leaf)
                childs[i]->traverse();

            std::cout << keys[i] << " ";
        }
        if (!leaf)
            childs[i]->traverse();
    }

    void insert(int k)
    {
        if (leaf) // if node is leaf directly add the key
        {
            int i = no_of_keys - 1;
            while (i >= 0 && k < keys[i]) // insertion in sorted array
            {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            no_of_keys++;
        }
        else
        { // if not search for the position
            int i = 0;
            while (i < no_of_keys && k > keys[i])
                i++;

            if (childs[i]->no_of_keys == 2 * t - 1) // split the child if already have maximum number of childs
            {
                split(i, childs[i]);
                if (k > keys[i])
                    i++;
            }

            childs[i]->insert(k); // call insert function for the child
        }
    }
    void remove(int k)
    {
        int pos = 0;
        while (k > keys[pos] && pos < no_of_keys)
            pos++;

        if (k == keys[pos] && pos < no_of_keys)
        {
            if (leaf)
                remove_from_leaf(pos);
            else
                remove_from_nonLeaf(pos);
        }
        else
        {
            if (leaf)
                std::cout << "key not found" << std::endl;
            else
            {
                if (childs[pos]->no_of_keys < t)
                    fill(pos);

                childs[pos]->remove(k);
            }
        }
    }
    void search(int k)
    {
        int i = 0;
        while (i < no_of_keys && k > keys[i])
            i++;

        if (i < no_of_keys && k == keys[i])
            std::cout << "Found";
        else if (leaf)
            std::cout << "Not Found";
        else
            childs[i]->search(k);
    }
    friend class BTree;
};

class BTree
{
private:
    Node *root;
    int t;

public:
    BTree(int _t) : t(_t), root(NULL) {}
    void insert_node(int k)
    {
        if (root == NULL)
        {
            root = new Node(t, true);
            root->keys[0] = k;
            root->no_of_keys = 1;
        }
        else
        {
            if (root->no_of_keys == 2 * t - 1)
            {
                Node *temp = new Node(t, false);
                temp->childs[0] = root;
                temp->split(0, root);
                int i = 0;
                if (k > temp->keys[0])
                    i++;
                temp->childs[i]->insert(k);
                root = temp;
            }
            else
                root->insert(k);
        }
    }
    void delete_node(int k)
    {
        if (root == NULL)
            std::cout << "Tree is empty" << std::endl;
        else
        {
            root->remove(k);

            if (root->no_of_keys == 0) // if root have no keys
            {
                Node *tmp = root;
                if (root->leaf) // if root is leaf means have no children
                    root = NULL;
                else // root have children replace root with first child, because there is only one key before deletion and should have only one child
                    root = root->childs[0];
                delete tmp;
            }
        }
    }
    void search_node(int k)
    {
        if (root == NULL)
            std::cout << "Tree is empty" << std::endl;
        else
            root->search(k);
    }
    void traverse_tree()
    {
        if (root == NULL)
            std::cout << "Tree is empty";
        else
            root->traverse();
        std::cout << std::endl;
    }
};

int main()
{
    BTree bt = BTree(3);
    bt.insert_node(2);
    bt.insert_node(4);
    bt.insert_node(5);
    bt.insert_node(6);
    bt.insert_node(7);
    bt.insert_node(1);
    bt.insert_node(3);
    bt.insert_node(8);
    bt.insert_node(9);
    bt.insert_node(10);
    bt.insert_node(11);
    bt.traverse_tree();

    bt.delete_node(5);
    bt.traverse_tree();

    bt.delete_node(8);
    bt.traverse_tree();
    return 0;
}
