//
//  WordTree.h
//  Homework4
//
//  Created by I-Lin Wu on 2019/8/18.
//  Copyright © 2019 I-Lin Wu. All rights reserved.
//

#ifndef WordTree_h
#define WordTree_h

#include <iostream>
#include <string>
using namespace std;

typedef string IType;

struct WordNode
{
    IType m_data;
    WordNode *m_left;
    WordNode *m_right;
    // You may add additional data members and member functions
    // in WordNode
    int m_count;
    WordNode(IType word)
    : m_data(word), m_left(nullptr), m_right(nullptr), m_count(1)
    { } ;
};

class WordTree
{
private:
    WordNode *root;
    void copyWordTree(WordNode*& thisNode, WordNode* otherNode);
    void distinctWords_auxiliary(int& count, WordNode* n) const;
    void totalWords_auxiliary(int& count, WordNode* n) const;
    friend void print(ostream& out, WordNode* n);
    void deleteTree(WordNode* n);
public:
    // default constructor
    WordTree() : root(nullptr) { };
    
    // copy constructor
    WordTree(const WordTree& rhs);
    
    // assignment operator
    const WordTree& operator=(const WordTree& rhs);
    // Inserts v into the WordTree
    void add(IType v);
    // Returns the number of distinct words / nodes
    int distinctWords() const;
    // Returns the total number of words inserted, including
    // duplicate values
    int totalWords() const;
    
    // Prints the LinkedList
    friend ostream& operator<<(ostream& out, const WordTree& rhs);
    // Destroys all the dynamically allocated memory in the
    // tree
    ~WordTree();
};

#endif /* WordTree_h */
