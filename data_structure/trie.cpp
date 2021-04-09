#include <iostream>
using namespace std;

struct Trie{
    bool finish;
    Trie* next[26]; // array of pointer

    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie(){
        for(int i=0; i<26; i++){
            if (next[i]){
                delete next[i];
            }
        }
    }

    void insert(const char* key) {
        if(*key == '\0'){
            finish = true;
        } else {
            int curr = *key - 'A';
            if (next[curr] == NULL){
                next[curr] = new Trie();
            }
            next[curr]->insert(key+1);
        }
    }

    Trie* find(const char *key){
        if(*key=='\0'){
            return this;
        }
        int curr = *key-'A';
        
        if(next[curr] == NULL) return NULL;
        return next[curr]->find(key+1);
    }
    void IsSorting(Trie *N, char str[], int idx)
    {
        if(N->finish==true) cout << str << endl;
        for(int i=0; i<26; i++)
        {
            if(N->next[i]!=NULL){
                char c = i+'A';
                str[idx] = c;
                N->IsSorting(N->next[i], str, idx+1);
            }
        }
    }
};

int main(void){
    Trie *Root = new Trie();
    char *String[2];
    String[0] = "HELLO";
    String[1] = "HI";

    for(int i=0; i<2; i++)
    {
        Root->insert(String[i]);
    }

    for(int i=0; i<26;i++)
    {
        if(Root->next[i] != NULL){
            char str[2] = {NULL,};
            str[0] = i+'A';
            Root->IsSorting(Root->next[i], str, 1);
        }
    }
}
