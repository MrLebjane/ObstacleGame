#include <iostream>
#include <ctime>
#include "LibCommon.h"
#include "GameLib.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    Game objFractalImage; /// Creating an instance of the painter class.
    objFractalImage.CreateWorld();

    bool blnContinue=true;

    do
    {
        system("cls");

        objFractalImage.print(); /// Delegation is going to take place here.

        cout<<"Get Player(P) to Goal($) without touching the rocks( R)"<<endl;
        cout<<endl;
        cout<<"W-UP"<<endl;
        cout<<"S-Down"<<endl;
        cout<<"A-Left"<<endl;
        cout<<"D-Right"<<endl;
        cout<<"X-Exit"<<endl;
        cout<<endl;
        cout<<"Enter Action"<<endl;
        char chInput='\0';
        cin>>chInput;

        switch(tolower(chInput))
        {
        case 'w':
            objFractalImage.Move(chInput);
            break;

        case 's':
            objFractalImage.Move(chInput);
            break;

        case 'a':
            objFractalImage.Move(chInput);
            break;

        case 'd':
            objFractalImage.Move(chInput);
            break;

        case 'x':
            blnContinue=false;
            break;

        default:
            cerr<<"Invalid Input.Enter the correct Option"<<endl;
            system("pause");
            break;
        }

    }while(blnContinue);

    return SUCCESS;
}
