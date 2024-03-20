# Commands
### A full list of commands in Jazz
### From BF:
- `>`: Moves pointer to the right by 1 cell
- `<`: Moves pointer to the left by 1 cell
- `.`: Prints ASCII char code of current cell value
- `,`: Takes a single character as input, and assigns its value to the current cell
- `+`: Increment current cell value
- `-`: Decrement current cell value
- `[`: If current cell is 0, continue reading from corresponding `]`
- `]`: If current cell is non-zero, jump back to corresponding `[`

### Jazz Specific:
- `^`: Moves pointer up by 1 cell
- `v`: Moves pointer down by 1 cell
- `!`: Prints out integer value of current cell, unformatted
- `#`: Start/end comment; interpreter ignores what's between two of these
- `{00-ff}`: Inserts a specific value into current cell (reads hex)
- `"..."`: Assigns characters between the quote marks into the matrix; substitute for long chains of `{..}>{..}>`

### Stack based Commands:
- `0-9`: Set stack index  

**Procedures:**
- `(`: Start reading procedure to stack index of proc stack
- `)`: Procedure end
- `:`: Call procedure at current stack index of proc stack
- `;`: Call procedure at current stack index of proc stack in temporary matrix with permanent memory carried over
<!-- TODO -->
**Permanent Memory:**
- `@`: Copy stack index of memory register to current cell
- `~`: Copy current cell to stack index of memory register
- `$`: Exchange current cell with stack index of memory register

### Directional Commands:   
Any one of these can be followed by `(^|v|>|<)`, to set the direction of flow, otherwise it defaults to the last pointer movement command.

- `c`: Copy previous cell to current cell
- `x`: Exchange current cell with previous cell
- `a`: Add previous cell to current and put resulting value in next cell
- `s`: Subtract previous cell from current and put resulting value in next cell 
- `m`: Multiply previous cell by current cell, and put resulting value in next cell
- `d`: Integer divide previous cell by current cell, and put resulting value in next cell

Note that `s` and `d` both automatically run `x` before execution if previous cell is greater than the current cell.
