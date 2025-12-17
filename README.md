*This project has been created as part of the 42 curriculum by afournie*

# push_swap

## Description
push_swap is a sorting project that uses two stacks (A and B) and a restricted set of operations to sort a list of integers in ascending order. The program must output the shortest possible sequence of valid operations that sorts stack A. For very small inputs, specialized routines are used; for larger inputs, a bitwise radix strategy is applied.

## Instructions
- Requirements: a POSIX environment with `make` and a C compiler.

- Build:
```bash
make
```

- Run (examples):
```bash
./push_swap 3 2 1
./push_swap "3 2 1"
ARG="3 2 1 5 4"; ./push_swap $ARG
```

- Verify with the Linux checker (if available):
```bash
ARG="3 2 1 5 4"; ./push_swap $ARG | ./checker_linux $ARG
```

## Operations
- Swap: `sa`
- Push: `pa`, `pb`
- Rotate: `ra`
- Reverse rotate: `rra`

## Error Handling
If input is invalid (non-numeric values, duplicates, out-of-int-range values, or malformed lists), the program writes `Error\n` to stderr and exits.

## Project Structure
```
push_swap/
├── includes/       # Header files
├── libft/          # libft library
├── srcs/           # Source code
│   ├── operations/ # Stack operations
│   └── errors/     # Error handling
└── Makefile
```

## Resources
- Stack (abstract data type): https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- Radix sort (LSD): https://en.wikipedia.org/wiki/Radix_sort
- AI usage (GitHub Copilot, Claude.AI):
	- Drafted and polished this README (structure, wording, examples).
	- Help with understanding byte manipulation.
