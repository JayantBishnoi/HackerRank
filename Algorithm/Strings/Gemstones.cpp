#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int gemstones(vector<string> arr) {
    int count=0,gems[26]={0};
    for(int i=0;i<arr.size();i++){
        string reference="";
        for(int j=0;j<arr[i].length();j++){
            int index = (int)arr[i][j]-'a';
            if(reference.find(arr[i][j])!=string::npos) continue;
            reference+=arr[i][j];
            gems[index]++;
        }
    }
    for(int i=0;i<26;i++){
        if(gems[i]==arr.size()) count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

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
