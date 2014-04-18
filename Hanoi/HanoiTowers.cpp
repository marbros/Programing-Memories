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

int iterativo(int n){ 
	iniciar(cantidadTorres);
	int x, i ,j , fr,to,paracom,numMenos1,opAnd,opOr,itera;
	int numero3=3;
	int numero2=2;
	int numDisc = n;
	int op1=1;
	__asm {
		mov x,1
		mov paracom,1
		mov itera,0
forncuad:
		mov eax,itera
		cmp eax,n
		jge finforncuad
		mov eax,paracom
		mul numero2
		mov paracom,eax
		inc itera
		jmp forncuad
finforncuad:
		mov eax,paracom
		mov paracom,eax
		dec paracom
	}
		//escribirNum(paracom);
	__asm{
		inc paracom
		ciclo:
		mov eax,x
		cmp eax,paracom
		jge fin
		mov eax,x
		dec eax
		mov numMenos1,eax
		mov eax,x
		and eax,numMenos1
		mov opAnd,eax
		mov edx,0
		div numero3
		mov fr,edx
		mov eax,x
		dec eax
		mov numMenos1,eax
		mov eax,x
		or eax,numMenos1
		inc eax
		mov opOr,eax
		mov edx,0
		div numero3
		mov to,edx
		mov eax,numDisc
		nop
		mov edx,0
		div numero2
		cmp edx,0
		je esPar
		jg noEsPar
		esPar:	
		mov eax,fr
		cmp eax,1
		jg fr2
		je fr1
		jl outFr
		fr2:	
		mov fr,1
		jmp outFr
		fr1:	
		mov fr,2
		outFr:	
		mov eax,to
		cmp eax,1
		jg to2
		je to1
		jl outto
		to2:	
		mov to,1
		jmp outto
		to1:	
		mov to,2
		outto:	
		nop
		noEsPar:
		inc x
	}
	mover(fr+1,to+1);
	_asm{
		jmp ciclo
fin:	
		nop
	}
}

void recursivo(int n, int from, int to, int via){
	int nMenos1;
	int cero=0;
	__asm{
		mov eax,n
		cmp eax,cero
		jle termino
		mov eax,to
		push eax
		mov eax,via
		push eax
		mov eax,from
		push eax
		mov eax,n
		dec eax
		push eax
		call recursivo
		pop edx
		pop edx
		pop edx
		pop edx
	}
		mover(from,to);
	__asm{
		mov eax,from
		push eax
		mov eax,to
		push eax
		mov eax,via
		push eax
		mov eax,n
		dec eax		
		push eax
		call recursivo
		pop edx
		pop edx
		pop edx
		pop edx
termino:
		nop
	}
}

int beginParam() {
	int paracom,itera,numero2;
	printf( "Ingrese la Cantidad de discos   " );
	scanf( "%d", &cantidadTorres );
	printf("\n");
	getchar();
	//Recursivo
	__asm{
		mov paracom,1
		mov itera,0
		mov numero2,2
forncuad:
		mov eax,itera
		cmp eax,cantidadTorres
		jge finforncuad
		mov eax,paracom
		mul numero2
		mov paracom,eax
		inc itera
		jmp forncuad
finforncuad:
		mov eax,paracom
		mov paracom,eax
		dec paracom
	}
	escribirNum(paracom);
	iniciar(cantidadTorres);
	
	return cantidadTorres;
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
