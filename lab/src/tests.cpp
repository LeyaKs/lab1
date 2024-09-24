#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include "funcs.h"

TEST_CASE(){
    std::wstring str = L"бубубу";
    std::wstring str1 = L"бу3бубу";
    REQUIRE(MySpace::division(str) == L"бу-бу-бу");
    REQUIRE(MySpace::division(str1) == L"");
    size_t len = wcslen(L"ляляля") + 1;
    std::wstring res = L"ля-ля-ля";
    wchar_t* str2 = new wchar_t[len];
    wcscpy(str2, L"ляляля");
    if (!str2) delete[] str2;
    REQUIRE(wcscmp(MySpace::division(str2), res.c_str()) == 0);
}