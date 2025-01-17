/**
 * file: rorng.c
 * author: Icko Iben
 * last modified: 2025/01/16
 * */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

#include "survivors.h"

void usage(const char*);
const char *get_random_ability(const char*[], int);
void generate_random_loadout(void);

int main(int argc, char *argv[])
{
  struct timeval tv;
  const char *prog_name = "rorng";
  const char *opts = ":n:h";
  char opt;
  int n = 1;

#ifdef DEBUG
  srand(69);
#else
  gettimeofday(&tv, NULL);
  unsigned int seed = (tv.tv_sec * 1000000) ^ tv.tv_usec;
  srand(seed);
#endif

  // Get options
  while ((opt = getopt(argc, argv, opts)) != -1) {
    switch(opt) {
      case ':':
        fprintf(stderr, "Error: Option -%c requires an argument.\n", optopt);
        return 1;
      case 'n':
        n = atoi(optarg);
        break;
      case 'h':
        usage(prog_name);
        return 0;
      default:
        fprintf(stderr, "Error: unknown option -%c\n", optopt);
        return 1;
    }
  }

  for(int i = 0; i < n; ++i) {
    generate_random_loadout();
    printf("\n");
  }

  return 0;
}

/**
 * usage
 *
 * Displays the usage information for the program, including available options.
 *
 * Parameters:
 *   program_name: The name of the program to include in the usage message.
 *
 * Return:
 *   void
 */
void usage(const char *program_name) {
  printf("Usage: %s [-n <number_of_loadouts>] [-h]\n", program_name);
  printf("\nOptions:\n");
  printf("  -n <number_of_loadouts>  Generate the specified number of random loadouts (default: 1)\n");
  printf("  -h                       Display this help message\n");
}

/**
 * get_random_ability
 *
 * Selects a random ability from a list of abilities, considering only non-NULL entries.
 *
 * Parameters:
 *   abilities: Array of ability strings.
 *   max_options: The maximum number of abilities to consider.
 *
 * Return:
 *   A randomly selected ability string, or NULL if no valid abilities are present.
 */
const char *get_random_ability(const char *abilities[], int max_options)
{
  // Count number of non-NULL options
  int valid_count = 0;
  for (int i = 0; i < max_options; ++i) {
    if (abilities[i] != NULL) {
      valid_count++;
    } else {
      break;
    }
  }

  // Randomly pick one of the valid abilities
  if (valid_count > 0) {
    int random_index = rand() % valid_count;
    return abilities[random_index];
  }

  return NULL;
}

/**
 * generate_random_loadout
 *
 * Generates a random loadout for a randomly selected survivor, including abilities.
 *
 * Parameters:
 *   None
 *
 * Return:
 *   void
 */
void generate_random_loadout(void)
{
  int num_survivors = sizeof(survivors) / sizeof(survivors[0]);

  int survivor_index = rand() % num_survivors;
  Survivor selected_survivor = survivors[survivor_index];

  printf("Survivor: %s\n", selected_survivor.name);

  // Handle special case: MUL-T can have multiple primaries
  if (strcmp(selected_survivor.name, "MUL-T") == 0) {
    const char *primary1 =
      get_random_ability(selected_survivor.abilities.primary, MAX_ABILITIES);
    const char *primary2 =
      get_random_ability(selected_survivor.abilities.primary, MAX_ABILITIES);

    printf("  Primary:   %s, %s\n", primary1, primary2);
  } else {
    const char *primary =
      get_random_ability(selected_survivor.abilities.primary, MAX_ABILITIES);

    printf("  Primary:   %s\n", primary);
  }

  // Generate secondary
  const char *secondary =
    get_random_ability(selected_survivor.abilities.secondary, MAX_ABILITIES);
  printf("  Secondary: %s\n", secondary);

  // Generate utility
  const char *utility =
    get_random_ability(selected_survivor.abilities.utility, MAX_ABILITIES);
  printf("  Utility:   %s\n", utility);

  // Handle special case: Captain can have multiple specials
  if (strcmp(selected_survivor.name, "Captain") == 0) {
    const char *special1 =
      get_random_ability(selected_survivor.abilities.special, MAX_ABILITIES);
    const char *special2 =
      get_random_ability(selected_survivor.abilities.special, MAX_ABILITIES);

    printf("  Special:   %s, %s\n", special1, special2);
  } else {
    const char *special =
      get_random_ability(selected_survivor.abilities.special, MAX_ABILITIES);

    printf("  Special:   %s\n", special);
  }
}
