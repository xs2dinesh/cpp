#include <iostream>
#include <string.h>
using namespace std;


int main (int argc, char* argv[]) 
{
  
  if( argc < 2) 
  {
    cout<<"USAGE: executable <sequence of 0s and 1s"<<endl;
    return -1;
  }
  
  size_t length = strlen ( argv[1] );
  size_t *indexArray = new size_t [ length * 2 + 1 ];
  size_t sum = 0;
  size_t startingIndex = 0 , count = 0;
  
  memset ( indexArray, -1, (length<<2 -1)*sizeof(size_t) );
  
  for ( size_t i = 0 ; i < length ; ++i ) 
  {
    sum += argv[1][i] - '0'? 1 : -1;
    if ( indexArray[length + sum] == -1)
      indexArray[length + sum] = i;
    else if( i - indexArray[length + sum] > count )  
    {
      startingIndex = indexArray[length + sum] + 1;
      count = i - indexArray[length + sum];
    }
  }
  
  cout<< "Longest substring which has equal number of 0s and 1s"
  <<endl<<"is starting at "<<startingIndex<<" and is of length "
  <<count<<endl;
      
  return 0;
}
