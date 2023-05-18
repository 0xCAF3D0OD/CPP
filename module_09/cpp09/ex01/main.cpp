//
// Created by Kevin Di nocera on 3/26/23.
//
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		perror("ac");
		return (1);
	}
	RPN polish_math;
	std::string	string(av[1]);

	if (polish_math.check_arguments(string.c_str()) == 1)
		return (1);
	polish_math.calculus(string.c_str());
	return (0);
}

//#include <iostream>
//#include <stack>
////using namespace std;
//int main() {
//	std::stack<int> stack;
//	stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
//	stack.push(22);
//	stack.push(24);
//	stack.push(25);
//	int num=0;
//	stack.push(num);
//	stack.pop();
//	stack.pop();
//	stack.pop();
//
//	while (!stack.empty()) {
//		std::cout << stack.top() <<" ";
//		stack.pop();
//		}
//}