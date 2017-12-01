#include <vector>
#include <iostream>
#include <string>
#include <algorithm>    // std::reverse
#include "BigInt.h"

using namespace std;
namespace mesa{
	string BigInt::copy_next(int *index, string in){
		string out;
		for(int i = *index;;i++){
			if(in[i]==' ' || in[i]=='\0')
				break;
			out.push_back(in[i]);
			*index = *index + 1;
		}
		*index = *index + 1;
		return out;
	}

	void BigInt::put_verbose(bool verb)
	{
		verbose = verb;
	}
	string BigInt::add(string A, string B, bool printResult)
	{
		string res;
		int index = 2;
		int carry = 0;
		int x, y, r;
		reverse (A.begin(), A.end());
		reverse (B.begin(), B.end());
		while (A.size()>B.size())
			B.push_back('0');
		while (B.size()>A.size())
			A.push_back('0');
		for (int i = 0; i < A.size();i++)
		{
			x = A[i] - '0';
			y = B[i] - '0';
			r = x + y + carry;
			res.push_back((r % 10) + '0');
			carry = r / 10;
		}
		if (carry == 1)
			res.push_back('1');
		reverse(res.begin(), res.end());
		if (printResult == true)
		{
			if (verbose == true)
			{
				cout << "\n" << A << " + "<< B <<" = " << res;
				cout << endl;
			}
			else {
				cout << "\n" << res;
				cout << endl;
			}
		}
		return res;
	}
	string BigInt::multiply(string A, string B, bool printResult)
	{
		string res;
		bool flag;
		int index = 2;
		if (A.size() == 0 || B.size() == 0)
		{
			if (printResult == true)
			{
				if (verbose == true)
				{
					cout << "\n" << A <<" * "<< B << " = " << "0";
					cout << endl;
				}
				else {
					cout << "\n" << "0";
					cout << endl;
				}
			}
			return "0";
		}
		vector<int> result(A.size() + B.size(), 0);
		int i_n1 = 0;
		int i_n2 = 0;
		for (int i = A.size() - 1; i >= 0; i--)
		{
			int carry = 0;
			int n1 = A[i] - '0';
			i_n2 = 0;
			for (int j = B.size() - 1; j >= 0; j--)
			{
				int n2 = B[j] - '0';
				int sum = n1*n2 + result[i_n1 + i_n2] + carry;
				carry = sum / 10;
				result[i_n1 + i_n2] = sum % 10;
				i_n2++;
			}
			if (carry > 0)
				result[i_n1 + i_n2] += carry;
			i_n1++;
		}
		for(int i = 0; i < result.size(); i++)
		{
			res.push_back(result[i] + '0');
		}
		reverse(res.begin(), res.end());
		flag = true;
		for(int i = 0; i < res.size();i++)
		{
			if(res[i]=='0' && flag)
				res.erase(res.begin() + i);
			if(res[i]!='0'){
				flag = false;
				break;
			}
		}
		if(flag)
			res = "0";
		if (printResult == true)
		{
			if (verbose == true)
			{
				cout << "\n" << A <<" * "<< B << " = " << res;
				cout << endl;
			}
			else {
				cout << "\n" << res;
				cout << endl;
			}
		}
		return res;
	}
	string BigInt::exponent(string base, string exp,  bool printResult)
	{
		string res, cur = "1";
		if(exp == "0")
		{
			 if (printResult == true)
			{
				if (verbose == true)
				{
					cout << "\n" << base <<" ^ "<< exp << " = " << "1";
					cout << endl;
				}
				else {
					cout << "\n" << "1";
					cout << endl;
				}
			}
			return "1";
		}
		res = base;
		while (cur != exp)
		{
			cur = add("1", cur,false);
			res = multiply(base, res,false);
		}
		if (printResult == true)
		{
			if (verbose == true)
			{
				cout << "\n" << base <<" ^ "<< exp << " = " << res;
				cout << endl;
			}
			else
			{
				cout << "\n" << res;
				cout << endl;
			}
		}
		return res;
	}
}
