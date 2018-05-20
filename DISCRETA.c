#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int verPrimo=0;
long int primo1, primo2;
long int textocrip[1000];

void descriptografar()
{
    //perguntar ao lucas se precisa verificar cada codição dos elementos!!!!
    long long int e, pq, r, q, a[1000], conta = 0;
    long long int salvo[1000] = {0};
    long long int st[1000];
    int i=0, j=1, k=0;

    printf("Digite o valor de E e (P-1)*(Q-1): \n");
    scanf("%lld %lld", &e, &pq);


    for(i=0; r!=1; i++)
    {
        q = e/pq;
        conta++;
        r = e%pq;
        e = pq;
        pq = r;

        a[i] = q;
    }

    for(i=conta-1; i>=0; i--)
    {
            salvo[j] =  a[i];
            j++;
    }

    salvo[0] = 1;
    //printf("%lld %lld", salvo[0], salvo[1]);
    j=0;

    while(salvo[j] != 0)
    {
        if(k==0)
        {
            st[k] = salvo[0];
        }
        else
        {
            st[k] = salvo[j] * st[j-1] + st[j-2];
        }

        printf("%lld\n", st[k]);

        k++;
        j++;


    }



}

 void criptografar()
 {
    int i;
    char texto[100];
    long long int n,e,C,aux, auxiliadora, auxtext, acumuladora=0;

    printf("Escreva um texto:\n");
    //scanf("%[^\n]s", texto);
    fgets(texto, 1000, stdin);
    printf("Digite o valor n da chave publica:\n");
    scanf("%lld", &n);
    printf("Digite o valor e da chave publica:\n");
    scanf("%lld", &e);

   for(i=0; i< strlen(texto); i++){
        auxtext = texto[i];
        aux = pow(auxtext,e);
        printf("%lld\n", texto[i]);
        C = aux % n;
        textocrip[i] = C;
        acumuladora++;
    }

    for(i=0; i < acumuladora; i++){

        printf("%lld ", textocrip[i]);
    }
    printf("\n");




 }


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
        printf("Valor E eh valido");


}

int main()
{
    int opcao;

    printf("Digite uma das 3 opcoes: \n\n");

    printf("1 - Gerar chave publica\n");
    printf("2 - Criptografar\n");
    printf("3 - Descriptografar\n\n");

    scanf("%d", &opcao);
    getchar();

    if(opcao == 1)
    {
        gerarChavePublica();
    }
    else if(opcao == 2)
    {
        criptografar();
    }
    else if(opcao == 3)
    {
        descriptografar();
    }
    else
    {
        printf("Opcao invalida!\n");
    }

}
