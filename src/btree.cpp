/*
    BinaryTree.cpp
*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct BinaryNode
{
    int data;
    BinaryNode *left;
    BinaryNode *right;

    //struct constructor
    BinaryNode() : data(0), left(nullptr), right(nullptr){};
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void PostOrder();
    void InOrder();
    void PreOrder();
    void InsertNode(int val);
    BinaryNode *FindNode(int key);

private:
    void __PostOrder(BinaryNode *proot);
    void __InOrder(BinaryNode *proot);
    void __PreOrder(BinaryNode *proot);
    BinaryNode *__InsertNode(BinaryNode *proot, int val);
    BinaryNode *__FindNode(BinaryNode *proot, int key);

    BinaryNode *m_root;
    size_t m_size;
};

BinaryTree::BinaryTree() : m_root(nullptr), m_size(0)
{
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::InsertNode(int val)
{
    m_root = __InsertNode(m_root, val);
}

BinaryNode *BinaryTree::__InsertNode(BinaryNode *proot, int val)
{
    //find null node
    if (proot == nullptr)
    {
        //new 不初始化， new()进行初始化
        BinaryNode *node = new BinaryNode();
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

void BinaryTree::__PostOrder(BinaryNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    __PostOrder(proot->left);
    __PostOrder(proot->right);

    cout << " " << proot->data;
}

void BinaryTree::PostOrder()
{
    __PostOrder(m_root);
    cout << endl;
}

void BinaryTree::__InOrder(BinaryNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    __InOrder(proot->left);
    cout << " " << proot->data;
    __InOrder(proot->right);
}

void BinaryTree::InOrder()
{
    __InOrder(m_root);
    cout << endl;
}

void BinaryTree::__PreOrder(BinaryNode *proot)
{
    if (proot == nullptr)
    {
        return;
    }

    cout << " " << proot->data;
    __PreOrder(proot->left);
    __PreOrder(proot->right);
}

void BinaryTree::PreOrder()
{
    __PreOrder(m_root);
    cout << endl;
}

BinaryNode *BinaryTree::__FindNode(BinaryNode *proot, int key)
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

BinaryNode *BinaryTree::FindNode(int key)
{
    return __FindNode(m_root, key);
}

int main(int args, char **argv)
{
    int a[5] = {4, 3, 5, 2, 1};
    BinaryTree b;

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

    BinaryNode *n = b.FindNode(3);
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
