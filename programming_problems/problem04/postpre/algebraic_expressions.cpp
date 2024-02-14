#include <string>
using std::string;

#include <iostream>
#include <stack>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix)
{
  // Creating a stack from the C++ STL
  std::stack<std::string> s;

  // For-Loop to check each character in the string
  for(int i = 0; i < postfix.length(); i++)
  {
    // If the character is an operator
    if(isoperator(postfix[i]))
    {
      // We have to evaluate and push the result
      // First operator and pop it out of stack
      std::string op1 = s.top();
      s.pop();
      // Second operator and pop it out of stack
      std::string op2 = s.top();
      s.pop();
      // Push result into the stack
      std::string op3 = postfix[i] + op2 + op1;
      s.push(op3);
    }
    // If the character is an operand
    else
    {
      // Need to convert the char into a string, so I am concatenting
      // it with an empty string
      std::string final = "";
      // Push the value of the operand into the stack
      s.push(final + postfix[i]);
    }
  }
  // The prefix resulting value will be the top-most value in the stack
  prefix = s.top();
}
