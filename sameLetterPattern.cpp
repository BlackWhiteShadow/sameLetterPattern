/* 
sameLetterPattern.cpp : Create a function that returns true if two strings share the same letter pattern, and false otherwise.

sameLetterPattern("ABAB", "CDCD") ➞ true
sameLetterPattern("ABCBA", "BCDCB") ➞ true
sameLetterPattern("FFGG", "CDCD") ➞ false
sameLetterPattern("FFFF", "ABCD") ➞ false
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> combination(string str)
{
    vector<char> arr;
    copy(str.begin(), str.end(), back_inserter(arr));
    vector<int> comb;
    int different = 1;
    comb.push_back(different);
    bool isSame = false;

    for (int i = 1; i < arr.size(); i++)
    {
        isSame = false;
        for (int j = 0; j < i; j++)
            if (arr[i] == arr[j])
            {
                isSame = true;
                comb.push_back(comb[j]);
                break;
            }
        if (isSame == true)
            continue;
        else
            comb.push_back(++different);
    }

    return comb;
}

bool sameLetterPattern(string str1, string str2) 
{
    vector<int> result1 = combination(str1);
    vector<int> result2 = combination(str2);

    return equal(result1.begin(), result1.end(), result2.begin());
}

int main()
{
    string str1, str2;

    cout << "Enter str1: ";
    cin >> str1;
    cout << "Enter str2: ";
    cin >> str2;
    cout << sameLetterPattern(str1, str2);
}

