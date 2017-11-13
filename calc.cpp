
#include <getopt.h>
#include <sstream>
#include "BigInt.h"

bool verbose = false;

void printhelp();
void argselect(int argc, char** argv);



int main(int argc, char** argv)
{
cout << "\nType help for program use information. Type quit to exit.\n\n";
    argselect(argc, argv);

    string input;
    string sstream;
    stringstream readline(input);

    readline >> sstream;
    //readline.ignore(input.length(),'#');

    while (getline(cin, input) || !readline.eof())
    {
        if (input[0] == '#') continue;
        if (tolower(input[0]) == 'q') { return 0; }
        if (tolower(input[0]) == 'h')
        {
            printhelp();
        }
        else {

            for (int i = 0; i <(int) input.size(); i++) {
                if (!(input[i] == '*' || input[i] == '^' || input[i] == '+' || input[i] == ' ' || (input[i] >= '0' && input[i] <= '9')))
                {
                    cout << "Please give one operator(+,*,^) and integer based operands.\n";
                    //return 0;
                    break;
                }
            }
            BigInt BI;
            if(verbose)
                BI.put_verbose(true);
            else
                BI.put_verbose(false);
            if(input[0]=='+') BI.add(input,true);
            if (input[0] == '*') BI.multiply(input,true);
            if (input[0] == '^') BI.exponent(input);
            cout << endl;
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
                 "* type 'quit' or just 'q' to exit the program                                               *\n"
                 "* ..........................................................................................*\n"
                 "* You can process a file with one operator and multiple operands per line.                  *\n"
                 "*********************************************************************************************\n"
                 "Created by Amir Torabi. \n"
    << std::endl;
        //exit(1);
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

