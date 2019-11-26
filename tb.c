#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

 typedef struct y
 {
 char nome[50];
 double notas[6];
 double exer[6];
 double trabalho;
 int subs;
 char situacao[1000];
 int mt;
 int aus;
 double mf2;
 }x;
    void menu();
    void cadastrar();
    void consultar();
    void alterar();
    void listar();

    int main(void)
{

    x alunos[50];

    setlocale(LC_ALL, "Portuguese");
    menu();


    return 0;
}
void menu()
{
        system("clear");
    int n;
    do
    {
        system("clear");
            printf("1-Cadastrar Uma Turma\n2-Consultar um aluno\n3-Alterar dados de um aluno\n4-Listar dados de uma turma\n5-Terminar a execução\n");
           scanf("%d",&n);

            getchar();
           if(n==1)
           {
               cadastrar();
           }
           else  if (n==2)
           {
               consultar();
           }
           else if (n==3)
           {
               alterar();
           }
           else  if(n==4)
           {
               listar();
           }
           else if(n==5)
           {
               break;
           }
           else
           {
           printf("Essa opção não existe\n");

           }
    }

    while(1);
}
void cadastrar()
{
    char nome[50];
    char turma[100];

    x alunos;
    printf("Informe o nome do arquivo\n");
    scanf("%s",turma);
    printf("\n");
    FILE *file;
    file=fopen(turma,"wb");

    do
    {


            double ne=0,np=0,nt=0,mf=0;

            printf("Digite Sua Matricula: ");
            scanf("%d",&alunos.mt);
            if(alunos.mt==0)
            {
                break;
            }

            printf("\n");
            printf("Digite seu Nome: ");
            getchar();

            scanf("%[^\n]",&alunos.nome);

            printf("\n");
            int i,j;
            for(i=0; i<6; i++)
            {
            printf("Digite a Nota %d: ",i+1);
            scanf("%lf",&alunos.notas[i]);
            printf("\n");

            np=np+alunos.notas[i];
        }
            np=np/6;
            for(j=0; j<6; j++)
            {
            printf("Digite a Nota do Exercicio %d: ",j+1);
            scanf("%lf",&alunos.exer[j]);

            printf("\n");
            ne=ne+alunos.exer[j];
            }
            ne=ne/6;
            printf("Digite Sua Nota de Trabalho: ");
            scanf("%lf",&alunos.trabalho);
            printf("\n");


            nt=nt+alunos.trabalho;
            printf("Digite o numero de ausencia: ");
            scanf("%d",&alunos.aus);
            printf("\n");

            mf=(np*0.8)+(ne*0.1)+(nt*0.1);
            alunos.mf2 = mf;
            if(alunos.aus<=32 && mf>=6)
            {
                strcpy(alunos.situacao,"Aprovado\n");
            }
            if(alunos.aus<=32 && mf<6)
            {
                strcpy(alunos.situacao,"Reprovado Por nota\n");
            }
            if(alunos.aus>32 && mf>=6)
            {
                strcpy(alunos.situacao,"Reprovado por ausencia\n");
            }
            if(alunos.aus>32 && mf<6)
            {
                strcpy(alunos.situacao,"Reprovado por ausencia e por nota\n");
            }
            fwrite(&alunos,sizeof(x),1,file);

}

    while(1);
     fclose(file);
}
void consultar()
{

x alunos;
int matricula,i,j;
char check[50];
FILE *file;
        do
        {
            printf("Informe o nome do arquivo a ser consultado\n");
            scanf("%s",check);
            printf("\n");
            FILE *file = fopen(check,"rb");
            if(strcmp(check,"fim")==0)
            {
            return;
            }

            if(file==NULL)
            {
            continue;
            }
            else
            {
            break;
            }

        }
        while(1);

do{
        FILE *file = fopen(check,"rb");
        printf("Informe a Matricula a ser consultada\n");
        scanf("%d",&matricula);
        printf("\n");
        if(matricula==0)

        {
        break;
        }
        while(1)
        {
        fread(&alunos,sizeof(x),1,file);

        if(feof(file))break;

        if(matricula==alunos.mt)
        {
            printf("%d\n",alunos.mt);
            printf("%s\n",alunos.nome);
            for(i=0; i<6; i++)
            {
            printf("%.2lf\n",alunos.notas[i]);
            }
            for(j=0; j<6; j++)
            {
            printf("%.2lf\n",alunos.exer[j]);
            }
            printf("%.2lf\n",alunos.trabalho);

            printf("%d\n",alunos.aus);

            printf("%.2lf\n",alunos.mf2);

            printf("%s\n",alunos.situacao);
        }

        }
        fclose(file);

 }
while(1);

}
void alterar()
{
while(1)
{
x alunos;
int a=0,mt2=0,i,aux=0;
char teste[100];
FILE *file;
        do
        {
            printf("informe o nome do arquivo a ser consultado\n");
            scanf("%s",teste);
            printf("\n");
            FILE *file = fopen(teste,"rb");
            if(strcmp(teste,"fim")==0)
            {
            return;
            }

            if(file==NULL)
            {
            continue;
            }
            else
            {
            break;
            }

        }
            while(1);

            do
            {
                aux=0;
                file=fopen(teste,"rb");
                printf("Informe A Matricula\n");
                scanf("%d",&mt2);
                printf("\n");
                if(mt2==0)
                {
                    fclose(file);
                    return;
                }
                do
                {
                    a++;
                    fread(&alunos,sizeof(x),1,file);
                    printf("Matricula: %d\n", alunos.mt);
                    if(mt2==alunos.mt)
                    {
                    break;
                    }
                    if(feof(file))
                    {
                        aux++;
                        break;
                    }

                }
                while(mt2!=alunos.mt);

                fclose(file);

            }

            while(aux==1);

            file=fopen(teste,"rb+");


            double ne=0,np=0,nt=0,mf=0;

            printf("Digite seu Nome: ");
            getchar();

            scanf("%[^\n]",&alunos.nome);

            printf("\n");
            int j;
            for(i=0; i<6; i++)
            {
            printf("Digite a Nota %d: ",i+1);
            scanf("%lf",&alunos.notas[i]);
            printf("\n");

            np=np+alunos.notas[i];
            }
            np=np/6;
            for(j=0; j<6; j++)
            {
            printf("Digite a Nota do Exercicio %d: ",j+1);
            scanf("%lf",&alunos.exer[j]);

            printf("\n");
            ne=ne+alunos.exer[j];
            }
            ne=ne/6;
            printf("Digite Sua Nota de Trabalho: ");
            scanf("%lf",&alunos.trabalho);
            printf("\n");


            nt=nt+alunos.trabalho;
            printf("Digite o numero de ausencia: ");
            scanf("%d",&alunos.aus);
            printf("\n");

            mf=(np*0.8)+(ne*0.1)+(nt*0.1);
            alunos.mf2 = mf;
            if(alunos.aus<=32 && mf>=6)
            {
                strcpy(alunos.situacao,"Aprovado\n");
            }
            if(alunos.aus<=32 && mf<6)
            {
                strcpy(alunos.situacao,"Reprovado Por nota\n");
            }
            if(alunos.aus>32 && mf>=6)
            {
                strcpy(alunos.situacao,"Reprovado por ausencia\n");
            }
            if(alunos.aus>32 && mf<6)
            {
                strcpy(alunos.situacao,"Reprovado por ausencia e por nota\n");
            }

            fseek(file,sizeof(x)*(a-1),SEEK_SET);

            fwrite(&alunos,sizeof(x),1,file);
            fclose(file);
            aux=0;
    }

}
void listar()
{

    char teste[100];
    FILE *file;
    x alunos;
    x *aux = (x*) malloc(sizeof(x)*1);
    x aux2;
    int n,a=1,i,j;
    menu:
    aux = (x*) malloc(sizeof(x)*1);

        do
        {
            printf("informe o nome do arquivo a ser consultado\n");
            scanf("%s",teste);
            printf("\n");
            file = fopen(teste,"rb");
            if(strcmp(teste,"fim")==0)
            {
            return;
            }

            if(file==NULL)
            {
            continue;
            }
            else
            {
            break;
            }

        }
            while(1);
       do
            {
            fread(&aux[a-1],sizeof(x),1,file);
            if(feof(file)) break;
            a++;
            aux = (x*) realloc(aux,sizeof(x)*a);
            }

            while(1);
            aux = (x*) realloc(aux,sizeof(x)*a-1);
            a--;


    do
    {
printf("1-listar os alunos por ordem crescente de matriculas\n2-listar os alunos por ordem alfabetica de nome\n3-Listar os alunos por ordem crescente de nota final\n4-terminar e voltar para processar nova turma\n5-terminar a execucao do modulo\n");

    scanf("%d",&n);
        if(n==1)
        {
            for(i=0; i<a; i++)
            {
                for(j=0; j<a-(i+1); j++)
                {
                    if(aux[j].mt>aux[j+1].mt)
                    {
                    aux2=aux[j];
                    aux[j]=aux[j+1];
                    aux[j+1]=aux2;

                    }

                }
            }
            for(i=0; i<a; i++)
            {
            printf("Matricula %d\n",aux[i].mt);
            }
            printf("\n\n");
        }

        else if(n==2)
        {
        for(i=0; i<a; i++)
            {
                for(j=0; j<a-(i+1); j++)
                {
                    if(strcmp(aux[j].nome,aux[j+1].nome)>0)
                    {
                    aux2=aux[j];
                    aux[j]=aux[j+1];
                    aux[j+1]=aux2;

                    }

                }
            }
            for(i=0; i<a; i++)
            {
            printf("%s\n",aux[i].nome);

            }
            printf("\n\n");

        }
        else if(n==3)
        {
        for(i=0; i<a; i++)
            {
                for(j=0; j<a-(i+1); j++)
                {
                    if(aux[j].mf2 > aux[j+1].mf2)
                    {
                    aux2=aux[j];
                    aux[j]=aux[j+1];
                    aux[j+1]=aux2;

                    }

                }
            }
            for(i=0; i<a; i++)
            {
            printf("%.2lf\n",aux[i].mf2);

            }
            printf("\n\n");

        }
        else if(n==4)
        {
            fclose(file);
            a=1;
            free(aux);
            goto menu;
        }
        else if(n==5)
        {
           break;
        }

    }
    while(1);
}
