/*
    btree.cpp
*/
#include <iostream>
#include <string>

using namespace std;

struct BNode
{
    int data;
    BNode *left;
    BNode *right;

    //struct constructor
    BNode() : data(0), left(nullptr), right(nullptr) {};
};

class BTree
{
public:
    BTree();
    ~BTree();

    void PostOrder();
    void InsertNode(int val);
    void DeleteNode(int val);
    BNode *FindNode(int key);

private:
    BNode *__InsertNode(BNode *proot, int val);
    void __PostOrder(BNode *proot);
    void __DeleteNode(int val);
    BNode *__FindNode(BNode *proot, int key);

    BNode *m_root;
    size_t m_size;
};

BTree::BTree() : m_root(nullptr), m_size(0)
{
}

BTree::~BTree()
{
}

void BTree::InsertNode(int val)
{
    m_root = __InsertNode(m_root, val);
}

BNode *BTree::__InsertNode(BNode *proot, int val)
{
    //find null node
    if (proot == nullptr)
    {
        //new 不初始化， new()进行初始化
        BNode *node = new BNode();
        if (node != nullptr)
        {
            node->data = val;
            proot = node;
            m_size += 1;
        }

        return proot;
    }

    if (val < m_root->data)
    {
        proot->left = __InsertNode(proot->left, val);
    }
    else if (val > proot->data)
    {
        proot->right = __InsertNode(proot->right, val);
    }

    //相等不插入
    return proot;
}

void BTree::__PostOrder(BNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    __PostOrder(proot->left);
    __PostOrder(proot->right);

    cout << "data:" << proot->data << endl;
}

void BTree::PostOrder()
{
    __PostOrder(m_root);
}

int main(int args, char **argv)
{
    int a[5] = {1, 2, 3, 4, 5};
    BTree b;

    for (size_t i = 1; i <= sizeof(a) / sizeof(int); i++)
    {
        b.InsertNode(i);
    }

    b.PostOrder();

    return 0;
}
