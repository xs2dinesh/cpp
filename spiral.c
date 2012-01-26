# include <stdio.h>
# include <stdlib.h>

# define PRINT(x,y) printf("%4d",matrix[(y)][(x)]);

void printNormal(int **matrix, const int size)
{
  int x,y ;
  
  for(y=0;y<size;y++)
  {
    for(x=0;x<size;x++)                   PRINT(x,y)
    
    printf("\n");
  }
}
  
/*
  Printing the matrix inside out.
  Spiral form
*/
  
void printSpiral(int **matrix, const int size)
{
  int iteration, x,y ;

  y = size>>1 ;
  x = y - 1;
  
  if( size & 0x1 )                        PRINT(y,y)

  for ( iteration = y ; iteration > 0 ; iteration--)
  {
    for (; y < size - x ;y++)             PRINT(x,y)

    for (x++, y--; x <=y ;x++)            PRINT(x,y)

    for (x--, y--; x >= size - y -1;--y)  PRINT(x,y)

    for (y++, x--; x >=y ;x--)            PRINT(x,y)
  }

  printf("\n");
}


/*
  Printing the matrix outside in.
  Helical form
*/

void printHelical(int **matrix, const int size)
{
  int iteration, x = 0 , y = 0 ;

  for ( iteration = size>>1 ; iteration > 0 ; iteration--)
  {
    for(;x < size - y - 1; x++)   PRINT(x,y)
    
    for(;y < x ; y++)             PRINT(x,y)

    for(;x > size - y - 1; x--)   PRINT(x,y)
      
    for(;y > x; y--)              PRINT(x,y)
    
    x++;y++;
  }
  
  if(size & 0x1)                  PRINT(x,y)
  
  printf("\n");
}


int main(int argc , char *argv[])
{
	int **matrix = NULL , size, x, y; 

  if(argc < 2)
  {
	 printf("Enter the size of matrix: ");
	 scanf("%d",&size);
	}
	else
	{
	 size = atoi(argv[1]);
	}
	
	if(size<=0)
	{
	 printf("The size entered is out of range.\n");
	 goto failure;
	}
	
  if((matrix = (int**) malloc(size * sizeof(int*)))==NULL)
  {
    perror(__FILE__ ": Allocating memory to 'matrix' ");
    goto failure;
  }
  
  matrix[0] = NULL;
  
  if((matrix[0] = (int*) malloc(size * size * sizeof(int)))==NULL)
  {
    perror(__FILE__ ": Allocating memory to 'matrix' ");
    goto failure;
  }
  
  for(x = 1;x < size ; x++)
    matrix[x] = matrix[x-1] + size;
    

  for(x = 0;x < size ; x++)
    for (y=0; y<size ;y++)
      matrix[x][y] = y + size * x;
  
   
  printf("\nMatrix is :\n");
	printNormal(matrix, size);

  printf("\nSpiral form is :\n");
  printSpiral(matrix, size);

  printf("\nHelical form is :\n");
  printHelical(matrix, size);

  free(*matrix);
  free(matrix);
   
	return 0;
	
failure:

  free(*matrix);
  free(matrix);
  
  return 1;  
}
