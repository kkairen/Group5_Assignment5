#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    // open dictionary
    ifstream dictionaryFile("dictionary.txt");
    vector<string> allwords;
    string checkWord; 

    // for each word in file add to vector
    // makes a vector version of dictionary file
    while (dictionaryFile >> checkWord){
        for (char &c : checkWord){
            c = tolower(c); // converts everything to lowercase = gets rid of case sensitivity issues
        }
        allwords.push_back(checkWord);
    }
    dictionaryFile.close(); // close your file

    
    ifstream checkFile("LoremIpsum.txt");
    if(!checkFile){
        cout << "Could Not Open to Spell Check" << endl;
        return 0;
    }

    if (allwords.empty()) {
        cout << "Dictionary is empty! Check your file path." << endl;
        return 0;
}

    // check spelling
    while (checkFile >> checkWord){
        if(find(allwords.begin(), allwords.end(), checkWord) == allwords.end()){

            // make word we are checking lowercase to match dictionary
            for (char &c : checkWord){
                c = tolower(c);
            }

            cout << "Incorrect:";
            // check to see if words match if not then print
            cout << checkWord << endl;
        }
    }

    cout << "\nPress Enter to exit...";
    cin.ignore(); // Clears any leftover characters in the buffer
    cin.get();    // Waits for the user to press Enter

    return 0;
}