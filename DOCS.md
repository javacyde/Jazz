# Commands
### A full list of commands in Jazz
**From BF:**
- `>`: Moves pointer to the right by 1 cell
- `<`: Moves pointer to the left by 1 cell
- `.`: Prints ASCII char code of current cell value
- `,`: Takes a single character as input, and assigns its value to the current cell
- `+`: Increment current cell value
- `-`: Decrement current cell value
- `[`: If current cell is 0, continue reading from corresponding `]`
- `]`: If current cell is non-zero, jump back to corresponding `[`

**Jazz specific:**
- `^` Moves pointer up by 1 cell
- `v` Moves pointer down by 1 cell
- `!` Prints out integer value of current cell, unformatted
- `#` Start/end comment, interpreter ignores what's between two of these
- `{00-ff}` Inserts a specific value into current cell (reads hex)
- `"..."` Assigns characters between the quote marks into the matrix; substitute for long chains of `{..}>{..}>`

**Procedures:**
- `0-9` Set stack index
- `(` Start reading procedure to stack index
- `)` Procedure end
- `:` Call procedure at current stack index
- `;` Call procedure at current stack index in temporary matrix