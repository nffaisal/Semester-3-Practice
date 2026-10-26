#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string> desPlaintextblock(string plaintext){ //lab 5 task 1  //first formatting the plaintext
        vector<string> blocks;
        for(int i=0; i<plaintext.length(); i+=64){   // FIX: was i<=, which created an extra all-zero block when length was a multiple of 64
            string block =plaintext.substr(i,64); //add all of the string
            while(block.length() <64){  //if string length is less than 64 then pad it until the end with 0
                block +='0';
            }
            blocks.push_back(block); //combine the string with the vector
        }
        return blocks;
}
string desInitialPermutation(string plaintext){  //Lab 5 task 2   // FIX: parameter was vector<string>, but a single block (string) is passed in
         //performing permutation according to the 8x8 IP table
        int IP[8][8] =   {   //Initial IP table
        {58, 50, 42, 34, 26, 18, 10, 2},
        {60, 52, 44, 36, 28, 20, 12, 4},
        {62, 54, 46, 38, 30, 22, 14, 6},
        {64, 56, 48, 40, 32, 24, 16, 8},
        {57, 49, 41, 33, 25, 17,  9, 1},
        {59, 51, 43, 35, 27, 19, 11, 3},
        {61, 53, 45, 37, 29, 21, 13, 5},
        {63, 55, 47, 39, 31, 23, 15, 7}
    };
    string permutatedblock ="";    //empty string that will contain the permutated block
     for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int position =IP[i][j];
            permutatedblock += plaintext[position- 1]; //add position of that text to the new text
     }
    }
    return permutatedblock;
}

string desPermutatedChoice1(string text){   //Lab 5 task 3
    int PCP[8][7] ={   //table
        {57,49,41,33,25,17,9},
        {1,58,50,42,34,26,18},
        {10,2,59,51,43,35,27},
        {19,11,3,60,52,44,36},
        {63,55,47,39,31,23,15},
        {7,62,54,46,38,30,22},   // FIX: was {7,63,54,46,38,39,22} (typos in the table)
        {14,6,61,53,45,37,29},
        {21,13,5,28,20,12,4}
    };
    string permutatedChoice =""; //final permutated choice string
    for(int i=0;i<8;i++){
        for(int j=0;j<7;j++){
            int position =PCP[i][j];
            permutatedChoice +=text[position-1];   // FIX: was "=", which overwrote the string each time instead of appending
        }
    }
    return permutatedChoice;
}
string desLeftShift(string text,int round ){ //lab 5 task 4
 
    int shifts;
    if (round == 1 || round == 2 || round == 9 || round == 16) //first decide how many bits to shift
        shifts = 1;
    else
        shifts = 2;
    for(int i =0;i<shifts;i++){ //for number of shifts
        char firstbit = text[0];       //store first bit
        for(int j=0;j<text.length() -1;j++){    //now shift everything 1 bit
            text[j]=text[j+1];
        }

        text[text.length()-1] =firstbit; //add the stored first bit to the end
    }                                    //if two shifts redo the storing and shifting again 
    return text;
}

string desPermutatedChoice2(string text){   //Lab 5 task 5
    int PCP[8][6] ={   //table
        {14,17,11,24,1,5,},
        {3,28,15,6,21,10},
        {23,19,12,4,26,8},
        {16,7,27,20,13,2},
        {41,52,31,37,47,55},
        {30,40,51,45,33,48},
        {44,49,39,56,34,53},
        {46,42,50,36,29,32}
    };
    string permutatedChoice2 =""; //final permutated choice string
    for(int i=0;i<8;i++){
        for(int j=0;j<6;j++){
            int position =PCP[i][j];
            permutatedChoice2 +=text[position -1];
        }
    }
    return permutatedChoice2;
}
string desExpansionPermutation(string plaintext){ // Lab 6 task 1-A
    int EXPtable[8][6] ={
        {32,1,2,3,4,5},
        {4,5,6,7,8,9},
        {8,9,10,11,12,13},
        {12,13,14,15,16,17},
        {16,17,18,19,20,21},
        {20,21,22,23,24,25},
        {24,25,26,27,28,29},
        {28,29,30,31,32,1}
    };
    string expanded =""; //expanded string string
    for(int i=0;i<8;i++){
        for(int j=0;j<6;j++){
            int position =EXPtable[i][j];
            expanded +=plaintext[position -1] ; //adding to the empty string
        }
    }
    return expanded;
}
  
int BOXES[8][4][16] = { //all the s boxes in a 3D matrix
    // S1
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },

    // S2
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },

    // S3
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },

    // S4
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },

    // S5
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },

    // S6
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },

    // S7
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },

    // S8
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}
    }
};

