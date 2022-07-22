#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//The function that returns the prize according to positions

int prize_finder(int a[50][10], int p1, int p2, int count)
{
    int result = 0;
    for(int i=0; i<=count; i++)
    {
        if (a[i][0] == p1 && a[i][1] == p2)
        {
            result = a[i][2];
            break;
        }
    }
    return result;
}

//The function that draws maze content taking inputs from main func.

void maze_content(char array[50][50], int r, int c)
{
    for(int i=0; i<r; i++)
    {
        for(int k=0; k<c; k++)
        {
            printf("%c", array[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

//In the main function we take inputs and pass to array to pass to maze content drawer function

int main()
{    
    int height, length;
    int row, column, current_pos1, current_pos2, final_pos1, final_pos2;
    char array[50][50], command, current_char;
    char direction;
    int bonus = 0, bonus_amount=0, game_end = 0;
    int bonus_array[50][10], counter = 0, prize = 0;
    

    scanf("%d %d", &height, &length);
    //Creating default maze content
    for (int ik = 0; ik < height; ik++)
    {
        for (int il = 0; il < length; il++)
        {
            if (ik==0 || ik == height-1)
            {
                array[ik][il]='*';
            }
            else
            {
                if (il == 0 || il == length-1)
                {
                    array[ik][il] = '*';
                }
                else
                {
                    array[ik][il] = ' ';
                }
            }
        }
        
    }
    //maze_content(array, height, length);

    //Taking inputs to pass to array with switch-case method
    scanf("%c", &command);
    while (command!='e')
    {
        switch (command)
        {
            case 's':
                scanf("%d %d", &row, &column);
                array[row][column] = 'O';
                current_pos1 = row;
                current_pos2 = column;
                break;

            case 'f':
                scanf("%d %d", &row, &column);
                array[row][column] = ' ';
                final_pos1 = row;
                final_pos2 = column;
                break;
            case 'b':
                scanf("%d %d", &row, &column);
                array[row][column] = '*';
                break;
            case '$':
                scanf("%d %d %d", &row, &column, &bonus_amount);
                array[row][column] = '$';
                bonus_array[counter][0] = row;
                bonus_array[counter][1] = column;
                bonus_array[counter][2] = bonus_amount;
                counter++;
                break;
            case 'X':
                scanf("%d %d", &row, &column);
                array[row][column] = 'X';
                break;
        }
        scanf("%c", &command);
        
    }

    scanf("%c", &command);
    scanf("%c", &command);
    //Initial Maze Content
    maze_content(array, height, length);

    //Using direction commands and applying the data
    while ((scanf("%c", &direction)!=EOF) && game_end==0)
    {
        switch (direction)
        {

        //Up Command
        case 'u':
            current_char = array[current_pos1][current_pos2];
            if (array[current_pos1-1][current_pos2] == '*')
            {
                printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                maze_content(array, height, length);
            }
            else if(current_pos1-1 == final_pos1 && current_pos2 == final_pos2)
            {
                printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
                current_char = 'O';
                array[current_pos1][current_pos2] = ' ';
                current_pos1--;
                array[current_pos1][current_pos2] = current_char;
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1-1][current_pos2] == 'X')
            {
                printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1-1][current_pos2] == '$')
            {
                prize = prize_finder(bonus_array, current_pos1-1, current_pos2, counter);
                bonus += prize;
                printf("YOU GOT %d $.\n", prize);
                array[current_pos1][current_pos2] = ' ';
                current_pos1--;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            else if(array[current_pos1-1][current_pos2]== ' ')
            {
                array[current_pos1][current_pos2] = ' ';
                current_pos1--;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            break;

        //Down Command
        case 'd':
            current_char = array[current_pos1][current_pos2];
            if (array[current_pos1+1][current_pos2] == '*')
            {
                printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                maze_content(array, height, length);
            }
            else if(current_pos1+1 == final_pos1 && current_pos2 == final_pos2)
            {
                printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
                current_char = 'O';
                array[current_pos1][current_pos2] = ' ';
                current_pos1++;
                array[current_pos1][current_pos2] = current_char;
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1+1][current_pos2] == 'X')
            {
                printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1+1][current_pos2] == '$')
            {
                prize = prize_finder(bonus_array, current_pos1+1, current_pos2, counter);
                bonus += prize;
                printf("YOU GOT %d $.\n", prize);
                array[current_pos1][current_pos2] = ' ';
                current_pos1++;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            else if(array[current_pos1+1][current_pos2]== ' ')
            {
                array[current_pos1][current_pos2] = ' ';
                current_pos1++;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            break;

        //Right Command
        case 'r':
            current_char = array[current_pos1][current_pos2];
            if (array[current_pos1][current_pos2+1] == '*')
            {
                printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                maze_content(array, height, length);
            }
            else if(current_pos1 == final_pos1 && current_pos2+1 == final_pos2)
            {
                printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
                current_char = 'O';
                array[current_pos1][current_pos2] = ' ';
                current_pos2++;
                array[current_pos1][current_pos2] = current_char;
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1][current_pos2+1] == 'X')
            {
                printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1][current_pos2+1] == '$')
            {
                prize = prize_finder(bonus_array, current_pos1, current_pos2+1, counter);
                bonus += prize;
                printf("YOU GOT %d $.\n", prize);
                array[current_pos1][current_pos2] = ' ';
                current_pos2++;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            else if(array[current_pos1][current_pos2+1]== ' ')
            {
                array[current_pos1][current_pos2] = ' ';
                current_pos2++;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            
            break;

        //Left  Command
        case 'l':
            current_char = array[current_pos1][current_pos2];
            if (array[current_pos1][current_pos2-1] == '*')
            {
                printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
                maze_content(array, height, length);
            }
            else if(current_pos1 == final_pos1 && current_pos2-1 == final_pos2)
            {
                printf("CONGRATS! YOU GOT %d BONUS:)\n", bonus);
                current_char = 'O';
                array[current_pos1][current_pos2] = ' ';
                current_pos2--;
                array[current_pos1][current_pos2] = current_char;
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1][current_pos2-1] == 'X')
            {
                printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
                maze_content(array, height, length);
                game_end = 1;
            }
            else if(array[current_pos1][current_pos2-1] == '$')
            {
                prize = prize_finder(bonus_array, current_pos1, current_pos2-1, counter);
                bonus += prize;
                printf("YOU GOT %d $.\n", prize);
                array[current_pos1][current_pos2] = ' ';
                current_pos2--;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            else if(array[current_pos1][current_pos2-1]== ' ')
            {
                array[current_pos1][current_pos2] = ' ';
                current_pos2--;
                array[current_pos1][current_pos2] = 'O';
                maze_content(array, height, length);
            }
            
            break;

        //Quit Command
        case 'q':
            game_end = 1;
            printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
            maze_content(array, height, length);
            break;
        }
    }

    //When the player cannot reach the end of game after commands end up 
    if (game_end==0)
    {	
        printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
        maze_content(array, height, length);
    }
    return 0;
}
