#include <cstdio>
#include <iostream>
#include <regex>
using namespace std;

void string_replace(string &s1, const string &s2, const string &s3) {
    string::size_type pos = 0;
    string::size_type a = s2.size();
    string::size_type b = s3.size();
    while ((pos = s1.find(s2, pos)) != string::npos) {
        s1.replace(pos, a, s3);
        pos += b;
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        string text, re;

        cin >> text >> re;
        //cout << text << endl << re << endl;
        string_replace(re, ".*", "(.)?\\1*");
        // cout << text <<" "<< re << endl;

        regex e(re);
        cout << (regex_match(text, e) ? "yes" : "no") << endl;
    }

    return 0;
}