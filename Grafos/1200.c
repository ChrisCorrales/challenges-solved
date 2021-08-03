#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct regNo
{
    struct regNo *esq;
    char valor;
    struct regNo *dir;
};
typedef struct regNo TNo;

void IncluiNo(TNo **, TNo **, char);
TNo *AchaPai(TNo *, char n);
void PesqArvor(TNo *, char, char *);
void ImprimeArvorePRE(TNo *, int *);
void ImprimeArvorePOS(TNo *, int *);
void ImprimeArvoreIN(TNo *, int *);
void LimpaArvore(TNo *);

int main()
{
    char Acao[9], Letra, Existe[15];
    int Bolean = FALSE;
    TNo *raiz = NULL, *pai;
    while (scanf("%s", Acao) != EOF)
    {
        if (strcmp(Acao, "I") == 0)
        {
            scanf(" %c", &Letra);
            IncluiNo(&raiz, &pai, Letra);
        }
        else if (strcmp(Acao, "P") == 0)
        {
            scanf(" %c", &Letra);
            PesqArvor(raiz, Letra, Existe);
            printf("%c %s\n", Letra, Existe);
            strcpy(Existe, "");
        }
        else if (strcmp(Acao, "INFIXA") == 0)
        {
            ImprimeArvoreIN(raiz, &Bolean);
            puts("");
            Bolean = FALSE;
        }
        else if (strcmp(Acao, "PREFIXA") == 0)
        {
            ImprimeArvorePRE(raiz, &Bolean);
            puts("");
            Bolean = FALSE;
        }
        else if (strcmp(Acao, "POSFIXA") == 0)
        {
            ImprimeArvorePOS(raiz, &Bolean);
            puts("");
            Bolean = FALSE;
        }
    }
    LimpaArvore(raiz);
    return 0;
}

void IncluiNo(TNo **r, TNo **p, char n)
{
    TNo *aux;
    aux = (TNo *)malloc(sizeof(TNo));
    aux->valor = n;
    aux->esq = NULL;
    aux->dir = NULL;
    *p = AchaPai(*r, n);
    if (*p == NULL)
        *r = aux;
    else if (n <= (**p).valor)
        (**p).esq = aux;
    else
        (**p).dir = aux;
}

TNo *AchaPai(TNo *r, char n)
{
    if (r == NULL)
        return NULL;
    else if (n <= r->valor)
    {
        if (r->esq == NULL)
            return r;
        else
            return AchaPai(r->esq, n);
    }
    else
    {
        if (r->dir == NULL)
            return r;
        else
            return AchaPai(r->dir, n);
    }
}
/* PRE ORDEM */
void ImprimeArvorePRE(TNo *r, int *bol)
{
    if (r != NULL)
    {
        if (*bol == FALSE)
        {
            printf("%c", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %c", r->valor);
        ImprimeArvorePRE(r->esq, bol);
        ImprimeArvorePRE(r->dir, bol);
    }
}
/* POS ORDEM */
void ImprimeArvorePOS(TNo *r, int *bol)
{
    if (r != NULL)
    {
        ImprimeArvorePOS(r->esq, bol);
        ImprimeArvorePOS(r->dir, bol);
        if (*bol == FALSE)
        {
            printf("%c", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %c", r->valor);
    }
}
/* INFIXA */
void ImprimeArvoreIN(TNo *r, int *bol)
{
    if (r != NULL)
    {
        ImprimeArvoreIN(r->esq, bol);
        if (*bol == FALSE)
        {
            printf("%c", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %c", r->valor);
        ImprimeArvoreIN(r->dir, bol);
    }
}

void LimpaArvore(TNo *r)
{
    if (r != NULL)
    {
        LimpaArvore(r->esq);
        LimpaArvore(r->dir);
        free(r);
    }
}

void PesqArvor(TNo *r, char valor, char *existe)
{
    if (r == NULL)
        strcpy(existe, "nao existe");
    else if (r->valor == valor)
        strcpy(existe, "existe");
    else
    {
        if (r->valor < valor)
            PesqArvor(r->dir, valor, existe);
        else if (r->valor >= valor)
            PesqArvor(r->esq, valor, existe);
    }
}