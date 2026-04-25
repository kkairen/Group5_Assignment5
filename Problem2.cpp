#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // open dictionary
    ifstream dictionaryFile("dictionary.txt");
    vector<string> allwords;
    string checkWord; 

    // for each word in file add to vector
    // makes a vector version of dictionary file
    while (dictionaryFile >> checkWord){
        allwords.push_back(checkWord);
    }
    dictionaryFile.close(); // close your file

    
    ifstream checkFile("LoremIpsum.txt");
    if(!checkFile){
        cout << "Could Not Open to Spell Check" << endl;
        return 0;
    }

    if (allwords.empty()) {
        cout << "WARNING: Dictionary is empty! Check your file path." << endl;
}

    // check spelling
    while (checkFile >> checkWord){
        if(find(allwords.begin(), allwords.end(), checkWord) == allwords.end()){
            for (char &c : checkWord) {
                c = std::tolower(c);
            }

            // check to see if words match if not then print
            cout << checkWord << endl;
        }
    }

    return 0;
}