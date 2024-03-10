# Commands
### A full list of commands in Jazz
**From BF:**  
- `>`: Moves pointer to the right by 1 cell
- `<`: Moves pointer to the left by 1 cell
- `.`: Prints ASCII char code of current cell value
- `,`: Takes a single character as input, and assigns its value to the current cell
- `[`: If current cell is 0, continue reading from corresponding `]`
- `]`: If current cell is non-zero, jump back to corresponding `[`

**Jazz specific:**
- `^` Moves pointer up by 1 cell
- `v` Moves pointer down by 1 cell
- `!` Prints out integer value of current cell, unformatted
- `#` Start/end comment, interpreter ignores what's between two of these
