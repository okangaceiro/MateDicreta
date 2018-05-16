#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int verPrimo=0;
long int primo1, primo2;

long int euclides(long int e, long int mult)
{
    long int aux;

    if(e%mult==0)
    {
        return mult;
    }
    else
    {
        aux = mult;
        mult = e%mult;
        e = aux;
    }
    euclides(e,mult);
}

long int verificarPrimo(long int primo)
{
    int i, j, cont=0;

    verPrimo = 0;

    for(i=1; i<sqrt(primo); i++)
    {
        if(primo % i == 0)
        {
            cont++;
        }

    }

    if(cont==1)
    {
         return verPrimo = 1;
    }
    else
    {
        return verPrimo = 0;
    }

}

long int gerarChavePublica()
{
        long int pri1, pri2, mult = 0, e, euclidizinho=0;

        printf("\nDigite um par de numeros primos P e Q: \n");
        scanf("%ld %ld", &primo1, &primo2);

        pri1 = verificarPrimo(primo1);
        pri2 = verificarPrimo(primo2);

        if(pri1==0 || pri2==0)
        {
            while(pri1==0)
            {
                printf("O numero P nao eh primo, por favor, digite outro valor: \n");
                scanf("%ld", &primo1);

                pri1 = verificarPrimo(primo1);

            }
            while(pri2==0)
            {
                printf("O numero Q nao eh primo, por favor, digite outro valor: \n");
                scanf("%ld", &primo2);

                pri2 = verificarPrimo(primo2);
            }

        }

        printf("Numeros P e Q sao primos!\n");

        printf("P = %ld  Q = %ld\n", primo1, primo2);

        mult = (primo1-1)*(primo2-1);

        printf("Digite um numero E relativamente primo a (p-1)(q-1) = %ld\n", mult);
        scanf("%ld", &e);

        euclidizinho = euclides(e, mult);

        while(euclidizinho!=1)
        {
            printf("Digite um outro valor valido para E: \n");
            scanf("%ld", &e);
            euclidizinho = euclides(e, mult);
        }


}

int main()
{
    int opcao;

    printf("Digite uma das 3 opcoes: \n\n");

    printf("1 - Gerar chave publica\n");
    printf("2 - Criptografar\n");
    printf("3 - Descriptografar\n\n");

    scanf("%d", &opcao);

    if(opcao == 1)
    {
        gerarChavePublica();
    }


}
