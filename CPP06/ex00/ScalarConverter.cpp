#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

//Functions placed here are only visible from this .cpp file.
namespace {
	//trim (remove leading and trailing whitespace)
	std::string trim(const std::string& s) {
		const size_t first = s.find_first_not_of(" \t\n\r");
		if (first == std::string::npos) return "";
		const size_t last = s.find_last_not_of(" \t\n\r");
		return s.substr(first, last - first + 1);
	}

	//double (floating-point number) is NaN (Not a Number) if d != d evaluates to true, it is likely NaN
 // or whether it is Infinity (±∞)
	bool isNan(double d) { return d != d; }
	bool isInf(double d) {
		return d == std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity();
	}

	bool isDigitChar(char c) { return (c >= '0' && c <= '9'); }
	bool isPrintableAscii(int c) { return (c >= 32 && c <= 126); }

	//whether the double value is an integer (no decimal places)
	//Convert d to `long` Store to l. then convert l back to double and check whether it matches the original value(d == l). 42.0 == 42.0 → true (an integer), 42.9 == 42.0 → false
	bool isIntegral(double d) {
		if (isNan(d) || isInf(d)) return false;
		long l = static_cast<long>(d);
		return d == static_cast<double>(l);
	}

	void printChar(double d) {
		std::cout << "char: ";
		if (isNan(d) || isInf(d) || d < 0 || d > 127) {
			std::cout << "impossible" << std::endl;
		} else if (!isPrintableAscii(static_cast<int>(d))) {
			std::cout << "Non displayable" << std::endl;
		} else {
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		}
	}

	void printInt(double d) {
		std::cout << "int: ";
		if (isNan(d) || isInf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
			std::cout << "impossible" << std::endl;
		} else {
			std::cout << static_cast<int>(d) << std::endl;
		}
	}

	//impossible: d itself isn't inf && f became inf.
	//means "d exceeds the maximum representable range of float and was clipped to inf during conversion" = it cannot be converted to float.
	void printFloat(double d) {
		std::cout << "float: ";
		if (isNan(d)) {
			std::cout << "nanf" << std::endl;
			return;
		}
		if (isInf(d)) {
			std::cout << (d < 0 ? "-inff" : "+inff") << std::endl;
			return;
		}
		float f = static_cast<float>(d);
		if ((isInf(static_cast<double>(f)) && !isInf(d))) {
			std::cout << "impossible" << std::endl;
			return;
		}
		std::cout << f;
		if (isIntegral(d)) std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	void printDouble(double d) {
		std::cout << "double: ";
		if (isNan(d)) {
			std::cout << "nan" << std::endl;
			return;
		}
		if (isInf(d)) {
			std::cout << (d < 0 ? "-inf" : "+inf") << std::endl;
			return;
		}
		std::cout << d;
		if (isIntegral(d)) std::cout << ".0";
		std::cout << std::endl;
	}

	bool parseInput(const std::string& in, double& out) {
		std::string l = trim(in);
		if (l.empty()) return false;

		if (l == "-inff" || l == "-inf") {
			out = -std::numeric_limits<double>::infinity();
			return true;
		}
		if (l == "+inff" || l == "+inf" || l == "inff" || l == "inf") {
			out = std::numeric_limits<double>::infinity();
			return true;
		}
		if (l == "nanf" || l == "nan") {
			out = std::numeric_limits<double>::quiet_NaN();
			return true;
		}

		//If it is a single character and not a number, treat it as a 'character'.
		if (l.length() == 1 && !isDigitChar(l[0])) {
			out = static_cast<double>(l[0]);
			return true;
		}

		char* endptr = 0;
		//std::strtod is a function that reads as far as it can and converts it to a double.
		out = std::strtod(l.c_str(), &endptr);
		if (endptr == l.c_str()) return false;

		if (*endptr == '\0') return true;
		if (*endptr == 'f' && *(endptr + 1) == '\0') return true;
		return false;
	}
}

//Analyse the input (converting it to double) and display it as four different types.
void ScalarConverter::convert(const std::string& in) { 
  double d;
	if (!parseInput(in, d)) {
		std::cout
			<< "char: impossible\n"
			<< "int: impossible\n"
			<< "float: impossible\n"
			<< "double: impossible"
			<< std::endl;
		return;
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
