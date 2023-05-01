#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion;
    int Duracion; // entre 10 – 100
} typedef Tarea;

//FUNCIONES

void cargarTareas(Tarea** ListaT, int cant);
void mostrarTareas(Tarea** ListaT, int cant);

//PROGRAMA PRINCIPAL
int main()
{
    int cantTareas;

    printf("Ingresa la cantidad de tareas: ");
    scanf("%d",&cantTareas);
    
    Tarea **listaTareas = (Tarea **)malloc(cantTareas * sizeof(Tarea *));

    //Inicialzacion del arreglo en NULL
    for (int i = 0; i < cantTareas; i++)
    {
        listaTareas[i] = NULL;
    }
    
    cargarTareas(listaTareas, cantTareas);
    mostrarTareas(listaTareas, cantTareas);

    //LIBERACION DE MEMORIA (Por cada malloc tengo un free)
    for (int i = 0; i < cantTareas; i++)
    {
        free(listaTareas[i]);
        free(listaTareas[i]->Descripcion);
    }
    
    //Libero el puntero doble
    free(listaTareas);

    return 0;
}

void cargarTareas(Tarea** ListaT, int cant){
    char *buffer;

    for(int i = 0; i < cant; i++) {

        ListaT[i] = (Tarea *)malloc(sizeof(Tarea) * 1);
        ListaT[i]->TareaID = i + 1;
        printf("\nIngrese la descripci%cn: ",162);
        buffer = (char *)malloc(100 * sizeof(char));
        fflush(stdin);
        gets(buffer);
        ListaT[i]->Descripcion = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(ListaT[i]->Descripcion, buffer);

        printf("\nIngrese la duraci%cn: ",162);
        scanf("%d", &ListaT[i]->Duracion);
        
        free(buffer);
    }

}

void mostrarTareas(Tarea** ListaT, int cant){
    printf("\n-----------TAREAS-----------");
    for (int i = 0; i < cant; i++)
    {
        printf("\nID de la tarea: %d", ListaT[i]->TareaID);
        printf("\nDescripci%cn de la tarea: %s",162 , ListaT[i]->Descripcion);
        printf("\nDuraci%cn de la tarea: %d",162 , ListaT[i]->Duracion);
        printf("\n");
    }
    
}