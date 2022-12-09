#include <bits/stdc++.h>
using namespace std;

string permutate(string str, int key[])
{
    string chunks = "";
    int pos = 0;

    for (int i = 0; i < str.length(); i++) // Lowercase the letters, split into chunks of 5 letter each
    {
        if (str[i] == ' ')
            continue;
        else if (pos && pos % 5 == 0)
            chunks += " ";

        chunks += isupper(str[i]) ? str[i] + 32 : str[i];
        pos++;
    }

    while ((chunks.length() - (chunks.find_last_of(" ") + 1)) < 5) // Fill the last chunk with random letters -- O(4)
        chunks += (char)(rand() % 26 + 'a');

    pos = 0, str = "";
    for (int i = 0; i < chunks.length(); i++) // Encrypt the chunks, according to permutation key
    {
        if (chunks[i] == ' ')
        {
            pos = 0;
            continue;
        }
        str += chunks[i + ((key[pos] + pos) % 5 - pos) % 5];
        pos++;
    }

    return str;
}

int main()
{
    string str;
    int key[5] = {2, 4, 1, 3, 5};
    getline(cin, str);
    str = permutate(str, key);
    cout << "Cipher text: " << str;

    return 0;
}
