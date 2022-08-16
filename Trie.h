//#pragma once
//#pragma once
//#include <string>
//#include <vector>
//#include <queue>
//#include <fstream>
//using namespace std;
//const int ALP = 96;
//
//struct TrieNode {
//    int cnt;
//    TrieNode* c[ALP];
//    bool isEndOfWord;
//    string meaning;
//
//    TrieNode() {
//        cnt = 0;
//        for (int i = 0; i < ALP; ++i)
//            c[i] = nullptr;
//        isEndOfWord = false;
//    }
//};
//
//void insert(TrieNode*& root, string s, string meaning);
//bool lookUpMeaning1(TrieNode* root, string s, string& meaning);
//bool EditDefination(TrieNode*& root, string s, string change);
//vector <pair<string, string>> lookUpMeaning(TrieNode* root, string s);
//void Deallocate(TrieNode*& root);
//bool isEmpty(TrieNode* root);
//TrieNode* remove(TrieNode*& root, string key, int len = 0);
//void deleteHistory(std::string address);
//void savetoHistory(std::string s, std::string address, std::string meaning);
//vector <pair<string, string>> viewHistory(std::string address);
//vector <pair<string, string>> loadLikeWord(std::string address);
//void releaseLikeWord(std::string address, vector<pair<string, string>> save);
