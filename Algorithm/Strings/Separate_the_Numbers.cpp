#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void separateNumbers(string s) {
    ll flag=0,initial;
    for(int i=1;i<=s.length()/2;i++){
        initial = stoll(s.substr(0,i));
        ll index=i;
        ll temp=initial;
        while(index!=s.length()){
            ll digits = log10(temp+1)+1;
            if(stoll(s.substr(index,digits))-temp==1){
                index+=digits;
                temp++;
                continue;
            }
            break;   
        }
        if(index==s.length()){
            flag++;
            break;
        }
    }
    cout<<((flag==1)?"YES "+to_string(initial):"NO")<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
