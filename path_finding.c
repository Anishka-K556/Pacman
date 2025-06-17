#include<raylib.h>
#include<stdlib.h>
#include"globals.h"

typedef struct {
    int row, col;
} Point;

typedef struct Node {
    Point pt;
    struct Node *next;
} Node;

typedef struct {
    int x, y;
} Ghost;


int isValid(int row, int col) {
    return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS) && (maze[row][col] == 0 || maze[row][col] == 2)&& (row!=ghostgy || col!=ghostgx) &&(row!=ghostpy ||col!=ghostpx) ;
}

Node* createNode(Point pt) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->pt = pt;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node **head, Point pt) {
    Node *newNode = createNode(pt);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Point dequeue(Node **head) {
    if (*head == NULL) {
        Point nullPoint = {-1, -1};
        return nullPoint;
    }
    Node *temp = *head;
    *head = (*head)->next;
    Point pt = temp->pt;
    free(temp);
    return pt;
}

int isEmpty(Node *head) {
    return head == NULL;
}

int bfs(Point start, Point end, Point parent[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};
    Node *queue = NULL;

    enqueue(&queue, start);
    visited[start.row][start.col] = 1;
    parent[start.row][start.col] = (Point){-1, -1};

    while (!isEmpty(queue)) {
        Point current = dequeue(&queue);

        if (current.row == end.row && current.col == end.col) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = current.row + dRow[i];
            int newCol = current.col + dCol[i];

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = 1;
                parent[newRow][newCol] = current;
                enqueue(&queue, (Point){newRow, newCol});
            }
        }
    }
    return 0;
}

void tracePath(Point start, Point end, Point parent[ROWS][COLS], Point path[], int *pathLen) {
    Point current = end;
    *pathLen = 0;

    while (!(current.row == start.row && current.col == start.col)) {
        path[(*pathLen)++] = current;
        current = parent[current.row][current.col];
    }
    path[(*pathLen)++] = start;

    for (int i = 0; i < *pathLen / 2; i++) {
        Point temp = path[i];
        path[i] = path[*pathLen - 1 - i];
        path[*pathLen - 1 - i] = temp;
    }
}

void moveGhost(int *gy,int *gx) {

    static int ghostMoveTimer = 0;
    static int ghostMoveInterval = 30;

    ghostMoveTimer++;
    if (ghostMoveTimer >= ghostMoveInterval) {
        if(!canConsumeGhosts)
        {
            Point start = {*gy, *gx};
            Point end = {pacmanY, pacmanX};
            Point parent[ROWS][COLS];
            Point path[ROWS * COLS];
            int pathLen;

            if (bfs(start, end, parent)) {
                tracePath(start, end, parent, path, &pathLen);
                if (pathLen > 1) {
                    *gy = path[1].row;
                    *gx = path[1].col;
                }
            }
        }
        else
        {
            int newghosty=*gy;
            int newghostx=*gx;

            if(pacmanY<*gy && isValid(*gy+1,*gx))
            {
                newghosty++;
            }
            else if(pacmanY>*gy && isValid(*gy-1,*gx))
            {
                newghosty--;
            }

            if(pacmanX<*gx && isValid(*gy,*gx+1))
            {
                newghostx++;
            }
            else if(pacmanX>*gx && isValid(*gy,*gx-1))
            {
                newghostx--;
            }
            *gy=newghosty;
            *gx=newghostx;

        }
            ghostMoveTimer = 0;
    }
}

