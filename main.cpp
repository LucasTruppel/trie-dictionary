#include <iostream>
#include <fstream>
#include "trie.h"
using namespace std;

int main() {
    // Abre o arquivo do dicionario
    string filename;
    cin >> filename;
    ifstream file;
    file.open(filename);

    // Declaração das variáveis utilizadas
    string line, dic_word, word;
    char charc;
    int pos = 0;

    // Criação da trie
    Trie trie;

    // Adiciona as palavras do arquivo à trie
    while (getline(file, line)) { // Leitura de cada linha do arquivo
        dic_word = "";
        for (int i = 1; i < line.length(); i++) { // Leitura de cada caracter da linha para formar a palavra
            charc = line[i];
            if (charc == ']')
                break;
            dic_word += charc;
        }
        trie.insert(dic_word, pos, line.length());
        pos += line.length() + 1;
    }
    
    while (true) {  // leitura das palavras ate' encontrar "0"
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }

        // Procura o prefixo/palavra de entrada na trie
        struct TrieNode* node = trie.find(word);

        // Caso a funcao find tenha retornado um ponteiro nulo, o prefixo não está na trie
        if (node == nullptr) {
            cout << word << " is not prefix"<< endl;
        } else {  // prefixo está na trie
            int count = trie.countWords(node);
            cout << word << " is prefix of " << count << " words" << endl;
            if (node->length != 0) {  // prefixo é de fato uma palavra no dicionário, ou seja, não é apenas um prefixo
                cout << word << " is at (" << node->pos << "," << node->length << ")" << endl;
            }
        }
    }

    return 0;
}
