//
// Created by Kevin Di nocera on 4/2/23.
//
#include <sys/time.h>
#include <iomanip>
#include "PmergeMe.hpp"

#define RED "\033[1;31m"
#define RES "\033[0m\n"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const& src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	this->_v = src._v;
	this->_l = src._l;
	this->_timeV = src._timeV;
	this->_timeL = src._timeL;
	return (*this);
}

/*----------------------------------------------------vector------------------------------------------------------------*/

std::vector<int> PmergeMe::stock_1_string(char **av, std::vector<int> tab_num)
{
	std::stringstream	ss;
	int					num;

	for (int i = 1; av[i]; ++i)
		ss << av[i];
	while (ss >> num) {
		if (num > INT_MAX || num < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(num);
	}
	return (tab_num);
}

std::vector<int> PmergeMe::stock_many_strings(char **av, std::vector<int> tab_num)
{
	for (int i = 1; av[i]; i++)
	{
		if (std::atoi(av[i]) > INT_MAX || std::atoi(av[i]) < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit (1);
		}
		tab_num.push_back(std::atoi(av[i]));
	}
	return (tab_num);
}

void	PmergeMe::merge_sort(std::vector<int> &v, int left, int right, int max_size_temp_tab)
{
	// Apply tri-insertion for small sub-tables
	// Appliquer tri-insertion pour les sous-tableaux de petite taille
	if ((right - left + 1) <= max_size_temp_tab) {
		insertion_sort(v, left, right);
		return ;
	}
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid, max_size_temp_tab);
		merge_sort(v, mid + 1, right, max_size_temp_tab);
		merge_V(v, left, mid, right);
	}
}

