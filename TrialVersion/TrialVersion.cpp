// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <String>
#include "windows.h"
#include <cstdlib>
#include <filesystem>
#include <stdio.h>
#include <io.h>
#include <sstream>


#define FlagHacker true
using namespace std;

int on, tw, th;

// Функция, которая либо извлекает дату и время обращения, изменения и создания файла, либо устанавливает её
// (в зависимости от поданного на вход флага)
void getSetDate(string strPath, LPFILETIME createt , LPFILETIME accesst, LPFILETIME writet, bool getOrSet)
{
	OFSTRUCT ofstruct;
	HANDLE handleFile = (HANDLE)OpenFile(strPath.c_str(), &ofstruct, OF_READWRITE);
	if (getOrSet)
	{
		GetFileTime(handleFile, createt, accesst, writet);
	}
	else
	{
		SetFileTime(handleFile, createt, accesst, writet);
	}
	CloseHandle(handleFile);
}

// Функция для шифрования путей к файлам
int* Func(string str) 
{
	string k = "dfc"; // Строка - ключ
	int str_length = str.length();
	int k_length = 3;
	int mod = str_length % k_length;
	int i_n = (str_length - mod) / k_length;

	// Генерируем новую строку, длины str.length()
	for (int i = 0; i < i_n; i++) {
		k += "dfc";
	}

	if (mod > 0) {
		k += "dfc";
	}

	int *intarr = new int[str_length];

	for (int i = 0; i < str_length; i++) {
		str[i] = str[i] ^ k[i]; // Побитовый XOR
		intarr[i] = 20 + (int)str[i];
	}

	return intarr;
}


// Функция для расшифровки количества запусков
string anotherFunc(int arrayInt[], int length) 
{
	string res = "";
	// Строка со случайными символами
	string chars = "THEQU3ICKBRO19WNF2XJMPSVLAZ0YDG:\\.theq6uickb8rown5fxjmp7sv4lazydg";
	// Строка с символами, расположенными по порядку
	string string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz:\\0123456789."; 

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < 65; j++)
		{
			// Если символ равен символу из случайной строки
			if (chars[j] == (char)arrayInt[i])
			{
				res += string[j]; // берётся символ из упорядоченной строки
			}
		}
	}
	return res;
}

// Функция для шифрования количества запусков
int* someFunction(string text) 
{
	int strlength = text.length();
	// Строка со случайными символами
	string chars = "THEQU3ICKBRO19WNF2XJMPSVLAZ0YDG:\\.theq6uickb8rown5fxjmp7sv4lazydg";
	int *arrint = new int [strlength];
	// Строка с символами, расположенными по порядку
	string string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz:\\0123456789.";

	int n = 0;
	for (int i = 0; i < strlength; i++) 
	{
		for (int j = 0; j < 65; j++) 
		{
			// Если символ равен символу из упорядоченной строки
			if (text[i] == string[j]) 
			{
				// соответствующий символ из случайной строки преобразуется в int
				char chr = chars[j];
				arrint[n] = (int)chr;
				n++;
			}
		}
	}
	return arrint;
}

// Строка для расшифровки путей к файлам
string algoRitm(int arr[], int arrLength) 
{ 
	string k = "";
	string str = "";

	int k_length = 3;
	int mod = arrLength % k_length;
	int i_n = (arrLength - mod) / k_length;

	// Генерируем строку соответствующей длины
	for (int i = 0; i < i_n; i++) {
		k += "dfc";
	}

	if (mod > 0) {
		k += "dfc";
	}

	// Преобразуем целые числа в символы, вычитая число 20
	for (int i = 0; i < arrLength; i++) {
		str += (char) arr[i] - 20;
	}

	// побитовый XOR
	for (int i = 0; i < arrLength; i++) {
		str[i] = str[i] ^ k[i];
	}

	return str;
}

