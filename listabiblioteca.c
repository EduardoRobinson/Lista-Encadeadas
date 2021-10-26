#include <stdio.h>
#include <stdlib.h>

typedef struct No{
int chave;
struct No *prox;

}lista;

lista *aloca(int k)
{
lista *aux;
aux=(lista *)malloc(sizeof(lista));
aux->chave=k;
aux->prox=NULL;
return aux;

}

lista *insereinicio(lista *prim,int k)
{
lista *no;
no=aloca(k);
if(no==NULL)return 0;
if(prim==NULL)
{
prim=no;
return prim;
}
else
{
lista *aux;
aux=prim;
prim=no;
prim->prox=aux;
return prim;


}

}

lista *inserefim(lista *prim,int k)
{
lista *no;
no=aloca(k);
if(no==NULL)return 0;
if(prim==NULL)
    {
        prim=no;
        return prim;
    }
else
{
    lista *aux=prim;
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
aux->prox=no;
return prim;

}

}

lista *imprime(lista *aux)
{

if(aux==NULL)
{
printf("fim");
}
else
{
printf("[%d]",aux->chave);
return imprime(aux->prox);

}


}

lista *removeinicio(lista *prim)
{
lista *aux=prim->prox;
free(prim);
prim=aux;
return prim;


}

lista *removefim(lista *prim)
{
lista *aux=prim;
if(prim->prox==NULL)
{
free(prim);
prim=NULL;
return prim;

}
while(aux->prox->prox!=NULL)
{
aux=aux->prox;
}
free(aux->prox);
aux->prox=NULL;
return prim;

}

lista *altera(lista *prim,int k,int n)
{
lista *aux=prim;
if(aux->chave==k)
{
aux->chave=n;
return prim;
}
while(aux->chave!=k)
{
aux=aux->prox;
}

aux->chave=n;
return prim;


}

int busca(lista *prim,int k)
{
lista *aux=prim;
int i=0;
while(aux!=NULL)
{
if(aux->chave==k)
{
i++;

}
aux=aux->prox;

}
return i;

}

lista *buscaremove(lista *prim,int k)
{
lista *aux=prim;
while(aux->prox->chave!=k)
{
aux=aux->prox;

}
lista *aux2=aux->prox->prox;
free(aux->prox);
aux->prox=aux2;
return prim;








}












int main()
{
lista *prim=NULL;
int opc=5,n,procura,n1;
while(opc!=0)
{
printf("\n1-inserir inicio");
printf("\n2-inserir final");
printf("\n3-remover inicio");
printf("\n4-remover final");
printf("\n5-alterar um campo");
printf("\n6-buscar e remover\n");
scanf("%d",&opc);
switch (opc)
{
case 1:printf("\nqual valor voce deseja inserir:\n");
        scanf("%d",&n);
        prim=insereinicio(prim,n);
        imprime(prim);
        break;
case 2:printf("\nqual valor voce deseja inserir:\n");
        scanf("%d",&n);
        prim=inserefim(prim,n);
        imprime(prim);
        break;
case 3:if(prim==NULL)
        {
        printf("sem itens na lista");
        break;
        }
        prim=removeinicio(prim);
        imprime(prim);
        break;
case 4:if(prim==NULL)
        {
        printf("sem itens na lista");
        break;
        }
        prim=removefim(prim);
        imprime(prim);
        break;
case 5:if(prim==NULL)
        {
        printf("sem itens na lista");
        break;
        }
        printf("qual campo da lista voce deseja alterar:\n");
        scanf("%d",&n);
        procura=busca(prim,n);
        if(procura==0)
        {
        printf("valor nao encontrado");
        break;
        }
        printf("qual valor voce deseja colocar nesse campo:\n");
        scanf("%d",&n1);
        prim=altera(prim,n,n1);
        imprime(prim);
        break;
case 6:if(prim==NULL)
        {
        printf("sem itens na lista");
        break;
        }
        printf("qual campo da lista voce deseja remover:\n");
        scanf("%d",&n);
        procura=busca(prim,n);
        if(procura==0)
        {
        printf("valor nao encontrado");
        break;
        }
        if(n==prim->chave)
        {
        prim=removeinicio(prim);
        imprime(prim);
        break;

        }        
        
        prim=buscaremove(prim,n);
        imprime(prim);
        break;


}



}



}
