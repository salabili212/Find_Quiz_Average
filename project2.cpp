/*Create a data file named gradesIn.txt containing quiz scores for approximately five students. 
Each student should have four quiz scores recorded using the double data type.
Your program should first read the four quiz scores from the file, 
then call a value-returning function that calculates the average after dropping the lowest score. 
This function must accept four double parameters and return the average of the three highest scores.

The output should be displayed on both the console and an output file. Name the output file as gradesOut.txt.
The output must include all the original data from the input file and an additional column showing each student’s quiz average.*/


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


double check_function(double q1, double q2, double q3, double q4){
    int low;
    double ave;
    if(q1<=q2&&q1<=q3&&q1<=q4){
        low=q1;
    }else if(q2<=q1&&q2<=q3&&q2<=q4){
        low=q2;
    }else if(q3<=q2&&q3<=q1&&q3<=q4){
        low=q3;
    }else{
        low=q4;
    }
    ave=(q1+q2+q3+q4-low)/3;
    return ave;
}



int main(){
    double q1,q2,q3,q4;
    string name;
    double result;

    ifstream inFile;
    ofstream outFile;

    outFile.open("gradesOut.txt");
    inFile.open("gradesIn.txt");

    cout <<"This programe will calculate the average of the student which it take four quizs and drop one the lowset grade\n";
    cout <<"|-------------------------------------------------------------------------------|\n";
    cout<<"| Name\t"<<"\tQuiz1\t"<<"Quiz2\t"<<"   Quiz3   "<<"  Quiz4    "<<"Average(3 Quizs only)"<<setw(6)<<"|"<<endl;
    cout <<"|-------------------------------------------------------------------------------|\n";
    outFile <<"|-------------------------------------------------------------------------------|\n";
    outFile<<"| Name\t"<<"\tQuiz1\t"<<"Quiz2\t"<<"   Quiz3   "<<"  Quiz4    "<<"Average(3 Quizs only)"<<setw(10)<<"|"<<endl;
    outFile <<"|-------------------------------------------------------------------------------|\n";
    while(inFile>>name>>q1>>q2>>q3>>q4){
        result=check_function(q1,q2,q3,q4);
        cout << "|"<<name<<setw(10)<<q1<<setw(10)<<q2<<setw(10)<<q3<<setw(10)<<q4<<setw(20)<<result<<setw(13)<<"|"<<endl;
        outFile << "|"<<name<<setw(10)<<q1<<setw(10)<<q2<<setw(10)<<q3<<setw(10)<<q4<<setw(20)<<result<<setw(13)<<"|"<<endl;
    }
    return 0;
}
    
    
