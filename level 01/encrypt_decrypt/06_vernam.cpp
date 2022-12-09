#include <bits/stdc++.h>
using namespace std;

bool golombsPostulates(string key)
{
    int ones = 0, zeros = 0, gaps = 0, blocks = 0, runs = 0, pre_num_of_ones = 0, n = ceil(log2(key.length())), arr[n] = {0};
    for (int i = 0; i < key.length(); i++)
    {
        int num_of_ones = 0;

        // For Condition 1: abs(ones - zeros) == 1 at least
        if (key[i] == '0')
            zeros++;
        else if (key[i] == '1')
            ones++;

        // For condition 2: get the length of each sequance of runs
        if (i == 0 || key[i] == key[i - 1])
        {
            if (key[i] == '0')
                gaps++;
            else if (key[i] == '1')
                blocks++;
        }
        if (i && (key[i] != key[i - 1] || i + 1 == key.length()))
        {
            if (gaps > n || blocks > n) // More than the largest acceptable value
                return false;

            arr[max(gaps - 1, blocks - 1)]++;
            gaps = 1;
            blocks = 1;
            runs++;
        }

        // For condition 3: count how many 1's, and 0's each one of its XOR. with this check it is already passed consition 3
        for (int j = 0; j < key.length() && i > 0; j++)
            if ((int)(key[j] ^ key[(i + j) % key.length()]) == 1)
                num_of_ones++;
        if (i > 1 && pre_num_of_ones != num_of_ones)
            return false;
        pre_num_of_ones = num_of_ones;
    }

    // Check condition 1: the abs difference at least == 1
    if (abs(ones - zeros) <= 1)
    {
        // Check condition 2: half the runs have length 1, one-fourth have length 2, one-eighth have length 3, etc.
        for (int i = 1; i < n || arr[i] == 0; i++)
            if (i && abs(arr[i] - (runs / pow(2, i + 1))) > 1)
                return false;

        return true;
    }
    return false;
}

int main()
{
    string key, str;
    cin >> str >> key;

    if (str.length() == key.length() && golombsPostulates(key))
    {
        for (int i = 0; i < str.length(); i++)
            str[i] = (int)(str[i] ^ key[i]) + '0';
        cout << "Encrypted: " << str;

        cout << endl;

        for (int i = 0; i < str.length(); i++)
            str[i] = (int)(str[i] ^ key[i]) + '0';
        cout << "Decrypted: " << str;
    }
    return 0;
}
