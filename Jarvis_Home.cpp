#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <windows.h>

using namespace std;

/// ========================================================================== ///

//////////////////////////////// Before Main ///////////////////////////////////

///////////// Global Variables ///////////
string HaddaadKey = "74588";
string mainDoorKey = "12345";
string safeRoomKey = "Zombies";
string safekey = "Brains";
string emergencyKey = "IamHaddaad";

string burglarHaddaadKeyInput;
string musicAnswer;
string getBackIn;
string recipieAnswer;
string livingCurtainAnswer;
string guestIntruderInputKey;
string guestLeaveAnswer;
string livingLeaveAnswer;
string HaddaadLeaveAnswer;
string HaddaadBurglarSure;

string safeRoomKeyInput;
string safeKeyInput;
string safeCloseInput;
string HaddaadIntruderInputKey;

bool Haddaad = 0;
bool Guest = 0;

bool switchcorridorlight = 0;
///////// Corridor Music Switch /////////
bool switchmusic = 0;
int musicVolume = 67;

int proteinIngredients = 3;
int coffeeIngredients = 3;
int smoothieIngredients = 3;

bool switchHaddaadRoomLight = 0;
int HaddaadLightIntensity = 7;
bool switchHaddaadMusic = 0;
int HaddaadMusicVolume = 67;
bool switchHaddaadtv = 0;
int HaddaadTvChannel = 15;
int HaddaadTvVolume = 67;
bool HaddaadCurtain = 0;
bool HaddaadRoomLock = 0;
bool safeRoomLock = 1;

bool switchGuestRoomLight = 0;
int guestLightIntensity = 7;
bool switchGuestTv = 0;
int guestTvChannel = 10;
int guestTvVolume = 67;
bool switchGuestMusic = 0;
int guestMusicVolume = 67;
bool guestCurtain = 0;
bool guestRoomLock = 0;

bool switchLivingRoomLight = 0;
int livingLightIntensity = 7;
bool switchLivingRoomTv = 0;
int livingTvChannel = 05;
int livingTvVolume = 67;
bool livingRoomCurtains = 0;

int safeKeyTries = 0;
int safeRoomtries = 0;

bool IfBurglar = 0;
bool HaddaadBurglarCheck = 0;
bool safeBurglarCheck = 0;

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
    cout << "\tYou have entered three times wrong Key.." << endl;
    cout << "\tI have enabled Burglar's Protocol." << endl;
    cout << "\tWhole house is getting sealed." << endl;
    Beep(500, 10000);
    cout << "\t(All Doors have been locked)" << endl;
    cout << "\t(Jarvis has informed the Owner and notified District Police)" << endl;
    cout << "\t(Police is comming)" << endl;
    cout << "\t(Burglar's Protocol can be deactivated with Master key only)" << endl;
burglarHaddaadKeyInputAgain:
    getline(cin, burglarHaddaadKeyInput);
    if (burglarHaddaadKeyInput != HaddaadKey)
    {
        cout << "\tWrong key." << endl;
        goto burglarHaddaadKeyInputAgain;
    }

    else
    {
        correctBeep();
        Haddaad = 1;
        cout << "\tKey Accepted. Burglar's Protocol is disabled." << endl;
        cout << "\t(The house is unsealed and the main door opens. Lights of corridor and kitchen are\n\
\tturned on.)"
             << endl;
        switchcorridorlight = 1;
        cout << "\tHaddaad someone tried to broke into your house and I had initiated Burglar's Protocol" << endl;
        cout << "\tI had also notified district Police at that time." << endl;
        cout << "\tYour house is in safe Hands. You don't need to worry." << endl;
        cout << "\tGet Relax. Everything is safe." << endl;
    }
}

//////////////////////////////// Guest Check /////////////////////////////////////
void guestCheck()
{
    if (Guest != 1)
    {
        cout << "\tIs Someone else with you?" << endl;
        string someoneAnswer;
    someoneAnswerAgain:
        getline(cin, someoneAnswer);
        if (someoneAnswer == "Yes" || someoneAnswer == "YES" || someoneAnswer == "yes" || someoneAnswer == "y" || someoneAnswer == "Y")
        {
            optionSelectYesBeep();
            Guest = 1;
            cout << "\tGlad to hear that. Welcome to our Home.. This is Jarvis, Your Personal Home Assistant." << endl;
        }
        else if (someoneAnswer == "No" || someoneAnswer == "NO" || someoneAnswer == "no" || someoneAnswer == "n" || someoneAnswer == "N")
        {
            noBeep();
            cout << "\tOkay.." << endl;
        }
        else
        {
            wrongBeep();
            cout << "\tI did not understand it Haddaad. Plz repeat Again: " << endl;
            goto someoneAnswerAgain;
        }
    }
}

////////////////////////////////////// Music Check ////////////////////////////////
void musicCheck()
{
    if (switchmusic == 1)
    {
        cout << "\t(Music is playing in the background)" << endl;
    }
}

/////////////////////////////////////// Living room Curtains check /////////////////////////
void livingCurtainCheck()
{
    if (livingRoomCurtains == 0)
    {
        cout << "\t(Curtains are closed right now)" << endl;
    }
    else
    {
        cout << "\t(Curtains are open)" << endl;
    }
}

//////////////////////////////////// Living Room Tv Check ///////////////////////
void livingTvCheck()
{
    if (switchLivingRoomTv == 1)
    {
        cout << "\t(Tv is on and current channel is " << livingTvChannel << " and volume is " << livingTvVolume << ")" << endl;
    }
}

//////////////////////////////////// Guest Room Curtains Check ///////////////////////
void guestCurtainCheck()
{
    if (guestCurtain == 0)
    {
        cout << "\t(Curtains are closed)" << endl;
    }
    else
    {
        cout << "\t(Curtains are open)" << endl;
    }
}

//////////////////////////////////// Guest Room Tv Check ///////////////////////
void guestTvCheck()
{
    if (switchGuestTv == 1)
    {
        cout << "\t(Tv is on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
    }
}

////////////////////////////////////// Guest Music Check ////////////////////////////////
void GuestMusicCheck()
{
    if (switchGuestMusic == 1)
    {
        cout << "\t(Music is Playing in the background and music volume is " << guestMusicVolume << ")" << endl;
    }
}

/////////////////////////////////// Guest Room Lock Check ////////////////////////////////
void guestLockCheck()
{
    if (guestRoomLock == 1)
    {
        cout << "\t(Room door is locked)" << endl;
    }
    else
    {
        cout << "\t(Room door is not Locked)" << endl;
    }
}

/////////////////////////////////// Haddaad Tv Check ////////////////////////////////
void HaddaadTvCheck()
{
    if (switchHaddaadtv == 1)
    {
        cout << "\t(Tv is on and current channel is " << HaddaadTvChannel << " and volume is " << HaddaadTvVolume << ")" << endl;
    }
}

//////////////////////////////////////// Haddaad Music Check /////////////////////////////
void HaddaadMusicCheck()
{
    if (switchHaddaadMusic == 1)
    {
        cout << "\t(Music is Playing in the background and music volume is " << HaddaadMusicVolume << ")" << endl;
    }
}

////////////////////////////////////// Haddaad Curtain Check /////////////////////////////
void HaddaadCurtainCheck()
{
    if (HaddaadCurtain == 0)
    {
        cout << "\t(Curtains are closed)" << endl;
    }
    else
    {
        cout << "\t(Curtains are open)" << endl;
    }
}

////////////////////////////// Haddaad Room Lock Check /////////////////////////////
void HaddaadLockCheck()
{
    if (HaddaadRoomLock == 1)
    {
        cout << "\t(Room door is locked)" << endl;
    }
    else
    {
        cout << "\t(Room door is not Locked)" << endl;
    }
}

//////////////////////// Burglar's Protocol Check ////////////////////////
void HaddaadBurglarProtocolCheck()
{
    if (IfBurglar == 1)
    {
        cout << "\t(Burglar's Protocol is Enabled)" << endl;
    }
}

//////////////////////// Haddaad Room Burglar Check ////////////////////////
void HaddaadRoomBurglarCheck()
{
    if (HaddaadBurglarCheck == 1)
    {
        cout << "\t(There is a breacher in Haddaad's Room. Jarvis has Locked all the doors. Burglar Protocol has been activated.\n\
\tHe will not be able to escape untill someone open the door of Haddaad's Room..)"
             << endl;
    }
}

//////////////////////// Safe Room Burglar Check ////////////////////////
void safeRoomBurglarCheck()
{
    if (safeBurglarCheck == 1)
    {
        cout << "\t(There is a breacher in Safe Room. Jarvis has Locked all the doors. Burglar Protocol has been activated.\n\
\tHe will not be able to escape untill someone open the door of Safe Room)"
             << endl;
    }
}

///////////////////////////// Leave Function ////////////////////////////
inline void LeavingHouse()
{
    Haddaad = 0;
    Guest = 0;
    switchcorridorlight = 0;
    switchmusic = 0;
    musicVolume = 67;
    switchHaddaadRoomLight = 0;
    HaddaadLightIntensity = 7;
    switchHaddaadMusic = 0;
    HaddaadMusicVolume = 67;
    switchHaddaadtv = 0;
    HaddaadCurtain = 0;
    HaddaadRoomLock = 0;
    safeRoomLock = 1;
    switchGuestRoomLight = 0;
    guestLightIntensity = 7;
    switchGuestTv = 0;
    switchGuestMusic = 0;
    guestMusicVolume = 67;
    guestCurtain = 0;
    guestRoomLock = 0;
    switchLivingRoomLight = 0;
    livingLightIntensity = 7;
    switchLivingRoomTv = 0;
    livingRoomCurtains = 0;
    safeKeyTries = 0;
    safeRoomtries = 0;
}

/// =============================================================================== ///
/// =============================================================================== ///

