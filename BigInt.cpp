
#include <vector>
#include <iostream>
#include <algorithm>    // std::reverse
#include "BigInt.h"

string BigInt::copy_next(int *index, string in){
    string out;
    for(int i = *index;;i++){
        if(in[i]==' ' || in[i]=='\0')
            break;
        out.push_back(in[i]);
        *index = *index + 1;
    }
    reverse(out.begin(),out.end());
    return out;
}

string BigInt::add(string in, bool printResult)
{
    string res, cur;
    int index = 2;
    int carry = 0;
    int x, y, r;
    while (index < (int)in.size())
    {
        cur = copy_next(&index, in);
        while (res.size() > cur.size())
            cur.push_back('0');
        while (cur.size() > res.size())
            res.push_back('0');
        for (int i = 0; i < (int)cur.size(); i++)
        {
            x = cur[i] - '0';
            y = res[i] - '0';
            r = x + y + carry;
            res[i] = (r % 10) + '0';
            carry = r / 10;
        }
        if (carry == 1)
        {
            res.push_back('1');
            carry = 0;
        }
        index++;
    }

for (int i = res.size() - 1; i >= 0; i--) {
        res[i];
    }
    reverse(res.begin(), res.end());
    if (printResult == true)
    {
        if (verbose == true)
        {
            cout << "\n" << in << " = " << res;
            cout << endl;
        }
        else {
            cout << "\n" << res;
            cout << endl;
        }
    }
    return res;
}

string BigInt::multiply(string in, bool printResult)
{
    string res, cur;
    int index = 2;
    res = copy_next(&index, in);
    reverse(res.begin(), res.end());
    index++;
    while (index < (int)in.size())
    {
        cur = copy_next(&index, in);
        reverse(cur.begin(), cur.end());
        //cout<<res<<'*'<< cur << '\n';
        if (res.size() == 0 || cur.size() == 0)
        {
            cout << "0";
            return "0";
        }
        vector<int> result(res.size() + cur.size(), 0);
        int i_n1 = 0;
        int i_n2 = 0;
        for (int i = res.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            int n1 = res[i] - '0';
            i_n2 = 0;
            for (int j = cur.size() - 1; j >= 0; j--)
            {
                int n2 = cur[j] - '0';
                int sum = n1*n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;

                i_n2++;
            }
            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }

int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;
        if (i == -1)
        {
            cout << "0";
            return "0";
        }
        index++;
        res = "";
        while (i >= 0)
            res += to_string(result[i--]);
    }
    if (printResult == true)
    {
        if (verbose == true)
        {
            cout << "\n" << in << " = " << res;
            cout << endl;
        }
        else {
            cout << "\n" << res;
            cout << endl;
        }
    }
    return res;
}

string BigInt::exponent(string in)
{
    string res, init, cur = "1", fin;
    int index = 2;
    res = copy_next(&index, in);
    reverse(res.begin(), res.end());
    init = res;
    index ++;
    fin = copy_next(&index, in);
    reverse(fin.begin(), fin.end());
    while (cur != fin)
    {
        string operation;
        operation = "+ 1 " + cur;
        cur = add(operation,false);
        operation = "* " + res + " " + init;
        res = multiply(operation,false);
    }
    cout << res << '\n';
    return res;
}
void BigInt::put_verbose(bool verb)
{
    verbose = verb;
}

