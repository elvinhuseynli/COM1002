#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//The function that returns the ceiling value of a number
int ceiling(float number)
{
    int inum = (int) number;
    if (number == (float)inum) 
    {
        return inum;
    }
    return inum + 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

//Mod function that finds modulus for floating-point number
int modulus(float first, float second)
{
    float remainder = 0.0f;
    remainder = first / second;
    if ((int) remainder == remainder)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

//Function that prints the current content
void gameboard_printer(int h, int w, char array[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            printf("%c", array[i][k]);
        }
        printf("\n");
    }
    printf("\n");    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

//Function that checks the neighbourhood
int neighbourhood_checker(int height, int width, char array[height][width], int c2, int c1, int *total, int *number)
{
    char main_brick = array[c2][c1];
    int counter = 0;
    int new_array[1000][2];
    int count = 0;
    int point = 0;
    if (main_brick == array[c2+1][c1+1]){
        counter++;
        new_array[count][0] = c2+1;
        new_array[count][1] = c1+1;
        count++;
    }
    if (main_brick == array[c2+1][c1]){
        counter++;
        new_array[count][0] = c2+1;
        new_array[count][1] = c1;
        count++;
    }
    if (main_brick == array[c2-1][c1+1]){
        counter++;
        new_array[count][0] = c2-1;
        new_array[count][1] = c1+1;
        count++;
    }
    if (main_brick == array[c2][c1+1]){
        counter++;
        new_array[count][0] = c2;
        new_array[count][1] = c1+1;
        count++;
    }
    if (main_brick == array[c2-1][c1-1]){
        counter++;
        new_array[count][0] = c2-1;
        new_array[count][1] = c1-1;
        count++;
    }
    if (main_brick == array[c2-1][c1]){
        counter++;
        new_array[count][0] = c2-1;
        new_array[count][1] = c1;
        count++;
    }
    if (main_brick == array[c2][c1-1]){
        counter++;
        new_array[count][0] = c2;
        new_array[count][1] = c1-1;
        count++;
    }
    if (main_brick == array[c2+1][c1-1]){
        counter++;
        new_array[count][0] = c2+1;
        new_array[count][1] = c1-1;
        count++;
    }
    ++counter;
    if (counter>=3){
        array[c2][c1] = ' ';
        for (int i = 0; i < count; i++)
        {
            array[new_array[i][0]][new_array[i][1]] = ' ';
        }
        if (counter>=5)
        {
            *number -= (counter-1);
            point = 100;
            *total+=point;        
            printf("You got %d points. Score: %d\n", point, *total);                    
            gameboard_printer(height, width, array);
        }
        else
        {
            *number-=(counter-1);
            point = counter*10;
            *total+=point;        
            printf("You got %d points. Score: %d\n", point, *total);                    
            gameboard_printer(height, width, array);
        } 
    }
    else
    {
        ++(*number);
        gameboard_printer(height, width, array);
    }    
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

//Main function
int main()
{   int height, width;
    scanf("%d %d", &width, &height);
    char array[height][width], shooter[1000];
    float shooter_angles[1000][2];
    char brick, shot_brick;
    int counter1 = 1, counter2 = 1, shooterpos1=0, shooterpos2=0;
    int count=0, total_score=0;
    float angle_x=0, angle_y=0;
    int number_of_bricks = 0;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
    
    //Creating the gameboard
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            if (i==0)
            {
                if (k==0 || k == width-1)
                {
                    array[i][k] = '|';
                }
                else
                {
                    array[i][k] = '~';
                }                                
            }
            else
            {
                if (k==0 || k == width-1)
                {
                    array[i][k] = '|';
                }
                else
                {
                    array[i][k] = ' ';
                }
            }
        }        
    }
    //gameboard_printer(height, width, array);
    scanf("%c", &brick);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
    //Getting Brick Colors
    scanf("%c", &brick);
    while (brick!='e')
    {
        if (brick=='\n')
        {
            counter2 = 1;
            counter1++;
        }
        else
        {            
            array[counter1][counter2] = brick;
            counter2++;
            if (brick != ' ')
            {
                number_of_bricks++;
            }
        }

        scanf("%c", &brick);
    }
    if (counter2==1)
    {
        counter2 = width-1;
    }
    scanf("%c", &brick);
    scanf("%c", &brick);
    scanf("%d %d", &shooterpos1, &shooterpos2);
    shot_brick = getchar();
    array[shooterpos2][shooterpos1] = '_';
    gameboard_printer(height, width, array);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
    //Getting inputs for shooting bricks
    scanf(" %c", &shot_brick);
    while (shot_brick!='q')
    {        
        scanf("%f %f", &angle_x, &angle_y);
        shooter[count] = shot_brick;
        shooter_angles[count][0] = angle_x;
        shooter_angles[count][1] = -angle_y;
        scanf(" %c", &shot_brick);    
        count++;    
    }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

    //To match the corresponding bricks with shooter bricks
    
    for (int h = 0; h < count && number_of_bricks!=0; h++)
    {
        float angle1 = shooter_angles[h][0], angle2 = shooter_angles[h][1];
        int count1 = shooterpos1, count2 = shooterpos2, exploded_bricks = 0, points = 0;
        int counting = 0;
        float ymove1 = 0, ymove=0.0f, slope=0.0f, xmove = 0.0f, xmove1 = 0;
        int change = 0;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
        //The first case
        if (angle1 == 0 && angle2 != 0)
        {
            while (array[count2-1][count1]==' ')
            {
                count2--;
            }
            if (array[count2-1][count1] != '|')
            {
                array[count2][count1] = shooter[h];
                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
            }
        }
        
//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

        //The second case
        else if (angle1 != 0 && angle2 != 0)
        {
            slope = angle2 / angle1;
            xmove = angle1/angle2;
            ymove = slope;

            //First slope condition

            if (slope<-1)
            {
                goto condition1;
                condition1:
                    if (change==0)
                    {
                        count1--;
                        count2--;
                    }
                    else
                    {
                        change = 0;
                    }
                    while (1)
                    {
                        if (modulus(xmove1, (int)(xmove1)) == 0)
                        {
                            if (array[count2-1][count1-1] == '~')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else if (array[count2-1][count1-1] != ' ')
                            {
                                if (array[count2-1][count1-1] != '|')
                                {
                                    array[count2][count1] = shooter[h];
                                    neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                    break;
                                }
                                else 
                                {
                                    xmove1=0;
                                    xmove = (-1) * xmove;
                                    change = 1;
                                    goto condition2;
                                }
                            }
                            else
                            {
                                xmove1+=xmove;
                                count1--;
                                count2--;
                            }
                        }
                        else if (fabs(xmove1) < ceiling(fabs(xmove1)) && fabs(xmove1+xmove) > ceiling(fabs(xmove1)))
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else if (array[count2-1][count1-1] != ' ')
                            {
                                array[--count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                xmove1+=xmove;
                                count1--;
                                count2--;
                            }                        
                        }
                        else
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;                                
                            }
                            else
                            {
                                xmove1+= xmove;
                                count2--;
                            }
                        }
                    }
            }
           
//--------------------------------------------------------------------------------------------------------------------------------------------------------------//

            //Second slope condition

            else if(slope>1)
            {
                goto condition2;
                condition2:
                    while (1)
                    {
                        if (modulus(xmove1, (int)(xmove1)) == 0)
                        {
                            if (array[count2-1][count1+1] == '~')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else if (array[count2-1][count1+1] != ' ')
                            {
                                if (array[count2-1][count1+1] != '|')
                                {
                                    array[count2][++count1] = shooter[h];
                                    neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                    break;
                                }
                                else
                                {
                                    xmove1=0;
                                    xmove1=(-1)*xmove;
                                    change = 1;
                                    goto condition1;
                                }
                            }
                            else
                            {
                                xmove1+=xmove;
                                count1++;
                                count2--;
                            }
                        }
                        else if (fabs(xmove1) < ceiling(fabs(xmove1)) && fabs(xmove1+xmove) > ceiling(fabs(xmove1)))
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else if (array[count2-1][count1+1] != ' ')
                            {
                                array[--count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                xmove1+=xmove;
                                count1++;
                                count2--;
                            }                        
                        }
                        else
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                xmove1+= xmove;
                                count2--;
                            }
                        }
                    }
            }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
            
            //Third slope condition
            
            else if (slope<0 && slope>-1)
            {
                goto condition3;
                condition3:
                    count1--;
                    count2--;
                    while (1)
                    {
                        if (modulus(ymove1, (int)(ymove1)) == 0)
                        {
                            if (array[count2-1][count1-1] != ' ')
                            {
                                if (array[count2-1][count1-1] != '|')
                                {
                                    array[count2][count1] = shooter[h];
                                    neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                    break;
                                }
                                else
                                {
                                    ymove1 = 0;
                                    ymove = (-1)*ymove;
                                    goto condition4;
                                }
                            }
                            else
                            {
                                ymove1+=ymove;
                                count1--;
                                count2--;
                            }
                        }
                        else if (fabs(ymove1) < ceiling(fabs(ymove1)) && fabs(ymove1+ymove) > ceiling(fabs(ymove1)))
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                if (array[count2-1][count1] != '|')
                                {
                                    array[count2][count1] = shooter[h];
                                    neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                    break;
                                }                                
                                else
                                {
                                    ymove1 = 0;
                                    ymove = (-1)*ymove;
                                    goto condition4;
                                }
                            }
                            else if (array[count2-1][count1-1] != ' ')
                            {
                                array[--count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                ymove1+=ymove;
                                count1--;
                                count2--;
                            }                        
                        }
                        else
                        {
                            if (array[count2][count1-1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                ymove1+= ymove;
                                count1--;
                            }
                        }
                    }                
            } 

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
            
            //Fourth slope condition
            
            else if (slope>0 && slope<1)
            {
                goto condition4;
                condition4:
                    count2--;
                    while (1)
                    {
                        if (modulus(ymove1, (int)(ymove1)) == 0)
                        {
                            if (array[count2-1][count1+1] != ' ')
                            {
                                if (array[count2-1][count1+1] != '|')
                                {
                                    array[count2][++count1] = shooter[h];
                                    neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                    break;
                                }
                                else
                                {
                                    ymove1 = 0;
                                    ymove = (-1)*ymove;
                                    count2--;
                                    count1++;
                                    goto condition3;
                                }
                            }
                            else
                            {
                                ymove1+=ymove;
                                count1++;
                                count2--;
                            }
                        }
                        else if (fabs(ymove1) < ceiling(fabs(ymove1)) && fabs(ymove1+ymove) > ceiling(fabs(ymove1)))
                        {
                            if (array[count2-1][count1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else if (array[count2-1][count1+1] != ' ')
                            {
                                array[--count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                ymove1+=ymove;
                                count1++;
                                count2--;
                            }                        
                        }
                        else
                        {
                            if (array[count2][count1+1] != ' ')
                            {
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                ymove1+= ymove;
                                count1++;
                            }
                        }
                    }                
            }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
            
            //Fifth slope condition
            
            else if (slope == -1)
            {
                goto condition5;
                condition5:
                    while (1)
                    {
                        if (array[count2-1][count1-1]!=' ')
                        {
                            if (array[count2-1][count1-1]!='|')
                            {                    
                                array[count2][count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                goto condition6;
                            }     
                        }
                        else
                        {
                            count2--;
                            count1--;
                        }
                                      
                    }
            }

//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
            
            //Sixth slope condition
            
            else if (slope == 1)
            {
                goto condition6;
                condition6:
                count2--;
                    while (1)
                    {
                        if (array[count2-1][count1+1]!=' ')
                        {
                            if (array[count2-1][count1+1]!='|')
                            {                    
                                array[count2][++count1] = shooter[h];
                                neighbourhood_checker(height, width, array, count2, count1, &total_score, &number_of_bricks);
                                break;
                            }
                            else
                            {
                                count2--;
                                goto condition5;
                            }     
                        }
                        else
                        {
                            count2--;
                            count1++;
                        }
                                      
                    }
            }
//--------------------------------------------------------------------------------------------------------------------------------------------------------------//
        }
    }
    printf("Game is over. Your score is %d!", total_score);


    return 0;
}