// Отвлекающая функция проверки
bool check() 
{
	int q = -1;
	SYSTEMTIME sTime;
	FILETIME ct, at, wt;
	OFSTRUCT of;
	HANDLE hFile = (HANDLE)OpenFile("C:\\WinLogs\\license1.txt", &of, OF_CREATE);
	GetFileTime(hFile, &ct, &at, &wt);
	FileTimeToSystemTime(&ct, &sTime);
	if (!q) {
		cout << "Дата создания: " << sTime.wYear << " " << sTime.wDay << " " << sTime.wMonth << endl;
	}
	if ((FlagHacker && (sTime.wYear != 2010) || (sTime.wDay != 21) || (sTime.wMonth != 01) || (sTime.wHour != 03) || (sTime.wMinute != 04) || (sTime.wSecond != 05)) && !FlagHacker) {
		cout << "Доступ запрещён!" << endl;
		return false;
	}
	sTime.wYear = 2010;
	sTime.wDay = 21;
	sTime.wMonth = 01;
	sTime.wHour = 03;
	sTime.wMinute = 04;
	sTime.wSecond = 05;
	SystemTimeToFileTime(&sTime, &wt);
	SetFileTime(hFile, &wt, &wt, &wt);
	CloseHandle(hFile);
	return true;
}

// Функция, проверяющая, остались ли ещё попытки
// на вход - три строки, полученные из файлов
bool thirdFunction(string one, string two, string three)
{
	// Преоразуем строки в int и расшифровываем. Получаем число запусков (string)
	int *arrayint = new int[1];
	arrayint[0] = atoi(one.c_str());
	one = anotherFunc(arrayint, 1);

	arrayint[0] = atoi(two.c_str());
	two = anotherFunc(arrayint, 1);

	arrayint[0] = atoi(three.c_str());
	three = anotherFunc(arrayint, 1);

	// Преобразуем число запусков снова в int, чтобы сравнить
	int oneint = atoi(one.c_str());
	int twoint = atoi(two.c_str());
	int threeint = atoi(three.c_str());

	// Сравнение 
	// число из отвлекающего файла всегда положительное, поэтому не влияет на результат проверки
	if ((oneint == twoint) && ((oneint > 0) && (threeint > 0)))
	{
		// Числа сохраняются, чтобы записать обновлённые данные в файлы
		on = oneint - 1;
		tw = twoint - 1;
		th = threeint + 1;
		return true;
	}

	return false;
}

