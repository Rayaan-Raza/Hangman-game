#include <iostream>
#include <string>
#include <ctime> 
#include <cstdlib> 
#include <unistd.h>
using namespace std;

void Draw(int a)
{
   if(a>=6)
   {
	cout<<"+----+"<<endl;
	cout<<"|    |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"========"<<endl;
        }
 	
    if(a==5)
   	{
	cout<<"+----+"<<endl;
	cout<<"|    |"<<endl;
	cout<<"O    |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"========"<<endl;
          }
 	
     if(a==4)
  	 {
	cout<<"+----+"<<endl;
	cout<<"|    |"<<endl;
	cout<<"O    |"<<endl;
	cout<<"|    |"<<endl;
	cout<<"     |"<<endl;
	cout<<"     |"<<endl;
	cout<<"========"<<endl;
 	}
 	
      if(a==3)
   	{
	cout<<"  +----+"<<endl;
	cout<<"  |    |"<<endl;
	cout<<"  O    |"<<endl;
	cout<<"/ |    |"<<endl;
	cout<<"       |"<<endl;
	cout<<"       |"<<endl;
	cout<<" ========="<<endl;
       }
   
         if(a==2)
  	 {
	cout<<"  +----+"<<endl;
	cout<<"  |    |"<<endl;
	cout<<"  O    |"<<endl;
	cout<<"/ | \\  |"<<endl;
	cout<<"       |"<<endl;
	cout<<"       |"<<endl;
	cout<<" ========="<<endl;
 	}
 	
  	if(a==1)
   	{
	cout<<"  +----+"<<endl;
	cout<<"  |    |"<<endl;
	cout<<"  O    |"<<endl;
	cout<<"/ | \\  |"<<endl;
	cout<<" /     |"<<endl;
	cout<<"       |"<<endl;
	cout<<" ========="<<endl;
 	}
 	
  	 if(a==0)
  	 {
	cout<<"  +----+"<<endl;
	cout<<"  |    |"<<endl;
	cout<<"  O    |"<<endl;
	cout<<"/ | \\  |"<<endl;
	cout<<" / \\   |"<<endl;
	cout<<"       |"<<endl;  
	cout<<" ========="<<endl;
 	}
   }
   
bool common(string name, string word) 
{
for (int i = 0; i < name.length(); ++i)
 {
    char c = name[i];
    	for (int j = 0; j < word.length(); ++j) 
    	{
        	if (word[j] == c) 
        	{
          	  return true;
        	}
  	  }
	}
    return false;
}

bool result(string displayWord, string word, int lives)
{
    if (displayWord == word) 
    {
        cout << "\nYou Win!" << endl;
        return true; // Return true if the player guessed the entire word.
    }

    if (lives == 0) 
    {
        Draw(0);
        cout << " " << endl;
        cout << "\nGame over!" << endl;
        cout << "The word was: " << word << endl;
        return false; // Return false if the game is not won yet.
    }
}
  
 string list[] = {"board", "monitor", "mouse", "laptop", "printer", "software", "hardware", "net", "browser", "firewall", "database", "ethernet", "password", "scanner", "bluetooth", "download", "upload", "website", "algorithm", "network", "trapped", "wall", "mainframe", "mother", "peripheral", "operating", "father", "javascript", "processor", "smartphone", "cache", "password", "slow", "webmaster", "programmer", "fast", "analytics", "artificial", "bandwidth", "biometric", "datacenter", "debugger", "freeware", "gigabyte", "malware", "multitasking", "resolution", "screenshot", "template", "virtual", "computer", "internet", "download", "keyboard", "firewall", "software", "bluetooth", "motherboard", "algorithm", "ethernet", "browser", "password", "scanner", "monitor", "peripheral", "database", "smartphone", "mainframe", "operating", "firewall", "airborne", "processor", "encryption", "upload", "cache", "bandwidth", "lenovo", "debugger", "gigabyte", "freeware", "falcon", "artificial", "resolution", "screenshot", "template", "virtual", "malware", "analytics", "software", "internet", "keyboard", "programmer", "firewall", "browser", "operating", "motherboard", "database", "ethernet", "algorithm", "mouse"};

int main()
{ 
    srand(time(0));
    char guess;
    int lives = 6;

    cout << "----------------Welcome To Hangman----------------" << endl;
    cout << " " << endl;

    string name = "";
    cout << "Enter your name: ";
    getline(cin, name);

    cout << " " << endl;

    int i = rand() % 99 + 1;

    string word = list[i];

    int count = 0;

    for (int i = 0; i < word.length(); i++)
    {
        count++;
    }

      system("clear");


    cout << "----------------Welcome To Hangman----------------" << endl;

    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;


      string displayWord(count, ' _ ');
    do
    {
        Draw(lives);

        cout << " " << endl;
                cout<<"Lives : "<<lives<<endl;
                        cout << " " << endl;
        cout << " " << endl;


        cout << "The word : ";


        bool revealed = false; // Add a flag to check if anything is revealed.

        for (int i = 0; i < word.length(); i++) 
        {
            if (displayWord[i] != ' ') 
            {
                cout << displayWord[i] << " ";
            } 
            else if (word[i] == guess) 
            {
                cout << guess << " ";  // Display the correctly guessed character.
                displayWord[i] = guess;  // Update displayWord when the character is guessed correctly.
                revealed = true; // Set the flag to true when something is revealed.
            } 
            else 
            {
                cout << "_ ";
            }
        }
        
          cout<<" "<<endl;
        cout << "\nGuess a character : ";
        cin >> guess;
        cout<<" "<<endl;
                

        bool flag = false;
        for (int i = 0; i < word.length(); i++) 
        {
            if (word[i] == guess) 
            {
                flag = true;
                displayWord[i] = guess;  // Update displayWord when the character is guessed correctly.
            }
        }

        if (flag) 
        {
            cout << "Correct guess!" << endl;
            if (common(displayWord, word) && lives == 6)
            {
        lives++; // Increase lives by 1 if the conditions are met
        cout << "You found a common letter! You gained an additional life!" << endl;
            }
        } 
        else 
        {
            lives--;
            cout << "Wrong guess. Lives remaining: " << lives << endl;
        }

        sleep(1);

        system("clear");

 if(result(displayWord, word, lives))
 {
    break;
 }

    } while (lives > 0);

    return 0;
}
