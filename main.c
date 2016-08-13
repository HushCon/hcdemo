#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "letters.h"

static void init_screen(void)
{
    initscr();
    noecho();  /* Do not echo user input to the screen */

    /* Green terminal color */
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
}

static char choose_hc(int row, int col)
{
    static int last;
    const char hc[] = "HUSHCON";

    if (rand() % 2)
      return ' ';

    last = (last + 1) % sizeof(hc);
    return hc[last];
}

static void put(int row, int col, char c)
{
    mvprintw(row, col, "%c", c);
    usleep(50);
    refresh();
}

static void stream(void)
{
    int r, c;
    for (r=0; r<LINES; ++r)
      for (c=0; c<COLS; ++c)
         put(r, c, choose_hc(r, c));
}

static void randfill(void)
{
    int i, j, total[1024][1024] = {0};

    for (i=0; i<LINES; ++i)
      for (j=0; j<COLS; ++j) {
          const int c = rand() % COLS;
          const int r = rand() % LINES;
          if (total[r][c])
              continue;
          put(r, c, choose_hc(r, c));
          total[r][c] = 1;
      }
}

static void print_letter(char letter, int scale)
{
    int mid_r, mid_c, r, c, siz_r, siz_c;

    /* Default is 3x5 */
    siz_c = 3 * scale;
    siz_r = 5 * scale;

    /* Find middle of screen for 3x5 letter */
    mid_c = (COLS  / 2) - (siz_c / 2);
    mid_r = (LINES / 2) - (siz_r / 2);

    for (r=0; r<siz_r; ++r)
      for (c=0; c<siz_c; ++c)
        mvprintw(mid_r + r, mid_c + c,
                 "%c", letters[LETTER(letter)][r/scale][c/scale]);
    refresh();
}

static void disp_letters(void)
{
    int i;
    const char *words = "HUSHCON";
    for (i=0; i<strlen(words); ++i) {
        print_letter(words[i], 8);
        usleep(500000);
    }
}

int main(void)
{
    int i;
    static void (*fns[])(void) = {stream, disp_letters, randfill};
    static int n_fns = sizeof(fns) / sizeof(fns[0]);

    init_screen();

    /* Not infinite */
    for (i=0; i<(unsigned)~0; ++i)
        fns[rand() % n_fns]();

    endwin();
    return 0; 
}
