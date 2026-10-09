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
    printf("\n============== MENU IVABOT ==============\n");
    printf("1 - Fazer pedido\n");
    printf("2 - Falar com atendente\n");
    printf("3 - Fazer uma reclamacao\n");
    printf("4 - Consultar informacoes do delivery\n");
    printf("5 - Encerrar atendimento\n");
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

}

/* Controla o fluxo de um atendimento conforme a opção escolhida. */
void executarAtendimento(void)
{

}

/* Percorre a árvore de decisão até obter uma recomendação. */
int executarArvoreDecisao(void)
{
    int recomendacao = 0;

    /* NÍVEL 1 DA ÁRVORE */

    /* NÍVEL 2 DA ÁRVORE */

    /* NÍVEL 3 DA ÁRVORE */

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
