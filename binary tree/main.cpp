#include <iostream>
#include "binary_tree.h"
#include <string>

int main(void) {

	BinaryTree btree;

	std::string s = "1 + 2 * (3 + 4)";
	std::cout << s <<"\n";

	btree.generate_tree(s);

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