#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <windows.h>


using namespace std;

///////////// Global Variables ///////////
    string burglarMasterKeyInput;
    string MasterKey = "74588";
    string mainDoorKey = "12345";


inline void wrongBeep()
{
    for (int i = 0; i < 3; i++)
        {
            Beep(200, 100);
        }
}

inline void correctBeep()
{
    Beep(150, 800);
}

void mainDoorBurglarProtocol()
{
    ////////////// Burglar's Protocol //////////////
    cout << "You have entered three times wrong Key.." << endl;
    cout << "I have enabled Burglar's Protocol." << endl;
    cout << "Whole house is getting sealed." << endl;
    Beep(500, 10000);
    cout << "(the whole house begans to seal (unbreakable shutters gets down))" << endl;
    cout << "(Jarvis made a call to Master and Police also.)" << endl;
    cout << "(Police is comming)" << endl;
    cout << "(Burglar's Protocol can be deactivated with Master key only)" << endl;
    burglarMasterKeyInputAgain:
    getline (cin, burglarMasterKeyInput);
    if (burglarMasterKeyInput != MasterKey)
    {
        cout << "Wrong key." << endl;
        goto burglarMasterKeyInputAgain;
    }
    
    else
    {
        correctBeep();
        Beep(500, 150);
        cout << "Key Accepted. Burglar's Protocol is disabled." << endl;
        cout << "(The house is unsealed and the main door opens. Lights of corridor and kitchen\
 is turned on.)" << endl;
        cout << "Master someone tried to enter your house and I have initiated Burglar's Protocol" << endl;
        cout << "Your house is safe Hands. You don't need to worry." << endl;
        cout << "I have also called Police at that time. You can now ask the police about the\
 situation." << endl;
        cout << "Get Relax. Everything is safe." << endl;

    }
}


main()
{
    ///////////// Opening statement //////////////
    cout << setw(50) << "Jarvis Home" << endl;
    cout << setw(53) << "A Smart Home Agent" << endl;

    ///////////// House Description //////////////
    cout << "(This house has 1 guest room, 1 master room, a kitchen, a drawing room and a coridor.\
 There is only one door through which you can enter or leave the house. The Master room has some\
 more security features which only master can access. Only Master has a special security key (Master\
 key) with which he can open any door of the house. There is also a safe room in Master room\
 which is accessed by master key only. The temperature of the house is fully maintained by\
 automatic temperature controller. The house has some more features related to different\
 appliances of the house. The Jarvis(AI Assistant) take care of different things of house\
 automatically.)";


    ////////////// Main Door ////////////////////
    cout << setw(50) << "(Main Door) ";
    cout << "Enter key to open: ";
    string mainDoorKeyInput;
    int mainDoorKeyTries = 0;
    mainDoorKeyInputAgain:
    getline(cin, mainDoorKeyInput);
    if (mainDoorKeyInput == MasterKey)
    {
        cout << "Access Granted." << endl;
        cout << "Welcome Master..!" << endl;
        correctBeep();
        Beep(500, 80);
    }
    else if (mainDoorKeyInput == mainDoorKey)
    {
        cout << "Access Granted." << endl;
        cout << "Welcome Sir..!" << endl;
        correctBeep();
        Beep(500, 80);
    }
    else
    {
        cout << "Wrong key. Access Denied." << endl;
        wrongBeep();
        mainDoorKeyTries += 1;
        if (mainDoorKeyTries == 3)
        {
            mainDoorBurglarProtocol();
            goto Corridor;
        }
        cout << "Enter again: ";
        goto mainDoorKeyInputAgain;
    }

    ///////////// Corridor /////////////
    Corridor:
    cout << "corridor";
    
    
    

    return 0;
}
