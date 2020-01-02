#include <iostream>
using namespace std;

int fact(int i);
int fib(int i);
void prime(int i);
bool primeChecker(int i, int checker = 2);
int mult(int i, int n);
int multHelper(int i, int n);
string reverseString(string s);
string reverseStringHelper(string s);
int countOccurrences(string s, string c);
int countOccurrencesHelper(string s, string c, int counter, int wordSize);

int main() {

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Hrycewicz Test Code~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
	// factorial
		int count;
		int f=5;
		cout << "factorial of " << f << " is " << fact(f) << endl << endl;
	// Fibonocci
		for (count=0;count < 10;count++)
		{
			cout << "Fibonocci sequence number " << count+1 << " is " << fib(count+1) << endl;
		}
	// primes
		prime (10);
	// multiplication
		int a=6, b=5;
		cout << endl << "product of " << a << " and " << b << " is " << mult(a,b) << endl << endl;
	// string reversal
		string s = "abcde";
		cout << "original string " << s << " reversed string " << reverseString(s) << endl << endl;
	// character counting
		string t="a";
		cout << "number of occurrences of " << t[0] << " in " << s << " is " << countOccurrences(s,t) << endl;

	    return 0;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MY OWN TEST CODE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	cout << fact(5) << endl;
//	cout << fib(7) << endl;
//	int i = 11;
//	bool prime = primeChecker(i);
//	if (prime == true)
//	{
//		cout << i << " is prime. " << endl;
//	}
//	else if (prime == false)
//	{
//		cout << i << " is NOT prime " << endl;
//	}
//	prime(20);
//	cout << mult(5,0);
//	string test = " ?esiw eht siugalP htraD fo ydegart eht fo draeh reve uoy evaH";	//azzip snhoj apap
//	cout << reverseString(test);
//	cout << test << endl;
//	string word = "my name jeff";
//	string search = "f";
//	cout << countOccurrences(word, search);
}

int fact(int i)
{
	//base case
	if (i == 1)
	{
		return 1;
	}

	return i*fact(i-1);
	//4 x 3
	//3 x 2
	//2 x 1
	//1 x 1
	//^ returns first int and multiplies them all
}
int fib(int i)
{
	//base cases
	if (i <= 0)	//i mean.... fibonocci sequence starts at 1 so i guess anything before that is 0
	{
		return 0;
	}

	if (i == 1 or i == 2)
	{
		return 1;
	}

	return fib(i-1) + fib(i-2);
}
void prime(int i)
{
	int counter = 0;
	int amount = 0;

	while (!(amount == i))
	{
		if (primeChecker(counter) == true)
		{
			cout << counter << " ";
			amount++;
		}
		counter++;
	}
}
bool primeChecker(int i, int checker)
{
	//base case: number is 1
	if (i == 1)
	{
		//cout << "primerChecker: Number is 1, which is technically NOT prime for some reason. " << endl;
		return false;
	}

	//base case: number is less than 2 (excluding the number 1)
	if (i <= 2)
	{
		//cout << "primeChecker: Number is equal to or less than 2 (and isn't 1) so it's prime. " << endl;
		return true;
	}

	//the checker increments by 1 every time then divides the number by the checker.
	//so, if checker ever reaches the given number, the number is prime
	//ex) if number = 7 and checker == 7, we have attempted to divide number by 1, 2, 3, 4, 5, and 6, with all of them having a remainder, so it's prime
	if (checker >= i)
	{
		//cout << "primeChecker: Checker is now the same number as number. " << endl;
		return true;
	}

	if (i % checker == 0)
	{
		//cout << "primeChecker: Number is not prime. " << endl;
		return false;
	}

	primeChecker(i, checker+1);
}
int mult(int i, int n)
{
	if (n == 0)
	{
		return 0;
	}
	return mult(i, n-1) + i;
}
int multHelper(int i, int n)
{
	//i didn't need a helper :(
}
string reverseString(string s)
{
	if (s.length() == 1)
	{
		return s;
	}
	string newString = reverseStringHelper(s);
	return newString;
}
string reverseStringHelper(string s)
{
	if (s.length() == 1)
	{
		return s.substr(0,1);
	}
	string firstLetter = s.substr(s.length()-1,s.length()-1);	//first letter of "ABC" is 'C'
	//cout << "firstLetter: " << firstLetter << endl;
	s = s.substr(0, s.length()-1);	//"ABCDEF" becomes "ABCDE"
	//cout << "entire string is now: " << s << endl;
	return firstLetter + reverseStringHelper(s);
}
int countOccurrences(string s, string c)
{
	int total;
	total = countOccurrencesHelper(s, c, 0, s.length());
	return total;
}
int countOccurrencesHelper(string s, string c, int counter, int wordSize)
{
	if(counter == wordSize)
	{
		//cout << "Counter: " << counter << endl;
		return 0;
	}
	if(s.substr(counter, 1) == c)
	{
		//cout << c << " found. Counter: " << counter << endl;
		return 1 + countOccurrencesHelper(s, c, counter+1, wordSize);
	}
	else
	{
		//cout << "Searching " << s.substr(counter,1) << "... " << c << " not found. Counter: " << counter << endl;
		return countOccurrencesHelper(s, c, counter+1, wordSize);
	}
}
