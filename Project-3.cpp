#include<iostream>
#include<iomanip>
using namespace std;

int main()

{

    int gpu_clk =0;
    int cpu_clk = 0;
    int cpu_core =0;
    int n = 0;
    int count = 0;
    int cha = 0 ;
    double perf_score =0;
    double res_mult = 0;
    double high_score = 0;
    double low_score = 0 ;
    float mult [4] = {1, 0.75, 0.55, 0.35} ;

    char res[4][15] =  { { "1280 * 720"}, {"1920 * 1080"}, {"2560 * 1440"}, {"3840 * 2160"} };
    char qual [5][15] = { {"Ultra"}, {"High"}, {"Medium"}, {"Low"}, {"Unable to play"} } ;

    char title[75] = "Computer Hardware Graphics Quality Recommendation Tool" ;
    cout << "\n" << title << endl ;

    cout << " How many computers are being processed? " ;
    cin >> n;

    do {
        cout << " Please enter the clock speed (in Megahertz) of your graphics card: " ;
        cin >> gpu_clk ;

        cout << " Please enter the clock speed (in Megahertz) of your processor: " ;
        cin >> cpu_clk ;

        cout << " Please enter the number of cores of your processor: " ;
        cin >> cpu_core ;

        cout << " What is the resolution of your monitor? "  << endl ;

        for (int i = 0; i < 4 ; i++)
            cout << "\t" << i+1 << " ) " << res[i] << endl ;

        cout << " Please select from the option above: " ;
        cin >> cha ;

        res_mult = mult[cha-1] ;

        perf_score = ((5 * gpu_clk) + (cpu_clk * cpu_core)) * res_mult ;

        cout << " GPU Clock Speed: " << gpu_clk << endl ;
        cout << " CPU Clock Speed: " << cpu_clk << endl ;
        cout << " Number of Cores: " << cpu_core << endl ;
        cout << " Monitor Resolution: " << res[cha-1] << endl ;
        printf( " Perfomance Score: %.2f " , perf_score) ;
        printf ( " \n ") ;

        if (perf_score > 17001)
            cout << " Recommended Graphics Quality: " << qual[0] << endl ;
        else if ( 15001 <=perf_score && perf_score<= 17000)
            cout << " Recommended Graphics Quality: " << qual[1] << endl ;
        else if ( 13001 <=perf_score && perf_score<= 15000)
            cout << " Recommended Graphics Quality: " << qual[2] << endl ;
        else if ( 11001 <=perf_score && perf_score<= 13000)
            cout << " Recommended Graphics Quality: " << qual[3] << endl ;
        else 
            cout << " Recommended Graphics Quality: " << qual[4] << endl ;
        
        if (high_score < perf_score)
            high_score = perf_score ;
        if (perf_score < low_score)
            perf_score = low_score ;
        if (count == 0)
            low_score = perf_score ;
        perf_score = 0 ;
        count ++ ;

    }
    while (count!= n) ;

    cout << " The highest performance score was: " << high_score << endl ;
    cout << " The lowest performance score was:  " << low_score << endl ;


return 0 ;

}
