#include <bits/stdc++.h>
using namespace std;
 
string _keyword[50] = {"auto",  "double", "else",   "int",  "struct", "break",
"switch", "case",   "enum", "register", "typedef", "char",  "extern",   "return",
"union", "const",   "float",    "short",    "unsigned", "continue", "for",
"default",  "goto", "sizeof", "do", "if",   "static",   "while", "void",
"bool", "explicit", "new", "catch", "false",    "operator", "template",
"class",    "private",  "this", "inline",   "public",   "throw", "signed",
"delete",   "protected",    "true", "try",  "typename", "using", "long"};
 
string _operator[10] = {"+", "-", "*", "/", "+=", "-=", "%", "=", "++", "--"};
 
string _logical_operator[9] = {"==", "!=", ">", "<", "<=", ">=", "&&", "||", "!"};
 
bool _isKeyword(string s) {
    for (int i = 0; i < 50; i++) if (s == _keyword[i]) return true;
    return false;
}
 
bool _isMathOperator(string s) {
    for (int i = 0; i < 10; i++) if (s == _operator[i]) return true;
    return false;
}
 
bool _isLogicalOperator(string s) {
    for (int i = 0; i < 9; i++) if (s == _logical_operator[i]) return true;
    return false;
}
 
bool _isNumericValues(string s) {
    for (int i = 0; i < s.size(); i++)
        if ((s[i] == '.' && s.size() > 1) || (s[i] >= '0' && s[i] <= '9')) return true;
    return false;
}
 
bool _isIdentifier(string s) {
    if (isalpha(s[0])) return true;
    return false;
}
 
int main() {
    freopen("in", "r", stdin);
    string s[10000], ss, word;
    int idx = 0;
    set <string> kw, id, mo, lo, nv, ot;
    while (getline(cin, s[idx])) {
        stringstream ss(s[idx]);
        while (ss >> word) {
            if (_isKeyword(word)) kw.insert(word);
            else if (_isIdentifier(word)) id.insert(word);
            else if (_isMathOperator(word)) mo.insert(word);
            else if (_isLogicalOperator(word)) lo.insert(word);
            else if (_isNumericValues(word)) nv.insert(word);
            else ot.insert(word);
        }
        idx++;
    }
    set <string> :: iterator it;
    printf("Keywords: ");
    for (it = kw.begin(); it != kw.end(); it++) cout << *it << ", ";
    printf("\n");
 
    printf("Identifiers: ");
    for (it = id.begin(); it != id.end(); it++) cout << *it << ", ";
    printf("\n");
 
    printf("Math Operators: ");
    for (it = mo.begin(); it != mo.end(); it++) cout << *it << ", ";
    printf("\n");
 
    printf("Logical Operators: ");
    for (it = lo.begin(); it != lo.end(); it++) cout << *it << ", ";
    printf("\n");
 
    printf("Numerical Values: ");
    for (it = nv.begin(); it != nv.end(); it++) cout << *it << ", ";
    printf("\n");
 
    printf("Others: ");
    for (it = ot.begin(); it != ot.end(); it++) cout << *it << " ";
    printf("\n");
}
