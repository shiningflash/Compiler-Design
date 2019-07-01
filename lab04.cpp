#include <bits/stdc++.h>
using namespace std;

string _type[10] = {"auto", "double", "int",  "enum", "char", "float", "short", "void",
"bool", "long"};

bool _isType(string s) {
    for (int i = 0; i < 50; i++) if (s == _type[i]) return true;
    return false;
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 0;
    string s, ps, word, met, ret;
    puts("Methods:\n--------");
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            word = "";
            for (; i < s.size(); i++) {
                if (s[i]  == ' ') {
                    if (_isType(word)) {
                        bool flg = 0;
                        for (int j = i; j < s.size(); j++) if (s[j] == '(') flg = 1;
                        if (flg) {
                            met = "";
                            for (i++; i < s.size(); i++) {
                                if (s[i] == ')') {
                                    met += s[i];
                                    cout << ++t << ". " << met << ", return type: " << word << endl;
                                    word = "";
                                    if (met == "main(String [] args)") return 0;
                                    break;
                                }
                                else met += s[i];
                            }
                        }
                        else {
                            word = "";
                            break;
                        }
                    }
                    else {
                        word = "";
                        break;
                    }
                }
                else word += s[i];
            }
        }
    }
}
