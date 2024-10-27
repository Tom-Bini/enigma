#ifndef _MAPPER_H_
#define _MAPPER_H_

#include <stdbool.h>

/**
 * @brief Allows to map a character to another character according to a mapping table.
 * 
 */
typedef struct Mapper_t Mapper;

/**
 * @brief Create a new Mapper.
 * 
 * @param mapping_table The mapping table.
 * @param state The initial state of the mapping table.
 * @return Mapper* The new Mapper.
 */
Mapper *mapperCreate(char *mapping_table, int state);

/**
 * @brief Free the memory allocated for the Mapper.
 * 
 * @param mapper The Mapper to free.
 */
void mapperFree(Mapper *mapper);

/**
 * @brief Map a character to another character.
 * 
 * @param mapper The Mapper.
 * @param input The input character.
 * @return char The output character.
 */
char mapperMap(Mapper *mapper, char input);

/**
 * @brief Shift the mapping table.
 * 
 * @param mapper The Mapper.
 * @return true If the mapping table just did a complete rotation (state has become 0).
 * @return false Otherwise
 */
bool mapperShift(Mapper *mapper);

/**
 * @brief Get the state of the Mapper.
 * 
 * @param mapper The Mapper.
 * @return int The state.
 */
int mapperGetState(Mapper *mapper);

/**
 * @brief Set the state of the Mapper.
 * 
 * @param mapper The Mapper.
 * @param state The new state.
 */
void mapperSetState(Mapper *mapper, int state);

#endif // _MAPPER_H_
