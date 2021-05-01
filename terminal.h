#include <termios.h>

#define CTRL_KEY(k) ((k) & 0x1f)
#define MARY_VERSION "0.0.1"

//editor row. pointer to specific row
typedef struct erow {
	int size;
	char *chars;
} erow;

struct editorConfig {
	int cx, cy;
	int rowoff;
	int screenrows;
 	int screencols;
	int numrows;
	//array of erow struct for multiple lines. Needs initialized to NULL later
	erow *rows;
  	struct termios orig_termios;
};

// Map keypress to number high enough it doesn't conflict with character type
enum editorKey {
	ARROW_LEFT  = 1000,
	ARROW_RIGHT,
	ARROW_UP,
	ARROW_DOWN,
	DEL_KEY,
	HOME_KEY,
	END_KEY,
	PAGE_UP,
	PAGE_DOWN
};

#ifndef TERMINAL_H
#define TERMINAL_H

void die(const char *s);

void disableRawMode();

void enableRawMode();

int editorReadKey();

int getCursorPosition(int *rows, int *cols);

int getWindowSize(int *rows, int *cols);

void initEditor();

#endif