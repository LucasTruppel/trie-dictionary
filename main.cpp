#include <iostream>
#include <fstream>
#include "trie.h"

int main() {
    
    using namespace std;

    string filename;
    string word;
    Trie trie;

    cin >> filename;  // entrada

    ifstream file;
    file.open(filename);
    string line, dic_word;
    int pos = 0;

    while (getline(file, line)) { // Leitura de cada linha do arquivo
        bool writing_word = true;
        char charc;
        dic_word = "";
        for (int i = 1; i < line.length(); i++) { // Leitura de cada caracter da linha
            charc = line[i];
            if (charc == ']')
                break;
            dic_word += charc;
        }
        trie.insert(dic_word, pos, line.length());
        pos += line.length() + 1;
    }
    
    while (1) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }

        struct TrieNode* node = trie.find(word);
        if (node == nullptr) {
            cout << word << " is not prefix"<< endl;
        } else {
            int count = trie.countWords(node);
            cout << word << " is prefix of " << count << " words" << endl;
            if (node->length != 0) {
                cout << word << " is at (" << node->pos << "," << node->length << ")" << endl;
            }
        }
    }

    return 0;
}
