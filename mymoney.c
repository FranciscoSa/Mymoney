#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*=============================== Área De globais ===========================*/

#define arquivo_conta "conta.bin"
#define arquivo_renda "renda.bin"
#define arquivo_cofrinho "cofrinho.bin"

/*============================ Área para structs ============================*/

//Struct modelo de contas a pagar
struct contas_a_pagar
{
    char nome_da_conta[50][100], vencimento_da_conta[50][11], descricao_da_conta[50][300];
    float valor_da_conta[50];
};
struct contas_a_pagar dados_contas;

//Struct modelo de rendas
struct minhas_rendas
{
    char nome_da_renda[50][100], data_da_adicao_da_renda[50][11], descricao_da_renda [50][300];
    float valor_da_renda[50];
};
struct minhas_rendas dados_rendas;

//Struct modelo cofrinho
struct meu_cofrinho
{
   char nome_do_cofrinho[50][100], descricao_do_cofrinho[50][300];
   float valor_do_cofrinho[50];
};
struct meu_cofrinho dados_cofrinho;

/*================ Prototipos de função ===============*/
void criar_bases_de_dados();
void carregar_dados(char arquivo[50]);
void salvar_dados(char arquivo[50]);
void listar_conta();
void adicionar_conta(char nome_da_conta[100], char vencimento_da_conta[11], char descricao_da_conta[300], float valor_da_conta);
void editar_conta(int id_gravar, char nome_da_conta [100], char vencimento_da_conta[11], char descricao_da_conta[300], float valor_da_conta);
void remover_conta(int id_conta);
void menu_principal();
void menu_contas ();

/*================ Funções Tratativas base de dados e arquivos ===============*/

//Função criar bases de dados 
void criar_bases_de_dados(){

    FILE *base_dados;
    int contador = 0;

    //Verificando se a base de dados conta.bin caso não exista cria.
    base_dados = fopen(arquivo_conta,"rb");
    
    if (base_dados == NULL)//validando se a base de dados existe.
    {
        for (contador = 0; contador <= 50; contador++){//Preenchendo a matriz valor_da_conta para no futuro mapear os espaços com registros validos
            dados_contas.valor_da_conta[contador] = 0; 
        }
        base_dados = fopen(arquivo_conta,"wb");
        fwrite(&dados_contas,sizeof(struct contas_a_pagar),1,base_dados);
    }
    fclose(base_dados);
    
    base_dados = fopen(arquivo_renda,"rb");
    if(base_dados == NULL)
    {
        for(contador = 0; contador <= 50; contador++){
            dados_rendas.valor_da_renda[contador] = 0;
        }
        base_dados = fopen(arquivo_renda,"wb");
        fwrite(&dados_rendas,sizeof(struct minhas_rendas),1,base_dados);
    }
    fclose(base_dados);

    base_dados = fopen(arquivo_cofrinho,"rb");
    if(base_dados == NULL)
    {
        for(contador = 0; contador <= 50; contador++){
            dados_cofrinho.valor_do_cofrinho[contador] = 0;
        }
        base_dados = fopen(arquivo_cofrinho,"wb");
        fwrite (&dados_cofrinho,sizeof(struct meu_cofrinho),1,base_dados);
    }
    fclose(base_dados);
}

//Funcão para carregar dados da base de dados para mémoria ram
void carregar_dados(char arquivo[50])
{
    FILE * base_dados;
    
    if(strcmp(arquivo, arquivo_conta) == 0 )
    {
        base_dados = fopen(arquivo_conta,"rb");
        fread(&dados_contas, sizeof(struct contas_a_pagar), 1, base_dados);
        fclose(base_dados);
    }else if (strcmp(arquivo, arquivo_renda) == 0)
    {
        base_dados = fopen(arquivo_renda,"rb");
        fread(&dados_rendas, sizeof(struct minhas_rendas), 1, base_dados);
        fclose(base_dados);
    }else if(strcmp(arquivo, arquivo_cofrinho) == 0)
    {
        base_dados = fopen(arquivo_cofrinho,"rb");
        fread(&dados_cofrinho, sizeof(struct meu_cofrinho), 1, base_dados);
        fclose(base_dados);
    }
}

