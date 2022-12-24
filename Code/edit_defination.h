#pragma once
#include "Trie2.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "textbox.h"
#include "switch_dataset.h"
bool add_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string new_meaning);
bool delete_mean(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning);
bool edit_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning, string new_meaning);
void addingWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
bool checkTonTai(TrieNode* root, string s, string meaning);
void deleteWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
void editWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);
void khungSettingEdit(TrieNode*& rootEnglish, TrieNode*& rootVietnam, sf::Font font, TrieNode*& englishVietNam, TrieNode*& englishVietNamDef, TrieNode*& slang, TrieNode*& slangDef, TrieNode*& emotion, TrieNode*& emotionDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion);