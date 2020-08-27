#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <windows.h>


using namespace std;


/// ========================================================================== ///

//////////////////////////////// Before Main ///////////////////////////////////


///////////// Global Variables ///////////
    string burglarMasterKeyInput;
    string MasterKey = "74588";
    string mainDoorKey = "12345";
    bool switchcorridorlight = 0;
    bool switchmusic = 0;


//////////// Beeps ///////////////////

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
    Beep(500, 150);
}




///////////////// Main Door Burglar's Protocol /////////////////////////////
void mainDoorBurglarProtocol()
{
    ////////////// Burglar's Protocol //////////////
    cout << "You have entered three times wrong Key.." << endl;
    cout << "I have enabled Burglar's Protocol." << endl;
    cout << "Whole house is getting sealed." << endl;
    Beep(500, 10000);
    cout << "(the whole house got sealed with unbreakable shutters)" << endl;
    cout << "(Jarvis has also made calls to Master and Police also.)" << endl;
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
        cout << "Key Accepted. Burglar's Protocol is disabled." << endl;
        cout << "(The house is unsealed and the main door opens. Lights of corridor and kitchen are\
 turned on. Some basic lights of the house are also turned on.)" << endl;
        switchcorridorlight = 1;
        cout << "Master someone tried to enter your house and I have initiated Burglar's Protocol" << endl;
        cout << "Your house is in safe Hands. You don't need to worry." << endl;
        cout << "I have also called Police at that time. You can now ask the police about the\
 situation." << endl;
        cout << "Get Relax. Everything is safe." << endl;
        cout << "Do you want me to turn on the music?" << endl;
    string musicAnswer;
    musicAnswerAgain:
    getline(cin, musicAnswer);
    if (musicAnswer == "Yes" || musicAnswer == "yes" || musicAnswer == "Y" || musicAnswer == "y")
    {
        cout << "Playing Music.." << endl;
        switchmusic = 1;
        cout << "(music is playing)" << endl;
    }
    else if (musicAnswer == "No" || musicAnswer == "no" || musicAnswer == "N" || musicAnswer == "n")
    {
        cout << "Okay Sir..!" << endl;
    }
    else
    {
        cout << "Dont Understand you Sir.\nPlease tell me again: ";
        goto musicAnswerAgain;
    }


    }
}



/// =============================================================================== ///


main()
{
    
    ///////////// Opening statement //////////////
    cout << setw(50) << "Jarvis Home" << endl;
    cout << setw(53) << "A Smart Home Agent" << endl;

    ///////////// House Description //////////////
    cout << "(This house has 1 guest room, 1 master room, a kitchen, a drawing room and a corridor.\
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
        correctBeep();
        cout << "Welcome Master..!" << endl;
    }
    else if (mainDoorKeyInput == mainDoorKey)
    {
        cout << "Access Granted." << endl;
        correctBeep();
        cout << "Welcome Sir..!" << endl;
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
    cout << "(Lights of corridor and Kitchen are turned on. Some basic lights of the house\
 are also turned on)";
    cout << "Do you want me to turn on the music?" << endl;
    string musicAnswer;
    musicAnswerAgain:
    getline(cin, musicAnswer);
    if (musicAnswer == "Yes" || musicAnswer == "yes" || musicAnswer == "Y" || musicAnswer == "y")
    {
        cout << "Playing Music.." << endl;
        switchmusic = 1;
        cout << "(music is playing)" << endl;
    }
    else if (musicAnswer == "No" || musicAnswer == "no" || musicAnswer == "N" || musicAnswer == "n")
    {
        cout << "Okay Sir..!" << endl;
    }
    else
    {
        cout << "Dont Understand you Sir.\nPlease tell me again: ";
        goto musicAnswerAgain;
    }
    
    Corridor:
    
    
    
    

    return 0;
}
