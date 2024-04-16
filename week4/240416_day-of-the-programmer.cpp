// 240416
// https://www.hackerrank.com/challenges/day-of-the-programmer

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    bool is_leap = false;
    bool is_1918 = false;
    string ddmm = "";
    
    if(year < 1918){ 
        if(year % 4 == 0) is_leap = true;
    } else if(year > 1918) { 
        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) is_leap = true;
    } else is_1918 = true;
    
    if(is_1918) {
        if(is_leap) ddmm = "25.09.";
        else ddmm = "26.09.";

    } else {
        if(is_leap) ddmm =  "12.09.";
        else ddmm = "13.09.";
    }
    
    return ddmm + to_string(year);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
