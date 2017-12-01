#pragma once
#include <string>
using namespace std;
namespace mesa
{
	class BigInt
	{
	private:   
		bool verbose;
		
	public:
		void put_verbose(bool verb);
		std::string copy_next(int *index, std::string in);
		std::string add(string A, string B, bool printResult);
		std::string multiply(string A, string B, bool printResult);
		std::string exponent(string base, string exp,  bool printResult);
		
	};
}
