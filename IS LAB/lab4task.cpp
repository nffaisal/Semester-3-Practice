#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string desPLaintextBlock(){
    string plaintext;
    cout<<"Enter PLaintext: ";
    getline(cin,plaintext);
    remove(plaintext.begin(),plaintext.end(),' '); //remove white spce
    while(plaintext.length()<64){ // padd the text
        plaintext = '0' + plaintext;
    }
    cout << "the  64 bit text is: "<< plaintext<<"\n ";

    return plaintext;
}
string initialPermutation(string plaintext) {

    int IP[8][8] = {
        {58, 50, 42, 34, 26, 18, 10, 2},
        {60, 52, 44, 36, 28, 20, 12, 4},
        {62, 54, 46, 38, 30, 22, 14, 6},
        {64, 56, 48, 40, 32, 24, 16, 8},
        {57, 49, 41, 33, 25, 17, 9, 1},
        {59, 51, 43, 35, 27, 19, 11, 3},
        {61, 53, 45, 37, 29, 21, 13, 5},
        {63, 55, 47, 39, 31, 23, 15, 7}
    };

    string result = "";

    for (int i = 0; i < 8; i++) { //loop through the array of permutation

        for (int j = 0; j < 8; j++) {

            int position = IP[i][j]; //store number

            result += plaintext[position - 1]; //change the letters position
        }
    }

    return result; //return permutated function
}
string desPermutedChoice1(string key)
{
    int PC1[8][7] = {
        {57,49,41,33,25,17,9},
        {1,58,50,42,34,26,18},
        {10,2,59,51,43,35,27},
        {19,11,3,60,52,44,36},
        {63,55,47,39,31,23,15},
        {7,62,54,46,38,30,22},
        {14,6,61,53,45,37,29},
        {21,13,5,28,20,12,4}
    };

    string permutedKey = "";

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            int position = PC1[i][j];

            // DES table positions start from 1
            permutedKey += key[position - 1];
        }
    }

    return permutedKey;
}

string desLeftShift(string block, int round)
{
    int shifts;

    if(round == 1 || round == 2 || round == 9 || round == 16)
    {
        shifts = 1;
    }
    else
    {
        shifts = 2;
    }

    for(int i = 0; i < shifts; i++)
    {
        // Save first bit
        char firstBit = block[0];

        // Move everything one position to the left
        block = block.substr(1);

        // Put first bit at the end
        block += firstBit;
    }

    return block;
}

string desPermutedChoice2(string block)
{
    int PC2[8][6] = {
        {14,17,11,24,1,5},
        {3,28,15,6,21,10},
        {23,19,12,4,26,8},
        {16,7,27,20,13,2},
        {41,52,31,37,47,55},
        {30,40,51,45,33,48},
        {44,49,39,56,34,53},
        {46,42,50,36,29,32}
    };

    string permutedKey = "";

    for(int i = 0; i < 8; i++)  //iternate through pc2
    {
        for(int j = 0; j < 6; j++)
        {
            int position = PC2[i][j];

            // DES positions start from 1
            permutedKey += block[position - 1];
        }
    }

    return permutedKey;
}
int main(){
    desPLaintextBlock();
}