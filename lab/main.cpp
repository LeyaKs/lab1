/**
 * \file 
 * \brief Main file
 */

#include <iostream>
#include <string>
#include "src/funcs.h"
#include "src/input.h"

/**
 * \brief Main fuction with dialogue with the user
 * 
 * Function has a do while loop to continue working
 */

int main() {
    setlocale(LC_CTYPE, "");
    bool  check = false;
    try {
        do {
            std::wcout << L"Enter word ---------> ";
            std::wstring str = input(check);
            if (!check) {
            std::wcout << "\nEOF" <<std::endl;
                return 0;
            }
            std::wstring result = MySpace::division(str);
            if (result.empty()) 
                std::wcout << L"Empty word or word contains other items" << std::endl;
            else
                std::wcout << L"Result ---------> " << result << std::endl;

                
            // size_t len = wcslen(L"ляляля") + 1;
            // wchar_t* str = new wchar_t[len];
            // if (!str) {
            //     delete[] str;
            //     return 0;
            // }
            // wcscpy(str, L"ляляля");
            // wchar_t* result = MySpace::division(str);
            //if (result == nullptr) {
                // delete[] str;
                // return 0;
            // }
            // std::wcout << L"Исходная строка: " << str << std::endl;
            // std::wcout << L"Результат: " << result << std::endl;
            // delete[] str;
            // delete[] result;
        } while(check);
    }
    catch(const std::exception& e) {
        std::wcerr << e.what() << std::endl;
    }
    catch(const std::runtime_error& e) {
        std::wcerr << "Input failed: " << e.what() << std::endl;
    }
    return 0;
}
