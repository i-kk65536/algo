#include <iostream>
#include <vector>
#include <string>
#define NIL nullptr
using namespace std;

class Tree
{
private:
    struct Node
    {
        int key;
        Node* left;
        Node* right;
    
        Node(int k, Node* l = NIL, Node* r = NIL) : key(k), left(l), right(r) {}
    };
    
    Node* root;

    Node* findMinimum(Node* node)
    {
        while (node->left != NIL)
        {
            node = node->left;
        }
        return node;
    }
    
    // 再帰的にノードを挿入するヘルパー関数
    Node* insertNodeHelper(Node* current, int key)
    {
        if (current == NIL)
        {
            return new Node(key);
        }

        if (key < current->key)
        {
            current->left = insertNodeHelper(current->left, key);
        }
        else if (key > current->key)
        {
            current->right = insertNodeHelper(current->right, key);
        }

        return current;
    }

    // 再帰的にノードを探索するヘルパー関数
    bool findHelper(Node* current, int key)
    {
        if (current == NIL)
        {
            return false;
        }
        if (current->key == key)
        {
            return true;
        }
        else if (key < current->key)
        {
            return findHelper(current->left, key);
        }
        else
        {
            return findHelper(current->right, key);
        }
    }

    // 再帰的にノードを削除するヘルパー関数
    Node* deleteNodeHelper(Node* current, int key)
    {
        if (current == NIL)
        {
            return current;
        }

        // ノードkを探す
        if (key < current->key)
        {
            current->left = deleteNodeHelper(current->left, key);
        }
        else if (key > current->key)
        {
            current->right = deleteNodeHelper(current->right, key);
        }
        // ノードkが見つかった場合
        else
        {
            // ケース1：子がいない場合
            if (current->left == NIL && current->right == NIL)
            {
                delete current;
                return NIL;
            }
            // ケース2：子が1つの場合
            else if (current->left == NIL)
            {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == NIL)
            {
                Node* temp = current->left;
                delete current;
                return temp;
            }
            // ケース3：子が2つある場合
            else
            {
                Node* temp = findMinimum(current->right);
                current->key = temp->key;
                current->right = deleteNodeHelper(current->right, temp->key);
            }
        }

        return current;
    }
    
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
    
    void FreeNode(Node* node)
    {
        if (node == NIL)
            return;

        FreeNode(node->left);
        FreeNode(node->right);
        delete node;
    }

public:
    Tree() : root(NIL) {}
    
    ~Tree()
    {
        FreeNode(root);
    }
    
    void insertKey(int key) {
        if (root == NIL)
        {
            root = new Node(key);
        }
        else
        {
            insertNodeHelper(root, key);
        }
    }

    bool find(int k)
    {
        return findHelper(root, k);
    }
    
    void deleteKey(int k)
    {
        root = deleteNodeHelper(root, k);
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

int main() {
    Tree tree;
    int cmd_num;
    cin >> cmd_num;
    for (int i = 0; i < cmd_num; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            int num;
            cin >> num;
            tree.insertKey(num);
        } else if (cmd == "find") {
            int num;
            cin >> num;
            bool exist = tree.find(num);
            cout << (exist ? "yes" : "no") << endl;
        } else if (cmd == "delete") {
            int num;
            cin >> num;
            tree.deleteKey(num);
        } else if (cmd == "print") {
            tree.print();
        }
    }
    return 0;
}

