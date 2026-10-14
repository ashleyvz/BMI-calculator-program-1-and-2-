/////////////////////////////////////////////////////////////////////
// Name: Ashley Villela
// Date: 10/13/2026
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: BMI calculator (program #1)
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double cmToM(double centi);
double bmiCalc(double wei, double hei);
string bmiclass(double bMi);

int main()
{
    int sentinal;
    double weight, heightCm, meters;
    double bmi;
    string name, lastname;
    
    cout << "How many patients do you want to process today? ";
    cin >> sentinal;
    
    cout << endl;
    
    for(int i = 0; i < sentinal; i++)
    {
        cout << "Enter the patient's name (#" << i + 1 << "): ";
        cin >> name >> lastname;
        
        cout << "Enter weight in kilograms: ";
        cin >> weight;
        
        if(weight < 0)
        {
            cout << "Error: The value " << weight << " is invalid for weight in kilograms." << endl;
            break;
        }
        
        cout << "Enter height in centimeters: ";
        cin >> heightCm;
        
        if(heightCm <= 0)
        {
            cout << "Error: The value " << heightCm << " is invalid for height in centimeters." << endl;
            break;
        }
        
        bmi = bmiCalc(weight, heightCm);
        cout << name << " " << lastname << "'s BMI is: " << bmiCalc(weight, heightCm) << endl;
        cout << "The BMI classification is " << fixed << setprecision(2) << bmiclass(bmi) << endl;
        cout << endl << endl;
    }
    
    cout << "Thank you for using our system!";
    
    
    return 0;
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
