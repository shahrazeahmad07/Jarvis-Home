#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <windows.h>


using namespace std;

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


main()
{
    ///////////// Burglar's variable ///////////
    string burglarMasterKey;

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
    cout << setw(50) << "Main Door";
    cout << "Enter key to open: ";
    string MasterKey = "74588";
    string mainDoorKey = "12345";
    string mainDoorKeyInput;
    mainDoorKeyInputAgain:
    getline(cin, mainDoorKeyInput);
    int mainDoorKeyTries = 0;
    if (mainDoorKeyInput == MasterKey)
    {
        cout << "Access Granted." << endl;
        cout << "Welcome Master..!" << endl;
        correctBeep();
    }
    else if (mainDoorKeyInput == mainDoorKey)
    {
        cout << "Access Granted." << endl;
        cout << "Welcome Sir..!" << endl;
        correctBeep();
    }
    else
    {
        cout << "Wrong key. Access Denied." << endl;
        cout << "Enter again: ";
        wrongBeep();
        ++mainDoorKeyTries;
        if (mainDoorKeyTries == 3)
        {
            goto BurglarsProtocol;
        }
        goto mainDoorKeyInputAgain;
    }
    
    
    ////////////// Burglar's Protocol //////////////
    BurglarsProtocol:
    cout << "You have entered three times wrong Key.." << endl;
    cout << "I have enabled Burglar's Protocol." << endl;
    cout << "Whole house is sealed." << endl;
    Beep(500, 50000000);
    cout << "(Jarvis made a call to Master and Police also.)" << endl;
    cout << "(Police is comming)" << endl;
    cout << "(Burglar's Protocol can be deactivated with Master key only)";
    getline (cin, burglarMasterKey);
    if (burglarMasterKey == MasterKey)
    {
        cout << "Key Accepted. Burglar's Protocol is disabled." << endl;
        cout << "(The house is unsealed and the main door opens.)" << endl;
        cout << "Master someone tried to enter your house and I have initiated Burglar's Protocol" << endl;
        cout << "Your house is safe Hands. You don't need to worry.";
        
    }

    return 0;
}
