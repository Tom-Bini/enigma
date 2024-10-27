#ifndef _ENIGMA_H_
#define _ENIGMA_H_

#include "rotor.h"
#include "mapper.h"

/**
 * @brief Represents an Enigma machine.
 * 
 */
typedef struct Enigma_t Enigma;

/**
 * @brief Create a new Enigma machine.
 * 
 * @param num_rotors The number of rotors.
 * @param rotor_tables The rotor mapping tables.
 * @param rotor_states The initial states of the rotors.
 * @param reflector_table The reflector mapping table.
 * @return Enigma* The new Enigma machine.
 */
Enigma *enigmaCreate(int num_rotors, char **rotor_tables,
                     int *rotor_states, char *reflector_table);

/**
 * @brief Free the memory allocated for the Enigma machine.
 * 
 * @param enigma The Enigma machine to free.
 */
void enigmaFree(Enigma *enigma);

/**
 * @brief Encrypt a message with the Enigma machine.
 * 
 * @param enigma The Enigma machine.
 * @param input The message to encrypt.
 * @param tofill The buffer to fill with the encrypted message.
 */
void enigmaEncrypt(Enigma *enigma, char *input, char *tofill);

/**
 * @brief Get the number of rotors of the Enigma machine.
 * 
 * @param enigma The Enigma machine.
 * @return int The number of rotors.
 */
int enigmaGetNumRotors(Enigma *enigma);

/**
 * @brief Get a rotor of the Enigma machine.
 * 
 * @param enigma The Enigma machine.
 * @param index The index of the rotor.
 * @return Rotor* The rotor.
 */
Rotor *enigmaGetRotor(Enigma *enigma, int index);

/**
 * @brief Get the reflector of the Enigma machine.
 * 
 * @param enigma The Enigma machine.
 * @return Mapper* The reflector.
 */
Mapper *enigmaGetReflector(Enigma *enigma);

/**
 * @brief Get the rotor states of the Enigma machine.
 * 
 * @param enigma The Enigma machine.
 * @param tofill The buffer to fill with the rotor states.
 */
void enigmaGetRotorStates(Enigma *enigma, int *tofill);

/**
 * @brief Reset the Enigma machine to its initial state or to a new initial state.
 * 
 * @param enigma The Enigma machine.
 * @param rotor_states The new rotor states, or NULL to reset to the initial states.
 */
void enigmaReset(Enigma *enigma, int *rotor_states);

#endif // _ENIGMA_H_
