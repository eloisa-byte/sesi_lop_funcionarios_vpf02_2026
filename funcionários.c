#include <stdio.h>
#include <windows.h>

struct Funcionario{
	char nome[50];
	char cargo[30];
	int salario;
};

int main(){
	SetConsoleOutputCP(CP_UTF8);
	struct Funcionario funcionarios[5] = {
		{"Ana Silva", "Gerente", 5000},
		{"Carlos Oliveira", "Analista", 3000},
		{"Maria Santos", "Assistente", 2000},
		{"Pedro Costa", "Supervisor", 4000},
		{"João Lima", "Diretor", 8000},
		
		};
	FILE *arquivo = fopen("funcionarios.csv","w");
	if(arquivo == NULL){
		printf("Erro ao gravar arquivo\n");
		return 0;
	}
	
	fprintf(arquivo,"Nome,Cargo,Salário\n");
	
	for(int i = 0; i < 5; i++)
		fprintf(arquivo,"%s, %s, %d\n",funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
	fclose(arquivo);
	printf("Arquivo criado com sucesso.");
	getch();
}
		