/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: 
*
*Adrian Paez
*Juan Gallardo
*Leonardo de la Cadena
*TEMA: TALLER DE RECUPERACION - REGISTRO DE AUTOS
*FECHA DE CREACION : 26 DE FEBRERO DEL 2022
*FECHA DE MODIFICACION: 26 DE FEBRERO DEL 2022
* */
#pragma once
#include <conio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

/**
* @file Tools.h
* @author Adrian Paez
* @version 2.0
*/

using namespace std;

class Tools
{
private:
public:
	/**
	* @brief compare 2 strings
	* @param string, string
	* @return int
	*/
	int compare(string a, string b);

	/**
	* @brief validate int data
	* @param const char*
	* @return int
	*/
	int validate_int(const char*);

	/**
	* @brief validate long data
	* @param const char*
	* @return long
	*/
	long validate_long(const char*);

	/**
	* @brief validate string data
	* @param const char*
	* @return string
	*/
	string validate_string(const char*);

	/**
	* @brief validate string of numbers data
	* @param const char*
	* @return string
	*/
	string validate_string_of_numbers(const char*);

	/**
	* @brief validate ecuadorian id number
	* @param string
	* @return bool
	*/
	bool validate_id(string);

	/**
	* @brief go to xy coordinates in console
	* @param int, int
	* @return void
	*/
	void gotoxy(int, int);

	/**
	* @brief detect if a given key is pressed
	* @param int
	* @return int
	*/
	int keyPressed(int);

	/**
	* @brief get position of console cursor in screen points
	* @param
	* @return COORD
	*/
	COORD GetConsoleCursorPosition();

	/**
	* @brief get click of mouse
	* @param
	* @return COORD
	*/
	COORD GetMouseClick();
};

int Tools::compare(string a, string b)
{
	const char* word1 = a.c_str();
	const char* word2 = b.c_str();
	int result = strcmp(word1, word2);
	return result;
}

int Tools::validate_int(const char* msg)
{
	int value;
	char data[5];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	data[i] = '\0';
	value = atoi(data);
	return value;
}

long Tools::validate_long(const char* msg)
{
	long value;
	char data[10];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	data[i] = '\0';
	value = atol(data);
	return value;
}

string Tools::validate_string(const char* msg)
{
	string value;
	char data[30];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= 'A' && c <= 'Z') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	cout << endl;
	data[i] = '\0';
	value.assign(data, i);
	return value;
}

string Tools::validate_string_of_numbers(const char* msg)
{
	string value;
	char data[11];
	char c;
	int i = 0;
	printf("%s", msg);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			data[i++] = c;
		}
	}
	cout << endl;
	data[i] = '\0';
	value.assign(data, i);
	return value;
}

bool Tools::validate_id(string _id)
{
	if (_id.length() != 10)
	{
		return true;
	}

	int temp;
	int sum_par = 0;
	int sum_impar = 0;
	int sum;

	int i = 1;
	std::string digits = _id.substr(0, _id.size() - 1);
	for (char& c : digits)
	{
		int digit = c - '0';
		if (i % 2 == 0) {
			sum_par += digit;
		}
		else {
			if ((digit * 2) > 9)
			{
				sum_impar += (digit * 2) - 9;
			}
			else
			{
				sum_impar += (digit * 2);
			}
		}
		i++;
	}

	sum = sum_par + sum_impar;
	int verifier = _id.at(_id.size() - 1) - '0';
	int higher = (10 - (sum % 10)) + sum;
	if (sum % 10 == 0)
	{
		return verifier != 0;
	}
	if ((higher - sum) == verifier) {
		return false;
	}
	else {
		std::cout << "\nLa cedula ingresada es invalida" << std::endl;
		return true;
	}
}

void Tools::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Tools::keyPressed(int key)
{
	return (GetAsyncKeyState(key) & 0x8000 != 0);
}

COORD Tools::GetConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleCursor;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tmp;
	POINT point;

	if (GetConsoleScreenBufferInfo(hConsoleOutput, &consoleCursor)) {
		tmp.X = consoleCursor.dwCursorPosition.X;
		tmp.Y = consoleCursor.dwCursorPosition.Y;
		point.x = tmp.X;
		point.y = tmp.Y;
		if (ClientToScreen(GetConsoleWindow(), &point) == 1) {
			tmp.X = point.x;
			tmp.Y = point.y;
			return tmp;
		}
		else
		{
			cout << "error" << endl;
			system("pause");
			system("exit");
		}
	}
	else
	{
		COORD invalid = { 0, 0 };
		return invalid;
	}
}

COORD Tools::GetMouseClick()
{
	COORD coor{};
	POINT point;

	if (keyPressed(VK_RBUTTON))
	{
		GetCursorPos(&point);
		//if (ClientToScreen(GetConsoleWindow(), &point) == 1) {
		coor.X = point.x;
		coor.Y = point.y;
		return coor;
		//}

	}
	return coor;
}