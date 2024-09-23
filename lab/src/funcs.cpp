#include <iostream>
#include <string>
#include "funcs.h"

#define VOWEL 0
#define CONSONANT 1
#define SYMBOL 2

namespace MySpace {
    int isVowel(const wchar_t letter) {
        std::wstring vowels(L"ёЁуУеЕыЫаАоОэЭяЯиИюЮ");
        std::wstring consonant(L"йЙцЦкКнНгГшШщЩзЗхХъЪфФвВпПрРлЛдДжЖчЧсСмМтТьЬбБ");
        for (int i = 0; i < (int)vowels.size(); ++i) {
            if (vowels[i] == letter)
                return VOWEL;
        }
        for (int i = 0; i < (int)consonant.size(); ++i) {
            if (consonant[i] == letter)
                return CONSONANT;
        }
        return SYMBOL;
    }

    std::wstring division(const std::wstring& str) {
        std::wstring result = L"";
        int begin = 0, flag = 0, distance = 0, end = 0, check = 0;
        for (int i = 0; i < (int)str.size(); ++i) {
            check = isVowel(str[i]);
            if (check == 2) return result;
            else if (check == 1)
                ++distance;
            else {
                if (flag) {
                    check = distance >= 2 ? 2 : 1; 
                    if (str[end + check] == L'ь' || str[end + check] == L'ъ') ++check;
                    result.insert(result.size(), str, begin, end - begin + check);
                    begin = end + check;
                    result += L"-";
                }
                flag = 1;
                end = i;
                distance = 0;
            }
        }
        result.insert(result.size(), str, begin, str.size() -  begin + 1);
        return result;
    }

    wchar_t* division(const wchar_t* str) {
        std::wstring str_t = str;
        std::wstring result = L"";
        int begin = 0, flag = 0, distance = 0, end = 0, check = 0;
        for (int i = 0; i < (int)str_t.size(); ++i) {
            check = isVowel(str_t[i]);
            if (check == 2) return (wchar_t*)result.c_str();
            else if (check == 1)
                ++distance;
            else {
                if (flag) {
                    check = distance >= 2 ? 2 : 1; 
                    if (str_t[end + check] == L'ь' || str_t[end + check] == L'ъ') ++check;
                    result.insert(result.size(), str_t, begin, end - begin + check);
                    begin = end + check;
                    result += L"-";
                }
                flag = 1;
                end = i;
                distance = 0;
            }
        }
        result.insert(result.size(), str_t, begin, str_t.size() -  begin + 1);
        
        size_t len = result.size() + 1;
        wchar_t* res_ptr = new wchar_t[len];
        if (!res_ptr) {
            return nullptr;
        }
        wcscpy(res_ptr, result.c_str());
         return res_ptr;
    }
}  // namespace MySpace
