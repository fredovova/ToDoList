#pragma once
void show_menu_en();
void show_menu_ru();
void add_note(std::string&new_note);
void show_all_notes();
std::string* Find_note(const std::string& note_to_find, int& n_found);
void  Remove_one_note(int &a,std::string &ptr);
std::string *all_notes(int& n_count);
void remove_one_note(std::string* all_notes_ptr, int n_count, int& a);
void Remove_all_notes();