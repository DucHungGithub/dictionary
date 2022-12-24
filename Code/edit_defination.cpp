using namespace std;
#include "edit_defination.h"
#include "addNewWord.h"
#include "Trie2.h"
#include "removeword.h"



bool add_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string new_meaning) {
    if (!check_exist(root_key, s)) return false;
	/*bool check1 = checkTonTai(root_key, s, new_meaning);*/
	/*if (check1)
		return false;*/
    insert(root_key, s, new_meaning);
    insert(root_def, new_meaning, s);
    return true;
}
bool delete_mean(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning) {
    if (!check_exist(root_key, s)) return false;
    if (check_delete_meaning(root_key, s) && check_delete_meaning(root_def, old_meaning)) {
        return delete_meaning(root_key, s, old_meaning) && delete_meaning(root_def, old_meaning, s);
    }
    else return false;
}
bool edit_meaning(TrieNode*& root_key, TrieNode*& root_def, string s, string old_meaning, string new_meaning) {
	if (!check_exist(root_key, s)) return false;
	if (!delete_meaning(root_key, s, old_meaning)) return false;
	insert(root_key, s, new_meaning);
	delete_meaning(root_def, old_meaning, s);
	int n = old_meaning.size();
	TrieNode* cur = root_def;
	for (int i = 0; i < n; ++i) {
		int nxt = int(old_meaning[i] - 32);
		cur = cur->c[nxt];
	}
	if (cur->meaning.size() == 0) root_def = remove(root_def, old_meaning, 0);
	insert(root_def, new_meaning, s);
	return true;
}

void addingWordScreen(sf::Font font,TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungadding.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "ADDING", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 300,300 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(15, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 110.f,80.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 39);

	Textbox noidungnhapDef(15, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 110.f,180.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 39);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 150.f,200.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
			}
			if (eventadd.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowAdd).x;
					float mouseY = sf::Mouse::getPosition(windowAdd).y;
					if (mouseX > 110 && mouseX < 427 && mouseY>74 && mouseY < 101)
					{
						thongbao.newstring("");
						noidungnhapKey.clearString();
						noidungnhapKey.setSelected(true);
					}
					else
						noidungnhapKey.setSelected(false);
					if (mouseX > 110 && mouseX < 427 && mouseY>173 && mouseY < 199)
					{
						thongbao.newstring("");
						noidungnhapDef.clearString();
						noidungnhapDef.setSelected(true);
					}
					else
					{
						noidungnhapDef.setSelected(false);
					}
					if (mouseX > 447 && mouseX < 504 && mouseY>217 && mouseY < 243)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						if (key != "" && def != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							bool check = add_meaning(rootKey, rootDef, key, def);
							if (check)
							{
								switch (chooseDic)
								{
								case 1:
								case 4:
									dicEngViet = true;
									break;
								case 2:
									dicSlang = true;
									break;
								case 3:
									dicEmotion = true;
									break;
								default:
									break;
								}
								thongbao.newstring("SUCCESS");
							}
								
							else
							{
								thongbao.newstring("FAILURE");
							}

						}
					}
					if (mouseX > 359 && mouseX < 414 && mouseY>219 && mouseY < 243)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						if (key != "" && def != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							add_new_word(rootKey, rootDef, key, def);
							switch (chooseDic)
							{
							case 1:
							case 4:
								dicEngViet = true;
								break;
							case 2:
								dicSlang = true;
								break;
							case 3:
								dicEmotion = true;
								break;
							default:
								break;
							}
							thongbao.newstring("SUCCESS");

						}
					}
				}
			}
		}
		
		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}

void deleteWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungdelete.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "DELETE", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 700,300 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(15, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 110.f,80.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 39);

	Textbox noidungnhapDef(15, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 110.f,180.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 39);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 150.f,200.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float mouseX = sf::Mouse::getPosition(windowAdd).x;
				float mouseY = sf::Mouse::getPosition(windowAdd).y;
				if (mouseX > 110 && mouseX < 427 && mouseY>74 && mouseY < 101)
				{
					thongbao.newstring("");
					noidungnhapKey.clearString();
					noidungnhapKey.setSelected(true);
				}
				else
					noidungnhapKey.setSelected(false);
				if (mouseX > 110 && mouseX < 427 && mouseY>173 && mouseY < 199)
				{
					thongbao.newstring("");
					noidungnhapDef.clearString();
					noidungnhapDef.setSelected(true);
				}
				else
				{
					noidungnhapDef.setSelected(false);
				}
				if (mouseX > 447 && mouseX < 504 && mouseY>217 && mouseY < 243)
				{
					string key = noidungnhapKey.getText();
					string def = noidungnhapDef.getText();
					if (key != "" && def != "")
					{
						noidungnhapKey.newstring("");
						noidungnhapDef.newstring("");
						bool check = delete_mean(rootKey, rootDef, key, def);
						if (check)
						{
							switch (chooseDic)
							{
							case 1:
							case 4:
								dicEngViet = true;
								break;
							case 2:
								dicSlang = true;
								break;
							case 3:
								dicEmotion = true;
								break;
							default:
								break;
							}
							thongbao.newstring("SUCCESS");
						}
						else
						{
							thongbao.newstring("FAILURE");
						}

					}
				}
				if (mouseX > 359 && mouseX < 414 && mouseY>219 && mouseY < 243)
				{
					string key = noidungnhapKey.getText();
					/*string def = noidungnhapDef.getText();*/
					if (key != "")
					{
						noidungnhapKey.newstring("");
						noidungnhapDef.newstring("");
						bool temp = remove_word(rootKey, rootDef, key);
						if (!temp)
							thongbao.newstring("FAILURE");
						else
						{
							switch (chooseDic)
							{
							case 1:
							case 4:
								dicEngViet = true;
								break;
							case 2:
								dicSlang = true;
								break;
							case 3:
								dicEmotion = true;
								break;
							default:
								break;
							}
							thongbao.newstring("SUCCESS");
						}
							

					}
				}
			}
		}

		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}

