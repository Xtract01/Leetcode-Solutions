class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string,string> caseMap;
    unordered_map<string,string> vowelMap;
    string toLower(string &s){
        string result = s ;
        for(char &ch:result){
            ch = tolower(ch);
        }
        return result;
    }
    string replaceVowel(string &s){
        string result = s;
        for(char &ch : result){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                ch='*';
            }
        }
        return result;
    }
    string checkForMatch(string &query){
        if(exactSet.count(query)){
            return query;
        }
        string lowerCase = toLower(query);
        if(caseMap.count(lowerCase)) return caseMap[lowerCase];
        string vowelCase = replaceVowel(lowerCase);
        if(vowelMap.count(vowelCase)) return vowelMap[vowelCase];
        return "";

    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMap.clear();
        vowelMap.clear();
        for(string word : wordlist){
            exactSet.insert(word);
            string lowerCase = toLower(word);
            if(caseMap.find(lowerCase)==caseMap.end()){
                caseMap[lowerCase] = word;
            }
            string vowelCase = replaceVowel(lowerCase);
            if(vowelMap.find(vowelCase)==vowelMap.end()){
                vowelMap[vowelCase] = word;
            }
        }
        vector<string> res;
        for(string &query : queries){
            res.push_back(checkForMatch(query));
        }
        return res;
    }
};