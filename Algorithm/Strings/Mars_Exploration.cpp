#include <bits/stdc++.h>

using namespace std;

int marsExploration(string s) {
    int count=0;
    for(int i=0;i<s.length();i++){
        if(i%3==0 || i%3==2){
            if(s[i]!='S') count++;
        }
        else if(s[i]!='O') count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