main()
{
    cout << endl << endl;
    ///////////// Opening statement //////////////
    cout <<  "\t\t\t\t\t\t------This premises is controlled by Jarvis------" << endl;

    ///////////// House Description //////////////
    cout << "  (This house has a guest room, a Master (Haddaad) room, an open kitchen, a drawing room and a corridor.There is only one door through which you can enter or leave the\n\
  house. Master room has some more security features which only Haddaad can access. Only Haddaad has a special security key (Master key) with which he can\n\
  use special features. There is also a safe room in Master room which is accessed by Master key only. The temperature of  the house is fully maintained\n\
  by automatic temperature controller. The house has some more features related to different appliances of the house. The Jarvis(AI Assistant) take care of\n\
  different things of house automatically. The house is fitted with proximity sensors and detect that if a person is present in the room or not and if Jarvis\n\
  detects that no one is in a certain place and the appliances are on, She will turn them off automatically. Each room has attach bath which is not controlled\n\
  by Jarvis i.e. You can controll it manually.)"
         << endl << endl;
         cout << "\t\t\t\t\t\t      (The Owner of this Facility is Haddaad)" << endl << endl;

    ///////////////////////////// Main Door //////////////////////////////
    cout << "\t\t\t\t\t\t       (Main Door) ";
    cout << "Enter key to open: ";
    string mainDoorKeyInput;
    int mainDoorKeyTries = 0;
mainDoorKeyInputAgain:
    getline(cin, mainDoorKeyInput);
    if (mainDoorKeyInput == HaddaadKey)
    {
        correctBeep();
        Haddaad = 1;
        mainDoorKeyTries = 0;
        cout << "\tAccess Granted." << endl;
        cout << "\tWelcome Home Haddaad..!" << endl;
        if (IfBurglar == 1)
        {
            cout << "Burglar's Protocol is enabled by someone from your Room. Be Careful Haddaad." << endl;
        }
        if (HaddaadBurglarCheck == 1)
        {
            cout << "\tThere is a breacher in your Room. I have Locked all the doors. Burglar Protocol has been activated.\n\
\tI would recommend you to call the Police and get help from them.."
                 << endl;
        }
        if (safeBurglarCheck == 1)
        {
            cout << "\tThere is a breacher in your Safe Room. I have Locked all the doors. Burglar Protocol has been activated.\n\
\tI would recommend you to call the Police and get help from them.."
                 << endl;
        }
    }
    else if (mainDoorKeyInput == mainDoorKey)
    {
        correctBeep();
        Guest = 1;
        mainDoorKeyTries = 0;
        cout << "\tAccess Granted." << endl;
        cout << "\tWelcome Home..!" << endl;
        if (IfBurglar == 1)
        {
            cout << "\tBurglar's Protocol is enabled by someone from Haddaad's Room. Be Careful." << endl;
        }
        if (HaddaadBurglarCheck == 1)
        {
            cout << "\tThere is a breacher in Haddaad's Room. I have Locked all the doors. Burglar Protocol has been activated.\n\
\tI would recommend you to call the Police and get help from them.."
                 << endl;
        }
        if (safeBurglarCheck == 1)
        {
            cout << "\tThere is a breacher in your Safe Room. I have Locked all the doors. Burglar Protocol has been activated.\n\
\tI would recommend you to call the Police and get help from them.."
                 << endl;
        }
    }
    else
    {
        wrongBeep();
        cout << "\tWrong key. Access Denied." << endl;
        mainDoorKeyTries += 1;
        if (mainDoorKeyTries == 3)
        {
            mainDoorBurglarProtocol();
            goto Corridor;
        }
        cout << "\tEnter again: " << endl;
        goto mainDoorKeyInputAgain;
    }

    //========================================================================================//
    //===================================== Corridor =========================================//
    cout << "\t(Main Door opens)" << endl;

    if (switchcorridorlight == 0)
    {
        cout << "\t(the lights of the corridor and kitchen turns on)" << endl;
        switchcorridorlight = 1;
    }
    else
    {
        cout << "\t(the Lights of corridor and Kitchen are already on)" << endl;
    }
    
Corridor:
    if (Haddaad == 1)
    {
        if (IfBurglar == 0 && HaddaadBurglarCheck == 0 && safeBurglarCheck == 0)
        {
            guestCheck();
            if (Guest == 0)
            {
                cout << "\tDo you want me to turn on the music?" << endl;
            musicAnswerAgain:
                getline(cin, musicAnswer);
                if (musicAnswer == "Yes" || musicAnswer == "YES" || musicAnswer == "yes" || musicAnswer == "Y" || musicAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "\tPlaying Music.." << endl;
                    switchmusic = 1;
                    cout << "\t(music is playing now)" << endl
                         << endl;
                }
                else if (musicAnswer == "No" || musicAnswer == "NO" || musicAnswer == "no" || musicAnswer == "N" || musicAnswer == "n")
                {
                    noBeep();
                    cout << "\tOkay Haddaad..!" << endl;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it Haddaad. Please repeat again: " << endl;
                    goto musicAnswerAgain;
                }
            }
        }
    }

//////////////////////// Corridor Options /////////////////////////
corridorOption:
    cout << endl;
    cout << "\t(You are in the corridor)" << endl;
    musicCheck();
    cout << endl;
    HaddaadBurglarProtocolCheck();
    HaddaadRoomBurglarCheck();
    safeRoomBurglarCheck();
    cout << endl;
    cout << "\t    1) Haddaad's Room" << endl;
    cout << "\t    2) Guest Room" << endl;
    cout << "\t    3) Living Room" << endl;
    cout << "\t    4) Kitchen" << endl;
    cout << "\t    5) Lights" << endl;
    cout << "\t    6) Music" << endl;
    cout << "\t    7) Go Out of the house(Temperory)" << endl;
    cout << "\t    8) Leave house" << endl;
    cout << endl;

    //////////////////// Corridor Option Select //////////////////////
    int corridorOptionSelect;
corridorOptionSelectAgain:
    while (!(cin >> corridorOptionSelect))
    {
        wrongBeep();
        cout << "\tInvalid Option. Select Again: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //////////////////// Corridor Switch ////////////////////////////
    switch (corridorOptionSelect)
    {
    //========================================================================================//
    //=================================== Haddaad Room ========================================//
    case 1:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (HaddaadRoomLock == 0)
        {
            optionSelectYesBeep();
            cout << endl;
            cout << "\t(The Door of Haddaad's room opens)" << endl;
            if (switchHaddaadRoomLight == 0)
            {
                cout << "\t(The Lights of the Haddaad's room turns on)" << endl;
                switchHaddaadRoomLight = 1;
            }
            else
            {
                cout << "\t(Light of the room is already on)" << endl;
            }

        ////////////////////////////// Haddaad Room Option /////////////////////
        HaddaadOption:
            cout << endl;
            cout << "\t(You are in the Haddaad's room)" << endl;
            HaddaadCurtainCheck();
            HaddaadMusicCheck();
            HaddaadTvCheck();
            HaddaadLockCheck();
            cout << endl;
            HaddaadBurglarProtocolCheck();
            HaddaadRoomBurglarCheck();
            safeRoomBurglarCheck();
            cout << endl;
            cout << "\t   1) Lights" << endl;
            cout << "\t   2) TV" << endl;
            cout << "\t   3) Music" << endl;
            cout << "\t   4) Curtains" << endl;
            cout << "\t   5) Room Lock" << endl;
            cout << "\t   6) Safe Room" << endl;
            cout << "\t   7) Burglar's Protocol" << endl;
            cout << "\t   8) Return to corridor" << endl;
            cout << endl;

            ///////////////////////////// Haddaad Room option Select //////////////////////
            int HaddaadOptionSelect;
        HaddaadOptionSelectAgain:
            while (!(cin >> HaddaadOptionSelect))
            {
                wrongBeep();
                cout << "\tInvalid Option. Enter Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ////////////////////////////// Haddaad Room Switch ////////////////////////////
            switch (HaddaadOptionSelect)
            {
            /////////////////////////// Haddaad Lights //////////////////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << "\t   1) Turn on the lights" << endl;
                cout << "\t   2) Turn off the lights" << endl;
                cout << "\t   3) Light Intensity" << endl;
                cout << "\t   4) Cancel" << endl;

                //////////////////// Haddaad Lights Option Select //////////////////////////
                int HaddaadLightsOptionSelect;
            HaddaadLightsOptionSelectAgain:
                while (!(cin >> HaddaadLightsOptionSelect))
                {
                    wrongBeep();
                    cout << "\tInvaid Option. Enter Again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                //////////////////// Haddaad lights Switch //////////////////////////
                switch (HaddaadLightsOptionSelect)
                {
                ////////////////////////// Turn on the light /////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadRoomLight == 1)
                    {
                        noBeep();
                        cout << "\tLights are already on" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLights are turned on" << endl;
                        switchHaddaadRoomLight = 1;
                        goto HaddaadOption;
                    }

                ////////////////////////// Turn off the light ////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadRoomLight == 0)
                    {
                        noBeep();
                        cout << "\tLights are already off" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLights are turned off" << endl;
                        switchHaddaadRoomLight = 0;
                        HaddaadLightIntensity = 7;
                        goto HaddaadOption;
                    }

                ///////////////////////// Light Intensity ///////////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadRoomLight == 0)
                    {
                        noBeep();
                        cout << "\tLights are off right now." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLight Intensity is at " << HaddaadLightIntensity << endl;
                        cout << endl;
                        cout << "\tEnter new Intensity (from 1 to 7)" << endl;
                    HaddaadLightIntensityAgain:
                        while (!(cin >> HaddaadLightIntensity))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Input Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (HaddaadLightIntensity >= 1 && HaddaadLightIntensity <= 7)
                        {
                            optionSelectYesBeep();
                            cout << "\tLight Intensity is set to " << HaddaadLightIntensity << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tInvalid entry. Please Enter Again: " << endl;
                            goto HaddaadLightIntensityAgain;
                        }
                    }

                ///////////////////////// Cancel ////////////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto HaddaadOption;

                ///////////////////////// Haddaad light invalid option //////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select again: " << endl;
                    goto HaddaadLightsOptionSelectAgain;
                }

            /////////////////////////// Haddaad Tv ///////////////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << endl;
                cout << "\t   1) Turn on TV" << endl;
                cout << "\t   2) Turn off TV" << endl;
                cout << "\t   3) Change channel to" << endl;
                cout << "\t   4) Change Volume" << endl;
                cout << "\t   5) Cancel" << endl;
                cout << endl;

                ////////////////////////// Haddaad TV Option Select ////////////////////////
                int HaddaadTvOptionSelect;
            HaddaadTvOptionSelectAgain:
                while (!(cin >> HaddaadTvOptionSelect))
                {
                    wrongBeep();
                    cout << "\tInvalid Option. Enter Again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ////////////////////////// Haddaad Tv Switch //////////////////////////
                switch (HaddaadTvOptionSelect)
                {
                ///////////////////////// Turn on Tv //////////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadMusic == 1)
                    {
                        if (switchHaddaadtv == 1)
                        {
                            noBeep();
                            cout << "\tTV is already on" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadtv = 1;
                            cout << "\tTV is turned on" << endl;
                            cout << "\t(TV turns on and current channel is " << HaddaadTvChannel << " and volume is " << HaddaadTvVolume << ")" << endl;
                            if (HaddaadMusicVolume != 0)
                            {
                                HaddaadMusicVolume = 0;
                                cout << "\t(Music is muted)" << endl;
                            }
                            goto HaddaadOption;
                        }
                    }
                    else
                    {
                        if (switchHaddaadtv == 1)
                        {
                            noBeep();
                            cout << "\tTV is already on" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadtv = 1;
                            cout << "\tTV is turned on" << endl;
                            cout << "\t(TV turns on and current channel is " << HaddaadTvChannel << " and volume is " << HaddaadTvVolume << ")" << endl;
                            goto HaddaadOption;
                        }
                    }

                ///////////////////////// Turn Off Tv //////////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadMusic == 1)
                    {
                        if (switchHaddaadtv == 0)
                        {
                            noBeep();
                            cout << "\tTV is already off" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadtv = 0;
                            HaddaadTvVolume = 67;
                            cout << "\tTV is turned off" << endl;
                            cout << "\t(TV turns off)" << endl;
                            if (HaddaadMusicVolume == 0)
                            {
                                HaddaadMusicVolume = 67;
                                cout << "\t(music is unmuted and volume is set to 67)" << endl;
                            }
                            goto HaddaadOption;
                        }
                    }
                    else
                    {
                        if (switchHaddaadtv == 0)
                        {
                            noBeep();
                            cout << "\tTV is already off" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadtv = 0;
                            HaddaadTvVolume = 67;
                            cout << "\tTV is turned off" << endl;
                            cout << "\t(TV turns off)" << endl;
                            goto HaddaadOption;
                        }
                    }

                ///////////////////////// Change Tv Channel //////////////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadtv == 0)
                    {
                        noBeep();
                        cout << "\tTv is off right now" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tCurrent channel is " << HaddaadTvChannel << endl;
                        cout << "\tWhat channel would you like to watch? (1 to 100)" << endl;
                    HaddaadTvChannelAgain:
                        while(!(cin >> HaddaadTvChannel))
                        {
                            wrongBeep();
                            cout << "\tMust be a number. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (HaddaadTvChannel >= 1 && HaddaadTvChannel <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "\tThe Channel is changed to " << HaddaadTvChannel << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tOnly 100 channels are available (i.e. 1 to 100). Enter Again: " << endl;
                            goto HaddaadTvChannelAgain;
                        }
                    }

                ///////////////////////// Change Volume //////////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadtv == 0)
                    {
                        noBeep();
                        cout << "\tTv is off right now" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tCurrent volume is " << HaddaadTvVolume << endl;
                        cout << "\tEnter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                    HaddaadTvVolumeAgain:
                        while(!(cin >> HaddaadTvVolume))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (HaddaadTvVolume >= 0 && HaddaadTvVolume <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "\tThe volume is now " << HaddaadTvVolume << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tInvalid Volume. Enter Again: " << endl;
                            goto HaddaadTvVolumeAgain;
                        }
                    }

                ///////////////////////// Cancel //////////////////////////
                case 5:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto HaddaadOption;

                ///////////////////////// Haddaad Tv Invalid ////////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    goto HaddaadTvOptionSelectAgain;
                }

            /////////////////////////// Haddaad Music /////////////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                //////////////////////// Haddaad Music Options /////////////////////////
                cout << "\t   1) Turn Music On" << endl;
                cout << "\t   2) Turn Music Off" << endl;
                cout << "\t   3) Choose Genre" << endl;
                cout << "\t   4) Music Volume" << endl;
                cout << "\t   5) Cancel" << endl;

                /////////////////////// Haddaad Music Input ////////////////////////////
                int HaddaadMusicOption;
            HaddaadMusicOptionAgain:
                while (!(cin >> HaddaadMusicOption))
                {
                    wrongBeep();
                    cout << "\tInvalid Option. Select again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ///////////////////////// Haddaad Music Switch ////////////////////////////
                switch (HaddaadMusicOption)
                {
                /////////////////////// Turn on music //////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadtv == 1)
                    {
                        if (switchHaddaadMusic == 1)
                        {
                            noBeep();
                            cout << "\tMusic is already playing" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadMusic = 1;
                            cout << "\tMusic is turned on. And Music Volume is " << HaddaadMusicVolume << endl;
                            if (HaddaadTvVolume != 0)
                            {
                                HaddaadTvVolume = 0;
                                cout << "\t(Tv is muted)" << endl;
                            }
                            goto HaddaadOption;
                        }
                    }
                    else
                    {
                        if (switchHaddaadMusic == 1)
                        {
                            noBeep();
                            cout << "\tMusic is already playing" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadMusic = 1;
                            cout << "\tMusic is turned on. And Music Volume is " << HaddaadMusicVolume << endl;
                            goto HaddaadOption;
                        }
                    }

                /////////////////////// Turn off music //////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadtv == 1)
                    {
                        if (switchHaddaadMusic == 0)
                        {
                            noBeep();
                            cout << "\tMusic is already off" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadMusic = 0;
                            HaddaadMusicVolume = 67;
                            cout << "\tMusic is turned off" << endl;
                            if (HaddaadTvVolume == 0)
                            {
                                HaddaadTvVolume = 67;
                                cout << "\t(Tv is unmuted and volume is set to 67)" << endl;
                            }
                            goto HaddaadOption;
                        }
                    }
                    else
                    {
                        if (switchHaddaadMusic == 0)
                        {
                            noBeep();
                            cout << "\tMusic is already off" << endl;
                            goto HaddaadOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchHaddaadMusic = 0;
                            HaddaadMusicVolume = 67;
                            cout << "\tMusic is turned off" << endl;
                            goto HaddaadOption;
                        }
                    }


                ////////////////////// Choose Genre /////////////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadMusic == 0)
                    {
                        wrongBeep();
                        cout << "\tMusic is off right now." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tWhat would you like to listen?" << endl;
                        string musicTrackAnswer;
                        getline (cin, musicTrackAnswer);
                        optionSelectYesBeep();
                        cout << "\tPlaying " << musicTrackAnswer << "..." << endl;
                        goto HaddaadOption;
                    }



                /////////////////////// Music Volume //////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchHaddaadMusic == 1)
                    {
                        optionSelectYesBeep();
                        cout << endl;
                        cout << "\tVolume of Music is currently at " << HaddaadMusicVolume << endl;
                        cout << "\tEnter new Volume (from 1 to 100)" << endl;
                    HaddaadMusicVolumeAgain:
                        while (!(cin >> HaddaadMusicVolume))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (!(HaddaadMusicVolume >= 1) || !(HaddaadMusicVolume <= 100))
                        {
                            wrongBeep();
                            cout << "\tInvalid Volume Level. Choose volume between 1 to 100. Enter again: " << endl;
                            goto HaddaadMusicVolumeAgain;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            cout << "\tVolume of music is set to " << HaddaadMusicVolume << endl;
                            goto HaddaadOption;
                        }
                    }
                    else
                    {
                        noBeep();
                        cout << "\tMusic is currently off" << endl;
                        goto HaddaadOption;
                    }

                /////////////////////// Cancel //////////////////////
                case 5:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto HaddaadOption;

                /////////////////////// Haddaad Music Invalid //////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    goto HaddaadMusicOptionAgain;
                }

            ///////////////////////////// Haddaad Curtains /////////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << endl;
                if (HaddaadCurtain == 0)
                {
                    cout << "\tDo you want me to open curtains?" << endl;
                    string HaddaadCurtainAnswer;
                HaddaadCurtainAnswerAgain:
                    getline (cin, HaddaadCurtainAnswer);
                    if (HaddaadCurtainAnswer == "Yes" || HaddaadCurtainAnswer == "YES" || HaddaadCurtainAnswer == "yes" || HaddaadCurtainAnswer == "Y" || HaddaadCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "\tOkay..!" << endl;
                        HaddaadCurtain = 1;
                        cout << "\t(Curtains opening)" << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadCurtainAnswer == "No" || HaddaadCurtainAnswer == "NO" || HaddaadCurtainAnswer == "no" || HaddaadCurtainAnswer == "N" || HaddaadCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay..!" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it. Please repeat again: " << endl;
                        goto HaddaadCurtainAnswerAgain;
                    }
                }
                else
                {
                    cout << "\tDo you want me to close the curtains?" << endl;
                    string HaddaadCurtainAnswer;
                HaddaadCurtainOpenAnswerAgain:
                    getline (cin, HaddaadCurtainAnswer);
                    if (HaddaadCurtainAnswer == "Yes" || HaddaadCurtainAnswer == "YES" || HaddaadCurtainAnswer == "yes" || HaddaadCurtainAnswer == "Y" || HaddaadCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "\tOkay..!" << endl;
                        HaddaadCurtain = 0;
                        cout << "\t(Curtains closing)" << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadCurtainAnswer == "No" || HaddaadCurtainAnswer == "NO" || HaddaadCurtainAnswer == "no" || HaddaadCurtainAnswer == "N" || HaddaadCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay..!" << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it. Please repeat again: " << endl;
                        goto HaddaadCurtainOpenAnswerAgain;
                    }
                }

            ///////////////////////////// Haddaad Room lock ////////////////////////
            case 5:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                if (HaddaadRoomLock == 0)
                {
                    cout << "\tDo You want me to Lock the room door?" << endl;
                    string HaddaadLockAnswer;
                HaddaadLockAnswerAgain:
                    getline (cin, HaddaadLockAnswer);
                    if (HaddaadLockAnswer == "Yes" || HaddaadLockAnswer == "YES" || HaddaadLockAnswer == "yes" || HaddaadLockAnswer == "Y" || HaddaadLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        HaddaadRoomLock = 1;
                        cout << "\tRoom door is locked now" << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadLockAnswer == "No" || HaddaadLockAnswer == "NO" || HaddaadLockAnswer == "no" || HaddaadLockAnswer == "N" || HaddaadLockAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it.. Please repeat Again: " << endl;
                        goto HaddaadLockAnswerAgain;
                    }
                }
                else
                {
                    cout << "\tDo You want me to unlock the room door?" << endl;
                    string HaddaadLockAnswer;
                HaddaadUnlockAnswerAgain:
                    getline (cin, HaddaadLockAnswer);
                    if (HaddaadLockAnswer == "Yes" || HaddaadLockAnswer == "YES" || HaddaadLockAnswer == "yes" || HaddaadLockAnswer == "Y" || HaddaadLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        HaddaadRoomLock = 0;
                        cout << "\tRoom door is unlocked now" << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadLockAnswer == "No" || HaddaadLockAnswer == "NO" || HaddaadLockAnswer == "no" || HaddaadLockAnswer == "N" || HaddaadLockAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it.. Please Answer Again: " << endl;
                        goto HaddaadUnlockAnswerAgain;
                    }
                }

            ///////////////////////////// Haddaad Safe Room ////////////////////////
            case 6:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << endl;
                cout << "\tEnter key to open: " << endl;
            safeRoomKeyInputAgain:
                getline (cin, safeRoomKeyInput);
                if (safeRoomKeyInput == safeRoomKey)
                {
                    ////////////////// Safe Room Options /////////////////
                    correctBeep();
                    safeRoomtries = 0;
                    cout << "\tKey Accepted." << endl;
                    cout << "\t(The light of the safe room turns on)" << endl;
                    cout << "\t(The Door of safe room closes when you get into the safe room)" << endl;
                safeRoomOption:
                    cout << endl;
                    cout << "\t   1) Use Safe" << endl;
                    cout << "\t   2) Return to Haddaad's Room" << endl;
                    cout << endl;
                    int safeRoomOptionSelect;
                safeRoomOptionSelectAgain:
                    while (!(cin >> safeRoomOptionSelect))
                    {
                        wrongBeep();
                        cout << "\tInvalid Option. Enter Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    //////////////////// Safe Room Switch ///////////////////
                    switch (safeRoomOptionSelect)
                    {
                    /////////////////////// Use Safe ////////////////////////
                    case 1:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        optionSelectYesBeep();
                        cout << "\tEnter Safe Key: " << endl;
                        getline (cin, safeKeyInput);
                        if (safeKeyInput == safekey)
                        {
                            correctBeep();
                            safeKeyTries = 0;
                            cout << "\tSafe Opens" << endl;
                            cout << "\tPress 1 to lock the safe (When you finish your Business): ";
                        safeCloseInputAgain:
                            getline (cin, safeCloseInput);
                            if (safeCloseInput == "1")
                            {
                                optionSelectYesBeep();
                                cout << "\tSafe is locked now." << endl;
                                goto safeRoomOption;
                            }
                            else
                            {
                                wrongBeep();
                                cout << "\tInvalid Input. Press 1 to lock the Safe (When you finish your Business): ";
                                goto safeCloseInputAgain;
                            }
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tInvalid Key." << endl;
                            safeKeyTries = safeKeyTries + 1;
                            if (safeKeyTries == 3)
                            {
                                safeBurglarCheck = 1;
                                HaddaadRoomLock = 1;
                                guestRoomLock = 1;
                                safeRoomLock = 1;
                                livingRoomCurtains = 0;
                                guestCurtain = 0;
                                HaddaadCurtain = 0;
                                cout << "\tMaximum limit of tries reached." << endl;
                                cout << "\t(Burglar's protocol is initiated. All doors are locked. You cannot escape now.)" << endl;
                                Beep(500, 10000);
                                cout << "\tEnter Master key to disable burglar's Protocol: " << endl;
                                string safeBurglarDisable;
                            safeBurglarDisableAgain:
                                getline (cin, safeBurglarDisable);
                                if (safeBurglarDisable == HaddaadKey)
                                {
                                    correctBeep();
                                    cout << "\tBurglar's Protocol is disabled." << endl;
                                    safeBurglarCheck = 0;
                                    goto safeRoomOption;
                                }
                                else
                                {
                                    wrongBeep();
                                    cout << "\tEnter Master key to disable burglar's Protocol: " << endl;
                                    goto safeBurglarDisableAgain;
                                }
                            }
                            goto safeRoomOption;
                        }

                    /////////////////////// Return to Haddaad Room ///////////////////////
                    case 2:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        optionSelectYesBeep();
                        cout << "\t(the Safe is Locked and the light turn off.)" << endl;
                        cout << "\t(The door of safe room gets locked when you returned back to Haddaad's Room)" << endl;
                        goto HaddaadOption;

                    //////////////////////// Safe Room Invalid Select ////////////////////////
                    default:
                        wrongBeep();
                        cout << "\tInvalid Option. Select Again: " << endl;
                        goto safeRoomOptionSelectAgain;
                    }
                }
                else
                {
                    wrongBeep();
                    cout << "\tWrong Key. Input Again: " << endl;
                    safeRoomtries = safeRoomtries + 1;
                    if (safeRoomtries == 3)
                    {
                        HaddaadBurglarCheck = 1;
                        HaddaadRoomLock = 1;
                        guestRoomLock = 1;
                        safeRoomLock = 1;
                        livingRoomCurtains = 0;
                        guestCurtain = 0;
                        HaddaadCurtain = 0;
                        cout << "\tMaximum limit of tries reached." << endl;
                        cout << "\t(Burglar's protocol is initiated. All doors are locked. You cannot escape now.)" << endl;
                        Beep(500, 10000);
                        cout << "\tEnter Master key to disable burglar's Protocol: " << endl;
                        string safeRoomBurglarDisable;
                    safeRoomBurglarDisableAgain:
                        getline (cin, safeRoomBurglarDisable);
                        if (safeRoomBurglarDisable == HaddaadKey)
                        {
                            correctBeep();
                            cout << "\tBurglar's Protocol is disabled." << endl;
                            HaddaadBurglarCheck = 0;
                            goto HaddaadOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tEnter Master key to disable burglar's Protocol: " << endl;
                            goto safeRoomBurglarDisableAgain;
                        }
                    }
                    goto safeRoomKeyInputAgain;
                }

            ///////////////////////////// Haddaad Burglar's Protocol //////////////////////
            case 7:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                if (IfBurglar == 0)
                {
                    cout << "\tDo you want me to enable Burglar's Protocol" << endl;
                HaddaadBurglarSureAgain:
                    getline (cin, HaddaadBurglarSure);
                    if (HaddaadBurglarSure == "Yes" || HaddaadBurglarSure == "YES" || HaddaadBurglarSure == "yes" || HaddaadBurglarSure == "y" || HaddaadBurglarSure == "Y")
                    {
                        optionSelectYesBeep();
                        IfBurglar = 1;
                        cout << "\tBurglar's Protocol Initiated." << endl;
                        for (int i = 0; i < 5; i++)
                        {
                            Beep(400, 250);
                            Beep(0, 100);
                        }
                        HaddaadRoomLock = 1;
                        guestRoomLock = 1;
                        safeRoomLock = 1;
                        livingRoomCurtains = 0;
                        guestCurtain = 0;
                        HaddaadCurtain = 0;
                        cout << "\t(All doors are locked and all curtains are also closed)" << endl;
                        cout << "\t(Jarvis has called the Police and Police is comming)" << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadBurglarSure == "No" || HaddaadBurglarSure == "NO" || HaddaadBurglarSure == "no" || HaddaadBurglarSure == "n" || HaddaadBurglarSure == "N")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not understand it. Please repeat Again: " << endl;
                        goto HaddaadBurglarSureAgain;
                    }
                }
                else
                {
                    cout << "\tDo you want me to Disable Burglar's Protocol" << endl;
                DisableHaddaadBurglarSureAgain:
                    getline (cin, HaddaadBurglarSure);
                    if (HaddaadBurglarSure == "Yes" || HaddaadBurglarSure == "YES" || HaddaadBurglarSure == "yes" || HaddaadBurglarSure == "y" || HaddaadBurglarSure == "Y")
                    {
                        optionSelectYesBeep();
                        IfBurglar = 0;
                        for (int i = 0; i < 5; i++)
                        {
                            Beep(130, 250);
                            Beep(0, 100);
                        }
                        cout << "\tBurglar's Protocol Disabled." << endl;
                        goto HaddaadOption;
                    }
                    else if (HaddaadBurglarSure == "No" || HaddaadBurglarSure == "NO" || HaddaadBurglarSure == "no" || HaddaadBurglarSure == "n" || HaddaadBurglarSure == "N")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto HaddaadOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not understand it. Please repeat Again: " << endl;
                        goto DisableHaddaadBurglarSureAgain;
                    }
                }

            ///////////////////////////// Return to corridor /////////////////////////
            case 8:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << "\tDo you want me to turn of all the appliances?" << endl;
            HaddaadLeaveAnswerAgain:
                getline (cin, HaddaadLeaveAnswer);
                if (HaddaadLeaveAnswer == "Yes" || HaddaadLeaveAnswer == "YES" || HaddaadLeaveAnswer == "yes" || HaddaadLeaveAnswer == "Y" || HaddaadLeaveAnswer == "y")
                {
                    optionSelectYesBeep();
                    switchHaddaadRoomLight = 0;
                    HaddaadLightIntensity = 7;
                    switchHaddaadtv = 0;
                    switchHaddaadMusic = 0;
                    HaddaadMusicVolume = 67;
                    HaddaadCurtain = 0;
                    HaddaadRoomLock = 0;
                    safeRoomLock = 1;
                    cout << "\tOkay.." << endl;
                    cout << "\t(All appliances of the room are turned off)" << endl;
                    cout << "\t(Curtains are also closed)" << endl;
                    goto corridorOption;
                }
                else if (HaddaadLeaveAnswer == "No" || HaddaadLeaveAnswer == "NO" || HaddaadLeaveAnswer == "no" || HaddaadLeaveAnswer == "N" || HaddaadLeaveAnswer == "n")
                {
                    noBeep();
                    HaddaadRoomLock = 0;
                    cout << "\tOkay.." << endl;
                    goto corridorOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it. Please repeat Again: " << endl;
                    goto HaddaadLeaveAnswerAgain;
                }

            //////////////////////////// Haddaad Invalid Select ///////////////////////
            default:
                wrongBeep();
                cout << "\tInvalid Option. Select again: " << endl;
                goto HaddaadOptionSelectAgain;
            }
        }
        else
        {
            wrongBeep();
            cout << "\tThe Haddaad's room is locked. Knock the Door and ask to open the door." << endl;
            goto corridorOption;
        }

    //========================================================================================//
    //==================================== Guest Room ========================================//
    case 2:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (guestRoomLock == 0)
        {
            optionSelectYesBeep();
            cout << endl;
            cout << "\t(The Door of guest room opens)" << endl;
            if (switchGuestRoomLight == 0)
            {
                cout << "\t(The Lights of the guest room turns on)" << endl;
                switchGuestRoomLight = 1;
            }
            else
            {
                cout << "\t(Light of the room is already on)" << endl;
            }

        ////////////////////////////// Guest Room Option /////////////////////
        guestOption:
            cout << endl;
            cout << "\t(You are in the Guest room)" << endl;
            guestCurtainCheck();
            GuestMusicCheck();
            guestTvCheck();
            guestLockCheck();
            cout << endl;
            HaddaadBurglarProtocolCheck();
            HaddaadRoomBurglarCheck();
            safeRoomBurglarCheck();
            cout << endl;
            cout << "\t   1) Lights" << endl;
            cout << "\t   2) TV" << endl;
            cout << "\t   3) Music" << endl;
            cout << "\t   4) Curtains" << endl;
            cout << "\t   5) Room Lock" << endl;
            cout << "\t   6) Return to corridor" << endl;
            cout << endl;

            ///////////////////////////// Guest Room option Select //////////////////////
            int guestOptionSelect;
        guestOptionSelectAgain:
            while (!(cin >> guestOptionSelect))
            {
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ///////////////////////////// Guest Room Switch /////////////////////////////
            switch (guestOptionSelect)
            {
            ///////////////////////////// Guest Lights ///////////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << "\t   1) Turn on the lights" << endl;
                cout << "\t   2) Turn off the lights" << endl;
                cout << "\t   3) Light Intensity" << endl;
                cout << "\t   4) Cancel" << endl;

                //////////////////// Guest Lights Option Select //////////////////////////
                int guestLightsOptionSelect;
            guestLightsOptionSelectAgain:
                while (!(cin >> guestLightsOptionSelect))
                {
                    wrongBeep();
                    cout << "\tInvaid Option. Select Again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ///////////////////// Guest lights Switch /////////////////////////////
                switch (guestLightsOptionSelect)
                {
                /////////////////////// Turn on the lights ////////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestRoomLight == 1)
                    {
                        noBeep();
                        cout << "\tLights are already on" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLights are turned on" << endl;
                        switchGuestRoomLight = 1;
                        goto guestOption;
                    }

                //////////////////////// Turn off the lights ///////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestRoomLight == 0)
                    {
                        noBeep();
                        cout << "\tLights are already off" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLights are turned off" << endl;
                        switchGuestRoomLight = 0;
                        guestLightIntensity = 7;
                        goto guestOption;
                    }

                //////////////////////// Light Intensity ////////////////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestRoomLight == 0)
                    {
                        noBeep();
                        cout << "\tLights are off right now." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tLight Intensity is at " << guestLightIntensity << endl;
                        cout << endl;
                        cout << "\tEnter new Intensity (from 1 to 7)" << endl;
                    guestLightIntensityAgain:
                        while (!(cin >> guestLightIntensity))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Input Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (guestLightIntensity >= 1 && guestLightIntensity <= 7)
                        {
                            optionSelectYesBeep();
                            cout << "\tLight Intensity is set to " << guestLightIntensity << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tInvalid entry. Please Enter Again: " << endl;
                            goto guestLightIntensityAgain;
                        }
                    }

                ////////////////////////// Cancel /////////////////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto guestOption;

                ////////////////////////// Guest lights invalid option /////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    goto guestLightsOptionSelectAgain;
                }

            ///////////////////////////// Guest TV /////////////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << endl;
                cout << "\t   1) Turn on TV" << endl;
                cout << "\t   2) Turn off TV" << endl;
                cout << "\t   3) Change channel to" << endl;
                cout << "\t   4) Change Volume" << endl;
                cout << "\t   5) Cancel" << endl;
                cout << endl;

                ////////////////////////// Guest TV Option Select ////////////////////////
                int guestTvOptionSelect;
            guestTvOptionSelectAgain:
                while (!(cin >> guestTvOptionSelect))
                {
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ///////////////////////// Guest Tv Switch ///////////////////////////
                switch (guestTvOptionSelect)
                {
                /////////////////////// Turn on tv ////////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestMusic == 1)
                    {
                        if (switchGuestTv == 1)
                        {
                            noBeep();
                            cout << "\tTV is already on" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 1;
                            cout << "\tTV is turned on" << endl;
                            cout << "\t(TV turns on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
                            if (guestMusicVolume != 0)
                            {
                                guestMusicVolume = 0;
                                cout << "\t(Music is muted)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestTv == 1)
                        {
                            noBeep();
                            cout << "\tTV is already on" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 1;
                            cout << "\tTV is turned on" << endl;
                            cout << "\t(TV turns on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
                            goto guestOption;
                        }
                    }

                /////////////////////// Turn off Tv ///////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestMusic == 1)
                    {
                        if (switchGuestTv == 0)
                        {
                            noBeep();
                            cout << "\tTV is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 0;
                            guestTvVolume = 67;
                            cout << "\tTV is turned off" << endl;
                            cout << "\t(TV turns off)" << endl;
                            if (guestMusicVolume == 0)
                            {
                                guestMusicVolume = 67;
                                cout << "\t(music is unmuted and volume is set to 67)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestTv == 0)
                        {
                            noBeep();
                            cout << "\tTV is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 0;
                            guestTvVolume = 67;
                            cout << "\tTV is turned off" << endl;
                            cout << "\t(TV turns off)" << endl;
                            goto guestOption;
                        }
                    }

                //////////////////////// Change Channel to //////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestTv == 0)
                    {
                        noBeep();
                        cout << "\tTv is off right now" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tCurrent channel is " << guestTvChannel << endl;
                        cout << "\tWhat channel would you like to watch? (1 to 100)" << endl;
                    guestTvChannelAgain:
                        while(!(cin >> guestTvChannel))
                        {
                            wrongBeep();
                            cout << "\tInvalid Input. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (guestTvChannel >= 1 && guestTvChannel <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "\tThe Channel is changed to " << guestTvChannel << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tOnly 100 channels are available (i.e. 1 to 100). Enter Again: " << endl;
                            goto guestTvChannelAgain;
                        }
                    }
                //////////////////////// Change Volume ////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestTv == 0)
                    {
                        noBeep();
                        cout << "\tTv is off right now" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tCurrent volume is " << guestTvVolume << endl;
                        cout << "\tEnter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                    guestTvVolumeAgain:
                        while(!(cin >> guestTvVolume))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (guestTvVolume >= 0 && guestTvVolume <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "\tThe volume is now " << guestTvVolume << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "\tInvalid Volume. Enter Again: " << endl;
                            goto guestTvVolumeAgain;
                        }
                    }

                //////////////////////// Cancel //////////////////////////
                case 5:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto guestOption;

                //////////////////////// Tv invalid option ////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    goto guestTvOptionSelectAgain;
                }

            ///////////////////////////// Guest Music ///////////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                //////////////////////// Guest Music Options /////////////////////////
                cout << "\t   1) Turn Music On" << endl;
                cout << "\t   2) Turn Music Off" << endl;
                cout << "\t   3) Choose Genre" << endl;
                cout << "\t   4) Music Volume" << endl;
                cout << "\t   5) Cancel" << endl;

                /////////////////////// Guest Music Input ////////////////////////////
                int guestMusicOption;
            guestMusicOptionAgain:
                while (!(cin >> guestMusicOption))
                {
                    wrongBeep();
                    cout << "\tInvalid Option. Select again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                //////////////////////// Guest Music Switch ////////////////////////
                switch (guestMusicOption)
                {
                //////////////////////// Turn Music on ////////////////////////
                case 1:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestTv == 1)
                    {
                        if (switchGuestMusic == 1)
                        {
                            noBeep();
                            cout << "\tMusic is already playing" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 1;
                            cout << "\tMusic is turned on. And Music Volume is " << guestMusicVolume << endl;
                            if (guestTvVolume != 0)
                            {
                                guestTvVolume = 0;
                                cout << "\t(Tv is muted)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestMusic == 1)
                        {
                            noBeep();
                            cout << "\tMusic is already playing" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 1;
                            cout << "\tMusic is turned on. And Music Volume is " << guestMusicVolume << endl;
                            goto guestOption;
                        }
                    }

                //////////////////////// Turn Music Off //////////////////////
                case 2:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestTv == 1)
                    {
                        if (switchGuestMusic == 0)
                        {
                            noBeep();
                            cout << "\tMusic is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 0;
                            guestMusicVolume = 67;
                            cout << "\tMusic is turned off" << endl;
                            if (guestTvVolume == 0)
                            {
                                guestTvVolume = 67;
                                cout << "\t(Tv is unmuted and volume is set to 67)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestMusic == 0)
                        {
                            noBeep();
                            cout << "\tMusic is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 0;
                            guestMusicVolume = 67;
                            cout << "\tMusic is turned off" << endl;
                            goto guestOption;
                        }
                    }

                ////////////////////// Choose Genre /////////////////////////
                case 3:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestMusic == 0)
                    {
                        wrongBeep();
                        cout << "\tMusic is off right now." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "\tWhat would you like to listen?" << endl;
                        string musicTrackAnswer;
                        getline (cin, musicTrackAnswer);
                        optionSelectYesBeep();
                        cout << "\tPlaying " << musicTrackAnswer << "..." << endl;
                        goto guestOption;
                    }



                //////////////////////// Music Volume //////////////////////
                case 4:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if (switchGuestMusic == 1)
                    {
                        optionSelectYesBeep();
                        cout << endl;
                        cout << "\tVolume of Music is currently at " << guestMusicVolume << endl;
                        cout << "\tEnter new Volume (from 1 to 100)" << endl;
                    guestMusicVolumeAgain:
                        while (!(cin >> guestMusicVolume))
                        {
                            wrongBeep();
                            cout << "\tInvalid Entry. Enter Again: " << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (!(guestMusicVolume >= 1) || !(guestMusicVolume <= 100))
                        {
                            wrongBeep();
                            cout << "\tInvalid Volume Level. Choose volume between 1 to 100. Enter again: " << endl;
                            goto guestMusicVolumeAgain;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            cout << "\tVolume of music is set to " << guestMusicVolume << endl;
                            goto guestOption;
                        }
                    }
                    else
                    {
                        noBeep();
                        cout << "\tMusic is currently off" << endl;
                        goto guestOption;
                    }

                //////////////////////// Cancel ////////////////////////////
                case 5:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    noBeep();
                    goto guestOption;

                /////////////////////// Invalid Music select ///////////////////////
                default:
                    wrongBeep();
                    cout << "\tInvalid Option. Select Again: " << endl;
                    goto guestMusicOptionAgain;
                }

            //////////////////////////// Guest Curtains //////////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << endl;
                if (guestCurtain == 0)
                {
                    cout << "\tDo you want me to open curtains?" << endl;
                    string guestCurtainAnswer;
                guestCurtainAnswerAgain:
                    getline (cin, guestCurtainAnswer);
                    if (guestCurtainAnswer == "Yes" || guestCurtainAnswer == "YES" || guestCurtainAnswer == "yes" || guestCurtainAnswer == "Y" || guestCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "\tOkay..!" << endl;
                        guestCurtain = 1;
                        cout << "\t(Curtains opening)" << endl;
                        goto guestOption;
                    }
                    else if (guestCurtainAnswer == "No" || guestCurtainAnswer == "NO" || guestCurtainAnswer == "no" || guestCurtainAnswer == "N" || guestCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay..!" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it. Please repeat again: " << endl;
                        goto guestCurtainAnswerAgain;
                    }
                }
                else
                {
                    cout << "\tDo you want me to close the curtains?" << endl;
                    string guestCurtainAnswer;
                guestCurtainOpenAnswerAgain:
                    getline (cin, guestCurtainAnswer);
                    if (guestCurtainAnswer == "Yes" || guestCurtainAnswer == "YES" || guestCurtainAnswer == "yes" || guestCurtainAnswer == "Y" || guestCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "\tOkay..!" << endl;
                        guestCurtain = 0;
                        cout << "\t(Curtains closing)" << endl;
                        goto guestOption;
                    }
                    else if (guestCurtainAnswer == "No" || guestCurtainAnswer == "NO" || guestCurtainAnswer == "no" || guestCurtainAnswer == "N" || guestCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay..!" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it. Please repeat again: " << endl;
                        goto guestCurtainOpenAnswerAgain;
                    }
                }

            //////////////////////////// Guest Room lock /////////////////////////
            case 5:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                if (guestRoomLock == 0)
                {
                    cout << "\tDo You want me to Lock the room door?" << endl;
                    string guestLockAnswer;
                guestLockAnswerAgain:
                    getline (cin, guestLockAnswer);
                    if (guestLockAnswer == "Yes" || guestLockAnswer == "YES" || guestLockAnswer == "yes" || guestLockAnswer == "Y" || guestLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        guestRoomLock = 1;
                        cout << "\tRoom door is locked now" << endl;
                        goto guestOption;
                    }
                    else if (guestLockAnswer == "No" || guestLockAnswer == "NO" || guestLockAnswer == "no" || guestLockAnswer == "N" || guestLockAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it.. Please repeat Again: " << endl;
                        goto guestLockAnswerAgain;
                    }
                }
                else
                {
                    cout << "\tDo You want me to unlock the room door?" << endl;
                    string guestLockAnswer;
                guestUnlockAnswerAgain:
                    getline (cin, guestLockAnswer);
                    if (guestLockAnswer == "Yes" || guestLockAnswer == "YES" || guestLockAnswer == "yes" || guestLockAnswer == "Y" || guestLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        guestRoomLock = 0;
                        cout << "\tRoom door is unlocked now" << endl;
                        goto guestOption;
                    }
                    else if (guestLockAnswer == "No" || guestLockAnswer == "NO" || guestLockAnswer == "no" || guestLockAnswer == "N" || guestLockAnswer == "n")
                    {
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tI did not Understand it.. Please repeat Again: " << endl;
                        goto guestUnlockAnswerAgain;
                    }
                }

            //////////////////////////// Guest Return to corridor ////////////////////////
            case 6:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                cout << "\tDo you want me to turn off all the appliances?" << endl;
            guestLeaveAnswerAgain:
                getline (cin, guestLeaveAnswer);
                if (guestLeaveAnswer == "Yes" || guestLeaveAnswer == "YES" || guestLeaveAnswer == "yes" || guestLeaveAnswer == "Y" || guestLeaveAnswer == "y")
                {
                    optionSelectYesBeep();
                    switchGuestRoomLight = 0;
                    guestLightIntensity = 7;
                    switchGuestTv = 0;
                    switchGuestMusic = 0;
                    guestMusicVolume = 67;
                    guestCurtain = 0;
                    guestRoomLock = 0;
                    cout << "\tOkay.." << endl;
                    cout << "\t(All appliances of the room are turned off)" << endl;
                    cout << "\t(Curtains are also closed)" << endl;
                    goto corridorOption;
                }
                else if (guestLeaveAnswer == "No" || guestLeaveAnswer == "NO" || guestLeaveAnswer == "no" || guestLeaveAnswer == "N" || guestLeaveAnswer == "n")
                {
                    noBeep();
                    guestRoomLock = 0;
                    cout << "\tOkay.." << endl;
                    goto corridorOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it. Please Repeat Again: " << endl;
                    goto guestLeaveAnswerAgain;
                }

            //////////////////////////// Guest Invalid Option ///////////////////////////
            default:
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                goto guestOptionSelectAgain;
            }
        }
        else
        {
            wrongBeep();
            cout << "\tThe guest room is locked. Knock the Door and ask to open the door." << endl;
            goto corridorOption;
        }

    //========================================================================================//
    //=================================== Living Room ========================================//
    case 3:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        optionSelectYesBeep();
        cout << endl;
        cout << "\t(The Door of living room opens)" << endl;
        if (switchLivingRoomLight == 0)
        {
            cout << "\t(The Lights of the living room turns on)" << endl;
            switchLivingRoomLight = 1;
        }
        else
        {
            cout << "\t(Light is already on)" << endl;
        }

    ////////////////////////////// Living Room Option /////////////////////
    livingOption:
        cout << endl;
        cout << "\t(You are in the Living room)" << endl;
        livingCurtainCheck();
        cout << endl;
        HaddaadBurglarProtocolCheck();
        HaddaadRoomBurglarCheck();
        safeRoomBurglarCheck();
        if (switchLivingRoomTv == 0)
        {
            musicCheck();
        }
        livingTvCheck();
        cout << endl;
        cout << "\t   1) Lights" << endl;
        cout << "\t   2) Cinematic TV" << endl;
        cout << "\t   3) Music" << endl;
        cout << "\t   4) Curtains" << endl;
        cout << "\t   5) Return to corridor" << endl;
        cout << endl;

        ///////////////////////////// Living Room option Select //////////////////////
        int livingOptionSelect;
    livingOptionSelectAgain:
        while (!(cin >> livingOptionSelect))
        {
            wrongBeep();
            cout << "\tInvalid Option. Selecct Again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ////////////////////////////// Living Room Switch ///////////////////////////////
        switch (livingOptionSelect)
        {
        //////////////////////////// Living Lights /////////////////////////////
        case 1:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            cout << "\t   1) Turn on the lights" << endl;
            cout << "\t   2) Turn off the lights" << endl;
            cout << "\t   3) Light Intensity" << endl;
            cout << "\t   4) Cancel" << endl;

            //////////////////// Living Lights Option Select //////////////////////////
            int livingLightsOptionSelect;
        livingLightsOptionSelectAgain:
            while (!(cin >> livingLightsOptionSelect))
            {
                wrongBeep();
                cout << "\tInvaid Option. Select Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ////////////////////// Living Lights Case /////////////////////////////////
            switch (livingLightsOptionSelect)
            {
            ///////////////////////// Turn on light ///////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomLight == 1)
                {
                    noBeep();
                    cout << "\tLights are already on." << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tLights are turned on." << endl;
                    switchLivingRoomLight = 1;
                    goto livingOption;
                }

            ///////////////////////// Turn off the light //////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomLight == 0)
                {
                    noBeep();
                    cout << "\tLights are already off." << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tLights are turned off." << endl;
                    switchLivingRoomLight = 0;
                    livingLightIntensity = 7;
                    goto livingOption;
                }

            ///////////////////////// Light Intensity /////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomLight == 0)
                {
                    noBeep();
                    cout << "\tLights are off right now." << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tLight Intensity is at " << livingLightIntensity << endl;
                    cout << endl;
                    cout << "\tEnter new Intensity (from 1 to 7)" << endl;
                    int newLivingLightIntensity;
                newLivingLightIntensityAgain:
                    while (!(cin >> newLivingLightIntensity))
                    {
                        wrongBeep();
                        cout << "\tInvalid Entry. Input Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (newLivingLightIntensity >= 1 && newLivingLightIntensity <= 7)
                    {
                        optionSelectYesBeep();
                        livingLightIntensity = newLivingLightIntensity;
                        cout << "\tLight Intensity is set to " << newLivingLightIntensity << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tInvalid entry. Please Enter Again: " << endl;
                        goto newLivingLightIntensityAgain;
                    }
                }

            ///////////////////////// Cancel ////////////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                noBeep();
                cout << "\tOkay.." << endl;
                goto livingOption;

            ////////////////////////// Invalid Input //////////////////////
            default:
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                goto livingLightsOptionSelectAgain;
            }

        //////////////////////////// Living Tv /////////////////////////////////
        case 2:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
        ////////////////////////// Living TV Options ///////////////////
        livingTvOption:
            cout << endl;
            cout << "\t   1) Turn on TV" << endl;
            cout << "\t   2) Turn off TV" << endl;
            cout << "\t   3) Change channel to" << endl;
            cout << "\t   4) Change Volume" << endl;
            cout << "\t   5) Cancel" << endl;
            cout << endl;

            ////////////////////////// Living TV Option Select ////////////////////////
            int livingTvOptionSelect;
        livingTvOptionAgain:
            while (!(cin >> livingTvOptionSelect))
            {
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            /////////////////////////// Living Tv Switch ///////////////////////////////
            switch (livingTvOptionSelect)
            {
            /////////////////////////// Turn on Tv ///////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomTv == 1)
                {
                    noBeep();
                    cout << "\tTV is already on" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchLivingRoomTv = 1;
                    cout << "\tTV is turned on" << endl;
                    cout << "\t(TV turns on and current channel is " << livingTvChannel << " and volume is " << livingTvVolume << ")" << endl;
                    goto livingOption;
                }

            /////////////////////////// Turn off Tv //////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "\tTV is already off" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchLivingRoomTv = 0;
                    cout << "\tTV is turned off" << endl;
                    cout << "\t(TV turns off)" << endl;
                    goto livingOption;
                }

            /////////////////////////// Change Channel to ////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "\tTv is off right now" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tCurrent channel is " << livingTvChannel << endl;
                    cout << "\tWhat channel would you like to watch? (1 to 100)" << endl;
                LivingTvChannelAgain:
                    while(!(cin >> livingTvChannel))
                    {
                        wrongBeep();
                        cout << "\tInvalid Entry. Enter Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (livingTvChannel >= 1 && livingTvChannel <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "\tThe Channel is changed to " << livingTvChannel << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tOnly 100 channels are available (i.e. 1 to 100). Enter Again: " << endl;
                        goto LivingTvChannelAgain;
                    }
                }

            /////////////////////////// Change Volume ////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "\tTv is off right now" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tCurrent volume is " << livingTvVolume << endl;
                    cout << "\tEnter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                LivingTvVolumeAgain:
                    while(!(cin >> livingTvVolume))
                    {
                        wrongBeep();
                        cout << "\tInvalid Entry. Enter Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (livingTvVolume >= 0 && livingTvVolume <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "\tThe volume is now " << livingTvVolume << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "\tInvalid Volume. Enter Again: " << endl;
                        goto LivingTvVolumeAgain;
                    }
                }

            /////////////////////////// Cancel ////////////////////////////
            case 5:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                noBeep();
                goto livingOption;

            /////////////////////////// Living Tv invalid option /////////////////
            default:
                wrongBeep();
                cout << "\tInvalid Input. Enter Again: " << endl;
                goto livingTvOptionAgain;
            }

        ///////////////////////////// Music //////////////////////////////////
        case 3:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            //////////////////////// Music Options /////////////////////////
            cout << "\t   1) Turn Music On" << endl;
            cout << "\t   2) Turn Music Off" << endl;
            cout << "\t   3) Choose Genre" << endl;
            cout << "\t   4) Music Volume" << endl;
            cout << "\t   5) Cancel" << endl;
            /////////////////////// Music Input ////////////////////////////
            int musicOption;
        livingmusicOptionAgain:
            while (!(cin >> musicOption))
            {
                wrongBeep();
                cout << "\tInvalid Option. Select again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            /////////////////////// Music Switch //////////////////////////
            switch (musicOption)
            {
            /////////////////////// Music on //////////////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchmusic == 1)
                {
                    noBeep();
                    cout << "\tMusic is already playing" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchmusic = 1;
                    cout << "\tMusic is turned on. And Music Volume is " << musicVolume << endl;
                    goto livingOption;
                }

            /////////////////////// Music off /////////////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchmusic == 0)
                {
                    noBeep();
                    cout << "\tMusic is already off" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchmusic = 0;
                    musicVolume = 67;
                    cout << "\tMusic is turned off" << endl;
                    goto livingOption;
                }


            ////////////////////// Choose Genre /////////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchmusic == 0)
                {
                    wrongBeep();
                    cout << "\tMusic is off right now." << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "\tWhat would you like to listen?" << endl;
                    string musicTrackAnswer;
                    getline (cin, musicTrackAnswer);
                    optionSelectYesBeep();
                    cout << "\tPlaying " << musicTrackAnswer << "..." << endl;
                    goto livingOption;
                }


            //////////////////////// Music Volume /////////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (switchmusic == 1)
                {
                    optionSelectYesBeep();
                    cout << endl;
                    cout << "\tVolume of Music is currently at " << musicVolume << endl;
                    cout << "\tEnter new Volume (from 1 to 100)" << endl;
                    int newVolumeMusic;
                livingnewVolumeMusicAgain:
                    while (!(cin >> newVolumeMusic))
                    {
                        wrongBeep();
                        cout << "\tInvalid Entry. Enter Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (!(newVolumeMusic >= 1) || !(newVolumeMusic <= 100))
                    {
                        wrongBeep();
                        cout << "\tInvalid Volume Level. Choose volume between 1 to 100. Enter again: " << endl;
                        goto livingnewVolumeMusicAgain;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        musicVolume = newVolumeMusic;
                        cout << "\tVolume of music is set to " << newVolumeMusic << endl;
                        goto livingOption;
                    }
                }
                else
                {
                    noBeep();
                    cout << "\tMusic is currently off" << endl;
                    goto livingOption;
                }

            ///////////////////////// Cancel //////////////////////////////
            case 5:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                noBeep();
                goto livingOption;

            //////////////////////// Music Invalid select /////////////////////////
            default:
                wrongBeep();
                cout << "\tInvalid Option. Select again: " << endl;
                goto livingmusicOptionAgain;
            }

        ///////////////////////////// Living Curtains //////////////////////////
        case 4:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            cout << endl;
            if (livingRoomCurtains == 0)
            {
                cout << "\tDo you want me to open curtains?" << endl;
            livingCurtainAnswerAgain:
                getline (cin, livingCurtainAnswer);
                if (livingCurtainAnswer == "Yes" || livingCurtainAnswer == "YES" || livingCurtainAnswer == "yes" || livingCurtainAnswer == "Y" || livingCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "\tOkay..!" << endl;
                    livingRoomCurtains = 1;
                    cout << "\t(Curtains opening)" << endl;
                    goto livingOption;
                }
                else if (livingCurtainAnswer == "No" || livingCurtainAnswer == "NO" || livingCurtainAnswer == "no" || livingCurtainAnswer == "N" || livingCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "\tOkay..!" << endl;
                    goto livingOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it. Please repeat again: " << endl;
                    goto livingCurtainAnswerAgain;
                }
            }
            else
            {
                cout << "\tDo you want me to close the curtains?" << endl;
            livingOpenCurtainAnswerAgain:
                getline (cin, livingCurtainAnswer);
                if (livingCurtainAnswer == "Yes" || livingCurtainAnswer == "YES" || livingCurtainAnswer == "yes" || livingCurtainAnswer == "Y" || livingCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "\tOkay..!" << endl;
                    livingRoomCurtains = 0;
                    cout << "\t(Curtains closing)" << endl;
                    goto livingOption;
                }
                else if (livingCurtainAnswer == "No" || livingCurtainAnswer == "NO" || livingCurtainAnswer == "no" || livingCurtainAnswer == "N" || livingCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "\tOkay..!" << endl;
                    goto livingOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it. Please repeat again: " << endl;
                    goto livingOpenCurtainAnswerAgain;
                }
            }

        //////////////////////////// Return to corridor from Living /////////////////
        case 5:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            cout << "\tDo you want me to turn off all the appliances?" << endl;
        livingLeaveAnswerAgain:
            getline (cin, livingLeaveAnswer);
            if (livingLeaveAnswer == "Yes" || livingLeaveAnswer == "YES" || livingLeaveAnswer == "yes" || livingLeaveAnswer == "Y" || livingLeaveAnswer == "y")
            {
                optionSelectYesBeep();
                cout << endl;
                cout << "\tOkay.." << endl;
                cout << "\t(All appliances of living room are turned off)" << endl;
                if (livingRoomCurtains == 1)
                {
                    livingRoomCurtains = 0;
                    cout << "\t(Curtains are closed)" << endl;
                }
                switchLivingRoomLight = 0;
                livingLightIntensity = 7;
                switchLivingRoomTv = 0;
                livingRoomCurtains = 0;
                goto corridorOption;
            }
            else if (livingLeaveAnswer == "No" || livingLeaveAnswer == "NO" || livingLeaveAnswer == "no" || livingLeaveAnswer == "N" || livingLeaveAnswer == "n")
            {
                noBeep();
                cout << "\tOkay.." << endl;
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "\tI did not Understand it.. Please repeat again: " << endl;
                goto livingLeaveAnswerAgain;
            }

        //////////////////////////// Living Invalid Input //////////////////////////
        default:
            wrongBeep();
            cout << "\tInvalid Option. Select Again: " << endl;
            goto livingOptionSelectAgain;
        }

    //========================================================================================//
    //====================================== Kitchen =========================================//
    case 4:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        optionSelectYesBeep();
    ////////////////////////// Kitchen Options ////////////////////////
    kitchenOption:
        cout << endl;
        cout << "\t(You are in the kitchen)" << endl;
        musicCheck();
        cout << endl;
        HaddaadBurglarProtocolCheck();
        HaddaadRoomBurglarCheck();
        safeRoomBurglarCheck();
        cout << endl;
        cout << "\t   1) Make Smoothie" << endl;
        cout << "\t   2) Make Coffee" << endl;
        cout << "\t   3) Make Protein Shake" << endl;
        cout << "\t   4) Search Recipie on Internet" << endl;
        cout << "\t   5) Return back to Corridor" << endl;
        cout << endl;

        ///////////////////////// Kitchen option Select ////////////////////
        int kitchenOptionSelect;
    kitchenOptionSelectAgain:
        while (!(cin >> kitchenOptionSelect))
        {
            wrongBeep();
            cout << "\tWrong Option. Select Again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ///////////////////////////// Kitchen Switch /////////////////////////////
        switch (kitchenOptionSelect)
        {
        //////////////////////// Make Smoothie ////////////////////////////
        case 1:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (smoothieIngredients == 0)
            {
                noBeep();
                cout << "\tThe Smoothie machine need a Refill.." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "\tMaking Smoothie";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "\tSmoothie is Ready" << endl;
                smoothieIngredients = smoothieIngredients - 1;
                goto kitchenOption;
            }

        ///////////////////////// Make Coffee ///////////////////////////////
        case 2:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (coffeeIngredients == 0)
            {
                noBeep();
                cout << "\tThe Coffee machine needs a Refill.." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "\tMaking Coffee";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "\tCoffee is Ready" << endl;
                coffeeIngredients = coffeeIngredients - 1;
                goto kitchenOption;
            }

        /////////////////////////// Make Protein Shake //////////////////////////
        case 3:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (proteinIngredients == 0)
            {
                noBeep();
                cout << "\tProtein Shake Maker needs a Refill." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "\tMaking Protein Shake";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "\tProtein Shake is Ready" << endl;
                proteinIngredients = proteinIngredients - 1;
                goto kitchenOption;
            }

        /////////////////////////// Search Recipie on Internet ////////////////////////
        case 4:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            cout << "\tWhich Recipie you want to search?" << endl;
            getline (cin, recipieAnswer);
            optionSelectYesBeep();
            cout << "\n\tSearching Recipie of " << recipieAnswer << " on the Internet";
            for (int i = 0; i < 3; i++)
            {
                Beep(0, 1000);
                cout << ".";
            }
            optionSelectYesBeep();
            cout << endl;
            cout << "\tShowing search results on the screen next to stove." << endl;
            goto kitchenOption;

        ///////////////////////////// Return back to corridor /////////////////////////
        case 5:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            goto corridorOption;

        ////////////////////////////// Kitchen Invalid ///////////////////////////////
        default:
            wrongBeep();
            cout << "\tInvalid Option. Select Again: " << endl;
            goto kitchenOptionSelectAgain;
        }

    //========================================================================================//
    //================================= Corridor Lights ======================================//
    case 5:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //////////////////////// Lights option ////////////////////////
        optionSelectYesBeep();
        cout << "\t   1) Turn on the light (Corridor and Kitchen)" << endl;
        cout << "\t   2) Turn off the light (Corridor and Kitchen)" << endl;
        cout << "\t   3) Turn off all the lights" << endl;
        cout << "\t   4) Cancel" << endl;

        //////////////////////// Lights option Select ////////////////////////
        int lightsOptionSelect;
    lightsOptionSelectAgain:
        while (!(cin >> lightsOptionSelect))
        {
            wrongBeep();
            cout << "\tInvalid Option. Select Again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //////////////////////// Lights switch //////////////////////////////
        switch (lightsOptionSelect)
        {
        //////////////////////// turn on the light //////////////////////////
        case 1:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchcorridorlight == 1)
            {
                noBeep();
                cout << "\tLights of corridor and Kitchen are already on." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchcorridorlight = 1;
                cout << "\tLights of corridor and kitchen are turned on." << endl;
                goto corridorOption;
            }

        //////////////////////// turn off the lights ////////////////////////
        case 2:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchcorridorlight == 0)
            {
                noBeep();
                cout << "\tLights are already off." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchcorridorlight = 0;
                cout << "\tLights of the corridor and kitchen are turned off." << endl;
                goto corridorOption;
            }

        //////////////////////// turn off all the lights /////////////////////////
        case 3:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            optionSelectYesBeep();
            switchcorridorlight = 0;
            switchHaddaadRoomLight = 0;
            switchGuestRoomLight = 0;
            switchLivingRoomLight = 0;
            cout << "\tAll the lights are turned off." << endl;
            goto corridorOption;

        //////////////////////////// Cancel ////////////////////////////////
        case 4:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            noBeep();
            goto corridorOption;

        //////////////////////////// Invalid light input /////////////////////
        default:
            wrongBeep();
            cout << "\tInvalid Option. Select Again: " << endl;
            goto lightsOptionSelectAgain;
        }

    //========================================================================================//
    //=================================== Corridor Music =====================================//
    case 6:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        optionSelectYesBeep();
        //////////////////////// Music Options /////////////////////////
        cout << "\t   1) Turn Music On" << endl;
        cout << "\t   2) Turn Music Off" << endl;
        cout << "\t   3) Choose Genre" << endl;
        cout << "\t   4) Music Volume" << endl;
        cout << "\t   5) Cancel" << endl;
        /////////////////////// Music Input ////////////////////////////
        int musicOption;
    musicOptionAgain:
        while (!(cin >> musicOption))
        {
            wrongBeep();
            cout << "\tInvalid Option. Select again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        /////////////////////// Music Switch //////////////////////////
        switch (musicOption)
        {
        /////////////////////// Music on //////////////////////////////
        case 1:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchmusic == 1)
            {
                noBeep();
                cout << "\tMusic is already playing" << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 1;
                cout << "\tMusic is turned on. And Music Volume is " << musicVolume << endl;
                goto corridorOption;
            }

        /////////////////////// Music off /////////////////////////////
        case 2:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchmusic == 0)
            {
                noBeep();
                cout << "\tMusic is already off" << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 0;
                musicVolume = 67;
                cout << "\tMusic is turned off" << endl;
                goto corridorOption;
            }

        ////////////////////// Choose Genre /////////////////////////
        case 3:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchmusic == 0)
            {
                wrongBeep();
                cout << "\tMusic is off right now." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "\tWhat would you like to listen?" << endl;
                string musicTrackAnswer;
                getline (cin, musicTrackAnswer);
                optionSelectYesBeep();
                cout << "\tPlaying " << musicTrackAnswer << "..." << endl;
                goto corridorOption;
            }
            
        //////////////////////// Music Volume /////////////////////////
        case 4:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (switchmusic == 1)
            {
                optionSelectYesBeep();
                cout << endl;
                cout << "\tVolume of Music is currently at " << musicVolume << endl;
                cout << "\tEnter new Volume (from 1 to 100)" << endl;
                int newVolumeMusic;
            newVolumeMusicAgain:
                while (!(cin >> newVolumeMusic))
                {
                    wrongBeep();
                    cout << "\tInvalid Entry. Enter Again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (!(newVolumeMusic >= 1) || !(newVolumeMusic <= 100))
                {
                    wrongBeep();
                    cout << "\tInvalid Volume Level. Choose volume between 1 to 100. Enter again: " << endl;
                    goto newVolumeMusicAgain;
                }
                else
                {
                    optionSelectYesBeep();
                    musicVolume = newVolumeMusic;
                    cout << "\tVolume of music is set to " << newVolumeMusic << endl;
                    goto corridorOption;
                }
            }
            else
            {
                noBeep();
                cout << "\tMusic is currently off" << endl;
                goto corridorOption;
            }

        ///////////////////////// Cancel //////////////////////////////
        case 5:
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            noBeep();
            goto corridorOption;

        //////////////////////// Music Invalid select /////////////////////////
        default:
            wrongBeep();
            cout << "\tInvalid Option. Select again: " << endl;
            goto musicOptionAgain;
        }

    //========================================================================================//
    //============================= Going out of the house ===================================//
    case 7:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        optionSelectYesBeep();
        /////////////////////////// both in house ///////////////////////////
        if (Haddaad == 1 && Guest == 1)
        {
            cout << "\tWho is going?" << endl;
            cout << "\t   1) Both" << endl;
            cout << "\t   2) Haddaad" << endl;
            cout << "\t   3) Guest" << endl;
            cout << "\t   4) No one" << endl;
            int goOutAnswer;
        goOutAnswerAgain:
            while (!(cin >> goOutAnswer))
            {
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (goOutAnswer)
            {
            //////////////////////////// Both going outside //////////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                Haddaad = 0;
                Guest = 0;
                cout << "\t(The Door gets locked when both of you gets out of the house)" << endl;
            bothAskGettingBackInAgain:
                cout << "\tGetting back in?" << endl;
            bothGetBackInAgain:
                getline (cin, getBackIn);
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    cout << "\tWho is getting in?" << endl;
                    cout << "\t   1) Both" << endl;
                    cout << "\t   2) Haddaad" << endl;
                    cout << "\t   3) Guest" << endl;
                    cout << "\t   4) No one" << endl;
                    int bothOutAnswer;
                bothOutAnswerAgain:
                    while (!(cin >> bothOutAnswer))
                    {
                        wrongBeep();
                        cout << "Invalid Option. Select Again: " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (bothOutAnswer)
                    {
                    //////////////// both getting in //////////////////////
                    case 1:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        optionSelectYesBeep();
                        Haddaad = 1;
                        Guest = 1;
                        cout << "\t(the door opens automatically without entring key)" << endl;
                        cout << "\t(the door gets locked when both of you gets back in the house)" << endl;
                        goto corridorOption;

                    //////////////// Haddaad getting in ////////////////////
                    case 2:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        optionSelectYesBeep();
                        Haddaad = 1;
                        cout << "\t(the door opens automatically without entring key)" << endl;
                        cout << "\t(the door gets locked when you get back in the house)" << endl;
                        goto corridorOption;

                    //////////////// Guest getting in /////////////////////
                    case 3:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        optionSelectYesBeep();
                        Guest = 1;
                        cout << "\t(the door opens automatically without entring key)" << endl;
                        cout << "\t(the door gets locked when you get back in the house)" << endl;
                        goto corridorOption;

                    //////////////// No one getting in /////////////////////
                    case 4:
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        noBeep();
                        cout << "\tOkay.." << endl;
                        goto bothAskGettingBackInAgain;

                    default:
                        wrongBeep();
                        cout << "\tInvalid Option. Select Again: " << endl;
                        goto bothOutAnswerAgain;
                    }
                }

                /////////////////////////// no Getting back in //////////////////////////////////
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "\tOkay.." << endl;
                    goto bothAskGettingBackInAgain;
                }
                /////////////////////////////// wrong getting back in /////////////////////////////
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it..! Please Repeat Again: " << endl;
                    goto bothGetBackInAgain;
                }

            //////////////////////////// Haddaad going out ////////////////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                Haddaad = 0;
                cout << "\t(the Door gets locked when you get out of the house)" << endl;
            bothHaddaadAskGettingBackInAgain:
                cout << "\tGetting back in?" << endl;
            bothHaddaadGetBackInAgain:
                getline (cin, getBackIn);
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    Haddaad = 1;
                    cout << "\t(The door Opens automatically without entring key)" << endl;
                    cout << "\t(The door gets locked when you get back in the house)" << endl;
                    goto corridorOption;
                }
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "\tOkay Haddaad.." << endl;
                    goto bothHaddaadAskGettingBackInAgain;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it Haddaad..! Please Answer Again: " << endl;
                    goto bothHaddaadGetBackInAgain;
                }

            //////////////////////////// Guest going out //////////////////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                Guest = 0;
                cout << "\t(the Door gets locked when you get out of the house)" << endl;
            guestAskGettingBackInAgain:
                cout << "\tgetting back in?" << endl;
            guestGetBackInAgain:
                getline (cin, getBackIn);
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    Guest = 1;
                    cout << "\t(The door Opens automatically without entring key)" << endl;
                    cout << "\t(The door gets locked when you get back in the house)" << endl;
                    goto corridorOption;
                }
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "\tOkay.." << endl;
                    goto guestAskGettingBackInAgain;
                }
                else
                {
                    wrongBeep();
                    cout << "\tI did not Understand it..! Please repeat Again: " << endl;
                    goto guestGetBackInAgain;
                }

            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                ////////////////// no one /////////////////////
                noBeep();
                cout << "\tOkay..!" << endl;
                goto corridorOption;

            default:
                wrongBeep();
                cout << "\tInvalid option. Select Again: " << endl;
                goto goOutAnswerAgain;
            }
        }
        /////////////////////////// Haddaad only ///////////////////////////////
        else if (Haddaad == 1 && Guest == 0)
        {
            Haddaad = 0;
            cout << "\t(The Door gets locked when you get out of the house)" << endl;
        HaddaadAskGettingBackInAgain:
            cout << "\tGetting back in?" << endl;
        HaddaadGetBackInAgain:
            getline (cin, getBackIn);
            if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
            {
                optionSelectYesBeep();
                Haddaad = 1;
                cout << "\t(The door Opens automatically without entring key)" << endl;
                cout << "\t(The door gets locked when you get back in the house)" << endl;
                goto corridorOption;
            }
            else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
            {
                noBeep();
                cout << "\tOkay Haddaad.." << endl;
                goto HaddaadAskGettingBackInAgain;
            }
            else
            {
                wrongBeep();
                cout << "\tI did not Understand it Haddaad..! Please repeat Again: " << endl;
                goto HaddaadGetBackInAgain;
            }
        }
        ////////////////////////////// Guest only ///////////////////////////
        else if (Haddaad == 0 && Guest == 1)
        {
            Guest = 0;
            cout << "\t(The Door gets locked when you get out of the house)" << endl;
        askGettingBackInAgain:
            cout << "\tGetting back in?" << endl;
        getBackInAgain:
            getline (cin, getBackIn);
            if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
            {
                optionSelectYesBeep();
                Guest = 1;
                cout << "\t(The door Opens automatically without entring key)" << endl;
                cout << "\t(The door gets locked when you get back in the house)" << endl;
                goto corridorOption;
            }
            else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
            {
                noBeep();
                cout << "\tOkay.." << endl;
                goto askGettingBackInAgain;
            }
            else
            {
                wrongBeep();
                cout << "\tI did not Understand it..! Please repeat Again: " << endl;
                goto getBackInAgain;
            }
        }

    //========================================================================================//
    //=================================== Leaving House ======================================//
    case 8:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        optionSelectYesBeep();
        ////////////////////////// Both in house /////////////////////////
        if (Haddaad == 1 && Guest == 1)
        {
            cout << "\tWho is going?" << endl;
            cout << "\t   1) Both" << endl;
            cout << "\t   2) Haddaad" << endl;
            cout << "\t   3) Guest" << endl;
            cout << "\t   4) No one" << endl;
            int leaveAnswer;
        leaveAnswerAgain:
            while (!(cin >> leaveAnswer))
            {
                wrongBeep();
                cout << "\tInvalid Option. Select Again: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (leaveAnswer)
            {
            /////////////////////////// Both leaving ///////////////////////////////
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                LeavingHouse();
                cout << "\t(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
                cout << "\t(Curtains are also closed)" << endl;
                cout << "\tBye Everyone.. Take care of yourselves." << endl;
                cout << "\t(Main Door gets locked after both of you gets out of the house)" << endl;
                break;

            ////////////////////// Haddaad leaving ///////////////////////////////
            case 2:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                Haddaad = 0;
                cout << "\tGoodbye Haddaad.. See you soon." << endl;
                cout << "\t(Door gets locked when you get out of the house)" << endl;
                break;

            //////////////////// Guest leaving //////////////////////
            case 3:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                optionSelectYesBeep();
                Guest = 0;
                cout << "\tGoodbye.. Take care of yourself." << endl;
                cout << "\t(Door gets locked when you get out of the house)" << endl;
                break;

            //////////////////// no one leaving ///////////////////////////
            case 4:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                noBeep();
                cout << "\tOkay..!" << endl;
                goto corridorOption;

            default:
                wrongBeep();
                cout << "\tInvalid option. Select Again: " << endl;
                goto leaveAnswerAgain;
            }
        }
        ////////////////////////// Haddaad only ///////////////////////////
        else if (Haddaad == 1 && Guest == 0)
        {
            LeavingHouse();
            cout << "\t(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
            cout << "\t(Curtains are also closed)" << endl;
            cout << "\tBye Haddaad.. See you soon." << endl;
            cout << "\t(Main Door gets locked after you get out of the house)" << endl;
        }
        //////////////////////// Guest only ////////////////////////////
        else if (Haddaad == 0 && Guest == 1)
        {
            LeavingHouse();
            cout << "\t(All electrical appliances (lights, music player, etc) are turned off.)" << endl;
            cout << "\t(Curtains are also closed)" << endl;
            cout << "\tGood Bye.. Take care of yourself..!" << endl;
            cout << "\t(Main Door gets locked after you get out of the house)" << endl;
        }

        exit(0);

    //////////////////////////////// Haddaad in case of emergency //////////////////////////////
    case 1998:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (HaddaadRoomLock == 0)
        {
            wrongBeep();
            cout << "\tThe Haddaad's Room Door is already open." << endl;
            cout << "\t(The door opens)" << endl;
            goto guestOption;
        }
        else if (HaddaadRoomLock == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                Beep(400, 250);
                Beep(0, 100);
            }
            cout << "\t(Hidden Haddaad's Room Door Unlock Portal opens)"
                 << endl;
            cout << "\tYou need an Emergency Key to open Haddaad's Room Door. If you have emergency key \n\
\tand want to enter the Haddaad's Room then say Yes. Otherwise say No." << endl;
            string HaddaadIntruderAnswer;
        HaddaadIntruderAnswerAgain:
            getline (cin, HaddaadIntruderAnswer);
            if (HaddaadIntruderAnswer == "Yes" || HaddaadIntruderAnswer == "YES" || HaddaadIntruderAnswer == "yes" || HaddaadIntruderAnswer == "Y" || HaddaadIntruderAnswer == "y")
            {
                optionSelectYesBeep();
                cout << "\tEnter key: " << endl;
                getline (cin, HaddaadIntruderInputKey);
                if (HaddaadIntruderInputKey == emergencyKey)
                {
                    correctBeep();
                    HaddaadRoomLock = 0;
                    cout << "\tKey Accepted." << endl;
                    goto HaddaadOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tWrong Key. Access denied." << endl;
                    cout << "\t(Hidden Guest Room Door Unlock Portal closes)";
                    goto corridorOption;
                }
            }
            else if (HaddaadIntruderAnswer == "No" || HaddaadIntruderAnswer == "NO" || HaddaadIntruderAnswer == "no" || HaddaadIntruderAnswer == "N" || HaddaadIntruderAnswer == "n")
            {
                noBeep();
                cout << "\tOkay" << endl;
                for (int i = 0; i < 5; i++)
                {
                    Beep(130, 250);
                    Beep(0, 100);
                }
                cout << "\t(Hidden Guest Room Door Unlock Portal closes)";
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "\tI did not Understand it. Please repeat Again: " << endl;
                goto HaddaadIntruderAnswerAgain;
            }
        }


    //////////////////////////////// Guest in case of emergency //////////////////////////////
    case 1987:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (guestRoomLock == 0)
        {
            wrongBeep();
            cout << "\tThe Guest Room Door is already open." << endl;
            cout << "\t(The door opens)" << endl;
            goto guestOption;
        }
        else if (guestRoomLock == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                Beep(400, 250);
                Beep(0, 100);
            }
            cout << "\t(Hidden Guest Room Door Unlock Portal opens)"
                 << endl;
            cout << "\tYou need an Emergency Key to open the Guest Room Door. If you have emergency key \n\
\tand want to enter the Guest Room then say Yes. Otherwise say No." << endl;
            string guestIntruderAnswer;
        guestIntruderAnswerAgain:
            getline (cin, guestIntruderAnswer);
            if (guestIntruderAnswer == "Yes" || guestIntruderAnswer == "YES" || guestIntruderAnswer == "yes" || guestIntruderAnswer == "Y" || guestIntruderAnswer == "y")
            {
                optionSelectYesBeep();
                cout << "\tEnter key: " << endl;
                getline (cin, guestIntruderInputKey);
                if (guestIntruderInputKey == emergencyKey)
                {
                    correctBeep();
                    guestRoomLock = 0;
                    cout << "\tKey Accepted." << endl;
                    goto guestOption;
                }
                else
                {
                    wrongBeep();
                    cout << "\tWrong Key. Access Denied" << endl;
                    cout << "\t(Hidden Guest Room Door Unlock Portal closes)";
                    goto corridorOption;
                }
            }
            else if (guestIntruderAnswer == "No" || guestIntruderAnswer == "NO" || guestIntruderAnswer == "no" || guestIntruderAnswer == "N" || guestIntruderAnswer == "n")
            {
                noBeep();
                cout << "\tOkay" << endl;
                for (int i = 0; i < 5; i++)
                {
                    Beep(130, 250);
                    Beep(0, 100);
                }
                cout << "\t(Hidden Guest Room Door Unlock Portal closes)";
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "\tI did not Understand it. Please repeat Again: " << endl;
                goto guestIntruderAnswerAgain;
            }
        }
        
    ////////////////////// Corridor Invalid Option ///////////////////////
    default:
        wrongBeep();
        cout << "\tInvalid Option. Select again: " << endl;
        goto corridorOptionSelectAgain;
    }

    getch();
    return 0;
}
