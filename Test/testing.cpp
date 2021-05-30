#pragma region includes
#include <sstream>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept> 
#include <iomanip>
#include <vector>
#pragma endregion

#pragma region usings
using std::cout; 
using std::cin; 
using std::endl;
using std::string; 
using std::exception;
using std::vector;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::stringstream;
#pragma endregion

int countWrds(string str);

int main() {
    string str1 = "Hello   bfb suejs jise    ds ss    sdd  33 333   dnj";
    string str2 = "     Hello   bfb suejs jise    ds ss    sdd  33 333   dnj";

    string str3 = "saveas \"C:\\Temp\\another file.xml\"";

    cout << "1: " << countWrds(str1) << endl;
    cout << "2: " << countWrds(str2) << endl;
    cout << "3: " << countWrds(str3) << endl;

    return 0;
}

int countWrds(string str) {
    stringstream s(str);
    string word;

    int count = 0;
    while (s >> word) {
        ++count;
    }

    return count;
}
