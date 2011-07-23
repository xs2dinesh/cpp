#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

struct Node 
{
  Node *prev, *next;
  int index;
  Node() : prev (0), next (0), index (-1)
  {}
};

typedef unordered_map<string, Node*> Hash;

Hash words;
Node  *start = NULL, *end = NULL;
unsigned int noOfWords = 0;
unsigned int smallestIndex = 0, smallestCount = -1 ;

void findSmallestSubString (string word, unsigned int indexInString)
{
  Hash::iterator nptr;
  bool checkForNewSmallest = false;
  
  /* its not their in words to check */
  if( (nptr=words.find(word)) == words.end() ) return ;
  
  if( nptr->second->index == -1 ) 
    noOfWords--; 
  
  nptr->second->index = indexInString;
  
  if( start == NULL ) start = nptr->second;
  else if( start == nptr->second) 
  {
    start = start->next;
    checkForNewSmallest = true;
  }
  
  if( end == NULL ) end = nptr->second;
  else if( end != nptr->second) 
  {
    Node *n = nptr->second;
    if( n->prev ) n->prev->next = n->next;
    if( n->next ) n->next->prev = n->prev;
    n->prev = end;
    end->next = n;
    end = n;
  }
  
  if( noOfWords == 0 && checkForNewSmallest ) 
  {
    if( smallestCount > end->index - start->index + 1 ) 
    {
      smallestIndex = start->index;
      smallestCount = end->index - start->index + 1;
    }
  }
}


int main () 
{
  unsigned int count = 0 ;
  string word;
  
  fstream cin ("smallestSubStringWithAllWords.in", ios::in ) ;
  
  cin >> noOfWords;
  count = noOfWords;
  
  while( count-- ) 
  {
    cin >> word;
    words[word] = new Node;
  }
 
  cin>>word;
  count = 1;

  while (!cin.eof())
  {
    findSmallestSubString(word, count);
    cin>>word;
    count++;
  }
  
  cin.close();
  
  if( smallestCount > 0 ) 
    cout<<"String starting from word at "<<smallestIndex<<" length "<< smallestCount
    <<" is the smallest substring."<<endl;
  
  return 0;
}


