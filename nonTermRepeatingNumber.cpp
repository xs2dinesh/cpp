#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <sstream>
using namespace std;


int *remainderArray = NULL;
int divisor = 0;

string getDigitsAfterDecimal(int dividend  ) 
{
  string retval;
  int remainder;
  
  dividend = dividend * 10;
  remainder = dividend % divisor;
  
  if( remainder == 0 ) 
  {
    stringstream ss; ss << dividend / divisor ;
    return ss.str();
  }
  
  remainderArray[remainder]++;
  
  if(remainderArray[remainder] == 2 )
    return string("]");
  else
  {
    retval =  getDigitsAfterDecimal(remainder);
    stringstream ss;    ss<<dividend / divisor;
    retval = ss.str() + retval ; 
  }
    
  if(remainderArray[remainder] == 2 )
  {
    retval = "[" + retval;
  }
  return retval;
}

string getDecimal( int dividend ) 
{
  stringstream retval;
  int remainder = 0; 
  
  retval << dividend / divisor;
  remainder = dividend % divisor;
  if( remainder ) 
  {
    remainderArray = new int [divisor];
    memset(remainderArray, 0, divisor*sizeof(int));
    retval <<"."<<getDigitsAfterDecimal(remainder);
    delete []remainderArray;
  }
  return retval.str();
}

int main (int argc, char* argv[] ) 
{
  if( argc < 3 ) 
  {
    cout<<"USAGE: executable <dividend> <divisor>"<<endl;
    return -1;
  }
  
  int dividend = strtol(argv[1], NULL, 10);
  divisor = strtol(argv[2], NULL, 10);
  
  cout<< dividend <<"/"<<divisor <<"="
      <<getDecimal(dividend)<<endl;
  
  return 0;
}      
