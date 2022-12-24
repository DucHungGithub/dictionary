﻿//#include <SFML/Graphics.hpp>
//#include "mainmenu.h"
//#include "textbox.h"
//#include "button.h"
//#include "Trie.h"
//#include "splitTu.h"
//#include "addNewWord.h"
//#include <fstream>
//
//
//
//
//int main()
//{
//	sf::Font font;
//	font.loadFromFile("font.ttf");
//	sf::Texture bgText;
//	bgText.loadFromFile("dohoa1.png");
//	
//	sf::Sprite spriteBG;
//	spriteBG.setTexture(bgText);
//
//	TrieNode* rootEngLish = nullptr;
//	rootEngLish = new TrieNode();
//
//	TrieNode* rootVietNam = nullptr;
//	rootVietNam = new TrieNode();
//
//	add_new_word(rootEngLish, rootVietNam, "Nghiem", "Hello/ con ga no minh 11k va di chan rau CT1821 PTNK");
//	add_new_word(rootEngLish, rootVietNam, "Nghiem", "Hello");
//	add_new_word(rootEngLish, rootVietNam, "Nghiem", "con ga no minh 11k va di chan rau CT1821 PTNK");
//	add_new_word(rootEngLish, rootVietNam, "Ngu ngu", "HoHO");
//	add_new_word(rootEngLish, rootVietNam, "Nguoioi", "Hihihihi");
//	add_new_word(rootEngLish, rootVietNam, "Ngusdf", "Hahamm");
//
//
//	Textbox nuthome(60, sf::Color::White, false);
//	nuthome.setPosition({ 300.f,200.f });
//	nuthome.newstring("HOME");
//	nuthome.setFont(font);
//	nuthome.setscaleAndOut(2.f, 0, 187, 191);
//
//	Textbox nutNewword(60, sf::Color::White, false);
//	nutNewword.setPosition({ 400.f,300.f });
//	nutNewword.newstring("NEW WORD");
//	nutNewword.setFont(font);
//	nutNewword.setscaleAndOut(2.f, 0, 187, 191);
//
//	Textbox nutLang(60, sf::Color::White, false);
//	nutLang.setPosition({ 570.f,400.f });
//	nutLang.newstring("LANGUAGES");
//	nutLang.setFont(font);
//	nutLang.setscaleAndOut(2.f, 0, 187, 191);
//
//	Textbox nutExit(60, sf::Color::White, false);
//	nutExit.setPosition({ 870.f,500.f });
//	nutExit.newstring("EXIT");
//	nutExit.setFont(font);
//	nutExit.setscaleAndOut(2.f, 0, 187, 191);
//bg:
//	sf::RenderWindow window(sf::VideoMode(bgText.getSize().x, bgText.getSize().y), "Main menu", sf::Style::Default);
//	window.setFramerateLimit(60);
//	window.setPosition({ 40,10 });
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//
//		}
//
//		if (nuthome.isMouseOver(window))
//		{
//			nuthome.setcolor(sf::Color::Red);
//			nuthome.setscaleAndOut(3.f, 245, 168, 154);
//		}
//		else
//		{
//			nuthome.setcolor(sf::Color::White);
//			nuthome.setscaleAndOut(2.f, 0, 187, 191);
//		}
//
//		if (nutNewword.isMouseOver(window))
//		{
//			nutNewword.setcolor(sf::Color::Red);
//			nutNewword.setscaleAndOut(3.f, 245, 168, 154);
//		}
//		else
//		{
//			nutNewword.setcolor(sf::Color::White);
//			nutNewword.setscaleAndOut(2.f, 0, 187, 191);
//		}
//
//		if (nutLang.isMouseOver(window))
//		{
//			nutLang.setcolor(sf::Color::Red);
//			nutLang.setscaleAndOut(3.f, 245, 168, 154);
//		}
//		else
//		{
//			nutLang.setcolor(sf::Color::White);
//			nutLang.setscaleAndOut(2.f, 0, 187, 191);
//		}
//		if (nutLang.isKickMouse(window))
//		{	
//			window.close();
//
//			sf::Texture BgLang;
//			sf::Texture BgLang1;
//			BgLang.loadFromFile("khung2.png");
//			BgLang1.loadFromFile("khung21.png");
//		bgHis:
//			sf::RenderWindow windowLang(sf::VideoMode(BgLang.getSize().x, BgLang.getSize().y), "LANGUGES", sf::Style::None);
//			windowLang.setFramerateLimit(60);
//			windowLang.setPosition({ 40,10 });
//			sf::Sprite spriteBgLang;
//			spriteBgLang.setTexture(BgLang);
//			sf::RectangleShape khungnhap;
//			int change = 1;
//			Textbox noidungnhap(20, sf::Color::Black, false);
//			noidungnhap.setPosition({ 390.f,115.f });
//			noidungnhap.newstring("");
//			noidungnhap.setFont(font);
//			noidungnhap.setLimit1(false, 60);
//			
//			//Choose Language
//			Textbox language(50, sf::Color::White, false);
//			language.newstring("ENG");
//			language.setFont(font);
//			language.setPosition({ 170.f,90.f });
//			language.setscaleAndOut(2.f, 255, 102, 0);
//			int langcheck = 1;
//			TrieNode* root = rootEngLish;
//			
//			
//			Textbox definationoRKey(30, sf::Color(247, 234, 118), false);
//			definationoRKey.newstring("DEFINITION:");
//			definationoRKey.setFont(font);
//			definationoRKey.setPosition({ 400.f,200.f });
//			/*definationoRKey.setscaleAndOut(2.f, 232, 214, 49);*/
//
//			//Khung chua tu yeu thich
//			vector<pair<string, string>> likeWord = loadLikeWord("LIKEWORD.txt");
//			
//
//
//
//			//express content when inputing
//			/*Textbox expressOutWord(20, sf::Color::White, false);
//			expressOutWord.newstring("Meaning");
//			expressOutWord.setFont(font);
//			expressOutWord.setPosition({ 405.f,250.f });*/
//			vector<Textbox> expressKhung;
//			expressKhung.resize(5);
//			for (int i = 0; i < 5; i++)
//			{
//				expressKhung[i].setcolor(sf::Color::White);
//				expressKhung[i].setSize(20);
//				expressKhung[i].setSelected(false);
//				expressKhung[i].newstring("");
//				expressKhung[i].setFont(font);
//				expressKhung[i].setPosition({ 405.f,250.f + 25 * i });
//			}
//			int n = 0;
//			std::string meaning;
//			std::string key;
//
//			//Khung goi y
//			bool congtac = false;
//			std::vector<Button> expressButton;
//			expressButton.resize(4);
//			for (int i = 0; i < 4; i++)
//			{
//				expressButton[i] = Button("", { 620.f,50.f }, 20, sf::Color(37, 40, 57), sf::Color::White);
//				expressButton[i].setPosition({ 368.f,155.f + i * 51.f }, 20);
//				expressButton[i].setFont(font);
//				expressButton[i].setoutline(sf::Color::Green);
//			}
//			
//
//			while (windowLang.isOpen())
//			{
//				sf::Event eventLang;
//				change = -1;
//				string tempKey = noidungnhap.getText();
//				string tempMeaning = "";
//				if (tempKey != "")
//				{
//					bool checkExist = lookUpMeaning1(root, tempKey, tempMeaning);
//					vector<pair<string, string>>::iterator kiemtra = find(likeWord.begin(), likeWord.end(), make_pair(tempKey, tempMeaning));
//					if (checkExist && kiemtra != likeWord.end())
//					{
//						change = 1;
//					}
//				}
//				while (windowLang.pollEvent(eventLang))
//				{
//					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					{
//						float posx = sf::Mouse::getPosition(windowLang).x;
//						float posy = sf::Mouse::getPosition(windowLang).y;
//						if (posx > 1039 && posx < 1090 && posy>80 && posy < 124)
//						{
//							if (change == -1 && tempKey!="" && tempMeaning!="")
//							{
//								likeWord.push_back(make_pair(tempKey, tempMeaning));
//							}
//						}
//						if (posx > 367 && posx < 986 && posy>99 && posy < 153)
//						{
//							noidungnhap.clearString();
//							noidungnhap.setSelected(true);
//							congtac = true;
//						}
//						else
//						{
//							noidungnhap.setSelected(false);
//							congtac = false;
//						}
//						if (posx > 159 && posx < 284 && posy>228 && posy < 348)
//						{
//							windowLang.close();
//							sf::Texture texttureLike;
//							texttureLike.loadFromFile("favourite.png");
//							sf::RenderWindow windowLike(sf::VideoMode(texttureLike.getSize().x, texttureLike.getSize().y), "LIKE", sf::Style::None);
//							windowLike.setFramerateLimit(60);
//							windowLike.setPosition({ 40,10 });
//							sf::Sprite spriteLike;
//							spriteLike.setTexture(texttureLike);
//
//							//khung 1
//							
//
//
//							vector<Textbox> expressKhung1KeyLike;
//							expressKhung1KeyLike.resize(3);
//							vector<Textbox> expressKhung1meaningLike;
//							expressKhung1meaningLike.resize(3);
//							for (int i = 0; i < 3; i++)
//							{
//								expressKhung1meaningLike[i].setcolor(sf::Color::Black);
//								expressKhung1meaningLike[i].setSize(20);
//								expressKhung1meaningLike[i].setSelected(false);
//								expressKhung1meaningLike[i].newstring("");
//								expressKhung1meaningLike[i].setFont(font);
//								expressKhung1meaningLike[i].setPosition({ 180.f,391.f + 25 * i });
//								expressKhung1KeyLike[i].setcolor(sf::Color::Black);
//								expressKhung1KeyLike[i].setSize(20);
//								expressKhung1KeyLike[i].setSelected(false);
//								expressKhung1KeyLike[i].newstring("");
//								expressKhung1KeyLike[i].setFont(font);
//								expressKhung1KeyLike[i].setPosition({ 180.f,300.f + 25 * i });
//								
//							}
//							int n1LikeKey = 0;
//							int n1LikeMeaning = 0;
//
//							////khung 2
//							vector<Textbox> expressKhung2KeyLike;
//							expressKhung2KeyLike.resize(3);
//							vector<Textbox> expressKhung2meaningLike;
//							expressKhung2meaningLike.resize(3);
//							for (int i = 0; i < 3; i++)
//							{
//								expressKhung2meaningLike[i].setcolor(sf::Color::Black);
//								expressKhung2meaningLike[i].setSize(20);
//								expressKhung2meaningLike[i].setSelected(false);
//								expressKhung2meaningLike[i].newstring("");
//								expressKhung2meaningLike[i].setFont(font);
//								expressKhung2meaningLike[i].setPosition({ 790.f,391.f + 25 * i });
//								expressKhung2KeyLike[i].setcolor(sf::Color::Black);
//								expressKhung2KeyLike[i].setSize(20);
//								expressKhung2KeyLike[i].setSelected(false);
//								expressKhung2KeyLike[i].newstring("");
//								expressKhung2KeyLike[i].setFont(font);
//								expressKhung2KeyLike[i].setPosition({ 790.f,300.f + 25 * i });
//
//							}
//							int n2LikeKey = 0;
//							int n2LikeMeaning = 0;
//							int kickcoLike = likeWord.size();
//							int chisoLike = 0;
//
//							while (windowLike.isOpen())
//							{
//								sf::Event eventLike;
//								while (windowLike.pollEvent(eventLike))
//								{
//									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//									{
//										float posx = sf::Mouse::getPosition(windowLike).x;
//										float posy = sf::Mouse::getPosition(windowLike).y;
//										if (posx > 218 && posx < 310 && posy>93 && posy < 179)
//										{
//											releaseLikeWord("LIKEWORD.txt", likeWord);
//											likeWord.clear();
//											windowLike.close();
//											goto bgHis;
//										}
//										if (posx > 483 && posx < 593 && posy>555 && posy < 605)
//										{
//											if (chisoLike - 2 >= 0)
//												chisoLike -= 2;
//										}
//										if (posx > 732 && posx < 841 && posy>555 && posy < 603)
//										{
//											if (kickcoLike - 1 - chisoLike >= 2)
//												chisoLike += 2;
//										}
//										if (posx > 460 && posx < 507 && posy>316 && posy<363)
//										{
//											likeWord.erase(likeWord.begin()+kickcoLike - 1 - chisoLike);
//											kickcoLike = likeWord.size();
//										}
//										if (posx > 1069 && posx < 1120 && posy>318 && posy < 366)
//										{
//											likeWord.erase(likeWord.begin() + kickcoLike - 2 - chisoLike);
//											kickcoLike = likeWord.size();
//										}
//									}
//									if (kickcoLike - 1 - chisoLike < 0)
//									{
//										n1LikeKey = 0;
//										n1LikeMeaning = 0;
//						
//									}
//									else
//									{
//										n1LikeKey = 0;
//										std::vector<string> cumDong1Key = cumTu(likeWord[kickcoLike - 1 - chisoLike].first, 38);
//										for (int i = 0; i < cumDong1Key.size(); i++)
//										{
//											n1LikeKey++;
//											expressKhung1KeyLike[i].newstring(cumDong1Key[i]);
//										}
//										n1LikeMeaning = 0;
//										std::vector<string> cumDong1meaning = cumTu(likeWord[kickcoLike - 1 - chisoLike].second, 38);
//										for (int i = 0; i < cumDong1meaning.size(); i++)
//										{
//											n1LikeMeaning++;
//											expressKhung1meaningLike[i].newstring(cumDong1meaning[i]);
//										}
//									}
//									if (kickcoLike - 2 - chisoLike < 0)
//									{
//										n2LikeKey = 0;
//										n2LikeMeaning = 0;
//
//									}
//									else
//									{
//										n2LikeKey = 0;
//										std::vector<string> cumDong2Key = cumTu(likeWord[kickcoLike - 2 - chisoLike].first, 38);
//										for (int i = 0; i < cumDong2Key.size(); i++)
//										{
//											n2LikeKey++;
//											expressKhung2KeyLike[i].newstring(cumDong2Key[i]);
//										}
//										n2LikeMeaning = 0;
//										std::vector<string> cumDong2meaning = cumTu(likeWord[kickcoLike - 2 - chisoLike].second, 38);
//										for (int i = 0; i < cumDong2meaning.size(); i++)
//										{
//											n2LikeMeaning++;
//											expressKhung2meaningLike[i].newstring(cumDong2meaning[i]);
//										}
//									}
//								}
//
//								windowLike.clear();
//								windowLike.draw(spriteLike);
//								for (int i = 0; i < n1LikeKey; i++)
//								{
//									expressKhung1KeyLike[i].drawTo(windowLike);
//								}
//								for (int i = 0; i < n1LikeMeaning; i++)
//								{
//									expressKhung1meaningLike[i].drawTo(windowLike);
//								}
//								for (int i = 0; i < n2LikeKey; i++)
//								{
//									expressKhung2KeyLike[i].drawTo(windowLike);
//								}
//								for (int i = 0; i < n2LikeMeaning; i++)
//								{
//									expressKhung2meaningLike[i].drawTo(windowLike);
//								}
//								windowLike.display();
//							}
//
//						}
//						if (posx > 156 && posx < 281 && posy>430 && posy < 537)
//						{
//							releaseLikeWord("LIKEWORD.txt", likeWord);
//							likeWord.clear();
//							windowLang.close();
//							if (langcheck == 1)
//							{
//								sf::Texture texttureHis;
//								texttureHis.loadFromFile("history.png");
//								sf::RenderWindow windowHis(sf::VideoMode(texttureHis.getSize().x, texttureHis.getSize().y), "HISTORY", sf::Style::None);
//								windowHis.setFramerateLimit(60);
//								windowHis.setPosition({ 40,10 });
//								sf::Sprite spriteHis;
//								spriteHis.setTexture(texttureHis);
//
//								Textbox deleteButton(40, sf::Color::White, false);
//								deleteButton.setPosition({ 120.f,550.f });
//								deleteButton.newstring("DELETE");
//								deleteButton.setFont(font);
//								deleteButton.setscaleAndOut(2.f, 0, 187, 191);
//
//								vector<pair<string, string>> khungluu;
//								khungluu = viewHistory("ENGLISHWORD.txt");
//								int chiso = 0;
//								int kichco = khungluu.size();
//
//								//history 1
//								Textbox expressKhung1Key(20, sf::Color::Black, false);
//								expressKhung1Key.setFont(font);
//								expressKhung1Key.setPosition({ 167.f,237.f });
//
//								//history 2
//								Textbox expressKhung2Key(20, sf::Color::Black, false);
//								expressKhung2Key.setFont(font);
//								expressKhung2Key.setPosition({ 753.f,237.f });
//
//								//history 3
//								Textbox expressKhung3Key(20, sf::Color::Black, false);
//								expressKhung3Key.setFont(font);
//								expressKhung3Key.setPosition({ 167.f,415.f });
//
//								//history 4
//								Textbox expressKhung4Key(20, sf::Color::Black, false);
//								expressKhung4Key.setFont(font);
//								expressKhung4Key.setPosition({ 757.f,415.f });
//
//								//history 1
//								vector<Textbox> expressKhung1meaning;
//								expressKhung1meaning.resize(3);
//
//								//history 2
//								vector<Textbox> expressKhung2meaning;
//								expressKhung2meaning.resize(3);
//
//								//history 3
//								vector<Textbox> expressKhung3meaning;
//								expressKhung3meaning.resize(3);
//
//								//history 4
//								vector<Textbox> expressKhung4meaning;
//								expressKhung4meaning.resize(3);
//
//								for (int i = 0; i < 3; i++)
//								{
//									//history 1
//									expressKhung1meaning[i].setcolor(sf::Color::Black);
//									expressKhung1meaning[i].setSize(20);
//									expressKhung1meaning[i].setSelected(false);
//									expressKhung1meaning[i].newstring("");
//									expressKhung1meaning[i].setFont(font);
//									expressKhung1meaning[i].setPosition({ 202.f,291.f + 25 * i });
//
//									//history 2
//									expressKhung2meaning[i].setcolor(sf::Color::Black);
//									expressKhung2meaning[i].setSize(20);
//									expressKhung2meaning[i].setSelected(false);
//									expressKhung2meaning[i].newstring("");
//									expressKhung2meaning[i].setFont(font);
//									expressKhung2meaning[i].setPosition({ 788.f,291.f + 25 * i });
//
//									//history 3
//									expressKhung3meaning[i].setcolor(sf::Color::Black);
//									expressKhung3meaning[i].setSize(20);
//									expressKhung3meaning[i].setSelected(false);
//									expressKhung3meaning[i].newstring("");
//									expressKhung3meaning[i].setFont(font);
//									expressKhung3meaning[i].setPosition({ 202.f,469.f + 25 * i });
//
//									//history 4
//									expressKhung4meaning[i].setcolor(sf::Color::Black);
//									expressKhung4meaning[i].setSize(20);
//									expressKhung4meaning[i].setSelected(false);
//									expressKhung4meaning[i].newstring("");
//									expressKhung4meaning[i].setFont(font);
//									expressKhung4meaning[i].setPosition({ 792.f,469.f + 25 * i });
//								}
//								int n1 = 0;
//								int n2 = 0;
//								int n3 = 0;
//								int n4 = 0;
//
//
//
//
//
//								while (windowHis.isOpen())
//								{
//									sf::Event eventHis;
//									while (windowHis.pollEvent(eventHis))
//									{
//										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//										{
//											float posx = sf::Mouse::getPosition(windowHis).x;
//											float posy = sf::Mouse::getPosition(windowHis).y;
//											if (posx > 299 && posx < 380 && posy>99 && posy < 177)
//											{
//												windowHis.close();
//												khungluu.clear();
//												goto bgHis;
//											}
//											if (posx > 483 && posx < 593 && posy>555 && posy < 605)
//											{
//												if (chiso - 4 >= 0)
//													chiso -= 4;
//											}
//											if (posx > 732 && posx < 841 && posy>555 && posy < 603)
//											{
//												if (kichco - 1 - chiso >= 4)
//													chiso += 4;
//											}
//										}
//
//									}
//									if (deleteButton.isMouseOver(windowHis))
//									{
//										deleteButton.setcolor(sf::Color::Red);
//										deleteButton.setscaleAndOut(3.f, 245, 168, 154);
//									}
//									else
//									{
//										deleteButton.setcolor(sf::Color::White);
//										deleteButton.setscaleAndOut(2.f, 0, 187, 191);
//									}
//									if (deleteButton.isKickMouse(windowHis))
//									{
//										deleteHistory("ENGLISHWORD.txt");
//										windowHis.close();
//										khungluu.clear();
//										goto bgHis;
//									}
//									//History 1 content
//									if (kichco - 1 - chiso < 0)
//									{
//										expressKhung1Key.newstring("");
//										n1 = 0;
//									}
//									else
//									{
//										n1 = 0;
//										expressKhung1Key.newstring(khungluu[kichco - 1 - chiso].first);
//										std::vector<string> cumDong1 = cumTu(khungluu[kichco - 1 - chiso].second, 38);
//										for (int i = 0; i < cumDong1.size(); i++)
//										{
//											n1++;
//											expressKhung1meaning[i].newstring(cumDong1[i]);
//										}
//									}
//
//
//
//									//History 2 content
//									if (kichco - 2 - chiso < 0)
//									{
//										expressKhung2Key.newstring("");
//										n2 = 0;
//									}
//									else
//									{
//										n2 = 0;
//										expressKhung2Key.newstring(khungluu[kichco - 2 - chiso].first);
//										std::vector<string> cumDong2 = cumTu(khungluu[kichco - 2 - chiso].second, 38);
//										for (int i = 0; i < cumDong2.size(); i++)
//										{
//											n2++;
//											expressKhung2meaning[i].newstring(cumDong2[i]);
//										}
//									}
//									//History 3 content
//									if (kichco - 3 - chiso < 0)
//									{
//										expressKhung3Key.newstring("");
//										n3 = 0;
//									}
//									else
//									{
//										n3 = 0;
//										expressKhung3Key.newstring(khungluu[kichco - 3 - chiso].first);
//										std::vector<string> cumDong3 = cumTu(khungluu[kichco - 3 - chiso].second, 38);
//										for (int i = 0; i < cumDong3.size(); i++)
//										{
//											n3++;
//											expressKhung3meaning[i].newstring(cumDong3[i]);
//										}
//									}
//									//History 4 content
//									if (kichco - 4 - chiso < 0)
//									{
//										expressKhung4Key.newstring("");
//										n4 = 0;
//									}
//									else
//									{
//										n4 = 0;
//										expressKhung4Key.newstring(khungluu[kichco - 4 - chiso].first);
//										std::vector<string> cumDong4 = cumTu(khungluu[kichco - 4 - chiso].second, 38);
//										for (int i = 0; i < cumDong4.size(); i++)
//										{
//											n4++;
//											expressKhung4meaning[i].newstring(cumDong4[i]);
//										}
//									}
//									windowHis.clear();
//									windowHis.draw(spriteHis);
//									expressKhung1Key.drawTo(windowHis);
//									for (int i = 0; i < n1; i++)
//									{
//										expressKhung1meaning[i].drawTo(windowHis);
//									}
//									expressKhung2Key.drawTo(windowHis);
//									for (int i = 0; i < n2; i++)
//									{
//										expressKhung2meaning[i].drawTo(windowHis);
//									}
//									expressKhung3Key.drawTo(windowHis);
//									for (int i = 0; i < n3; i++)
//									{
//										expressKhung3meaning[i].drawTo(windowHis);
//									}
//									expressKhung4Key.drawTo(windowHis);
//									for (int i = 0; i < n4; i++)
//									{
//										expressKhung4meaning[i].drawTo(windowHis);
//									}
//									deleteButton.drawTo(windowHis);
//									windowHis.display();
//								}
//							}
//							else if (langcheck == -1)
//							{
//								sf::Texture texttureHis;
//								texttureHis.loadFromFile("historyViet.png");
//								sf::RenderWindow windowHis(sf::VideoMode(texttureHis.getSize().x, texttureHis.getSize().y), "HISTORY", sf::Style::None);
//								windowHis.setFramerateLimit(60);
//								windowHis.setPosition({ 40,10 });
//								sf::Sprite spriteHis;
//								spriteHis.setTexture(texttureHis);
//
//								Textbox deleteButton(40, sf::Color::White, false);
//								deleteButton.setPosition({ 120.f,550.f });
//								deleteButton.newstring("DELETE");
//								deleteButton.setFont(font);
//								deleteButton.setscaleAndOut(2.f, 0, 187, 191);
//
//								vector<pair<string, string>> khungluu;
//								khungluu = viewHistory("VIETNAMWORD.txt");
//								int chiso = 0;
//								int kichco = khungluu.size();
//
//								//history 1
//								Textbox expressKhung1meaning(20, sf::Color::Black, false);
//								expressKhung1meaning.setFont(font);
//								expressKhung1meaning.setPosition({ 287.f,315.f });
//
//
//								vector<Textbox> expressKhung1key;
//								expressKhung1key.resize(3);
//								for (int i = 0; i < 3; i++)
//								{
//									expressKhung1key[i].setcolor(sf::Color::Black);
//									expressKhung1key[i].setSize(20);
//									expressKhung1key[i].setSelected(false);
//									expressKhung1key[i].newstring("");
//									expressKhung1key[i].setFont(font);
//									expressKhung1key[i].setPosition({ 202.f,230.f + 25 * i });
//								}
//								int n1 = 0;
//
//
//
//								//history 2
//								Textbox expressKhung2meaning(20, sf::Color::Black, false);
//								expressKhung2meaning.setFont(font);
//								expressKhung2meaning.setPosition({ 837.f,315.f });
//
//
//								vector<Textbox> expressKhung2key;
//								expressKhung2key.resize(3);
//								for (int i = 0; i < 3; i++)
//								{
//									expressKhung2key[i].setcolor(sf::Color::Black);
//									expressKhung2key[i].setSize(20);
//									expressKhung2key[i].setSelected(false);
//									expressKhung2key[i].newstring("");
//									expressKhung2key[i].setFont(font);
//									expressKhung2key[i].setPosition({ 752.f,230.f + 25 * i });
//								}
//								int n2 = 0;
//
//
//
//
//								//history 3
//								Textbox expressKhung3meaning(20, sf::Color::Black, false);
//								expressKhung3meaning.setFont(font);
//								expressKhung3meaning.setPosition({ 287.f,490.f });
//
//
//								vector<Textbox> expressKhung3key;
//								expressKhung3key.resize(3);
//								for (int i = 0; i < 3; i++)
//								{
//									expressKhung3key[i].setcolor(sf::Color::Black);
//									expressKhung3key[i].setSize(20);
//									expressKhung3key[i].setSelected(false);
//									expressKhung3key[i].newstring("");
//									expressKhung3key[i].setFont(font);
//									expressKhung3key[i].setPosition({ 202.f,405.f + 25 * i });
//								}
//								int n3 = 0;
//
//
//
//								//history 4
//								Textbox expressKhung4meaning(20, sf::Color::Black, false);
//								expressKhung4meaning.setFont(font);
//								expressKhung4meaning.setPosition({ 837.f,490.f });
//
//
//								vector<Textbox> expressKhung4key;
//								expressKhung4key.resize(3);
//								for (int i = 0; i < 3; i++)
//								{
//									expressKhung4key[i].setcolor(sf::Color::Black);
//									expressKhung4key[i].setSize(20);
//									expressKhung4key[i].setSelected(false);
//									expressKhung4key[i].newstring("");
//									expressKhung4key[i].setFont(font);
//									expressKhung4key[i].setPosition({ 752.f,405.f + 25 * i });
//								}
//								int n4 = 0;
//
//
//
//
//
//								while (windowHis.isOpen())
//								{
//									sf::Event eventHis;
//									while (windowHis.pollEvent(eventHis))
//									{
//										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//										{
//											float posx = sf::Mouse::getPosition(windowHis).x;
//											float posy = sf::Mouse::getPosition(windowHis).y;
//											if (posx > 299 && posx < 380 && posy>99 && posy < 177)
//											{
//												windowHis.close();
//												khungluu.clear();
//												goto bgHis;
//											}
//											if (posx > 483 && posx < 593 && posy>555 && posy < 605)
//											{
//												if (chiso - 4 >= 0)
//													chiso -= 4;
//											}
//											if (posx > 732 && posx < 841 && posy>555 && posy < 603)
//											{
//												if (kichco - 1 - chiso >= 4)
//													chiso += 4;
//											}
//										}
//
//									}
//									if (deleteButton.isMouseOver(windowHis))
//									{
//										deleteButton.setcolor(sf::Color::Red);
//										deleteButton.setscaleAndOut(3.f, 245, 168, 154);
//									}
//									else
//									{
//										deleteButton.setcolor(sf::Color::White);
//										deleteButton.setscaleAndOut(2.f, 0, 187, 191);
//									}
//									if (deleteButton.isKickMouse(windowHis))
//									{
//										deleteHistory("VIETNAMWORD.txt");
//										windowHis.close();
//										khungluu.clear();
//										goto bgHis;
//									}
//
//									//History 1 content
//									if (kichco - 1 - chiso < 0)
//									{
//										expressKhung1meaning.newstring("");
//										n1 = 0;
//									}
//									else
//									{
//										n1 = 0;
//										expressKhung1meaning.newstring(khungluu[kichco - 1 - chiso].second);
//										std::vector<string> cumDong1 = cumTu(khungluu[kichco - 1 - chiso].first, 38);
//										for (int i = 0; i < cumDong1.size(); i++)
//										{
//											n1++;
//											expressKhung1key[i].newstring(cumDong1[i]);
//										}
//									}
//
//
//
//									//History 2 content
//									if (kichco - 2 - chiso < 0)
//									{
//										expressKhung2meaning.newstring("");
//										n2 = 0;
//									}
//									else
//									{
//										n2 = 0;
//										expressKhung2meaning.newstring(khungluu[kichco - 2 - chiso].second);
//										std::vector<string> cumDong2 = cumTu(khungluu[kichco - 2 - chiso].first, 38);
//										for (int i = 0; i < cumDong2.size(); i++)
//										{
//											n2++;
//											expressKhung2key[i].newstring(cumDong2[i]);
//										}
//									}
//									//History 3 content
//									if (kichco - 3 - chiso < 0)
//									{
//										expressKhung3meaning.newstring("");
//										n3 = 0;
//									}
//									else
//									{
//										n3 = 0;
//										expressKhung3meaning.newstring(khungluu[kichco - 3 - chiso].second);
//										std::vector<string> cumDong3 = cumTu(khungluu[kichco - 3 - chiso].first, 38);
//										for (int i = 0; i < cumDong3.size(); i++)
//										{
//											n3++;
//											expressKhung3key[i].newstring(cumDong3[i]);
//										}
//									}
//									//History 4 content
//									if (kichco - 4 - chiso < 0)
//									{
//										expressKhung4meaning.newstring("");
//										n4 = 0;
//									}
//									else
//									{
//										n4 = 0;
//										expressKhung4meaning.newstring(khungluu[kichco - 4 - chiso].second);
//										std::vector<string> cumDong4 = cumTu(khungluu[kichco - 3 - chiso].first, 38);
//										for (int i = 0; i < cumDong4.size(); i++)
//										{
//											n4++;
//											expressKhung4key[i].newstring(cumDong4[i]);
//										}
//									}
//									windowHis.clear();
//									windowHis.draw(spriteHis);
//									expressKhung1meaning.drawTo(windowHis);
//									for (int i = 0; i < n1; i++)
//									{
//										expressKhung1key[i].drawTo(windowHis);
//									}
//									expressKhung2meaning.drawTo(windowHis);
//									for (int i = 0; i < n2; i++)
//									{
//										expressKhung2key[i].drawTo(windowHis);
//									}
//									expressKhung3meaning.drawTo(windowHis);
//									for (int i = 0; i < n3; i++)
//									{
//										expressKhung3key[i].drawTo(windowHis);
//									}
//									expressKhung4meaning.drawTo(windowHis);
//									for (int i = 0; i < n4; i++)
//									{
//										expressKhung4key[i].drawTo(windowHis);
//									}
//									deleteButton.drawTo(windowHis);
//									windowHis.display();
//								}
//							}
//						}
//						if (posx > 1127 && posx < 1159 && posy>77 && posy < 130)
//						{
//							releaseLikeWord("LIKEWORD.txt",likeWord);
//							likeWord.clear();
//							windowLang.close();
//							goto bg;
//						}
//					}
//					if (eventLang.type == sf::Event::TextEntered)
//					{
//						for (int i = 0; i < 4; i++)
//						{
//							expressButton[i].setText("");
//						}
//						noidungnhap.typeOn(eventLang);
//						std::string textCheck = noidungnhap.getText();
//						vector <pair<string, string>> hello = lookUpMeaning(root, textCheck);
//						for (int i = 0; i < 4 && i<hello.size(); i++)
//						{
//							expressButton[i].setText(hello[i].first);
//						}
//					}
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
//					{
//						congtac = false;
//						n = 0;
//						noidungnhap.setSelected(false);
//						
//						key = noidungnhap.getText();
//						bool check = lookUpMeaning1(root, key, meaning);
//						if (!check)
//						{
//							n++;
//							expressKhung[0].newstring("NOT WORD");
//						}
//						else if(check)
//						{
//							std::vector<string> cumDong = cumTu(meaning, 90);
//							for (int i = 0; i < cumDong.size(); i++)
//							{
//								n++;
//								expressKhung[i].newstring(cumDong[i]);
//							}
//							if (langcheck == 1)
//								savetoHistory(key, "ENGLISHWORD.txt",meaning);
//							else if(langcheck==-1)
//								savetoHistory(key, "VIETNAMWORD.txt", meaning);
//						}
//					}
//					if (language.isKickMouse(windowLang))
//					{
//						if (langcheck == 1)
//						{
//							language.newstring("VNM");
//							root = rootVietNam;
//							langcheck = -1;
//						}
//						else if (langcheck == -1)
//						{
//							language.newstring("ENG");
//							root = rootEngLish;
//							langcheck = 1;
//						}
//					}
//					if (change == 1)
//					{
//						spriteBgLang.setTexture(BgLang1);
//					}
//					else if (change == -1)
//					{
//						spriteBgLang.setTexture(BgLang);
//					}
//
//					
//				}
//			
//				
//				windowLang.clear();
//				windowLang.draw(spriteBgLang);
//				windowLang.draw(khungnhap);
//				noidungnhap.drawTo(windowLang);
//				
//				for (int i = 0; i < n; i++)
//					expressKhung[i].drawTo(windowLang);
//				/*expressOutWord.drawTo(windowLang);*/
//				definationoRKey.drawTo(windowLang);
//				if (congtac)
//				{
//					for (int i = 0; i < 4; i++)
//					{
//						expressButton[i].drawTo(windowLang);
//					}
//				}
//				language.drawTo(windowLang);
//				windowLang.display();
//			}
//
//		}
//		if (nutExit.isMouseOver(window))
//		{
//			nutExit.setcolor(sf::Color::Red);
//			nutExit.setscaleAndOut(3.f, 245, 168, 154);
//		}
//		else
//		{
//			nutExit.setcolor(sf::Color::White);
//			nutExit.setscaleAndOut(2.f, 0, 187, 191);
//		}
//		if (nutExit.isKickMouse(window))
//			window.close();
//
//
//		window.clear();
//		
//		
//		window.draw(spriteBG);
//		nuthome.drawTo(window);
//		nutLang.drawTo(window);
//		nutNewword.drawTo(window);
//		nutExit.drawTo(window);
//		window.display();
//	}
//	Deallocate(rootEngLish);
//	Deallocate(rootVietNam);
//}