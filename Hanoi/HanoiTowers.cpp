#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
using namespace System;

int puzzle;
int res = 1;

int cantidadTorres;

std::vector<int> a;
std::vector<int> b;
std::vector<int> c;

void iniciar(int n){
	a.clear();
	b.clear();
	c.clear();
	for(int i=n;i>0;i--){
		a.push_back(i);
	}
}

void hanoi(int puzzle, char from, char help, char into) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if(puzzle > 0) {
		hanoi (puzzle - 1, from, into, help);
		// system ("color B" );
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);		
		printf("\t\t | Mueva la Pieza %d De %c a la Torre %c        |\n", puzzle, from, into);
		hanoi(puzzle - 1, help, from, into);
	} 
}

void config() {
	system("cls");
	menu();
}

void action(int option) {
	
	int canTowers = 0;	
	switch (option) {
		case 2:
			canTowers = beginParam();
			recursivo(canTowers,1,3,2);
			config();
		   break;
		case 3:
			canTowers = beginParam();
			iterativo(canTowers);
			config(); 			   		   
		   break;
		case 5:
		   exit(0);		   
		   break;		   	   
		default:
		   cout << "Opcion invalida" << endl;
	}
}

int main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int puzzle;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\t\t --------------------------------------------- \n");
	printf("\t\t               Torres De Hanoi                 \n");
	printf("\t\t --------------------------------------------- \n");
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);		
	printf("\t\t Inserte El numero de piezas que desea :  ");
	SetConsoleTextAttribute(h, FOREGROUND_RED  | FOREGROUND_INTENSITY);
	scanf("%d", &puzzle);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);	
	printf("\t\t --------------------------------------------- \n");
	hanoi(puzzle, 'A', 'B', 'C');
	printf("\t\t --------------------------------------------- \n");
	int res = 1;

	for(int i = 0; i < puzzle; i++)
		res = res * 2;
	printf("\t\t\t      Cantidad De Pasos: %i", res -1);
	getch();	
}
