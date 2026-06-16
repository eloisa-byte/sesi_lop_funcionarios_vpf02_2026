#include <stdio.h>
#include <windows.h>

#define MAX_LETRAS 100
#define MAX_LINHAS 50

struct Funcionario {
    char nome[50];
    char cargo[30];
    int salario;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int qtdLinhas = 0;
    struct Funcionario funcionarios[MAX_LINHAS];
    
    FILE *arquivo = fopen("funcionarios.csv", "r");
    if (arquivo == NULL) {
        printf("Arquivo não encontrado.\n");
        getchar(); 
        return 1;
    }
    
    char linha[MAX_LETRAS];
    while (fgets(linha, sizeof(linha), arquivo) != NULL && qtdLinhas < MAX_LINHAS) {
        
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '\n') {
                linha[i] = '\0';
                break;
            }
        }
        
        qtdLinhas++;
        
        if (qtdLinhas > 1) {
        
            sscanf(linha, "%49[^,],%29[^,],%d",
                funcionarios[qtdLinhas - 2].nome,
                funcionarios[qtdLinhas - 2].cargo,
                &funcionarios[qtdLinhas - 2].salario
            );
        }
    }
    
    fclose(arquivo);
    
    double media = 0;
    printf("Nome\tCargo\tSalario\n");
    
    for (int i = 0; i < qtdLinhas - 1; i++) {

        printf("%s\t%s\t%d\n", funcionarios[i].nome, funcionarios[i].cargo, funcionarios[i].salario);
        media += funcionarios[i].salario;
    }
    
    if (qtdLinhas > 1) {
        media = media / (double)(qtdLinhas - 1);
    }
    
    printf("\nForam analisados %d funcionarios\n", qtdLinhas - 1);
    printf("A média salarial dos funcionarios da empresa é %.1f reais\n", media);
    
    getchar();
    return 0;
}