#include <iostream>
#include "binary_tree.h"

int main(void) {

	// (4 + 5) * 3

	char c = '*';
	BinaryTree btree(c);
	c = '+';
	btree.insert_item(c, 2);

	btree.insert_item(3, 3);
	btree.insert_item(4, 4);
	btree.insert_item(5, 5);

	std::cout << "infix: ";
	btree.print_infix();
	std::cout << "\n";
	std::cout << "prefix: ";
	btree.print_prefix();
	std::cout << "\n";
	std::cout << "postfix: ";
	btree.print_postfix();
}