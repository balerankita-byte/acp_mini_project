#include <ncurses.h>
#include <math.h>

#define ROWS 25
#define COLS 50

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            canvas[i][j] = '_';
}

void displayCanvas()
{
    clear();

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            mvaddch(i, j, canvas[i][j]);
        }
    }

    mvprintw(ROWS + 2, 0, "Press any key to return...");
    refresh();
    getch();
}

void drawRectangle(int x, int y, int w, int h)
{
    for(int i = y; i < y + h && i < ROWS; i++)
        for(int j = x; j < x + w && j < COLS; j++)
            canvas[i][j] = '*';
}

void drawLine(int x1, int y1, int x2, int y2)
{
    if(y1 == y2)
    {
        for(int i = x1; i <= x2 && i < COLS; i++)
            canvas[y1][i] = '*';
    }
    else if(x1 == x2)
    {
        for(int i = y1; i <= y2 && i < ROWS; i++)
            canvas[i][x1] = '*';
    }
}

void drawTriangle(int x, int y, int h)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = -i; j <= i; j++)
        {
            if(x + j >= 0 && x + j < COLS &&
               y + i >= 0 && y + i < ROWS)
                canvas[y + i][x + j] = '*';
        }
    }
}

void drawCircle(int cx, int cy, int r)
{
    for(int y = 0; y < ROWS; y++)
    {
        for(int x = 0; x < COLS; x++)
        {
            int dx = x - cx;
            int dy = y - cy;

            if(dx * dx + dy * dy <= r * r)
                canvas[y][x] = '*';
        }
    }
}

void deleteArea(int x, int y, int w, int h)
{
    for(int i = y; i < y + h && i < ROWS; i++)
        for(int j = x; j < x + w && j < COLS; j++)
            canvas[i][j] = '_';
}

int main()
{
    int choice;

    initscr();
    cbreak();
    noecho();

    initializeCanvas();

    while(1)
    {
        clear();

        mvprintw(1, 5, "2D GRAPHICS EDITOR");
        mvprintw(3, 5, "1. Draw Rectangle");
        mvprintw(4, 5, "2. Draw Line");
        mvprintw(5, 5, "3. Draw Triangle");
        mvprintw(6, 5, "4. Draw Circle");
        mvprintw(7, 5, "5. Delete Area");
        mvprintw(8, 5, "6. Display Picture");
        mvprintw(9, 5, "7. Clear Canvas");
        mvprintw(10, 5, "8. Exit");

        mvprintw(12, 5, "Enter Choice: ");
        refresh();

        scanw("%d", &choice);

        int x, y, w, h, r;
        int x1, y1, x2, y2;

        switch(choice)
        {
            case 1:
                mvprintw(14, 5, "x y width height: ");
                scanw("%d%d%d%d", &x, &y, &w, &h);
                drawRectangle(x, y, w, h);
                break;

            case 2:
                mvprintw(14, 5, "x1 y1 x2 y2: ");
                scanw("%d%d%d%d", &x1, &y1, &x2, &y2);
                drawLine(x1, y1, x2, y2);
                break;

            case 3:
                mvprintw(14, 5, "x y height: ");
                scanw("%d%d%d", &x, &y, &h);
                drawTriangle(x, y, h);
                break;

            case 4:
                mvprintw(14, 5, "center_x center_y radius: ");
                scanw("%d%d%d", &x, &y, &r);
                drawCircle(x, y, r);
                break;

            case 5:
                mvprintw(14, 5, "x y width height: ");
                scanw("%d%d%d%d", &x, &y, &w, &h);
                deleteArea(x, y, w, h);
                break;

            case 6:
                displayCanvas();
                break;

            case 7:
                initializeCanvas();
                break;

            case 8:
                endwin();
                return 0;

            default:
                mvprintw(16, 5, "Invalid Choice!");
                getch();
        }
    }

    endwin();
    return 0;
}
