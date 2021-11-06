#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

void pow(int e, int b);
//global variables for the function variable and constant variable

int option;
const double g = 9.81;
const double p = 1000;



// welcome message function
void welcome(){
  //printing the options
  cout << " 1) Calculating the force on the dam \n 2) Calculating the force for a range of water elevation \n 3)Exit the program\n";
  // asking for the function input
  cout<< "Please choose a task: ";
  cin>> option;
  if(option != 1 || option != 2 || option !=3){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');


    }
}

//force over dam function
void ForceOverDam(){
    // identifying input variables
    double D, b, d, a;
    cout<< "The Depth Of The Channel: " << endl;
    cin >> D;

    cout<< "Width Of The Channel Base: " << endl;
    cin>> b;

    cout<< "Elevation Of Water Above Channel Bottom: " << endl;
    cin>> d;

    cout<< "Distance From Edge To Bank Of The Channel: " << endl;
    cin>> a;
    //checking if the values are positive & validating data types
    if(D <= 0 || b <= 0 || d <= 0 || a <= 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Please enter positive values\n\n";
        welcome();
    }else{
    //applying the equation

            double  f = p * g *  ((a * pow(d,4))  /  (6 * pow(D,2) ) + (b * pow(d,2)) / 2);

    cout  << "Force: " << f << " \n" <<endl;
    }
}

void RangeOfForces(){
        //identifying  variables
        double  D, b, a, d1, d2;
                long int f;
        //Inputs
        cout<< "The Depth Of The Channel: " << endl;
        cin >> D;

        cout<< "Width Of The Channel Base: " << endl;
        cin>> b;

        cout<< "Elevation Of Water Above Channel Bottom: " << endl;
        cin>> d1;

        cout<< "Second Elevation Of Water Above Channel Bottom: " << endl;
        cin>> d2;

        cout<< "Distance From Edge To Bank Of The Channel: " << endl;
        cin>> a;

        if(D <= 0 || b <= 0 || d1 <= 0 || d2 <= 0  ||a <= 0 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Please enter positive values\n\n";
            welcome();
        }else if (d1 >= d2) {
             cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Second Elevation should be greater than the First Elevation \n\n";
            welcome();


        }else{
    //table for the range
        cout << left << setw(10) << "Elevation" << "     :       " <<  left <<  setw(10) << "Force"  << endl;;
        for(double i = d1; i <= d2; i++ ){

             double  f = p * g *  ((a * pow(i,4))  /  (6 * pow(D,2) ) + (b * pow(i,2)) / 2);


             cout << left << setw(10) << i << "     :       " << left << setw(10) << f << endl ;
        }
        }

        cout << "\n\n";



}

int main() {
  // calling the welcome message
 welcome();
 while (option !=3){
  // Computation
  if (option == 1){
      //calling force over dam function
      ForceOverDam();
      welcome();
    }else if(option == 2){
        // calling range of forces function
        RangeOfForces();
        welcome();
    }else{
        // printing error message and repeating the program
        cout << "Please choose one of the option (1,2,3)\n\n";
        welcome();
    }
 }
  //program termination
  cout<< "Terminating the Program";
  return 0;
}
