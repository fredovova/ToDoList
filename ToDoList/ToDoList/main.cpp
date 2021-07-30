#include <iostream>
#include "Functionr.h"

void language()
{
	using namespace std;
	cout << " Choose language : " <<
		"  1.English ,  2.Russian" << endl;;
	int language;
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
int main()
{
	using namespace std;
	setlocale(LC_ALL, "ru");

	language();

	return 0;
}