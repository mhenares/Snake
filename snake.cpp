// header files
#include "formatted_console_io_v18.h"
#include <fstream>
#include <iostream>
using namespace std;

// global constants

   const int MAX_NAME_LEN = 30, MAX_SCORES = 11, CENTER_X = 40, ANY_KEY_Y = 23; 
   const int IMPLEMENT_Y = 21, SNAKE_X = 17, SNAKE_Y = 12, TIMER = 2;
   const int STEP_SIZE = 2, MAX_X = 74, MAX_Y = 21, DATA_ENTRY = 6, WINDOW_START = 5;
   const int MENU_X = 29, MENU_Y = 6, MID_X = 39, MID_Y = 12, TOP_Y = 2, SCORES_X = 56;
   const char FILE_NAME[MAX_NAME_LEN] = "scores.txt";
   const char COMMA = ',', END_LINE = '\n', NULL_CHAR = '\0';
    const short WINDOW_FG_COLOR = COLOR_WHITE;
    const short WINDOW_BG_COLOR = COLOR_BLUE;
    const short WALL_SYMBOL = 176;
    const char MARKER_CHAR = 'S';
    const char SPACE = ' ';
    const int DATA_LINE = 19;
    const int POSITIONS = 2;
    const int MAX_FOOD = 100;
    const int CROSS_SIZE = 5;
    const int MAX_SNAKE = 8;
    const int XLOC = 0;
    const int YLOC = 1;
    const int FIRST_INDEX = 0;
    const int DEFAULT = 99;
    const char PLUS = '+';
    const char MINUS = '-';
    const char EQUAL = '=';
    const int KB_SPACE = 32;

// function prototypes

/*
name: loadScores
process: loads scores from file to arrays
function input/parameters: players array(char), scores array(int)
function output/parameters: players array(char), scores array(int)
function output return: number of players
device input: file input 
device output: none
dependencies: fstream
developer: Miguel Henares
*/
int loadScores( char players[][MAX_NAME_LEN], int scores[] );

/*
name: title
process: displays title screen
function input/parameters: x and y positions (int)
function output/parameters: none
function output return: none
device input: none
device output: displayed title
dependencies: formatted console
developer: Phillip Pratt
*/
void title( int xPos, int yPos );

/*
name: introLoop
process: loops the title screen
function input/parameters: none
function output/parameters: none
function output return: none
device input: none
device output: none
dependencies: none
developer: Phillip Pratt
*/
void introLoop ();

/*
name: displayBackgroundColors
process: displays background colors
function input/parameters: none
function output/parameters: none
function output return: none
device input: none
device output: displayed colors
dependencies: formatted console
developer: Phillip Pratt
*/
void displayBackgroundColors ();

/*
name: displaySnakeInstruct
process: displays the instruction screen
function input/parameters: none
function output/parameters: none
function output return: none
device input: none
device output: displayed instructions
dependencies: formatted console
developer: Phillip Pratt
*/
void displaySnakeInstruct ();

/*
name: displayMenu
process: displays menu
function input/parameters: none
function output/parameters: none
function output return: user choice (char)
device input: user input (char)
device output: displayed menu
dependencies: formatted console, displayBackgroundColors
developer: Hyche D'Amato
*/
char displayMenu();

/*
name: difficulty
process: displays difficulty module
function input/parameters: none
function output/parameters: none
function output return: difficulty level (int)
device input: user input (int)
device output: displayed module
dependencies: formatted console
developer: Hyche D'Amato
*/
int difficulty();

/*
name: startGame
process: starts game
function input/parameters: difficulty
function output/parameters: none
function output return: none
device input: user controls (char)
device output: game display
dependencies: formatted console, move, displayLine, fillPositionArr, 
              initializePosArr, randomObjectDisplay, 
              startPosition, gameStats, gamePlay
developer: Phillip Pratt, Miguel Henares, Professor Leverington
*/
int startGame( int difficultyLevel );

/*
name: displayScores
process: displays scores module
function input/parameters: players array (char), scores array, size (int)
function output/parameters: players array (char), scores array, size (int)
function output return: none
device input: none
device output: displayed scores
dependencies: formatted console
developer: Miguel Henares
*/
void displayScores( char players[][ MAX_NAME_LEN ], int scores[], int size);

/*
name: saveScores
process: uploads scores and names to file
function input/parameters: players array (char), scores array, size (int)
function output/parameters: players array (char), scores array, size (int)
function output return: none
device input: none
device output: none
dependencies: fstream
developer: Miguel Henares
*/
void saveScores( char players[][MAX_NAME_LEN], int scores[], int size );

/*
name: initializeArrays
process: initializes arrays to set values
function input/parameters: players array (char), scores array
function output/parameters: players array (char), scores array
function output return: none
device input: none
device output: none
dependencies: none
developer: Miguel Henares
*/
void initializeArrays( char players[][MAX_NAME_LEN], int scores[] );

/*
name: askForName
process: prompts user for name
function input/parameters: players array (char), size (int)
function output/parameters: players array (char), size (int)
function output return: none
device input: user input
device output: displayed prompt
dependencies: formatted console, displayBackgroundColors
developer: Miguel Henares
*/
void askForName( char players[][MAX_NAME_LEN], int size );

/*
name: move
process: sets parameters to move to the next location
function input/parameters: xPos, yPos, xVect, yVect, position, snake 
                                                           and character arrays
function output/parameters: xPos, yPos, position, snake and character arrays
function output return: bool, if snake can move
device input: none
device output: displays snakes location
dependencies: moveSnake, displaySnake
developer: Phillip Pratt & Professor Leverington
*/
bool move( int &xPos, int &yPos, int xVect, int yVect,
              int positionArr [ ] [ POSITIONS ], int snakeArr [ ] [ POSITIONS ],
                                                              char charArr [] );
    
