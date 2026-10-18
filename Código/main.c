/*
    TDE II - CHATBOT EM C
    Projeto: IvaBot

    Equipe:
        Douglas Meneses Lima Oliveira - Tech Lead e QA
        Cauã Freitas dos Santos       - Desenvolvedor
        Gabriel Maltez Rodrigues      - Desenvolvedor
        Pedro Henrick Messias Gomes   - Desenvolvedor
        Vinicius de Amorim Bueno      - Desenvolvedor
        Vinicius de Moraes Azevedo de Brito - Desenvolvedor

    Conceito: chatbot baseado em REGRAS. Nao usa IA generativa.
    O programa segue uma arvore de decisao fixa, escrita com
    "if/else" e "switch", e responde de forma previsivel.
*/

#include <stdio.h>
#include <string.h>

/* ============================================================
   MODULO: CONTADOR DE ATENDIMENTOS

   Encapsula a variavel `total_atendimentos`. Ninguem fora deste
   bloco deve alterar a variavel diretamente: sempre passa por
   estas funcoes. Assim, se um dia precisarmos salvar o total em
   arquivo ou enviar para um servidor, mudamos SO aqui - o resto
   do programa continua funcionando sem alteracao.

   O `static` faz a variavel existir so neste arquivo, evitando
   conflito se o projeto crescer e ganhar mais arquivos.
   ============================================================ */

static int total_atendimentos = 0;

/* Zera o contador. Chamada uma vez, no inicio do programa. */
void iniciarContadorAtendimentos(void)
{
    total_atendimentos = 0;
}

/* Soma 1 ao total. Chamada quando um atendimento e concluido. */
void registrarAtendimentoConcluido(void)
{
    total_atendimentos++;
}

/* Devolve o valor atual. Usado para montar o relatorio final. */
int obterTotalAtendimentos(void)
{
    return total_atendimentos;
}

/* ============================================================
   CONTADORES DE RECOMENDACAO
   Um contador para cada recomendacao possivel. Tambem `static`
   pelo mesmo motivo: so este arquivo mexe neles.
   ============================================================ */

static int cont_recomendacao1 = 0;  /* Pizza Frango com Catupiry */
static int cont_recomendacao2 = 0;  /* Pizza Calabresa           */
static int cont_recomendacao3 = 0;  /* Pizza Atum                */
static int cont_recomendacao4 = 0;  /* Bebida (qualquer)         */

/* ============================================================
   MENU PRINCIPAL
   Requisito do guia: no minimo 4 opcoes de atendimento + sair.
   A opcao 5 e a saida; as opcoes 1-4 sao servicos oferecidos.
   ============================================================ */

void exibirMenu(void)
{
    printf("\n============== MENU IVABOT ==============\n");
    printf("1 - Fazer pedido\n");
    printf("2 - Falar com atendente\n");
    printf("3 - Fazer uma reclamacao\n");
    printf("4 - Consultar cardapio\n");
    printf("5 - Encerrar atendimento\n");
    printf("=========================================\n");
}

/* ============================================================
   LEITURA SEGURA DE INTEIRO

   `scanf("%d")` tem um problema classico: se o usuario digitar
   uma letra, o scanf falha, NAO consome a letra, e a proxima
   leitura encontra a mesma letra - gerando loop infinito.

   Esta funcao:
     1. Tenta ler um inteiro.
     2. Se falhar, limpa o buffer com getchar() ate o '\n'.
     3. Devolve -1 para sinalizar "valor invalido".

   Como o menu so aceita 1-5, devolver -1 e seguro: vai cair
   na validacao e ser rejeitado.
   ============================================================ */

int lerInteiroSeguro(void)
{
    int valor;

    if (scanf("%d", &valor) != 1)
    {
        while (getchar() != '\n');  /* descarta o lixo do buffer */
        return -1;
    }

    return valor;
}

/* ============================================================
   VALIDACAO
   Aceita apenas 1..5. Qualquer outro valor exibe aviso e o
   programa volta ao menu. O `0` do codigo antigo foi removido
   porque nao existe opcao 0 no menu.
   ============================================================ */

int validarOpcao(int opcao)
{
    if (opcao >= 1 && opcao <= 5)
    {
        return 1;   /* valida   */
    }

    printf("Opcao inexistente. Tente novamente.\n");
    return 0;       /* invalida */
}

/* ============================================================
   ARVORE DE DECISAO

   CONVENCAO DE RETORNO (importante para entender o fluxo):
     -1  -> fluxo cancelado ou erro. NAO conta atendimento.
      0  -> atendimento concluido, mas sem recomendacao
             (ex: consultar cardapio, falar com atendente).
      1..4 -> atendimento concluido COM uma recomendacao.

   A arvore NAO controla o encerramento do programa. Ela apenas
   responde "qual foi o resultado deste atendimento". Quem
   decide continuar ou parar e o `main`. Isso mantem cada
   funcao com uma unica responsabilidade.
   ============================================================ */

