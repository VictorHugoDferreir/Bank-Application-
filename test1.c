#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int entrada(int menu);  //menu principal do programa
int condicao(int *codigo, double *saldo, int conta, int menu, int verifica, double valor, double ativo); //entradas do menu
int Deposito(double *saldo, int *codigo, int conta, double valor, int verifica);    //realiza o deposito
int Saque(double *saldo, int *codigo, int conta, double valor, int verifica);   //realiza o saque
int Ativo(double *saldo, double ativo, int verifica);       //calcula o ativo bancario 
int EncerraPrograma(int verifica);      //encerra o programa 

typedef struct{
    
    int codigo;
    double saldo;

}Dados;

int main()
{
    int i, j, conta;
    double valor, ativo = 0;     //variaveis 
    int verifica = 0;
    int menu;
    
    Dados *contas;

    contas = calloc(100, sizeof(int));

    while(verifica != 2)
    {
        printf("\n\tENTRADA\n"
                "\n1 - Informar os dados da conta\n"
                "2 - Prosseguir\n");
        scanf("\n%d", &verifica);
        
    
            for(j = 0; j < 10; j++)
            {
                if(j == i)      //se estiverem no mesmo indice, sera o mesmo valor
                {
                    continue;
                }
                    if(codigo[i] == codigo[j])  //para nao admitir contas repetidas
                    {
                        printf("\n\t**Nao repita o codigo**\n"); 
                        i -= 1;
                        break;
                    }
            }
    }
    
    while(verifica != 3)    //parametro para rodar o programa e sair do mesmo
    {
        verifica = condicao(codigo, saldo, conta, menu, verifica, valor, ativo);
    }
    
    return 0;
}
int entrada(int menu)
{
    do{
        printf( "\n\t\tMENU\n\n"
                "\n1 - Efetuar Deposito"
                "\n2 - Efetuar Saque"
                "\n3 - Consultar o ativo bancario"
                "\n4 - Finalizar o programa\n\n");
        scanf("\n%d", &menu);
        fflush(stdin);
    }while(menu < 1 || menu > 4);
    
    return menu;
}
int condicao(int *codigo, double *saldo, int conta, int menu, int verifica, double valor, double ativo)
{
    int i = 0;
    
    switch(entrada(menu))
    {
        case 1:
        
        verifica = Deposito(saldo, codigo, conta, valor, verifica);
            
        break;
        
        case 2:
        
        verifica = Saque(saldo, codigo, conta, valor, verifica);
        
        break;
        
        case 3:
        
        verifica = Ativo(saldo, ativo, verifica);
            
        break;
        
        case 4:
        
        verifica = EncerraPrograma(verifica);
        
        break;
    }
    
    return verifica;
}
int Deposito(double *saldo, int *codigo, int conta, double valor, int verifica)
{
    int i; 
    
    printf("\n\tDigite o codigo da conta (3 digitos)\n");
    scanf("\n%d", &conta);
        
        for(i = 0; i < 10; i++)
        {
            if(conta == codigo[i])      //se a conta estiver no programa, realiza o calculo
            {   
                printf("\nConta %d\tSaldo: RS %.2lf\n", conta, saldo[i]);
                printf("\n\tDigite o valor de deposito\n");
                scanf("\n%lf", &valor);
                    
                saldo[i] += valor;
                        
                printf("\n\tSaldo atualizado\n\n"
                       "\nConta %d\tSaldo: RS %.2lf\n", conta, saldo[i]);
                verifica = 2;
                               
                i = -1;
                break;
            }
        }
            if(verifica != 2)   //se nao estiver, volta para o menu
            {
                printf("\n\t**CONTA NAO ENCONTRADA**\n\n");
                    
            }
    
    return 2;
}
int Saque(double *saldo, int *codigo, int conta, double valor, int verifica)
{   
    int i;
    
    printf("\n\tDigite o codigo da conta (3 digitos)\n");
    scanf("\n%d", &conta);
        
        for(i = 0; i < 10; i++)
        {
            if(conta == codigo[i])  //se a conta estiver cadastrada, o calculo é realizado
            {   
                verifica = 3;
                    
                printf("\nConta %d\tSaldo: RS %.2lf\n", conta, saldo[i]);
                printf("\n\tDigite o valor de saque\n");
                scanf("\n%lf", &valor);
                                   
                if(valor <= saldo[i])   //se o valor do saque nao estourar o valor em caixa, realiza o calculo
                {
                    saldo[i] -= valor;
                        
                        printf("\n\tSaldo atualizado\n\n"
                               "\nConta %d\tSaldo: RS %.2lf\n", conta, saldo[i]);
                               
                    i = -1;
                    break;
                }
                    else    //se for maior, retorna ao menu
                    {
                        printf("\n\t**SALDO INSUFICIENTE**\n");
                    }
            }
        }
                if(verifica != 3)
                {
                    printf("\n\t**CONTA NAO CADASTRADA**\n\n");
                    
                }
                
    return 3;
}
int Ativo(double *saldo, double ativo, int verifica)
{
    int i;
    
    for(i = 0; i < 10; i++) //calculo dos ativos 
    {
        ativo += saldo[i];
    }
        printf("\n\t**ATIVO BANCARIO**\n"
               "\n\nRS %.2lf", ativo);
        
    return 4;
}
int EncerraPrograma(int verifica)
{
    printf("\n\t**PROGRAMA ENCERRADO**\n\n");
    
    return 1;
}

