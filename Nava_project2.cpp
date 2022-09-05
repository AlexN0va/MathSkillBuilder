// navaa_p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//7/24/2022
/*Math skill Builder program is intended to give you mathimatical questions of your choosing.
* Using functions for alogorithms that check useer input or randomly choose the question. 
*/
#include <iostream> //console
#include <cstdlib>  //for random numbers
#include <ctime>    //time. for random numbers
#include <cmath>    //math. for math questions
#include <iomanip>  //formatting. data validation and simple formatting

using namespace std;

//#######################################################################################################

//Function Prototypes
    
    //program user interface in main
    void programInfo();
    void mathSkillBuilderMenu(/*out*/ int& choice);
    void processProbSets(/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect);
    void printReport(/*in*/ int choice,/*in*/ int numProbSets,/*in*/ int numCorrect);

    //overloaded functions accessed by Math Builder Skill set modules for random number generation    
    void generateOperands(/*out*/ double& num1, /*out*/ double& num2);
    void generateOperands(/*out*/ double& num1, /*out*/double& num2,/*out*/double& num3);

    //various modules to process Math Builder Skill sets
    void arithmeticProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount);
    void geometryProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount);
    void statisticsProbSet(/*in*/ int numProbSets, /*out */ int& correctCount);
    void checkAnswer(/*in*/ double userAnswer, /*in*/ double correctAnswer, /*out*/ int& correctCount);

//#######################################################################################################

//global constants
    const int PROBSPERSET = 4;            // number of problems in each Math Skill Builder set
    const int MIN_NUM = 1, MAX_NUM = 10;  // random number range used for operands and arguments in each problem
    const double PI = 3.141593;           // geometry problems

//#######################################################################################################

