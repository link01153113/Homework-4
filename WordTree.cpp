//
//  WordTree.cpp
//  Homework4
//
//  Created by I-Lin Wu on 2019/8/18.
//  Copyright © 2019 I-Lin Wu. All rights reserved.
//

#include "WordTree.h"

void WordTree::copyWordTree(WordNode*& n1, WordNode* n2)
{
    if (n2 == nullptr)
        n1 = nullptr;
    else
    {
        n1 = new WordNode(n2->m_data);
        n1->m_count = n2->m_count;
        copyWordTree(n1->m_left, n2->m_left);
        copyWordTree(n1->m_right, n2->m_right);
    }
}

WordTree::WordTree(const WordTree& rhs)
{
    if (rhs.root == nullptr)
        root = nullptr;
    else
        copyWordTree(root, rhs.root);
}

const WordTree& WordTree::operator=(const WordTree& rhs)
{
    copyWordTree(root, rhs.root);
    return *this;

}

void WordTree::add(IType v)
{
    if(root == nullptr)
        root = new WordNode(v);
    else
    {
        WordNode* p = root;
        while(p != nullptr)
        {
            if(p->m_data == v) //already word in tree, increase count
            {
                p->m_count++;
                return;
            }
            else if(v < p->m_data)
            {
                if(p->m_left == nullptr)
                {
                    p->m_left = new WordNode(v);
                    return;
                }
                else
                    p = p->m_left;
            }
            else
            {
                if(p->m_right == nullptr)
                {
                    p->m_right = new WordNode(v);
                    return;
                }
                else
                    p = p->m_right;
            }
        }
    }
}

void WordTree::distinctWords_auxiliary(int& count, WordNode* n) const
{
    if (n == nullptr)
        return;
    count++;
    distinctWords_auxiliary(count, n->m_left);
    distinctWords_auxiliary(count, n->m_right);
}

int WordTree::distinctWords() const
{
    int count = 0;
    if (root != nullptr)
        distinctWords_auxiliary(count, root);
    return count;
}

void WordTree::totalWords_auxiliary(int& count, WordNode* n) const
{
    if (n == nullptr)
        return;
    count += n->m_count;
    totalWords_auxiliary(count, n->m_left);
    totalWords_auxiliary(count, n->m_right);
}

int WordTree::totalWords() const
{
    int count = 0;
    if (root != nullptr)
        totalWords_auxiliary(count, root);
    return count;
}

void print(ostream& out, WordNode* n)
{
    if (n == nullptr)
        return;
    
    print(out, n->m_left);
    out << n->m_data << " " << n->m_count << endl;
    print(out, n->m_right);
}

ostream& operator<<(ostream& out, const WordTree& rhs)
{
    print(out, rhs.root);
    return out;
}

void WordTree::deleteTree(WordNode* n)
{
    if(n == nullptr)
        return;
    deleteTree(n->m_left);
    deleteTree(n->m_right);
    delete n;
}

WordTree::~WordTree()
{
    deleteTree(root);
}
