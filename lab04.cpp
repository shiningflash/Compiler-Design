#include <bits/stdc++.h>
using namespace std;

string _keyword[50] = {"auto",  "double", "else",   "int",  "struct", "break",
"switch", "case",   "enum", "register", "typedef", "char",  "extern",   "return",
"union", "const",   "float",    "short",    "unsigned", "continue", "for",
"default",  "goto", "sizeof", "do", "if",   "static",   "while", "void",
"bool", "explicit", "new", "catch", "false",    "operator", "template",
"class",    "private",  "this", "inline",   "public",   "throw", "signed",
"delete",   "protected",    "true", "try",  "typename", "using", "long"};

bool _isKeyword(string s) {
    for (int i = 0; i < 50; i++) if (s == _keyword[i]) return true;
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string s, ps, word, met, ret;
    puts("Methods:");
    while (getline(cin, s)) {
        stringstream ss(s);
        vector <string> v;
        while (ss >> word) {
            v.push_back(word);
        }
        bool flag = false;
        for (int i = 0; i < v.size(); i++) {
                if (_isKeyword(v[i])) {
                    ret = v[i];
                    for (int k = 0; k < v[i+1].size(); k++) {
                        if (v[i+1][k] == '(') {
                            flag = true;
                            met = v[i+1];
                            for (int j = i+2; j < v.size(); j++) {
                                met = met + v[j];
                            }
                        }
                    }
                }
            }
            cout << met << ", return type: " << ret << endl;
        }
    }
