/*
    btree.cpp
*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct BNode
{
    int data;
    BNode *left;
    BNode *right;

    //struct constructor
    BNode() : data(0), left(nullptr), right(nullptr){};
};

class BTree
{
public:
    BTree();
    ~BTree();

    void PostOrder();
    void InOrder();
    void PreOrder();
    void InsertNode(int val);
    void RemoveNode(int val);
    void RemoveAll(int val);
    BNode *FindNode(int key);

private:
    void __PostOrder(BNode *proot);
    void __InOrder(BNode *proot);
    void __PreOrder(BNode *proot);
    BNode *__InsertNode(BNode *proot, int val);
    BNode *__FindNode(BNode *proot, int key);
    void __RemoveNode(BNode *proot, int val);

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

    cout << " " << proot->data;
}

void BTree::PostOrder()
{
    __PostOrder(m_root);
    cout << endl;
}

void BTree::__InOrder(BNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    __InOrder(proot->left);
    cout << " " << proot->data;
    __InOrder(proot->right);
}

void BTree::InOrder()
{
    __InOrder(m_root);
    cout << endl;
}

void BTree::__PreOrder(BNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    cout << " " << proot->data;
    __PreOrder(proot->left);
    __PreOrder(proot->right);
}

void BTree::PreOrder()
{
    __PreOrder(m_root);
    cout << endl;
}

BNode *BTree::__FindNode(BNode *proot, int key)
{
    if (proot == NULL)
    {
        return nullptr;
    }

    if (proot->data > key)
    {
        return __FindNode(proot->left, key);
    }
    else if (proot->data < key)
    {
        return __FindNode(proot->right, key);
    }

    // find node proot
    return proot;
}

BNode *BTree::FindNode(int key)
{
    return __FindNode(m_root, key);
}

void BTree::__RemoveNode(BNode *proot, int val)
{
}

void BTree::RemoveNode(int val)
{
    __RemoveNode(m_root, val);
}

int main(int args, char **argv)
{
    int a[5] = {4, 3, 5, 2, 1};
    BTree b;

    for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        b.InsertNode(a[i]);
    }

    cout << "PreOrder:" << endl;
    b.PreOrder();

    cout << "InOrder:" << endl;
    b.InOrder();

    cout << "PostOrder:" << endl;
    b.PostOrder();

    BNode *n = b.FindNode(3);
    if (n)
    {
        cout << "n:" << n->data;
    }
    else
    {
        cout << "not find n!" << endl;
    }

    return 0;
}
