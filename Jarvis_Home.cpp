#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
#include <windows.h>


using namespace std;


/// ========================================================================== ///

//////////////////////////////// Before Main ///////////////////////////////////


///////////// Global Variables ///////////
    string MasterKey = "74588";
    string mainDoorKey = "12345";
    string safeRoomKey = "Zombies";
    string safekey = "Brains";
    string burglarMasterKeyInput;
    string musicAnswer;
    string getBackIn;
    string recipieAnswer;
    string livingCurtainAnswer;
    string guestIntruderInputKey;
    string guestLeaveAnswer;
    string livingLeaveAnswer;
    string masterLeaveAnswer;
    string safeRoomKeyInput;
    string safeKeyInput;
    string safeCloseInput;
    string MasterBurglarSure;

    bool switchcorridorlight = 0;
    bool switchMasterRoomLight = 0;
    bool switchGuestRoomLight = 0;
    bool switchLivingRoomLight = 0;
    
    bool switchmusic = 0;
    bool Master = 1;
    bool Guest = 0;
    bool switchCurtain = 0;
    bool switchTv = 0;
    int musicVolume = 67;
    int proteinIngredients = 3;
    int coffeeIngredients = 3;
    int smoothieIngredients = 3;
    int livingLightIntensity = 7;
    bool switchLivingRoomTv = 0;
    int livingTvChannel = 05;
    int livingTvVolume = 67;
    int guestLightIntensity = 7;
    bool switchGuestTv = 0;
    int guestTvChannel = 10;
    int guestTvVolume = 67;
    bool switchGuestMusic = 0;
    int guestMusicVolume = 67;
    int masterLightIntensity = 7;
    bool switchMasterMusic = 0;
    int masterMusicVolume = 67;
    bool switchMastertv = 0;
    int masterTvChannel = 15;
    int masterTvVolume = 67;
    int safeKeyTries = 0;
    bool safeBurglarCheck = 0;
    int safeRoomtries = 0;
    bool MasterBurglarCheck = 0;
    bool safeRoomLock = 1;
    bool IfBurglar = 0;

    bool livingRoomCurtains = 0;
    bool guestCurtain = 0;
    bool masterCurtain = 0;

    bool guestRoomLock = 0;
    bool masterRoomLock = 0;
    


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


////////////////////////////////////// Music Check ////////////////////////////////
void musicCheck()
{
    if (switchmusic == 1)
    {
        cout << "(Music is playing in the background)" << endl;
    }
}


/////////////////////////////////////// Living room Curtains check /////////////////////////
void livingCurtainCheck()
{
    if (livingRoomCurtains == 0)
    {
        cout << "(Curtains are closed right now)" << endl;
    }
    else
    {
        cout << "(Curtains are open)" << endl;
    }
}


//////////////////////////////////// Living Room Tv Check ///////////////////////
void livingTvCheck()
{
    if (switchLivingRoomTv == 1)
    {
        cout << "(Tv is on and current channel is " << livingTvChannel << " and volume is " << livingTvVolume << ")" << endl;
    }
}


//////////////////////////////////// Guest Room Curtains Check ///////////////////////
void guestCurtainCheck()
{
    if (guestCurtain == 0)
    {
        cout << "(Curtains are closed)" << endl;
    }
    else
    {
        cout << "(Curtains are open)" << endl;
    }
}

//////////////////////////////////// Guest Room Tv Check ///////////////////////
void guestTvCheck()
{
    if (switchGuestTv == 1)
    {
        cout << "(Tv is on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
    }
}

////////////////////////////////////// Guest Music Check ////////////////////////////////
void GuestMusicCheck()
{
    if (switchGuestMusic == 1)
    {
        cout << "(Music is Playing in the background and music volume is " << guestMusicVolume << ")" << endl;
    }
    
}


/////////////////////////////////// Guest Room Lock Check ////////////////////////////////
void guestLockCheck()
{
    if (guestRoomLock == 1)
    {
        cout << "(Room door is locked)" << endl;
    }
    else
    {
        cout << "(Room door is not Locked)" << endl;
    }
}


/////////////////////////////////// Master Tv Check ////////////////////////////////
void masterTvCheck()
{
    if (switchMastertv == 1)
    {
        cout << "(Tv is on and current channel is " << masterTvChannel << " and volume is " << masterTvVolume << ")" << endl;
    }
}


//////////////////////////////////////// Master Music Check /////////////////////////////
void MasterMusicCheck()
{
    if (switchMasterMusic == 1)
    {
        cout << "(Music is Playing in the background and music volume is " << masterMusicVolume << ")" << endl;
    }    
}


////////////////////////////////////// Master Curtain Check /////////////////////////////
void masterCurtainCheck()
{
    if (masterCurtain == 0)
    {
        cout << "(Curtains are closed)" << endl;
    }
    else
    {
        cout << "(Curtains are open)" << endl;
    }
}


////////////////////////////// Master Room Lock Check /////////////////////////////
void masterLockCheck()
{
    if (masterRoomLock == 1)
    {
        cout << "(Room door is locked)" << endl;
    }
    else
    {
        cout << "(Room door is not Locked)" << endl;
    }
}








/// =============================================================================== ///
/// =============================================================================== ///


