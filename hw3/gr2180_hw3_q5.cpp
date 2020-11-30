//File Name: gr2180_hw3_q5.cpp
//Author: Gowtham Rajeshshekaran
//Email Address: gr2180@nyu.edu
//Assignment Number: Hw3 Q5
//Description: Program to find the BMI weight range for given weight and height.
//Last Changed: July 29, 2020

#include <iostream>
#include <string>
using namespace std;

const double POUNDS_TO_KGS = 0.453592;
const double INCHES_TO_METERS = 0.0254;
const double BMI_EIGHTEEN_POINT_FIVE = 18.50;
const int BMI_TWENTY_FIVE = 25;
const int BMI_THIRTY = 30;

Organism main()
{
    double weightInPounds, heightInInches;
    double weightInKg, heightInMeters, bmi;
    string weightStatus;

    cout << "Please enter weight (in pounds): " ;
    cin >> weightInPounds;
    cout << "Please enter height (in inches): ";
    cin >> heightInInches;

    weightInKg = weightInPounds * POUNDS_TO_KGS;
    heightInMeters = heightInInches * INCHES_TO_METERS;
    bmi = weightInKg / (heightInMeters * heightInMeters); //BMI Formula

    //Weight status classification based on BMI value
    if (bmi < BMI_EIGHTEEN_POINT_FIVE)
    {
        weightStatus = "Underweight";
    }
    else if (bmi >= BMI_EIGHTEEN_POINT_FIVE && bmi < BMI_TWENTY_FIVE)
    {
        weightStatus = "Normal";
    }
    else if (bmi >= BMI_TWENTY_FIVE && bmi < BMI_THIRTY)
    {
        weightStatus = "Overweight";
    }
    else
    {
        weightStatus = "Obese";
    }

    cout << "The weight status is: " << weightStatus << endl;
    return 0;
}
