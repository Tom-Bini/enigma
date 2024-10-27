#ifndef _ROTOR_H_
#define _ROTOR_H_

#include <stdbool.h>

#include "mapper.h"

/**
 * @brief Represents a rotor of the Enigma machine.
 * 
 */
typedef struct Rotor_t Rotor;

/**
 * @brief Create a new Rotor.
 * 
 * @param forward_table The forward mapping table.
 * @param state The initial state of the rotor.
 * @return Rotor* The new Rotor.
 */
Rotor *rotorCreate(char *forward_table, int state);

/**
 * @brief Free the memory allocated for the Rotor.
 * 
 * @param rotor The Rotor to free.
 */
void rotorFree(Rotor *rotor);

/**
 * @brief Get the forward Mapper of the Rotor.
 * 
 * @param rotor The Rotor.
 * @return Mapper* The forward Mapper.
 */
Mapper *rotorGetForwardMapper(Rotor *rotor);

/**
 * @brief Get the backward Mapper of the Rotor.
 * 
 * @param rotor The Rotor.
 * @return Mapper* The backward Mapper.
 */
Mapper *rotorGetBackwardMapper(Rotor *rotor);

/**
 * @brief Get the state of the Rotor.
 * 
 * @param rotor The Rotor.
 * @return int The state.
 */
int rotorGetState(Rotor *rotor);

/**
 * @brief Set the state of the Rotor.
 * 
 * @param rotor The Rotor.
 * @param state The new state.
 */
void rotorSetState(Rotor *rotor, int state);

/**
 * @brief Map a character to another character using the forward Mapper of the Rotor.
 * 
 * @param rotor The Rotor.
 * @param input The input character.
 * @return char The output character.
 */
char rotorMapForward(Rotor *rotor, char input);

/**
 * @brief Map a character to another character using the backward Mapper of the Rotor.
 * 
 * @param rotor The Rotor.
 * @param input The input character.
 * @return char The output character.
 */
char rotorMapBackward(Rotor *rotor, char input);

/**
 * @brief Shift the Rotor.
 * 
 * @param rotor The Rotor.
 * @return true If the Rotor just did a complete rotation (state has become 0).
 * @return false Otherwise
 */
bool rotorShift(Rotor *rotor);

#endif // _ROTOR_H_