string getSubBox(string text, int boxNumber) //lab 6 task 2
{
    // First and last bits determine the row
    string rowBits = "";
    rowBits += text[0];
    rowBits += text[5];

    int row = stoi(rowBits, nullptr, 2);

    // Middle four bits determine the column
    string columnBits = text.substr(1, 4);
    int column = stoi(columnBits, nullptr, 2);

    // Get the decimal value from the selected S-box
    int value = BOXES[boxNumber][row][column];

    // Convert the value into 4-bit binary
    string result = "";
    for (int i = 3; i >= 0; i--)  { 
          result += ((value >> i) & 1) + '0';
    }

    return result;
}

string getSubBoxes(string text) //lab 6 task 1-B: 48 bits in, 32 bits out (uses all 8 S-boxes)
{
    string result = "";
    for (int i = 0; i < 8; i++)
    {
        string sixBits = text.substr(i * 6, 6);
        result += getSubBox(sixBits, i);
    }
    return result;
}

string desRoundPermutation(string text) //to make the permutated round block
{
    int RP[4][8] = {
        {16, 7, 20, 21, 29, 12, 28, 17},
        {1, 15, 23, 26, 5, 18, 31, 10},
        {2, 8, 24, 14, 32, 27, 3, 9},
        {19, 13, 30, 6, 22, 11, 4, 25}
    };

    string permutatedBlock = "";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int position = RP[i][j];
            permutatedBlock += text[position - 1];
        }
    }
    return permutatedBlock;
}
string desFinalPermutation(string text)  //lab task 4 //final permutation to get 64 bit 
{
    int FP[8][8] = {
        {40, 8, 48, 16, 56, 24, 64, 32},
        {39, 7, 47, 15, 55, 23, 63, 31},
        {38, 6, 46, 14, 54, 22, 62, 30},
        {37, 5, 45, 13, 53, 21, 61, 29},
        {36, 4, 44, 12, 52, 20, 60, 28},
        {35, 3, 43, 11, 51, 19, 59, 27},
        {34, 2, 42, 10, 50, 18, 58, 26},
        {33, 1, 41, 9, 49, 17, 57, 25}
    };
    string permutatedBlock = "";
    for (int i = 0; i < 8; i++){
          for (int j = 0; j < 8; j++)
        {
            int position = FP[i][j]; //swap positioning
            permutatedBlock += text[position - 1];
        }
    }
   return permutatedBlock;
}
string desXOR(string a, string b) //helper function instead of repeatedly wring XOR
{
    string result = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }
   return result;
}
vector<string> desGenerateRoundKeys(string key) //function to generate all the round keys
{
    vector<string> roundKeys;
    string permutedKey = desPermutatedChoice1(key);
    string C = permutedKey.substr(0, 28);
    string D = permutedKey.substr(28, 28);

    for (int round = 1; round <= 16; round++) //creating round keys
    {
        C = desLeftShift(C, round);
        D = desLeftShift(D, round);

        string combined = C + D;

        string roundKey = desPermutatedChoice2(combined);

        roundKeys.push_back(roundKey);
    }
    return roundKeys;
}

string desCrypt(string plaintext, vector<string> roundKeys) //16-round Feistel engine used by both encryption and decryption
{
    // Divide plaintext into 64-bit blocks
    vector<string> blocks = desPlaintextblock(plaintext);

    string encryptedText = "";

    // Encrypt each block separately
    for (int b = 0; b < blocks.size(); b++)
    {
        // Initial permutation
        string permutedBlock = desInitialPermutation(blocks[b]);

        // Split into left and right halves
        string L = permutedBlock.substr(0, 32);
        string R = permutedBlock.substr(32, 32);

        // Perform 16 DES rounds
        for (int round = 0; round < 16; round++)
        {
            // Expand right half: 32 bits -> 48 bits
            string expanded = desExpansionPermutation(R);
            string xorResult = desXOR(expanded, roundKeys[round]);
            string sBoxResult = getSubBoxes(xorResult);

            // Apply round permutation
            string fResult = desRoundPermutation(sBoxResult);

            // XOR with left half to get new right half
            string newR = desXOR(L, fResult);

            // Move old right half to left
            L = R;
            R = newR;
        }

        // Swap halves after the 16th round
        string combined = R + L;

        // Apply final permutation
        string encryptedBlock = desFinalPermutation(combined);

        encryptedText += encryptedBlock;
    }

    return encryptedText;
}

string desEncryption(string plaintext, string key) //Lab 6 task 2-A: final encryption method
{
    vector<string> roundKeys = desGenerateRoundKeys(key);   // K1 ... K16
    return desCrypt(plaintext, roundKeys);
}

string desDecryption(string ciphertext, string key) //Lab 6 task 2-B: same algorithm, keys in reverse order
{
    vector<string> roundKeys = desGenerateRoundKeys(key);
    vector<string> reversedKeys(roundKeys.rbegin(), roundKeys.rend());   // K16 ... K1
    return desCrypt(ciphertext, reversedKeys);
}

