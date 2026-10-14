/////////////////////////////////////////////////////////////////////
// Name: Ashley Villela
// Date: 10/13/2026
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: BMI calculator (program #2)
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void getPatientData(ifstream& infile, string firname[], string lasname[], double wei[], double hei[], int &count);
double cmToM(double centi);
double bmiCalc(double wei, double hei);
string bmiclass(double bMi);
void displayResults(string firname[], string lasname[], double weig[], double heig[], int count);

const int MAX = 140;
int main()
{
    ifstream ifile;
    int counter;
    double weight[MAX], heightCm[MAX];
    string fnames[MAX], lname[MAX];
    
    ifile.open("patients.txt");
    if(!ifile)
    {
        cout << "Error!!" << endl;
        return 1;
    }
    
    getPatientData(ifile, fnames, lname, weight, heightCm, counter);
    
    displayResults(fnames,lname, weight, heightCm, counter);

    cout << "Thank you for using our system!";
    
    
    ifile.close();
    return 0;
}

void getPatientData(ifstream& infile, string firname[], string lasname[], double wei[], double hei[], int &count)
{
    int totalPatient = 0;
    infile >> totalPatient;
    
    count = 0;
    while(count < totalPatient && count < MAX && infile >> firname[count] >> lasname[count] >> wei[count] >> hei[count])
    {
        count++;
        
    }
}


double cmToM(double centi)
{
    
    return centi / 100.;
}



double bmiCalc(double wei, double hei)
{
    
    hei = cmToM(hei); 
    return round((wei / (hei * hei)) * 100.0 ) / 100.0;
    
}

string bmiclass(double bMi)
{
    
    if(bMi < 18.50)
    { 
        return "Underweight";
    }
    else if(bMi >= 18.50 && bMi <= 24.9)
    {
        return "Normal Weight";
    }
    else if(bMi > 24.9 && bMi <= 29.9)
    {
        return "Overweight";
    }
    else
    {
        return "Obese";
    }
    
    
}
void displayResults( string firname[], string lasname[], double weig[], double heig[], int count)
{
    for(int i= 0; i < count; i++)
    {
        if(weig[i] <= 0)
        {
            cout << "ERROR: The value " << weig[i] << " is invalid for weight in kilograms. \nProgram ended."; 
            return;
        }
        if(heig[i] <= 0)
        {
            cout << "ERROR: The value " << heig[i] << " is invalid for height in centimeters. \nProgram ended."; 
            return;
        }
        
        
        double bMi = bmiCalc(weig[i], heig[i]);
        
        if(bMi < 0)
        {
            continue;
        }
        
        cout << fixed << setprecision(2);
        cout << "(#" << i + 1 << ") " << firname[i] << " " << lasname[i]<< "'s BMI is: " << bMi << endl;
        cout << "The BMI classification is " << fixed << setprecision(2) << bmiclass(bMi) << endl;
        cout << endl;
    }
}
