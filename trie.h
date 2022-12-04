// Copyright [2022] <Lucas Castro Truppel Machado
#include <string>
using namespace std;

struct TrieNode {
    char letter;
    struct TrieNode* children[26];
    unsigned long pos;
    unsigned long length;
};

class Trie {
 public:
    Trie();

    ~Trie();

    void insert(string word, unsigned long pos_, unsigned long length_);

    struct TrieNode* find(string word);

    int count_words(struct TrieNode* node);
    
    struct TrieNode* createNode(char letter);

    struct TrieNode* root;
};

// Construtor da árvore
Trie::Trie() {
    root = createNode('0');
}

// Destrutor da árvore
Trie::~Trie() {
}

// Cria nodo
struct TrieNode* Trie::createNode(char letter_) {
    struct TrieNode* new_node = new TrieNode;
    new_node->letter = letter_;
    new_node->pos = 0;
    new_node->length = 0;

    for (int i = 0; i < 26; i++) {
        new_node->children[i] = nullptr;
    }

    return new_node;
}

// Insere uma palavra na árvore
void Trie::insert(string word, unsigned long pos_, unsigned long length_) {
    struct TrieNode* current_node = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == nullptr) {
            current_node->children[index] = createNode(word[i]);
        }
        current_node = current_node->children[index];
    }
    current_node->pos = pos_;
    current_node->length =  length_;
}

// Procura uma palava na árvore
struct TrieNode* Trie::find(string word) {
    struct TrieNode* current_node = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';
        if (current_node->children[index] == nullptr) {
            return (nullptr);
        }
        current_node = current_node->children[index];
    }
    return current_node;
}

// Conta quantas palavras são formadas por um prefixo
int Trie::count_words(struct TrieNode* node) {
    int sum = 0;
    if (node->length != 0)
        sum++;

    for (int index = 0; index < 26; index++) {
        if (node->children[index] != nullptr) {
            sum += count_words(node->children[index]);
        }
    }
    return sum;
}
