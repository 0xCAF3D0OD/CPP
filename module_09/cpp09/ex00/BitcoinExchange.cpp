#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& origin)
{
	*this = origin;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & origin)
{
	this->_map = origin._map;
	return (*this);
}

void	BitcoinExchange::init_csv(void)
{
	std::ifstream csv("data.csv");
	if (!csv.is_open()) {
		std::cerr << "failed to open file." << std::endl;
		exit(1);
	}
	std::string read;
	float nb = 0.0;
	size_t size;

	/* Getline put the line in the string read*/
	while(std::getline(csv, read))
	{
		/* We verify if read doesn't contain the string "date,exchange_rate"*/
		if (read != "date,exchange_rate")
		{
			/* Find the "," character and we put the emplacement in size.*/
			size = read.find(',');
			/* With the size, whe extract the number in the string and convert it in float with
			 * the function std::istringstream. */
			std::istringstream(read.substr(size + 1, read.length())) >> nb;
			/* We stock the float in our map containers. */
			_map[read.substr(0, size)] = nb;
		}
	}
}

bool 	BitcoinExchange::is_valid_date(const std::string& date_str)
{
	int year, month, day;
	char delim;
	std::istringstream date(date_str);
	date >> year >> delim >> month >> delim >> day;
	if (date.fail() || date.peek() != EOF) {
		// The conversion failed or it's still exist character in the string.
		return false;
	}
	// The months are invalid.
	if (month < 1 || month > 12)
		return (false);
	if (year < 2009)
		return (false);
//	std::cout << "year = " << year << "-" << month << "-" << day << std::endl;
	return (true);
}

int	BitcoinExchange::data_base(const char *av)
{
	if (!av)
		return (1);
	const char *tmp;
	std::ifstream infile(av);
	if ((tmp = std::strchr(av, '.')))
	{
		if (std::strncmp(tmp, ".txt", std::strlen(tmp))) {
			std::cerr << "Error: file is not supported" << std::endl;
			exit(1);
		}
	}
	/* Check if the file is open */
	if (!infile.is_open()) {
		std::cerr << "failed to open file." << std::endl;
		return (1);
	}
	std::string read;
	size_t size;
	float nb = 0.0;
	/* Iterator created for the last bloc condition */
	std::map<std::string, float>::const_iterator it;
	while(std::getline(infile, read)) {
		if (read != "date | value") {
			/* Pipe exist ?! If not continue to the next index */
			if ((size = read.find('|')) >= read.size()) {
				std::cout << "Error: No separation pipe in file" << std::endl;
				continue;
			}
			/* Is there the right datum ?! If not continue to the next index */
			if ((read[size - 1] != ' ') || (read[size - 2] == ' ')) {
				std::cout << "Error: Wrong format of datum." << std::endl;
				continue;
			}
			/* Create the key = datum */
			std::string key = read.substr(0, size - 1);
			if (key.find("-") > 4) {
				std::cout << "Error: datum separation must be '-'" << std::endl;
				continue;
			}
			int count = 0;
			const char *tp = key.c_str();
			for (int i = 0; tp[i]; ++i) {
				if (tp[i] == '-')
					count++;
			}
			if (count != 2) {
				std::cout << "Error: datum separation '-' must be 2" << std::endl;
				continue;
			}
			if (key.find("-") > 4) {
				std::cout << "Error: datum separation must be '-'" << std::endl;
				continue;
			}
			if (!is_valid_date(key))
			{
				std::cout << "Error: bad input => " << key << std::endl;
				continue;
			}
			/* Create the value, a string to check if negative */
			std::string value = read.substr(size + 1, read.size());
			if (value.find("-") == 1) {
				std::cout << "Error: Value is negative" << std::endl;
				continue;
			}
			/* Check if the conversion is a success, if std::istringstream fail maybe no number was given */
			if (!(std::istringstream(read.substr(size + 1, read.length())) >> nb)) {
				std::cout << "Error: Il manque la valeur du btc" << std::endl;
				continue;
			}
			if (nb > 1000) {
				std::cout << "Error: Value is higher as 1000" << std::endl;
				continue;
			}
			if (nb < 0) {
				std::cout << "Error: Value is less than 0" << std::endl;
				continue;
			}
			/* Find the right datum in the database if not we take the datum before this who doesn't exist in the data. */
			if (_map.find(key) == _map.end()) {
				float i;
				for (it = _map.begin(); it != _map.end(); ++it) {
					if (it->first >= key) {
						it--;
						break;
					}
				}
				i = it->second;
				i *= nb;
 				std::cout << it->first << " => " << nb << " => " << i << std::endl;
			}
			else {
				float i;
				std::stringstream ss;
				std::string str;
				ss << read;
				while (ss >> str)
				{
					if (std::strcmp(str.c_str(), " "))
						break;
				}
				i = it->second;
				i *= nb;
				std::cout << str << " => " << nb << " => " << i << std::endl;
			}
		}
	}
	return (0);
}

BitcoinExchange::~BitcoinExchange() {}
