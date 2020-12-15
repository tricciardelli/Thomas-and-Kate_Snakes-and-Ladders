#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std; // so we can use 'cout << "Hello World"<<endl;' in the stead of 'std::cout << "Hello World"<<endl;'

//first let us declare a few neccessary functions

void board();//initialize function to draw the board

int check_progress();//initialize function to check game progress

int roll_dice();//initialize function to roll dice

//the we declare some variables

int roll; //holds the rolled value for the player
int computer_roll; //holds the rolled value for computer

int input; //variable to hold the users input, any number to roll dice and 0 to quit game, although entering a not a number value ends  the game as well...

int progress; //holds the value for the progress

int player = 0;

int computer = 0;

//both player and computer's initial starting point is 0

int squares[100]; // for the 100 squares, computers right counts from 0


int main() //this is where it all goes down in c++, it's like the canvas for da vinci...
{
    srand( time(NULL) ); //we need random numbers remeber?

    string alert = ""; //to alert you for your triumphs and misfortunes
    string computer_alert = ""; // to alert you for computer's triumphs and misfortunes

    cout << "Welcome to snakes and ladders, enter any number to roll dice, press 0 to quit\n\n";
    cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n";

    for ( int i = 1; i <= 100; i++) // this loop just makes it possible for us to give our squares values
        {
            squares[i] = i;
        }

    do // every game is in some sort of loop
    {
        cout << "enter: ";
        cin >> input;

        roll = roll_dice();//player rolls dice

        if( (roll + player) > 100)
        {
            player = player; //player has rolled a number that exceeds the end point player remains where they are
        }
        else
        {
            squares[player] = player;//overwrite the current position
            player = player + roll;//move player to a new position
        }

        computer_roll = roll_dice();//computer rolls dice

        if( (computer_roll + computer) > 100)
        {
            computer = computer; //computer has rolled a number that exceeds the end point, computer remains where it is
        }
        else
        {
            squares[computer] = computer;//overwrite the current position
            computer = computer + computer_roll;//move computer to a new position
        }

        switch(player) // it is snakes and ladders, numbers represent the snakes and ladders
        {
            case 99:
            player = 5;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 93:
            player = 25;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 77:
            player = 9;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 52:
            player = 6;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 30:
            player = 2;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 45:
            player = 66;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 35:
            player = 67;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 20:
            player = 41;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 8:
            player = 28;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 4:
            player = 36;
            alert = "YAY! you climbed a ladder!!!";
            break;

            default:
            alert = "";

        }

        switch(computer)
        {
            case 99:
            computer = 5;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 93:
            computer = 25;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 77:
            computer = 9;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 52:
            computer = 6;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 30:
            computer = 2;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 45:
            computer = 66;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 35:
            computer = 67;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 20:
            computer = 41;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 8:
            computer = 28;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 4:
            computer = 36;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            default:
            computer_alert = "";
        }

        squares[player] = 200; //player's position shall be represented by the integer 200
        squares[computer] = 300; //computer's position shall be represented by the inteer 300

	if ( input != 0)
	{
            cout<<"You rolled "<<roll<<" Computer rolled "<<computer_roll<<endl;
            cout<<"Your Position: "<<player<<" Computer's Position: "<<computer<<endl;
            cout <<alert<<endl;
            cout <<computer_alert<<endl;

            board();
            cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n"; //so the player knows which is a snake and that which is ladder
        }

        progress = check_progress();

    }
    while ( progress == 0 && input != 0 );

    if ( squares[100] == 200)
    {
        cout << "||You Win!||"<<endl;
    }
    else if ( squares[100] == 300)
    {
        cout << "||Game Over Computer Wins!"<<endl;
    }
    else
    {
        cout << "You Quit!";
    }

    cin.get();
    cin.ignore();
}

void board()//define the board drawing mechanism!
{
    cout << "----------------------------------------------------------------------------"<<endl<<endl;
         cout << squares[100]<<"\t"<<squares[99]<<"\t"<<squares[98]<<"\t"<<squares[97]<<"\t"<<squares[96]<<"\t"
         <<squares[95]<<"\t"<<squares[94]<<"\t"<<squares[93]<<"\t"<<squares[92]<<"\t"<<squares[91]<<endl<<endl;

         cout << squares[81]<<"\t"<<squares[82]<<"\t"<<squares[83]<<"\t"<<squares[84]<<"\t"<<squares[85]<<"\t"
         <<squares[86]<<"\t"<<squares[87]<<"\t"<<squares[88]<<"\t"<<squares[89]<<"\t"<<squares[90]<<endl<<endl;

         cout << squares[80]<<"\t"<<squares[79]<<"\t"<<squares[78]<<"\t"<<squares[77]<<"\t"<<squares[76]<<"\t"
         <<squares[75]<<"\t"<<squares[74]<<"\t"<<squares[73]<<"\t"<<squares[72]<<"\t"<<squares[71]<<endl<<endl;

         cout << squares[61]<<"\t"<<squares[62]<<"\t"<<squares[63]<<"\t"<<squares[64]<<"\t"<<squares[65]<<"\t"
         <<squares[66]<<"\t"<<squares[67]<<"\t"<<squares[68]<<"\t"<<squares[69]<<"\t"<<squares[70]<<endl<<endl;

         cout << squares[60]<<"\t"<<squares[59]<<"\t"<<squares[58]<<"\t"<<squares[57]<<"\t"<<squares[56]<<"\t"
         <<squares[55]<<"\t"<<squares[54]<<"\t"<<squares[53]<<"\t"<<squares[52]<<"\t"<<squares[51]<<endl<<endl;

         cout << squares[41]<<"\t"<<squares[42]<<"\t"<<squares[43]<<"\t"<<squares[44]<<"\t"<<squares[45]<<"\t"
         <<squares[46]<<"\t"<<squares[47]<<"\t"<<squares[48]<<"\t"<<squares[49]<<"\t"<<squares[50]<<endl<<endl;

         cout << squares[40]<<"\t"<<squares[39]<<"\t"<<squares[38]<<"\t"<<squares[37]<<"\t"<<squares[36]<<"\t"
         <<squares[35]<<"\t"<<squares[34]<<"\t"<<squares[33]<<"\t"<<squares[32]<<"\t"<<squares[31]<<endl<<endl;

         cout << squares[21]<<"\t"<<squares[22]<<"\t"<<squares[23]<<"\t"<<squares[24]<<"\t"<<squares[25]<<"\t"
         <<squares[26]<<"\t"<<squares[27]<<"\t"<<squares[28]<<"\t"<<squares[29]<<"\t"<<squares[30]<<endl<<endl;

         cout << squares[20]<<"\t"<<squares[19]<<"\t"<<squares[18]<<"\t"<<squares[17]<<"\t"<<squares[16]<<"\t"
         <<squares[15]<<"\t"<<squares[14]<<"\t"<<squares[13]<<"\t"<<squares[12]<<"\t"<<squares[11]<<endl<<endl;

         cout << squares[1]<<"\t"<<squares[2]<<"\t"<<squares[3]<<"\t"<<squares[4]<<"\t"<<squares[5]<<"\t"
         <<squares[6]<<"\t"<<squares[7]<<"\t"<<squares[8]<<"\t"<<squares[9]<<"\t"<<squares[10]<<endl<<endl;
    cout << "----------------------------------------------------------------------------"<<endl;
}

int roll_dice()//define the dice rolling mechanism
{
    return rand() % (7-1) + 1;
}

int check_progress()//define the progress checking mechanism
{
    if ( squares[100] == 200 || squares[100] == 300)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

