#include <stdlib.h>

#include "mapper.h"

#define NUM_LETTERS 26

struct Mapper_t{
    char *emapping;
    char state;
};

Mapper *mapperCreate(char *mapping_table, int state){
    Mapper *Mapper = (Mapper *)malloc(sizeof(Mapper))

    if(!Mapper)
        return NULL;

    for(unsigned char i = 0; i != '\0'; i++){
        Mapper -> emapping[i] = malloc(sizeof(char) * 26);

        if(!g -> emapping[i]){
            for(unsigned char j = 0; j < i; j++)
                free(g -> emapping[j]);
            free(g -> emapping);
            free(g);
            return NULL;
        }
    }

    char temporary[26];

    const char english_letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for(int i = 0; i < 26; i++){
        int j = 0;
        while (english_letters[i] != mapping_table[j]){
            j++;
        }
        Mapper->emapping[i] = j - i;
    }

    return Mapper;
    //return NULL;
}

void mapperFree(Mapper *mapper)
{
    return;
}

char mapperMap(Mapper *mapper, char input)
{
    return input;
}

bool mapperShift(Mapper *mapper)
{
    return false;
}

int mapperGetState(Mapper *mapper)
{
    return (int)mapper->state;
}

void mapperSetState(Mapper *mapper, int state)
{
    char temp_letter;
    for(int i = 0; i < 26; i++){
        mapper->emapping[i];
    }
    mapper->state = (char)state;
    return;
} Chokbar de malde !
