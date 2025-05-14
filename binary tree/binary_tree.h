#pragma once

class BinaryNode
{
public:
	BinaryNode(int value);
	~BinaryNode();

	int value;
	BinaryNode* left;
	BinaryNode* right;
private:

};

class BinaryTree
{
public:
	BinaryTree(int root);
	BinaryTree(BinaryNode* root);
	~BinaryTree();

	void print_infix();
	void print_prefix();
	void print_postfix();
	void print_level();

private:

};