int executarArvoreDecisao(int menu)
{
    int pedido, sabor, bebida, resposta;
    char reclamacao[500];

    switch (menu)
    {
        /* ---------------- NIVEL 1: PEDIDO ---------------- */
        case 1:
            printf("\nQual tipo de pedido deseja?\n");
            printf("1 - Pizza\n");
            printf("2 - Bebidas\n");
            printf("3 - Voltar ao menu principal\n");
            printf("Digite uma opcao: ");
            pedido = lerInteiroSeguro();

            /* ------------- NIVEL 2: CATEGORIA ------------- */
            switch (pedido)
            {
                /* -------- Pizza -> NIVEL 3: SABOR -------- */
                case 1:
                    printf("\n======= PIZZAS =======\n");
                    printf("1 - Frango com Catupiry - R$ 69,90\n");
                    printf("2 - Calabresa           - R$ 59,90\n");
                    printf("3 - Atum                - R$ 79,90\n");
                    printf("Escolha o sabor: ");
                    sabor = lerInteiroSeguro();

                    switch (sabor)
                    {
                        case 1:
                            printf("\nVoce escolheu Frango com Catupiry!\n");
                            return 1;   /* recomendacao 1 */
                        case 2:
                            printf("\nVoce escolheu Calabresa!\n");
                            return 2;   /* recomendacao 2 */
                        case 3:
                            printf("\nVoce escolheu Atum!\n");
                            return 3;   /* recomendacao 3 */
                        default:
                            printf("Opcao invalida!\n");
                            return -1;  /* nao conta atendimento */
                    }

                /* -------- Bebida -> NIVEL 3: TIPO -------- */
                case 2:
                    printf("\n======= BEBIDAS =======\n");
                    printf("1 - Coca-Cola 2L - R$ 12,90\n");
                    printf("2 - Fanta 2L     - R$ 10,90\n");
                    printf("Escolha a bebida: ");
                    bebida = lerInteiroSeguro();

                    /* As duas bebidas compartilham a mesma
                       recomendacao (4). Se um dia quiserem
                       separar, basta criar a rec. 5. */
                    if (bebida == 1 || bebida == 2)
                    {
                        printf("\nBebida adicionada ao pedido!\n");
                        return 4;
                    }

                    printf("Opcao invalida!\n");
                    return -1;

                case 3:
                    printf("Voltando ao menu principal...\n");
                    return -1;   /* usuario desistiu do pedido */

                default:
                    printf("Opcao invalida!\n");
                    return -1;
            }

        /* ---------------- ATENDENTE HUMANO ---------------- */
        case 2:
            printf("\nDeseja falar com um atendente humano?\n");
            printf("1 - Sim\n2 - Nao\n");
            resposta = lerInteiroSeguro();

            if (resposta == 1)
            {
                printf("Encaminhando para um atendente humano...\n");
                return 0;   /* conta atendimento, sem recomendacao */
            }
            if (resposta == 2)
            {
                printf("Atendimento humano cancelado.\n");
                return -1;
            }
            printf("Opcao invalida!\n");
            return -1;

        /* ---------------- RECLAMACAO ---------------- */
        case 3:
            printf("\nDeseja fazer uma reclamacao?\n");
            printf("1 - Sim\n2 - Nao\n");
            resposta = lerInteiroSeguro();

            if (resposta == 1)
            {
                /* O getchar() consome o '\n' que sobrou do
                   scanf anterior. Sem isso, o fgets leria uma
                   linha vazia e a reclamacao sairia em branco. */
                getchar();
                printf("Digite sua reclamacao: ");
                fgets(reclamacao, sizeof(reclamacao), stdin);

                /* strcspn encontra a posicao do '\n' e o troca
                   por '\0' - efetivamente removendo a quebra
                   de linha do final da string. */
                reclamacao[strcspn(reclamacao, "\n")] = '\0';

                printf("\nReclamacao registrada: %s\n", reclamacao);
                return 0;
            }
            if (resposta == 2)
            {
                printf("Reclamacao cancelada.\n");
                return -1;
            }
            printf("Opcao invalida!\n");
            return -1;

        /* ---------------- CONSULTAR CARDAPIO ---------------- */
        case 4:
            printf("\n========== CARDAPIO IVABOT ==========\n");
            printf("Pizzas:\n");
            printf("  - Frango com Catupiry - R$ 69,90\n");
            printf("  - Calabresa           - R$ 59,90\n");
            printf("  - Atum                - R$ 79,90\n");
            printf("Bebidas:\n");
            printf("  - Coca-Cola 2L - R$ 12,90\n");
            printf("  - Fanta 2L     - R$ 10,90\n");
            printf("=====================================\n");
            return 0;   /* conta atendimento, sem recomendacao */

        default:
            return -1;
    }
}

