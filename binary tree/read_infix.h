#pragma once
const int PLU = 43;
const int MIN = 45;
const int MUL = 42;
const int DVI = 47;
const int OPEN = 40;
const int CLOSE = 41;
const int SPACE = 32;

bool is_operator(char c);

bool is_parentheses(char c);

bool is_space(char c);

int check_priority(char op);