/*
name: displayLine
process: draws line across screen at location
function input/parameters: none
function output/parameters: none
function output return: none
device input: none
device output: A line across the screen 
dependencies: formatted console
developer: Phillip Pratt
*/
void displayLine ();

/* 
name: isItem
process: uses index of character array and returns what character is at index
function input/parameters: index, character array
function output/parameters: character array
function output return: integer value of coresponding character
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
int isItem ( int index, char charArr [ ] );

/* 
name: fillPositionArr
process: uses a random number and stores food/wall locations
function input/parameters: position array
function output/parameters: position array
function output return: none
device input: none
device output: none 
dependencies: getCrossPosition
developer: Phillip Pratt
*/
void fillPositionArr ( int positionArr [ ] [ POSITIONS ] );

/* 
name: getCrossPosition
process: uses random number and stores food/wall locations around random number
function input/parameters: position array, index, val_X & val_Y (random numbers)
function output/parameters: position array, index
function output return: none
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
void getCrossPosition ( int &index, int positionArr [ ] [ POSITIONS ],
                                                         int val_X, int val_Y );

/* 
name: initializePosArr
process: initializes position array to values outside of display
function input/parameters: position array
function output/parameters: position array
function output return: none
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
void initializePosArr ( int positionArr [ ] [ POSITIONS ] );

/* 
name: randomObjectDisplay
process: displays changing color food/walls for snake
function input/parameters: greenIndex yellowIndex redIndex clearIndex 
                                                    position and character array
function output/parameters: same as input
function output return: none
device input: none
device output: none 
dependencies: formatted console
developer: Phillip Pratt
*/
void randomObjectDisplay ( int &greenIndex, int &yellowIndex, int &redIndex, 
                             int &clearIndex, int positionArr [ ] [ POSITIONS ],
                                                             char charArr [ ] );

/* 
name: startPosition
process: initialize snake array to start location
function input/parameters: snake array
function output/parameters: snake array
function output return: none
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
void startPosition ( int snakeArr [ ] [ POSITIONS ] );

/* 
name: moveSnake
process: places new positions in array and overrides oldest position
function input/parameters: snake array, x and y positions
function output/parameters: snake array
function output return: none
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
void moveSnake ( int snakeArr [ ] [ POSITIONS ], int xPos, int yPos );

/* 
name: displaySnake
process: goes through snake array and prints a character at a location
function input/parameters: snake array
function output/parameters: snake array
function output return: none
device input: none
device output: a row of 'S' on the screen 
dependencies: formatted console
developer: Phillip Pratt
*/
void displaySnake ( int snakeArr [ ] [ POSITIONS ] ); 

/* 
name: initializeCharArr
process: initialize snake array to first character to be displayed
function input/parameters: character array
function output/parameters: character array
function output return: none
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
void initializeCharArr ( char charArr [ ] );

/* 
name: snakeCollision
process: searches through position array to see if x and y positions are in the
         array and returns what result a collision with item would be
function input/parameters: character and position array, x and y positions
function output/parameters: character and position array
function output return: value of -1, 0, 1, or 99;
device input: none
device output: none 
dependencies: isItem
developer: Phillip Pratt
*/
int snakeCollision ( int positionArr [ ] [ POSITIONS ], char charArr [ ], 
                                                           int xPos, int yPos );

/* 
name: gamePlay
process: uses a result from snakeCollision, to give points or take away life, 
         closes out of function if life equals zero
function input/parameters: calculate, points and life
function output/parameters: points and life
function output return: true if program to continue false if life == 0
device input: none
device output: none 
dependencies: none
developer: Phillip Pratt
*/
bool gamePlay ( int calculate, int &life, int &points );

/* 
name: gameStats
process: displays info on bottom of game screen
function input/parameters: points and life
function output/parameters: none
function output return: none
device input: none
device output: data on progress of game 
dependencies: formatted console
developer: Phillip Pratt
*/
void gameStats ( int life, int points );

void sortArray( int scores [ MAX_SCORES ], char players[][MAX_NAME_LEN] );

// main program
int main()
   {
    // initialize program

       // initialize variables
       int choice= 1, scores[ MAX_SCORES ], size, points;
       char userInput, players[ MAX_SCORES ][ MAX_NAME_LEN ];
       bool progContinue = true;
       
       // initialize arrays
          // function: initializeArrays
       initializeArrays( players, scores);
       
       // load data
          // function: loadScores
       size = loadScores( players, scores );

       // start curses
          // function: startCurses
       startCurses();

       // display snake title
          // function: introLoop
       introLoop();

       // display instructions
          // function: displaySnakeInstruct
       displaySnakeInstruct();

    // start menu loop
       do
       { 
        // diplay menu
           // function: displayMenu
        userInput = displayMenu();

        // make selection from user input
         switch( userInput )
            {
             // check for case '1', 's', 'S'
             case '1':
             case 's':
             case 'S':       
               // set difficulty
                  // function: difficulty
               choice = difficulty();
               break;
       
             // check for case '2', 'p', 'P'
             case '2':
             case 'p':
             case 'P':      
                // get playes name
                   // function: askForName
                askForName( players, size );

                // clear the screen to play
                   // function: setColor
                setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );

                   // function: clearScreen
                clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

                // start game
                   // function: startGame
                points = startGame( choice );
                    
                // save score
                scores[size] = points;
                    
                // sort arrays
                sortArray(scores, players);
                break;
       
             // check for case '3', 'd', 'D'
             case '3':
             case 'd':
             case 'D':              
                // display top scores
                   // function: displayScores
                displayScores( players, scores, size );

                break;

             // check for case '4', 'q', 'Q'
             case '4':
             case 'q':
             case 'Q':       
                // set program continue flag to false
                progContinue = false;
                break;
            }
    }
    while( progContinue );
    // end loop

    // end program
       
       // save scores
          // function: saveScores
       saveScores( players, scores, size );
       
       // shut down curses
          // function: endCurses
       endCurses();

       // return success
       return 0;
   }