int main()
{
    cout << showpoint << fixed << setprecision(2); // formatted number display
    srand(time(0));                               // seed the random number generator

    int choice = 0, numProbSets = 0, numCorrect = 0;    //input we will get out of functions
        
    programInfo();  //program info for the user
    mathSkillBuilderMenu(choice);   //Menu for user to choose what kind of question set they want

    while (choice != 4) //if choice equals for then break program
    {
        processProbSets(choice, numProbSets, numCorrect);   //ask how many sets of question they want then display questions
        printReport(choice, numProbSets, numCorrect);   //display the report results of question right and wrong
        mathSkillBuilderMenu(choice);   //display the options of what set of question again
 
       
    }

    cout << "\n\nNow exiting MATH SKILL BUILDER program ...." << endl;

    return 0;
}
//#######################################################################################################
void programInfo()
{

/*
   The programInfo function provides a few details about the math skill builder program,
   the menu driven user interface, the type of skill sets and the problems in each set are
   generated and user response is assessed.
   pre: none
   post: Formatted display of program information displayed in console output
*/

    cout << "                       MATH IS FUN                                            " << endl;
    cout << "The Math Skill Builder program will assess basic mathematics skills.          " << endl;
    cout << "Each Math skill builder set generates four problems using randomly            " << endl;
    cout << "generated numbers in the range of 1 to 10, stored as double values.\n         " << endl;
    cout << "The randomly generated numbers are to be used as operands or arguments        " << endl;
    cout << "for the various arithmetic, geometry or other problem types to be generated   " << endl;
    cout << "in each Math skill builder set. User response to a problem is compared to the " << endl;
    cout << "correct answer and an appropriate message is displayed.\n                     " << endl;

    cout << "A menu driven interface provides the user an opportunity to select a specific " << endl;
    cout << "Math Builder Skill set to try and the program interface design algorithms are " << endl;
    cout << "built with expandability in mind to allow for (1) additional problem sets or  " << endl;
    cout << "modules to be added or (2) additional different problem types in each set or  " << endl;
    cout << "(3) a larger random number range.\n                                           " << endl;

    cout << "Program Assertions: When comparing two double values with precision (for eg., " << endl;
    cout << "in comparing user response to the correct answer for a double quotient result " << endl;
    cout << "or mixed type calculation the user is reminded to provide a response rounded  " << endl;
    cout << "to two decimal places, as a precision criteria of less than .01 will be used  " << endl;
    cout << "to determine equality. Expect a few floating point representational errors.   " << endl;
}
//#######################################################################################################
void mathSkillBuilderMenu(/*out*/ int& choice)
{
    /*
  The mathSkillBuilderMenu function includes a formatted display of 4 menu choices and a
  leading prompt for user input is provided.

  Input validation is included for out of range choice or non alpha character input. With
  an appropriate message and a re-input is allowed. The validated input is passed
  through a reference parameter variable choice to the calling code.
  pre: none
  post: Formatted display of program information displayed. A value for reference parameter choice
        has been entered by the user and validated. Range validation (1-4) and a cin fail state will
        allow user to reenter a new value.
*/
    cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << setw(50) << "-  MATH SKILL BUILDER SETS - Select one  -" << endl;
    cout << setw(50) << "*        1. BASIC ARITHMETIC             *" << endl;
    cout << setw(9) << char(227) << "        2. BASIC GEOMETRY               " << char(227) << endl;
    cout << setw(50) << "%        3. BASIC STATISTICS             %" << endl;
    cout << setw(50) << "\\        4. EXIT MATH IS FUN             \\" << endl;
    cout << setw(50) << "++++++++++++++++++++++++++++++++++++++++++" << endl;

    cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
    cin >> choice;
    cout << "\n-------------------------------------------------------------------------------------" << endl;

    while (choice < 1 || choice > 4 || !cin) //checks user input for numbers outside of range and other data types (failstate)
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "OOPS, Invalid choice? " << endl;
        cout << "\nSELECT A MATH SKILL BUILDER SET OR TYPE 4 TO EXIT: ";
        cin >> choice;
        cout << "\n-------------------------------------------------------------------------------------" << endl;

    }
}
//#######################################################################################################
void processProbSets(/*in*/ int choice, /*out*/ int& numProbSets, /*out*/ int& numCorrect)
{
    /*
    * this functions purpose is to ask how many sets of questions user wants and also calls specific funtion according to their choice of skill set.
    * pre:use must have choosen a valid choice of skill set
    * post: determine how many sets of questions user wants and call function to display the questions
    
    */
        switch (choice)
        {

        case(1):
            cout << "\nMATH BUILDER SKILL SET#1 selected. This skill set contains a series of 4 problems in the set." << endl;
            cout << "\nHow many times you wish to attempt this current set (enter 1-5): " << endl;
            cin >> numProbSets;

            arithmeticProbSet(numProbSets, numCorrect);
            break;

        case(2):
            cout << "MATH BUILDER SKILL SET#2 selected. This skill set contains a series of 4 problems in the set." << endl;
            cout << "\nHow many times you wish to attempt this current set (enter 1-5): " << endl;
            cin >> numProbSets;

            geometryProbSet(numProbSets, numCorrect);
            

            break;
        case(3):
            cout << "MATH BUILDER SKILL SET#3 selected. This skill set contains a series of 4 problems in the set." << endl;
            cout << "\nHow many times you wish to attempt this current set (enter 1-5): " << endl;
            cin >> numProbSets;

            statisticsProbSet(numProbSets, numCorrect);
            break;

        default:
            cout << "Not one" << endl;

            break;

        }
    

}
//#######################################################################################################
void printReport(/*in*/ int choice,/*in*/ int numProbSets,/*in*/ int numCorrect)
{
    /*
    * display the results of how many question gotten right and wrong, but also the percentage rate
    * pre:processProbSet mus have ran a specific funtion based on user choice of skill set. numCorrect, numProbSets must have values based on userAnswers
    * post:display results of skill set questions.
    */
    switch (choice) 
    {

    case(1):
        cout << "================================================================="
            << "\nBasic Arithmetic Skill Set: You got " << numCorrect<< " correct out of " << numProbSets * 4 << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "% "
            << "\n=================================================================" << endl;
        break;

    case(2):
        cout << "================================================================="
            << "\nBasic Geometry Skill Set: You got " << numCorrect << " correct out of " << numProbSets * 4 << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "% "
            << "\n=================================================================" << endl;
        break;
    case(3):
        cout << "================================================================="
            << "\nBasic Statistics Skill Set: You got " << numCorrect << " correct out of " << numProbSets * 4 << " for " << (100 * numCorrect) / (PROBSPERSET * numProbSets) << "% "
            << "\n=================================================================" << endl;
        break;

    default:
        cout << "Not one" << endl;

        break;

    }


}
//#######################################################################################################
//#######################################################################################################
void generateOperands(/*out*/ double& num1, /*out*/ double& num2)
{
    /*
    * pre:num1 and num2 must be declared
    * post: output random numbers named num1 and num2
    */
    num1 = MIN_NUM + rand() % MAX_NUM;
    num2 = MIN_NUM + rand() % MAX_NUM;

}
//#######################################################################################################
void generateOperands(/*out*/ double& num1, /*out*/double& num2,/*out*/double& num3)
{
    /*
    * pre:num1 and num2 must be declared
    * post: output random numbers named num1, num2, and num3
    */
    num1 = MIN_NUM + rand() % MAX_NUM;
    num2 = MIN_NUM + rand() % MAX_NUM;
    num3 = MIN_NUM + rand() % MAX_NUM;
}
//#######################################################################################################
void arithmeticProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount)
{
    /*
    * pre:user choice  == 1, valid number for numprobSets
    * post: display all the questions and ask for answers, also checks questions trhough another function and outputs correctCount
    
    */
    double num1 = 0, num2 = 0, userAnswer = 0, correctAnswer = 0;   //declare varibales
    correctCount = 0;

    cout << "Arithmetic skill sets" << endl;


    for (int probSets = 1; probSets <= numProbSets; probSets++)
    {
       
        cout << "\nArithmetic Problem Set#" << probSets << "; " //dipsplays the current number of problem sets
            << "\n-------------------------" << endl;

        for (int probNum = 1; probNum <= PROBSPERSET; probNum++) {

            //pretest nested for loop. first loop determines how many sets fo question there wil be. 
            //Second for loop is the Problems per set, there are four problems pre set therefore runs four times
            generateOperands(num1, num2);   //generate two random numbers for each question

            switch (probNum) //switch statment has four and will loop through all of them after each question has been answered
            {
            case(1)://question one
                cout << num1 << " + " << num2 << " = ";
                correctAnswer = num1 + num2;
                break;

            case(2)://question two
                cout << num1 << " - " << num2 << " = ";
                correctAnswer = num1 - num2;
                break;

            case(3)://question three
                cout << num1 << " * " << num2 << " = ";
                correctAnswer = num1 * num2;
                break;
            case(4)://question four           
                cout << "Type a responses rounded to two decimal places below..." << endl;
                cout << num1 << " / " << num2 << " = ";
                correctAnswer = num1 / num2;
                break;
            default:
                cout << "something went wrong!" << endl;
                break;


            }
            cin >> userAnswer;  //inputs answer after each case

            checkAnswer(userAnswer, correctAnswer, correctCount);
        }

    }
}
//#######################################################################################################
void geometryProbSet(/*in*/ int numProbSets, /*out*/ int& correctCount)
{
    /*
* pre:user choice  == 2, valid number for numprobSets
* post: display all the questions and ask for answers, also checks questions trhough another function and outputs correctCount

*/
    double num1 = 0, num2 = 0, num3 = 0, userAnswer = 0, correctAnswer = 0; //declare variables to be eventually initalized
    correctCount = 0;

    cout << "Geometry skill sets" << endl;


    for (int probSets = 1; probSets <= numProbSets; probSets++) {

        cout << "\nGeometry Problem Set#" << probSets << "; "
            << "\n-------------------------" << endl;

        for (int probNum = 1; probNum <= PROBSPERSET; probNum++) {
            //pretest nested for loop. first loop determines how many sets fo question there wil be. 
//Second for loop is the Problems per set, there are four problems pre set therefore runs four times

            generateOperands(num1, num2, num3);

            switch (probNum) {
            case(1):    //question one
                cout << "Calculate the area of a Triangle given base and height: Base = " << num1 << ", Height = " << num2 << endl;
                cout << "Area of Triangle is: ";
                correctAnswer = 0.5 * num1 * num2;
                break;

            case(2):    //question two
                cout << "Calculate the perimeter of a Triangle with three sides: side1 = " << num1 << ", side2 = " << num2 << ", side3 = " << num3 << endl;
                cout << "Perimeter of Triangle is: ";
                correctAnswer = num1 + num2 + num3;
                break;

            case(3):    //question three
                cout << "Calculate the perimeter of a Rectangle : Length = " << num1 << " and Width = " << num2 << endl;
                cout << "Perimeter of Rectangle is: ";
                correctAnswer = 2*(num1 + num2);
                break;
            case(4):    //question four               
                cout << "Calculate the area of a Circle given radius: Radius = " << num1 << " and Pi(Ï) is " << PI;
                cout << "\nType a responses rounded to two decimal places below..." << endl;
                cout << "\nArea of Circle is: ";
                correctAnswer = PI * num1 * num1;
                break;
            default:
                cout << "something went wrong!" << endl;
                break;


            }

            cin >> userAnswer;

            checkAnswer(userAnswer, correctAnswer, correctCount);

        }

    }

}
//#######################################################################################################
void statisticsProbSet(/*in*/ int numProbSets, /*out */ int& correctCount)//for extra credit only
{
    /*
    * to be modificated... This is intended to ask questions regarding about statistics
* pre:user choice  == 3, valid number for numprobSets
* post: display all the questions and ask for answers, also checks questions trhough another function and outputs correctCount
*/
    double num1 = 0, num2 = 0, num3 = 0,  userAnswer = 0, correctAnswer = 0;
    correctCount = 0;

    cout << "Statistics skill sets" << endl;

    for (int probSets = 1; probSets <= 1; probSets++) {
        //for loop runs one until further modification of the program
        cout << "\nStatistics Problem Set#" << probSets << "; "
            << "\n-------------------------" << endl;
        cout << "4 Statistics formulas to be coded...."
            << "\n-------------------------" << endl;
        /*
        for (int probNum = 1; probNum <= PROBSPERSET; probNum++) {

            generateOperands(num1, num2, num3);

            switch (probNum) {
            case(1):
                cout << "Calculate the average of " << num1 << ", " << num2 << ", " << num3 << endl;
                cout << "Average = ";
                correctAnswer = (num1 + num2 + num3) / 0.5;
                break;

            case(2):
                cout << "Calculate the median of " << num1 << ", " << num2 << ", " << num3 <<  endl;
                cout << "Average = ";
                correctAnswer = (num1 + num2 + num3) / 5;
                break;

            case(3):
                cout << "Calculate the perimeter of a Rectangle : Length = " << num1 << " and Width = " << num2 << endl;
                cout << "Perimeter of Rectangle is: ";
                correctAnswer = 2 * (num1 + num2);
                break;
            case(4):
                cout << "Type a responses rounded to two decimal places below..." << endl;
                cout << "Calculate the area of a Circle given radius: Radius = " << num1 << " and Pi(Ï) is " << PI;
                cout << "Area of Circle is: ";
                correctAnswer = PI * num1 * num1;
                break;
            default:
                cout << "something went wrong!" << endl;
                break;


            }
        

            cin >> userAnswer;

            checkAnswer(userAnswer, correctAnswer, correctCount);
        }
        */

        

    }
}
//#######################################################################################################
void checkAnswer(/*in*/ double userAnswer, /*in*/ double correctAnswer, /*out*/ int& correctCount)
{
    /*
    * Function's purpose is to check the input that the user inputs for each question, and determine if it is correct or wrong or if the value is even valid
    * pre:needs a userAnswer and the correctAnswer to compare
    * post: display whether correct or wrong and if wrong give answer. If asnwer is correct then increment the correctCount plus one for results and printReport function.(display right or wrong, output correctCount)
    */
    while (!cin) //if answer is valid(failstate). lets user answer again
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "OOPS,that is an input error. Please retype:";
        cin >> userAnswer;
    }
    
    if (userAnswer == correctAnswer) //if userAsner == correct answer, incremement correctcount plus one, and display correct
    {
        cout << "Correct! " << endl;
        correctCount++;
        cout << "-------------------------" << endl;
    }
    
    else //if wrong then display wrogn and give answer
    {
        cout << "Incorrect. Correct answer displayed with precision of .01 = " << correctAnswer << endl;
        cout << "-------------------------" << endl;
    }
}
