## NxN 6-Transistor SRAM Test-Case Generator
This repository contains C++ code to generate the input signals/stimuli for a 6-transsistor SRAM Array that is simulated in another software (Cadence ADE L). It also generates the correct output signals to verify the result. The below images shows an individual 6T cell. Source: Wikipedia.
 
<img width="40%" alt="Screenshot 2020-08-24 at 7 49 57 PM" src="https://user-images.githubusercontent.com/18059416/91055991-0340d800-e643-11ea-83fd-7c94aef4ca2a.png">

## Variants
There are two types of addressing used for the SRAM Array
### Cell Addressing
Requires a row decoder and a coloumn mux in hardware. Requires corresponding input signals.<br>
Number of Address Signals = 2 * lg(n) for a nxn SRAM Array<br>
Number of i/o Bits = 1
### Row Addressing
Requires just a row decoder in hardware.<br>
Number of Address Signals = lg(n) for a nxn SRAM Array<br>
Number of i/o Bits = n for a nxn SRAM Array

## Sample Output
The below snapshot shows a sample testcase and involved transitions in a 2x2 array which stores half a byte of data.

<img width="50%" alt="Screenshot 2020-08-24 at 7 43 22 PM" src="https://user-images.githubusercontent.com/18059416/91055539-6a11c180-e642-11ea-8c6c-999a4a67e522.png">

