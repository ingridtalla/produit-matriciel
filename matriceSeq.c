#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ms 3
int main(int argc, char* argv[])
{
    int i,j,k;
    int x,c;
    int M_a[ms][ms];
    int M_b[ms][ms];
    int M_c[ms][ms];
    int rank, p;
    double starttime, endtime;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Status status;
  
    if(rank == 0)
    {
        printf("\n les valeurs de la matrice de A:\n");
       

        for(i=0; i<ms; ++i)
            for(j=0; j<ms; ++j)
            scanf("%d",&M_a[i][j]);
        for(i=0; i<ms; ++i)
        {
            for(j=0; j<ms; ++j)
                printf("%5d" , M_a[i][j]);
            printf("\n");
        }
        printf("\n les valeurs de la matrice de  B:\n");
        
        for(x=0; x<ms; ++x)
            for(c=0; c<ms; ++c)
            scanf("%d",&M_b[x][c]);
        for(x=0; x<ms; ++x)
        {
            for(c=0; c<ms; ++c)
                printf("%5d" , M_b[x][c]);
            printf("\n");
        }
    }
   
    
    
    //time function
    starttime = MPI_Wtime();
    for(k=0; k<ms; k++)
    for(i=0; i<ms; i++)
    	{
        M_c[i][k] = 0;
        for(j=0; j<ms; j++)
            M_c[i][k] = M_c[i][k] + M_a[i][j] * M_b[j][k];
        }
        endtime = MPI_Wtime();
    
    if(rank == 0)
    {
    //resultat of multiplication
        printf("\n le resutat de multiplication de A*B est  C:\n");
            for(i=0; i<ms; i++)
            {
            printf("\n");
            for(k=0; k<ms; k++)
                printf("%7d" , M_c[i][k]);
            }//execution time
            printf("\n\n le temps sequenciel est de %f second\n", endtime-starttime);
    }
    printf("\n");
   
    MPI_Finalize();
}
