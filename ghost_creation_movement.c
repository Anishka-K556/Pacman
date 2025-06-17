#include<raylib.h>
#include "globals.h"

void Drawghost(int x,int y,Color ghostcolor)
{   DrawCircle(x*tileSize+tileSize/2,y*tileSize+tileSize/2,12,ghostcolor);
    DrawRectangle(x*tileSize+tileSize/2-12,y*tileSize+tileSize/2,24,12,ghostcolor);
    DrawCircle(x*tileSize+tileSize/2-8,y*tileSize+tileSize/2+12,4,ghostcolor);
    DrawCircle(x*tileSize+tileSize/2,y*tileSize+tileSize/2+12,4,ghostcolor);
    DrawCircle(x*tileSize+tileSize/2+8,y*tileSize+tileSize/2+12,4,ghostcolor);
    DrawCircle(x*tileSize+tileSize/2-6,y*tileSize+tileSize/2-2,3,WHITE);
    DrawCircle(x*tileSize+tileSize/2+4,y*tileSize+tileSize/2-2,3,WHITE);
    DrawCircle(x*tileSize+tileSize/2-6,y*tileSize+tileSize/2-2,2,BLACK);
    DrawCircle(x*tileSize+tileSize/2+4,y*tileSize+tileSize/2-2,2,BLACK);

}

void UpdateGhost(int *gx, int *gy,int check)
{
    static int frameCounter = 0;
    static int moveSpeed = 10;

    int rand = GetRandomValue(1, 4);
    if (frameCounter >= moveSpeed) {
        if(check==2){
        if (rand == 1 && maze[*gy][*gx + 1] != 1 &&(*gx+1!=ghostpx) && (*gx+1!=ghostrx)){

            (*gx)++;
        }
        else if (rand == 2 && maze[*gy + 1][*gx] != 1 &&(*gy+1!=ghostpy) && (*gy+1!=ghostry)) {
            (*gy)++;
        }
        else if (rand == 3 && maze[*gy][*gx - 1] != 1 &&(*gx-1!=ghostpx) && (*gx-1!=ghostrx)) {
            (*gx)--;
        }
        else if (rand == 4 && maze[*gy - 1][*gx] != 1 &&(*gy-1!=ghostpy) && (*gy-1!=ghostry)) {
            (*gy)--;
        }
        }
        else if(check==1){
        if (rand == 1 && maze[*gy][*gx + 1] != 1 &&(*gx+1!=ghostgx) && (*gx+1!=ghostrx)){

            (*gx)++;
        }
        else if (rand == 2 && maze[*gy + 1][*gx] != 1 &&(*gy+1!=ghostgy) && (*gy+1!=ghostry)) {
            (*gy)++;
        }
        else if (rand == 3 && maze[*gy][*gx - 1] != 1 &&(*gx-1!=ghostgx) && (*gx-1!=ghostrx)) {
            (*gx)--;
        }
        else if (rand == 4 && maze[*gy - 1][*gx] != 1 &&(*gy-1!=ghostgy) && (*gy-1!=ghostry)) {
            (*gy)--;
        }
        }
        frameCounter = 0;
    } else {
        frameCounter++;
    }

}

void GhostChasePacman(int px, int py, int *gx, int *gy)
{
    static int frameCounter2 = 0;
    static int moveSpeed = 5;

    if (frameCounter2 >= moveSpeed)
    {
        if (px == *gx && abs(py - *gy) <= 10)
        {
            if (py < *gy)
            {
                if (canConsumeGhosts && maze[*gy + 1][*gx] != 1  &&(*gy+1!=ghostpy)&& (*gx+1!=ghostrx) )
                {
                    (*gy)++;
                }
                else if(!canConsumeGhosts && maze[*gy - 1][*gx] != 1 &&(*gy-1!=ghostpy)&&(*gy-1!=ghostry))
                {
                    (*gy)--;
                }
            }
            else if (py > *gy)
            {
                if(canConsumeGhosts&& maze[*gy - 1][*gx] != 1 &&(*gy-1!=ghostpy)&&(*gy-1!=ghostry))
                {
                    (*gy)--;
                }
                else if(!canConsumeGhosts&&maze[*gy + 1][*gx]!=1 &&(*gy-1!=ghostpy))
                {
                    (*gy)++;
                }
            }
        }
        else if (py == *gy && abs(px - *gx) <= 10)
        {
            if (px < *gx)
            {
                if(canConsumeGhosts && maze[*gy][*gx + 1] != 1&&(*gx+1!=ghostpx) && (*gx+1!=ghostrx))
                {
                    (*gx)++;
                }
                else if(!canConsumeGhosts && maze[*gy][*gx - 1]!= 1 &&(*gx-1!=ghostpx) && (*gx-1!=ghostrx))
                {
                    (*gx)--;
                }
            }
            else if (px > *gx)
            {
                if (canConsumeGhosts && maze[*gy][*gx - 1]!= 1&&(*gx-1!=ghostpx) && (*gx-1!=ghostrx))
                {
                    (*gx)--;
                }
                else if(!canConsumeGhosts && maze[*gy][*gx + 1] != 1 &&(*gx+1!=ghostpx) && (*gx+1!=ghostrx))
                {
                    (*gx)++;
                }
            }
        }
        else
        {
            UpdateGhost(gx, gy,2);
        }

        frameCounter2 = 0;
    }
    else
    {
        frameCounter2++;
    }
}

void GhostCollidePacman(Sound pacman_eaten,Sound ghost_eaten)
{   if(((pacmanX==ghostrx && ghostry == pacmanY)||(pacmanX==ghostpx && ghostpy == pacmanY)||(pacmanX==ghostgx && ghostgy == pacmanY)) && (!superPelletExists2))
    {   pacmanX=1;
        pacmanY=1;
        n--;
        PlaySound(pacman_eaten);
    }
    else if((pacmanX==ghostrx && ghostry == pacmanY)&& (superPelletExists2)&& pacmanX!=48 && pacmanY!=1)
    {   ghostrx=48;
        ghostry=1;
        score+=200;
        PlaySound(ghost_eaten);

    }
    else if((pacmanX==ghostpx && ghostpy == pacmanY)&& (superPelletExists2)&& pacmanX!=48 && pacmanY!=1)
    {   ghostpx=25;
        ghostpy=23;
        score+=200;
        PlaySound(ghost_eaten);
    }
    else if((pacmanX==ghostgx && ghostgy == pacmanY )&& (superPelletExists2)&& pacmanX!=48 && pacmanY!=1)
    {   ghostgx=14;
        ghostgy=13;
        score+=200;
        PlaySound(ghost_eaten);
    }
}

