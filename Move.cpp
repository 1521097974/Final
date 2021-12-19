#include <iostream>
#include <termio.h>
#include <stdio.h>
#include "global.hpp"
#include "kbhit.hpp"


using namespace std;
void find()
{
    int mx,my;
    for(mx=0;mx<20;mx++)
    {
        for(my=0;my<20;my++)
        {
            if(Array[mx][my]==2)
            {
                i=mx;
                j=my;
            }
        }
    }
}

void up()
{
    if(Array[i-1][j]==0)
    {
        Array[i-1][j]=2;
        Array[i][j]=0;
        
    }
}
void down()
{
    if(Array[i+1][j]==0)
    {
        Array[i+1][j]=2;
        Array[i][j]=0;
    }
}
void left()
{
    if(Array[i][j-1]==0)
    {
        Array[i][j-1]=2;
        Array[i][j]=0;
    }
}
void right()
{
    if(Array[i][j+1]==0)
    {
        Array[i][j+1]=2;
        Array[i][j]=0;
    }
}
void move()
{
    //char input;
        //cin>>input;
        int input=scanKeyboard();
        find();
        switch (input)
			{
			case 119: up();break;
			case 97: left();break;
			case 115: down();break;
			case 100: right();break;
			case 27: exit(1) ;
			}
}
