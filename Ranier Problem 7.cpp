/*
   Name: Ranier Aponte
   Assignment: Assignment 5 - P8.7 Random Monoalphabet Cipher
   Course: C++ Programming
   Description: This program encrypts or decrypts a text file using a keyword-based
                random monoalphabet substitution cipher. The keyword removes duplicate
                letters first. Then the rest of the alphabet is added in reverse order.
                Each code segment is authored by Ranier Aponte.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Author: Ranier Aponte
// Converts a character to uppercase.
char toUpperChar(char ch)
{
    return static_cast<char>(toupper(static_cast<unsigned char>(ch)));
}

// Author: Ranier Aponte
// Returns true when the character is an English alphabet letter.
bool isLetter(char ch)
{
    return isalpha(static_cast<unsigned char>(ch));
}

// Author: Ranier Aponte
// Removes duplicate letters from the keyword and keeps the first copy of each letter.
string removeDuplicateLetters(const string& keyword)
{
    string result = "";

    for (char ch : keyword)
    {
        if (isLetter(ch))
        {
            char upper = toUpperChar(ch);

            if (result.find(upper) == string::npos)
            {
                result += upper;
            }
        }
    }

    return result;
}

// Author: Ranier Aponte
// Builds the cipher alphabet from the keyword.
string buildCipherAlphabet(const string& keyword)
{
    string cipherAlphabet = removeDuplicateLetters(keyword);

    for (char ch = 'Z'; ch >= 'A'; ch--)
    {
        if (cipherAlphabet.find(ch) == string::npos)
        {
            cipherAlphabet += ch;
        }
    }

    return cipherAlphabet;
}

// Author: Ranier Aponte
// Encrypts one character using the cipher alphabet.
char encryptCharacter(char ch, const string& cipherAlphabet)
{
    if (!isLetter(ch))
    {
        return ch;
    }

    bool lowercase = islower(static_cast<unsigned char>(ch));
    char upper = toUpperChar(ch);
    int index = upper - 'A';
    char encrypted = cipherAlphabet[index];

    if (lowercase)
    {
        return static_cast<char>(tolower(static_cast<unsigned char>(encrypted)));
    }

    return encrypted;
}

// Author: Ranier Aponte
// Decrypts one character using the cipher alphabet.
char decryptCharacter(char ch, const string& cipherAlphabet)
{
    if (!isLetter(ch))
    {
        return ch;
    }

    bool lowercase = islower(static_cast<unsigned char>(ch));
    char upper = toUpperChar(ch);
    size_t index = cipherAlphabet.find(upper);
    char decrypted = static_cast<char>('A' + index);

    if (lowercase)
    {
        return static_cast<char>(tolower(static_cast<unsigned char>(decrypted)));
    }

    return decrypted;
}

// Author: Ranier Aponte
// Processes the input file and writes the encrypted or decrypted result to the output file.
bool processFile(const string& inputFileName, const string& outputFileName,
                 const string& cipherAlphabet, bool decryptMode)
{
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile)
    {
        cout << "Error: Could not open input file." << endl;
        return false;
    }

    if (!outputFile)
    {
        cout << "Error: Could not open output file." << endl;
        return false;
    }

    char ch;
    while (inputFile.get(ch))
    {
        if (decryptMode)
        {
            outputFile << decryptCharacter(ch, cipherAlphabet);
        }
        else
        {
            outputFile << encryptCharacter(ch, cipherAlphabet);
        }
    }

    return true;
}

// Author: Ranier Aponte
// Displays the correct way to run the program.
void displayUsage()
{
    cout << "Usage:" << endl;
    cout << "  crypt -e -kKEYWORD input.txt output.txt" << endl;
    cout << "  crypt -d -kKEYWORD input.txt output.txt" << endl;
    cout << endl;
    cout << "Example:" << endl;
    cout << "  crypt -d -kFEATHER encrypt.txt output.txt" << endl;
}

// Author: Ranier Aponte
// Main function that checks command-line arguments and starts the file process.
int main(int argc, char* argv[])
{
    if (argc != 5)
    {
        displayUsage();
        return 1;
    }

    string mode = argv[1];
    string keyArgument = argv[2];
    string inputFileName = argv[3];
    string outputFileName = argv[4];

    if (mode != "-e" && mode != "-d")
    {
        cout << "Error: Use -e to encrypt or -d to decrypt." << endl;
        displayUsage();
        return 1;
    }

    if (keyArgument.length() <= 2 || keyArgument.substr(0, 2) != "-k")
    {
        cout << "Error: A keyword must be supplied using -kKEYWORD." << endl;
        displayUsage();
        return 1;
    }

    string keyword = keyArgument.substr(2);
    string cleanedKeyword = removeDuplicateLetters(keyword);

    if (cleanedKeyword.empty())
    {
        cout << "Error: The keyword must contain at least one letter." << endl;
        return 1;
    }

    string cipherAlphabet = buildCipherAlphabet(keyword);
    bool decryptMode = (mode == "-d");

    if (processFile(inputFileName, outputFileName, cipherAlphabet, decryptMode))
    {
        cout << "File processed successfully." << endl;
        cout << "Cipher alphabet: " << cipherAlphabet << endl;
        return 0;
    }

    return 1;
}
