#include "BinaryTree.h"
#include <iomanip>

/**
 * Constructor of Binary tree class.
 */
Tree::Tree() : m_pstRootNode( NULL )
{
    int nData = 0;
    char ch;
    cout << "Enter tree elements" << endl;
    while( cin >> nData, !cin.fail())
    {
        AddNode( nData, m_pstRootNode );
    }
    cin.clear();
    cin.get( ch );
}


/**
 * Destructor of Binary tree class.
 */
Tree::~Tree()
{
}


/**
 * Function to perform binary search and return
 * the corresponding tree node.
 */
TreeNode*& Tree::Search( const int nData_i )
{
    TreeNode** pstNode = &m_pstRootNode;
    while( 1 )
    {
        if( NULL == *pstNode )
        {
            return *pstNode;
        }
        else if( nData_i < ( *pstNode )->nData )
        {
            pstNode = &( *pstNode )->pstLeftNode;
        }
        else if( nData_i > ( *pstNode )->nData )
        {
            pstNode = &( *pstNode )->pstRightNode;
        }
        else
        {
            return *pstNode;
        }
    }
}


/**
 * Function to delete the input tree node.
 */
int Tree::DeleteNode( const int nData_i )
{
    TreeNode* &pstP = Search( nData_i );
    TreeNode* pstP0 = pstP;
    TreeNode** pstQQ = NULL;
    TreeNode* pstQ = NULL;

    if( NULL == pstP )
    {
        return 0;
    }
    else if( NULL == pstP->pstRightNode )
    {
        pstP = pstP->pstLeftNode;
        delete pstP0;
    }
    else if( NULL == pstP->pstLeftNode )
    {
        pstP = pstP->pstRightNode;
        delete pstP0;
    }
    else
    {
        pstQQ = &pstP->pstLeftNode;
        while( NULL != ( *pstQQ )->pstRightNode )
        {
            pstQQ = &( *pstQQ )->pstRightNode;
        }
        pstP->nData = ( *pstQQ )->nData;
        pstQ = *pstQQ;
        *pstQQ = pstQ->pstLeftNode;
        delete pstQ;
    }
    return 1;
}


/**
 * Function to add a node to the tree.
 */
void Tree::AddNode( const int nData_i, TreeNode*& pstNode_i )
{
    if( NULL == pstNode_i )
    {
        pstNode_i = new TreeNode();
        pstNode_i->nData = nData_i;
        pstNode_i->pstLeftNode = pstNode_i->pstRightNode = NULL;
    }
    else
    {
        AddNode( nData_i, nData_i < pstNode_i->nData ? pstNode_i->pstLeftNode : pstNode_i->pstRightNode );
    }
}


/**
 * Function to print the tree data tree traversal.
 */
void Tree::Print( const int nSpace_i, const TreeNode* pstNode_i )
{
    if( pstNode_i )
    {
        Print( nSpace_i + 4, pstNode_i->pstRightNode );
        cout << setw( nSpace_i ) << pstNode_i->nData << endl;
        Print( nSpace_i + 4, pstNode_i->pstLeftNode );
    }
}


/**
 * Main function to demonstrate Binary Tree.
 **/
int main()
{
    Tree tree;
    cout << "\n*** Resulting Tree ***" << endl;
    tree.PrintTree();

    cout << "Enter the value of node to be deleted : " << endl;
    int nValue = 0;
    cin >> nValue;

    if( tree.DeleteNode( nValue ))
    {
        cout << "*** Tree after deleting ***" << endl;
        tree.PrintTree();
    }
    else
    {
        cout << "Node not found!!!..." << endl;
    }

    return 0;
}