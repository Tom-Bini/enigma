#include <stdlib.h>

#include "rotor.h"
#include "mapper.h"
#include "enigma.h"

// DEBUG
#include <stdio.h>

#define NUM_LETTERS 26

struct Enigma_t
{
};

Enigma *enigmaCreate(int num_rotors, char **rotor_tables,
                     int *rotor_states, char *reflector_table)
{
    return NULL;
}

void enigmaFree(Enigma *enigma)
{
    return;
}

void enigmaEncrypt(Enigma *enigma, char *input, char *tofill)
{
    return;
}

int enigmaGetNumRotors(Enigma *enigma)
{
    return 0;
}

Rotor *enigmaGetRotor(Enigma *enigma, int index)
{
    return NULL;
}

Mapper *enigmaGetReflector(Enigma *enigma)
{
    return NULL;
}

void enigmaGetRotorStates(Enigma *enigma, int *tofill)
{
    return;
}

void enigmaReset(Enigma *enigma, int *rotor_states)
{
    return;
}
