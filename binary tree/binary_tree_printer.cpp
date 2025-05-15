#include "binary_tree.h"
#include <iostream>
#include <queue>

void BinaryTree::print_infix()
{
	print_in(root);
}

void BinaryTree::print_prefix()
{
	print_pre(root);
}

void BinaryTree::print_postfix()
{
	print_post(root);
}

void BinaryTree::print_level()
{
	print_level_order(root);
}

void BinaryTree::print_in(BinaryNode* node)
{
	if (node == nullptr) return;
	if (not is_leaf(node))std::cout << "(";
	char c = node->value;
	print_in(node->left);
	std::cout << c << "";
	print_in(node->right);
	if (not is_leaf(node))std::cout << ")";
}

void BinaryTree::print_pre(BinaryNode* node)
{
	if (node == nullptr) return;
	char c = node->value;
	std::cout << c << " ";
	print_pre(node->left);
	print_pre(node->right);
}

void BinaryTree::print_post(BinaryNode* node)
{
	if (node == nullptr) return;
	char c = node->value;
	print_post(node->left);
	print_post(node->right);
	std::cout << c << " ";
}

void BinaryTree::print_level_order(BinaryNode* node) // queue required
{
	std::queue<BinaryNode*> subtree;
	BinaryNode* current = node;

	if (current == nullptr) return;
	subtree.push(current);

	while (!subtree.empty())
	{
		current = subtree.front();

		char c = current->value;
		std::cout << c << " ";
		
		if(current->left) subtree.push(current->left);
		if (current->right) subtree.push(current->right);
		subtree.pop();
	}
}