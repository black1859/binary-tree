#include "binary_tree.h"
#include <stack>
#include "read_infix.h"

void BinaryTree::generate_tree(std::string infix)
{
	std::stack<BinaryNode*> operand_s;
	std::stack<BinaryNode*> operator_s;

	int index = 0;
	int c = infix[index];

	while (c)
	{
		if (is_operator(c)) { 
			while (not operator_s.empty() && check_priority(c) <= check_priority(operator_s.top()->value))
			{
				BinaryNode* opr = operator_s.top();
				operator_s.pop();
				BinaryNode* right = operand_s.top();
				operand_s.pop();
				BinaryNode* left = operand_s.top();
				operand_s.pop();

				opr->left = left;
				opr->right = right;

				operand_s.push(opr);
			}
			operator_s.push(new BinaryNode(c, nullptr, nullptr));
		}
		else if (is_parentheses(c)) {
			if (c== OPEN)operator_s.push(new BinaryNode(c, nullptr, nullptr));
			else {
				while (operator_s.top()->value != OPEN) {
					BinaryNode* opr = operator_s.top();
					operator_s.pop();
					BinaryNode* right = operand_s.top();
					operand_s.pop();
					BinaryNode* left = operand_s.top();
					operand_s.pop();

					opr->left = left;
					opr->right = right;

					operand_s.push(opr);
				}
				operator_s.pop(); // remove '(' in stack
			}
		}
		else if (is_space(c)) { }
		else operand_s.push(new BinaryNode(c, nullptr, nullptr));

		c = infix[++index];
	}
	while (!operator_s.empty())
	{
		BinaryNode* opr = operator_s.top();
		operator_s.pop();
		BinaryNode* right = operand_s.top();
		operand_s.pop();
		BinaryNode* left = operand_s.top();
		operand_s.pop();

		opr->left = left;
		opr->right = right;

		operand_s.push(opr);
	}
	root = operand_s.top();
	operand_s.pop();
}