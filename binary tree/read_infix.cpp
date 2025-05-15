#include "read_infix.h"

bool is_operator(char c)
{
    return (c == PLU || c == MIN || c == MUL || c == DVI);
}

bool is_parentheses(char c)
{
    return (c == OPEN || c == CLOSE);
}

bool is_space(char c)
{
    return c == SPACE;
}

int check_priority(char op)
{
    if (op == PLU || op == MIN) return 0;
    else if (op == MUL || op == DVI) return 1;
    return -12345;
}
