#include <iostream>
#include <vector>
#define NIL nullptr
using namespace std;

class Tree
{
private:
    struct Node
    {
    public:
        int key;
        Node* left;
        Node* right;

        Node(int k, Node* l = NIL, Node* r = NIL) : key(k), left(l), right(r) {}
    };

    Node* root;
    
    vector<int> InOrder(Node* root)
    {
        vector<int> inorder_list;
        if (root == NIL)
            return inorder_list;

        vector<int> left = InOrder(root->left);
        inorder_list.insert(inorder_list.end(), left.begin(), left.end());
        
        inorder_list.emplace_back(root->key);
        
        vector<int> right = InOrder(root->right);
        inorder_list.insert(inorder_list.end(), right.begin(), right.end());

        return inorder_list;
    }

    vector<int> PreOrder(Node* root)
    {
        vector<int> preorder_list;
        if (root == NIL)
            return preorder_list;

        preorder_list.emplace_back(root->key);

        vector<int> left = PreOrder(root->left);
        preorder_list.insert(preorder_list.end(), left.begin(), left.end());

        vector<int> right = PreOrder(root->right);
        preorder_list.insert(preorder_list.end(), right.begin(), right.end());

        return preorder_list;
    }

    void DeleteNode(Node* node)
    {
        if (node == NIL)
            return;

        DeleteNode(node->left);
        DeleteNode(node->right);
        delete node;
    }

public:
    Tree() : root(NIL) {}

    ~Tree()
    {
        DeleteNode(root);
    }

    void insert(int key)
    {
        Node* new_node = new Node(key);
        Node* parent = NIL;
        Node* current = root;

        while (current != NIL)
        {
            parent = current;
            if (new_node->key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        
        if (parent == NIL)
            root = new_node;
        else if (new_node->key < parent->key)
            parent->left = new_node;
        else
            parent->right = new_node;
    }

    void print()
    {
        for (const auto& key : InOrder(root))
            cout << " " << key;
        cout << endl;
        for (const auto& key : PreOrder(root))
            cout << " " << key;
        cout << endl;
    }
};

int main()
{
    Tree tree;
    int cmd_num;
    cin >> cmd_num;
    for (int i = 0; i < cmd_num; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "insert")
        {
            int num;
            cin >> num;
            tree.insert(num);
        }
        if (cmd == "print")
        {
            tree.print();
        }
    }
}
