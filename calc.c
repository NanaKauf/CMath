/*
 * calc.c
 * 
 * Copyright 2013 Janaina Flor Kaufmann <janaina@medusakauf>
 * 
 * This program is free software; you can redistribute it and/or modify
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
	
	dump_io(stdin);
	
	printf("Adição: + | Subtração: - | Multiplição: x | Divisão: / \n");
	printf("Digite a operação a ser realizada: ");
	scanf("%c", &c);
	
	if (c == '/' && b == 0) {
		do {
			printf("O segundo número digitado não pode ser divido. \n");
			printf("Digite um número diferente de 0: ");
			scanf("%f", &b);
		} while (b == 0);
	}
	
	
	if (c == '+') {
		printf("O resultado é: %.2f\n", a + b);
	}
	else if (c == '-') {
		printf("O resultado é: %.2f\n", a - b);
	}
	else if (c == 'x') {
		printf("O resultado é: %.2f\n", a * b);
	}
	else if (c == '/') {
		printf("O resultado é: %.2f\n", a / b);
	}
	
	do {
		dump_io(stdin);
		printf("Deseja fazer uma nova operação, 's' para sim, 'n' para não: ");
		scanf("%c", &r);
	
		if (r != 's' && r !='n') {
			printf("Opção inválida. Digite Novamente.\n");
		}
	} while (r != 's' && r !='n');
} while (r == 's');
	printf("Bye\n");
	return 0;
}
