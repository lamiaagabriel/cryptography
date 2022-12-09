/**
 * Encrypt by replacing the character to its k-th character after it.
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    string str;
    cin >> str >> k;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (((str[i] - 'a') + k) % 26) + 'a';
        else if (isupper(str[i]))
            str[i] = (((str[i] - 'A') + k) % 26) + 'A';
    }
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = (((str[i] - 'a') - k) + 26) % 26 + 'a';
        else if (isupper(str[i]))
            str[i] = (((str[i] - 'A') - k) + 26) % 26 + 'A';
    }
    cout << "Decrypted: " << str << endl;
    return 0;
}
