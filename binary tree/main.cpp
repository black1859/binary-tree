#include <iostream>
#include "binary_tree.h"
#include <string>

int main(void) {

	BinaryTree btree;
	BinaryTree btree2;

	std::string s1 = "((1 + 2) * (3 - 4) + (5 * (6 + 7)))";
	std::string s2 = "(8 * (9 + 1)) - ((3 - 2) / (5 + 4))";
	std::string s3 = "(((1 + 2) + (3 + 4)) * (5 + (6 * 7)))";
	std::string s4 = "(1 + ((2 + 3) * (4 - 5) + (6 / 7)))";
	std::string s5 = "((1 / (2 + 3)) + ((4 * 5) - (6 + 7)))";
	
	std::string target = s1;


	std::cout << target << "\n";
	btree.generate_tree(target);

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