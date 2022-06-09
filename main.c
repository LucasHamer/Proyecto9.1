#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int CantUnidVendi;
    float ImporteTotal;

}Sproducto;

int buscar(Sproducto[], char[],int);
int main()
{
    Sproducto vproducto[50];
    int x=0,cantidad,pos,f;
    char cod[6];

        printf("Ingrese descripcion de producto(Finaliza con FIN): ");
            fflush(stdin);
            gets(vproducto[x].descripcion);

    while((strcmpi(vproducto[x].descripcion,"Fin"))!=0)
        {
            printf("Ingrese codigo de producto: ");
            fflush(stdin);
            gets(vproducto[x].codigo);

            printf("Ingrese precio de producto: ");
            fflush(stdin);
            scanf("%f",&vproducto[x].precio);

            printf("Ingrese cantidad de unidades vendidas de producto(Mes anterior): ");
            fflush(stdin);
            scanf("%d",&vproducto[x].CantUnidVendi);

            printf("Ingrese importe total de producto(Mes anterior): ");
            fflush(stdin);
            scanf("%f",&vproducto[x].ImporteTotal);

            printf("\n");
            x++;


        printf("Ingrese descripcion de producto(Finaliza con FIN): ");
            fflush(stdin);
            gets(vproducto[x].descripcion);
        }

            printf("Ingrese cantidad(Mes actual): ");
            fflush(stdin);
            scanf("%d",&cantidad);

        while(cantidad!=0)
            {
                printf("Ingrese codigo de producto(Mes actual): ");
                fflush(stdin);
                gets(cod);
                printf("\n");

                pos=buscar(vproducto,cod,x);
                    if(pos!=-1)
                    {
                        vproducto[pos].CantUnidVendi+=cantidad;
                        vproducto[pos].ImporteTotal+=cantidad*vproducto[pos].precio;
                    }
                    else
                    {
                        printf("Codigo incorrecto");
                    }
                    printf("\n");
                printf("Ingrese cantidad(Mes actual): ");
                fflush(stdin);
                scanf("%d",&cantidad);
            }
            printf("\n%-30s %16s %10s","Descripcion","Cantidad Vendida","Importe");
            for(f=0;f<x;f++)
            printf("\n%-30s %16d %10.2f",vproducto[f].descripcion,vproducto[f].CantUnidVendi,vproducto[f].ImporteTotal);
            printf("\n");

    return 0;
}
int buscar(Sproducto co[], char pro[],int can)
{
    int f=0,p=-1;

    while(p==-1&&f<can)
    {
        if(strcmpi(co[f].codigo,pro)==0)
        {
            p=f;
        }
        else
        {
            f++;
        }
    }
    return p;
};
