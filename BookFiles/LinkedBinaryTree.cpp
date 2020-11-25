#include "LinkedBinaryTree.h"

LinkedBinaryTree::LinkedBinaryTree()			// constructor
    : _root(NULL), n(0) { }

int LinkedBinaryTree::size() const			// number of nodes
{
    return n;
}
bool LinkedBinaryTree::empty() const			// is tree empty?
{
    return size() == 0;
}
LinkedBinaryTree::Position LinkedBinaryTree::root() const // get the root
{
    return Position(_root);
}

void LinkedBinaryTree::addRoot()			// add root to empty tree
{
    _root = new Node; n = 1;
}

// list of all nodes
LinkedBinaryTree::PositionList LinkedBinaryTree::positions(std::string option) const {
    PositionList pl;

    if (option == "preorder") {
        preorder(_root, pl);					// preorder traversal
        return PositionList(pl);				// return resulting list
    }
    else if (option == "postorder") {
        postorder(_root, pl);                   // postorder traversal
        return PositionList(pl);
    }
    else if (option == "inorder") {
        inorder(_root, pl);                     // inorder traversal
        return PositionList(pl);
    }
    else {
        preorder(_root, pl);                    // default postorder traversal
        return PositionList(pl);
    }
}
// preorder traversal
void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));				// add this node
    if (v->left != NULL)					// traverse left subtree
        preorder(v->left, pl);
    if (v->right != NULL)					// traverse right subtree
        preorder(v->right, pl);
}
// inorder traversal
void LinkedBinaryTree::inorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)
        inorder(v->left, pl);               // traverse left subtree
    
    pl.push_back(Position(v));              // add this node
    if (v->right != NULL)                   // traverse right subtree
        inorder(v->right, pl);
    
}
// postorder traversal
void LinkedBinaryTree::postorder(Node* v, PositionList& pl) const
{
    if (v->left != NULL)
        postorder(v->left, pl);             // traverse left subtree
    if (v->right != NULL)
        postorder(v->right, pl);            // traverse right subtree
    pl.push_back(Position(v));              // add this node
}

LinkedBinaryTree::Position				// remove p and parent
LinkedBinaryTree::removeAboveExternal(const Position& p) {
    Node* w = p.v;  Node* v = w->par;			// get p's node and parent
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {					// child of root?
        _root = sib;					// ...make sibling root
        sib->par = NULL;
    }
    else {
        Node* gpar = v->par;				// w's grandparent
        if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
        else gpar->right = sib;
        sib->par = gpar;
    }
    delete w; delete v;					// delete removed nodes
    n -= 2;						// two fewer nodes
    return Position(sib);
}

// insert item at p
// if their is an item already at p then the item will be inserted
// either to the left or right node of p
void LinkedBinaryTree::insert(const Elem& e, Position& p)
{
    Node* v = p.v;                  // get p's node

    if (empty()) {                  
        addRoot();                  // if tree is empty add a root node
        v = _root;                  // set v to the root node
        v->elt = e;                 // assign e to v's element
        v->par = NULL;              // point v's parent to null
        p.v = v;                    // point v back to p for later reference
        expandExternal(v);          // expand the tree 
    }
    else {
        v->elt = e;                 // assign e to v's element
        v->par = NULL;              // point v's parent to null
        p.v = v;                    // point v back to p
    }
}

// insert item in left child of p
void LinkedBinaryTree::insertLeft(const Elem& e, const Position& p)
{
    Node* v = p.v;                  // get p's node
    if (v->left == NULL) {          
        expandExternal(v);          // if the left node of p is empty
        insertLeft(e, v);           // expand subtree and insert element
    }
    else
    {
        v->left->elt = e;           // assign e v's left child's element
        v->left->par = v;           // point v's left child parent to v
    }
}

// insert item in right child of p
void LinkedBinaryTree::insertRight(const Elem& e, const Position& p)
{
    Node* v = p.v;                  // get p's node
    if (v->right == NULL) {
        expandExternal(v);          // if the right node of p is empty
        insertRight(e, v);          // expand subtree and insert element
    }
    else
    {
        v->right->elt = e;          // assign e v's right child's element
        v->right->par = v;          // point v's right child parent to v
    }
}

// prints list of tree according to traversal option provided
// preorder, postorder, inorder
void LinkedBinaryTree::print(std::string option)
{
    PositionList list = positions(option);          // get position list by the traversal option

    PositionList::iterator it;
    for (it = list.begin(); it != list.end(); ++it) {
        Position p = *it;                           // iterate through list and print each element
        std::cout << " " << *p;
    }
}

// expand external node
void LinkedBinaryTree::expandExternal(const Position& p) {
    Node* v = p.v;					// p's node
    v->left = new Node;					// add a new left child
    v->left->par = v;					// v is its parent
    v->right = new Node;				// and a new right child
    v->right->par = v;					// v is its parent
    n += 2;						// two more nodes
}