/* ============================================================
   EXIBICAO DA RECOMENDACAO
   Esta funcao SO exibe. Nao conta nada. A contagem fica em
   `registrarRecomendacao`, para evitar dupla contagem (bug
   do prototipo antigo, que incrementava dentro do exibir).
   ============================================================ */

void exibirRecomendacao(int recomendacao)
{
    printf("\n>>> RECOMENDACAO IVABOT <<<\n");

    switch (recomendacao)
    {
        case 1: printf("Pizza Frango com Catupiry!\n"); break;
        case 2: printf("Pizza Calabresa!\n");            break;
        case 3: printf("Pizza Atum!\n");                 break;
        case 4: printf("Bebida refrescante (2L)!\n");    break;
        default: printf("Sem recomendacoes.\n");         break;
    }
}

/* ============================================================
   REGISTRO DA RECOMENDACAO
   Incrementa o contador correspondente. Valores 0 e -1 sao
   ignorados (nao representam recomendacao).
   ============================================================ */

void registrarRecomendacao(int recomendacao)
{
    switch (recomendacao)
    {
        case 1: cont_recomendacao1++; break;
        case 2: cont_recomendacao2++; break;
        case 3: cont_recomendacao3++; break;
        case 4: cont_recomendacao4++; break;
    }
}

/* ============================================================
   RELATORIO FINAL
   Requisito do guia: mostrar total de atendimentos e quantas
   vezes cada recomendacao foi indicada.
   ============================================================ */

void exibirEstatisticas(void)
{
    printf("\n========== ESTATISTICAS FINAIS ==========\n");
    printf("Total de atendimentos: %d\n", obterTotalAtendimentos());
    printf("-----------------------------------------\n");
    printf("Recomendacao 1 (Frango com Catupiry): %d\n", cont_recomendacao1);
    printf("Recomendacao 2 (Calabresa):           %d\n", cont_recomendacao2);
    printf("Recomendacao 3 (Atum):                %d\n", cont_recomendacao3);
    printf("Recomendacao 4 (Bebida):              %d\n", cont_recomendacao4);
    printf("=========================================\n");
}

/* ============================================================
   FUNCAO PRINCIPAL

   Responsabilidades do main:
     1. Iniciar o contador.
     2. Rodar o laco do menu ate o usuario pedir para sair.
     3. Chamar a arvore, tratar o retorno e atualizar contadores.
     4. Exibir o relatorio final.

   Nada de arvore, exibicao ou contagem "escondida" no main -
   cada bloco tem um papel unico.
   ============================================================ */

int main(void)
{
    int opcao;
    int recomendacao;
    int programa_encerrado = 0;

    iniciarContadorAtendimentos();

    printf("Bem-vindo ao IvaBot!\n");

    while (!programa_encerrado)
    {
        exibirMenu();
        printf("Digite a opcao desejada: ");
        opcao = lerInteiroSeguro();

        if (!validarOpcao(opcao))
        {
            continue;   /* volta ao menu sem fazer nada */
        }

        /* --- Opcao 5: encerrar (com confirmacao) ---
           Fica no main porque encerrar o programa e uma
           decisao GLOBAL, nao uma etapa da arvore. */
        if (opcao == 5)
        {
            int confirma;
            printf("\nDeseja realmente encerrar o atendimento?\n");
            printf("1 - Sim\n2 - Nao\n");
            confirma = lerInteiroSeguro();

            if (confirma == 1)
            {
                printf("Atendimento encerrado!\n");
                programa_encerrado = 1;
            }
            else
            {
                printf("Encerramento cancelado. Voltando ao menu...\n");
            }
            continue;
        }

        /* --- Opcoes 1..4: percorre a arvore --- */
        recomendacao = executarArvoreDecisao(opcao);

        /* Retorno -1 = cancelado: nao conta atendimento. */
        if (recomendacao < 0)
        {
            continue;
        }

        /* Atendimento concluido: incrementa o total. */
        registrarAtendimentoConcluido();

        /* Se houve recomendacao, exibe e registra. */
        if (recomendacao > 0)
        {
            exibirRecomendacao(recomendacao);
            registrarRecomendacao(recomendacao);
        }
    }

    exibirEstatisticas();
    return 0;
}
