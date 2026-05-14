class Solution {
public:
    vector<string> res;
    int m;
    int n;

    //Node struct for trie
    struct Node{
        bool flag;
        string word;
        Node* children[26];
    };
    
    Node* getNode(){
        Node* newNode= new Node();
        newNode->flag = false;
        newNode-> word = "";

        for(int i=0; i<26; i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    void insert(string word, Node* root){
        Node* node = root;

        for(int i=0; i<word.length(); i++){
            if(node->children[word[i] - 'a'] == NULL){
                Node* temp = getNode();
                node->children[word[i] - 'a'] = temp;
            }

            node = node->children[word[i] - 'a'];
        }

        node->flag = true;
        node->word = word;
    }

    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    void findWord(vector<vector<char>>& board, int i, int j, Node* root){
        if(i < 0 || i >= m || j < 0 || j >= n) return;

        if(board[i][j] == '#' || root->children[board[i][j] - 'a'] == NULL) return;

        root = root->children[board[i][j] - 'a'];

        if(root->flag){
            res.push_back(root->word);
            root->flag = false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        // left, right, up, down
        for(vector<int>& dir: directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            findWord(board, new_i, new_j, root);
        }
        board[i][j] = temp;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); // row;
        n = board[0].size(); //cols

        //create root
        Node* root = getNode();

        // Insert all the words in trie
        for(int i=0; i<words.size(); i++){
            insert(words[i], root);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char ch = board[i][j];
                
                if(root->children[ch - 'a'] != NULL){
                    findWord(board, i, j, root);
                }
            }
        }

        return res;
    }
};
