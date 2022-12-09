/**
 * Encrypting using a word key
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string key, str;
    cin >> str >> key;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (str[i] + key[i % key.length()] - 2 * 'a') % 26 + 'a';
        else if (isupper(str[i]))
            str[i] = (str[i] + key[i % key.length()] - 2 * 'A') % 26 + 'A';
    }
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (str[i] - key[i % key.length()] + 26) % 26 + 'a';
        else if (isupper(str[i]))
            str[i] = (str[i] - key[i % key.length()] + 26) % 26 + 'A';
    }

    cout << "Decrypted: " << str << endl;

    return 0;
}