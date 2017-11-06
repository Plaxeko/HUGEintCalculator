
#include <vector>
#include <iostream>
#include <algorithm>    // std::reverse
#include <string>
#include <getopt.h>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;

bool verbose = false;


string copy_next(int *index, string in);
void add(string in);
void printhelp();
void argselect(int argc, char** argv);



int main(int argc, char** argv)
{
    cout << "\n" << "Type help for program use information. Type quit to exit." << "\n\n";
    argselect(argc, argv);

    string input;

    string sstream;
    stringstream readline(input);
    readline >> sstream;
//    char op = sstream[0];

    while(getline(cin, input) || !readline.eof())
    {


         if(tolower(input[0]) == 'q'){return 0;}
         if(tolower(input[0]) == 'h')
            {
                printhelp();
            }
            else{
   // cout<<input<<endl;

    for(int i=0 ;i < input.size();i++){
        if(!(input[i]=='+' ||input[i]==' '||(input[i]>= '0' && input[i]<= '9'))){
            cout <<"Please give one operator(+,*,^) and integer based operands.\n";
            return 0;
            }
        }
        add(input);
        }
    }
        return 0;
}


void printhelp()
{
    std::cout << "*********************************************************************************************\n"
                 "* 1.Give the system an operator first.                                                      *\n"
                 "* 2.Follow the operator by any number of operands needed seperated by a space.              *\n"
                 "*                                                                                           *\n"
                 "* Restart program with flag -v for verbose mode or -h to print help screen                  *\n"
                 "* -v will set the system to verbose mode and display your input before the result.          *\n"
                 "* .............................................................................             *\n"
                 "* You can Add (+), multiply (*), and give exponent (^). example input: + 10 10 10           *\n"
                 "* ..........................................................................................*\n"
                 "* type 'quit' to exit the program                                                           *\n"
                 "* ..........................................................................................*\n"
                 "* You can process a file with one operator and multiple operands per line.                  *\n"
                 "*********************************************************************************************\n"
                 "Created by Amir Torabi. \n"
     << std::endl;
  	// exit(1);
}

string copy_next(int *index, string in){
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

void argselect(int argc, char** argv)
{
    const char* const opt = "hv";
    while(true)
    {
        const auto select = getopt(argc,argv,opt);
        if (-1 == select)
            break;
        switch(select)
        {
        case 'v':
            verbose = true;
            std::cout << "verbose mode On" << std::endl;
            break;
        case 'h':
            printhelp();
            break;
        case '?':
            default:
            std::cout <<  "Unknown command" << std::endl;
            break;
        }
    }
}

void add(string in)
{
    string res, cur;
    int index = 2;
    int carry = 0;
    int x,y,r;
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
        if(carry == 1){
            res.push_back('1');
            carry = 0;
        }
        index++;
    }
    string newstring = "";
    for(int i =res.size()-1; i >=0;i--) {
         res[i];
            }
        reverse(res.begin(), res.end());

        if(verbose == true)
        {
            cout << in << " = " << res;
            cout << endl;
        } else{
            cout << res;
            cout << endl;
        }

}

