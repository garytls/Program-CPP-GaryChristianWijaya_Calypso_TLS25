#include <iostream>
#include <string>
using namespace std;

string myReverse(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
    return s;
}

string decrypt(string code) {
    int pos = -1;
    for (int i = 0; i < code.length(); i++) {
        if (isdigit(code[i])) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return "Kode tidak valid!";

    string asciiStr = "";
    while (pos < code.length() && isdigit(code[pos])) {
        asciiStr += code[pos];
        pos++;
    }
    int asciiVal = stoi(asciiStr);
    char firstChar = (char)asciiVal;

    string raw = code.substr(0, pos - asciiStr.length()) + code.substr(pos);
    string reversed = myReverse(raw);
    if (!reversed.empty() && reversed[0] == firstChar) {
        reversed = reversed.substr(1);
    }
    string result = "";
    result += firstChar;
    result += reversed;

    return result + " (tanpa vokal)";
}

int main() {
    string input;
    cout << "Masukkan sandi: ";
    cin >> input;

    cout << "Hasil dekripsi: " << decrypt(input) << endl;

    return 0;
}
