# Commands
### A full list of commands in Jazz
### From BF:
- `>`: Move pointer to the right by 1 cell
- `<`: Move pointer to the left by 1 cell
- `.`: Print ASCII char corresponding to current cell value (%256, so it wraps)
- `,`: Take a single character as input, and assign its value to the current cell
- `+`: Increment current cell value
- `-`: Decrement current cell value
- `[`: If current cell is 0, continue reading from corresponding `]`
- `]`: If current cell is non-zero, jump back to corresponding `[`

### Jazz Specific:
- `^`: Move pointer up by 1 cell
- `v`: Move pointer down by 1 cell
- `!`: Print out integer value of current cell, unformatted
- `#`: Start/end comment; interpreter ignores what's between two of these
- `{00-ff}`: Insert a specific value into current cell (reads hex)
- `"..."`: Assign characters between the quote marks into the matrix; substitute for long chains of `{..}>{..}>`

### Stack based Commands:
- `0-9`: Set stack index  

**Procedures:**
- `(`: Start reading procedure to stack index of proc stack
- `)`: Procedure end
- `:`: Call procedure at current stack index of proc stack
- `;`: Call procedure at current stack index of proc stack in temporary matrix with permanent memory and direction of flow carried over

**Permanent Memory:**
- `@`: Copy stack index of memory register to current cell
- `~`: Copy current cell to stack index of memory register
- `$`: Exchange current cell with stack index of memory register

### Directional Commands:
Direction of flow defaults to direction of last pointer movement command. Bear in mind that flow is static, so when it's set in a procedure, it's changed in the main program when the procedure is called, no matter how it's called (making `(>|<|^|v);` a good shorthand for changing the flow without moving the pointer).

- `c`: Copy previous cell to current cell
- `x`: Exchange current cell with previous cell
- `a`: Add previous cell to current and put resulting value in next cell
- `s`: Subtract previous cell from current (or current from previous) and put resulting value in next cell 
- `m`: Multiply previous cell by current cell, and put resulting value in next cell
- `d`: Integer divide previous cell by current cell (or vice versa), and put resulting value in next cell

Note that the result of `s` is always positive and the result of `d` is never 0.
