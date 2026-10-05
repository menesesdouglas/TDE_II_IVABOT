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

/*
    Apresenta ao usuário o menu principal da IvaBot,
    contendo as opções disponíveis de atendimento
    e a opção de encerramento.
*/
void exibirMenu(void)
{

}


/*
    Obtém do usuário a opção escolhida no menu principal
    e disponibiliza esse valor para o controle do atendimento.
*/
int lerOpcaoMenu(void)
{

}


/*
    Verifica se a opção informada pelo usuário corresponde
    a uma opção existente no menu e determina se a entrada
    pode prosseguir para o fluxo de atendimento.
*/
int validarOpcao(int opcao)
{

}


/*
    Coordena o fluxo de um atendimento individual,
    encaminhando o usuário para a opção selecionada
    e garantindo o encerramento adequado daquele atendimento.
*/
void executarAtendimento(void)
{

}


/*
    Conduz o usuário pelos níveis da árvore de decisão
    da IvaBot até determinar uma recomendação final
    conforme as regras estabelecidas pela equipe.
*/
int executarArvoreDecisao(void)
{
    int recomendacao = 0;


    /* ========================================================
       NÍVEL 1 DA ÁRVORE
       ======================================================== */


    /* ========================================================
       NÍVEL 2 DA ÁRVORE
       ======================================================== */


    /* ========================================================
       NÍVEL 3 DA ÁRVORE
       ======================================================== */


    return recomendacao;
}


/*
    Apresenta ao usuário a recomendação correspondente
    ao resultado obtido na árvore de decisão.
*/
void exibirRecomendacao(int recomendacao)
{

}


/*
    Registra nas estatísticas a recomendação obtida
    durante o atendimento, atualizando o contador
    correspondente ao resultado da árvore de decisão.
*/
void registrarRecomendacao(int recomendacao)
{

}


/*
    Apresenta o relatório final da utilização da IvaBot,
    incluindo o total de atendimentos e a quantidade
    de vezes que cada recomendação foi indicada.
*/
void exibirEstatisticas(void)
{

}

/* ============================================================
   FUNÇÃO PRINCIPAL
   ============================================================ */

int main() {
	/*
        Inicialização do sistema e execução do fluxo
        principal da IvaBot.
    */
	
    return 0;
}