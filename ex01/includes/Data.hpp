#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>


class Data
{
        std::string strData;
        int intData;
        char charData;
    public:
        Data() = delete;
        Data(std::string strData, int intData, char charData):
            strData(strData), intData(intData), charData(charData) {}
        Data(const Data &other);
        Data& operator=(const Data &other);
        ~Data() {};
        std::string toString() const;
};

#endif
