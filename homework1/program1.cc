// Minh My Tran - CSCE24O HW 1 - 003

#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;

int main() {
    bool t = true;
    double count = 0.0;
    double right = 0.0;
    while ( t == true ) { 
        int x, y, z, n;
        char a, b;
        char input;
        count ++;
        cin >> x >> a >> y >> b >> z;
        if( a == '+') {
            n = x + y;
        }
        else if (a == '-') {
            n = x - y;
        } 
        else if (a == '*') {
            n = x * y;
        } 
        else if (a == '/') {
            n = x / y;
        }
        else if ( a == '%') {
            n = x % y;
        } else {
            cout << "Unrecognized arithmetic operator " << a <<endl;
        }

        
		if ( b == '<') {   
			cout << x << ' ' << a << ' ' << y << ' ' << b << ' ' << z << ' ';
			if ( n < z )
			{
				cout << "- Correct" << endl;
				right ++;
			}
			else
			{
				cout << "- Incorrect" << endl;
			}
		}
		else if (b == '>') {
			cout << x << ' ' << a << ' ' << y << ' ' << b << ' ' << z << ' ';
			if (n > z)
			{
				cout << "- Correct" << endl;
				right ++;
			} else {
				cout << "- Incorrect" << endl;
			}
		} 
	
        if( b != '>' && b != '<') {
            cout << "Unrecognized relational operator " << b <<endl;
        }

        cin >> input;
        switch (input)
        {
        case 'c':
            continue;
        case 'q':
            double p = (right/count) * 100;
            if( p > 0 ) {
                cout << right << " of " << count <<
                " = "<< std::fixed << std::setprecision(2) << p << "%";
            } else {
                cout << "0 of 0 = 0.00%" << endl;
            }
            t = false;
        }
    }
    return 0;
}