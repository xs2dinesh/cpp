#include <iostream>
#include <string.h>
using namespace std;

int *table = 0;
int length = 0;

void create_table(char* str) {
  int pastChar = 0, index = 2;
  length = strlen(str);
  table = new int[length + 1];
  table[0] = -1, table[1] = 0;

  while (index < length) {
    if (str[index - 1] == str[pastChar]) {
      table[index++] = ++pastChar;
    } else if (pastChar) {
      pastChar = table[pastChar];
    } else {
      table[index++] = 0;
    }
  }
}

int search(char* string, char* token) {
  int pivot = 0;
  int index = 0;

  create_table(string);

  while (pivot + index < length) {
    if (string[pivot + index] == token[index]) {
      ++index;
      if (token[index] == '\0')
        return pivot + 1;
    } else if (table[pivot + index] > 0) {
      pivot = pivot + index - table[pivot + index];
      index = table[pivot + index];
    } else {
      ++pivot;
      index = 0;
    }
  }

  return length;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    cout << "usage : executable source-string sub-string-to-search" << endl;
    return -1;
  }

  cout << "source string : " << argv[1] << endl;
  cout << "sub string to search : " << argv[2] << endl;

  cout << "source string length = " << length << ", sub string found at : "
      << search(argv[1], argv[2]) << endl;
  return 0;
}
