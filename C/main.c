//
//  main.c
//  Basic
//
//  Created by Junyoung Kim on 2023/10/25.
//

#include <stdio.h>

int map[5][5]={
    0,0,0,0,0,
    0,0,0,1,0,
    0,1,0,0,0,
    0,0,0,1,0,
    0,0,0,0,0
};
void maze(int row, int col);
int main()
{
    maze(0,0);
    return 0;
}


void maze(int row, int col)
{
    printf("(%d %d)", row, col);
    if(row==4 && col==4)                    //row 4 column 4 is a destination, condition to stop the program.
    {
        printf("\n");
        return ;
    }
    else
    {
        if(col+1<5&&map[row][col+1]==0)     //if the value you try to go is 0 next time, go.
        {
            maze(row,col+1);
        }
        if(row+1<5&&map[row+1][col]==0)
        {
            maze(row+1,col);
        }
        return ;
    }
};