string binToHex(string bits) //only used to print results in hex as well
{
    string hex = "";
    for (int i = 0; i + 3 < bits.length(); i += 4)
    {
        int v = stoi(bits.substr(i, 4), nullptr, 2);
        hex += "0123456789ABCDEF"[v];
    }
    return hex;
}

void printGroups(string label, string bits, int group) //prints bits split in groups so they are easy to read
{
    cout << label;
    for (int i = 0; i < bits.length(); i++)
    {
        if (i % group == 0 && i != 0) cout << " ";
        cout << bits[i];
    }
    cout << endl;
}

int main()
{
    string plaintext =
        "0000000100100011010001010110011110001001101010111100110111101111";

    string key =
        "0001001100110100010101110111100110011011101111001101111111110001";

    cout <<"KEY CONVERSION " << endl;
    printGroups("Original 64-bit key : ", key, 8);
    string pc1 = desPermutatedChoice1(key);
    printGroups("After PC1 (56 bits) : ", pc1, 7);
    cout << "C0 = " << pc1.substr(0, 28) << endl;
    cout << "D0 = " << pc1.substr(28, 28) << endl;

    vector<string> roundKeys = desGenerateRoundKeys(key);
    cout << endl << "16 Round keys (48 bits, after shifts + PC2):" << endl;
    for (int i = 0; i < 16; i++)
        printGroups("K" + to_string(i + 1) + (i < 9 ? " : " : ": "), roundKeys[i], 6);

    cout << endl << "ROUND " << endl;
    printGroups("Plaintext (64)      : ", plaintext, 8);
    string ip = desInitialPermutation(plaintext);
    printGroups("After IP (64)       : ", ip, 8);
    string L0 = ip.substr(0, 32);
    string R0 = ip.substr(32, 32);
    cout << "L0 = " << L0 << endl;
    cout << "R0 = " << R0 << endl;

    cout << endl << "--- Task 1-A: desExpansionPermutation (32 -> 48) ---" << endl;
    string expanded = desExpansionPermutation(R0);
    printGroups("Input  (32 bits): ", R0, 4);
    printGroups("Output (48 bits): ", expanded, 6);

    cout << endl << "--- XOR with round key K1 ---" << endl;
    string xored = desXOR(expanded, roundKeys[0]);
    printGroups("Expanded R0     : ", expanded, 6);
    printGroups("K1              : ", roundKeys[0], 6);
    printGroups("XOR result (48) : ", xored, 6);

    cout << endl << "--- Task 1-B: getSubBoxes (48 -> 32), S-box substitution ---" << endl;
    for (int i = 0; i < 8; i++)
    {
        string six = xored.substr(i * 6, 6);
        cout << "S" << i + 1 << ": input " << six << " (row " << six[0] << six[5]
             << ", col " << six.substr(1, 4) << ") -> " << getSubBox(six, i) << endl;
    }
    string sboxOut = getSubBoxes(xored);
    printGroups("Input  (48 bits): ", xored, 6);
    printGroups("Output (32 bits): ", sboxOut, 4);

    cout << endl << "Task 1-C: desRoundPermutation" << endl;
    string rp = desRoundPermutation(sboxOut);
    printGroups("Input  (32 bits): ", sboxOut, 4);
    printGroups("Output (32 bits): ", rp, 4);

    cout << endl << "Task 1-D: desFinalPermutation" << endl;
    string fpInput = "0000000100100011010001010110011110001001101010111100110111101111";
    string fpOutput = desFinalPermutation(fpInput);
    printGroups("Input  (64 bits): ", fpInput, 8);
    printGroups("Output (64 bits): ", fpOutput, 8);

    cout << endl << " 2-A: desEncryption" << endl;
    string encrypted = desEncryption(plaintext, key);
    printGroups("Plaintext  : ", plaintext, 8);
    printGroups("Ciphertext : ", encrypted, 8);
    cout << "Ciphertext (hex): " << binToHex(encrypted) << endl;

    cout << endl << " 2-B: desDecryption" << endl;
    string decrypted = desDecryption(encrypted, key);
    printGroups("Ciphertext : ", encrypted, 8);
    printGroups("Decrypted  : ", decrypted, 8);
    cout << "Decrypted (hex) : " << binToHex(decrypted) << endl;
    cout << (decrypted == plaintext ? "SUCCESS: decrypted text matches the original plaintext" : "ERROR: decrypted text does not match") << endl;

    cout << endl << "MULTIPLE BLOCKS" << endl;
    string twoBlocks = plaintext + "1111111100000000111111110000000011111111000000001111111100000000";
    string enc2 = desEncryption(twoBlocks, key);
    string dec2 = desDecryption(enc2, key);
    cout << "Encrypted (hex): " << binToHex(enc2) << endl;
    cout << (dec2 == twoBlocks ? "SUCCESS: both blocks decrypted correctly" : "ERROR: mismatch") << endl;

    return 0;
}