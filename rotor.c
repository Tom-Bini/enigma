#include <stdlib.h>
#include "mapper.h"

#include "rotor.h"

#define NUM_LETTERS 26

struct Rotor_t
{
};

Rotor *rotorCreate(char *forward_table, int state)
{
    return NULL;
}

void rotorFree(Rotor *rotor)
{
    return;
}

Mapper *rotorGetForwardMapper(Rotor *rotor)
{
    return NULL;
}

Mapper *rotorGetBackwardMapper(Rotor *rotor)
{
    return NULL;
}

int rotorGetState(Rotor *rotor)
{
    return 0;
}

void rotorSetState(Rotor *rotor, int state)
{
    return;
}

char rotorMapForward(Rotor *rotor, char input)
{
    return input;
}

char rotorMapBackward(Rotor *rotor, char input)
{
    return input;
}

bool rotorShift(Rotor *rotor)
{
    return false;
}
