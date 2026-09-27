#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string keyword, userentered;

    cout << "Enter the Keyword: ";
    getline(cin, userentered);


    // ==========================================
    // CREATE PLAYFAIR MATRIX
    // ==========================================

    // keyword will eventually contain all 25 letters
    string text, result;

    // Add keyword letters
    for(int i = 0; i < userentered.length(); i++)
    {
        char c = toupper(userentered[i]);

        // Replace J with I
        if(c == 'J')
        {
            c = 'I';
        }

        // Ignore spaces
        if(isspace(c))
        {
            continue;
        }

        // Add only unique letters
        if(keyword.find(c) == string::npos)
        {
            keyword += c;
        }
    }
    // Add remaining alphabet letters
    for(char c = 'A'; c <= 'Z'; c++)
    {
        // Skip J
        if(c == 'J') { continue; }

        // Add only unused letters
        if(keyword.find(c) == string::npos)
        {
            keyword += c;
        }
    }
    // Put letters into 5x5 matrix
    char playfair[5][5];

    int index = 0;

    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; col < 5; col++)
        {
            playfair[row][col] = keyword[index];

            index++;

            cout << playfair[row][col] << " ";
        }

        cout << endl;
    }
     //Creating PlainText

    cout << "Enter a plaintext: ";
    getline(cin, text);


    for(int i = 0; i < text.length(); )
    {
        // Detect whitespace
        if(!isspace(text[i]))
        {
            // Convert to uppercase
            text[i] = toupper(text[i]);

            // Replace J with I
            if(text[i] == 'J')
            {
                text[i] = 'I';
            }
            // Last character
            if(i + 1 >= text.length())
            {
                result += text[i];
                i++;
            }
            // Repeated letters
            else if(text[i] == text[i + 1])
            {
                result += text[i];
                result += 'X';

                // Only move one position
                i++;
            }
            else
            {
                result += text[i];
                result += text[i + 1];
                // Move two positions
                i += 2;
            }
        }

        // Skip whitespace
        else
        {     i++;   }
    }


    // Make length even
    if(result.length() % 2 != 0)
    {
        result += 'X';
    }


    cout << "\nPrepared plaintext: " << result << endl;


    return 0;
}