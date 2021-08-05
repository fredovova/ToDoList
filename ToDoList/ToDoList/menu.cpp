#include <iostream>
#include <string>
#include<vector>
#include "Functionr.h"

int language = 0;
void languag()
{
	using namespace std;
	cout << " Choose language : " <<
		"  1.English ,  2.Russian" << endl;
	cin >> language;
	switch (language)
	{
	case 1:
		show_menu_en();
		break;
	case 2:

		show_menu_ru();
		break;
	}
}
void menu()
{
	using namespace std;

	if (language == 1)
	{
		int chois = 0;
		cin >> chois;
		while (chois)
		{


			if (chois == 1)
			{
				system("cls");
				cout << "Add note()" << endl;
				string new_note;
				getline(cin, new_note);
				add_note(new_note);
				show_menu_en();
				cin >> chois;
				system("pause");
			}
			else if (chois == 2)
			{

				system("cls");
				cout << "Show all notes()" << endl;
				show_all_notes();
				show_menu_en();
				cin >> chois;
				system("pause");
			}


			else if (chois == 3)
			{

				system("cls");
				cout << "Find note()" << endl;
				string note_to_find;
				getline(cin, note_to_find);
				cout << "Поиск : " << endl;
				getline(cin, note_to_find);
				int n_found = 0;

				string* found_notes = Find_note(note_to_find, n_found);
				if (found_notes)
				{
					cout << "Заметка найдена : " << endl;
					for (size_t i = 0; i < n_found; i++)
					{
						cout << found_notes[i] << endl;
					}
					delete[]found_notes;
				}
				else
				{
					cout << "Нужных заметок нет " << endl;
				}
				show_menu_en();

				cin >> chois;
				system("pause");
			}


			else if (chois == 4)
			{

				system("cls");
				cout << "Remove one note()" << endl;
				show_menu_en();
				cin >> chois;
				system("pause");
			}
			else if (chois == 5)
			{

				system("cls");
				cout << "Remove all notes()" << endl;
				show_menu_en();

				cin >> chois;
				system("pause");
			}

			else if (chois == 6)
			{

				break;
			}
		}
	}
	if (language == 2)
	{
		int chois = 0;
		cin >> chois;
		while (chois)
		{


			if (chois == 1)
			{
				system("cls");
				cout << "Добавить заметку()" << endl;
				string new_note;
				getline(cin, new_note);
				add_note(new_note);
				show_menu_ru();
				cin >> chois;
				system("pause");
			}
			else if (chois == 2)
			{

				system("cls");
				cout << "Показать все заметки()" << endl;
				show_all_notes();
				show_menu_ru();
				cin >> chois;
				system("pause");
			}


			else if (chois == 3)
			{

				system("cls");
				cout << "Найти заметку()" << endl;
				string note_to_find;
				getline(cin, note_to_find);
				cout << "Поиск : " << endl;
				getline(cin, note_to_find);
				int n_found = 0;
				
				string *found_notes = Find_note( note_to_find, n_found);
				if (found_notes)
				{
					cout << "Заметка найдена : " << endl;
					for (int i = 0; i < n_found; i++)
					
						cout << found_notes[i] << endl;
					
					delete[]found_notes;
				}
				else
				{
					cout << "Нужных заметок нет " << endl;
				}
				show_menu_ru();
				cin >> chois;
				system("pause");
			}


			else if (chois == 4)
			{

				system("cls");
				cout << "Удалить заметку()" << endl;
				int a;
				cin >> a;
				
				
				show_menu_ru();
				cin >> chois;
				system("pause");
			}
			else if (chois == 5)
			{

				system("cls");
				cout << "Удалить все заметки()" << endl;
				show_menu_ru();
				cin >> chois;
				system("pause");
			}

			else if (chois == 6)
			{

				break;
			}
		}
	}
}