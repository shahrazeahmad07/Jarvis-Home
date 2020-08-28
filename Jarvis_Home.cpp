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
    string musicAnswer;

    bool switchcorridorlight = 0;
    bool switchMasterRoomLight = 0;
    bool switchGuestRoomLight = 0;
    bool switchLivingRoomLight = 0;
    
    bool switchmusic = 0;
    bool Master = 0;
    bool Guest = 0;
    bool switchCurtain = 0;
    bool switchTv = 0;
    


////////////////// Beeps ///////////////////

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

inline void optionSelectYesBeep()
{
    Beep(500, 150);
}

inline void noBeep()
{
    Beep(130, 150);
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
    cout << "(Jarvis has called Master and Police)" << endl;
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
        Master = 1;
        cout << "Key Accepted. Burglar's Protocol is disabled." << endl;
        cout << "(The house is unsealed and the main door opens. Lights of corridor and kitchen are\n\
 turned on. Some basic lights of the house are also turned on.)" << endl;
        switchcorridorlight = 1;
        cout << "Master someone tried to broke into your house and I have initiated Burglar's Protocol" << endl;
        cout << "Your house is in safe Hands. You don't need to worry." << endl;
        cout << "I have also called Police at that time. You can now ask the police about the\n\
 situation." << endl;
        cout << "Get Relax. Everything is safe." << endl;        
    }
}


//////////////////////////////// Guest Check /////////////////////////////////////
void guestCheck()
{
    cout << "Is Someone else with you?" << endl;
    string someoneAnswer;
    someoneAnswerAgain:
    getline (cin, someoneAnswer);
    if (someoneAnswer == "Yes" || someoneAnswer == "YES" || someoneAnswer == "yes" || someoneAnswer == "y" || someoneAnswer == "Y")
    {
        Guest = 1;
        cout << "O Nice. Welcome our Guest.. This is me Jarvis." << endl;
    }
    else if (someoneAnswer == "No" || someoneAnswer == "NO" || someoneAnswer == "no" || someoneAnswer == "n" || someoneAnswer == "N")
    {
        cout << "Okay Sir.." << endl;
    }
    else
    {
        cout << "I Dont understand you Master. Plz Answer Again: ";
        goto someoneAnswerAgain;
    }
}


/// =============================================================================== ///


main()
{
    
    ///////////// Opening statement //////////////
    cout << setw(50) << "Jarvis Home" << endl;
    cout << setw(53) << "A Smart Home Agent" << endl;

    ///////////// House Description //////////////
    cout << "(This house has 1 guest room, 1 master room, a kitchen, a drawing room and a corridor.\n\
 There is only one door through which you can enter or leave the house. The Master room has some\n\
 more security features which only master can access. Only Master has a special security key (Master\n\
 key) with which he can open any door of the house. There is also a safe room in Master room\n\
 which is accessed by master key only. The temperature of the house is fully maintained by\n\
 automatic temperature controller. The house has some more features related to different\n\
 appliances of the house. The Jarvis(AI Assistant) take care of different things of house\n\
 automatically.)" << endl;


    ///////////////////////////// Main Door //////////////////////////////
    cout << setw(40) << "(Main Door) ";
    cout << "Enter key to open: ";
    string mainDoorKeyInput;
    int mainDoorKeyTries = 0;
    mainDoorKeyInputAgain:
    getline(cin, mainDoorKeyInput);
    if (mainDoorKeyInput == MasterKey)
    {
        correctBeep();
        Master = 1;
        cout << "Access Granted." << endl;
        cout << "Welcome Master..!" << endl;

    }
    else if (mainDoorKeyInput == mainDoorKey)
    {
        correctBeep();
        Guest = 1;
        cout << "Access Granted." << endl;
        cout << "Welcome Sir..!" << endl;
    }
    else
    {
        wrongBeep();
        cout << "Wrong key. Access Denied." << endl;
        mainDoorKeyTries += 1;
        if (mainDoorKeyTries == 3)
        {
            mainDoorBurglarProtocol();
            goto Corridor;
        }
        cout << "Enter again: ";
        goto mainDoorKeyInputAgain;
    }

    //////////////////////////// Corridor //////////////////////////////
    switchcorridorlight = 1;
    cout << "(Main Door opens. Lights of corridor and Kitchen are turned on. Some basic lights\n\
 of the house are also turned on)" << endl;

    Corridor:
    if (Master == 1)
    {
        guestCheck();
        if (Guest == 0)
        {
            cout << "Do you want me to turn on the music?" << endl;
            musicAnswerAgain:
            getline(cin, musicAnswer);
            if (musicAnswer == "Yes" || musicAnswer == "YES" || musicAnswer == "yes" || musicAnswer == "Y" || musicAnswer == "y")
            {
                optionSelectYesBeep();
                cout << "Playing Music.." << endl;
                switchmusic = 1;
                cout << "(music is playing)" << endl;
            }
            else if (musicAnswer == "No" || musicAnswer == "NO" || musicAnswer == "no" || musicAnswer == "N" || musicAnswer == "n")
            {
                noBeep();
                cout << "Okay Master..!" << endl;
            }
            else
            {
                wrongBeep();
                cout << "I Dont Understand you Master.\nPlease tell me again: ";
                goto musicAnswerAgain;
            }
        }
    }
    


    //////////////////////// Corridor Options /////////////////////////


    cout << endl;
    cout << "    1) Master Room" << endl;
    cout << "    2) Guest Room" << endl;
    cout << "    3) Living Room" << endl;
    cout << "    4) Kitchen" << endl;
    cout << "    5) Lights" << endl;
    cout << "    6) Music" << endl;
    cout << "    7) Go Out of the house(Temperory)" << endl;
    cout << "    8) Leave house" << endl;
    cout << endl;

    //////////////////// Corridor Option Select //////////////////////
    int corridorOptionSelect;
    corridorOptionSelectAgain:
    while (!(cin >> corridorOptionSelect))
    {
        cout << "Invalid Input. Select Again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ///////////////////// Corridor Switch /////////////////////////////
    switch (corridorOptionSelect)
    {
    case 1:
        cout << "Master room" << endl;
        break;

    case 2:
        cout << "Guest room" << endl;
        break;

    case 3:
        cout << "Living room" << endl;
        break;

    case 4:
        cout << "Kitchen" << endl;
        break;

    case 5:
        cout << "Lights" << endl;
        break;

    case 6:
        cout << "Music" << endl;
        break;

    case 7:
        cout << "Go out of the house (Temperory)" << endl;
        break;

    case 8:
        cout << "Leave house" << endl;
        break;
    
    default:
        cout << "Invalid Input. Select Again: ";
        goto corridorOptionSelectAgain;
    }

    return 0;
}
