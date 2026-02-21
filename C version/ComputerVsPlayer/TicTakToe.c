/*
| ======================================================================================================================================
| Name          : TicTakToe (Computer vs Player)
| Author        : Shahzad
| Version       : 1.0-Beta
| Description   : TicTocToe Game - Player VS Computer
| Copyright     : No Copyright. You are allowed to re-use the code or parts of it!
| ======================================================================================================================================
*/
#include <stdio.h>
#include <windows.h>

void stampa(char *p);
int turnoComputer(char *p, int dim, int cont);
int turnoGiocatore(char *p, int dim);
int controllaVincita(char *p);
int ControllaSeVince(char *p);
int isFinita(char *p);


int main()
{
    int i=0, dim=9, win=0, turniComputer=0;
    char posizioni[9] = "123456789";


    while(i==0)
    {
        //Computer's turn:
        printf("\n\nComputer's Turn:\n");
        Sleep(1000);
        turniComputer++;
        turnoComputer(posizioni, dim, turniComputer);
        stampa(posizioni);

        //Check Win or Even:
        if(controllaVincita(posizioni))
            return 0;
        if(isFinita(posizioni))
            return 0;

        //Players's turn:
        turnoGiocatore(posizioni, dim);
        stampa(posizioni);

        //Check Win or Lose:
        if(controllaVincita(posizioni))
            return 0;
        if(isFinita(posizioni))
            return 0;
    }
}



//function Print:
void stampa(char *p)
{
    printf(" %c | %c | %c\n", p[0], p[1], p[2]);
    printf(" --|---|--\n");
    printf(" %c | %c | %c\n", p[3], p[4], p[5]);
    printf(" --|---|--\n");
    printf(" %c | %c | %c\n", p[6], p[7], p[8]);
}

//function Player's turn:
int turnoGiocatore(char *p, int dim)
{
    int check=0, scelta=0;

    while(check==0){
        printf("\nPlayer's Turn:\n");

        while(scelta<1 || scelta>9){
            printf("In which position would you like to place 'O': ");
            scanf("%d", &scelta);
        }

        if(p[scelta-1] != 'X' && p[scelta-1] != 'O')
        {
            p[scelta-1] = 'O';
            return 0;
        }
        else
        { 
            printf("ERROR! The box is already occupied!\n");
            scelta=0;
        }
    }

    return 0;
}

//function Computer's turn:
int turnoComputer(char *p, int dim, int cont)
{
    int mossaSuccessiva=9;
    
    switch(cont)
    {

    //Computer's first turn
    case 1:
        p[6] = 'X';
        break;
    
    //Computer's second turn
    case 2:
        if(p[2] != '3')
            p[0] = 'X';
        else
            p[2] = 'X';
        break;

    //Computer's third turn
    case 3:
        mossaSuccessiva=ControllaSeVince(p);
        if(mossaSuccessiva!=9)
        {
            p[mossaSuccessiva] = 'X';
            return 0;
        }
        else
        {
            if(p[8] == '9')
            {
                p[8] = 'X';
            }
            else
            {
                for(int cont1=0;cont<dim;cont1++)
                {
                    if(p[cont1] != 'X' && p[cont1] != 'O')
                    {
                        p[cont1] = 'X';
                        return 0;
                    }
                }
            }
        }
        break;

    default: //>3 turni Computer
        mossaSuccessiva=ControllaSeVince(p);
        if(mossaSuccessiva!=9)
        {
            p[mossaSuccessiva] = 'X';
            return 0;
        } 
        if(mossaSuccessiva==9)
        {
            for(int cont1=0;cont<dim;cont1++)
            {
                if(p[cont1] != 'X' && p[cont1] != 'O')
                {
                    p[cont1] = 'X';
                    return 0;
                }
            }
        }
    }

    return 0;
}

//function to check win:
int controllaVincita(char *p)
{
    int vincitore=0;

    //Check Computer win
    if((p[0] == 'X' && p[0] == p[1] && p[1] == p[2]) || (p[3] == 'X' && p[3] == p[4] && p[4] == p[5]) || (p[6] == 'X' && p[6] == p[7] && p[7] == p[8]))
        vincitore = 1;
    if((p[0] == 'X' && p[0] == p[3] && p[3] == p[6]) || (p[1] == 'X' && p[1] == p[4] && p[4] == p[7]) || (p[2] == 'X' && p[2] == p[5] && p[5] == p[8]))
        vincitore = 1;
    if((p[0] == 'X' && p[0] == p[4] && p[4] == p[8]) || (p[6] == 'X' && p[6] == p[4] && p[4] == p[2]))
        vincitore = 1;

    if(vincitore){
        printf("\n------------------------------------------\n");
        printf("THE COMPUTER HAS WON!\n");
        printf("Artificial intelligence is taking over...\n");
        printf("------------------------------------------\n\n");
        return 1;
    }

    //Check Player win
    if((p[0] == 'O' && p[0] == p[1] && p[1] == p[2]) || (p[3] == 'O' && p[3] == p[4] && p[4] == p[5]) || (p[6] == 'O' && p[6] == p[7] && p[7] == p[8]))
        vincitore = 1;
    if((p[0] == 'O' && p[0] == p[3] && p[3] == p[6]) || (p[1] == 'O' && p[1] == p[4] && p[4] == p[7]) || (p[2] == 'O' && p[2] == p[5] && p[5] == p[8]))
        vincitore = 1;
    if((p[0] == 'O' && p[0] == p[4] && p[4] == p[8]) || (p[6] == 'O' && p[6] == p[4] && p[4] == p[2]))
        vincitore = 1;
    
    if(vincitore){
        printf("\n-----------------------------------------------------------------\n");
        printf("CONGRATS, YOU WON!\n");
        printf("Are you a god? Because you just beat an argorithm designed to never lose!\n");
        printf("-----------------------------------------------------------------\n\n");
        return 1;
    }

    return 0;
}

