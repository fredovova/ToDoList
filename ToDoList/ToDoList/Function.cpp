#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include "menu.h"
using namespace std;
void show_menu_ru()
{
	cout << " [1] Добавить заметку" << endl;
	cout << " [2] Показать все заметки" << endl;
	cout << " [3] Найти заметку" << endl;
	cout << " [4] Удалить заметку " << endl;
	cout << " [5] Удалить все заметки" << endl;
	cout << " [6] Выйти" << endl;

}
void show_menu_en()
{
	cout << " [1] Add note" << endl;
	cout << " [2] Show all notes" << endl;
	cout << " [3] Find note" << endl;
	cout << " [4] Remove one note" << endl;
	cout << " [5] Remove all notes" << endl;
	cout << " [6] Exit" << endl;
}

//функция добавления заметки
void add_note(string& new_note)
{
	
	string patch = "text.txt";
	ofstream fout;
	fout.open(patch, fstream::in | fstream::out | fstream::app);

	if (!fout.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		SetConsoleCP(1251);
		string note;
		getline(cin, note);
		fout << note << "\n";
		SetConsoleCP(851);
	}
	fout.close();
	
}

//функция вывода заметки
void show_all_notes()
{
	string patch = "text.txt";
	ifstream open;
	open.open(patch);
	string str;
	if (!open.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		for (size_t i = 1; !open.eof(); i++)
		{
			str = "";
			getline(open, str);
			if (str.empty())
				continue;
			cout << "[" << i << "]" << str << endl;

		}
	}

	
	open.close();
}
//Найти заметку
string *Find_note(const string & note_to_find,int &n_found)
{
	string patch = "text.txt";
	ifstream open;
	open.open(patch);
	string str;
	if (!open.is_open())
	{
		cout << "Error" << endl;
	}
	string one_note;
	string *found_notes = nullptr;
	string *found_notes_tmp = nullptr;
	int count = 0;//колличество найденных элементов 
	while (!open.eof())
	{
		getline(open, one_note);	//считываем 
		if (one_note.find(note_to_find) != -1) //если присутствует строка,то увеличиваем кол-во найденных строк
		{
			count++;
			found_notes_tmp = new string[count];
			//копируем все элементы
			for (int i = 0; i < count-1; i++)
			
				found_notes_tmp[i] = found_notes[i];
				//добавляем найденную заметку в конец строки
				found_notes_tmp[count - 1] = one_note;
				//удаляем старое содержимое 
				delete []found_notes;
				found_notes = found_notes_tmp;
				found_notes_tmp = nullptr;
			
		}
		
	}
	open.close();
	n_found = count;
	return found_notes;

}
//Удалить заметку 
void  Remove_one_note(int &a,string &ptr)
{
	string patch = "text.txt";
	ifstream open;

	open.open(patch, fstream::in | fstream::out );
	ptr.erase(a);
	
		
	open.close();
}
