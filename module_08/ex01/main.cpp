//
// Created by Kevin Di nocera on 11/6/22.
//

#include "Span.hpp"
//
//int main(void)
//{
//	Span sp = Span(50);
//	sp.Crand_number();
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//
//	return 0;
//}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "KIVIIIIIIIIIIIIIIIN\n";
	return 0;
}
