#include <iostream>
#include <ctime>

using namespace std;

// Functions
void title();
void update();
int randomNumber();
bool checker();

// Main function
int main()
{
    // Title
    title();
    cout << "[+] Estoy pensando en un numero del 1 al 10 \n"<<"[+] Tienes 3 intentos" << endl;

    // Game update funcion
    update();

    return 0;
}

// Game functions


// Title bulder
void title()
{
    string title = "<<ADIVINA EL NUMERO>>";
    cout << title << endl;
    for(int i = 0; i < title.size(); i++) {
        cout << "=";
    }cout << endl;  
}


// Random number generator
int randomNumber()
{
    int random;
    srand((unsigned)time(0));
    random = rand() % (11);
    return random;
}

// Checks if the user input number equals the random number
bool checker(int randomNumber, int userNumber)
{
    if (userNumber == randomNumber)
    {
        return true;
    }
    else {
        return false;
    }
    
}


// Update function
void update()
{
    int fails = 0;
    int lifes = 3;
    
    int userNum;
    int random = randomNumber();

    bool gameOver = false;

    while (gameOver == false)
    {
        cout << "[>>] Ingresa un numero: "; cin >> userNum;
        bool isCorrectAnswer = checker(random, userNum);
       

        if (isCorrectAnswer == true)
        {
            cout << "\n[+] Has ganado!" << endl;
            gameOver = true;
            system("pause");
        }
        else if(isCorrectAnswer == false) {
            lifes -= 1;
            fails += 1;
            if (lifes == 0 && fails == 3)
            {

            }
            else {
                cout << "[-] Oh no! Te has equivocado!. Ahora tienes " << lifes << " intentos." << endl;
            }
        }

        if (lifes == 0 && fails == 3)
        {
            gameOver = true;
            cout << "\n[-] Has perdido el juego :(" << endl;
            system("pause");
        }
    }    
}