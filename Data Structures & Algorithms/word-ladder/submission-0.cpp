class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> set;
        for(auto word: wordList){
            set.insert(word);
        }

        int n = beginWord.size();
        q.push({beginWord, 1});

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto[word, count] = q.front();
                q.pop();
                if(word == endWord) return count;

                for(int j=0; j<n; j++){
                    char originalChar = word[j];

                    for(char ch='a'; ch<='z'; ch++){
                        if(ch == originalChar) continue;

                        word[j] = ch;
                        if(set.find(word) != set.end()){
                            q.push({word, count+1});
                            set.erase(word);
                        }
                    }
                    word[j] = originalChar;
                }
            }
        }

        return 0;

    }
};
