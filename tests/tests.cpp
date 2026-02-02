// tests.cpp : Source file for your target.
//

#include "tests.h"
#include "RomanNumerals.h"
#include "catch_amalgamated.hpp"


TEST_CASE("TestValidNumeralAddition") {
	std::pair<std::string, int> numerals = GENERATE(std::make_pair("MDCCCLXVII", 1867), std::make_pair("MMCCCLXVII", 2367), std::make_pair("VI", 6), std::make_pair("MI", 1001), std::make_pair("VIII", 8), std::make_pair( "MXXX", 1030), std::make_pair("MCCCXXX", 1330));

	int expected = numerals.second;

	int actual = RomanNumeralStringToDecimal(numerals.first);

	REQUIRE(expected == actual);


}

TEST_CASE("TestValidNumeralSubtraction") {
	std::pair<std::string, int> numerals = GENERATE( std::make_pair("IV", 4), std::make_pair("CM", 900), std::make_pair("XCIV", 94),std::make_pair( "CMXIX", 919));

	int expected = numerals.second;

	int actual = RomanNumeralStringToDecimal(numerals.first);

	REQUIRE(expected == actual);


}


TEST_CASE("TestValidSingleNumerals") {
	std::pair<std::string, int> numerals = GENERATE(std::make_pair("I", 1), std::make_pair("V", 5), std::make_pair("X", 10), std::make_pair("L", 50), std::make_pair("C", 100), std::make_pair("D", 500), std::make_pair("M", 1000));

	int expected = numerals.second;

	int actual = RomanNumeralStringToDecimal(numerals.first);

	REQUIRE(expected == actual);


}


TEST_CASE("TestInvalidNumeralSubtraction") {
	std::string numerals = GENERATE("IIIIV", "CCCCM", "VX", "DM", "VM", "LD", "VX");

	REQUIRE_THROWS_AS(RomanNumeralStringToDecimal(numerals), std::invalid_argument);
	
}



TEST_CASE("TestInvalidNumerals") {
	std::string numerals = GENERATE("J", "MMCCCLXVBI", "IQ", "V5", "VIN", "MIK");

	REQUIRE_THROWS_AS(RomanNumeralStringToDecimal(numerals), std::invalid_argument);

}

TEST_CASE("TestInvalidNumeralRepeats") {
	std::string numerals = GENERATE("DD", "MDD", "DVV", "MLL", "CVV", "MIIII", "DXXXX", "MCCCC", "MMMM", "MCCCIIII");

	REQUIRE_THROWS_AS(RomanNumeralStringToDecimal(numerals), std::invalid_argument);

}



