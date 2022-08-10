#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    int flag=0;
    if(s[s.length()-2]=='P') flag++;
    else if(s.substr(0,2)=="12") flag+=2;
    if(flag==1 && s.substr(0,2)=="12") flag=0;
    string hr = s.substr(0,2);
    int hour = stoi(hr);
    if(flag==1) hour+=12;
    else if(flag==2) hour-=12;
    string ans=((hour<10)?"0":"")+to_string(hour)+s.substr(2,6);
    return ans;
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
