
// ConsoleApplication1.cpp

// Groupmemebers: Everette, ???, ???, ???

#include <cstring>
#include <iostream> 
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem; 

const string WELCOME_MESSAGE = "Welcome to myShell\n";
const string VOLUME_MESSAGE = "Volume in drive C is Windows\nVolume Serial number is 12345\n";

const string EXIT_MESSAGE = "Thanks for using myShell!\n";

const string TEMP_MESSAGE = "This is command: ";

bool isRunning = true;

void printWelcomeMessage();
void printExitMessage();
void commandDir();
void commandHelp();
void commandVol();
void commandPath();
void commandTaskList();
void commandNotePad();
void commandEcho();
void commandPing();
void commandQuit();

void printWelcomeMessage()
{
    cout << WELCOME_MESSAGE;
}

void printExitMessage()
{
    cout << endl << EXIT_MESSAGE << endl;
}

void commandDir()
{
    cout << endl;
    commandVol();
    cout << endl;
    cout << "Directory of ";
    commandPath();
    cout << endl;

    for (const auto & entry : fs::directory_iterator(fs::current_path()))
        std::cout << entry.path() << std::endl;

    cout << endl;
}

void commandHelp()
{
    cout << endl;
    cout << "Availble commands:\n" << "dir\nhelp\nvol\npath\ntasklist\nnotepad\necho\ncolor\nping\nquit\nexit\n";
    cout << endl;
}

void commandVol()
{
    cout << endl;
    cout << VOLUME_MESSAGE;
    cout << endl;
}

void commandPath()
{
    cout << endl;
    cout << fs::current_path() << endl;
    cout << endl;
}

void commandTaskList()
{
    cout << endl;
    cout << "No tasks are currently running on myShell" << endl;
    cout << endl;
}

void commandNotePad()
{
    cout << endl;
    cout << "Notepad is not installed on myShell" << endl;
    cout << endl;
}

void commandEcho(char *argument1)
{
    cout << endl;
    cout << argument1 << endl;
    cout << endl;
}

void commandColor()
{
    cout << endl;
    cout << "Unfornatly you can't change the color in this terminal" << endl;
    cout << endl;
}

void commandPing(char *argument1)
{
    cout << endl;
    cout << "Pinging " << argument1 << " with 32 bytes of data: " << endl;

    bool packet1success = ((double) rand() / (RAND_MAX)) + 1;
    bool packet2success = ((double) rand() / (RAND_MAX)) + 1;
    bool packet3success = ((double) rand() / (RAND_MAX)) + 1;
    bool packet4success = ((double) rand() / (RAND_MAX)) + 1;

    int packet1Time = rand() % 4 + 1;
    int packet2Time = rand() % 4 + 1;
    int packet3Time = rand() % 4 + 1;
    int packet4Time = rand() % 4 + 1;

    int numberOfSuccessPackets = 0;

    if(packet1success == true)
    {
        cout << "Reply from " << argument1 << ": bytes=32 time=" << packet1Time << "ms TTL=64" << endl;;
        numberOfSuccessPackets++;
    }
    if(packet2success == true)
    {
        cout << "Reply from " << argument1 << ": bytes=32 time=" << packet2Time << "ms TTL=64" << endl;
        numberOfSuccessPackets++;
    }
    if(packet3success == true)
    {
        cout << "Reply from " << argument1 << ": bytes=32 time=" << packet3Time << "ms TTL=64" << endl;
        numberOfSuccessPackets++;
    }
    if(packet4success == true)
    {
        cout << "Reply from " << argument1 << ": bytes=32 time=" << packet4Time << "ms TTL=64" << endl;
        numberOfSuccessPackets++;
    }

    cout << endl;

    cout << "Ping statistics for " << argument1 << ":" << endl 
    << "  Packets: sent=4, Recived=" << numberOfSuccessPackets 
    << ", Lost=" << (4-numberOfSuccessPackets) << endl 
    << "Approximate round trip times in milli-secons:" << endl
    << "Minimum = " << packet1Time << "ms, Maximum = " << packet2Time 
    << ", Average = " << packet3Time << "ms" << endl;

    cout << endl;

}

void commandQuit()
{
    isRunning = false;
}


int main() 
{ 
    
    printWelcomeMessage();

    char buffer[100];

    do
    {
        
        //get input
        cin.getline(buffer, 100);

        //parse input
        char *ptr = strtok(buffer, " ");

        char *command = ptr;

        ptr = strtok (NULL, " , ");
        char *argument1 = ptr;
        ptr = strtok (NULL, " , ");
        char *argument2 = ptr;
        ptr = strtok (NULL, " , ");
        char *argument3 = ptr;
        ptr = strtok (NULL, " , ");
        char *argument4 = ptr;

        //execute command
        if(strcmp(command, "dir") == 0)
        {
            commandDir();
        }
        else if(strcmp(command, "help") == 0)
        {
            commandHelp();
        }
        else if(strcmp(command, "vol") == 0)
        {
            commandVol();
        }
        else if(strcmp(command, "path") == 0)
        {
            commandPath();
        }
        else if(strcmp(command, "tasklist") == 0)
        {
            commandTaskList();
        }
        else if(strcmp(command, "notepad") == 0)
        {
            commandNotePad();
        }
        else if(strcmp(command, "echo") == 0)
        {
            commandEcho(argument1);
        }
        else if(strcmp(command, "color") == 0)
        {
            commandColor();
        }
        else if(strcmp(command, "ping") == 0)
        {
            commandPing(argument1);
        }
        else if(strcmp(command, "quit") == 0)
        {
            commandQuit();
        }
        else if(strcmp(command, "exit") == 0)
        {
            commandQuit();
        }
        else
        {
            cout << "Command " << command << " is not recognized\n";
        }


    } while(isRunning == true);

    printExitMessage();

    return 0; 
} 
