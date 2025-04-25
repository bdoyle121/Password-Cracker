#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "Hashtable.h"
#include "Logger.h"
#include "md5.h"
using namespace std;

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

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cerr << "Usage: " << argv[0] << "<dictionary_file> <target_hash>\n";
        return 1;
    }

    string dictionaryFile = argv[1];
    string targetHash = argv[2];

    vector<string> dictionary = loadDictionary(dictionaryFile);
    if (dictionary.empty()) {
        cerr << "No words are loading. Exiting.\n";
        return 1;
    }

    cout << "Loaded " << dictionary.size() << "words from" << dictionaryFile << ".\n";
    cout << "Target hash:" << targetHash << "\n";

    HashTable hashTable;
    Logger logger;

    bool cracked = false;

    for (const auto& word : dictionary) {
        string hash = md5Hash(word);

        logger.logAttempt(word);
        hashTable.insert(hash, word);

        if (hash == targetHash) {
            cout << "\n Password cracked:" << word << "\n";
            cracked = true;
            break;
        }
    }

    if (!cracked) {
        cout << "\n Password is not found in the dictionary.\n";
    }
    cout << "\n Last 10 attempts:\n";
    logger.printLog(10);

    return 0;
}