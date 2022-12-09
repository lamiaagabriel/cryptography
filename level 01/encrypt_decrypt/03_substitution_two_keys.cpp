/**
 * Encrypt by replacing the character to its equivalent one in the key string,
 * depending on its position wether it is even or odd.
 *      As the first letter 'A' == 'Q' according to the key1 string, if it was in an odd position.
 *      And it is 'M' according to the key2 string, if it was in an even position.
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string key1 = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm", key2 = "MNBVCXZLKJHGFDSAPOIUYTREWQmnbvcxzlkjhgfdsapoiuytrewq", str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        int index = (isupper(str[i])) ? str[i] - 'A' : str[i] - 'a' + 26;
        str[i] = (i % 2 == 0) ? key1[index] : key2[index];
    }
    cout << "Encrypted: " << str << endl;

    for (int i = 0; i < str.length(); i++)
    {
        int index = (i % 2 == 0) ? key1.find(str[i]) : key2.find(str[i]);
        str[i] = (index <= 25) ? index + 'A' : index + 'a' - 26;
    }
    cout << "Decrypted: " << str << endl;

    return 0;
}