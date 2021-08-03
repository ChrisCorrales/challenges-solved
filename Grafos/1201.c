#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

struct regNo
{
    struct regNo *esq;
    int valor;
    struct regNo *dir;
};
typedef struct regNo TNo;

void IncluiNo(TNo **, TNo **, int);
TNo *AchaPai(TNo *, int);
TNo *PesqArvor(TNo *, int);
TNo *RetiraArvoEsq(TNo *, int);
void ImprimeArvorePRE(TNo *, int *);
void ImprimeArvorePOS(TNo *, int *);
void ImprimeArvoreIN(TNo *, int *);
void LimpaArvore(TNo *);

int main()
{
    char Acao[9];
    int Bolean = FALSE, Num;
    TNo *raiz = NULL, *pai, *aux;
    while (scanf("%s", Acao) != EOF)
    {
        if (strcmp(Acao, "I") == 0)
        {
            scanf(" %d", &Num);
            IncluiNo(&raiz, &pai, Num);
        }
        else if (strcmp(Acao, "P") == 0)
        {
            scanf("%d", &Num);
            aux = PesqArvor(raiz, Num);
            if (aux == NULL)
                printf("%d nao existe\n", Num);
            else
                printf("%d existe\n", Num);
        }
        else if (strcmp(Acao, "R") == 0)
        {
            scanf("%d", &Num);
            raiz = RetiraArvoEsq(raiz, Num);
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

void IncluiNo(TNo **r, TNo **p, int n)
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

TNo *AchaPai(TNo *r, int n)
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
            printf("%d", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %d", r->valor);
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
            printf("%d", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %d", r->valor);
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
            printf("%d", r->valor);
            *bol = TRUE;
        }
        else
            printf(" %d", r->valor);
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

TNo *PesqArvor(TNo *r, int valor)
{
    if (r == NULL)
        return NULL;
    else if (r->valor == valor)
        return r;
    else if (r->valor < valor)
        return PesqArvor(r->dir, valor);
    else if (r->valor >= valor)
        return PesqArvor(r->esq, valor);
    return r;
}

TNo *RetiraArvoEsq(TNo *r, int n)
{
    TNo *aux;
    if (r == NULL)
        return NULL;
    else if (r->valor > n)
        r->esq = RetiraArvoEsq(r->esq, n);
    else if (r->valor < n)
        r->dir = RetiraArvoEsq(r->dir, n);
    else
    {
        if (r->esq == NULL && r->dir == NULL)
        {
            free(r);
            r = NULL;
        }
        else if (r->esq == NULL)
        {
            aux = r;
            r = r->dir;
            free(aux);
        }
        else if (r->dir == NULL)
        {
            aux = r;
            r = r->esq;
            free(aux);
        }
        else
        {
            aux = r->esq;
            while (aux->dir != NULL)
                aux = aux->dir;
            r->valor = aux->valor;
            aux->valor = n;
            r->esq = RetiraArvoEsq(r->esq, n);
        }
    }
    return r;
}