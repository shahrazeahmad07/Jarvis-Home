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
    string burglarMasterKeyInput;
    string musicAnswer;
    string getBackIn;
    string recipieAnswer;

    bool switchcorridorlight = 0;
    bool switchMasterRoomLight = 0;
    bool switchGuestRoomLight = 0;
    bool switchLivingRoomLight = 0;
    
    bool switchmusic = 0;
    bool Master = 0;
    bool Guest = 0;
    bool switchCurtain = 0;
    bool switchTv = 0;
    int musicVolume = 67;
    int proteinIngredients = 3;
    int coffeeIngredients = 3;
    int smoothieIngredients = 3;
    


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
                optionSelectYesBeep();
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

    return 0;
}
