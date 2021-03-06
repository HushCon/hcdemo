/* 
 * 3x5 Letters
 */

#define LETTER(_l) (_l - 'A' + 10)

/* 0-9 digits, 10-35 letters A-Z */
static const char letters[46][5][3] = 
{
[LETTER('C')] = 
    {{'X', 'X', 'X'},
     {'X', ' ', ' '},
     {'X', ' ', ' '},
     {'X', ' ', ' '},
     {'X', 'X', 'X'}},
[LETTER('H')] =
    {{'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', 'X', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', 'X'}},
[LETTER('N')] = 
    {{' ', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', 'X', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', ' '}},
[LETTER('O')] = 
    {{'X', 'X', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', 'X', 'X'}},
[LETTER('S')] = 
    {{'X', 'X', 'X'},
     {'X', ' ', ' '},
     {'X', 'X', 'X'},
     {' ', ' ', 'X'},
     {'X', 'X', 'X'}},
[LETTER('U')] = 
    {{'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', ' ', 'X'},
     {'X', 'X', 'X'}},
};
