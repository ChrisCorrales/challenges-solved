#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct regNo
{
    struct regNo *esq;
    char nome[11];
    int vivo, totkill;
    struct regNo *dir;
};
typedef struct regNo TNo;

void IncluiNo(TNo **, TNo **, char *, int);
int PesqArvorVivo(TNo *, char *);
int PesqArvorMorto(TNo *, char *);
void ImprimeArvoreIN(TNo *);
TNo *AchaPai(TNo *, char *);

int main()
{
    char Assasin[11], Vitim[11];
    TNo *raiz = NULL, *pai;
    int bolean;
    while (scanf("%s%s", Assasin, Vitim) != EOF)
    {
        bolean = PesqArvorVivo(raiz, Assasin);
        if (bolean == FALSE)
            IncluiNo(&raiz, &pai, Assasin, TRUE);
        bolean = PesqArvorMorto(raiz, Vitim);
        if (bolean == FALSE)
            IncluiNo(&raiz, &pai, Vitim, FALSE);
    }
    puts("HALL OF MURDERERS");
    ImprimeArvoreIN(raiz);
    return 0;
}

int PesqArvorVivo(TNo *r, char *valor)
{
    if (r == NULL)
        return FALSE;
    else if (strcmp(r->nome, valor) == 0)
    {
        r->totkill = r->totkill + 1;
        return TRUE;
    }
    else if (strcmp(r->nome, valor) < 0)
        return PesqArvorVivo(r->dir, valor);
    else if (strcmp(r->nome, valor) > 0)
        return PesqArvorVivo(r->esq, valor);
    return FALSE;
}

int PesqArvorMorto(TNo *r, char *valor)
{
    if (r == NULL)
        return FALSE;
    else if (strcmp(r->nome, valor) == 0)
    {
        r->vivo = FALSE;
        return TRUE;
    }
    else if (strcmp(r->nome, valor) < 0)
        return PesqArvorMorto(r->dir, valor);
    else if (strcmp(r->nome, valor) > 0)
        return PesqArvorMorto(r->esq, valor);
    return FALSE;
}

void IncluiNo(TNo **r, TNo **p, char *nome, int bolean)
{
    TNo *aux;
    char n[11];
    aux = (TNo *)malloc(sizeof(TNo));
    strcpy(aux->nome, nome);
    aux->vivo = bolean;
    aux->totkill = 1;
    aux->esq = NULL;
    aux->dir = NULL;
    *p = AchaPai(*r, nome);
    if (*p == NULL)
        *r = aux;
    else if (strcmp(nome, (**p).nome) < 0)
        (**p).esq = aux;
    else
        (**p).dir = aux;
}

void ImprimeArvoreIN(TNo *r)
{
    if (r != NULL)
    {
        ImprimeArvoreIN(r->esq);
        if (r->vivo == TRUE)
            printf("%s %d\n", r->nome, r->totkill);
        ImprimeArvoreIN(r->dir);
    }
}

TNo *AchaPai(TNo *r, char *n)
{
    if (r == NULL)
        return NULL;
    else if (strcmp(n, r->nome) < 0)
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