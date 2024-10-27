#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#include "mappings.h"
#include "enigma.h"
#include "crack_enigma.h"

#define DEFAULT_SCORE -INFINITY

double score_text(char *text, double **bigrams)
{
    return DEFAULT_SCORE;
}

Enigma *crack_enigma_state(char *ciphertext, double **bigrams, Enigma *enigma)
{
    return NULL;
}

Enigma *crack_enigma_full(char *ciphertext, double **bigrams, int num_rotors)
{
    return NULL;
}
