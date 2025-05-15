#pragma once
#include <string>

class BinaryNode
{
public:
	BinaryNode(int value, BinaryNode* left, BinaryNode* right);
	~BinaryNode();

	int value;
	BinaryNode* left;
	BinaryNode* right;
private:

};

class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(int root);
	BinaryTree(BinaryNode* root);
	~BinaryTree();
	
	void generate_tree(std::string infix);

	BinaryNode* get_root();

	void insert_item(int value, int destination);
	
	void print_infix();
	void print_prefix();
	void print_postfix();
	void print_level();

private:
	BinaryNode* root;
	BinaryNode* search_node_by_index(BinaryNode* current, int destination, int current_positon);
	bool is_leaf(BinaryNode* node);

	void print_in(BinaryNode* node);
	void print_pre(BinaryNode* node);
	void print_post(BinaryNode* node);
	void print_level_order(BinaryNode* node);
};