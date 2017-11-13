
#include <string>

class BigInt
{
    string res, cur;

    int index = 2;
    int carry = 0;
    int x,y,r;
    bool verbose;


public:
    void put_verbose(bool verb);
    string copy_next(int *index, string in);
    string add(string in,bool printResult);
    string multiply(string in, bool printResult);
    string exponent(string in);


};
