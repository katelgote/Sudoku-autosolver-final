
#include<simplecpp>
#include "normal.h"
#include "diagonal.h"
#include "window.h"

int main()
{


    int temp;//TO CLOSE THE WINDOW AFTER THE SOLVED SUDOKU IS SHOWN
    initCanvas("sudoku autosolver",800,650);

    while (true)
    {
        Text t1(300,100,"SUDOKU AUTO-SOLVER");
        t1.setFill(FALSE);
        t1.setColor(COLOR(0,0,255));

        Rectangle a(300,170,120,50);
        a.setFill(FALSE);
        a.setColor(COLOR(255,0,0));

        Text t2(300,170,"START GAME");
        t2.setFill(FALSE);
        t2.setColor(COLOR(0,0,255));

        Rectangle s(300,240,120,50);
        s.setFill(FALSE);
        s.setColor(COLOR(255,0,0));

        Text t3(300,240,"EXIT");
        t3.setFill(FALSE);
        t3.setColor(COLOR(0,0,255));

        int v=getClick();
        int x=v/65536;
        int y=v%65536;
        if(x>=300-60&&x<=300+60&&y<=170+25&&y>=170-25)
        {
            temp=1;
            break;
        }
        if(x>=300-60&&x<=300+60&&y<=240+25&&y>=240-25)
        {
            temp=0;
            break;
        }

    }

    if(temp==0)
    {
        return 0;
    }

    if(temp==1)
    {
        while(true)
        {
            Text t1(300,84.375,"SELECT THE TYPE OF SUDOKU");
            t1.setFill(FALSE);
            t1.setColor(COLOR(0,0,255));

            Rectangle rec2(300,191.25,140,40);
            rec2.setFill(FALSE);
            rec2.setColor(COLOR(255,0,0));

            Text t2(300,191.25,"NORMAL SUDOKU");
            t2.setFill(FALSE);
            t2.setColor(COLOR(0,0,255));

            Rectangle rec3(300,247.5,140,40);
            rec3.setFill(FALSE);
            rec3.setColor(COLOR(255,0,0));

            Text t3(300,247.5,"DIAGONAL SUDOKU");
            t3.setFill(FALSE);
            t3.setColor(COLOR(0,0,255));

            Rectangle rec4(300,303.75,140,40);
            rec4.setFill(FALSE);
            rec4.setColor(COLOR(255,0,0));

            Text t4(300,303.75,"WINDOW SUDOKU");
            t4.setFill(FALSE);
            t4.setColor(COLOR(0,0,255));

            Rectangle rec5(300,360,140,40);
            rec5.setFill(FALSE);
            rec5.setColor(COLOR(255,0,0));

            Text t6(300,360,"EXIT");
            t6.setFill(FALSE);
            t6.setColor(COLOR(0,0,255));


            int v=getClick();
            int x=v/65536;
            int y=v%65536;
            if(x>=300-70&&x<=300+70&&y<=191.25+20&&y>=191.25-20)
            {
                temp=1;
                break;
            }

            if(x>=300-70&&x<=300+70&&y<=247.5+20&&y>=247.5-20)
            {
                temp=2;
                break;
            }
            if(x>=300-70&&x<=300+70&&y<=303.75+20&&y>=303.75-20)
            {
                temp=3;
                break;
            }
            if(x>=300-70&&x<=300+70&&y<=360+20&&y>=360-20)
            {
                temp=0;
                break;
            }


        }
    }

    if(temp==0)
    {
        return 0;
    }

    if(temp==1)
    {
        temp = Normal(input);
    }
    if(temp==2)
    {
        temp = Diagonal(input_d);
    }
    if (temp==3)
    {
        temp = Window(input_w);
    }

}