void editWordScreen(sf::Font font, TrieNode*& rootKey, TrieNode*& rootDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion)
{
	sf::Texture Bgadd;
	Bgadd.loadFromFile("khungedit.png");
	sf::RenderWindow windowAdd(sf::VideoMode(Bgadd.getSize().x, Bgadd.getSize().y), "EDIT", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 430,240 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(Bgadd);

	Textbox noidungnhapKey(20, sf::Color::Black, false);
	noidungnhapKey.setPosition({ 163.f,89.f });
	noidungnhapKey.newstring("");
	noidungnhapKey.setFont(font);
	noidungnhapKey.setLimit1(false, 60);

	Textbox noidungnhapDef(20, sf::Color::Black, false);
	noidungnhapDef.setPosition({ 163.f,222.f });
	noidungnhapDef.newstring("");
	noidungnhapDef.setFont(font);
	noidungnhapDef.setLimit1(false, 60);

	Textbox noidungnhapNew(20, sf::Color::Black, false);
	noidungnhapNew.setPosition({ 163.f,347.f });
	noidungnhapNew.newstring("");
	noidungnhapNew.setFont(font);
	noidungnhapNew.setLimit1(false, 60);

	Textbox thongbao(20, sf::Color::Cyan, false);
	thongbao.setPosition({ 244.f,380.f });
	thongbao.newstring("");
	thongbao.setFont(font);

	while (windowAdd.isOpen())
	{
		sf::Event eventadd;
		while (windowAdd.pollEvent(eventadd))
		{
			if (eventadd.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (eventadd.type == sf::Event::TextEntered)
			{
				noidungnhapKey.typeOn(eventadd);
				noidungnhapDef.typeOn(eventadd);
				noidungnhapNew.typeOn(eventadd);
			}
			if (eventadd.type == sf::Event::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					float mouseX = sf::Mouse::getPosition(windowAdd).x;
					float mouseY = sf::Mouse::getPosition(windowAdd).y;
					if (mouseX > 158 && mouseX < 593 && mouseY>81 && mouseY < 112)
					{
						thongbao.newstring("");
						noidungnhapKey.clearString();
						noidungnhapKey.setSelected(true);

					}
					else
						noidungnhapKey.setSelected(false);
					if (mouseX > 157 && mouseX < 594 && mouseY>217 && mouseY < 247)
					{
						thongbao.newstring("");
						noidungnhapDef.clearString();
						noidungnhapDef.setSelected(true);
					}
					else
					{
						noidungnhapDef.setSelected(false);
					}

					if (mouseX > 158 && mouseX < 590 && mouseY>341 && mouseY < 370)
					{
						thongbao.newstring("");
						noidungnhapNew.clearString();
						noidungnhapNew.setSelected(true);
					}
					else
					{
						noidungnhapNew.setSelected(false);
					}

					if (mouseX > 626 && mouseX < 702 && mouseY>350 && mouseY < 378)
					{
						string key = noidungnhapKey.getText();
						string def = noidungnhapDef.getText();
						string neww = noidungnhapNew.getText();
						if (key != "" && def != "" && neww != "")
						{
							noidungnhapKey.newstring("");
							noidungnhapDef.newstring("");
							bool check = edit_meaning(rootKey, rootDef, key, def,neww);
							if (check)
							{
								switch (chooseDic)
								{
								case 1:
								case 4:
									dicEngViet = true;
									break;
								case 2:
									dicSlang = true;
									break;
								case 3:
									dicEmotion = true;
									break;
								default:
									break;
								}
								thongbao.newstring("SUCCESS");
							}
							else
							{
								thongbao.newstring("FAILURE");
							}

						}
					}
				}
			}
		}

		windowAdd.clear();

		windowAdd.draw(spriteBgAdd);
		noidungnhapDef.drawTo(windowAdd);
		noidungnhapKey.drawTo(windowAdd);
		noidungnhapNew.drawTo(windowAdd);
		thongbao.drawTo(windowAdd);
		windowAdd.display();
	}
}
//
//TrieNode* englishVietnam = nullptr;
//TrieNode* englishVietnamDef = nullptr;
//TrieNode* slang = nullptr;
//TrieNode* slangDef = nullptr;
//TrieNode* emotiondef = nullptr;
//TrieNode* emotion = nullptr;

void khungSettingEdit(TrieNode*& rootEnglish, TrieNode*& rootVietnam, sf::Font font,TrieNode*& englishVietNam,TrieNode*& englishVietNamDef,TrieNode*& slang, TrieNode*& slangDef,TrieNode*& emotion,TrieNode*& emotionDef, int& chooseDic, bool& dicEngViet, bool& dicSlang, bool& dicEmotion)
{
	sf::Texture bgSet;
	bgSet.loadFromFile("khungsetting.png");
	sf::RenderWindow windowAdd(sf::VideoMode(bgSet.getSize().x, bgSet.getSize().y), "SETTING", sf::Style::Default);
	windowAdd.setFramerateLimit(60);
	windowAdd.setPosition({ 40,10 });
	sf::Sprite spriteBgAdd;
	spriteBgAdd.setTexture(bgSet);
	
	Textbox nuthome(60, sf::Color::White, false);
	nuthome.setPosition({ 300.f,220.f });
	nuthome.newstring("ENGLISH");
	nuthome.setFont(font);
	nuthome.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutNewword(60, sf::Color::White, false);
	nutNewword.setPosition({ 300.f,400.f });
	nutNewword.newstring("VIETNAM");
	nutNewword.setFont(font);
	nutNewword.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutLang(60, sf::Color::White, false);
	nutLang.setPosition({ 700.f,220.f });
	nutLang.newstring("EMOTION");
	nutLang.setFont(font);
	nutLang.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutExit(60, sf::Color::White, false);
	nutExit.setPosition({ 700.f,400.f });
	nutExit.newstring("SLANG");
	nutExit.setFont(font);
	nutExit.setscaleAndOut(2.f, 0, 187, 191);

	Textbox nutExit2(60, sf::Color::Blue, false);
	nutExit2.setPosition({ 120.f,100.f });
	nutExit2.newstring("RESET");
	nutExit2.setFont(font);
	nutExit2.setscaleAndOut(2.f, 0, 187, 191);
	while (windowAdd.isOpen())
	{
		sf::Event event;
		while (windowAdd.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				windowAdd.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				float mouseX = sf::Mouse::getPosition(windowAdd).x;
				float mouseY = sf::Mouse::getPosition(windowAdd).y;
				if (mouseX > 1128 && mouseY > 80 && mouseX < 1162 && mouseY < 128)
					windowAdd.close();

			}
			if (nuthome.isMouseOver(windowAdd))
			{
				nuthome.setcolor(sf::Color::Red);
				nuthome.setscaleAndOut(3.f, 245, 168, 154);
			}
			else
			{
				nuthome.setcolor(sf::Color::White);
				nuthome.setscaleAndOut(2.f, 0, 187, 191);
			}
			if (nuthome.isKickMouse(windowAdd))
			{
				rootEnglish = englishVietNam;
				rootVietnam = englishVietNamDef;
				chooseDic = 1;
				windowAdd.close();
			}
			if (nutNewword.isMouseOver(windowAdd))
			{
				nutNewword.setcolor(sf::Color::Red);
				nutNewword.setscaleAndOut(3.f, 245, 168, 154);
			}
			else
			{
				nutNewword.setcolor(sf::Color::White);
				nutNewword.setscaleAndOut(2.f, 0, 187, 191);
			}
			if (nutNewword.isKickMouse(windowAdd))
			{
				rootEnglish = englishVietNamDef;
				rootVietnam = englishVietNam;
				chooseDic = 4;
				windowAdd.close();
			}
			if (nutLang.isMouseOver(windowAdd))
			{
				nutLang.setcolor(sf::Color::Red);
				nutLang.setscaleAndOut(3.f, 245, 168, 154);
			}
			else
			{
				nutLang.setcolor(sf::Color::White);
				nutLang.setscaleAndOut(2.f, 0, 187, 191);
			}
			if (nutLang.isKickMouse(windowAdd))
			{
				rootEnglish = emotion;
				rootVietnam = emotionDef;
				chooseDic = 3;
				windowAdd.close();
			}
			if (nutExit.isMouseOver(windowAdd))
			{
				nutExit.setcolor(sf::Color::Red);
				nutExit.setscaleAndOut(3.f, 245, 168, 154);
			}
			else
			{
				nutExit.setcolor(sf::Color::White);
				nutExit.setscaleAndOut(2.f, 0, 187, 191);
			}
			if (nutExit.isKickMouse(windowAdd))
			{
				rootEnglish = slang;
				rootVietnam = slangDef;
				chooseDic = 3;
				windowAdd.close();
			}
			//Reset original tree (not finished)
			if (nutExit2.isMouseOver(windowAdd))
			{
				nutExit2.setcolor(sf::Color::Red);
				nutExit2.setscaleAndOut(3.f, 245, 168, 154);
			}
			else
			{
				nutExit2.setcolor(sf::Color::Blue);
				nutExit2.setscaleAndOut(2.f, 0, 187, 191);
			}
			if (nutExit2.isKickMouse(windowAdd))
			{
				switch (chooseDic)
				{
				case 1:
					if (!dicEngViet)
					{
						windowAdd.close();
					}
					else
					{
						deallocate(englishVietNam);
						deallocate(englishVietNamDef);
						build_data(englishVietNam, englishVietNamDef, "sample3Ori.txt", '`');
						rootEnglish = englishVietNam;
						rootVietnam = englishVietNamDef;
						dicEngViet = false;
						windowAdd.close();
					}
					break;
				case 2:
					if (!dicSlang)
						windowAdd.close();
					else
					{
						deallocate(slang);
						deallocate(slangDef);
						build_data(slang, slangDef, "sample1Ori.txt", '`');
						rootEnglish = slang;
						rootVietnam = slangDef;
						dicSlang = false;
						windowAdd.close();
					}
					break;
				case 3:
					if (!dicEmotion)
						windowAdd.close();
					else
					{
						deallocate(emotion);
						deallocate(emotionDef);
						build_data(emotion, emotionDef, "emotionalOri.txt", '`');
						rootEnglish = slang;
						rootVietnam = slangDef;
						dicSlang = false;
						windowAdd.close();
					}
					break;
				case 4:
					if (!dicEngViet)
					{
						windowAdd.close();
					}
					else
					{
						deallocate(englishVietNam);
						deallocate(englishVietNamDef);
						build_data(englishVietNam, englishVietNamDef, "sample3Ori.txt", '`');
						rootEnglish = englishVietNamDef;
						rootVietnam = englishVietNam;
						dicEngViet = false;
						windowAdd.close();
					}
					break;
				default:
					break;
				}
			}
			

		}

		
		
		
		windowAdd.clear();
		windowAdd.draw(spriteBgAdd);
		nuthome.drawTo(windowAdd);
		nutLang.drawTo(windowAdd);
		nutNewword.drawTo(windowAdd);
		nutExit.drawTo(windowAdd);
		nutExit2.drawTo(windowAdd);
		windowAdd.display();

	}



}