
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

void BigInt::add(string in)
{
    while (index < in.size()){
        cur = copy_next(&index, in);
    while(res.size()> cur.size())
        cur.push_back('0');
    while(cur.size()> res.size())
        res.push_back('0');
    for(int i = 0; i<cur.size();i++) {
        x =cur[i] - '0';
        y = res[i] - '0';
        r = x + y + carry;
        res[i] = (r%10) + '0';
        carry = r/10;
        }
        if(carry == 1)
        {
            res.push_back('1');
            carry = 0;
        }
        index++;
    }
         for(int i =res.size()-1; i >=0;i--) {
            res[i];
        }

        reverse(res.begin(), res.end());

        //cout << endl;

        if(verbose == true)
        {
            cout << "\n" << in << " = " << res;
            cout << endl;
        } else{
            cout << "\n" << res;
            cout << endl;
        }
}
