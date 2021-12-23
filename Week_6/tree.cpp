/*
1)	Define Node structure for a binary search tree 
2)	Write functions to 
-	Insert a node into the tree (Node) 
-	Delete the node from the tree (Node) 
-	Search a given node in the tree  
-	Traversal the tree  
3)	Study balance tree, AVL tree and prepare slides to present in the next lecture.  
*/

#include <iostream>
#include <assert.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
   // constructors
   Node(int value) : data(value), left(NULL), right(NULL)
   {};

   static void insertNodeToBst(Node* root, int value)
   {
      if (root == NULL)
      {
         root = new Node(value);
         return;
      }
      if (value >= root->data)
      {
         if (root->right == NULL)
            root->right = new Node(value);
         else
            insertNodeToBst(root->right, value);
      }
      else
      {
         if (root->left == NULL)
            root->left = new Node(value);
         else
            insertNodeToBst(root->left, value);
      }
   }

   static void travelPreOrder(ostream &os, Node *root)
   {
      if (!root)
         return;
      os << *root << " ";
      travelPreOrder(os, root->left);
      travelPreOrder(os, root->right);
   }

   static void travelInOrder(ostream &os, Node *root)
   {
      if (!root) 
         return;
      travelInOrder(os, root->left);
      os << *root << " ";
      travelInOrder(os, root->right);
   }
   
   static void travelPostOrder(ostream &os, Node *root)
   {
      if (!root) 
         return;
      travelPostOrder(os, root->left);
      travelPostOrder(os, root->right);
      os << *root << " ";
   }

   static Node* searchNode(Node *root, int value)
   {
      // Base Cases: root is null or key is present at root
      if (!root || root->data == value)
         return root;
      // value is greater than root's key
      if (value > root->data)
         return searchNode(root->right, value);
      // value is smaller than root's key
      return searchNode(root->left, value);
   }

   static Node* deleteNode(struct Node* root, int value)
   {
      // base case
      if (root == NULL)
         return root;
   
      // If the key to be deleted is
      // smaller than the root's
      // key, then it lies in left subtree
      if (value < root->data)
         root->left = deleteNode(root->left, value);
   
      // If the key to be deleted is
      // greater than the root's
      // key, then it lies in right subtree
      else if (value > root->data)
         root->right = deleteNode(root->right, value);
   
      // if key is same as root's key, then This is the node
      // to be deleted
      else 
      {
         // node has no child
         if (root->left == NULL && root->right == NULL)
            return NULL;
         // node with only one child
         else if (root->left == NULL) 
         {
            Node* temp = root->right;
            free(root);
            return temp;
         }
         else if (root->right == NULL)
         {
            Node* temp = root->left;
            free(root);
            return temp;
         }
         // node with two children: Get the inorder successor
         // (smallest in the right subtree)
         Node* temp = root->right;
         while (temp->left != NULL)
         {
            temp = temp->left;
         }
         // Copy the inorder successor's content to this node
         root->data = temp->data;
         // Delete the inorder successor
         root->right = deleteNode(root->right, temp->data);
      }
      return root;
   }

   friend ostream& operator<< (ostream &os, Node &temp_node)
   { 
      os << temp_node.data; 
      return os;
   };
};

struct BST
{
   enum TRAVERSAL_MODE {PRE_ORDER, IN_ORDER, POST_ORDER};
   Node* root;
   TRAVERSAL_MODE traversal_mode;
   // constructors
   BST(): root(NULL), traversal_mode(PRE_ORDER)
   {};
   BST(Node* a): root(a), traversal_mode(PRE_ORDER)
   {};

   // methods
   void setTraversalMode(TRAVERSAL_MODE mode)
   {
      assert(((mode == PRE_ORDER) || (mode == IN_ORDER) || (mode == POST_ORDER)));
      this->traversal_mode = mode;
   }

   
   friend ostream& operator<< (ostream &os, BST &temp_bst)
   { 
      if (temp_bst.traversal_mode == PRE_ORDER)
      {
         // pre-order traversal 
         os << "\n" << "Traveling by pre-order ..." << "\n";
         Node::travelPreOrder(os, temp_bst.root);
      } 
      if (temp_bst.traversal_mode == IN_ORDER)
      {
         // in-order traversal 
         os << "\n" << "Traveling by in-order ..." << "\n";
         Node::travelInOrder(os, temp_bst.root);
      } 
      if (temp_bst.traversal_mode == POST_ORDER)
      {
         // in-order traversal 
         os << "\n" << "Traveling by post-order ..." << "\n";
         Node::travelPostOrder(os, temp_bst.root);
      } 
      return os;
   }

};


int main()
{
   BST *bst = new BST(new Node(50));
   Node::insertNodeToBst(bst->root, 30);
   Node::insertNodeToBst(bst->root, 20);
   Node::insertNodeToBst(bst->root, 40);
   Node::insertNodeToBst(bst->root, 70);
   Node::insertNodeToBst(bst->root, 60);
   Node::insertNodeToBst(bst->root, 80);
   
   // traverling the tree
   bst->setTraversalMode(BST::PRE_ORDER);
   cout << *bst << endl;
   bst->setTraversalMode(BST::IN_ORDER);
   cout << *bst << endl;
   bst->setTraversalMode(BST::POST_ORDER);
   cout << *bst << endl;
   // searching a node in the tree
   int temp_val = 80;
   Node* r = Node::searchNode(bst->root, temp_val);
   if (r != NULL)
      cout << temp_val << " is existing in the tree at: <" << r << ">" << endl;
   else
      cout << temp_val << " is not existing in the tree!!!" << endl;
   // deleting a node in the tree
   temp_val = 40;
   cout << "Deleating a node whose value is: " << temp_val << endl;
   Node::deleteNode(bst->root, temp_val);
   bst->setTraversalMode(BST::IN_ORDER);
   cout << *bst << endl;

   return 0;
}