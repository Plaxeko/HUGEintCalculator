
#include <string>

using namespace std;

class BigInt
{
    string res, cur;

    int index = 2;
    int carry = 0;
    int x,y,r;


public:
    bool verbose = false;
    void add(string in);
    string copy_next(int *index, string in);
};
