#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "enigma.h"
#include "crack_enigma.h"
#include "mappings.h"

#define MAX_MESSAGE_SIZE 100

static void print_usage(void);

static int main_encrypt(int argc, char const *argv[]);
static int main_crack(int argc, char const *argv[]);
static void load_file(char *filename, char *message);
static void load_bigrams(char *bigrams_filename, double **bigrams);

static void print_usage(void)
{
    printf("Usage: To encrypt a message: enigma -e <message> <rotor 1 index> <rotor 1 state> [<rotor 2 index> <rotor 2 state> ...] <reflector index>\n");
    printf("       To crack the machine: enigma -c <encrypted filename> <bigrams filename> <encrypted message>\n");
}

static void load_file(char *filename, char *tofill)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    int i = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            tofill[i] = c;
            i++;

            if (i == MAX_MESSAGE_SIZE)
            {
                break;
            }
        }
    }
    tofill[i] = '\0';

    fclose(file);

    return;
}

static void load_bigrams(char *bigrams_filename, double **bigrams)
{
    FILE *file = fopen(bigrams_filename, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: could not open file %s\n", bigrams_filename);
        exit(1);
    }

    // Each line is formatted as "aa 0.1234"
    char c1, c2;
    double freq;
    while (fscanf(file, "%c%c %lf\n", &c1, &c2, &freq) != EOF)
    {
        bigrams[c1 - 'a'][c2 - 'a'] = freq;
    }

    fclose(file);
}

static int main_encrypt(int argc, char const *argv[])
{
    // Check the number of arguments, argc should be at least 5 and even
    if (argc < 6 || argc % 2 == 1)
    {
        print_usage();
        return 1;
    }

    // Get the message
    char *message = (char *)argv[2];

    // Get the number of rotors
    int num_rotors = (argc - 3) / 2;

    // Get the rotor mapping tables and states
    char **rotor_tables = malloc(num_rotors * sizeof(char *));
    if (rotor_tables == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int *rotor_states = malloc(num_rotors * sizeof(int));
    if (rotor_states == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < num_rotors; i++)
    {
        int index = 3 + 2 * i;
        int rotor_index = atoi(argv[index]);
        int rotor_state = atoi(argv[index + 1]);

        if (rotor_index == 0 && strcmp(argv[index], "0") != 0)
        {
            printf("Invalid rotor index: should be a number, got %s\n", argv[index]);
            print_usage();
            return 1;
        }

        if (rotor_state == 0 && strcmp(argv[index + 1], "0") != 0)
        {
            printf("Invalid rotor state: should be a number, got %s\n", argv[index + 1]);
            print_usage();
            return 1;
        }

        if (rotor_index >= NUM_POSSIBLE_ROTORS)
        {
            printf("Invalid rotor index: should be < %u, got %u\n", NUM_POSSIBLE_ROTORS, rotor_index);
            print_usage();
            return 1;
        }

        if (rotor_state >= NUM_LETTERS)
        {
            printf("Invalid rotor state: should be < %u, got %u\n", NUM_LETTERS, rotor_state);
            print_usage();
            return 1;
        }

        rotor_tables[i] = ROTOR_TABLES[rotor_index];
        rotor_states[i] = rotor_state;
    }

    // Get the reflector mapping table
    int reflector_index = atoi(argv[argc - 1]);
    if (reflector_index == 0 && strcmp(argv[argc - 1], "0") != 0)
    {
        printf("Invalid reflector index: should be a number, got %s\n", argv[argc - 1]);
        print_usage();
        return 1;
    }

    if (reflector_index >= NUM_POSSIBLE_REFLECTORS)
    {
        printf("Invalid reflector index: should be < %u, got %u\n", NUM_POSSIBLE_REFLECTORS, reflector_index);
        print_usage();
        return 1;
    }

    char *reflector_table = REFLECTOR_TABLES[reflector_index];

    // Create the enigma machine
    Enigma *enigma = enigmaCreate(num_rotors, rotor_tables, rotor_states, reflector_table);

    // Free the rotor mapping tables and states
    free(rotor_tables);
    free(rotor_states);

    // Encrypt the message
    char *encrypted = calloc(strlen(message) + 1, sizeof(char));
    enigmaEncrypt(enigma, message, encrypted);

    // Print the encrypted message
    printf("%s\n", encrypted);

    // Free the enigma machine
    enigmaFree(enigma);
    free(encrypted);

    return 0;
}

static int main_crack(int argc, char const *argv[])
{
    // Check the number of arguments
    if (argc != 5)
    {
        print_usage();
        return 1;
    }

    // Get the filename of the encrypted message
    char *filename = (char *)argv[2];

    // Get the bigrams filename
    char *bigrams_filename = (char *)argv[3];

    // Get the encrypted message
    char *encrypted_message = (char *)argv[4];

    // Load the encrypted text
    char encrypted[MAX_MESSAGE_SIZE + 1];
    load_file(filename, encrypted);

    // Load the bigrams
    double **bigrams = malloc(NUM_LETTERS * sizeof(double *));
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        bigrams[i] = malloc(NUM_LETTERS * sizeof(double));
    }

    load_bigrams(bigrams_filename, bigrams);

    // Crack the enigma machine
    Enigma *enigma = crack_enigma_full(encrypted, bigrams, 3);

    // Decrypt the message
    char *message = calloc(strlen(encrypted_message) + 1, sizeof(char));
    enigmaEncrypt(enigma, encrypted_message, message);

    // Print the encrypted and decrypted messages
    printf("Encrypted: %s\n", encrypted_message);
    printf("Decrypted: %s\n", message);

    // Free the enigma machine
    enigmaFree(enigma);

    // Free the bigrams
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        free(bigrams[i]);
    }
    free(bigrams);

    free(message);

    return 0;
}

int main(int argc, char const *argv[])
{
    // Check first argument to determine the mode
    if (argc == 1)
    {
        print_usage();
        return 1;
    }

    // Crack the machine
    if (strcmp(argv[1], "-c") == 0)
    {
        return main_crack(argc, argv);
    }

    // Encrypt a message
    else if (strcmp(argv[1], "-e") == 0)
    {
        return main_encrypt(argc, argv);
    }

    print_usage();
    return 1;
}
