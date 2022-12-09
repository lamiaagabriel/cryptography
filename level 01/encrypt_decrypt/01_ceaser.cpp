/**
 * Encrypt by replacing the character to its key-th character after it.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int key;
    string str;
    cin >> str >> key;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (((str[i] - 'a') + key) % 26) + 'a';
        else if (isupper(str[i]))
            str[i] = (((str[i] - 'A') + key) % 26) + 'A';
    }
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (((str[i] - 'a') - key) + 26) % 26 + 'a';
        else if (isupper(str[i]))
            str[i] = (((str[i] - 'A') - key) + 26) % 26 + 'A';
    }
    cout << "Decrypted: " << str << endl;
    return 0;
}
