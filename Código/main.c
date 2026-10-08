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

}

/* Lê e retorna a opção escolhida pelo usuário. */
int lerOpcaoMenu(void)
{

}

/* Verifica se a opção informada é válida. */
int validarOpcao(int opcao)
{

}

/* Controla o fluxo de um atendimento conforme a opção escolhida. */
void executarAtendimento(void)
{

}

/* Percorre a árvore de decisão até obter uma recomendação. */
int executarArvoreDecisao(int escolhaMenu)
{
    int recomendacao = 0;
    int menu, pedido, opcao1 = 0, opcao2 = 0, opcao3 = 0;
    int bebida, sabor;
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


                    if (sabor >= 1 && sabor <= 3)
                    {
                        printf("\nPizza adicionada ao pedido!\n");
                    }
                    else
                    {
                        printf("Opcao invalida!\n");
                    }
                    break;

                case 2:
                    printf("\n======= BEBIDAS =======\n");
                    printf("1 - Coca-Cola 2L - R$ 12,90\n");
                    printf("2 - Fanta 2L - R$ 10,90\n");
                    printf("Escolha a bebida: ");
                    scanf("%d", &bebida);


                    if (bebida >= 1 && bebida <= 2)
                    {
                        printf("\nBebida adicionada ao pedido!\n");
                    }
                    else
                    {
                        printf("Opcao invalida!\n");
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


            if (opcao1 == 1)
            {
                printf("Encaminhando para um atendente humano.\n");
            }
            else if (opcao1 == 2)
            {
                printf("Atendimento humano cancelado.\n");
            }
            else
            {
                printf("Opcao invalida!\n");
            }
            break;

        case 3:
            printf("\nDeseja fazer uma reclamacao?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao2);


            if (opcao2 == 1)
            {
                getchar(); /* Remove o ENTER deixado pelo scanf */


                printf("Digite sua reclamacao: ");
                fgets(reclamacao, sizeof(reclamacao), stdin);


                reclamacao[strcspn(reclamacao, "\n")] = '\0';


                printf("\nReclamacao registrada: %s\n", reclamacao);
            }
            else if (opcao2 == 2)
            {
                printf("Reclamacao cancelada.\n");
            }
            else
            {
                printf("Opcao invalida!\n");
            }
            break;

        case 4:
            printf("\nDeseja realmente encerrar o atendimento?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &opcao3);


            if (opcao3 == 1)
            {
                printf("Atendimento encerrado!\n");
            }
            else if (opcao3 == 2)
            {
                printf("Atendimento mantido.\n");
            }
            else
            {
                printf("Opcao invalida!\n");
            }
            break;

        default:
            printf("Opcao invalida!\n");
            break;
    }


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

    /* Inicialização e controle do programa. */

    return 0;
}