void PmergeMe::insertion_sort(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::merge_V(std::vector<int>& v, int left, int mid, int right)
{
	int L_side = mid - left + 1;
	int	R_side = right - mid;

	// Create temporary left and right sub-tables.
	// Créer des sous-tableaux temporaire gauche et droite.
	std::vector<int> L(L_side), R(R_side);

	//	Copy the data to the temporary left and right sub-tables.
	// Copier les données dans les sous-tableaux temporaire gauche et droite.
	for (int i = 0; i < L_side; ++i)
		L[i] = v[left + i];
	for (int j = 0; j < R_side; ++j)
		R[j] = v[mid + 1 + j];

	// Merge the left and right sub-tables into the main table
	// Fusionner les sous-tableaux gauche et droit dans le tableau principal
	int i = 0;
	int j = 0;
	int k = left;

	while (i < L_side && j < R_side) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i++;
		}
		else {
			v[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[] if any are left
	// Copier les éléments restants de L[] s'il en reste
	while (i < L_side) {
		v[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[] if any are left
	// Copier les éléments restants de R[] s'il en reste
	while (j < R_side) {
		v[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::display_sequence_vector(const std::vector<int>& v, const std::string& title)
{
	std::cout << title << ":	\" ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\"" << std::endl;
}

/*----------------------------------------------------list------------------------------------------------------------*/

std::list<int> PmergeMe::stock_1_string_L(char **av, std::list<int> tab_num)
{
	std::stringstream	ss;
	int					num;

	for (int i = 1; av[i]; ++i)
		ss << av[i];
	while (ss >> num) {
		if (num > INT_MAX || num < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(num);
	}
	return (tab_num);
}

std::list<int> PmergeMe::stock_many_strings_L(char **av, std::list<int> tab_num)
{
	for (int i = 1; av[i]; i++) {
		if (std::atoi(av[i]) > INT_MAX || std::atoi(av[i]) < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(std::atoi(av[i]));
	}
	return (tab_num);
}

// Function to perform insertion sort on a list
void PmergeMe::insertionSort(std::list<int>& lst)
{
	// 1. Declare an iterator i for the input list lst.
	std::list<int>::iterator i;

	// 2. Iterate through the list starting from the second element (i initially points to the first element).
	for (i = lst.begin(); i != lst.end(); ++i) {
		// 3. For each element, declare an iterator j initialized to the current position of i.
		std::list<int>::iterator j = i;
		// 4. While j is not at the beginning of the list and the previous element (*std::prev(j))
		// is greater than the current element (*j):
		while (j != lst.begin() && *std::prev(j) > *j) {
			// 4.1. Swap the current element (*j) with the previous element (*std::prev(j)) using the std::iter_swap function.
			std::iter_swap(j, std::prev(j));
			// 4.2. Decrement j to move towards the beginning of the list.
			--j;
		}
		// 5. Repeat steps 3 and 4 for all elements in the list.
	}
}

// Function to merge two sorted lists
std::list<int> PmergeMe::merge(const std::list<int>& left, const std::list<int>& right)
{
	// Create an empty std::list<int> called result to store the merged elements.
	std::list<int> result;
	// Declare two const_iterators, left_iter and right_iter, initialized to the beginning of the left
	// and right lists respectively.
	std::list<int>::const_iterator left_iter = left.begin();
	std::list<int>::const_iterator right_iter = right.begin();

	// Iterate through the left and right lists until one of them is completely traversed:
	while (left_iter != left.end() && right_iter != right.end()) {
		// If the current element in left (*left_iter) is less than or equal to the current element in right (*right_iter),
		// add the left element to the result list and increment the left_iter.
		if (*left_iter <= *right_iter) {
			result.push_back(*left_iter);
			++left_iter;
		}
		// Otherwise, add the right element to the result list and increment the right_iter.
		else {
			result.push_back(*right_iter);
			++right_iter;
		}
	}
	// After the loop, one of the lists may still have unprocessed elements. Add any remaining elements
	// from both lists to the result list using the insert function.
	result.insert(result.end(), left_iter, left.end());
	result.insert(result.end(), right_iter, right.end());

	// Return the result list containing the merged elements.
	return (result);
}

// Function to perform merge-insertion sort on a list
// Merge sort is a divide and conquer algorithm, which naturally lends itself to recursion. The input list is divided
// into smaller subproblems, and the function is called recursively on these subproblems until a base case
// (list of size 1 or less) is reached.
// Recursion works particularly well for recursively defined data structures and problems that can be broken
// down into subproblems.
std::list<int> PmergeMe::merge_insertion_sort(std::list<int>& lst) {
	// If the input list lst has a size of 1 or less, it is already sorted, so return it directly.
	if (lst.size() <= 1) {
		return lst;
	}
	// If the input list lst has a size of 11 or less, use the insertionSort function to sort it in-place and return it.
	else if (lst.size() <= 11) {
		insertionSort(lst);
		return lst;
	}

	// For larger lists, find the middle element by creating an iterator mid pointing to the middle of the list.
	std::list<int>::iterator mid = std::next(lst.begin(), lst.size() / 2);
	// Create two sublists left and right by splitting the input list lst at the middle element.
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());

	// Recursively call the merge_insertion_sort function on both left and right sublists.
	left = merge_insertion_sort(left);
	right = merge_insertion_sort(right);

	// Merge the sorted left and right sublists using the merge function,
	// and assign the merged result back to the input list lst.
	lst = merge(left, right);
	return (lst);
}

void PmergeMe::display_sequence_list(const std::list<int>& l, const std::string& title)
{
	std::cout << title << ":	\" ";
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\"" << std::endl;
}

/*----------------------------------------------------list------------------------------------------------------------*/

char	**new_av(char **av)
{
	char	**table;
	char	*av_copy;
	char	*token;
	int		i = 0;

	table = new char*[std::strlen(av[1])];
	av_copy = new char[std::strlen(av[1]) + 1];
	strcpy(av_copy, av[1]);

	token = std::strtok(av_copy, " ");
	while (token)
	{
		table[i] = new char(std::strlen(token) + 1);
		strcpy(table[i], token);
		i++;
		token = strtok(NULL, " ");
	}

	delete[] av_copy;
	return (table);
}

int duplicate(char **av, int len)
{
	char **tmp = av;
	std::vector<int> numbers;

	for (int i = 0; i < len; ++i)
		numbers.push_back(atoi(tmp[i]));
	std::sort(numbers.begin(), numbers.end());
	for (size_t i = 0; i < numbers.size() - 1; ++i) {
		if (numbers[i] == numbers[i + 1]) {
			for (size_t k = 0; k != numbers.size(); ++k)
			{
				if (numbers[k] == numbers[i] && numbers[k + 1] == numbers[k])
				{
					std::cout << RED << numbers[k] << " " << numbers[k + 1] << RES << std::endl;
					break ;
				}
				std::cout << numbers[k] << " ";
			}
			std::cerr << RED << "\nError: duplicate number: " << numbers[i] << " " << numbers[i + 1] << RES << std::endl;
			return (1);
		}
	}
	return (0);
}

void	PmergeMe::stock_args_string(char **av, int ac)
{
	std::vector<int> 	v_numbers;
	std::list<int> 		l_numbers;
	char				**n_av;
	int					size = 0;

	if (ac == 2) {
		n_av = new_av(av);
		for (int i = 0; n_av[i]; ++i)
			size++;
		if (!duplicate(n_av, size)) {
			v_numbers = stock_1_string(av, v_numbers);
			l_numbers = stock_1_string_L(av, l_numbers);
		}
		else
			exit(1);
	}
	else {
		if (!duplicate(av, ac)) {
			v_numbers = stock_many_strings(av, v_numbers);
			l_numbers = stock_many_strings_L(av, l_numbers);
		}
		else
			exit(1);
	}
	if (v_numbers.size() == 1 || l_numbers.size() == 1)
	{
		std::cerr << "error: less arguments" << std::endl;
		exit(1);
	}
	this->_v = v_numbers;
	this->_l = l_numbers;
}

int PmergeMe::check_args_is_digit(char **av, int ac)
{
	std::string 		tmp;

	for (int it = 1; av[it]; ++it) {
		tmp = av[it];
		if (ac > 2) {
			if (tmp.find_first_not_of("0123456789") != std::string::npos) {
				if (strchr(tmp.c_str(), '-'))
					std::cerr << "error: digit must be positive => ";
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
		else {
			if (tmp.find_first_not_of("0123456789 ") != std::string::npos) {
				if (strchr(tmp.c_str(), '-'))
					std::cerr << "error: digit must be positive => ";
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void PmergeMe::sort_sequence(std::vector<int>& v, std::list<int>& l)
{
	int	left = 0;
	int right = _v.size() - 1;
	//	Maximum size of sub-tables that will be sorted using the insertion sort.
	//	Taille maximale des sous-tableaux qui seront triés à l'aide du tri par insertion.
	int	max_size_temp_tab = 5;
	struct timeval start, end;

	gettimeofday(&start, 0);
	merge_sort(v, left, right, max_size_temp_tab);
	gettimeofday(&end, 0);
	_timeV = ((end.tv_sec - start.tv_sec)  * 1e-6) + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, 0);
	merge_insertion_sort(l);
	gettimeofday(&end, 0);
	_timeL = ((end.tv_sec - start.tv_sec)  * 1e-6) + (end.tv_usec - start.tv_usec);
}

// The merge-insert algorithm is slower when using a list container compared to a vector container due to the difference
// in memory allocation, access patterns, and operations supported by the two containers.
void	PmergeMe::algo(void)
{
	display_sequence_vector(_v, "vector before");
	display_sequence_list(_l, "list before");

	sort_sequence(_v, _l);

	display_sequence_vector(_v, "\nvector after");
	display_sequence_list(_l, "list after");
	std::cout << "\nTime to process a range of: " << _v.size() << " elements with std::vector:	";
	std::cout << "Measured time is = " << std::fixed << std::setprecision(5) << _timeV << " microseconds." << std::endl;
	std::cout << "Time to process a range of: " << _l.size() << " elements with std::list:	";
	std::cout << "Measured time is = " << std::fixed << std::setprecision(5) << _timeL << " microseconds." << std::endl;
}

PmergeMe::~PmergeMe(void) {}

