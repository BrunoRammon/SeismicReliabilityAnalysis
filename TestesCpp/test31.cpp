#include <sstream>
#include <iostream>

// class test
// {
// public:
//     std::stringstream _residualHistoryStream;
// private:
//     void func()
//     {
//         _residualHistoryStream << "bbbb\n";
//         std::cout << ss;
//     }
// };

int main()
{
    std::stringstream _residualHistoryStream;
    std::cout << _residualHistoryStream.rdbuf()->in_avail() << std::endl;
    _residualHistoryStream << "";

    std::cout << _residualHistoryStream.rdbuf()->in_avail() << std::endl;
}