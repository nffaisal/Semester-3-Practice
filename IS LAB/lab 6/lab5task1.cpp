#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string> desPlaintextblock(string plaintext){ //lab 5 task 1  //first formatting the plaintext
        vector<string> blocks;
        for(int i=0; i<=plaintext.length(); i++){
            string block =plaintext.substr(i,64); //add all of the string
            while(block.length() <64){  //if string length is less than 64 then pad it until the end with 0
                block +='0';
            }
            blocks.push_back(block); //combine the string with the vector
        }
        return blocks;
}
string desInitialPermutation(vector<string> plaintext){  //Lab 5 task 2
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
            permutatedblock += plaintext[position]; //add position of that text to the new text
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
        {7,63,54,46,38,39,22},
        {14,6,61,53,45,37,29},
        {21,13,5,28,20,12,4}
    };
    string permutatedChoice =""; //final permutated choice string
    for(int i=0;i<8;i++){
        for(int j=0;j<7;j++){
            int position =PCP[i][j];
            permutatedChoice =text[position];
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
        char firstbit =0;       //store first bit
        for(int j=0;j<text.length() -1;j++){    //now shift everything 1 bit
            text[j]=text[j+1];
        }
        text[text.length()-1] =firstbit; //add the stored first bit to the end
    }   //if two shifts redo the storing and shifting again 
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
            permutatedChoice2 =text[position];
        }
    }
    return permutatedChoice2;
}
string expansionPermutation(String plaintext){ //

}

int main(){

}