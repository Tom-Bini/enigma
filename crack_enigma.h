#ifndef _CRACK_ENIGMA_H
#define _CRACK_ENIGMA_H

#include "enigma.h"

/**
 * @brief Score a text by computing the log likelihood of the bigrams in the text.
 *
 * @param text the text to score
 * @param bigrams the bigram frequencies
 * @return double the score of the text
 */
double score_text(char *text, double **bigrams);

/**
 * @brief Crack an Enigma machine whose only the rotors initial states are unknown.
 *
 * @param ciphertext the ciphertext to crack
 * @param bigrams the bigram frequencies
 * @param enigma the Enigma machine
 * @return Enigma* the Enigma machine with the cracked initial states that obtained the best score
 */
Enigma *crack_enigma_state(char *ciphertext, double **bigrams, Enigma *enigma);

/**
 * @brief Crack an Enigma machine with unknown rotors and reflector.
 *
 * @param ciphertext the ciphertext to crack
 * @param bigrams the bigram frequencies
 * @param num_rotors the number of rotors
 * @return Enigma* the Enigma machine that obtained the best score
 */
Enigma *crack_enigma_full(char *ciphertext, double **bigrams, int num_rotors);

#endif // _CRACK_ENIGMA_H
