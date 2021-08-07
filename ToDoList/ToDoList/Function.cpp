#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "menu.h"
using namespace std;

//функци€ добавлени€ заметки
void add_note(string& new_note)
{
	
	string patch = "text2.txt";
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

//функци€ вывода заметки
void show_all_notes()
{
	string patch = "text2.txt";
	ifstream open;
	open.open(patch);
	string str;
	if (!open.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		for (int i = 0; !open.eof(); i++)
		{
			//str = "";
			getline(open, str);
			if (str.empty())
				continue;
			cout << "[" << i << "]" << str << endl;

		}
	}

	
	open.close();
}
//Ќайти заметку
string *Find_note(const string & note_to_find,int &n_found)
{
	string patch = "text2.txt";
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
				//добавл€ем найденную заметку в конец строки
				found_notes_tmp[count - 1] = one_note;
				//удал€ем старое содержимое 
				delete []found_notes;
				found_notes = found_notes_tmp;
				found_notes_tmp = nullptr;
			
		}
		
	}
	open.close();
	n_found = count;
	return found_notes;

}
//возвращает указатель на массив всех заметок
string *all_notes(int &n_count)
{
	string patch = "text2.txt";
	ifstream open;
	open.open(patch);
	if (!open.is_open())
	{
		cout << "Error" << endl;
	}
	string all_not;
	string *all_notes = nullptr;
	string* all_notes_tmp = nullptr;
	int count = 0;
	while (!open.eof())
	{
		getline(open,all_not);
		count++;
		all_notes_tmp = new string[count];
		for (size_t i = 1; i < count-1; i++)
		
			all_notes_tmp[i] = all_notes[i];
		
		all_notes_tmp[count - 1] = all_not;
		delete[]all_notes;
		all_notes = all_notes_tmp;
		all_notes_tmp = nullptr;
	}
	open.close();
	n_count = count;
	return all_notes;
	
}

//”дал€ем выбранную заметку

void remove_one_note(string* all_notes_ptr,int n_count ,int &a)
{
	
	string patch = "text2.txt";
	ofstream fout;
	fout.open(patch);

	if (!fout.is_open())
	{
		cout << "Error" << endl;
	}
	//запись заметки,без заметок с индексом а
	SetConsoleCP(1251);
	for (size_t i = 1; i < n_count; i++)
	{
		if (i==a-1)
		
			continue;
			fout << all_notes_ptr[i] << endl;
		
	}
	SetConsoleCP(851);
	
	fout.close();
}
void Remove_all_notes()
{
	fstream file("text2.txt", fstream::out| fstream::trunc);
	if (!file.is_open())
	{
		cout << "Error" << endl;
	}
	file.close();
}