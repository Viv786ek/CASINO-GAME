#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules();

int main()
{
    string name;
    int amnt; 
    int bidamnt;
    int guess;
    int dice; 
    char choice;

    srand(time(0)); // Use for Generating Random Number Each Time.

 cout<<"\n===============================================================================================";
 cout<<"\n   CCCCC      A        SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n CC          A  A      SS             III     NN N   NN   OO      OO    ";
 cout<<"\nCC          A    A     SSSSSSSSS      III     NN  N  NN   OO      OO    ";
 cout<<"\n CC        AAAAAAAA           SS      III     NN   N NN   OO      OO    ";
 cout<<"\n   CCCCC  A        A   SSSSSSSSS   IIIIIIIII  NN     NN    OOOOOOOO     ";
 cout<<"\n===============================================================================================\n";
 
    cout <<"\nEnter Player Name: ";
    getline(cin, name);

    cout <<"\nDeposit Your Amount: $";
    cin >> amnt;
   
    do
    {
        system("cls");
        rules();
        do
        {
            cout <<"\nWelcome "<<name<<" Are You Ready To Play? "<<"\n\n"; 
 cout<<"Enter Bid Amount: $";
            cin >> bidamnt;
            if(bidamnt > amnt)
                cout <<"You Can not Bid More Than Current Amount\n"
                       <<"\nRe-enter Amount: ";
        }while(bidamnt > amnt);

        do
        {
            cout <<"Guess The Number Between 1 To 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "\nNumber Sholud Be Between 1 To 10\n"
                    <<"\nGuess Numer Again: ";
        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1;
   
        if(dice == guess)
        {
            cout <<"\nHurray You Won " << bidamnt * 10<<"$";
            amnt = amnt + bidamnt * 10;
        }
        else
        {
            cout << "Sorry You Lose "<< bidamnt <<"$\n";
            amnt = amnt - bidamnt;
        }

        cout << "\nThe Winning Number Was: " << dice <<"\n";
        cout << "\n"<<name<<", Your Remaining Amount Is " << amnt << "$\n";
        if(amnt == 0)
        {
            cout << "\nSorry You Don't Have Money To Play \n";
            break;
        }
        cout << "\nYou Want To Play Again Press (y/n)? "; 
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
   
    cout<<"\n===============================================================================================\n";
    cout << "Thanks For Playing Game Again Your Current Amount Is " << amnt << "$";
    cout<<"\n===============================================================================================\n";

    return 0;
}

void rules()
{
    system("cls");
    cout<<"\n===============================================================================================\n";
    cout << "\t\t\tGame Rules";
    cout<<"\n===============================================================================================";
    cout << "\n1. Choose Number Between 1 To 10";
    cout << "\n2. Winning Amount Will Be 10 Times Of Bid Amount";
    cout << "\n3. Loose Amount Will Be Biding Amount";
    cout << "\n4. You Can Leave A Game Any Time";
    cout<<"\n===============================================================================================\n";
}
