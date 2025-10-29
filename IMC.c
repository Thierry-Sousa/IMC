#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil"); // só pra não bugar os acentos

    float peso, altura, imc;
    float totalImc = 0;    // acumula todos os IMCs
    int qtdPessoas = 0;
    int opcao = 1;

    do {
        printf("\n--- CÁLCULO DE IMC ---\n");
        printf("Peso (kg): ");
        scanf("%f", &peso);

        printf("Altura (m): ");
        scanf("%f", &altura);

        if (altura > 0 && peso > 0) {
            imc = peso / (altura * altura);
            totalImc += imc;
            qtdPessoas++;

            printf("\nIMC calculado: %.2f\n", imc);

            // classificação básica
            if (imc < 18.5) {
                printf("Classificação: Abaixo do peso\n");
            } else if (imc < 25.0) {
                printf("Classificação: Peso normal\n");
            } else if (imc < 30.0) {
                printf("Classificação: Sobrepeso\n");
            } else if (imc < 35.0) {
                printf("Classificação: Obesidade I\n");
            } else if (imc < 40.0) {
                printf("Classificação: Obesidade II\n");
            } else {
                printf("Classificação: Obesidade III (mórbida)\n");
            }

        } else {
            // aqui podia validar de novo com laço, mas por enquanto só aviso
            printf("\nValores inválidos! Peso e altura precisam ser maiores que zero.\n");
        }

        printf("\n--------------------------------------------\n");
        printf("Calcular IMC de outra pessoa? [1] Sim / [0] Não: ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    printf("\n============================================\n");
    printf("             RESULTADO FINAL                \n");
    printf("============================================\n");

    if (qtdPessoas > 0) {
        float media = totalImc / qtdPessoas;
        printf("Pessoas avaliadas: %d\n", qtdPessoas);
        printf("Média dos IMCs: %.2f\n", media);
    } else {
        printf("Nenhum IMC calculado.\n");
    }

    printf("\nFim do programa.\n");
    return 0;
}