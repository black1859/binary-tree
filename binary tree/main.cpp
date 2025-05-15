#include <iostream>
#include "binary_tree.h"

int main(void) {

	char c = '*';
	BinaryTree btree(c);
	btree.insert_item(2, 2);

	c = '+';
	btree.insert_item(c, 3);

	btree.insert_item(4, 6);
	btree.insert_item(5, 7);

	std::cout << "infix: ";
	btree.print_infix();
	std::cout << "\n";
	std::cout << "prefix: ";
	btree.print_prefix();
	std::cout << "\n";
	std::cout << "postfix: ";
	btree.print_postfix();
	std::cout << "\nlevel: ";
	btree.print_level();
}