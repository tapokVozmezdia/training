#include <stdio.h>
#include <stdlib.h>

int main()
{  
    int n;
   
    printf("Type in square matrix size: ");
    scanf("%i", &n);
       
    int** mass = (int**)calloc(n*n, sizeof(int*));
   
    for(int i = 0; i < n; i++)
    {
        mass[i] = (int*)calloc(n, sizeof(int));
    }
    //int mass[n][n];


    printf("Let's fill the matrix:\n");
   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //scanf("%i ", &mass[i][j]);
            scanf("%i ", *(mass + i) + j);
        }
    }
   
    printf("Your matrix:\n");
   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("(%i)", mass[i][j]);
        }
        printf("\n");
    }
   
    FILE* file = fopen("data.txt", "wr");


    if(file == NULL)
    {
        printf("File open error\n");
        return 1;
    }


    printf("Modified matrix:\n");


    int temp;
    int border = n;


    for(int i = 0; i < n; i++)
    {


        for(int j = 0; j < n - border; j++)
        {
            temp = mass[i][j];
            mass[i][j] = mass[j][i];
            mass[j][i] = temp;
        }
        border--;
    }
   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("(%i)", mass[i][j]);
            fprintf(file,"%i ", mass[i][j]);
        }
        fprintf(file,"\n");
        printf("\n");
    }
   
    //free(mass);
    fclose(file);
    return 0;
}
