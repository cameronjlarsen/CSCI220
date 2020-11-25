#include <list>
#include <string>
#include <iostream>

typedef std::string Elem;					// base element type
class LinkedBinaryTree {
protected:
    struct Node {					// a node of the tree
        Elem    elt;					// element value
        Node* par;					// parent
        Node* left;					// left child
        Node* right;				// right child
        Node() : elt(), par(NULL), left(NULL), right(NULL) { } // constructor
    };
public:
    class Position {					// position in the tree
    private:
        Node* v;						// pointer to the node
    public:
        Position(Node* _v = NULL) : v(_v) { }		// constructor
        Elem& operator*()					// get element
        {
            return v->elt;
        }
        Position left() const				// get left child
        {
            return Position(v->left);
        }
        Position right() const				// get right child
        {
            return Position(v->right);
        }
        Position parent() const				// get parent
        {
            return Position(v->par);
        }
        bool isRoot() const				// root of the tree?
        {
            return v->par == NULL;
        }
        bool isExternal() const				// an external node?
        {
            return v->left == NULL && v->right == NULL;
        }
        friend class LinkedBinaryTree;			// give tree access
    };
    typedef std::list<Position> PositionList;		// list of positions
public:
    LinkedBinaryTree();					// constructor
    int size() const;					// number of nodes
    bool empty() const;					// is tree empty?
    Position root() const;				// get the root
    PositionList positions(std::string option) const;   // list of nodes
    void addRoot();					// add root to empty tree
    void expandExternal(const Position& p);		// expand external node
    Position removeAboveExternal(const Position& p);	// remove p and parent
    void insert(const Elem& e, Position& p);            // insert item at p
    void insertLeft(const Elem& e, const Position& p);        // insert item in left child of p
    void insertRight(const Elem& e, const Position& p);       // insert item in right child of p
    void print(std::string option);               // print the tree
protected: 						// local utilities
    void preorder(Node* v, PositionList& pl) const;	// preorder utility
    void inorder(Node* v, PositionList& pl) const; // inorder utility
    void postorder(Node* v, PositionList& pl) const; // postorder utility
private:
    Node* _root;					// pointer to the root
    int n;						// number of nodes
};