//Função salvar alteração na base de dados 
void salvar_dados(char arquivo[50])
{
    FILE * base_dados;
    
    if(strcmp(arquivo, arquivo_conta) == 0 )
    {
        base_dados = fopen(arquivo_conta,"wb");
        fwrite(&dados_contas, sizeof(struct contas_a_pagar), 1, base_dados);
        fclose(base_dados);
    }else if (strcmp(arquivo, arquivo_renda) == 0)
    {
        base_dados = fopen(arquivo_renda,"wb");
        fwrite(&dados_rendas, sizeof(struct minhas_rendas), 1, base_dados);
        fclose(base_dados);
    }else if(strcmp(arquivo, arquivo_cofrinho) == 0)
    {
        base_dados = fopen(arquivo_cofrinho,"wb");
        fwrite(&dados_cofrinho, sizeof(struct meu_cofrinho), 1, base_dados);
        fclose(base_dados);
    }
}

/*==================== Funções Tratativas contas a pagar ====================*/

//Função listar conta a pagar
void listar_conta(){
    int contador = 0;
    printf("\n--------------------------------------------------------------------------\n");
    for (contador = 0; contador <= 50; contador++)
    {
        if (dados_contas.valor_da_conta[contador] != 0)
        {
            printf ("ID Conta: %d\nNome da Conta: %s\nVencimento: %s\nDescrição: %s\nValor: R$ %.2f",contador, dados_contas.nome_da_conta[contador], dados_contas.vencimento_da_conta[contador], dados_contas.descricao_da_conta[contador], dados_contas.valor_da_conta[contador]);
            printf("\n--------------------------------------------------------------------------\n");
        }
    }
}

//Função adicionar conta a pagar
void adicionar_conta(char nome_da_conta[100], char vencimento_da_conta[11], char descricao_da_conta[300], float valor_da_conta)
{
    int contador = 0, id_gravar;
    //Verificando qual espaço na base de dados esta fazio 
    for (contador = 0; contador <= 50; contador++)
    {
        if (dados_contas.valor_da_conta[contador] == 0)
        {
            id_gravar = contador;
            contador = 100;
        }
    }
    strcpy(dados_contas.nome_da_conta[id_gravar], nome_da_conta);
    strcpy(dados_contas.vencimento_da_conta[id_gravar], vencimento_da_conta);
    strcpy(dados_contas.descricao_da_conta[id_gravar], descricao_da_conta);
    dados_contas.valor_da_conta[id_gravar] = valor_da_conta;
    salvar_dados(arquivo_conta);
}

//Função editar conta a pagar
void editar_conta(int id_gravar, char nome_da_conta [100], char vencimento_da_conta[11], char descricao_da_conta[300], float valor_da_conta){
    strcpy(dados_contas.nome_da_conta[id_gravar], nome_da_conta);
    strcpy(dados_contas.vencimento_da_conta[id_gravar], vencimento_da_conta);
    strcpy(dados_contas.descricao_da_conta[id_gravar], descricao_da_conta);
    dados_contas.valor_da_conta[id_gravar] = valor_da_conta;
    salvar_dados(arquivo_conta);
}
//Função remover conta a pagar
void remover_conta(int id_conta){
    dados_contas.valor_da_conta[id_conta] = 0;
    salvar_dados(arquivo_conta);
}
/*==================== Funções dos Menus ====================*/

//função menu principal (recursiva)
void menu_principal(){

    carregar_dados(arquivo_conta);
    carregar_dados(arquivo_renda);
    carregar_dados(arquivo_cofrinho);
    
    int controle_menu_principal = 0 ;    
    
    printf ("\n[ [1] - Contas a Pagar ] ");
    printf ("[ [2] - Minha carteira ] ");
    printf ("[ [3] - Meus Cofrinhos ] ");
    printf ("[ [0] - Fechar programa ] \n");
    scanf("%d",&controle_menu_principal);
    switch (controle_menu_principal)
    {
        case 0 :
            printf("Finalizando programa ...");
            break;
        case 1 :
            menu_contas();
            break;
        case 2 :
            break;
        case 3 :
            break;
        default:
            printf("\nOpção invalida !! \n");
            break;
        }
    if (controle_menu_principal != 0 )
    {
        menu_principal();
    }
}

void menu_contas ()
{

}
/*==================== void test ====================*/

int main (){
    menu_principal();
    return 0;
}