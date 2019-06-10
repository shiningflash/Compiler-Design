/*
    @author : Amirul Islam (17101537)
    @date   : 27 May, 2019 (mon)
    @task   : lab 02 (email and web validity checker)
*/

#include <bits/stdc++.h>
using namespace std;

/*
    :: E-mail address format

   LOCAL_PART
    ----------
    The local-part of the email address may use any of these ASCII characters:
    - uppercase and lowercase Latin letters A to Z and a to z;
    - digits 0 to 9;
    - printable characters !#$%&'*+-/=?^_`{|}~;

   DOMAIN_PART
    ----------
    * only one @ is allowed, not more or less
    - uppercase and lowercase Latin letters A to Z and a to z;
    - digits 0 to 9, provided that top-level domain names are not all-numeric;

    Ref: https://en.wikipedia.org/wiki/Email_address
*/

bool local_Valid(char ch) {
    return ((ch >= 35 && ch <= 39) || (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 94 && ch <= 126) || ch == 33 || ch == 61 || ch == 63);
}

bool domain_Valid(char ch, char pre) {
    if (ch == '.' && pre != '.') return true;
    return ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}

bool check_mail(string address) {
    int i(0), state(0), valid_mail(0);
    while (i < address.size()) {
        if (state == 0 && (local_Valid(address[i]))) state = 1;
        else if (state == 1 && (local_Valid(address[i]) || (address[i] == 46 && address[i-1] != 46))) state = 1;
        else if (state == 1 && address[i] == '@') state = 2;
        else if ((state == 2 || state == 3) && domain_Valid(address[i], address[i-1])) state = 3;
        else return false;
        i++;
    }
    return (state == 3);
}

int check_http(string s) {
    bool flag = 0;
    if (s[0] == 'h' && s[1] == 't' && s[2] == 't' &&  s[3] == 'p') flag = 1;
    if (flag == 1 && s[4] == ':' && s[5] == '\\' && s[6] == '\\') return 7;
    if (flag == 1 && s[4] == 's' && s[5] == ':' && s[6] == '\\' && s[7] == '\\') return 8;
    return 0;
}

bool web_part(char ch) {
    return ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}

bool check_website(string address) {
    int i = check_http(address), state = 0;
    while (i < address.size()) {
        if ((state == 0 || state == 1) && web_part(address[i])) state = 1;
        else if (state == 1 && (address[i] == '.' || address[i] == '\\')) state = 2;
        else if ((state == 2 || state == 3) && web_part(address[i])) state = 3;
        else if (state == 3 && (address[i] == '.' || address[i] == '\\')) state = 2;
        else return false;
        i++;
    }
    return (state == 3);
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    string address;
    int tst;
    scanf("%d", &tst);
    getchar();
    for (int t(1); t <= tst; t++) {
        getline(cin, address);
        if (check_mail(address)) printf("%s, %d\n", "Email", t);
        else printf("%s, %d\n", (check_website(address) ? "Web" : "Invalid address"), t);
    }
}