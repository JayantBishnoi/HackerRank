#include <bits/stdc++.h>

using namespace std;

string pangrams(string s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
    int index,flag=26, alphabet[26]={0};
    for(int i=0;i<s.length();i++){
        if(s[i]==' ') continue;
        index = (int)s[i]-'a';
        alphabet[index]++;
        if(alphabet[index]==1) flag--;
        if(flag==0) break;
    }
    return (flag==0)?"pangram":"not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