// function implementations

void title( int xPos, int yPos )
   {
    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "SSSSSSS  NN    N     A     KK   KK  EEEEEEE", "LEFT" );
          yPos ++;

    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "SS       NNN   N    AAA    KK  KK   EEE    ", "LEFT" );
          yPos ++;

    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "SS       NNNN  N  AA   AA  KKKK     EEEEE  ", "LEFT" );
          yPos ++;

    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "SSSSSSS  NN NN N  AAAAAAA  KKKK     EEEEE  ", "LEFT" );
          yPos ++;

    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "     SS  NN  NNN  AA   AA  KK  KK   EEE    ", "LEFT" );
          yPos ++;

    // Print line in Title
       // function: printStringAt () and move y position
          printStringAt ( xPos, yPos, 
                        "SSSSSSS  N    NN  AA   AA  KK   KK  EEEEEEE", "LEFT" );
   }

void introLoop ()
   {
    // Initialize Variables
       int counter = 0, xPos = SNAKE_X, yPos = SNAKE_Y, toCloseLoop = 0;
       bool good = true;

    // Start Loop
    while ( good )
     { 
      // First Step of motion, if counter
      if ( counter < 5 )
        {
         // change color of display
            // function: setColor ()
               setColor ( COLOR_BLUE, COLOR_CYAN, SET_BRIGHT );

            // function: clearScreen ()
               clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

         // display title at location and set next location
            // function: title ()
               title ( xPos, yPos );
               xPos -= STEP_SIZE;
               yPos --;
        }
      // Second Step of motion, if counter
      else if ( counter < 10 )
        {
         // change color of display
            // function: setColor ()
               setColor ( COLOR_MAGENTA, COLOR_BLACK, SET_BRIGHT );

            // function: clearScreen ()
               clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

         // display title at location and set next location
            // function: title ()
               title ( xPos, yPos );
               xPos += STEP_SIZE;
               yPos --;
        }
      // Third Step of motion, if counter
      else if ( counter < 15 )
        {
         // change color of display
            // function: setColor ()
               setColor ( COLOR_YELLOW, COLOR_MAGENTA, SET_BRIGHT );

            // function: clearScreen ()
               clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

         // display title at location and set next location
            // function: title ()
               title ( xPos, yPos );
               xPos += STEP_SIZE;
               yPos ++;
        }
      // Fourth Step of motion, if counter
      else if ( counter < 20 )
        {
         // change color of display
            // function: setColor ()
               setColor ( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

            // function: clearScreen ()
               clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

         // display title at location and set next location
            // function: title ()
               title ( xPos, yPos );
               xPos -= STEP_SIZE;
               yPos ++;
        }
      // Reset Loop
       else
        {
         // counter reset
         counter = 0;

         // position reset
         xPos = SNAKE_X, yPos = SNAKE_Y;
        }

       // Display Creators of this Program
          // function: printStringAt ()
             printStringAt ( CENTER_X, IMPLEMENT_Y, 
  "Implemented by Miguel Henares, D'Amato Hyche, and Phillip Pratt", "CENTER" );

       // display creators of this program
          // function: printStringAt ()
             printStringAt ( CENTER_X, ANY_KEY_Y,
                                        "PRESS ANY KEY TO CONTINUE", "CENTER" );
      
       // Loop Continue
       counter ++;

       // Get Input Required to end loop
          // function: waitForInput ()
             toCloseLoop = waitForInput ( TIMER );

       // Test to close Loop
       if ( toCloseLoop > 0 )
         {
          // Loop End
          good = false;
         }
      }
   }

void displayBackgroundColors ()
   {
    // set Background window Color
       // function: setColor()
          setColor( COLOR_WHITE, COLOR_GREEN, SET_BRIGHT );

       // function: clearScreen ()
          clearScreen ( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

    // set forground window Color
       // function: setColor ()
          setColor( COLOR_WHITE, COLOR_MAGENTA, SET_BRIGHT );

       // function: clearScreen ()
          clearScreen ( WINDOW_START, WINDOW_START, MAX_X, MAX_Y );
   }

void displaySnakeInstruct ()
   {
    // Initialize Variables
    int xLoc = CENTER_X, yLoc = DATA_ENTRY;

    // Clear the Screen and display background
       // function: displayBackgroundColors ()
          displayBackgroundColors ();

    // Display Title and Underline
       // function: printStringAt (), and incriment yLoc
          printStringAt ( xLoc, yLoc, "Snake Instructions", "CENTER");
          yLoc ++;

       // function: printStringAt (), and incriment yLoc twice
          printStringAt ( xLoc, yLoc, "==================", "CENTER" );
          yLoc += STEP_SIZE;

    // Display Info on Green Circles
       // function: printStringAt (), and incriment yLoc 
          printStringAt ( xLoc, yLoc, "Green circles are food", "CENTER");
          yLoc ++; 

       // function: printStringAt (), and incriment yLoc twice     
          printStringAt ( xLoc, yLoc, "Eating a green circle gets a point", 
                                                                     "CENTER" );
          yLoc += STEP_SIZE;
        
    // Display Info on Yellow Circles
       // function: printStringAt (), and incriment yLoc
          printStringAt ( xLoc, yLoc, "Yellow circles warn that red is coming", 
                                                                     "CENTER" );
          yLoc ++;

       // function: printStringAt (), and incriment yLoc twice
          printStringAt ( xLoc, yLoc, "but have no food value", "CENTER" );
          yLoc += STEP_SIZE; 

    // Display Info on Red Circles
       // function: printStringAt (), and incriment yLoc
          printStringAt ( xLoc, yLoc, "Red circles are barriers", "CENTER" );
          yLoc ++;  

       // function: printStringAt (), and incriment yLoc two times
          printStringAt ( xLoc, yLoc, "Hitting a red circle loses a life", 
                                                                     "CENTER" );
          yLoc += STEP_SIZE; 


    // Display Info on Objective of Game 
       // function: printStringAt ()
          printStringAt( xLoc, yLoc,  
                  "Try to gather as many green circles as possible", "CENTER" );

    // Hold Screen for User
       // function: waitForInput ()
          waitForInput ( FIXED_WAIT ); 
   }

char displayMenu()
   {
     // initialize variables
     int xPos = MENU_X;
     int yPos = MENU_Y;
     char userInput;
 
     // display boxed window
        // function: displayBackgroundColors ()
     displayBackgroundColors ();

     // print title and underline
       // function: printStringAt
     yPos += STEP_SIZE;
     printStringAt( xPos, yPos, "MENU SELECTIONS", "LEFT" );
     yPos++;
     printStringAt( xPos, yPos, "---------------", "LEFT" );
     yPos++;

     // print the menu
       // function: printStringAt
    yPos++;
    printStringAt( xPos, yPos, "1. <S>et Difficulty", "LEFT" );
    yPos++;
    printStringAt( xPos, yPos, "2. <P>lay Game", "LEFT" );
    yPos++;
    printStringAt( xPos, yPos, "3. <D>isplay Top Scores", "LEFT" );
    yPos++;
    printStringAt( xPos, yPos, "4. <Q>uit Program", "LEFT" );
    yPos++;
    yPos++;
    printStringAt( xPos, yPos, "Enter Selection: ", "LEFT" );

    // prompt for user's input
       // function: waitForInput
    userInput = waitForInput( FIXED_WAIT );

    // return user's input
    return userInput; 
   
  }

int difficulty()
   {
    // initialize function/variables
    int difficulty, xPos, yPos;
    bool difficultyRight=false;

    // loop difficulty module until input is correct
    while( difficultyRight == false)
    {
       // set color
          // function: setColor
       setColor( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );

       // clear screen
          // function: clearScreen
       clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );

       // display test/prompt
          // function: promptForIntAt, printStringAt
       xPos = MID_X, yPos = MID_Y;
       printStringAt( xPos, yPos, "Game Difficulty Entry Module", "CENTER" );
       xPos = MENU_X, yPos+=2;
       difficulty = promptForIntAt( xPos, yPos, "Enter Game Difficulty <1-3>: " ); 
    
       // check for valid input
       if( difficulty >=1 && difficulty <= 3)
       {
        difficultyRight = true;
       }
    }

   return difficulty;
   }

int startGame( int difficultyLevel )
   {
    // initialize program / function
    
       // initialize variables
       int userInput, xLoc, yLoc, xVector, yVector, gameCalculate, life = 3, points = 0;
       bool continueProgram = true, programContinue = true; 
       int positionArr [ MAX_FOOD ] [ POSITIONS ], snakeArr [ MAX_SNAKE ] [ POSITIONS ] ;
       int greenIndex = 0, yellowIndex = 0, redIndex = 0, clearIndex = 0, counter = 0;
       char charArr [ MAX_FOOD ];
       
       // initialize locations and movement vectors
       xLoc = SCRN_MAX_X / 2;
       yLoc = SCRN_MAX_Y / 2;
       xVector = 0; yVector = 0;

       // get array positions
       startPosition ( snakeArr );
       initializeCharArr ( charArr );
       fillPositionArr ( positionArr );

       // draw line
       displayLine ();


   // start loop
    do
       {

        // get an input key, waiting for user input
        userInput = waitForInput( difficultyLevel
                                 
                                 
                                 );

            // if user presses right arrow
            if( userInput == KB_RIGHT_ARROW )
            {
               // while the snake is being asked to turn back on itself
               while( xVector == -1 )
               {
                  // ask user to change other direction
                  userInput = waitForInput( FIXED_WAIT );
                  
                  // if direction is valid end loop
                  if( userInput != KB_RIGHT_ARROW )
                  {
                     xVector = 0;
                  }
               }

               // if direction is valid allow motion
               if( xVector != -1 )
               {
                  xVector = 1;
                  yVector = 0;
               }
            }

            // if user presses left arrow
            if( userInput == KB_LEFT_ARROW )
            {
                // while the snake is being asked to turn back on itself
                while( xVector == 1 )
                {
                   // ask user to change other direction
                   userInput = waitForInput( FIXED_WAIT );

                   // if direction is valid end loop
                   if( userInput != KB_LEFT_ARROW )
                   {
                      xVector = 0;
                   }
                }

                // if direction is valid allow motion
                if( xVector != 1 )
                {
                   xVector = -1;
                   yVector = 0;
                }

                // compensate for other motions coded prior
                if( userInput == KB_RIGHT_ARROW )
                {
                  xVector = 1;
                  yVector = 0;
                }
            }

            // if user presses up arrow
            if( userInput == KB_UP_ARROW )
            {
                // while the snake is being asked to turn back on itself
                while( yVector == 1 )
                {
                   // ask user to change other direction
                   userInput = waitForInput( FIXED_WAIT );

                   // if direction is valid end loop
                   if( userInput != KB_UP_ARROW )
                   {
                      yVector = 0;
                   }
                }

                // if direction is valid allow motion
                if( yVector != 1 )
                {
                   xVector = 0;
                   yVector = -1;
                }

                // compensate for other motions coded prior
                if( userInput == KB_RIGHT_ARROW )
                {
                      xVector = 1;
                      yVector = 0;
                }

                if( userInput == KB_LEFT_ARROW )
                {
                       xVector = -1;
                       yVector = 0;
                }

             }

            // if user presses down arrow
            if( userInput == KB_DOWN_ARROW )
            {
                // while the snake is being asked to turn back on itself
                while( yVector == -1 )
                {
                   // ask user to change other direction
                   userInput = waitForInput( FIXED_WAIT );

                   // if direction is valid end loop
                   if( userInput != KB_DOWN_ARROW )
                   {
                      yVector = 0;
                   }
                }

                // if direction is valid allow motion
                if( yVector != -1 )
                {
                   xVector = 0;
                   yVector = 1;
                }

                // compensate for other motions coded prior
                if( userInput == KB_RIGHT_ARROW )
                {
                      xVector = 1;
                      yVector = 0;
                }

                if( userInput == KB_LEFT_ARROW )
                {
                       xVector = -1;
                       yVector = 0;
                }

                if( userInput == KB_UP_ARROW )
                {
                       xVector = 0;
                       yVector = -1;
                }
           }

            // if user presses escape
            if( userInput == KB_ESCAPE )
            {
               continueProgram = false;
            
                return points;
            }

            // if user presses space bar
            if( userInput == KB_SPACE )
            {
             // hold program
                // function: waitForInput
             waitForInput ( FIXED_WAIT );
            }

        // move the character
        move( xLoc, yLoc, xVector, yVector, positionArr, snakeArr, charArr );

        gameCalculate = snakeCollision ( positionArr, charArr, xLoc, yLoc );

        programContinue = gamePlay ( gameCalculate, life, points );
        gameStats ( life, points );

           if ( counter > 6 / difficultyLevel )
           {
            randomObjectDisplay ( greenIndex, yellowIndex, redIndex, clearIndex, positionArr, charArr );
            counter = 0;
           }
        counter ++;
       }
    while( continueProgram && programContinue );
       
    // return
    return points;
   }

void displayScores( char players[][ MAX_NAME_LEN ], 
                                   int scores[], int size )
   {
    // initialize function
    int xPos, yPos, index = 0, colIndex = 0;

    // set color
       // function: setColor
    setColor( COLOR_WHITE, COLOR_BLUE, SET_BRIGHT );

    // clear screen
       // function: clearScreen
    clearScreen( SCRN_MIN_X, SCRN_MIN_Y, SCRN_MAX_X, SCRN_MAX_Y );
              
       // if no scores are recorded
       if( players[ index ][ colIndex ] == NULL_CHAR )
       {
           // display no scores screen
              // function: printStringAt, setColor, waitforInput
           xPos = MID_X;
           yPos = MID_Y;
           printStringAt( xPos, yPos, "No Scores Recorded", "CENTER");
           yPos+=2;
           setColor( COLOR_YELLOW, COLOR_BLUE, SET_BRIGHT);
           printStringAt( xPos, yPos, "Press Any Key to Continue . . .", "CENTER");
           waitForInput(FIXED_WAIT); 
       }

       else
       {
          // print title 
             // function: printStringAt
          xPos = MID_X, yPos = TOP_Y;
          printStringAt( xPos, yPos, "TOP TEN WINNERS", "CENTER" );
          yPos++;
          printStringAt( xPos, yPos, "---------------", "CENTER" );

          // print subtitles
             // function: printStringAt
          xPos = MENU_X, yPos+=2;
          printStringAt( xPos, yPos, "NAMES                   SCORES", "LEFT"); 
          yPos++; 
          printStringAt( xPos, yPos, "-----                   ------", "LEFT");  
          yPos+=2;

          // loop to display data
          while( index < size && index < MAX_SCORES - 1 )
          {
             // display names and high scores
                // function: printStringAt, printIntAt
             xPos = MENU_X;
             printStringAt( xPos, yPos, players[index], "LEFT");
             xPos = SCORES_X;
             printIntAt( xPos, yPos, scores[index], "LEFT" );
             yPos++;
             index++;
          }
   
          // wait for user
             // function: waitForInput, printStringAt
          xPos = MENU_X;
          yPos++;
          printStringAt( xPos, yPos, "Press any key to continue . . .", "LEFT");
          waitForInput(FIXED_WAIT);
       }

   }

void sortArray( int scores [ MAX_SCORES ], char players[][MAX_NAME_LEN] )
{
    // initialize function/variables
    bool swapped = true;
    int index;
    char temporary[MAX_NAME_LEN], temporaryTwo[MAX_NAME_LEN];
        
    // loop until no more swaps
    while( swapped )
    {
        // set boolean to false and index to zero
        swapped = false;
        index = 0;
            
        // loop until next to last item
        while( index < MAX_SCORES )
        {
            // check for first one greater 
            // than second one
            if( scores[ index ] < scores[ index + 1 ] )
            {
                // swap
                swap( scores[ index ], scores[ index + 1 ] );
                
                strcpy( temporary, players[ index ]);
                
                strcpy( players[ index ], players[ index+1 ]);
                strcpy( players[ index + 1 ], temporary);

                // set swapped flag
                swapped = true;
            }
                
            // increment the inner loop index
            index++;
        }
    }
}

int loadScores( char players[][MAX_NAME_LEN], int scores[] )
{
    // initialize function/variables
    int index = 0;
    ifstream fin;
    int score, size;
    char dummy;
    
    // clear and open file
       // function: .clear, .open
    fin.clear();
    fin.open( FILE_NAME );
    
    // prime loop
       // function: getline, fstream >>
    fin >> score;
    scores[ index ] = score;
    fin >> dummy;
    fin.getline( players[ index ], MAX_NAME_LEN, END_LINE );
    
    // increment index
    index++;
    
    // loop to load data to arrays
    while( fin.good())
    {
        // load data
           // function: getline, fstream >>
        fin >> score;
        scores[ index ] = score;
        fin >> dummy;
        fin.getline( players[ index ], MAX_NAME_LEN, END_LINE );
        
        // increment index
        index++;
    }
    
    // give size
    size = index;
    
    // close file
       // function: .close
    fin.close();
    
    // return size
    return size;
        
}

void saveScores( char players[][MAX_NAME_LEN], int scores[], int size )
{
    // initialize function/variables
    ofstream fout;
    int index = 0;
    
    // open file
    fout.open( FILE_NAME );
    
    // begin loop 
    while( index < size && index < MAX_SCORES - 1 )
    {
        // output array data to file
           // function: fstream <<
        fout << scores[ index ] << COMMA << players[ index ] << endl;
        
        // increment index
        index++;
    }
    
    // close file
       // function: .close
    fout.close();
}

void initializeArrays( char players[][MAX_NAME_LEN], int scores[] )
{
    // initialize function/variables
    int index = 0, colIndex = 0;
       
    // set array values
    while( index < MAX_SCORES )
    {
        players[index][colIndex]= NULL_CHAR;
        scores[index] = 0;
        index++;
    }
 
}

void askForName( char players[][MAX_NAME_LEN], int size )
   {
    // display boxed window
       // function: displayBackgroundColors ()
    displayBackgroundColors ();
    
    // ask user for name
       // funtion: promptForStringAt
    promptForStringAt( MENU_X, MID_Y, "Enter your name: ", players[size] ); 
}

bool move( int &xPos, int &yPos, int xVect, int yVect, int positionArr [ ] [ POSITIONS ], int snakeArr [ ] [ POSITIONS ], char charArr [] )
   {
    // initialize function/variables
    bool moved = false;

    // if x vector is live, test for acceptable movement limits
    if( ( xVect != 0 ) // is meant to move
          && ( xPos + xVect >= SCRN_MIN_X ) // won't go off left side of screen 
               && ( xPos + xVect <= SCRN_MAX_X )  ) // won't go off right side of screen
       {

        // reset the x position
        xPos = xPos + xVect;

     if ( snakeCollision ( positionArr, charArr, xPos, yPos ) != -1 )
       {
        moveSnake ( snakeArr, xPos, yPos );
        // set moved flag to indicate success
        moved = true;
       }
      else
       {
        xPos = xPos - xVect;
       }
       }

    // if y vector is live, test for acceptable movement limits
    else if( ( yVect != 0 ) // is meant to move
               && ( yPos + yVect >= SCRN_MIN_Y ) // won't go off top of screen
                    && ( yPos + yVect < DATA_LINE ) ) // won't go off bottom of screen
       {

        // reset the y position
        yPos = yPos + yVect;

     if ( snakeCollision ( positionArr, charArr, xPos, yPos ) != -1 )
       {
        moveSnake ( snakeArr, xPos, yPos );
        // set moved flag to indicate success
        moved = true;
       }
      else
       {
        yPos = yPos - yVect;
       }
       }

    // print the marker at the specified location
    setColor ( COLOR_WHITE, COLOR_BLACK, SET_BRIGHT );
    displaySnake ( snakeArr );

    // return successful move
    return moved;
   }

void displayLine ()
   {
    // Initialize Variables 
       int index;

    // Loop across entire screen length
       for ( index = FIRST_INDEX; index <= SCRN_MAX_X; index++ )
          {
           // print character to screen to represent a wall
              printCharAt ( index, DATA_LINE, WALL_SYMBOL ); 
          }
   }

void fillPositionArr ( int positionArr [ ] [ POSITIONS ] )
   {
    // Initialize Variables
       int index = FIRST_INDEX, checkIndex = FIRST_INDEX;
       int val_X, val_Y;
       bool goodLocation = true;

       // Initialize Arrays
          // function: initializePosArr 
             initializePosArr ( positionArr );
 
    // Loop across position array
       while ( index < MAX_FOOD )
          {
           // get a random number inside display window for x and y positions
              val_X = rand () % 78 + 2;
              val_Y = rand () % 17 + 1;

           // create full food/ wall display around positions
              // function: getCrossPosition
                 getCrossPosition ( index, positionArr, val_X, val_Y );

    // Loop across position array to check for previous number existance
       while ( goodLocation && (checkIndex < index) )
          {
           // if number for x position does exist exit loop
              if ( positionArr [ checkIndex ][ XLOC ] == val_X )
                {
                 // set flag to exit loop
                    goodLocation = false;
                }
           // if number for y position does exist exit loop
              else if ( positionArr [ checkIndex ][ YLOC ] == val_Y )
                {
                 // set flag to exit loop
                    goodLocation = false;
                }
           // if number at index does not exist then check next index
              else
                { 
                 // step up checkIndex
                    checkIndex ++;
                }
          }

    // If positions do not exist then set next index
       if ( goodLocation )
         {
          // step up index
             index ++;
         }

    // Reset Flags and Indices
       goodLocation = true;
       checkIndex = FIRST_INDEX;
          }
   }

void initializePosArr ( int positionArr [ ] [ POSITIONS ] )
   {
    // Initialize Variables
       int rowIndex, colIndex;

    // Loop through position array of food/wall array of maximum food
       for ( rowIndex = FIRST_INDEX; rowIndex < MAX_FOOD; rowIndex ++ )
          {
           // Loop through position array of x and y positions
              for ( colIndex = FIRST_INDEX; colIndex < POSITIONS; colIndex ++ )
                 {
                  // set values to outside screen display
                     positionArr [ rowIndex ] [ colIndex ] = DEFAULT;
                 }
          }
   }

void getCrossPosition ( int &index, int positionArr [ ] [ POSITIONS ], int val_X, int val_Y )
   {
    // Set Central food/ wall location
       // set x position
          positionArr [ index ] [ XLOC ] = val_X;

       // set y position
          positionArr [ index ] [ YLOC ] = val_Y;

    // Set Left food/ wall location
       // move index
          index ++;

       // set x position
          positionArr [ index ] [ XLOC ] = val_X - 1;

       // set y position
          positionArr [ index ] [ YLOC ] = val_Y;

    // Set Right food/ wall location
       // move index
          index ++;

       // set x position
          positionArr [ index ] [ XLOC ] = val_X + 1;

       // set y position
          positionArr [ index ] [ YLOC ] = val_Y;

    // Set Top food/ wall location
       // move index
          index ++;

       // set x position
          positionArr [ index ] [ XLOC ] = val_X;

       // set y position
          positionArr [ index ] [ YLOC ] = val_Y - 1;

    // Set Bottom food/ wall location
       // move index
          index ++;

       // set x position
          positionArr [ index ] [ XLOC ] = val_X;

       // set y position
          positionArr [ index ] [ YLOC ] = val_Y + 1;

    // Go to next index for next food/wall item
       // move index
          index++;
   }

void randomObjectDisplay ( int &greenIndex, int &yellowIndex, int &redIndex, 
          int &clearIndex, int positionArr [ ] [ POSITIONS ], char charArr [ ] )
   {
    // Initialize Variables
       int randomEvent, printCounter;

    // get a random number between one and four
       randomEvent = rand () % 4 + 1;

    // If the random number is one
       if ( randomEvent == 1 )
         {
          // change the color for a green character
             setColor ( COLOR_GREEN, COLOR_BLACK, SET_BRIGHT );

          // reset full cross counter
             printCounter = FIRST_INDEX;

          // loop to display full cross
             while ( printCounter < CROSS_SIZE )
                { 
                 // insure displays correct image
                    charArr [ greenIndex ] = PLUS;
 
                 // display at position
                    printCharAt ( positionArr [ greenIndex ] [ XLOC ], 
                  positionArr [ greenIndex ] [ YLOC ], charArr [ greenIndex ] );

                 // go to next index
                    greenIndex++;
                    printCounter ++;
                }
          // If at maximum index
             if  ( greenIndex == MAX_FOOD )
                {
                 // reset all indicies
                    greenIndex = FIRST_INDEX, yellowIndex = FIRST_INDEX, 
                               redIndex = FIRST_INDEX, clearIndex = FIRST_INDEX;
                }
         } 

     // If the random number is one and was green color first
        else if ( randomEvent == 2 && greenIndex > yellowIndex )
         {
          // change the color for a yellow character
             setColor ( COLOR_YELLOW, COLOR_BLACK, SET_BRIGHT );
          // reset full cross counter
             printCounter = FIRST_INDEX;

          // loop to display full cross
             while ( printCounter < CROSS_SIZE )
                { 
                 // insure not grabbed by snake
                    if ( charArr [ yellowIndex ] != SPACE )
                      {
                       // insure displays correct image
                          charArr [ yellowIndex ] = EQUAL;
                      }
                 // display at position
                    printCharAt ( positionArr [ yellowIndex ] [ XLOC ], 
                positionArr [ yellowIndex ] [ YLOC ], charArr [ yellowIndex ] );

                 // go to next index
                   yellowIndex++;
                   printCounter ++;
                }
         }
        else if ( randomEvent == 3 && yellowIndex > redIndex )
         {
          // change the color for a red character
             setColor ( COLOR_RED, COLOR_BLACK, SET_BRIGHT );
          // reset full cross counter
             printCounter = FIRST_INDEX;
          // loop to display full cross
             while ( printCounter < CROSS_SIZE )
                { 
                 // insure not grabbed by snake
                    if ( charArr [ redIndex ] != SPACE )
                      {
                       // insure displays correct image
                          charArr [ redIndex ] = MINUS;
                      }
                 // display at position           
                    printCharAt ( positionArr [ redIndex ] [ XLOC ],
                      positionArr [ redIndex ] [ YLOC ], charArr [ redIndex ] );

                 // go to next index
                    redIndex++;
                    printCounter ++;
                }
         }
        else if ( randomEvent == 4 && redIndex > clearIndex )
         {
          // change the color for a black character
             setColor ( COLOR_BLACK, COLOR_BLACK, SET_BRIGHT );

          // reset full cross counter
             printCounter = FIRST_INDEX;

          // loop to display full cross
             while ( printCounter < CROSS_SIZE )
                { 
                 // insure displays correct image
                    charArr [ clearIndex ] = SPACE;

                 // display at position 
                    printCharAt ( positionArr [ clearIndex ] [ XLOC ],
                  positionArr [ clearIndex ] [ YLOC ], charArr [ clearIndex ] );

                 // go to next index
                    clearIndex++;
                    printCounter ++;
                }
         }
   }

void startPosition ( int snakeArr [ ] [ POSITIONS ] )
  {
   // Initialize Variables
      int index, xPos = SCRN_MAX_X / 2, yPos = (SCRN_MAX_Y / 2) - 1;

   // Loop through snake array
   for ( index = FIRST_INDEX; index < MAX_SNAKE; index ++ )
      {
       // set Start Locations
          // set x start position
             snakeArr [ index ] [ XLOC ] = xPos;

          // set y start position
             snakeArr [ index ] [ YLOC ] = yPos;

          // go to next y position
             yPos ++;
      }
   }

void moveSnake ( int snakeArr [ ] [ POSITIONS ], int xPos, int yPos )
   {
    // Initialize Variables
    int index;

    // Loop across snake array
    for ( index = MAX_SNAKE -1; index > FIRST_INDEX; index -- )
       {
        // move old positions to higher index location
           // move x position
              snakeArr [ index ] [ XLOC ] = snakeArr [ index - 1 ] [ XLOC ]; 

           // move y position
              snakeArr [ index ] [ YLOC ] = snakeArr [ index - 1 ] [ YLOC ];
       }

    // Assign new positions to first location in snake array
       // assign new x position
          snakeArr [ FIRST_INDEX ] [ XLOC ] = xPos;

       // assign new y position
          snakeArr [ FIRST_INDEX ] [ YLOC ] = yPos;
   }

void displaySnake ( int snakeArr [ ] [ POSITIONS ] ) 
   {
    // Initialize Variables
       int index;

    // Loop through snake array
       for ( index = FIRST_INDEX; index < MAX_SNAKE - 1 ;  index ++)
          {
           // print to screen image of snake
              printCharAt ( snakeArr [ index ] [ XLOC ],
                                     snakeArr [ index ] [ YLOC ], MARKER_CHAR );
          }

    // Clear last location of snake
       printCharAt ( snakeArr [ MAX_SNAKE - 1 ] [ XLOC ], 
                                   snakeArr [ MAX_SNAKE - 1 ] [ YLOC ], SPACE );
   }

void initializeCharArr ( char charArr [ ] )
   {
    // Initialize Variables
       int index;

    // Loop through character array
       for ( index = FIRST_INDEX; index < MAX_FOOD; index ++)
          {
           // set array to first display item
              charArr [ index ] = SPACE;
          }
   }

int snakeCollision ( int positionArr [ ] [ POSITIONS ], char charArr [ ], int xPos, int yPos )
   {
    // Initialize Variables
       int index, points = DEFAULT;

    // Loop through food/wall array
       for ( index = FIRST_INDEX; index < MAX_FOOD; index ++ )
          {
           // test if x and y are represented by food or wall
              if ( positionArr [ index ] [ XLOC ] == xPos &&
                                        positionArr [ index ] [ YLOC ] == yPos )
                {
                 // test if a character exists at location
                    // function: isItem
                       points = isItem ( index, charArr );
                }
          }
    // return dummy value
       return points;
   }

int isItem ( int index, char charArr [ ] )
   {
    int count = 0;
    // test if not empty
       if ( charArr [ index ] != SPACE )
         {
          // test if green
             if ( charArr [ index ] == PLUS )
               {
                // clear location
                   charArr [ index ] = SPACE;

                // get point
                   count++;

               }
          // test if yellow
             else if ( charArr [ index ] == EQUAL )
               {
                // clear location
                   charArr [ index ] = SPACE;
               }
          // test if red
             else if ( charArr [ index ] == MINUS )
               {
                // loose point
                count --;
               }
         }
    // return dumy value
    return count;
   }

bool gamePlay ( int calculate, int &life, int &points )
   {
    // Initialize Variables
       bool programContinue = true;

    // Check if should add points
       if ( calculate == 0 )
         {
          // step up points
             points ++;
         }

    // Check if should decrease life
       else if ( calculate == -1 )
         {
          // step down life
             life--;

          // check if lives are gone
             if ( life == 0 )
               {
                // if lives are gone set flag to exit game
                   programContinue = false;
               }
         }
    // return flag 
       return programContinue;
   }
        
void gameStats ( int life, int points )
   {
    // Initialize Variables
       int xPos = 3, yPos = 20;

    // set display color
       // function: setColor
          setColor( COLOR_RED, COLOR_BLACK, SET_BRIGHT );

    // display instructions
       // function: printStringAt and increment yPos
          printStringAt ( xPos, yPos, "Press Up or Down Arrow to Set Direction", "Left" );
          yPos ++;
 
       // function: printStringAt
          printStringAt ( xPos, yPos, "       Press Spacebar to Pause         ", "Left" );

    // reset positions
    xPos = 50, yPos = 20;

    // display info for points
       // function: printStringAt, printIntAt, and increment y position
          printStringAt ( xPos, yPos, "Number of Food Items: ", "LEFT" );
          printIntAt ( xPos + 22, yPos, points, "LEFT" );
          yPos ++;

    // display info for points
       // function: printStringAt, printIntAt, and increment y position
          printStringAt ( xPos, yPos, "     Lives Remaining: ", "LEFT" );
          printIntAt ( xPos + 22, yPos, life, "LEFT" );
   }

