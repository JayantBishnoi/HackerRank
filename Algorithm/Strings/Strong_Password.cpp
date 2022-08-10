#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int minimumNumber(int n, string password){
    int flag_count = 4, flag[4] = {0};
    
    for(int i = 0; i < password.length(); i++){
        if(password[i] >= 'a' && password[i] <= 'z'){
            if(flag[0]==0) flag_count--;
            flag[0]=1;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            if(flag[1]==0) flag_count--;
            flag[1]=1;
        }
        else if(password[i] >= '0' && password[i] <= '9'){
            if(flag[2]==0) flag_count--;
            flag[2]=1;
        }
        else{
            if(flag[3]==0) flag_count--;
            flag[3]=1;
        }
        if(flag_count==0) break;
    }
    return max(flag_count, 6 - n);     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
