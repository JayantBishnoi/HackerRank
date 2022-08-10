#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    int i,flag;
    while(true){
        flag=0;
        for(i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                flag++;
                break;
            }
        }
        if(flag==0) break;
        s.erase(i,2);
        if(s.empty())break;
    }
    return ((s.empty())?"Empty String":s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
