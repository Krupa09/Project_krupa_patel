#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{ 
 int GPUspeed = 0, CPUspeed = 0, cores = 0, resolutionChoice = 0;
 float multiplier= 0.0, performanceScore = 0.0;
 string graphicsquality = "", stringText = "Computer Hardware Graphics Quality recommendation tools";
 int resolutionMatrix[4][2]={
 {1280, 720},
 {1920, 1080},
 {2560, 1440},
 {3840, 2160}
 };
 //input of the graphics card speed
 cout << "Please enter the clock speed (in Megahertz) of your graphic card: ";
 cin >> GPUspeed;
 
 cout << "Please enter the clock speed (in Megahertz) of your processor: ";
 cin >> CPUspeed;
 
 cout < "Please enter the number of cores of your processor: ";
 cin >> cores;
 
 // display resolutionMatrix
 cout << "What is the resolution of your monitor? \n";
 cout << "\t 1) 1280 x 720 \n" ;
 cout << "\t 2) 1920 x 1080 \n" ;
 cout << "\t 3) 2560 x 1440 \n" ;
 cout << "\t 4) 3840 x 2160 \n" ;
 cout << "Please select from above: ";
 cin >> resolutionChoice;
 
 //switch(resolution choice) 
	switch(resolutionChoice)
	{
		case 1: // 1280 x 720
	        multiplier = 1;
            resolutionChoice = 1280 * 720;
            break;
        case 2: // 1920 x 1080
	        multiplier = 0.75;
            resolutionChoice = 1920 * 1080;
            break;
        case 3: // 2560 x 1440
	        multiplier = 0.55;
            resolutionChoice = 2560 * 1440;
            break;
        case 4: // 3840 x 2160
	        multiplier = 0.35;
            resolutionChoice = 3840 * 2160;
            break;
        default : // error
	        cout << "wrong resolution choice input!";
	        return 0;
            break;
	}
        
 // calculate performace score
    performanceScore = ((5 * GPUspeed) + (cores * CPUspeed)) * multiplier;
  
  // determine graphics quality
  if(performanceScore >= 17000)
     graphicsquality = "Ultra";
  else if(performanceScore >= 15000)
     graphicsquality = "High";
  else if(performanceScore >= 13000)
     graphicsquality = "Medium";
  else if(performanceScore >= 11000)
     graphicsquality = "Low";
  else 
     graphicsquality = "Unable to play";
     
  // output results
  cout << stringText << endl;
  cout << "GPU clock speed: " << GPUspeed << "MHz" << endl;
  cout << "CPU clock speed : " << CPUspeed << "MHz" << endl;
  cout << "Number of cores: " << cores << endl;
  cout << "Monitor Resolution: " << resolutionMatrix << endl;
  cout << "Performance Score: " << performanceScore << endl;
  cout << "Recommended Graphics Quality: " << graphicsquality << endl;
  
  return 0; 
 
}
