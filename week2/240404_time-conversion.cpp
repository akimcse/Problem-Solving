// 240404
// https://www.hackerrank.com/challenges/time-conversion

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string output;
    string new_hour_time;
    
    if(s[8] == 'P'){
        string hour = s.substr(0,2);
        int new_hour = stoi(hour) + 12;
        if(new_hour == 24) new_hour_time = "12";
        else new_hour_time = to_string(new_hour);
        string military = s.replace(0, 2, new_hour_time);
        output = military.erase(8,2);
    }
    
    if(s[8] == 'A'){
        string hour = s.substr(0,2);
        if(hour == "12"){
            new_hour_time = "00";
            string military = s.replace(0, 2, new_hour_time);
            output = military.erase(8,2);
        }
        else output = s.erase(8,2);
    }   

    return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
