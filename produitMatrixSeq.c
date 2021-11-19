#include <mpi.h>
#include<stdio.h> 
#include<stdlib.h>

 int main(int argc, char** argv){
  int mat1[10][10], mat2[10][10], mul[10][10];
  int n,m,i,j,k,node;
  double mytime;
  
  
   MPI_Init(&argc,&argv);
   mytime = MPI_Wtime();  /*get the time just before work to be timed*/
   MPI_Comm_rank(MPI_COMM_WORLD, &node);
   
    printf("Entrez le nombre de lignes et de colonnes:\n");
    scanf("%d%d",&n,&m);
  
    printf("Entrez les éléments de la première matrice\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
  
    printf("Entrez les éléments de la deuxième matrice\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    } 
    
  printf("Multiplication du matrice = \n");
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      mul[i][j]=0;
      for(k = 0; k < m; k++)
      {
        mul[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  
  //Afficher le résultat
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++) 
    {
      printf("%d\t",mul[i][j]);
    }
    printf("\n");
  }
  mytime = MPI_Wtime() - mytime;
  printf("Timing from node %d is %lf seconds.\n",node,mytime);
   
  MPI_Finalize();
}















