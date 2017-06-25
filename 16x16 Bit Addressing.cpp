#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
//Macro Function Definitions
#define iloop(n) for(int i=0; i<n; i++)
#define jloop(n) for(int j=0; j<n; j++)
//Function 'decode'
//Effectively converts a bit vector 'v' into a decimal number 'out'
int decode(vector<vector<bool> > v, int index) {
    int out = 0;
    int p = 1;
    iloop(v.size()) {
        out += v[i][index] * p;
        p *= 2;
    }
    return out;
}
//Function 'out'
//Prints a string 's' followed by bit vector 'v'
void out(string s, vector<bool> &v) {
    cout << setw(5) << s;
    iloop(v.size()) {
        cout << (int) v[i];
    }
    cout << endl;
}
//The SRAM Array is of size count x count bits.
#define count 16
//This is the number of lines required to address a row or coloumn.
//aline = lg(count)
#define aline 4
//Indicates Number of Address Lines to Use in The Test
//More useful at larger values of count
//The SRAM is tested in row addresses 0..amax-1 col address 0..amax-1
//For testing whole SRAM, amax <- aline
//In this case, only one quarter of SRAM cells is tested.
#define amax 2
int main() {
    
    //Indicates the number of input/output signals to generate in the test-case.
    int n;
    cout << "Enter number of random numbers to generate: ";
    cin >> n;

    //Data Structures to store signal information
    vector<vector<bool> > sram(count, vector<bool>(count));
    vector<vector<bool> > xAddress(aline, vector<bool>(n));
    vector<vector<bool> > yAddress(aline, vector<bool>(n));
    vector<bool> enable(n, 1);
    vector<bool> write(n);
    vector<bool> bitstream(n);
    vector<bool> output(n);
    
    //Generate random input signals for test-case
    srand(time(NULL));
    iloop(n) {
        jloop(amax) xAddress[i][j] = (rand() % 2 == 1);
        jloop(amax) yAddress[i][j] = (rand() % 2 == 1);
        bitstream[i] = (rand() % 2 == 1);
        write[i] = (rand() % 2 == 1);
    }
    cout << "Random Numbers Generated" << endl;

    //SRAM circuit logic for bit addressing
    iloop(n) {
        if (write[i]) sram[decode(xAddress, i)][decode(yAddress, i)] = bitstream[i];
        output[i] = sram[decode(xAddress, i)][decode(yAddress, i)];
    }

    //Output All Variables
    cout << "Signals:" << endl;

    iloop(aline) out("x" + to_string(i) + ": ", xAddress[i]);
    iloop(aline) out("y" + to_string(i) + ": ", yAddress[i]);

    out("en: ", enable);
    out("wr: ", write);
    out("bit: ", bitstream);

    cout << endl << "Outputs:" << endl;
    out("out: ", output);
    return 0;
}