int main(int argc, char* argv[]) 
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	error_code e;
	LPCWSTR strng = L"C:\\ProgramData\\D";
	string с, str;

	if (CreateDirectory(strng, NULL))
	{
		с = "directory create";
	}
	else 
	{
		с = "error create directory";
	}

	strng = L"C:\\ProgramData\\C";

	if (CreateDirectory(strng, NULL))
	{
		с = "directory create";
	}
	else
	{
		с = "error create directory";
	}

	// Зашифрованные пути к файлам
	/*
	int array1[38] = { 59, 112, 83, 69, 41, 26, 42, 41, 83, 72, 39, 21, 28, 35, 20, 76, 54, 32, 27, 39, 34, 21, 28, 43, 43, 78, 52, 76, 37, 30, 30, 30, 32, 23, 92, 43, 48, 38 };// "C:\\Users\\Public\\Documents\\C\\winlog.txt"
	int array2[34] = { 59, 112, 83, 69, 41, 26, 42, 41, 83, 72, 39, 21, 28, 35, 20, 76, 54, 32, 27, 39, 34, 21, 28, 43, 43, 78, 30, 30, 20, 32, 94, 38, 47, 36 }; // "C:\\Users\\Public\\Documents\\info.txt"
	int array3[13] = { 52, 112, 83, 39, 35, 33, 60, 29, 24, 94, 38, 47, 36 }; // "D:\\winLog.txt"
	*/

	int array1[27] = { 59, 112, 83, 72, 40, 32, 23, 40, 22, 29, 54, 22, 36, 27, 83, 59, 78, 40, 33, 28, 35, 31, 21, 97, 36, 50, 43 }; // C:\\ProgramData\\C\\winlog.txt
	int array2[23] = { 59, 112, 83, 72, 40, 32, 23, 40, 22, 29, 54, 22, 36, 27, 83, 33, 28, 25, 31, 92, 43, 48, 38 }; // C:\\ProgramData\\info.txt
	int array3[27] = { 59, 112, 83, 72, 40, 32, 23, 40, 22, 29, 54, 22, 36, 27, 83, 52, 78, 40, 33, 28, 67, 31, 21, 97, 36, 50, 43 }; // C:\\ProgramData\\D\\winLog.txt

	// Берём даты и время каждого файла
	FILETIME ct1, ct2, ct3, at1, at2, at3, wt1, wt2, wt3;
	getSetDate(algoRitm(array1, 27), &ct1, &at1, &wt1, true);
	getSetDate(algoRitm(array2, 23), &ct2, &at2, &wt2, true);
	getSetDate(algoRitm(array3, 27), &ct3, &at3, &wt3, true);
	
	ifstream fl1(algoRitm(array1, 27));
	ifstream fl2(algoRitm(array2, 23));
	ifstream fl3(algoRitm(array3, 27));

	if (!fl1 && !fl2 && !fl3) {
		ofstream f1(algoRitm(array1, 27));
		ofstream f2(algoRitm(array2, 23));
		ofstream f3(algoRitm(array3, 27));

		if (f1.is_open() && f2.is_open() && f3.is_open())
		{
			f1 << 52;
			f2 << 52;
			f3 << 52;
		}

		f1.close();
		f2.close();
		f3.close();

		getSetDate(algoRitm(array1, 27), &ct1, &at1, &wt1, true);
		getSetDate(algoRitm(array2, 23), &ct2, &at2, &wt2, true);
		getSetDate(algoRitm(array3, 27), &ct3, &at3, &wt3, true);
	}

	fl1.close();
	fl2.close();
	fl3.close();

	// Открываем файлы
	ifstream fin1(algoRitm(array1, 27));
	ifstream fin2(algoRitm(array2, 23));
	ifstream fin3(algoRitm(array3, 27));

	// Если не получиось открыть - выход
	if (!(fin1.is_open() || fin2.is_open() || fin3.is_open())) {
		cout << endl;
		cout << "Произошла ошибка. Вероятно, закрыт доступ к файлам" << endl;
		system("pause");
		return false;
	}

	// Считываем из файлов строки
	string buff1, buff2, buff3;
	getline(fin1, buff1);
	getline(fin2, buff2);
	getline(fin3, buff3);

	fin1.close();
	fin2.close();
	fin3.close();

	bool abcd = check();
	int i = 0;
	// Отвлекающая функция - в любом случае вернёт true
	if (abcd) {
		cout << "Программа для установки даты и времени изменения файла" << endl;
		// Если число запусков ещё не исчерпано, программа выполняется
		if (thirdFunction(buff1, buff2, buff3)) {
			while (true) {
				int btn;
				cout << endl;
				cout << "Нажмите клавишу 1, чтобы установить дату и время изменения файла" << endl;
				
				// После нескольких действий, файлы снова открываются
				ofstream fout1(algoRitm(array1, 27));
				ofstream fout2(algoRitm(array2, 23));
				ofstream fout3(algoRitm(array3, 27));

				// В них перезаписывается информация о числе запусков
				if (fout1.is_open() && fout2.is_open()) 
				{
					ostringstream stream1, stream2;
					stream1 << on;
					stream2 << tw;

					fout1 << *someFunction(stream1.str()) << endl;
					fout2 << *someFunction(stream2.str()) << endl;
					fout1.close();
					fout2.close();
				}

				if (fout3.is_open())
				{
					ostringstream stream3;
					stream3 << th;
					fout3 << *someFunction(stream3.str()) << endl;
					fout3.close();
				}

				cout << "Чтобы выйти, нажмите любую другую клавишу" << endl;
				cout << "> ";

				// Время и даты доступа и изменения файлов с количеством запусков устанавливается таким, как было изначально
				getSetDate(algoRitm(array1, 27), &ct1, &at1, &wt1, false);
				getSetDate(algoRitm(array2, 23), &ct2, &at2, &wt2, false);
				getSetDate(algoRitm(array3, 27), &ct3, &at3, &wt3, false);

				// После перезаписи выполнение программы продолжается
				cin >> btn;
				if (btn != 1)
				{
					return 0;
				}
				else
				{
					cout << endl;
					cout << "Введите полный адрес вашего файла (например, C:\\Users\\User\\abcd.txt): " << endl;
					cout << "> ";
					cin >> str;

					SYSTEMTIME st;
					FILETIME ct, at, wt;
					OFSTRUCT of;
					HANDLE hFile = (HANDLE)OpenFile(str.c_str(), &of, OF_READWRITE);
					GetFileTime(hFile, &ct, &at, &wt);

					if (FileTimeToSystemTime(&ct, &st)) {
						cout << endl;
						cout << "Информация о файле:" << endl;
						cout << "Дата создания файла (по гринвичу): " << st.wDay << "." << st.wMonth << "." << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
						FileTimeToSystemTime(&at, &st);
						cout << "Дата доступа к файлу (по гринвичу): " << st.wDay << "." << st.wMonth << "." << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
						FileTimeToSystemTime(&wt, &st);
						cout << "Дата изменения файла (по гринвичу): " << st.wDay << "." << st.wMonth << "." << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
					}
					else
					{
						cout << endl;
						cout << "К сожалению, не удалось считать информацию о файле. Вероятно, доступ к нему закрыт" << endl;
					}

					cout << endl;
					cout << "Введите год, месяц, число, час, минуту и секунду нужной даты по Гринвичу, разделяя их клавишей Enter: " << endl;
					cout << "> ";
					cin >> st.wYear;
					cout << "> ";
					cin >> st.wMonth;
					cout << "> ";
					cin >> st.wDay;
					cout << "> ";
					cin >> st.wHour;
					cout << "> ";
					cin >> st.wMinute;
					cout << "> ";
					cin >> st.wSecond;
					if (!SystemTimeToFileTime(&st, &wt))
					{
						cout << endl;
						cout << "К сожалению, не удалось установить дату изменения для файла. Возможно, введённая информация была некорректной." << endl;
					}
					else
					{
						if (!SetFileTime(hFile, NULL, NULL, &wt))
						{
							cout << endl;
							cout << "К сожалению, не удалось установить дату изменения для файла. Вероятно, доступ к нему закрыт" << endl;
						}
						else
						{
							cout << endl;
							cout << "Дата и время изменения выбранного файла успешно перезаписаны" << endl;
						}
					}
					CloseHandle(hFile);

					i++;
					if (i > 200) {
						cout << endl;
						cout << "Произошла ошибка. Приносим извинения за неудобства. Пожалуйста, перезапустите программу" << endl;
						break;
					}
				}
			}
		}
		// Если число запусков исчерпано, то программа блокируется не сразу, выполняет несколько действий
		else 
		{
			int btn;
			cout << endl;
			cout << "Нажмите клавишу 1, чтобы установить дату и время изменения файла" << endl;
			cout << "Чтобы выйти, нажмите любую другую клавишу" << endl;
			cout << "> ";

			// Время и даты доступа и изменения файлов с количеством запусков устанавливается таким, как было изначально
			getSetDate(algoRitm(array1, 27), &ct1, &at1, &wt1, false);
			getSetDate(algoRitm(array2, 23), &ct2, &at2, &wt2, false);
			getSetDate(algoRitm(array3, 27), &ct3, &at3, &wt3, false);

			cin >> btn;

			cout << endl;
			// Но потом завершается
			cout << "Количество запусков приложения исчерпано." << endl;
			cout << "Чтобы продолжить использование программы, купите лицензию" << endl;
		}

	}
	return 0;
}