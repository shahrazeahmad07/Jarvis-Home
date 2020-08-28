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
    Beep(400, 150);
}

inline void optionSelectYesBeep()
{
    Beep(400, 150);
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
    if (Guest != 1)
    {
        cout << "Is Someone else with you?" << endl;
        string someoneAnswer;
        someoneAnswerAgain:
        getline (cin, someoneAnswer);
        if (someoneAnswer == "Yes" || someoneAnswer == "YES" || someoneAnswer == "yes" || someoneAnswer == "y" || someoneAnswer == "Y")
        {
            optionSelectYesBeep();
            Guest = 1;
            cout << "O Nice. Welcome our Guest.. This is me Jarvis." << endl;
        }
        else if (someoneAnswer == "No" || someoneAnswer == "NO" || someoneAnswer == "no" || someoneAnswer == "n" || someoneAnswer == "N")
        {
            noBeep();
            cout << "Okay Sir.." << endl;
        }
        else
        {
            wrongBeep();
            cout << "I Dont understand you Master. Plz Answer Again: ";
            goto someoneAnswerAgain;
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
                cout << "I Dont Understand you Master. Please answer again: ";
                goto musicAnswerAgain;
            }
        }
    }
    


    //////////////////////// Corridor Options /////////////////////////

    corridorOption:
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


    //////////////////// Corridor Switch ////////////////////////////
    switch (corridorOptionSelect)
    {

    //////////////////// Leave House /////////////////////////////
    case 8:
        optionSelectYesBeep();
        if (Master == 1 && Guest == 1)
        {
            cout << "Who is going?" << endl;
            cout << "   1) Both" << endl;
            cout << "   2) Master" << endl;
            cout << "   3) Guest" << endl;
            cout << "   4) No one" << endl;
            int leaveAnswer;
            leaveAnswerAgain:
            while (!(cin >> leaveAnswer))
            {
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (leaveAnswer)
            {
            case 1:
                optionSelectYesBeep();
                switchMasterRoomLight = 0;
                switchcorridorlight = 0;
                switchCurtain = 0;
                switchmusic = 0;
                switchTv = 0;
                switchGuestRoomLight = 0;
                switchLivingRoomLight = 0;
                Master = 0;
                Guest = 0;
                cout << "(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
                cout << "(Curtains are also closed)" << endl;
                cout << "Bye Everyone.. Take care of yourselves." << endl;
                cout << "(Main Door gets locked after both of you gets out of the house)" << endl;
                break;

            case 2:
                optionSelectYesBeep();
                Master = 0;
                cout << "Goodbye Master.. See you soon." << endl;
                cout << "(Door gets locked when you get out of the house)" << endl;
                break;

            case 3:
                optionSelectYesBeep();
                Guest = 0;
                cout << "Goodbye Sir.. Take care of yourself." << endl;
                cout << "(Door gets locked when you get out of the house)" << endl;
                break;

            case 4:
                optionSelectYesBeep();
                cout << "Okay..!" << endl;
                goto corridorOption;
            
            default:
                wrongBeep();
                cout << "Invalid option. Select Again: ";
                goto leaveAnswerAgain;
            }
        }
        else if (Master == 1 && Guest == 0)
        {
            switchMasterRoomLight = 0;
            switchcorridorlight = 0;
            switchCurtain = 0;
            switchmusic = 0;
            switchTv = 0;
            switchGuestRoomLight = 0;
            switchLivingRoomLight = 0;
            Master = 0;
            cout << "(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
            cout << "(Curtains are also closed)" << endl;
            cout << "Bye Master.. See you soon." << endl;
            cout << "(Main Door gets locked after you get out of the house)" << endl;
        }
        else if (Master == 0 && Guest == 1)
        {
            switchMasterRoomLight = 0;
            switchcorridorlight = 0;
            switchCurtain = 0;
            switchmusic = 0;
            switchTv = 0;
            switchGuestRoomLight = 0;
            switchLivingRoomLight = 0;
            Guest == 0;
            cout << "(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
            cout << "(Curtains are also closed)" << endl;
            cout << "Good Bye Sir.. Take care of yourself..!" << endl;
            cout << "(Main Door gets locked after you get out of the house)" << endl;
        }
        
        exit(0);

    default:
        wrongBeep();
        cout << "Invalid Option. Select again: ";
        goto corridorOptionSelectAgain;
    }

    return 0;
}
