#include "binary_tree.h"

BinaryNode::BinaryNode(int value, BinaryNode* left, BinaryNode* right)
{
	this->value = value;
	this->left = left;
	this->right = right;
}

BinaryNode::~BinaryNode()
{
	if (left) delete left;
	if (right) delete right;
}

BinaryTree::BinaryTree(int root_value)
{
	this->root = new BinaryNode(root_value, nullptr, nullptr);
}

BinaryTree::BinaryTree(BinaryNode* root)
{
	this->root = root;
}

BinaryTree::~BinaryTree()
{
	delete root;
}

BinaryNode* BinaryTree::get_root()
{
	return root;
}

void BinaryTree::insert_item(int value, int destination)
{	
	// if destination is even -> left (2n)
	// if destination is odd -> right (2n+1)
	if (destination % 2) { // odd
		BinaryNode* current = search_node_by_index(root, (destination - 1) / 2, 1); //root is position 1
		current->right = new BinaryNode(value, nullptr, nullptr); }
	else // even
	{
		BinaryNode* current = search_node_by_index(root, destination / 2, 1); //root is position 1
		current->left = new BinaryNode(value, nullptr, nullptr);
	}
}

BinaryNode* BinaryTree::search_node_by_index(BinaryNode* current, int destination, int current_positon)
{
	if (current == nullptr) return nullptr;
	if (current_positon == destination) return current;

	BinaryNode* left = search_node_by_index(current->left, destination, current_positon * 2);
	if (left) return left;

	BinaryNode* right = search_node_by_index(current->right, destination, current_positon * 2 + 1);
	return right;
}

bool BinaryTree::is_leaf(BinaryNode* node)
{
	return node->left == nullptr && node->right == nullptr;
}
