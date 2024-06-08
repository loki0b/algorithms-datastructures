#ifndef DICT_H
#define DICT_H

typedef struct list dict;
typedef struct e entry;
void d_append(dict *d, entry *element); // TODO: implement the key and element with char array
char* d_remove(dict *d, char* key);
char** get_keys*(dict *d);
char* find(dict *d, char* key);
int size(dict *d);

#endif
