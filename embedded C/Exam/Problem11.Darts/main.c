#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isInABoard(double boardX,double  boardY, double boardRadius, double shotX, double shotY);
int isInAHead(double headX, double headY, double headRadius, double shotX, double shotY);
int isInAArm(double topleftX, double topleftY, double bottomRihgtX, double bottomRightY, double shotX, double shotY);

int main(void)
{
    double boardX, boardY, boardRadius;
    double headX, headY, headRadius;
    double topleftX, topLeftY, bottomRightX, bottomRightY;
    int n;
    double shotX, shotY;
    int points = 0;
    int health = 100;
    int hitRatio;
    int success = 0;
    
    scanf("%lf %lf %lf", &boardX, &boardY, &boardRadius);
    scanf("%lf %lf %lf", &headX, &headY, &headRadius);
    scanf("%lf %lf %lf %lf", &topleftX, &topLeftY, &bottomRightX, &bottomRightY);
    scanf("%d", &n);
    
    int i;
    for (i = 1; i <= n; i++) 
    {
        scanf("%lf %lf", &shotX, &shotY);
        int inAArm = isInAArm(topleftX, topLeftY, bottomRightX, bottomRightY, shotX, shotY);
        int inABoard = isInABoard(boardX, boardY, boardRadius, shotX, shotY);
        int inAHead = isInAHead(headX, headY, headRadius, shotX, shotY);
        
        if (inABoard == 1 && 0 == inAArm && 0 == inAHead)
        {
            points += 50;
        }
        
        if (inABoard) 
        {
            success++;
        }

        
        if (inAArm == 1)
        {
            if (inABoard == 1) 
            {
                points += 25;
            }
            
            health -= 30;
        }
        
        if (inAHead == 1)
        {
           if (inABoard == 1) 
            {
                points += 25;
            }
           
            health -= 25;
        }

        if (health <= 0)
        {
            n = i;
            health = 0;
            
            break;
        }
    }

    hitRatio =(int)(100*success / n);
    
    printf("Points: %d\n", points);
    printf("Hit ratio: %d%%\n", hitRatio);
    printf("Bay Mile: %d", health);
    

    return 0;
}

int isInAArm(double topleftX, double topleftY, double bottomRihgtX, double bottomRightY, double shotX, double shotY)
{
    if (shotX < topleftX || shotX > bottomRihgtX || shotY > topleftY || shotY < bottomRightY) {
        
        return 0;
    }
    
    return 1;
}

int isInABoard(double boardX, double boardY, double boardRadius, double shotX, double shotY)
{
    double distance = sqrt((shotX - boardX)*(shotX - boardX) + (shotY - boardY)*(shotY - boardY));
    if (distance > boardRadius)
    {
        return 0;
    }
    
    return 1;
}

int isInAHead(double headX, double headY, double headRadius, double shotX, double shotY)
{
    double distance = sqrt((shotX - headX)*(shotX - headX) + (shotY - headY)*(shotY - headY));
    if (distance > headRadius)
    {
        return 0;
    }
    
    return 1;
}

