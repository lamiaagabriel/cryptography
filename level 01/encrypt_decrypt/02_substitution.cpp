/**
 * Encrypt by replacing the character to its equivalent one in the key string.
 *      As the first letter 'A' == 'Q' in the key string, and 'B' == 'W', and so on.
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string key = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm", str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        int index = (isupper(str[i])) ? str[i] - 'A' : str[i] - 'a' + 26;
        str[i] = key[index];
    }
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        int index = key.find(str[i]);
        str[i] = (index <= 25) ? index + 'A' : index + 'a' - 26;
    }
    cout << "Decrypted: " << str << endl;

    return 0;
}