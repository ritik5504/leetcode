class Solution {
public:
    bool write(string word, vector<bool>& trackLetters){
        for(int i =0; i < word.size(); i++){
            if(trackLetters[word[i]-'a'] == false) return false;
        }

        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> wordString;
        string word = "";

        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                wordString.push_back(word);
                word = "";
            } else {
                word += text[i];
            }
        }

        wordString.push_back(word);

        vector<bool> trackLetters(26, true);

        for(int i = 0; i < brokenLetters.size(); i++){
            trackLetters[brokenLetters[i]-'a'] = false;
        }

        int result = 0;

        for(int i = 0; i < wordString.size(); i++){
            if(write(wordString[i], trackLetters)){
                result++;
            }
        }

        return result;
    }
};