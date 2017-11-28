#pragma once

class BigInt
{
private:   
    bool verbose;
    
public:
    void put_verbose(bool verb);
    std::string copy_next(int *index, std::string in);
    std::string add(std::string in,bool printResult);
    std::string multiply(std::string in, bool printResult);
    std::string exponent(std::string in);
    
};
