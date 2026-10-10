/*
    TDE II - CHATBOT EM C

    IVABOT

    Equipe:

        Douglas Meneses Lima Oliveira - Tech lead e QA

        Cauã Freitas dos Santos - Desenvolvedor

        Gabriel Maltez Rodrigues - Desenvolvedor

        Pedro Henrick Messias Gomes - Desenvolvedor

        Vinicius de Amorim Bueno - Desenvolvedor

        Vinicius de Moraes Azevedo de Brito - Desenvolvedor
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>


/* ============================================================
   VARIÁVEIS DE CONTROLE
   ============================================================ */

int opcao_menu;
int programa_encerrado;


/* ============================================================
   VARIÁVEIS DA ÁRVORE DE DECISÃO
   ============================================================ */

int categoria;
int subcategoria;
int preferencia;


/* ============================================================
   ESTATÍSTICAS
   ============================================================ */

int total_atendimentos;

int cont_recomendacao1;
int cont_recomendacao2;
int cont_recomendacao3;
int cont_recomendacao4;

/* ============================================================
   IMPLEMENTAÇÃO DAS FUNÇÕES
   ============================================================ */

/* Apresenta o menu principal da IvaBot. */
void exibirMenu(void)
{
    printf("\n============== MENU IVABOT ==============\n");
    printf("1 - Fazer pedido\n");
    printf("2 - Falar com atendente\n");
    printf("3 - Fazer uma reclamacao\n");
    printf("4 - Encerrar atendimento\n");
    printf("=========================================\n");
}

/* Lê e retorna a opção escolhida pelo usuário. */
int lerOpcaoMenu(void)
{
    int opcao;
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    return opcao;
}

/* Verifica se a opção informada é válida. */
int validarOpcao(int opcao)
{
    if (opcao == 0 || opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
    {
        return 1;
    }

    printf("Opcao inexistente. Tente novamente.\n");

    return 0;
}

/* Percorre a árvore de decisão até obter uma recomendação. */

int executarArvoreDecisao(int menu)
{
    int recomendacao = 0;
    int pedido, opcao1 = 0, opcao2 = 0, opcao3 = 0;
    int bebida, sabor, programa_encerrado = 0;
    char reclamacao[500];

    /* ========================================================
       NÍVEL 1 DA ÁRVORE
    ======================================================== */
    switch (menu)
    {
        case 1:
            printf("\nQual tipo de pedido deseja?\n");
            printf("1 - Pizza\n");
            printf("2 - Bebidas\n");
            printf("3 - Voltar ao menu principal\n");
            printf("Digite uma opcao: ");
            scanf("%d", &pedido);

            /* ========================================================
               NÍVEL 2 DA ÁRVORE
            ======================================================== */
            switch (pedido)
            {
                case 1:
                    printf("\n======= PIZZAS =======\n");
                    printf("1 - Frango com Catupiry - R$ 69,90\n");
                    printf("2 - Calabresa - R$ 59,90\n");
                    printf("3 - Atum - R$ 79,90\n");
                    printf("Escolha o sabor: ");
                    scanf("%d", &sabor);

                    switch (sabor)
                    {
                        case 1:
                        	printf("\nVocê escolheu o sabor Frango com Catupiry\n");
                        	break;
                        case 2:
                        	printf("\nVocê escolheu o sabor Calabresa\n");
                        	break;
                        case 3:
                            printf("\nVocê escolheu o sabor Atum\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                    break;

                case 2:
                    printf("\n======= BEBIDAS =======\n");
                    printf("1 - Coca-Cola 2L - R$ 12,90\n");
                    printf("2 - Fanta 2L - R$ 10,90\n");
                    printf("Escolha a bebida: ");
                    scanf("%d", &bebida);

                    switch (bebida)
                    {
                        case 1:
                            printf("\nBebida adicionada ao pedido!\n");
                            break;
                        case 2:
                            printf("\nBebida adicionada ao pedido!\n");
                            break;

                        default:
                            printf("Opcao invalida!\n");
                            break;
                    }
                    break;

                case 3:
                    printf("Voltando ao menu principal!\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            break;

        case 2:
            printf("\nDeseja falar com um atendente humano?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao1);

            switch (opcao1)
            {
                case 1:
                    printf("Encaminhando para um atendente humano.\n");
                    break;

                case 2:
                    printf("Atendimento humano cancelado.\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            break;

        case 3:
            printf("\nDeseja fazer uma reclamacao?\n");
            printf("1 - Sim\n2 - Não\n");
            scanf("%d", &opcao2);

            switch (opcao2)
            {
                case 1:
                    getchar();
                    printf("Digite sua reclamacao: ");
                    fgets(reclamacao, sizeof(reclamacao), stdin);
                    reclamacao[strcspn(reclamacao, "\n")] = '\0';
                    printf("\nReclamacao registrada: %s\n", reclamacao);
                    break;

                case 2:
                    printf("Reclamacao cancelada.\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            break;

        case 4:
            printf("\nDeseja realmente encerrar o atendimento?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao3);

            switch (opcao3)
            {
                case 1:
                    printf("Atendimento encerrado!\n");
                    programa_encerrado = 1;
                    break;

                case 2:
                    printf("Atendimento mantido.\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }
    return programa_encerrado;

    /* ========================================================
       NÍVEL 3 DA ÁRVORE
    ======================================================== */
    return recomendacao;
}


/* Exibe a recomendação obtida pela árvore de decisão. */
void exibirRecomendacao(int recomendacao)
{
    switch (recomendacao) {
    
        case 1 :
        	printf("Recomendação 1\n");
        	break;
        	
        case 2 :
        	printf("Recomendação 2\n");
        	break;
        	
        case 3 :
        	printf("Recomendação 3\n");
        	break;
        	
        default:
        	printf("Sem recomendações\n");
        	break;
        }

}

/* Atualiza o contador da recomendação obtida. */
void registrarRecomendacao(int recomendacao)
{

}

/* Exibe as estatísticas finais do chatbot. */
void exibirEstatisticas(void)
{

}

/* ============================================================
   FUNÇÃO PRINCIPAL
   ============================================================ */

int main() {

    programa_encerrado = 0;

    while (!programa_encerrado) {
        exibirMenu();
        opcao_menu = lerOpcaoMenu();

        if (validarOpcao(opcao_menu)) {
            programa_encerrado = executarArvoreDecisao(opcao_menu);
        }
    }
    
    //exibirEstatisticas();
    return 0;
}