main()
{
    
    ///////////// Opening statement //////////////
    cout << setw(50) << "Jarvis Home" << endl;
    cout << setw(53) << "A Smart Home Agent" << endl;

    ///////////// House Description //////////////
    cout << "(This house has 1 guest room, 1 master room, an open kitchen, a drawing room and a corridor.\n\
There is only one door through which you can enter or leave the house. The Master room has some\n\
more security features which only master can access. Only Master has a special security key (Master\n\
key) with which he can open any door of the house. There is also a safe room in Master room\n\
which is accessed by master key only. The temperature of the house is fully maintained by\n\
automatic temperature controller. The house has some more features related to different\n\
appliances of the house. The Jarvis(AI Assistant) take care of different things of house\n\
automatically. The house is fitted with proximity sensors and detect that if a person is present in the room or not and\n\
if Jarvis detects that no one is in a certain place and the appliances are on, She will turn them off automatically)" << endl;


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
    cout << "(Main Door opens. Lights of corridor and Kitchen are turned on.)" << endl;

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
                cout << "(music is playing now)" << endl << endl;
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
    cout << "(You are in the corridor)" << endl;
    musicCheck();
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
        wrongBeep();
        cout << "Invalid Input. Select Again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    //////////////////// Corridor Switch ////////////////////////////
    switch (corridorOptionSelect)
    {
    ///////////////////////////// Master Room //////////////////////////////
    case 1:
        optionSelectYesBeep();
        cout << endl;
        cout << "(The Door of Master room opens)" << endl;
        if (switchMasterRoomLight == 0)
        {
            cout << "(The Lights of the Master room turns on)" << endl;
            switchMasterRoomLight = 1;
        }
        else
        {
            cout << "(Light of the room is already on)" << endl;
        }

        ////////////////////////////// Master Room Option /////////////////////
        masterOption:
        cout << endl;
        cout << "(You are in the Master room)" << endl;
        masterCurtainCheck();
        MasterMusicCheck();
        masterTvCheck();
        masterLockCheck();
        cout << endl;
        cout << "   1) Lights" << endl;
        cout << "   2) TV" << endl;
        cout << "   3) Music" << endl;
        cout << "   4) Curtains" << endl;
        cout << "   5) Room Lock" << endl;
        cout << "   6) Safe Room" << endl;
        cout << "   7) Burglar's Protocol" << endl;
        cout << "   8) Return to corridor" << endl;
        cout << endl;

        ///////////////////////////// Master Room option Select //////////////////////
        int masterOptionSelect;
        masterOptionSelectAgain:
        while (!(cin >> masterOptionSelect))
        {
            wrongBeep();
            cout << "Invalid Input. Enter Again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ////////////////////////////// Master Room Switch ////////////////////////////
        switch (masterOptionSelect)
        {
        /////////////////////////// Master Lights //////////////////////////////////
        case 1:
            optionSelectYesBeep();
            cout << "   1) Turn on the lights" << endl;
            cout << "   2) Turn off the lights" << endl;
            cout << "   3) Light Intensity" << endl;
            cout << "   4) Cancel" << endl;

            //////////////////// Master Lights Option Select //////////////////////////
            int masterLightsOptionSelect;
            masterLightsOptionSelectAgain:
            while (!(cin >> masterLightsOptionSelect))
            {
                wrongBeep();
                cout << "Invaid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            //////////////////// Master lights Switch //////////////////////////
            switch (masterLightsOptionSelect)
            {
            ////////////////////////// Turn on the light /////////////////////
            case 1:
                if (switchMasterRoomLight == 1)
                {
                    noBeep();
                    cout << "Lights are already on" << endl;
                    goto masterOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Lights are turned on" << endl;
                    switchMasterRoomLight = 1;
                    goto masterOption;
                }

            ////////////////////////// Turn off the light ////////////////////
            case 2:
                if (switchMasterRoomLight == 0)
                {
                    noBeep();
                    cout << "Lights are already off" << endl;
                    goto masterOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Lights are turned off" << endl;
                    switchMasterRoomLight = 0;
                    masterLightIntensity = 7;
                    goto masterOption;
                }

            ///////////////////////// Light Intensity ///////////////////////
            case 3:
                if (switchMasterRoomLight == 0)
                {
                    noBeep();
                    cout << "Lights are off" << endl;
                    goto masterOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Light Intensity is at " << masterLightIntensity << endl;
                    cout << endl;
                    cout << "Enter new Intensity (from 1 to 7)" << endl;
                    MasterLightIntensityAgain:
                    while (!(cin >> masterLightIntensity))
                    {
                        wrongBeep();
                        cout << "Invalid Input. Input Again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (masterLightIntensity >= 1 && masterLightIntensity <= 7)
                    {
                        optionSelectYesBeep();
                        cout << "Light Intensity is set to " << masterLightIntensity << endl;
                        goto masterOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Intensity of light is from 1 to 7 only. Enter Again: ";
                        goto MasterLightIntensityAgain;
                    }
                }

            ///////////////////////// Cancel ////////////////////////////
            case 4:
                noBeep();
                goto masterOption;
            
            ///////////////////////// Master light invalid option //////////////////
            default:
                wrongBeep();
                cout << "Invalid Option. Select again: ";
                goto masterLightsOptionSelectAgain;
            }
    
        /////////////////////////// Master Tv ///////////////////////////////
        case 2:
            optionSelectYesBeep();
            cout << endl;
            cout << "   1) Turn on TV" << endl;
            cout << "   2) Turn off TV" << endl;
            cout << "   3) Change channel to" << endl;
            cout << "   4) Change Volume" << endl;
            cout << "   5) Cancel" << endl;
            cout << endl;

            ////////////////////////// Master TV Option Select ////////////////////////
            int masterTvOptionSelect;
            masterTvOptionSelectAgain:
            while(!(cin >> masterTvOptionSelect))
            {
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ////////////////////////// Master Tv Switch //////////////////////////
            switch (masterTvOptionSelect)
            {
            ///////////////////////// Turn on Tv //////////////////////////
            case 1:
                if (switchMasterMusic == 1)
                {
                    if (switchMastertv == 1)
                    {
                        noBeep();
                        cout << "TV is already on" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMastertv = 1;
                        cout << "TV is turned on" << endl;
                        cout << "(TV turns on and current channel is " << masterTvChannel << " and volume is " << masterTvVolume << ")" << endl;
                        if (masterMusicVolume != 0)
                        {
                            masterMusicVolume = 0;
                            cout << "(Music is muted)" << endl;
                        }
                        goto masterOption;
                    }
                }
                else
                {
                    if (switchMastertv == 1)
                    {
                        noBeep();
                        cout << "TV is already on" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMastertv = 1;
                        cout << "TV is turned on" << endl;
                        cout << "(TV turns on and current channel is " << masterTvChannel << " and volume is " << masterTvVolume << ")" << endl;
                        goto masterOption;
                    }
                }

            ///////////////////////// Turn Off Tv //////////////////////////
            case 2:
                if (switchMasterMusic == 1)
                {
                    if (switchMastertv == 0)
                    {
                        noBeep();
                        cout << "TV is already off" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMastertv = 0;
                        masterTvVolume = 67;
                        cout << "TV is turned off" << endl;
                        cout << "(TV turns off)" << endl;
                        if (masterMusicVolume == 0)
                        {
                            masterMusicVolume = 67;
                            cout << "(music is unmuted and volume is set to 67)" << endl;
                        }
                        goto masterOption;
                    }
                }
                else
                {
                    if (switchMastertv == 0)
                    {
                        noBeep();
                        cout << "TV is already off" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMastertv = 0;
                        masterTvVolume = 67;
                        cout << "TV is turned off" << endl;
                        cout << "(TV turns off)" << endl;
                        goto masterOption;
                    }
                }

            ///////////////////////// Change Tv Channel //////////////////////////
            case 3:
                if (switchMastertv == 0)
                {
                    noBeep();
                    cout << "Tv is off right now" << endl;
                    goto masterOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Current channel is " << masterTvChannel << endl;
                    cout << "Which channel you want me to tune into? (1 to 100)" << endl;
                    MasterTvChannelAgain:
                    cin >> masterTvChannel;
                    if (masterTvChannel >= 1 && masterTvChannel <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "The Channel is changed to " << masterTvChannel << endl;
                        goto masterOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Only 100 channels are available (i.e. 1 to 100). Enter Again: ";
                        goto MasterTvChannelAgain;
                    }
                }

            ///////////////////////// Change Volume //////////////////////////
            case 4:
                if (switchMastertv == 0)
                {
                    noBeep();
                    cout << "Tv is off right now" << endl;
                    goto masterOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Current volume is " << masterTvVolume << endl;
                    cout << "Enter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                    masterTvVolumeAgain:
                    cin >> masterTvVolume;
                    if (masterTvVolume >= 0 && masterTvVolume <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "The volume is now " << masterTvVolume << endl;
                        goto masterOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Invalid Volume. Enter Again: ";
                        goto masterTvVolumeAgain;
                    }
                }

            ///////////////////////// Cancel //////////////////////////
            case 5:
                noBeep();
                goto masterOption;
            
            ///////////////////////// Master Tv Invalid ////////////////////
            default:
                wrongBeep();
                cout << "Invalid Option. Select Again: ";
                goto masterTvOptionSelectAgain;
            }

        /////////////////////////// Master Music /////////////////////////////
        case 3:
            optionSelectYesBeep();
            //////////////////////// Master Music Options /////////////////////////
            cout << "   1) Turn Music On" << endl;
            cout << "   2) Turn Music Off" << endl;
            cout << "   3) Music Volume" << endl;
            cout << "   4) Cancel" << endl;

            /////////////////////// Master Music Input ////////////////////////////
            int masterMusicOption;
            masterMusicOptionAgain:
            while (!(cin >> masterMusicOption))
            {
                wrongBeep();
                cout << "Invalid Input. Select again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ///////////////////////// Master Music Switch ////////////////////////////
            switch (masterMusicOption)
            {
            /////////////////////// Turn on music //////////////////////
            case 1:
                if (switchMastertv == 1)
                {
                    if (switchMasterMusic == 1)
                    {
                        noBeep();
                        cout << "Music is already playing" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMasterMusic = 1;
                        cout << "Music is turned on. And Music Volume is " << masterMusicVolume << endl;
                        if (masterTvVolume != 0)
                        {
                            masterTvVolume = 0;
                            cout << "(Tv is muted)" << endl;
                        }
                        goto masterOption;
                    }
                }
                else
                {
                    if (switchMasterMusic == 1)
                    {
                        noBeep();
                        cout << "Music is already playing" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMasterMusic = 1;
                        cout << "Music is turned on. And Music Volume is " << masterMusicVolume << endl;
                        goto masterOption;
                    }
                }

            /////////////////////// Turn off music //////////////////////
            case 2:
                if (switchMastertv == 1)
                {
                    if (switchMasterMusic == 0)
                    {
                        noBeep();
                        cout << "Music is already off" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMasterMusic = 0;
                        masterMusicVolume = 67;
                        cout << "Music is turned off" << endl;
                        if (masterTvVolume == 0)
                        {
                            masterTvVolume = 67;
                            cout << "(Tv is unmuted and volume is set to 67)" << endl;
                        }
                        goto masterOption;
                    }
                }
                else
                {
                    if (switchMasterMusic == 0)
                    {
                        noBeep();
                        cout << "Music is already off" << endl;
                        goto masterOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        switchMasterMusic = 0;
                        masterMusicVolume = 67;
                        cout << "Music is turned off" << endl;
                        goto masterOption;
                    }
                }

            /////////////////////// Music Volume //////////////////////
            case 3:
                if (switchMasterMusic == 1)
                {
                    optionSelectYesBeep();
                    cout << endl;
                    cout << "Volume of Music is currently at " << masterMusicVolume << endl;
                    cout << "Enter new Volume (from 1 to 100)" << endl;
                    MasterMusicVolumeAgain:
                    while (!(cin >> masterMusicVolume))
                    {
                        wrongBeep();
                        cout << "Invalid Input. Enter Again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (!(masterMusicVolume >= 1) || !(masterMusicVolume <= 100))
                    {
                        wrongBeep();
                        cout << "Wrong Volume Level. Volume can be any level between 1 to 100 only. Enter again: ";
                        goto MasterMusicVolumeAgain;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Volume of music is set to " << masterMusicVolume << endl;
                        goto masterOption;
                    }
                }
                else
                {
                    noBeep();
                    cout << "Music is currently off" << endl;
                    goto masterOption;
                }

            /////////////////////// Cancel //////////////////////
            case 4:
                noBeep();
                goto masterOption;
            
            /////////////////////// Master Music Invalid //////////////////
            default:
                wrongBeep();
                cout << "Invalid Option. Select Again: ";
                goto masterMusicOptionAgain;
            }

        ///////////////////////////// Master Curtains /////////////////////////
        case 4:
            optionSelectYesBeep();
            cout << endl;
            if (masterCurtain == 0)
            {
                cout << "Do you want me to open curtains?" << endl;
                string masterCurtainAnswer;
                masterCurtainAnswerAgain:
                cin >> masterCurtainAnswer;
                if (masterCurtainAnswer == "Yes" || masterCurtainAnswer == "YES" || masterCurtainAnswer == "yes" || masterCurtainAnswer == "Y" || masterCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "Okay..!" << endl;
                    masterCurtain = 1;
                    cout << "(Curtains Opens)" << endl;
                    goto masterOption;
                }
                else if (masterCurtainAnswer == "No" || masterCurtainAnswer == "NO" || masterCurtainAnswer == "no" || masterCurtainAnswer == "N" || masterCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "Okay..!" << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you. Please answer again: ";
                    goto masterCurtainAnswerAgain;
                }
            }
            else
            {
                cout << "Do you want me to close the curtains?" << endl;
                string masterCurtainAnswer;
                masterCurtainOpenAnswerAgain:
                cin >> masterCurtainAnswer;
                if (masterCurtainAnswer == "Yes" || masterCurtainAnswer == "YES" || masterCurtainAnswer == "yes" || masterCurtainAnswer == "Y" || masterCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "Okay..!" << endl;
                    masterCurtain = 0;
                    cout << "(Curtains Close)" << endl;
                    goto masterOption;
                }
                else if (masterCurtainAnswer == "No" || masterCurtainAnswer == "NO" || masterCurtainAnswer == "no" || masterCurtainAnswer == "N" || masterCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "Okay..!" << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you. Please answer again: ";
                    goto masterCurtainOpenAnswerAgain;
                }
            }

        ///////////////////////////// Master Room lock ////////////////////////
        case 5:
            optionSelectYesBeep();
            if(masterRoomLock == 0)
            {
                cout << "Do You want me to Lock the room door?" << endl;
                string masterLockAnswer;
                masterLockAnswerAgain:
                cin >> masterLockAnswer;
                if (masterLockAnswer == "Yes" || masterLockAnswer == "YES" || masterLockAnswer == "yes" || masterLockAnswer == "Y" || masterLockAnswer == "y")
                {
                    optionSelectYesBeep();
                    masterRoomLock = 1;
                    cout << "Room door is locked now" << endl;
                    goto masterOption;
                }
                else if (masterLockAnswer == "No" || masterLockAnswer == "NO" || masterLockAnswer == "no" || masterLockAnswer == "N" || masterLockAnswer == "n")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you.. Please Answer Again: ";
                    goto masterLockAnswerAgain;
                }
            }
            else
            {
                cout << "Do You want me to unlock the room door?" << endl;
                string masterLockAnswer;
                masterUnlockAnswerAgain:
                cin >> masterLockAnswer;
                if (masterLockAnswer == "Yes" || masterLockAnswer == "YES" || masterLockAnswer == "yes" || masterLockAnswer == "Y" || masterLockAnswer == "y")
                {
                    optionSelectYesBeep();
                    masterRoomLock = 0;
                    cout << "Room door is unlocked now" << endl;
                    goto masterOption;
                }
                else if (masterLockAnswer == "No" || masterLockAnswer == "NO" || masterLockAnswer == "no" || masterLockAnswer == "N" || masterLockAnswer == "n")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you.. Please Answer Again: ";
                    goto masterUnlockAnswerAgain;
                }
            }

        ///////////////////////////// Master Safe Room ////////////////////////
        case 6:
            optionSelectYesBeep();
            cout << endl;
            cout << "Enter key to Enter: ";
            safeRoomKeyInputAgain:
            cin >> safeRoomKeyInput;
            if (safeRoomKeyInput == safeRoomKey)
            {
                ////////////////// Safe Room Options /////////////////
                correctBeep();
                safeRoomtries = 0;
                cout << "Key Accepted." << endl;
                cout << "(The light of the safe room turns on)" << endl;
                cout << "(The Door of safe room closes when you get into the safe room)" << endl;
                safeRoomOption:
                cout << endl;
                cout << "   1) Use Safe" << endl;
                cout << "   2) Return to Master Room" << endl;
                cout << endl;
                int safeRoomOptionSelect;
                safeRoomOptionSelectAgain:
                while(!(cin >> safeRoomOptionSelect))
                {
                    cout << "Invalid Input. Enter Again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                //////////////////// Safe Room Switch ///////////////////
                switch (safeRoomOptionSelect)
                {
                /////////////////////// Use Safe ////////////////////////
                case 1:
                    optionSelectYesBeep();
                    cout << "Enter Safe Key: ";
                    cin >> safeKeyInput;
                    if (safeKeyInput == safekey)
                    {
                        correctBeep();
                        safeKeyTries = 0;
                        cout << "Safe Opens" << endl;
                        cout << "Press 1 to lock the safe (When you finish your Business): ";
                        safeCloseInputAgain:
                        cin >> safeCloseInput;
                        if (safeCloseInput == "1")
                        {
                            optionSelectYesBeep();
                            cout << "Safe is locked now." << endl;
                            goto safeRoomOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "Invalid Input. Press 1 to lock the Safe (When you finish your Business): ";
                            goto safeCloseInputAgain;
                        }
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Invalid Key." << endl;
                        safeKeyTries = safeKeyTries + 1;
                        if (safeKeyTries == 3)
                        {
                            safeBurglarCheck = 1;
                            masterRoomLock = 1;
                            guestRoomLock = 1;
                            safeRoomLock = 1;
                            livingRoomCurtains = 0;
                            guestCurtain = 0;
                            masterCurtain = 0;
                            cout << "Maximum limit of tries reached." << endl;
                            cout << "(Burglar's protocol is initiated. All doors are locked. You cannot escape now.)" << endl;
                            Beep(500, 10000);
                            cout << "Enter Master key to disable burglar's Protocol: ";
                            string safeBurglarDisable;
                            safeBurglarDisableAgain:
                            cin >> safeBurglarDisable;
                            if (safeBurglarDisable == MasterKey)
                            {
                                correctBeep();
                                cout << "Burglar's Protocol is disabled." << endl;
                                safeBurglarCheck = 0;
                                goto safeRoomOption;
                            }
                            else
                            {
                                wrongBeep();
                                cout << "Enter Master key to disable burglar's Protocol: ";
                                goto safeBurglarDisableAgain;
                            }
                        }
                        goto safeRoomOption;
                    }
                    
                /////////////////////// Return to Master Room ///////////////////////
                case 2:
                    optionSelectYesBeep();
                    cout << "(the Safe is Locked and the light turn off.)" << endl;
                    cout << "(The door of safe room gets locked when you returned back to Master Room)" << endl;
                    goto masterOption;

                //////////////////////// Safe Room Invalid Select ////////////////////////
                default:
                    wrongBeep();
                    cout << "Invalid Option. Select Again: ";
                    goto safeRoomOptionSelectAgain;
                }
            }
            else
            {
                wrongBeep();
                cout << "Wrong Key. Input Again: ";
                safeRoomtries = safeRoomtries + 1;
                if (safeRoomtries == 3)
                {
                    MasterBurglarCheck = 1;
                    masterRoomLock = 1;
                    guestRoomLock = 1;
                    safeRoomLock = 1;
                    livingRoomCurtains = 0;
                    guestCurtain = 0;
                    masterCurtain = 0;
                    cout << "Maximum limit of tries reached." << endl;
                    cout << "(Burglar's protocol is initiated. All doors are locked. You cannot escape now.)" << endl;
                    Beep(500, 10000);
                    cout << "Enter Master key to disable burglar's Protocol: ";
                    string safeRoomBurglarDisable;
                    safeRoomBurglarDisableAgain:
                    cin >> safeRoomBurglarDisable;
                    if (safeRoomBurglarDisable == MasterKey)
                    {
                        correctBeep();
                        cout << "Burglar's Protocol is disabled." << endl;
                        MasterBurglarCheck = 0;
                        goto masterOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Enter Master key to disable burglar's Protocol: ";
                        goto safeRoomBurglarDisableAgain;
                    }
                }
                goto safeRoomKeyInputAgain;
            }

        ///////////////////////////// Master Burglar's Protocol //////////////////////
        case 7:
            optionSelectYesBeep();
            if (IfBurglar == 0)
            {
                cout << "Do you want me to enable Burglar's Protocol" << endl;
                MasterBurglarSureAgain:
                cin >> MasterBurglarSure;
                if (MasterBurglarSure == "Yes" || MasterBurglarSure == "YES" || MasterBurglarSure == "yes" || MasterBurglarSure == "y" || MasterBurglarSure == "Y")
                {
                    optionSelectYesBeep();
                    IfBurglar = 1;
                    cout << "Burglar's Protocol Initiated." << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        Beep(400, 250);
                        Beep (0, 100);
                    }
                    masterRoomLock = 1;
                    guestRoomLock = 1;
                    safeRoomLock = 1;
                    livingRoomCurtains = 0;
                    guestCurtain = 0;
                    masterCurtain = 0;
                    cout << "(Jarvis has called the Police and Police is comming)" << endl;
                    goto masterOption;
                }
                else if (MasterBurglarSure == "No" || MasterBurglarSure == "NO" || MasterBurglarSure == "no" || MasterBurglarSure == "n" || MasterBurglarSure == "N")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I dont understand you. Please Answer Again: ";
                    goto MasterBurglarSureAgain;
                }
            }
            else
            {
                cout << "Do you want me to Disable Burglar's Protocol" << endl;
                DisableMasterBurglarSureAgain:
                cin >> MasterBurglarSure;
                if (MasterBurglarSure == "Yes" || MasterBurglarSure == "YES" || MasterBurglarSure == "yes" || MasterBurglarSure == "y" || MasterBurglarSure == "Y")
                {
                    optionSelectYesBeep();
                    cout << "Burglar's Protocol Disabled." << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        Beep(130, 250);
                        Beep (0, 100);
                    }
                    goto masterOption;
                }
                else if (MasterBurglarSure == "No" || MasterBurglarSure == "NO" || MasterBurglarSure == "no" || MasterBurglarSure == "n" || MasterBurglarSure == "N")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto masterOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I dont understand you. Please Answer Again: ";
                    goto DisableMasterBurglarSureAgain;
                }
            }
            
        ///////////////////////////// Return to corridor /////////////////////////
        case 8:
            optionSelectYesBeep();
            cout << "Do you want me to turn of all the appliances?" << endl;
            masterLeaveAnswerAgain:
            cin >> masterLeaveAnswer;
            if (masterLeaveAnswer == "Yes" || masterLeaveAnswer == "YES" || masterLeaveAnswer == "yes" || masterLeaveAnswer == "Y" || masterLeaveAnswer == "y")
            {
                optionSelectYesBeep();
                switchMasterRoomLight = 0;
                masterLightIntensity = 7;
                switchMastertv = 0;
                switchMasterMusic = 0;
                masterCurtain = 0;
                masterRoomLock = 0;
                safeRoomLock = 1;
                cout << "(All appliances of the room are turned off)" << endl;
                cout << "(Curtains are also closed)" << endl;
                goto corridorOption;
            }
            else if (masterLeaveAnswer == "No" || masterLeaveAnswer == "NO" || masterLeaveAnswer == "no" || masterLeaveAnswer == "N" || masterLeaveAnswer == "n")
            {
                noBeep();
                cout << "Okay.." << endl;
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "I Dont Understand you. Enter Again: ";
                goto masterLeaveAnswerAgain;
            }
    
        //////////////////////////// Master Invalid Select ///////////////////////
        default:
            wrongBeep();
            cout << "Invalid Option. Select again: ";
            goto masterOptionSelectAgain;
        }

    ////////////////////////////// Guest Room //////////////////////////////////////
    case 2:
        if (guestRoomLock == 0)
        {
            optionSelectYesBeep();
            cout << endl;
            cout << "(The Door of guest room opens)" << endl;
            if (switchGuestRoomLight == 0)
            {
                cout << "(The Lights of the guest room turns on)" << endl;
                switchGuestRoomLight = 1;
            }
            else
            {
                cout << "(Light of the room is already on)" << endl;
            }
            
            ////////////////////////////// Guest Room Option /////////////////////
            guestOption:
            cout << endl;
            cout << "(You are in the Guest room)" << endl;
            guestCurtainCheck();
            GuestMusicCheck();
            guestTvCheck();
            guestLockCheck();
            cout << endl;
            cout << "   1) Lights" << endl;
            cout << "   2) TV" << endl;
            cout << "   3) Music" << endl;
            cout << "   4) Curtains" << endl;
            cout << "   5) Room Lock" << endl;
            cout << "   6) Return to corridor" << endl;
            cout << endl;

            ///////////////////////////// Guest Room option Select //////////////////////
            int guestOptionSelect;
            guestOptionSelectAgain:
            while (!(cin >> guestOptionSelect))
            {
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ///////////////////////////// Guest Room Switch /////////////////////////////
            switch (guestOptionSelect)
            {
            ///////////////////////////// Guest Lights ///////////////////////////
            case 1:
                optionSelectYesBeep();
                cout << "   1) Turn on the lights" << endl;
                cout << "   2) Turn off the lights" << endl;
                cout << "   3) Light Intensity" << endl;
                cout << "   4) Cancel" << endl;

                //////////////////// Guest Lights Option Select //////////////////////////
                int guestLightsOptionSelect;
                guestLightsOptionSelectAgain:
                while (!(cin >> guestLightsOptionSelect))
                {
                    wrongBeep();
                    cout << "Invaid Input. Enter Again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ///////////////////// Guest lights Switch /////////////////////////////
                switch (guestLightsOptionSelect)
                {
                /////////////////////// Turn on the lights ////////////////////////
                case 1:
                    if (switchGuestRoomLight == 1)
                    {
                        noBeep();
                        cout << "Lights are already on" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Lights are turned on" << endl;
                        switchGuestRoomLight = 1;
                        goto guestOption;
                    }

                //////////////////////// Turn off the lights ///////////////////////
                case 2:
                    if (switchGuestRoomLight == 0)
                    {
                        noBeep();
                        cout << "Lights are already off" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Lights are turned off" << endl;
                        switchGuestRoomLight = 0;
                        guestLightIntensity = 7;
                        goto guestOption;
                    }

                //////////////////////// Light Intensity ////////////////////////////
                case 3:
                    if (switchGuestRoomLight == 0)
                    {
                        noBeep();
                        cout << "Lights are off" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Light Intensity is at " << guestLightIntensity << endl;
                        cout << endl;
                        cout << "Enter new Intensity (from 1 to 7)" << endl;
                        guestLightIntensityAgain:
                        while (!(cin >> guestLightIntensity))
                        {
                            wrongBeep();
                            cout << "Invalid Input. Input Again: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (guestLightIntensity >= 1 && guestLightIntensity <= 7)
                        {
                            optionSelectYesBeep();
                            cout << "Light Intensity is set to " << guestLightIntensity << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "Intensity of light is from 1 to 7 only. Enter Again: ";
                            goto guestLightIntensityAgain;
                        }
                    }

                ////////////////////////// Cancel /////////////////////////////////
                case 4:
                    noBeep();
                    goto guestOption;

                ////////////////////////// Guest lights invalid option /////////////////
                default:
                    wrongBeep();
                    cout << "Invalid Option. Enter Again: ";
                    goto guestLightsOptionSelectAgain;
                }
            
            ///////////////////////////// Guest TV /////////////////////////////
            case 2:
                optionSelectYesBeep();
                cout << endl;
                cout << "   1) Turn on TV" << endl;
                cout << "   2) Turn off TV" << endl;
                cout << "   3) Change channel to" << endl;
                cout << "   4) Change Volume" << endl;
                cout << "   5) Cancel" << endl;
                cout << endl;

                ////////////////////////// Guest TV Option Select ////////////////////////
                int guestTvOptionSelect;
                guestTvOptionSelectAgain:
                while(!(cin >> guestTvOptionSelect))
                {
                    wrongBeep();
                    cout << "Invalid Input. Enter Again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                ///////////////////////// Guest Tv Switch ///////////////////////////
                switch (guestTvOptionSelect)
                {
                /////////////////////// Turn on tv ////////////////////////
                case 1:
                    if (switchGuestMusic == 1)
                    {
                        if (switchGuestTv == 1)
                        {
                            noBeep();
                            cout << "TV is already on" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 1;
                            cout << "TV is turned on" << endl;
                            cout << "(TV turns on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
                            if (guestMusicVolume != 0)
                            {
                                guestMusicVolume = 0;
                                cout << "(Music is muted)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestTv == 1)
                        {
                            noBeep();
                            cout << "TV is already on" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 1;
                            cout << "TV is turned on" << endl;
                            cout << "(TV turns on and current channel is " << guestTvChannel << " and volume is " << guestTvVolume << ")" << endl;
                            goto guestOption;
                        }
                    }

                /////////////////////// Turn off Tv ///////////////////////
                case 2:
                    if (switchGuestMusic == 1)
                    {
                        if (switchGuestTv == 0)
                        {
                            noBeep();
                            cout << "TV is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 0;
                            guestTvVolume = 67;
                            cout << "TV is turned off" << endl;
                            cout << "(TV turns off)" << endl;
                            if (guestMusicVolume == 0)
                            {
                                guestMusicVolume = 67;
                                cout << "(music is unmuted and volume is set to 67)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestTv == 0)
                        {
                            noBeep();
                            cout << "TV is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestTv = 0;
                            guestTvVolume = 67;
                            cout << "TV is turned off" << endl;
                            cout << "(TV turns off)" << endl;
                            goto guestOption;
                        }
                    }

                //////////////////////// Change Channel to //////////////////
                case 3:
                    if (switchGuestTv == 0)
                    {
                        noBeep();
                        cout << "Tv is off right now" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Current channel is " << guestTvChannel << endl;
                        cout << "Which channel you want me to tune into? (1 to 100)" << endl;
                        guestTvChannelAgain:
                        cin >> guestTvChannel;
                        if (guestTvChannel >= 1 && guestTvChannel <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "The Channel is changed to " << guestTvChannel << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "Only 100 channels are available (i.e. 1 to 100). Enter Again: ";
                            goto guestTvChannelAgain;
                        }
                        
                    }
                //////////////////////// Change Volume ////////////////////
                case 4:
                    if (switchGuestTv == 0)
                    {
                        noBeep();
                        cout << "Tv is off right now" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        optionSelectYesBeep();
                        cout << "Current volume is " << guestTvVolume << endl;
                        cout << "Enter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                        guestTvVolumeAgain:
                        cin >> guestTvVolume;
                        if (guestTvVolume >= 0 && guestTvVolume <= 100)
                        {
                            optionSelectYesBeep();
                            cout << "The volume is now " << guestTvVolume << endl;
                            goto guestOption;
                        }
                        else
                        {
                            wrongBeep();
                            cout << "Invalid Volume. Enter Again: ";
                            goto guestTvVolumeAgain;
                        }
                    }

                //////////////////////// Cancel //////////////////////////
                case 5:
                    noBeep();
                    goto guestOption;

                //////////////////////// Tv invalid option ////////////////
                default:
                    wrongBeep();
                    cout << "Invalid Option Enter Again: ";
                    goto guestTvOptionSelectAgain;
                }

            ///////////////////////////// Guest Music ///////////////////////////
            case 3:
                optionSelectYesBeep();
                //////////////////////// Guest Music Options /////////////////////////
                cout << "   1) Turn Music On" << endl;
                cout << "   2) Turn Music Off" << endl;
                cout << "   3) Music Volume" << endl;
                cout << "   4) Cancel" << endl;

                /////////////////////// Guest Music Input ////////////////////////////
                int guestMusicOption;
                guestMusicOptionAgain:
                while (!(cin >> guestMusicOption))
                {
                    wrongBeep();
                    cout << "Invalid Input. Select again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                //////////////////////// Guest Music Switch ////////////////////////
                switch (guestMusicOption)
                {
                //////////////////////// Turn Music on ////////////////////////
                case 1:
                    if (switchGuestTv == 1)
                    {
                        if (switchGuestMusic == 1)
                        {
                            noBeep();
                            cout << "Music is already playing" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 1;
                            cout << "Music is turned on. And Music Volume is " << guestMusicVolume << endl;
                            if (guestTvVolume != 0)
                            {
                                guestTvVolume = 0;
                                cout << "(Tv is muted)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestMusic == 1)
                        {
                            noBeep();
                            cout << "Music is already playing" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 1;
                            cout << "Music is turned on. And Music Volume is " << guestMusicVolume << endl;
                            goto guestOption;
                        }
                    }
                    

                //////////////////////// Turn Music Off //////////////////////
                case 2:
                    if (switchGuestTv == 1)
                    {
                        if (switchGuestMusic == 0)
                        {
                            noBeep();
                            cout << "Music is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 0;
                            guestMusicVolume = 67;
                            cout << "Music is turned off" << endl;
                            if (guestTvVolume == 0)
                            {
                                guestTvVolume = 67;
                                cout << "(Tv is unmuted and volume is set to 67)" << endl;
                            }
                            goto guestOption;
                        }
                    }
                    else
                    {
                        if (switchGuestMusic == 0)
                        {
                            noBeep();
                            cout << "Music is already off" << endl;
                            goto guestOption;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            switchGuestMusic = 0;
                            guestMusicVolume = 67;
                            cout << "Music is turned off" << endl;
                            goto guestOption;
                        }
                    }

                //////////////////////// Music Volume //////////////////////
                case 3:
                    if (switchGuestMusic == 1)
                    {
                        optionSelectYesBeep();
                        cout << endl;
                        cout << "Volume of Music is currently at " << guestMusicVolume << endl;
                        cout << "Enter new Volume (from 1 to 100)" << endl;
                        guestMusicVolumeAgain:
                        while (!(cin >> guestMusicVolume))
                        {
                            wrongBeep();
                            cout << "Invalid Input. Enter Again: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        if (!(guestMusicVolume >= 1) || !(guestMusicVolume <= 100))
                        {
                            wrongBeep();
                            cout << "Wrong Volume Level. Volume can be any level between 1 to 100 only. Enter again: ";
                            goto guestMusicVolumeAgain;
                        }
                        else
                        {
                            optionSelectYesBeep();
                            cout << "Volume of music is set to " << guestMusicVolume << endl;
                            goto guestOption;
                        }
                    }
                    else
                    {
                        noBeep();
                        cout << "Music is currently off" << endl;
                        goto guestOption;
                    }

                //////////////////////// Cancel ////////////////////////////
                case 4:
                    noBeep();
                    goto guestOption;
                
                /////////////////////// Invalid Music select ///////////////////////
                default:
                    wrongBeep();
                    cout << "Invalid Option. Select Again: ";
                    goto guestMusicOptionAgain;
                }

            //////////////////////////// Guest Curtains //////////////////////////
            case 4:
                optionSelectYesBeep();
                cout << endl;
                if (guestCurtain == 0)
                {
                    cout << "Do you want me to open curtains?" << endl;
                    string guestCurtainAnswer;
                    guestCurtainAnswerAgain:
                    cin >> guestCurtainAnswer;
                    if (guestCurtainAnswer == "Yes" || guestCurtainAnswer == "YES" || guestCurtainAnswer == "yes" || guestCurtainAnswer == "Y" || guestCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "Okay..!" << endl;
                        guestCurtain = 1;
                        cout << "(Curtains Opens)" << endl;
                        goto guestOption;
                    }
                    else if (guestCurtainAnswer == "No" || guestCurtainAnswer == "NO" || guestCurtainAnswer == "no" || guestCurtainAnswer == "N" || guestCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "Okay..!" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "I Dont Understand you. Please answer again: ";
                        goto guestCurtainAnswerAgain;
                    }
                }
                else
                {
                    cout << "Do you want me to close the curtains?" << endl;
                    string guestCurtainAnswer;
                    guestCurtainOpenAnswerAgain:
                    cin >> guestCurtainAnswer;
                    if (guestCurtainAnswer == "Yes" || guestCurtainAnswer == "YES" || guestCurtainAnswer == "yes" || guestCurtainAnswer == "Y" || guestCurtainAnswer == "y")
                    {
                        optionSelectYesBeep();
                        cout << "Okay..!" << endl;
                        guestCurtain = 0;
                        cout << "(Curtains Close)" << endl;
                        goto guestOption;
                    }
                    else if (guestCurtainAnswer == "No" || guestCurtainAnswer == "NO" || guestCurtainAnswer == "no" || guestCurtainAnswer == "N" || guestCurtainAnswer == "n")
                    {
                        noBeep();
                        cout << "Okay..!" << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "I Dont Understand you. Please answer again: ";
                        goto guestCurtainOpenAnswerAgain;
                    }
                }

            //////////////////////////// Guest Room lock /////////////////////////
            case 5:
                optionSelectYesBeep();
                if(guestRoomLock == 0)
                {
                    cout << "Do You want me to Lock the room door?" << endl;
                    string guestLockAnswer;
                    guestLockAnswerAgain:
                    cin >> guestLockAnswer;
                    if (guestLockAnswer == "Yes" || guestLockAnswer == "YES" || guestLockAnswer == "yes" || guestLockAnswer == "Y" || guestLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        guestRoomLock = 1;
                        cout << "Room door is locked now" << endl;
                        goto guestOption;
                    }
                    else if (guestLockAnswer == "No" || guestLockAnswer == "NO" || guestLockAnswer == "no" || guestLockAnswer == "N" || guestLockAnswer == "n")
                    {
                        noBeep();
                        cout << "Okay.." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "I Dont Understand you.. Please Answer Again: ";
                        goto guestLockAnswerAgain;
                    }
                }
                else
                {
                    cout << "Do You want me to unlock the room door?" << endl;
                    string guestLockAnswer;
                    guestUnlockAnswerAgain:
                    cin >> guestLockAnswer;
                    if (guestLockAnswer == "Yes" || guestLockAnswer == "YES" || guestLockAnswer == "yes" || guestLockAnswer == "Y" || guestLockAnswer == "y")
                    {
                        optionSelectYesBeep();
                        guestRoomLock = 0;
                        cout << "Room door is unlocked now" << endl;
                        goto guestOption;
                    }
                    else if (guestLockAnswer == "No" || guestLockAnswer == "NO" || guestLockAnswer == "no" || guestLockAnswer == "N" || guestLockAnswer == "n")
                    {
                        noBeep();
                        cout << "Okay.." << endl;
                        goto guestOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "I Dont Understand you.. Please Answer Again: ";
                        goto guestUnlockAnswerAgain;
                    }
                }
                
                

            //////////////////////////// Guest Return to corridor ////////////////////////
            case 6:
                optionSelectYesBeep();
                cout << "Do you want me to turn off all the appliances?" << endl;
                guestLeaveAnswerAgain:
                cin >> guestLeaveAnswer;
                if (guestLeaveAnswer == "Yes" || guestLeaveAnswer == "YES" || guestLeaveAnswer == "yes" || guestLeaveAnswer == "Y" || guestLeaveAnswer == "y")
                {
                    optionSelectYesBeep();
                    switchGuestRoomLight = 0;
                    guestLightIntensity = 7;
                    switchGuestTv = 0;
                    guestTvVolume = 67;
                    switchGuestMusic = 0;
                    guestMusicVolume = 67;
                    guestCurtain = 0;
                    guestRoomLock = 0;
                    cout << "(All appliances of the room are turned off)" << endl;
                    cout << "(Curtains are also closed)" << endl;
                    goto corridorOption;
                }
                else if (guestLeaveAnswer == "No" || guestLeaveAnswer == "NO" || guestLeaveAnswer == "no" || guestLeaveAnswer == "N" || guestLeaveAnswer == "n")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto corridorOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you. Enter Again: ";
                    goto guestLeaveAnswerAgain;
                }
            
            //////////////////////////// Guest Invalid Option ///////////////////////////
            default:
                wrongBeep();
                cout << "Invalid Option. Enter Again: ";
                goto guestOptionSelectAgain;
            }
        }
        else
        {
            optionSelectYesBeep();
            cout << "The guest room is locked. Knock the Door and ask to open the door from the person in the guest room.\n\
(The guest room door can be unlocked using master key only, in case of emergency. If you have master key and want to open the door\n\
then say Yes and if not then say No.)" << endl;
            string guestIntruderAnswer;
            guestIntruderAnswerAgain:
            cin >> guestIntruderAnswer;
            if (guestIntruderAnswer == "Yes" || guestIntruderAnswer == "YES" || guestIntruderAnswer == "yes" || guestIntruderAnswer == "Y" || guestIntruderAnswer == "y")
            {
                optionSelectYesBeep();
                cout << "Enter key: ";
                cin >> guestIntruderInputKey;
                if (guestIntruderInputKey == MasterKey)
                {
                    correctBeep();
                    guestRoomLock = 0;
                    goto guestOption;
                }
                else
                {
                    wrongBeep();
                    cout << "Wrong Key. Access denied." << endl;
                    goto corridorOption;
                }
            }
            else if (guestIntruderAnswer == "No" || guestIntruderAnswer == "NO" || guestIntruderAnswer == "no" || guestIntruderAnswer == "N" || guestIntruderAnswer == "n")
            {
                noBeep();
                cout << "Okay" << endl;
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "I dont Understand you. Please Answer Again: ";
                goto guestIntruderAnswerAgain;
            }
        }

    //////////////////////////// Living Room //////////////////////////
    case 3:
        optionSelectYesBeep();
        cout << endl;
        cout << "(The Door of living room opens)" << endl;
        if (switchLivingRoomLight == 0)
        {
            cout << "(The Lights of the living room turns on)" << endl;
            switchLivingRoomLight = 1;
        }
        else
        {
            cout << "(Light is already on)" << endl;
        }
        
        ////////////////////////////// Living Room Option /////////////////////
        livingOption:
        cout << endl;
        cout << "(You are in the Living room)" << endl;
        livingCurtainCheck();
        if (switchLivingRoomTv == 0)
        {
            musicCheck();
        }
        livingTvCheck();
        cout << endl;
        cout << "   1) Lights" << endl;
        cout << "   2) Cenematic TV" << endl;
        cout << "   3) Music" << endl;
        cout << "   4) Curtains" << endl;
        cout << "   5) Return to corridor" << endl;
        cout << endl;

        ///////////////////////////// Living Room option Select //////////////////////
        int livingOptionSelect;
        livingOptionSelectAgain:
        while (!(cin >> livingOptionSelect))
        {
            wrongBeep();
            cout << "Invalid Input. Enter Again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ////////////////////////////// Living Room Switch ///////////////////////////////
        switch (livingOptionSelect)
        {
        //////////////////////////// Living Lights /////////////////////////////
        case 1:
            optionSelectYesBeep();
            cout << "   1) Turn on the lights" << endl;
            cout << "   2) Turn off the lights" << endl;
            cout << "   3) Light Intensity" << endl;
            cout << "   4) Cancel" << endl;

            //////////////////// Living Lights Option Select //////////////////////////
            int livingLightsOptionSelect;
            livingLightsOptionSelectAgain:
            while (!(cin >> livingLightsOptionSelect))
            {
                wrongBeep();
                cout << "Invaid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            ////////////////////// Living Lights Case /////////////////////////////////
            switch (livingLightsOptionSelect)
            {
            ///////////////////////// Turn on light ///////////////////////
            case 1:
                if (switchLivingRoomLight == 1)
                {
                    noBeep();
                    cout << "Lights are already on" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Lights are turned on" << endl;
                    switchLivingRoomLight = 1;
                    goto livingOption;
                }
                
            ///////////////////////// Turn off the light //////////////////
            case 2:
                if (switchLivingRoomLight == 0)
                {
                    noBeep();
                    cout << "Lights are already off" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Lights are turned off" << endl;
                    switchLivingRoomLight = 0;
                    livingLightIntensity = 7;
                    goto livingOption;
                }

            ///////////////////////// Light Intensity /////////////////////
            case 3:
                if (switchLivingRoomLight == 0)
                {
                    noBeep();
                    cout << "Lights are off" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Light Intensity is at " << livingLightIntensity << endl;
                    cout << endl;
                    cout << "Enter new Intensity (from 1 to 7)" << endl;
                    int newLivingLightIntensity;
                    newLivingLightIntensityAgain:
                    while (!(cin >> newLivingLightIntensity))
                    {
                        wrongBeep();
                        cout << "Invalid Input. Input Again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (newLivingLightIntensity >= 1 && newLivingLightIntensity <= 7)
                    {
                        optionSelectYesBeep();
                        livingLightIntensity = newLivingLightIntensity;
                        cout << "Light Intensity is set to " << newLivingLightIntensity << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Intensity of light is from 1 to 7 only. Enter Again: ";
                        goto newLivingLightIntensityAgain;
                    }
                }
                
            ///////////////////////// Cancel ////////////////////////////
            case 4:
                noBeep();
                cout << "Okay.." << endl;
                goto livingOption;

            ////////////////////////// Invalid Input //////////////////////            
            default:
                wrongBeep();
                cout << "Invalid Input. Enter Again: " << endl;
                goto livingLightsOptionSelectAgain;
            }


        //////////////////////////// Living Tv /////////////////////////////////
        case 2:
            optionSelectYesBeep();
            ////////////////////////// Living TV Options ///////////////////
            livingTvOption:
            cout << endl;
            cout << "   1) Turn on TV" << endl;
            cout << "   2) Turn off TV" << endl;
            cout << "   3) Change channel to" << endl;
            cout << "   4) Change Volume" << endl;
            cout << "   5) Cancel" << endl;
            cout << endl;

            ////////////////////////// Living TV Option Select ////////////////////////
            int livingTvOptionSelect;
            livingTvOptionAgain:
            while(!(cin >> livingTvOptionSelect))
            {
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            /////////////////////////// Living Tv Switch ///////////////////////////////
            switch (livingTvOptionSelect)
            {
            /////////////////////////// Turn on Tv ///////////////////////
            case 1:
                if (switchLivingRoomTv == 1)
                {
                    noBeep();
                    cout << "TV is already on" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchLivingRoomTv = 1;
                    cout << "TV is turned on" << endl;
                    cout << "(TV turns on and current channel is " << livingTvChannel << " and volume is " << livingTvVolume << ")" << endl;
                    goto livingOption;
                }
                
                

            /////////////////////////// Turn off Tv //////////////////////
            case 2:
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "TV is already off" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    switchLivingRoomTv = 0;
                    cout << "TV is turned off" << endl;
                    cout << "(TV turns off)" << endl;
                    goto livingOption;
                }

            /////////////////////////// Change Channel to ////////////////
            case 3:
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "Tv is off right now" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Current channel is " << livingTvChannel << endl;
                    cout << "Which channel you want me to tune into? (1 to 100)" << endl;
                    LivingTvChannelAgain:
                    cin >> livingTvChannel;
                    if (livingTvChannel >= 1 && livingTvChannel <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "The Channel is changed to " << livingTvChannel << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Only 100 channels are available (i.e. 1 to 100). Enter Again: ";
                        goto LivingTvChannelAgain;
                    }
                    
                }
                
            /////////////////////////// Change Volume ////////////////////
            case 4:
                if (switchLivingRoomTv == 0)
                {
                    noBeep();
                    cout << "Tv is off right now" << endl;
                    goto livingOption;
                }
                else
                {
                    optionSelectYesBeep();
                    cout << "Current volume is " << livingTvVolume << endl;
                    cout << "Enter new Volume: (Min Volume = 1, Max Volume is 100, To Mute Enter 0)" << endl;
                    LivingTvVolumeAgain:
                    cin >> livingTvVolume;
                    if (livingTvVolume >= 0 && livingTvVolume <= 100)
                    {
                        optionSelectYesBeep();
                        cout << "The volume is now " << livingTvVolume << endl;
                        goto livingOption;
                    }
                    else
                    {
                        wrongBeep();
                        cout << "Invalid Volume. Enter Again: ";
                        goto LivingTvVolumeAgain;
                    }
                    
                }

            /////////////////////////// Cancel ////////////////////////////
            case 5:
                noBeep();
                goto livingOption;

            /////////////////////////// Living Tv invalid option /////////////////
            default:
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                goto livingTvOptionAgain;
            }

        ///////////////////////////// Music //////////////////////////////////
        case 3:
            optionSelectYesBeep();
        //////////////////////// Music Options /////////////////////////
        cout << "   1) Turn Music On" << endl;
        cout << "   2) Turn Music Off" << endl;
        cout << "   3) Music Volume" << endl;
        cout << "   4) Cancel" << endl;
        /////////////////////// Music Input ////////////////////////////
        int musicOption;
        livingmusicOptionAgain:
        while (!(cin >> musicOption))
        {
            wrongBeep();
            cout << "Invalid Input. Select again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        /////////////////////// Music Switch //////////////////////////
        switch (musicOption)
        {
        /////////////////////// Music on //////////////////////////////
        case 1:
            if (switchmusic == 1)
            {
                noBeep();
                cout << "Music is already playing" << endl;
                goto livingOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 1;
                cout << "Music is turned on. And Music Volume is " << musicVolume << endl;
                goto livingOption;
            }
            
            

        /////////////////////// Music off /////////////////////////////
        case 2:
            if (switchmusic == 0)
            {
                noBeep();
                cout << "Music is already off" << endl;
                goto livingOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 0;
                musicVolume = 67;
                cout << "Music is turned off" << endl;
                goto livingOption;
            }
            
        //////////////////////// Music Volume /////////////////////////
        case 3:
            if (switchmusic == 1)
            {
                optionSelectYesBeep();
                cout << endl;
                cout << "Volume of Music is currently at " << musicVolume << endl;
                cout << "Enter new Volume (from 1 to 100)" << endl;
                int newVolumeMusic;
                livingnewVolumeMusicAgain:
                while (!(cin >> newVolumeMusic))
                {
                    wrongBeep();
                    cout << "Invalid Input. Enter Again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (!(newVolumeMusic >= 1) || !(newVolumeMusic <= 100))
                {
                    wrongBeep();
                    cout << "Wrong Volume Level. Volume can be any level between 1 to 100 only. Enter again: ";
                    goto livingnewVolumeMusicAgain;
                }
                else
                {
                    optionSelectYesBeep();
                    musicVolume = newVolumeMusic;
                    cout << "Volume of music is set to " << newVolumeMusic << endl;
                    goto livingOption;
                }
            }
            else
            {
                noBeep();
                cout << "Music is currently off" << endl;
                goto livingOption;
            }
            
        ///////////////////////// Cancel //////////////////////////////
        case 4:
            noBeep();
            goto livingOption;
        
        //////////////////////// Music Invalid select /////////////////////////
        default:
            wrongBeep();
            cout << "Invalid Input. Select again: ";
            goto livingmusicOptionAgain;
        }

        ///////////////////////////// Living Curtains //////////////////////////
        case 4:
            optionSelectYesBeep();
            cout << endl;
            if (livingRoomCurtains == 0)
            {
                cout << "Do you want me to open curtains?" << endl;
                livingCurtainAnswerAgain:
                cin >> livingCurtainAnswer;
                if (livingCurtainAnswer == "Yes" || livingCurtainAnswer == "YES" || livingCurtainAnswer == "yes" || livingCurtainAnswer == "Y" || livingCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "Okay..!" << endl;
                    livingRoomCurtains = 1;
                    cout << "(Curtains Opens)" << endl;
                    goto livingOption;
                }
                else if (livingCurtainAnswer == "No" || livingCurtainAnswer == "NO" || livingCurtainAnswer == "no" || livingCurtainAnswer == "N" || livingCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "Okay..!" << endl;
                    goto livingOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you. Please answer again: ";
                    goto livingCurtainAnswerAgain;
                }
            }
            else
            {
                cout << "Do you want me to close the curtains?" << endl;
                livingOpenCurtainAnswerAgain:
                cin >> livingCurtainAnswer;
                if (livingCurtainAnswer == "Yes" || livingCurtainAnswer == "YES" || livingCurtainAnswer == "yes" || livingCurtainAnswer == "Y" || livingCurtainAnswer == "y")
                {
                    optionSelectYesBeep();
                    cout << "Okay..!" << endl;
                    livingRoomCurtains = 0;
                    cout << "(Curtains Close)" << endl;
                    goto livingOption;
                }
                else if (livingCurtainAnswer == "No" || livingCurtainAnswer == "NO" || livingCurtainAnswer == "no" || livingCurtainAnswer == "N" || livingCurtainAnswer == "n")
                {
                    noBeep();
                    cout << "Okay..!" << endl;
                    goto livingOption;
                }
                else
                {
                    wrongBeep();
                    cout << "I Dont Understand you. Please answer again: ";
                    goto livingOpenCurtainAnswerAgain;
                }
            }

        //////////////////////////// Return to corridor from Living /////////////////
        case 5:
            optionSelectYesBeep();
            cout << "Do you want me to turn off all the appliances?" << endl;
            livingLeaveAnswerAgain:
            cin >> livingLeaveAnswer;
            if (livingLeaveAnswer == "Yes" || livingLeaveAnswer == "YES" || livingLeaveAnswer == "yes" || livingLeaveAnswer == "Y" || livingLeaveAnswer == "y")
            {
                optionSelectYesBeep();
                cout << endl;
                cout << "(All appliances of living room are turned off)" << endl;
                if(livingRoomCurtains == 1)
                {
                    livingRoomCurtains = 0;
                    cout << "(Curtains are closed)" << endl;
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
                cout << "Okay.." << endl;
                goto corridorOption;
            }
            else
            {
                wrongBeep();
                cout << "I dont Understand you.. Please answer again: ";
                goto livingLeaveAnswerAgain;
            }
            
            
        //////////////////////////// Living Invalid Input //////////////////////////        
        default:
            wrongBeep();
            cout << "Invalid Input. Select Again: ";
            goto livingOptionSelectAgain;
        }

    /////////////////////// Kitchen ///////////////////////////
    case 4:
        optionSelectYesBeep();
        ////////////////////////// Kitchen Options ////////////////////////
        kitchenOption:
        cout << endl;
        cout << "(You are in the kitchen)" << endl;
        musicCheck();
        cout << endl;
        cout << "   1) Make Smoothie" << endl;
        cout << "   2) Make Coffee" << endl;
        cout << "   3) Make Protein Shake" << endl;
        cout << "   4) Search Recipie on Internet" << endl;
        cout << "   5) Return back to Corridor" << endl;
        cout << endl;

        ///////////////////////// Kitchen option Select ////////////////////
        int kitchenOptionSelect;
        kitchenOptionSelectAgain:
        while (!(cin >> kitchenOptionSelect))
        {
            wrongBeep();
            cout << "Wrong Input. Input Again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        ///////////////////////////// Kitchen Switch /////////////////////////////
        switch (kitchenOptionSelect)
        {
        //////////////////////// Make Smoothie ////////////////////////////
        case 1:
            if (smoothieIngredients == 0)
            {
                noBeep();
                cout << "The Ingredients used to make Smoothie are end. Refill first plz." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "Making Smoothie";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "Smoothie is Ready" << endl;
                smoothieIngredients = smoothieIngredients - 1;
                goto kitchenOption;
            }
            

        ///////////////////////// Make Coffee ///////////////////////////////
        case 2:
            if (coffeeIngredients == 0)
            {
                noBeep();
                cout << "The Ingredients used to make Coffee are end. Refill first plz." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "Making Coffee";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "Coffee is Ready" << endl;
                coffeeIngredients = coffeeIngredients - 1;
                goto kitchenOption;
            }
            

        /////////////////////////// Make Protein Shake //////////////////////////
        case 3:
            if (proteinIngredients == 0)
            {
                noBeep();
                cout << "The Ingredients used to make Protein Shake are end. Refill first plz." << endl;
                goto kitchenOption;
            }
            else
            {
                optionSelectYesBeep();
                cout << "Making Protein Shake";
                for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
                cout << endl;
                optionSelectYesBeep();
                cout << "Protein Shake is Ready" << endl;
                proteinIngredients = proteinIngredients - 1;
                goto kitchenOption;
            }

        /////////////////////////// Search Recipie on Internet ////////////////////////
        case 4:
            optionSelectYesBeep();
            cout << "Which Recipie you want to search? (spaces in the name must be replaced with underscore)" << endl;
            cin >> recipieAnswer;
            optionSelectYesBeep();
            cout << "Searching Recipie of " << recipieAnswer << " on the Internet";
            for (int i = 0; i < 3; i++)
                {
                    Beep(0, 1000);
                    cout << ".";
                }
            optionSelectYesBeep();
            cout << endl;
            cout << "Showing search results on the screen next to stove." << endl;
            goto kitchenOption;

        ///////////////////////////// Return back to corridor /////////////////////////
        case 5:
            optionSelectYesBeep();
            goto corridorOption;
        
        ////////////////////////////// Kitchen Invalid ///////////////////////////////
        default:
            wrongBeep();
            cout << "Invalid Input. Input Again: ";
            goto kitchenOptionSelectAgain;
        }

    //////////////////////// Lights /////////////////////////////////
    case 5:
        //////////////////////// Lights option ////////////////////////
        optionSelectYesBeep();
        cout << "   1) Turn on the light (Corridor and Kitchen)" << endl;
        cout << "   2) Turn off the light (Corridor and Kitchen)" << endl;
        cout << "   3) Turn off all the lights" << endl;
        cout << "   4) Cancel" << endl;

        //////////////////////// Lights option Select ////////////////////////
        int lightsOptionSelect;
        lightsOptionSelectAgain:
        while (!(cin >> lightsOptionSelect))
        {
            wrongBeep();
            cout << "Invalid Input. Input Again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        //////////////////////// Lights switch //////////////////////////////
        switch (lightsOptionSelect)
        {
        //////////////////////// turn on the light //////////////////////////
        case 1:
            if (switchcorridorlight == 1)
            {
                noBeep();
                cout << "Lights of corridor and Kitchen are already on." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchcorridorlight = 1;
                cout << "Lights of corridor and kitchen are turned on." << endl;
                goto corridorOption;
            }

        //////////////////////// turn off the lights ////////////////////////
        case 2:
            if (switchcorridorlight == 0)
            {
                noBeep();
                cout << "Lights are already off." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchcorridorlight = 0;
                cout << "Lights of the corridor and kitchen are turned off." << endl;
                goto corridorOption;
            }

        //////////////////////// turn off all the lights /////////////////////////
        case 3:
            if (switchcorridorlight == 0)
            {
                noBeep();
                cout << "Lights are already off." << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchcorridorlight = 0;
                switchMasterRoomLight = 0;
                switchGuestRoomLight = 0;
                switchLivingRoomLight = 0;
                cout << "All the lights are turned off." << endl;
                goto corridorOption;
            }
        
        //////////////////////////// Cancel ////////////////////////////////
        case 4:
            noBeep();
            goto corridorOption;
        
        //////////////////////////// Invalid light input /////////////////////
        default:
            wrongBeep();
            cout << "Invalid Input. Enter Again: ";
            goto lightsOptionSelectAgain;
        }

    //////////////////////// Music //////////////////////////////////
    case 6:
        optionSelectYesBeep();
        //////////////////////// Music Options /////////////////////////
        cout << "   1) Turn Music On" << endl;
        cout << "   2) Turn Music Off" << endl;
        cout << "   3) Music Volume" << endl;
        cout << "   4) Cancel" << endl;
        /////////////////////// Music Input ////////////////////////////
        int musicOption;
        musicOptionAgain:
        while (!(cin >> musicOption))
        {
            wrongBeep();
            cout << "Invalid Input. Select again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        /////////////////////// Music Switch //////////////////////////
        switch (musicOption)
        {
        /////////////////////// Music on //////////////////////////////
        case 1:
            if (switchmusic == 1)
            {
                noBeep();
                cout << "Music is already playing" << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 1;
                cout << "Music is turned on. And Music Volume is " << musicVolume << endl;
                goto corridorOption;
            }
            
            

        /////////////////////// Music off /////////////////////////////
        case 2:
            if (switchmusic == 0)
            {
                noBeep();
                cout << "Music is already off" << endl;
                goto corridorOption;
            }
            else
            {
                optionSelectYesBeep();
                switchmusic = 0;
                musicVolume = 67;
                cout << "Music is turned off" << endl;
                goto corridorOption;
            }
            
        //////////////////////// Music Volume /////////////////////////
        case 3:
            if (switchmusic == 1)
            {
                optionSelectYesBeep();
                cout << endl;
                cout << "Volume of Music is currently at " << musicVolume << endl;
                cout << "Enter new Volume (from 1 to 100)" << endl;
                int newVolumeMusic;
                newVolumeMusicAgain:
                while (!(cin >> newVolumeMusic))
                {
                    wrongBeep();
                    cout << "Invalid Input. Enter Again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (!(newVolumeMusic >= 1) || !(newVolumeMusic <= 100))
                {
                    wrongBeep();
                    cout << "Wrong Volume Level. Volume can be any level between 1 to 100 only. Enter again: ";
                    goto newVolumeMusicAgain;
                }
                else
                {
                    optionSelectYesBeep();
                    musicVolume = newVolumeMusic;
                    cout << "Volume of music is set to " << newVolumeMusic << endl;
                    goto corridorOption;
                }
            }
            else
            {
                noBeep();
                cout << "Music is currently off" << endl;
                goto corridorOption;
            }
            
        ///////////////////////// Cancel //////////////////////////////
        case 4:
            noBeep();
            goto corridorOption;
        
        //////////////////////// Music Invalid select /////////////////////////
        default:
            wrongBeep();
            cout << "Invalid Input. Select again: ";
            goto musicOptionAgain;
        }

    //////////////////// Go Out of the House ////////////////////////
    case 7:
        optionSelectYesBeep();
        /////////////////////////// both in house ///////////////////////////
        if (Master == 1 && Guest == 1)
        {
            cout << "Who is going?" << endl;
            cout << "   1) Both" << endl;
            cout << "   2) Master" << endl;
            cout << "   3) Guest" << endl;
            cout << "   4) No one" << endl;
            int goOutAnswer;
            goOutAnswerAgain:
            while (!(cin >> goOutAnswer))
            {
                wrongBeep();
                cout << "Invalid Input. Enter Again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            switch (goOutAnswer)
            {
            //////////////////////////// Both going outside //////////////////////////
            case 1:
                optionSelectYesBeep();
                Master = 0;
                Guest = 0;
                cout << "(The Door gets locked when both of you gets out of the house)" << endl;
                bothAskGettingBackInAgain:
                cout << "Getting back in?" << endl;
                bothGetBackInAgain:
                cin >> getBackIn;
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    cout << "Who is getting in?" << endl;
                    cout << "   1) Both" << endl;
                    cout << "   2) Master" << endl;
                    cout << "   3) Guest" << endl;
                    cout << "   4) No one" << endl;
                    int bothOutAnswer;
                    bothOutAnswerAgain:
                    while (!(cin >> bothOutAnswer))
                    {
                        wrongBeep();
                        cout << "Invalid Input. Enter Again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    switch (bothOutAnswer)
                    {
                    //////////////// both getting in //////////////////////
                    case 1:
                        optionSelectYesBeep();
                        Master = 1;
                        Guest = 1;
                        cout << "(the door opens automatically without entring key)" << endl;
                        cout << "(the door gets locked when both of you gets back in the house)" << endl;
                        goto corridorOption;
                    
                    //////////////// Master getting in ////////////////////
                    case 2:
                        optionSelectYesBeep();
                        Master = 1;
                        cout << "(the door opens automatically without entring key)" << endl;
                        cout << "(the door gets locked when you get back in the house)" << endl;
                        goto corridorOption;

                    //////////////// Guest getting in /////////////////////
                    case 3:
                        optionSelectYesBeep();
                        Guest = 1;
                        cout << "(the door opens automatically without entring key)" << endl;
                        cout << "(the door gets locked when you get back in the house)" << endl;
                        goto corridorOption;
                    
                    //////////////// No one getting in /////////////////////
                    case 4:
                        noBeep();
                        cout << "Okay.." << endl;
                        goto bothAskGettingBackInAgain;

                    default:
                        wrongBeep();
                        cout << "Invalid input. Enter Again: ";
                        goto bothOutAnswerAgain;
                    }
                    
                }

                /////////////////////////// no Getting back in //////////////////////////////////
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "Okay.." << endl;
                    goto bothAskGettingBackInAgain;
                }
                /////////////////////////////// wrong getting back in /////////////////////////////
                else
                {
                    wrongBeep();
                    cout << "I dont Understand you..! Answer Again: ";
                    goto bothGetBackInAgain;
                }
                
            //////////////////////////// Master going out ////////////////////////////////
            case 2:
                optionSelectYesBeep();
                Master = 0;
                cout << "(the Door gets locked when you get out of the house)" << endl;
                bothmasterAskGettingBackInAgain:
                cout << "Getting back in?" << endl; 
                bothMasterGetBackInAgain:
                cin >> getBackIn;
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    Master = 1;
                    cout << "(The door Opens automatically without entring key)" << endl;
                    cout << "(The door gets locked when you get back in the house)" << endl;
                    goto corridorOption;
                }
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "Okay Master.." << endl;
                    goto bothmasterAskGettingBackInAgain;
                }
                else
                {
                    wrongBeep();
                    cout << "I dont Understand you Master..! Answer Again: ";
                    goto bothMasterGetBackInAgain;
                }
            
            //////////////////////////// Guest going out //////////////////////////////////
            case 3:
                optionSelectYesBeep();
                Guest = 0;
                cout << "(the Door gets locked when you get out of the house)" << endl;
                guestAskGettingBackInAgain:
                cout << "getting back in?" << endl;
                guestGetBackInAgain:
                cin >> getBackIn;
                if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
                {
                    optionSelectYesBeep();
                    Guest = 1;
                    cout << "(The door Opens automatically without entring key)" << endl;
                    cout << "(The door gets locked when you get back in the house)" << endl;
                    goto corridorOption;
                }
                else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
                {
                    noBeep();
                    cout << "Okay Sir.." << endl;
                    goto guestAskGettingBackInAgain;
                }
                else
                {
                    wrongBeep();
                    cout << "I dont Understand you Sir..! Answer Again: ";
                    goto guestGetBackInAgain;
                }

            case 4:
                ////////////////// no one /////////////////////
                noBeep();
                cout << "Okay..!" << endl;
                goto corridorOption;
            
            default:
                wrongBeep();
                cout << "Invalid option. Select Again: ";
                goto goOutAnswerAgain;
            }
        }
        /////////////////////////// Master only ///////////////////////////////
        else if (Master == 1 && Guest == 0)
        {
            Master = 0;
            cout << "(The Door gets locked when you get out of the house)" << endl;
            masterAskGettingBackInAgain:
            cout << "Getting back in?" << endl; 
            masterGetBackInAgain:
            cin >> getBackIn;
            if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
            {
                optionSelectYesBeep();
                Master = 1;
                cout << "(The door Opens automatically without entring key)" << endl;
                cout << "(The door gets locked when you get back in the house)" << endl;
                goto corridorOption;
            }
            else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
            {
                noBeep();
                cout << "Okay Master.." << endl;
                goto masterAskGettingBackInAgain;
            }
            else
            {
                wrongBeep();
                cout << "I dont Understand you Master..! Answer Again: ";
                goto masterGetBackInAgain;
            }
        }
        ////////////////////////////// Guest only ///////////////////////////
        else if (Master == 0 && Guest == 1)
        {
            Guest = 0;
            cout << "(The Door gets locked when you get out of the house)" << endl;
            askGettingBackInAgain:
            cout << "Getting back in?" << endl; 
            getBackInAgain:
            cin >> getBackIn;
            if (getBackIn == "Yes" || getBackIn == "YES" || getBackIn == "yes" || getBackIn == "y" || getBackIn == "Y")
            {
                optionSelectYesBeep();
                Guest = 1;
                cout << "(The door Opens automatically without entring key)" << endl;
                cout << "(The door gets locked when you get back in the house)" << endl;
                goto corridorOption;
            }
            else if (getBackIn == "No" || getBackIn == "NO" || getBackIn == "no" || getBackIn == "n" || getBackIn == "N")
            {
                noBeep();
                cout << "Okay Sir.." << endl;
                goto askGettingBackInAgain;
            }
            else
            {
                wrongBeep();
                cout << "I dont Understand you Sir..! Answer Again: ";
                goto getBackInAgain;
            }
        }

    //////////////////// Leave House /////////////////////////////
    case 8:
        optionSelectYesBeep();
        ////////////////////////// Both in house /////////////////////////
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
            /////////////////////////// Both leaving ///////////////////////////////                
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

            ////////////////////// Master leaving ///////////////////////////////
            case 2:
                optionSelectYesBeep();
                Master = 0;
                cout << "Goodbye Master.. See you soon." << endl;
                cout << "(Door gets locked when you get out of the house)" << endl;
                break;

            //////////////////// Guest leaving //////////////////////
            case 3:
                optionSelectYesBeep();
                Guest = 0;
                cout << "Goodbye Sir.. Take care of yourself." << endl;
                cout << "(Door gets locked when you get out of the house)" << endl;
                break;

            //////////////////// no one leaving ///////////////////////////
            case 4:
                noBeep();
                cout << "Okay..!" << endl;
                goto corridorOption;
            
            default:
                wrongBeep();
                cout << "Invalid option. Select Again: ";
                goto leaveAnswerAgain;
            }
        }
        ////////////////////////// Master only ///////////////////////////
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
        //////////////////////// Guest only ////////////////////////////
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

    ////////////////////// Corridor Invalid Option ///////////////////////
    default:
        wrongBeep();
        cout << "Invalid Option. Select again: ";
        goto corridorOptionSelectAgain;
    }
    
    getch();
    return 0;
}
