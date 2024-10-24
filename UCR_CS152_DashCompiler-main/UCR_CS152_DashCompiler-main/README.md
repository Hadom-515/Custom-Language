# CS152 - DASH Language

Author(s): Danin Namiranian, Abhinav Ramachandran, TianCheng Zhao, Hunter Adomitis

# Language Features

| Language Feature   | Code Example          |
| ------------------ | --------------------- |
| Add                | `x + y`               |
| Sub                | `x - y`               |
| Multiply           | `x * y`               |
| Divide             | `x / y`               |
| Modulus            | `x % y`               |
| Less Than          | `x < y`               |
| Less Than Equal    | `x <= y`              |
| Equality           | `x === y`             |
| Not Equality       | `x != y`              |
| Greater Than       | `x > y`               |
| Greater Than Equal | `x >= y`              |
| Write              | `prt(x)`              |
| Read               | `read(x)`             |
| Arrays             | `int[8] array`        |
| Comment            | `# This is a comment` |

# Table of Symbols

| Symbol               | Token Name                 |
| -------------------- | -------------------------- |
| `func`               | FUNC DECLARATION           |
| `return`             | RETURN TOKEN               |
| `int`                | INT DECLARATION            |
| `prt`                | PRINT KEYWORD              |
| `read`               | READ KEYWORD               |
| `while`              | LOOP KEYWORD               |
| `if`                 | IF KEYWORD                 |
| `else`               | ELSE KEYWORD               |
| `break`              | BREAK KEYWORD              |
| `continue`           | CONTINUE KEYWORD           |
| `;`                  | SEMICOLON                  |
| `,`                  | COMMA                      |
| `(`                  | LEFT PAREN                 |
| `)`                  | RIGHT PAREN                |
| `{`                  | LEFT CURLY                 |
| `}`                  | RIGHT CURLY                |
| `[`                  | LEFT BRACKET               |
| `]`                  | RIGHT BRACKET              |
| `+`                  | ADDITION OPERATOR          |
| `-`                  | SUBTRACTION OPERATOR       |
| `*`                  | MULTIPLICATION OPERATOR    |
| `/`                  | DIVISION OPERATOR          |
| `%`                  | MODULUS OPERATOR           |
| `=`                  | ASSIGNMENT OPERATOR        |
| `<`                  | LESS                       |
| `<=`                 | LESS EQUAL                 |
| `>`                  | GREATER                    |
| `>=`                 | GREATER EQUAL              |
| `===`                | EQUALITY                   |
| `!=`                 | NOT EQUAL                  |
| (IDENTIFIER)         | IDENTIFIER                 |
| (NUMBER)             | NUMBER                     |
| (COMMENT)            | [Ignored]                  |
| (WHITESPACE)         | [Handled Internally]       |
| (INVALID IDENTIFIER) | ERROR: Invalid Identifier  |
| . (Any other)        | ERROR: Unrecognized Symbol |
