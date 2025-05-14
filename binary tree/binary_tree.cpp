#include "binary_tree.h"

BinaryNode::BinaryNode(int value)
{
	this->value = value;
	left = nullptr;
	right = nullptr;
}

BinaryNode::~BinaryNode()
{
	if (left) delete left;
	if (right) delete right;
}

