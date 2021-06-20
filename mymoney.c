#include <stdio.h>
#include <stdlib.h>

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

/*================ Funções Tratativas base de dados e arquivos ===============*/

//Função criar bases de dados 
void criar_bases_de_dados(){
    
    FILE *base_dados_conta;
    FILE *base_dados_renda;
    FILE *base_dados_cofrinho;
    int contador = 0;

    //Verificando se a base de dados conta.bin caso não exista cria.
    base_dados_conta = fopen(arquivo_conta,"rb");
    
    if (base_dados_conta == NULL)//validando se a base de dados existe.
    {
        for (contador = 0; contador <= 50; contador++){//Preenchendo a matriz valor_da_conta para no futuro mapear os espaços com registros validos
            dados_contas.valor_da_conta[contador] = 0; 
        }
        base_dados_conta = fopen(arquivo_conta,"wb");
        fwrite(&dados_contas,sizeof(struct contas_a_pagar),1,base_dados_conta);
    }
    fclose(base_dados_conta);
    
    base_dados_renda = fopen(arquivo_renda,"rb");
    if(base_dados_renda == NULL)
    {
        for(contador = 0; contador <= 50; contador++){
            dados_rendas.valor_da_renda[contador] = 0;
        }
        base_dados_renda = fopen(arquivo_renda,"wb");
        fwrite(&dados_rendas,sizeof(struct minhas_rendas),1,base_dados_renda);
    }
    fclose(base_dados_renda);

    base_dados_cofrinho = fopen(arquivo_cofrinho,"rb");
    if(base_dados_cofrinho == NULL)
    {
        for(contador = 0; contador <= 50; contador++){
            dados_cofrinho.valor_do_cofrinho[contador] = 0;
        }
        base_dados_cofrinho = fopen(arquivo_cofrinho,"wb");
        fwrite (&dados_cofrinho,sizeof(struct meu_cofrinho),1,base_dados_cofrinho);
    }
    fclose(base_dados_cofrinho);
}

/*==================== Funções Tratativas contas a pagar ====================*/

//Função listar conta a pagar
void listar_conta(){
    
}

//Função adicionar conta a pagar
void adicionar_conta(char nome_da_conta [50][100], char vencimento_da_conta[50][11], char descricao_da_conta[50][300], float valor_da_conta[50]){
    
}

//Função editar conta a pagar
void editar_conta(char nome_da_conta [50][100], char vencimento_da_conta[50][11], char descricao_da_conta[50][300], float valor_da_conta[50]){
    
}
//Função remover conta a pagar
void remover_conta(int id_conta){
    
}

int main (){
    criar_bases_de_dados();
    return 0;
}