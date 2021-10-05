#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DX 3

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 2) {
        return EXIT_FAILURE;
    }
    
    // Open file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    
    // Read file
    char** lines = NULL;
    int* lines_length = NULL;
    char* line_buffer = NULL;
    int line_count = 0;
    int max_line_length = 0;
    size_t line_buffer_size = 0;
    while (getline(&line_buffer, &line_buffer_size, fp) >= 0) {
        lines = realloc(lines, (line_count + 1) * sizeof(char*));
        lines_length = realloc(lines_length, (line_count + 1) * sizeof(int));
        
        lines[line_count] = line_buffer;
        lines_length[line_count] = line_buffer_size;
        
        line_count++;
        line_buffer = NULL;
        
        if (max_line_length < line_buffer_size / sizeof(char)) {
            max_line_length = line_buffer_size / sizeof(char);
        }
    }
    
    // Setup window
    WINDOW *win;
    int c = 0;
    
    initscr();
    noecho();
    cbreak();
    printw("File: %s", argv[1]);
    refresh();
    
    win = newwin(LINES - 2 * DX, COLS - 2 * DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    wmove(win, 1, 0);
    
    int current_line = 0;
    int current_column = 0;
    
    // Update window
    while(1) {
        werase(win);
        
        for (int i = 0; i < LINES - 2 * DX - 2 && i + current_line < line_count; i++) {
            wmove(win, i + 1, 0);
            char* line_to_show = NULL;
            if (strlen(lines[i + current_line]) > current_column) {
                line_to_show = lines[i + current_line] + current_column;
            } else {
                line_to_show = "";
            }
            wprintw(win, "  %d: %s", i + current_line + 1, line_to_show);
        }
        box(win, 0, 0);
        
        c = wgetch(win);
        if (c == 27) {
            break;
        }
        
        switch(c) {
            case ' ':
            case KEY_DOWN:
                if (current_line + 1 < line_count) {
                    current_line++;
                }
                break;
            case KEY_UP:
                if (current_line - 1 >= 0) {
                    current_line--;
                }
                break;
            case KEY_RIGHT:
                if (current_column + 1 < max_line_length) {
                    current_column++;
                }
                break;
            case KEY_LEFT:
                if (current_column - 1 >= 0) {
                    current_column--;
                }
                break;
            default:
                break;
        }
    }
    
    endwin();
    
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
    fclose(fp);
    
    return 0;
}
