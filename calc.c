/*
 * calc.c
 * 
 * Copyright 2008 Victor V. Flores <userx.gnu@gmail.com>
 * 
 * CMath program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "headers/dumper.h"
#include "headers/help.h"


#define TRUE	1
#define FALSE	0

unsigned short int asking_to_repeat(void){
	unsigned short int flag = FALSE;

	char r;

	dump_io (stdin);
	do {
		
		printf("Deseja fazer uma nova operação, 's' para sim, 'n' para não: ");
		scanf("%c", &r);

		if (r == 's') {
			clear ();
			flag = TRUE;
		} else if (r == 'n') {
			printf("Bye!\n");
			return flag;
		}else {
			printf("Opção inválida. Digite Novamente.\n");
		}
	} while (flag == FALSE);

	return flag;

}

unsigned short int operator_test(char * c, float *b){
	unsigned short int flag = FALSE;
	
	dump_io(stdin);
	do {

		printf("Adição: + | Subtração: - | Multiplicação: * | Divisão: / \n");
		printf("Digite a operação a ser realizada: ");
		scanf("%c", c);
		printf("\n\t DEBUG- C: %c\n", *c);
		if (*c == '/' && *b == 0) {
			do {
				printf("O segundo número não pode ser dividido. \n");
				printf("Digite um número diferente de 0: ");
				scanf("%f", b);
			
			} while (*b == 0);
			flag = TRUE;
		}
		else if (*c == '+' || *c == '-' || *c == '*' || *c == '/') {
			clear ();
			flag = TRUE;
		}
		else {
			clear ();
			printf("Opção inválida. Digite Novamente.\n");
		}
	} while (flag == FALSE);
	
	return flag;
}

int main(){

	float a;
	float b;

	char c;
	char r;

	clear ();

	do {

		printf("Digite o primeiro número: ");
		scanf("%f", &a);

		printf("Digite o segundo número: ");
		scanf("%f", &b);

		if (operator_test(&c, &b) == TRUE) {
			if (c == '+') {
				printf("O resultado é: %.2f\n", a + b);	
			} else if (c == '-') {
				printf("O resultado é: %.2f\n", a - b);
			} else if (c == '*') {
				printf("O resultado é: %.2f\n", a * b);
			} else if (c == '/') {
				printf("O resultado é: %.2f\n", a / b);
			}
		}

	} while ( asking_to_repeat () );

	return 0;
}

