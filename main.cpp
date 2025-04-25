#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Hashtable.h"
#include "Logger.h"
#include "md5.h"
using namespace std;
/*
* This vector takes words from the dictionary file and puts them into a vector of strings.
* it then returns a vector containing each word from the dictionary. 
*/
vector<string> loadDictionary(const string& filename) {
    ifstream file(filename);
    vector<string> words;
    string word;

    if(!file.is_open()) {
        cout << "Could not open dictionary file.\n";
        return words;
    }

    while (getline(file, word)) {
        if (!word.empty()) {
             words.push_back(word);
        }
       
    }
    return words;
}
/*
* This main function runs the password cracker using a dictionary attack. 
* it loads the dictionary and hashes each word using the md5 file, compares it to the target hash, 
* it then logs all attempts and stops when it finds the correct password. 
*/
int main(int argc, char* argv[]) {
    if(argc != 3) {
        cerr << "Usage: " << argv[0] << "<dictionary_file> <target_hash>\n";
        return 1;
    }
    // First and second user input, first is the file path and the second is the target md5 hash
    string dictionaryFile = argv[1];
    string targetHash = argv[2];

    // Loads dictionary words into vector 
    vector<string> dictionary = loadDictionary(dictionaryFile);
    if (dictionary.empty()) {
        cerr << "No words are loading. Exiting.\n";
        return 1;
    }
    
    cout << "Loaded " << dictionary.size() << "words from" << dictionaryFile << ".\n";
    cout << "Target hash:" << targetHash << "\n";

    // Initializes the hash table and logger
    HashTable hashTable;
    Logger logger;
    // stops the program if the password is found 
    bool cracked = false;
    // Loops through all the words in the dictionary 
    for (const auto& word : dictionary) {
        string hash = md5Hash(word);

        logger.logAttempt(word);
        hashTable.insert(hash, word);
        // compares generated hash with the target hash
        if (hash == targetHash) {
            cout << "\n Password cracked:" << word << "\n";
            cracked = true;
            break;
        }
    }

    // if a match is not found in the dictionary file
    if (!cracked) {
        cout << "\n Password is not found in the dictionary.\n";
    }
    // Displays the last 10 password attempts
    cout << "\n Last 10 attempts:\n";
    logger.printLog(10);

    return 0;
}