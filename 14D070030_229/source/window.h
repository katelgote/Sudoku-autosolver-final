

/* ************************     WINDOW SUDOKU   **************************************************************** */

#include<simplecpp>
int input_w[9][9],output_w[9][9];

//FUNCTION FOR CHECKING THAT GIVEN VALUE IS VALID FOR THAT BOX OR NOT
int inputvalue_w(int x,int y,int value)
{
    {
//scanning horizontally and vertically
        for(int i=0 ; i<9 ; i++)
        {
            if(value==output_w[x][i]||value==output_w[i][y])
                return 0;
        }

//scanning its own square
        for(int i=(x/3)*3 ; i<=((x/3)*3)+2 ; i++)
            for(int j=(y/3)*3 ; j<=((y/3)*3)+2 ; j++)
                if(value==output_w[i][j])
                    return 0;

//scanning in each  inside 4  boxes
        if(x>0 && x<4 && y>0 && y<4)
            for(int i=1 ; i<=3 ; i++)
                for(int j=1 ; j<=3 ; j++)
                    if(value==output_w[i][j])
                        return 0;


        if(x>4 && x<8 && y>0 && y<4)
            for(int i=5 ; i<=7 ; i++)
                for(int j=1 ; j<=3 ; j++)
                    if(value==output_w[i][j])
                        return 0;


        if(x>0 && x<4 && y>4 && y<8)
            for(int i=1 ; i<=3 ; i++)
                for(int j=5 ; j<=7 ; j++)
                    if(value==output_w[i][j])
                        return 0;

        if(x>4 && x<8 && y>4 && y<8)
            for(int i=5 ; i<=7 ; i++)
                for(int j=5 ; j<=7 ; j++)
                    if(value==output_w[i][j])
                        return 0;


    }
    return value;
}

//FUNCTION WHICH SOLVE THE GIVEN SUDOKU BY GIVIING INPUTS FROM 1 TO 9
//********* ((BACKTRACKING))******************

int solve_w(int x,int y)
{
    int temp;
    if(output_w[x][y]==0)    //MAKES CHANGES IFF BOX IS BLANK.*********
    {
        int i;
        for( i = 1; i<10; i++)
        {
            temp=inputvalue_w(x,y,i);
            if(temp>0)
            {
                output_w[x][y]=temp;   //  OUTPUT ARRAY STORES THE INSERTED VALUES

                if(x==8&&y==8)     // IF STARTING FROM (0,0) THE CHECKING OF LAST BOX COMES AND IS VALID IT RETURNS 1
                    return 1;
                else if(x==8)
                {
                    if(solve_w(0,y+1))   //IF AFTER INSERTING THE INPUTS IN A ROW ENDS THEN FUNCTION GOES TO NEXT ROW 1ST COLUMN.
                        return 1;
                }
                else
                {
                    if(solve_w(x+1,y))  //ELSE IT GOES TO NEXT BOX IN THE SAME ROW.
                        return 1;
                }
            }
        }


           //IF NO INPUT IS POSSIBLE +THEN i REACHES UPTO 9 AND THEN DUE TO i++ => i=10.
            /* ****************************************************************************************************
            WHEN THE FLOW OF CONTROL REACHES ... if(solve_d(x+1,y))....then again solve(x+1,y) is executed .
            now if there is no possible value to be inserted then new_i=10,and previous box is reset to 0 value as (output_d[x][y]!=input_d[x][y])
            now in previous loop i increases as.. 'if(solve_d(x+1,y))'... gives false value(0),
             this leads to next possible  temp value.
            if this also doesn't valid then solve(x-1,y) is executed. and their changes are made.
        This process is carried on.
            *************************************************************************************************** */

            if( i==10)
        {
            if(output_w[x][y]!=input_w[x][y])
                output_w[x][y]=0;
            return 0;
        }
    }

    if(x==8&&y==8)    // IF LAST BOX COMES AND IS VALID IT RETURNS 1
        return 1;

    else if(x==8)
    {
        if(solve_w(0,y+1))  //IF AFTER INSERTING THE INPUTS IN A ROW ENDS THEN FUNCTION GOES TO NEXT ROW 1ST COLUMN.
            return 1;
    }
    else
    {
        if(solve_w(x+1,y))
            return 1;
    }
}


