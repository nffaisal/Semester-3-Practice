#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Task 1 Part A: Rail Fence Encryption


string rail_fence_encrypt(string text, int key)
{
    // If there is only one rail, ciphertext = plaintext
    if (key == 1)
        return text;

    vector<string> rails(key);

    int row = 0;
    int direction = 1;   // 1 =moving down, -1 =moving up

    // Put characters in zigzag form
    for (char ch : text)
    {
        rails[row] += ch;

        // Change direction at the top
        if (row == 0)
            direction = 1;

        // Change direction at the bottom
        else if (row == key - 1)
            direction = -1;

        row += direction;
    }

    // Read all rails from top to bottom
    string encrypted = "";

    for (int i = 0; i < key; i++)
    {
        encrypted += rails[i];
    }

    return encrypted;
}

// Task 1 Part B: Rail Fence Decryption

string rail_fence_decrypt(string ciphertext, int key)
{
    if (key == 1)
        return ciphertext;

    int length = ciphertext.length();

    // Stores the rail number for each character position
    vector<int> pattern;

    int row = 0;
    int direction = 1;

    // Create the zigzag pattern
    for (int i = 0; i < length; i++)
    {
        pattern.push_back(row);

        if (row == 0)
            direction = 1;

        else if (row == key - 1)
            direction = -1;

        row += direction;
    }


    // Count how many characters belong to each rail
    vector<int> railCount(key, 0);

    for (int i = 0; i < length; i++)
    {
        railCount[pattern[i]]++;
    }


    // Put ciphertext characters into their respective rails
    vector<string> rails(key);

    int index = 0;

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < railCount[i]; j++)
        {
            rails[i] += ciphertext[index];
            index++;
        }
    }
    // Read characters following the zigzag pattern
    string decrypted = "";
    vector<int> railPosition(key, 0);
    for (int i = 0; i < length; i++)
    {
        int currentRail = pattern[i];

        decrypted += rails[currentRail][railPosition[currentRail]];

        railPosition[currentRail]++;
    }

    return decrypted;
}

// Task 2: Brute Force Decryption

void rail_fence_brute_force(string ciphertext)
{
    cout << "\nBrute Force Results:\n";
    cout << "-------------------\n";

    // Try every possible key from 2
    // up to the length of the ciphertext
    for (int key = 2; key <= ciphertext.length(); key++)
    {
        string plaintext = rail_fence_decrypt(ciphertext, key);

        cout << "Key " << key << " : " << plaintext << endl;
    }
}

// Main Function

 int main()
{
  
    // Task 1: Encryption and Decryption
    string text = "HELLOWORLD";
    int key = 3;
    string encrypted = rail_fence_encrypt(text, key);
    string decrypted = rail_fence_decrypt(encrypted, key);
    cout << "Original Text : " << text << endl;
    cout << "Key           : " << key << endl;
    cout << "Encrypted     : " << encrypted << endl;
    cout << "Decrypted     : " << decrypted << endl;


    
    // Task 2: Brute Force Test Case 1
  

    cout << "\n\nTest Case 1";
    cout << "\nCiphertext: HOLELWRDLOX\n";

    rail_fence_brute_force("HOLELWRDLOX");
    // Task 2: Brute Force Test Case 2
    cout << "\n\nTest Case 2";
    cout << "\nCiphertext: AAXTKTNXTCDWXAAX\n";

    rail_fence_brute_force("AAXTKTNXTCDWXAAX");
    // Task 2: Brute Force Test Case 3
    cout << "\n\nTest Case 3";
    cout << "\nCiphertext: CYTGAHRPORPY\n";

    rail_fence_brute_force("CYTGAHRPORPY");


    return 0;
}