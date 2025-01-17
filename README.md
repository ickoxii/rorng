# Random Loadout Generator (`rorng`)

## Overview
The `rorng` project is a command-line utility designed to generate random loadouts for survivors, complete with random abilities. This can be useful for players looking to add variety or unpredictability to their gameplay.

## Features
- Randomly selects a survivor from a predefined list.
- Generates random abilities for primary, secondary, utility, and special slots.
- Handles special cases for specific survivors (e.g., "MUL-T" and "Captain").
- Configurable to generate multiple loadouts in a single run.

## Prerequisites
- macOS with a C compiler (e.g., `gcc` or `clang`).

## Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd <repository_folder>
   ```

2. Build the program using the provided `Makefile`:
   ```bash
   make
   ```

3. The compiled binary will be available as `rorng` in the project directory.

## Usage
Run the program with the following syntax:
```bash
./rorng [-n <number_of_loadouts>] [-h]
```

### Options:
- `-n <number_of_loadouts>`: Specify the number of random loadouts to generate (default is 1).
- `-h`: Display the help message and usage instructions.

### Examples:
1. Generate a single random loadout:
   ```bash
   ./rorng
   ```

2. Generate 5 random loadouts:
   ```bash
   ./rorng -n 5
   ```

3. Display the help message:
   ```bash
   ./rorng -h
   ```

## File Structure
- **`survivors.h`**: Contains the list of survivors and their abilities.
- **`rorng.c`**: The main program logic.
- **`Makefile`**: Automates the compilation process for macOS.

## Special Cases
- **MUL-T**: Can randomly generate two primary abilities.
- **Captain**: Can randomly generate two special abilities.

## Notes
- The program uses the current system time and CPU cycles to seed the random number generator for high fidelity randomness.
- The output is printed to the console for easy access.

## Contributing
Contributions are welcome! If you'd like to contribute:
1. Fork the repository.
2. Create a feature branch.
3. Submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).

## Author
Developed by Icko Iben.
