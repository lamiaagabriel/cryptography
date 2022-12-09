/**
 * Encrypting using a word key
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string key = "sesame", str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
        str[i] = (str[i] + key[i % key.length()] - 2 * 'a') % 26 + 'a';
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
        str[i] = (str[i] - key[i % key.length()] + 26) % 26 + 'a';
    cout << "Decrypted: " << str << endl;

    return 0;
}