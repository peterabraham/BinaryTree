#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * Binary tree node.
 */
struct TreeNode
{
    int nData;
    TreeNode* pstLeftNode;
    TreeNode* pstRightNode;
};

/**
 * Binary tree class.
 */
class Tree
{
public:

    Tree();
    ~Tree();
    TreeNode*& Search( const int nData_i );
    int DeleteNode( const int nData_i );

    /**
     * Function to print the tree data(Inorder traversal).
     */
    inline void PrintTree()
    {
        Print( 0, m_pstRootNode );
    }

private:

    Tree::Tree( Tree& tree_i );
    Tree& operator=( Tree& tree_i );
    void AddNode( const int nData_i, TreeNode*& pstNode_i );
    void Print( const int nSpace_i, const TreeNode* pstNode_i );

    TreeNode* m_pstRootNode;
};

#endif // _BINARY_TREE_H_