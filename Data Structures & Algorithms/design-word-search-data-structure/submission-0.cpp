struct Node{
    bool flag;
    Node* links[26];

    Node(){
        flag = false;

        for(int i = 0; i < 26; i++){
            links[i] = NULL;
        }
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void setEnd(){
        flag = true;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
};

class WordDictionary {
private:
    Node* root;

    bool dfs(string word, int index, Node* root){
          Node* node = root;

          for(int i=index; i<word.length(); i++){
            char ch = word[i];

            if(ch == '.'){
                for(auto child: node->links){
                    if(child != NULL && dfs(word, i+1, child)){
                        return true;
                    }
                }

                return false;
            }else{
                if(!node->containsKey(ch)){
                    return false;
                }
                node = node->get(ch);
            }

          }
          return node->flag;
    }


public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;

        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }
};
