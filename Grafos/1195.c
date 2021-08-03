#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct regNo
{
    struct regNo *esq;
    int valor;
    struct regNo *dir;
};
typedef struct regNo TNo;

void IncluiNo(TNo **, TNo **, int);
TNo *AchaPai(TNo *, int n);
void ImprimeArvorePRE(TNo *);
void ImprimeArvorePOS(TNo *);
void ImprimeArvoreIN(TNo *);
void LimpaArvore(TNo *);

int main()
{
    TNo *raiz, *pai;
    int TotCasos, Cases, TotNum, Cont2, Num;
    scanf("%d", &TotCasos);
    for (Cases = 0; Cases < TotCasos; Cases++)
    {
        scanf("%d", &TotNum);
        raiz = NULL;
        for (Cont2 = 0; Cont2 < TotNum; Cont2++)
        {
            scanf("%d", &Num);
            IncluiNo(&raiz, &pai, Num);
        }
        printf("Case %d:\n", Cases + 1);
        printf("Pre.:");
        ImprimeArvorePRE(raiz);
        puts("");
        printf("In..:");
        ImprimeArvoreIN(raiz);
        puts("");
        printf("Post:");
        ImprimeArvorePOS(raiz);
        puts("");
        LimpaArvore(raiz);
        puts("");
    }
    return 0;
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
        /* n é descendente do lado esquerdo de r */
        if (r->esq == NULL)
            return r;
        else
            return AchaPai(r->esq, n);
    else
        /* n é descendente do lado direito de r */
        if (r->dir == NULL)
        return r;
    else
        return AchaPai(r->dir, n);
}

/* PRE ORDEM */
void ImprimeArvorePRE(TNo *r)
{
    if (r != NULL)
    {
        printf(" %d", r->valor);
        ImprimeArvorePRE(r->esq);
        ImprimeArvorePRE(r->dir);
    }
}
/* POS ORDEM */
void ImprimeArvorePOS(TNo *r)
{
    if (r != NULL)
    {
        ImprimeArvorePOS(r->esq);
        ImprimeArvorePOS(r->dir);
        printf(" %d", r->valor);
    }
}
/* INFIXA */
void ImprimeArvoreIN(TNo *r)
{
    if (r != NULL)
    {
        ImprimeArvoreIN(r->esq);
        printf(" %d", r->valor);
        ImprimeArvoreIN(r->dir);
    }
}