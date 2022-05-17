//File p04.cpp asks the user for a dollar amount between 0.01 and  $12000 and returns
//how to give change for that amount

#include <iostream>
#include <cmath>
using namespace std;
//function TheBill takes value parameters for dollar amount, denomination being checked
// and reference parameter for the spelling of the denomination
int TheBill(int amount, int denomination, string const  &denominationspelling)
{
        //the quantity of that denomination is found by dividing the amount by the denomination
        int quantity=amount/denomination;
        //the value returned by the function is the amount remaining after that denomination of bill is removed
        int returnvalue=amount-(quantity*denomination);
        //if quantity is greater than 0 so there are bills of that denomination
        if(quantity>0)
        {
                //checks to see if denomination is 1 to see if it must say coin for dollar coins instead of bill
                if(denomination==1)
                {
                        cout << quantity << " " << denominationspelling << " coin";
                }
                //otherwise it is a paper bill and prints the denominationspelling followed by "bill"
                else
                {
                        //print the number of bills followed by the spelling of the bill denomination and dollar bill
                        cout << quantity << " "<<  denominationspelling << " dollar bill";
                }
                //if there is more than one bill or coin add a s to the end of the statement  before advancing to a newline to make it plural
                if(quantity>1)
                {
                        cout << "s"<<endl;
                }
                //otherwise it stays as bills and continues to a newline
                else
             	 {
	   cout << endl;
                }
        }
        //return the return value
        return returnvalue;
}
//function TheCoin takes the same parameters at TheBill and determines the amount of change needed for coins
int TheCoin(int amount, int denomination, string const &denominationspelling)
{
        int  quantity=amount/denomination;
        int  returnvalue=floor(amount-(quantity*denomination));
        if(quantity>0)
        {
                cout << quantity << " " << denominationspelling;
                //checks to see if denomination is one for a penny as the plural for penny is different from other coins
                if( denomination==1)
                {
                        //if the coin is a penny and has multiple pennies it adds ies to the end of the statement to make pennny plural
                        if(quantity>1)
                        {
                                cout << "ies" << endl;
                        }
                        //otherwise penny is singular and adds a y to the end of the denominationspelling "penn" for correct grammer
                        else
                        {
                                cout << "y" << endl;
                        }
                }
                //other statements are  just like above function
                else if(denominationspelling !="penn" and quantity>1)
                {
                        cout << "s" << endl;
                }
                else
                {
                        cout <<endl;
                }
           }
        return returnvalue;
}
//function Coins takes an int parameter for the smount of change and uses the TheCoin method to determine number of coins needed
void Coins(int c)
{
//passes tTheCoin function the amount, denomination and denominationspelling
        c=TheCoin(c,50, "half dollar");
        c=TheCoin(c,25, "quarter");
        c=TheCoin(c,10, "dime");
        c=TheCoin(c,5,"nickel");
        c=TheCoin(c,1, "penn");

}
//function Bills takes an int parameter for the number of dollars and uses the TheBills function to determine number of bills and dollar coins
void Bills(int dollars)
{
        //passes TheBill functionn the amount , denomination and denomination spelling
        dollars=TheBill(dollars,10000,"ten-thousand");
        dollars=TheBill(dollars,5000,"five-thousand");
        dollars=TheBill(dollars,1000, "one-thousand");
        dollars=TheBill(dollars,500,"five-hundred");
        dollars=TheBill(dollars,100,"one-hundred");
        dollars=TheBill(dollars,50,"fifty");
        dollars=TheBill(dollars,20, "twenty");
        dollars=TheBill(dollars,10,"ten");
        dollars=TheBill(dollars,5,"five");
        dollars=TheBill(dollars,2,"two");
        dollars=TheBill(dollars,1, "one-dollar");
}
//function main gets the desired amount of change by prompting the user and calls the required functions for calculations
int main()
{
        double amount=2;
        //uses a do while loop to continueously prompt the user for a new value until they enter a value less than 1 penny
        do
        {
                //promps the user to enter the desired amount to get change for
                cout << "Enter the amount for which you want change. ";
                //reads in the amount to the amount variable
                cin >> amount;
                //if the amount is greater than or equal to 12000 the user is told the amount is too large and told to try again. Uses two endline //for formatting
                if(amount >= 12000)
                {
                        cout << "The amount is too large. Try again. "<<endl<<endl;
                }
                //otherwise input is valid and needed calculations are performed
                else
                {
                        //dollars is set to the integer portion of amount
                        int dollars=(int)(amount);
                        //function Bills is called with the parameter of collars to print out needed bills
                        Bills(dollars);
                        //amount of dcents is found by rounding amount subtracted by dollars and multiplying by 100
                        int cents=round( (100*(amount-dollars)));
                        //coins function is called with parameter to print out needed ccins
                        Coins(cents);
                        //if the amount is legal so the program will not be terminated once the while statement is reached
                        if(amount>=0.01)
                        {
                                //print a newline for correct formatting between entries
                                cout << endl;
                        }
                }
        }
        while(amount>=0.01);
        return 0;
}