//INITIALIZE  THE WINDOW SUDOKU TO 0 IN EVERY BOX.
int Window(int input_w[9][9])
{

    int temp;

    for(int i=0; i<=8; i++)
    {
        for(int j=0; j<=8; j++)
        {
            input_w[i][j]=0;
        }
    }

    //initCanvas("sudoku",800,650);

    Text in(150,20,"GIVE INPUTS");
    Text head(500,100,"WINDOW SUDOKU");
    head.setFill(FALSE);
    head.setColor(COLOR(0,150,200));

    //Rectangle*Dividers[9][9];
    //Beginning of loop for creating tiles

    Rectangle*Tiles[9][9];

    for(int i=0; i<=8; i++)
    {
        for(int j=0; j<=8; j++)
        {
            Tiles[i][j]=new Rectangle(55+30*i,55+30*j,30,30);

            if((i>=0&&i<=2&&j>=0&&j<=2)||(i>=3&&i<=5&&j>=3&&j<=5)||(i>=6&&i<=8&&j>=6&&j<=8)||(i>=6&&i<=8&&j>=0&&j<=2)||(i>=0&&i<=2&&j>=6&&j<=8))
            {
                Tiles[i][j]->setFill(false);
                Tiles[i][j]->setColor(COLOR(255,0,0));
            }
        }
    }

// RECTANGLE TO CREATE OUTER 9X9 BOX.

    Rectangle window_outer_box(175,175,270,270);
    window_outer_box.setFill(FALSE);
    window_outer_box.setColor(COLOR(0,0,0));

    Rectangle Normal1(175,175,271,271);
    Normal1.setFill(FALSE);
    Normal1.setColor(COLOR(0,0,200));

    Rectangle Normal2(175,175,272,272);
    Normal2.setFill(FALSE);
    Normal2.setColor(COLOR(0,0,200));


    //vertical lines
    Line l1(130,40,130,310);
    Line l2(220,40,220,310);
    //horizontal lines
    Line l3(40,130,310,130);
    Line l4(40,220,310,220);


    Line l10(131,41,131,311);
    Line l20(221,41,221,311);
    Line l30(41,131,311,131);
    Line l40(40,220,311,221);
    // TO MAKE INSIDE 4 RECTANGLES.

    Rectangle r1(115,115,88,88);
    r1.setFill(FALSE);
    r1.setColor(COLOR(255,0,0));

     Rectangle r10(115,115,87,87);
    r10.setFill(FALSE);
    r10.setColor(COLOR(0,0,255));

    Rectangle r2(235,115,88,88);
    r2.setFill(FALSE);
    r2.setColor(COLOR(255,0,0));

     Rectangle r20(235,115,87,87);
    r20.setFill(FALSE);
    r20.setColor(COLOR(0,0,255));

    Rectangle r3(115,235,88,88);
    r3.setFill(FALSE);
    r3.setColor(COLOR(255,0,0));

    Rectangle r30(115,235,87,87);
    r30.setFill(FALSE);
    r30.setColor(COLOR(0,0,255));


    Rectangle r4(235,235,88,88);
    r4.setFill(FALSE);
    r4.setColor(COLOR(255,0,0));

     Rectangle r40(235,235,87,87);
    r40.setFill(FALSE);
    r40.setColor(COLOR(0,0,255));

    // TO CREATE  BUTTONS FROM 1 TO 9
    Rectangle*Buttons[9];
    for(int i=0; i<9; i++)
    {
        Buttons[i]=new Rectangle(140+40*i,380,30,30);

        Buttons[i]->setFill(false);
        Buttons[i]->setColor(COLOR(200,20,200));
    }

//objects of type text for displaying numbers on the buttons

    Text p1(100+40*1,380,"1");
    Text p2(100+40*2,380,"2");
    Text p3(100+40*3,380,"3");
    Text p4(100+40*4,380,"4");
    Text p5(100+40*5,380,"5");
    Text p6(100+40*6,380,"6");
    Text p7(100+40*7,380,"7");
    Text p8(100+40*8,380,"8");
    Text p9(100+40*9,380,"9");


//SOLVE BUTTON FOR CALLING PROGRAM FOR THE SOLUTION OF GIVEN SUDOKU.

    Rectangle Solv(550,200,120,50);
    Text sol(550,200,"SOLVE");

    // INSTRUCTIONS FOR PLAYING SUDOKU
    int startoflines=380;
    Text instruction(startoflines,440,"INSTRUCTIONS");
    instruction.setFill();
    instruction.setColor(COLOR(200,0,0));

    Text lineL1(startoflines,480,"First click in one of the box in 9x9 grid where you want to give inputs");
    Text lineL2(startoflines,500,"Then click on one of 1 to 9 buttons shown below the 9X9 grid");
    Text lineL3(startoflines,520,"After giving inputs click on SOLVE button on right side of canvas");
    Text lineL4(startoflines,540,"Then solution is displayed ");
    Text lineL5(startoflines,560," Then Click once again anywhere on the Canvas to Exit");



//WHILE LOOP FOR TAKING ANY NO. OF INPUTS AND SHOWING OUTPUTS
    while(1)
    {


        int v=getClick();
        int x=v/65536;
        int y=v%65536;


        for(int j=0; j<9; j++)
        {
            for(int i=0; i<9; i++)
            {
                //click on a particular box.
                // starting from [0][0] box having Center (55,55).
                // CHECKING EACH BOX THAT CLICK IS DONE IN IT OR NOT
                if(55+30*i-15<x && 55+30*i+15>x && 55+30*j-15<y && 55+30*j+15>y)

                {

//SECOND GETCLICK FOR GIVING VALUE TO THE EARLIER CLICKED BOX

                    int buttonclick=getClick();
                    int x1=buttonclick/65536;
                    int y1=buttonclick%65536;
                    if(140-15<x1 && x1<140+15 && 380-15<y1 &&y1<380+15)
                    {
                        input_w[i][j]=1;
                        p1.imprint();
                        p1.moveTo(55+30*i,55+30*j);
                        p1.imprint();
                    }
                    else if(180-15<x1&& x1<180+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=2;
                        p2.imprint();
                        p2.moveTo(55+30*i,55+30*j);
                        p2.imprint();

                    }
                    else if(220-15<x1 && x1<220+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=3;
                        p3.imprint();
                        p3.moveTo(55+30*i,55+30*j);
                        p3.imprint();
                    }
                    else if(260-15<x1 && x1<260+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=4;
                        p4.imprint();
                        p4.moveTo(55+30*i,55+30*j);
                        p4.imprint();
                    }
                    else if(300-15<x1 && x1<300+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=5;
                        p5.imprint();
                        p5.moveTo(55+30*i,55+30*j);
                        p5.imprint();
                    }
                    else if(340-15<x1 && x1<340+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=6;
                        p6.imprint();
                        p6.moveTo(55+30*i,55+30*j);
                        p6.imprint();

                    }
                    else if(380-15<x1 && x1<380+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=7;
                        p7.imprint();
                        p7.moveTo(55+30*i,55+30*j);
                        p7.imprint();
                    }
                    else if(420-15<x1 && x1<420+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=8;
                        p8.imprint();
                        p8.moveTo(55+30*i,55+30*j);
                        p8.imprint();
                    }
                    else if(460-15<x1 && x1<460+15 && 380-15<y1 && y1<380+15)
                    {
                        input_w[i][j]=9;
                        p9.imprint();
                        p9.moveTo(55+30*i,55+30*j);
                        p9.imprint();

                    }

                    else
                    {
                        i--;
                    }


                }
            }

        }

        //IF SSECOND GETCKILCK IS ON SOLVE BUTTON

        if(x>550-60 && x<550+60 && y>200-25 && y<200+25)
        {
            cout<<"your given Sudoku is"<<endl;
            for(int j=0; j<9; j++)
            {
                for(int i=0; i<9; i++)
                {
                    cout<<input_w[i][j]<<" ";
                }
                cout<<endl;
            }

            in.hide();     //TO HIDE TEXT "GIVE INPUTS"

            //COPYING OUTPUT ARRAY TO INPUT ARRAY.

            for(int j=0; j<9; j++)

            {
                for(int i=0; i<9; i++)
                {
                    output_w[i][j]=input_w[i][j];
                }
            }

            if(solve_w(0,0)==1)  //IF SOLUTION IS POSSIBLE
            {
                cout<<endl;
                cout<<"The Solution for given sudoku is"<<endl<<endl;


                //SHOWS SOLUTION GRID
               Text solutions(140,340," SOLUTION PUZZLE");
                for(int j=0; j<9; j++)
                {
                    for(int i=0; i<9; i++)
                    {
                        int canvas_output_w =output_w[i][j] ;
                        switch(canvas_output_w)
                        {
                        case 1 :
                        {
                            output_w[i][j]=1;
                            cout<<output_w[i][j]<<" ";
                            p1.moveTo(55+30*i,55+30*j);
                            p1.imprint();
                            break;
                        }
                        case 2 :
                        {
                            output_w[i][j]=2;
                            cout<<output_w[i][j]<<" ";
                            p2.moveTo(55+30*i,55+30*j);
                            p2.imprint();
                            break;
                        }
                        case 3 :
                        {
                            output_w[i][j]=3;
                            cout<<output_w[i][j]<<" ";
                            p3.moveTo(55+30*i,55+30*j);
                            p3.imprint();
                            break;
                        }
                        case 4 :
                        {
                            output_w[i][j]=4;
                            cout<<output_w[i][j]<<" ";
                            p4.moveTo(55+30*i,55+30*j);
                            p4.imprint();
                            break;
                        }
                        case 5 :
                        {
                            output_w[i][j]=5;
                            cout<<output_w[i][j]<<" ";
                            p5.moveTo(55+30*i,55+30*j);
                            p5.imprint();
                            break;
                        }
                        case 6 :
                        {
                            output_w[i][j]=6;
                            cout<<output_w[i][j]<<" ";
                            p6.moveTo(55+30*i,55+30*j);
                            p6.imprint();
                            break;
                        }
                        case 7 :
                        {
                            output_w[i][j]=7;
                            cout<<output_w[i][j]<<" ";
                            p7.moveTo(55+30*i,55+30*j);
                            p7.imprint();
                            break;
                        }
                        case 8 :
                        {
                            output_w[i][j]=8;
                            cout<<output_w[i][j]<<" ";
                            p8.moveTo(55+30*i,55+30*j);
                            p8.imprint();
                            break;
                        }
                        case 9 :
                        {
                            output_w[i][j]=9;
                            cout<<output_w[i][j]<<" ";
                            p9.moveTo(55+30*i,55+30*j);
                            p9.imprint();
                            break;
                        }

                        }
                    }
                    cout<<endl;

                }
                break;
            }
            else   //SOLUTION IS NOT POSSIBLE
            {
                cout<<"NO SOLUTION IS POSSIBLE FOR GIVEN SUDOKU";

                Text nosolution(175,500,"NO SOLUTION IS POSSIBLE FOR GIVEN SUDOKU");
                break;

            }
        }
    }

//TO HIDE 1 TO 9 BUTTONS AND IMPRINTED TEXT(1 TO 9)

    Rectangle hidebuttons(300,380,450,50);
    hidebuttons.setFill(true);
    hidebuttons.setColor(COLOR(255,255,255));

    Rectangle button2(150,20,10);
    button2.setFill(true);
    button2.setColor(COLOR(255,255,255));



    getClick(); //TO CLOSE THE WINDOW AFTER THE SOLVED SUDOKU IS SHOWN

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(Tiles[i][j]!=NULL)
            {
                delete Tiles[i][j];
                //delete Dividers[i][j];
            }
        }
    }


    for(int i=0; i<9; i++)
    {
        if(Buttons[i]!=NULL)
        {
            delete Buttons[i];
            // delete ButtonDividers[i];
        }
    }





    return 0;
}


