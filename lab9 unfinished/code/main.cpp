#include "hash.cpp"

int main()
{
  int key[] = {1, 2, 3, 3, 4, 5};
  int data[] = {123, 432, 523, 43, 423, 111};
  
  int size = sizeof(key)/sizeof(key[0]);

  HashTable h(size);

  for(int i = 0; i < size; i++)
  	h.insertItem(key[i], data[i]);

  h.displayHash();
}
