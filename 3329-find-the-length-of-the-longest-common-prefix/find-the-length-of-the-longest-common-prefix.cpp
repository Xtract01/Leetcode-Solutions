class Solution {
public:
    struct trieNode{
        trieNode* children[10];
    };
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        for(int i=0 ; i<10 ;i++) newNode->children[i] = NULL;
        return newNode;
    }
    void insert(trieNode* root,string s){
        trieNode* pCrawl = root;
        for(int i=0 ; i<s.length() ; i++){
            int idx = s[i] - '0';
            if(pCrawl->children[idx]==NULL) pCrawl->children[idx] = new trieNode();
            pCrawl = pCrawl->children[idx];
        }
    }
    int lengthOfPrefix(trieNode* root , string s){
        trieNode* pCrawl = root;
        int cnt =0;
        for(int i=0 ; i<s.length() ; i++){
            int idx = s[i] - '0';
            if(pCrawl->children[idx]){
                pCrawl = pCrawl->children[idx];
                cnt++;
            }
            else break;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        trieNode* root = getNode();
        int n = arr1.size();
        int m = arr2.size();
        for(int i=0;i<n ; i++){
            string s = to_string(arr1[i]);
            insert(root,s);
        }
        int res  = 0;
        for(int i=0 ; i<m ; i++){
            string s = to_string(arr2[i]);
            res = max(res,lengthOfPrefix(root,s));
        }
        return res;
    }
};