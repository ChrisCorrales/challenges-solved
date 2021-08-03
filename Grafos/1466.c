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

struct regLista
{
    TNo *End;
    struct regLista *Prox;
};
typedef struct regLista tLista;

typedef struct
{
    tLista *Inicio, *Final;
    int Qtd;
} DescFila;

void IncluiNo(TNo **, TNo **, int);
TNo *AchaPai(TNo *, int n);
TNo *LimpaArvore(TNo *);
TNo *PesqArvor(TNo *r, int);
void ImprimeArvoreNVL(TNo *);

void Enqueue(DescFila *);
void Queue(DescFila *, TNo *);
void InitializeQueue(DescFila *);

int main()
{
    TNo *raiz = NULL, *pai;
    int TotCasos, Cases, TotNum, Cont2, Num;
    scanf("%d", &TotCasos);
    for (Cases = 0; Cases < TotCasos; Cases++)
    {
        scanf("%d", &TotNum);
        for (Cont2 = 0; Cont2 < TotNum; Cont2++)
        {
            scanf("%d", &Num);
            IncluiNo(&raiz, &pai, Num);
        }
        printf("Case %d:\n", Cases + 1);
        ImprimeArvoreNVL(raiz);
        raiz = LimpaArvore(raiz);
        puts("");
    }
}

void ImprimeArvoreNVL(TNo *r)
{
    DescFila descritor;
    int bolean = TRUE;
    InitializeQueue(&descritor);
    Queue(&descritor, r);
    while (descritor.Qtd > 0)
    {
        if (bolean == TRUE)
        {
            printf("%d", r->valor);
            bolean = FALSE;
        }
        else
            printf(" %d", r->valor);
        if (r->esq != NULL)
            Queue(&descritor, r->esq);
        if (r->dir != NULL)
            Queue(&descritor, r->dir);
        Enqueue(&descritor);
        if (descritor.Inicio != NULL)
            r = descritor.Inicio->End;
    }
    puts("");
}

TNo *PesqArvor(TNo *r, int valor)
{
    if (r == NULL)
        return NULL;
    else if (r->valor == valor)
        return r;
    else if (r->valor < valor)
        return PesqArvor(r->dir, valor);
    else if (r->valor > valor)
        return PesqArvor(r->esq, valor);
    return r;
}

void Enqueue(DescFila *descritor)
{
    tLista *aux;
    aux = descritor->Inicio;
    descritor->Inicio = descritor->Inicio->Prox;
    descritor->Qtd--;
    if (descritor->Inicio == NULL)
        descritor->Final = NULL;
    free(aux);
}

void Queue(DescFila *descritor, TNo *end)
{
    tLista *aux;
    aux = (tLista *)malloc(sizeof(tLista));
    aux->End = end;
    aux->Prox = NULL;
    if (descritor->Inicio == NULL)
        descritor->Inicio = aux;
    else
        descritor->Final->Prox = aux;
    descritor->Final = aux;
    descritor->Qtd++;
}

void InitializeQueue(DescFila *descritor)
{
    descritor->Inicio = NULL;
    descritor->Final = NULL;
    descritor->Qtd = 0;
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

TNo *LimpaArvore(TNo *r)
{
    if (r != NULL)
    {
        LimpaArvore(r->esq);
        LimpaArvore(r->dir);
        free(r);
    }
    return NULL;
}