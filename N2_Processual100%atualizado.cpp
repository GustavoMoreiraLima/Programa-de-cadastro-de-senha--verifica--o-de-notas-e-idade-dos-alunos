#include <stdio.h>

//Declarando fun��es
void cadastrarSenhas(int vetor[10]);

void mostrarVetor(int vetor[10]);

int validarSenha(int vetor[10]);

void calcMedia();

void verificarIdade();

//Codigo Principal
int main() {
    int senhas[10];
    printf("----------PROGRAMA DE CADASTRO DE SENHAS, VERIFICACAO DE NOTAS E IDADES DOS ALUNOS----------\n");
    cadastrarSenhas(senhas); //Puxando a fun��o p/ cadastrar senha

    if (validarSenha(senhas)) { //Puxando a fun��o p/ validar a senha
        printf("\nBem Vindo ao Sistema.");
        //Mostrando o Menu
        int opcao = 0;
        do {
            printf("\nSelecione uma opcao:"	
		           "\n-----MENU-----"				
                   "\n1 - Calcular media de alunos"
                   "\n2 - Verificar idade de alunos"
                   "\n3 - Sair"
                   "\nDigite: ");
            scanf("%d", &opcao);
            if (opcao == 1) {
                calcMedia(); //Puxando a fun��o p/ calcular media
            } else if (opcao == 2) {
                verificarIdade(); //Puxando a fun��o p/ verificar nome e idade
            }
            //Saindo do sistema
        } while (opcao != 3); 
    }
    printf("Obrigado por usar nosso sistema");
}

//Fun��es
void cadastrarSenhas(int vetor[10]) {
    printf("Cadastre 10 senhas de acesso (ate 3 numeros inteiros):\n");
	//Cadastrando as senhas e verificando se possua as credenciais corretas
    for (int i = 0; i < 10; i++) {
        int valid = 0;
        int senha;
        do {
            printf("\nSenha %d: ", i + 1);
            scanf("%d", &senha);
            if (senha < 0 || senha > 999) {
                printf("\nCredenciais invalidas, tente novamente.");
            } else {
                valid = 1;
            }
        } while (valid == 0);

        vetor[i] = senha;
    }
}

void mostrarVetor(int vetor[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%d", vetor[i]);
    }
}

int validarSenha(int vetor[10]) {
	//Validando senha
    int valid = 0;
    do {
        int _senha;
        printf("\nDigite sua senha: ");
        scanf("%d", &_senha);
        for (int i = 0; i < 10; i++) {
            if (vetor[i] == _senha) {
                valid = 1;
                break;
            }
        }

        if (valid == 1) {
            printf("Senha correta");
        } else {
            printf("Senha incorreta");
        }

    } while (valid == 0);

    return 1;
}

void calcMedia() {
	//Calculando a media das notas cadastradas
	int qtd_notas;
    float nota;
    float soma = 0.0;
    float media;
    printf("Digite quantas notas deseja cadastrar: ");
    scanf("%d", &qtd_notas);
    for(int i = 1; i <= qtd_notas; i++){	//o codigo se repetir� at� a vari�vel "i" ser maior que a "qtd_notas"	
        printf("\nCadastre a nota %d: ", i);
        scanf("%f", &nota);
        soma = soma + nota;
	  }
	media = soma / qtd_notas;
	printf("\nForam cadastradas %d notas.", qtd_notas);
	printf("\nA soma das notas e: %.2f", soma);
	printf("\nA media e: %.2f", media);
}

void verificarIdade(){
	//Verificando a idade do aluno
	int qtd_alunos;
    printf("Quantos alunos deseja verificar ? ");
    scanf("%d", &qtd_alunos);
    for (int j = 1; j <= qtd_alunos; j++) {		//o codigo se repetir� at� a vari�vel "j" ser maior que a "qtd_alunos"	
        char aluno[50];
        int idade;
        printf("\nDigite o nome e a idade do aluno %d: ", j);
        scanf("%s %d", &aluno, &idade);
        if (idade >= 18){	//Verificando se � maior de idade e mostrando ao usu�rio
        	printf("\nO Aluno %s, tem %d anos. Portanto e maior de idade.", aluno, idade);
		} else {
			printf("\nO Aluno %s, tem %d anos. Portanto e menor de idade.", aluno, idade);
		}
	}
}