//check finish function:
int isFinita(char *p)
{
    int check;

    if(p[0] != '1' && p[1] != '2' && p[2] != '3' && p[3] != '4' && p[4] != '5' && p[5] != '6' && p[6] != '7' && p[7] != '8' && p[8] != '9')
        check = 1;
    else
        check = 0;

    if(check)
    {
        printf("\n-----------------------------------------------------------------\n");
        printf("TIE!");
        printf("Not too bad, you were able to defend yourself!\n");
        printf("\n-----------------------------------------------------------------\n");
        return 1;
    }

    return 0;
}

//funzione controllaSeVince:
int ControllaSeVince(char *p)
{
//------WINNING CHECK (X)-----
//orrizonal:
    if(p[0] == '1' && p[1] == 'X' && p[1] == p[2]) //line 1
        return 0;
    if(p[1] == '2' && p[0] == 'X' && p[0] == p[2])
        return 1;
    if(p[2] == '3' && p[0] == 'X' && p[0] == p[1])
        return 2;
    if(p[3] == '4' && p[4] == 'X' && p[4] == p[5]) //line 2
        return 3;
    if(p[4] == '5' && p[3] == 'X' && p[3] == p[5])
        return 4;
    if(p[5] == '6' && p[3] == 'X' && p[3] == p[4])
        return 5;
    if(p[6] == '7' && p[7] == 'X' && p[7] == p[8]) //line 3
        return 6;
    if(p[7] == '8' && p[6] == 'X' && p[6] == p[8])
        return 7;
    if(p[8] == '9' && p[6] == 'X' && p[6] == p[7])
        return 8;
//vertical:
    if(p[0] == '1' && p[3] == 'X' && p[3] == p[6]) //line 1
        return 0;
    if(p[3] == '4' && p[0] == 'X' && p[0] == p[6])
        return 3;
    if(p[6] == '7' && p[0] == 'X' && p[0] == p[3])
        return 6;
    if(p[1] == '2' && p[4] == 'X' && p[4] == p[7]) //line 2
        return 1;
    if(p[4] == '5' && p[1] == 'X' && p[1] == p[7])
        return 4;
    if(p[7] == '8' && p[1] == 'X' && p[1] == p[4])
        return 7;
    if(p[2] == '3' && p[5] == 'X' && p[5] == p[8]) //line 3
        return 2;
    if(p[5] == '6' && p[2] == 'X' && p[2] == p[8])
        return 5;
    if(p[8] == '9' && p[2] == 'X' && p[2] == p[5])
        return 8;
//diagonal:
    if(p[0] == '1' && p[4] == 'X' && p[4] == p[8]) //line 1
        return 0;
    if(p[4] == '5' && p[0] == 'X' && p[0] == p[8])
        return 4;
    if(p[8] == '9' && p[0] == 'X' && p[0] == p[4])
        return 8;
    if(p[2] == '3' && p[4] == 'X' && p[4] == p[6]) //line 2
        return 2;
    if(p[4] == '5' && p[2] == 'X' && p[2] == p[6])
        return 4;
    if(p[6] == '7' && p[2] == 'X' && p[2] == p[4])
        return 6;

//------LOOSING CHECK (X)-----
//orrizontal:
    if(p[0] == '1' && p[1] == 'O' && p[1] == p[2]) //line 1
        return 0;
    if(p[1] == '2' && p[0] == 'O' && p[0] == p[2])
        return 1;
    if(p[2] == '3' && p[0] == 'O' && p[0] == p[1])
        return 2;
    if(p[3] == '4' && p[4] == 'O' && p[4] == p[5]) //line 2
        return 3;
    if(p[4] == '5' && p[3] == 'O' && p[3] == p[5])
        return 4;
    if(p[5] == '6' && p[3] == 'O' && p[3] == p[4])
        return 5;
    if(p[6] == '7' && p[7] == 'O' && p[7] == p[8]) //line 3
        return 6;
    if(p[7] == '8' && p[6] == 'O' && p[6] == p[8])
        return 7;
    if(p[8] == '9' && p[6] == 'O' && p[6] == p[7])
        return 8;
//vertical:
    if(p[0] == '1' && p[3] == 'O' && p[3] == p[6]) //line 1
        return 0;
    if(p[3] == '4' && p[0] == 'O' && p[0] == p[6])
        return 3;
    if(p[6] == '7' && p[0] == 'O' && p[0] == p[3])
        return 6;
    if(p[1] == '2' && p[4] == 'O' && p[4] == p[7]) //line 2
        return 1;
    if(p[4] == '5' && p[1] == 'O' && p[1] == p[7])
        return 4;
    if(p[7] == '8' && p[1] == 'O' && p[1] == p[4])
        return 7;
    if(p[2] == '3' && p[5] == 'O' && p[5] == p[8]) //line 3
        return 2;
    if(p[5] == '6' && p[2] == 'O' && p[2] == p[8])
        return 5;
    if(p[8] == '9' && p[2] == 'O' && p[2] == p[5])
        return 8;
//diagonal:
    if(p[0] == '1' && p[4] == 'O' && p[4] == p[8]) //line 1
        return 0;
    if(p[4] == '5' && p[0] == 'O' && p[0] == p[8])
        return 4;
    if(p[8] == '9' && p[0] == 'O' && p[0] == p[4])
        return 8;
    if(p[2] == '3' && p[4] == 'O' && p[4] == p[6]) //line 2
        return 2;
    if(p[4] == '5' && p[2] == 'O' && p[2] == p[6])
        return 4;
    if(p[6] == '7' && p[2] == 'O' && p[2] == p[4])
        return 6;

    return 9;
}
