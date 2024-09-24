/**
 * \file
 * \brief File with description of input functions
 */


#include <iostream>
#include <limits>



/**
 * \brief Input string
 * \param flag
 * \return str Resulting string
 */

std::wstring input(bool& flag) {
        std::wstring str;
        std::wcin >> str;
        do {
            if (std::wcin.eof() || std::wcin.bad()) {
                flag = false;
                return str;
            } else if (std::wcin.fail()) {
                std::wcin.clear();
                std::wcin.ignore(
                    std::numeric_limits<std::streamsize>::max(), '\n');
                std::wcout << L"Incorrect data! Try again ---------> ";
                std::wcin >> str;
            }
        } while (!std::wcin.good());
        flag = true;
        return str;
    }