#include "../../Dropbox/GIT/headers/dumper.h"
#include "../../Dropbox/GIT/headers/help.h"


#define TRUE	1
#define FALSE	0

unsigned short int ask_to_user(void){
	unsigned short int flag = FALSE;

	char r;

	do {
		dump_io(stdin);
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

unsigned short int testando(float *b){
	unsigned short int test = FALSE;
	char c;
	
	clear ();
	
	do {
		printf("Adição: + | Subtração: - | Multiplicação: x | Divisão: / \n");
		printf("Digite a operação a ser realizada: ");
		scanf("%c\n", &c);
		if (c == '/' && *b == 0) {
			do {
				printf("O segundo número não pode ser digitado. \n");
				printf("Digite um número diferente de 0: ");
				scanf("%f", b);
			} while (*b == 0);
		}
		else if (c == '+' || c == '-' || c == 'x' || c == '/') {
			clear ();
			test = TRUE;
		}
		else {
			printf("Opção inválida. Digite Novamente.\n");
		}
	} while (test == FALSE);
	
	return test;
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

		//dump_io(stdin);

		//printf("Adição: + | Subtração: - | Multiplição: x | Divisão: / \n");
		//printf("Digite a operação a ser realizada: ");
		//scanf("%c", &c);

		//if (c == '/' && b == 0) {
		//	do {
		//		printf("O segundo número digitado não pode ser divido. \n");
		//		printf("Digite um número diferente de 0: ");	
		//		scanf("%f", &b);
		//	} while (b == 0);
		//}

		if (testando(&b) == TRUE) {
			if (c == '+') {
				printf("O resultado é: %.2f\n", a + b);	
			} else if (c == '-') {
				printf("O resultado é: %.2f\n", a - b);
			} else if (c == 'x') {
				printf("O resultado é: %.2f\n", a * b);
			} else if (c == '/') {
				printf("O resultado é: %.2f\n", a / b);
			}
		}

	} while ( ask_to_user () );

	return 0;
}
