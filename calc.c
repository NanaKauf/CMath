#include "../Headers/dumper.h"
#include "../Headers/help.h"
#include <math.h>


#define TRUE	1
#define FALSE	0

unsigned short int asking_to_repeat(void){
	unsigned short int flag = FALSE;

	char r;

	dump_io (stdin);
	do {
		
		printf("%s Deseja fazer uma nova operação, '%ss%s' para sim, '%sn%s' para não: %s", T_GREEN, T_RED, T_GREEN, T_RED, T_GREEN, NOTHING);
		scanf("%c", &r);

		if (r == 's') {
			clear ();
			flag = TRUE;
		} else if (r == 'n') {
			printf("%s Bye! %s\n", T_BLUE, NOTHING);
			return flag;
		}else {
			printf("%s Opção inválida. Digite Novamente. %s\n", T_RED, NOTHING);
		}
	} while (flag == FALSE);

	return flag;

}

unsigned short int operator_test(char * c, float *b){
	unsigned short int flag = FALSE;
	
	dump_io(stdin);
	do {

		printf("%s Adição: + | Subtração: - | Multiplicação: * | Divisão: / %s\n", T_PURPLE, NOTHING);
		printf("%s Digite a operação a ser realizada: %s", T_GREEN, NOTHING);
		scanf("%c", c);
		if (*c == '/' && *b == 0) {
			do {
				printf("%s O segundo número não pode ser dividido. %s\n", T_RED, NOTHING);
				printf("%s Digite um número diferente de 0: %s", T_RED, NOTHING);
				scanf("%f", b);
			
			} while (*b == 0);
			flag = TRUE;
		}
		else if (*c == '+' || *c == '-' || *c == '*' || *c == '/') {
			flag = TRUE;
		}
		else {
			clear ();
			printf("%s Opção inválida. Digite Novamente. %s\n", T_RED, NOTHING);
		}
	} while (flag == FALSE);
	
	return flag;
}

int main(){

	float a;
	float b;
	float e;
	float f;

	int g;
	int d;

	char c;
	char r;

	clear ();

	do {
		printf("%s Opções comuns de operação digite '%s1%s', operadores não covencionais digite '%s2%s': %s", T_CYAN, T_RED, T_CYAN, T_RED, T_CYAN, NOTHING);
		scanf("%d", &g);

		clear ();

		if (g == 1) {
			printf("%s Digite o primeiro número: %s", T_GREEN, NOTHING);
			scanf("%f", &a);

			printf("%s Digite o segundo número: %s", T_GREEN, NOTHING);
			scanf("%f", &b);

			if (operator_test(&c, &b) == TRUE) {
				if (c == '+') {
					printf("%s O resultado é: %s %.2f %s\n", T_CYAN, T_RED, a + b, NOTHING);
				} else if (c == '-') {
					printf("%s O resultado é: %s %.2f %s\n", T_CYAN, T_RED, a - b, NOTHING);
				} else if (c == '*') {
					printf("%s O resultado é: %s %.2f %s\n", T_CYAN, T_RED, a * b, NOTHING);
				} else if (c == '/') {
					printf("%s O resultado é: %s %.2f %s\n", T_CYAN, T_RED, a / b, NOTHING);
				}
			}
		} else if (g == 2) {
			printf("%s Exponencial: 1 |Raiz Quadrada: 2 |Logaritimo: 3 |Logaritimo 10: 4 |Resto da Divisão: 5 %s \n", T_PURPLE, NOTHING);
			printf("%s Digite a operação a ser realizada: %s", T_GREEN, NOTHING);
			scanf("%d", &d);

			clear ();

			if (d == 1) {
				printf("%s Digite a base: %s", T_GREEN, NOTHING);
				scanf("%f", &e);

				printf("%s Digite o expoente: %s", T_GREEN, NOTHING);
				scanf("%f", &f);
				
				printf("%s O resultado é:%s %.2f %s\n", T_CYAN, T_RED, pow(e,f), NOTHING);
			} else if (d == 2) {
				printf("%s Digite o número: %s", T_GREEN, NOTHING);
				scanf("%f", &e);

				printf("O resultado é: %.2f \n", T_CYAN, T_RED, sqrt(e), NOTHING);
			} else if (d == 3) {
				printf("%s Digite um número: %s", T_GREEN, NOTHING);
				scanf("%f", &e);
			}
			
		}

	} while ( asking_to_repeat () );

	return 0;
}
