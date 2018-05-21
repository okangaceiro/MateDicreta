#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int verPrimo=0;
long int primo1, primo2;
long int textocrip[1000];

/*Calculado conforme a aula
Formula: a^b mod n  */
long long int expModular(long long int a, long long int b, long long int n){
    long long int z = 0;
    if(b==0){
        return 1;
    };
    z = expModular(a, floor(b/2), n) % n;
    if(b%2 == 0){
        return (z*z) % n;
    }else{
        return (z*z*a) % n ;
    }
}

long long int* euclidesEstendido(long long int a,long long int b){
    long long int *vetEuclides;
    long long int d = 0;
    vetEuclides = (long long int*) malloc(3*sizeof(long long int));
    if (b == 0){
        vetEuclides[0] = 1;
        vetEuclides[1] = 0;
        vetEuclides[2] = a;
        return vetEuclides;
    }
    vetEuclides = euclidesEstendido(b, a%b);
    vetEuclides[0] = b;
    vetEuclides[1] = a - (floor(a/b)*b);
    vetEuclides[2] = vetEuclides[2];
    return vetEuclides;
}

long long int potencia(long long int a, long long int e, long long int n){

    long long int A = a, P = 1, E = e;

	while(1){

		if(E == 0)
			return P;

		else if(E%2 != 0){
			P = (A * P)%n;
			E = (E-1)/2;
		}

		else{
			E = E/2;
		}
		A = (A*A)%n;
	}
}

void descriptografar()
{
    //perguntar ao lucas se precisa verificar cada codição dos elementos!!!!
    long long int e, p, q, r, pq, a[1000], conta = 0, t=0, s=0;
    long long int salvo[1000] = {0};
    long long int st[1000];
    long long int mensagem[100], mensagemC[100];
    int i=0, j=1, k=0,contad=0;
    FILE *descript;


    printf("Digite o valor de E, P e Q: \n");
    scanf("%lld %lld %lld", &e, &p, &q);
    pq = (p-1)*(q-1);

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


        k++;
        j++;
    }

    //printf("%lld\n", st[k-2]);

    if(conta%2!=0)
    {
        t = st[k-1]*(-1);
        s = st[k-2];
    }
    else
    {
        t = st[k-1];
        s = st[k-2]*(-1);
    }

    printf("%lld\n%lld", s, t);

    descript = fopen("descriptar.txt","w");
    fclose(descript);

    printf("\nDigite a mensagem cript.(obs: digite -1 para encerrar a entrada):\n");

    for(i=0; ;i++)
    {           
        scanf("%lld", &mensagemC[i]);
        contad++;
        if(mensagemC[i]==-1) break;
    }

    //printf("%lld\n", s);

    for(i = 0; i < contad-1; i++){
		mensagem[i] = expModular(mensagemC[i], s, p*q);
		printf("%lld ", mensagem[i]);
	}
	descript = fopen("descriptar.txt","r+");

	for(i = 0; i < contad-1; i++)
    {
		fprintf(descript,"%lld ", mensagem[i]);
	}

	fclose(descript);
}

 void criptografar()
 {
    int i=0;
    char texto[100];
    long long int n,e,C,aux, auxiliadora, auxtext, acumuladora = 0;
    FILE *cripto;
    cripto = fopen("cripto.txt","w");
    fclose (cripto);
    printf("Escreva um texto:\n");
    //scanf("%[^\n]s", texto);
    fgets(texto, 1000, stdin);
    printf("Digite o valor n da chave publica:\n");
    scanf("%lld", &n);
    printf("Digite o valor e da chave publica:\n");
    scanf("%lld", &e);
    for(i = 0; i < strlen(texto); i++){
            aux = texto[i];
		textocrip[i] = expModular(aux, e, n);
            aux=0;
		acumuladora++;
	}
	cripto = fopen("cripto.txt","r+");

    for(i=0; i < acumuladora; i++){

        fprintf(cripto,"%lld ", textocrip[i]);
    }
    printf("\n");
    fclose (cripto);


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

    for(i=1; i<=sqrt(primo); i++)
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
        FILE *chavepublic;
        chavepublic = fopen("chavepublic.txt","w");
        fclose(chavepublic);

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
        chavepublic = fopen("chavepublic.txt","r+");
        fprintf(chavepublic,"%ld %ld", primo1*primo2, e);
        fclose (chavepublic);

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
