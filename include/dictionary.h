#ifndef DICT_H
#define DICT_H

typedef struct list dict;
void d_insert(dict *d, key k, char *element); // TODO: implement the key and element with char array
char* d_remove(dict *d, key k);
char** get_keys*(dict *d);
char* find(dict *d, key k);
int size(dict *d);

#endif
