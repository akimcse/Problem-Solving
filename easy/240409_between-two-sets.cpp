// 240409
// https://www.hackerrank.com/challenges/between-two-sets

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 *
 * factor: 인수........ ^_^
 * 첫번째 element들을 인수로 갖고, 동시에 두번째 element들의 인수인 수 x의 개수를 출력하면 됨
 */

int getTotalX(vector<int> a, vector<int> b) {
    vector<int> factors;
    vector<int> x;
    
    // 먼저 두번째 vector element의 인수인지 확인하여 factors vector에 추가
    for(int i = 1; i <= 100; i++) {
        bool isFactor = true;
        for(int j = 0; j < (int)b.size(); j++) {
            if(b[j] % i != 0) {
                isFactor = false;
                break;
            }
        }
        if(isFactor) {
            factors.push_back(i);
        }
    }
    
    // 다음으로 factors vector의 element들이 첫번째 vector element의 배수인지 확인하여 최종 x vector에 추가
    for(int i = 0; i < (int)factors.size(); i++) {
        bool isMultiple = true;
        for(int j = 0; j < (int)a.size(); j++) {
            if(factors[i] % a[j] != 0) {
                isMultiple = false;
                break;
            }
        }
        if(isMultiple) {
            x.push_back(i);
        }
    }
    
    return x.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
