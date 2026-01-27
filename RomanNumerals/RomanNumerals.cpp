// RomanNumerals.cpp : Defines the entry point for the application.
//

#include "RomanNumerals.h"
#include <stdexcept>
#include <array>
#include <string>



int RomanNumeralCharToDecimal(char romanNumeral) {
	switch (romanNumeral) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		throw std::invalid_argument{ romanNumeral + " is not a valid roman numeral!"};
	}

}


void validatePreviousNumerals(char repeatChar, int repeatNum) {
	bool tooManyRepeatedNumerals;
	switch (repeatChar) {
	case 'I':
	case 'X':
	case 'C':
	case 'M':
		// If there are 4 repeated numerals that are of these types, it is invalid
		tooManyRepeatedNumerals = (repeatNum >= 4);
		if(tooManyRepeatedNumerals) {
			throw std::invalid_argument{ "The numeral " + repeatChar + std::string(" may not have 4 or more repeated numerals of the same type") };
		}
		break;
	case 'V':
	case 'L':
	case 'D':
		// If there are any repeated numerals that are of these types, it is invalid
		tooManyRepeatedNumerals = (repeatNum >= 2);
		if (tooManyRepeatedNumerals) {
			throw std::invalid_argument{ "The numeral " + repeatChar + std::string(" may not have any repeated numerals of the same type") };
		}
		break;
	default:
		break;
	}
}

bool isSubtractiveNumeral(char numeral) {
	switch (numeral) {
	case 'I':
	case 'X':
	case 'C':
		return true;
	default:
		return false;
	}
}

int RomanNumeralStringToDecimal(const std::string& romanNumerals) {
	int total = 0;
	char repeatChar = '\0';
	int repeatNum = 0;
	const char* start = romanNumerals.data();
	const char* current = start;
	const char* end = current + romanNumerals.size();
	while (current < end) {
		if (repeatChar != *current) {
			repeatChar = *current;
			repeatNum = 1;
		}
		else {
			repeatNum++;
		}
		validatePreviousNumerals(repeatChar, repeatNum);
		int decimal = RomanNumeralCharToDecimal(*current);
		// Check the next character, to see if this character should subtract or add
		if (end > (current + 1) && RomanNumeralCharToDecimal(current[1]) > decimal ) {
			if (!isSubtractiveNumeral(*current)) {
				throw std::invalid_argument{ "The numeral " + *current + std::string(" cannot be used to subtract") };
			}
			total -= decimal;
		}
		else {
			total += decimal;
		}
		current++;
		
	}
	if (total > 3999) {
		throw std::out_of_range{"The total number represented cannot exceed 3999"};
	}
	return total;
}


