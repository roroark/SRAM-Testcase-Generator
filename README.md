## NxN 6TSRAM Test-Case Generator
This repository contains C++ code to generate the input signals/stimuli for a SRAM Array that is simulated in another software (Cadence ADE L). It also generates the correct output signals to verify the result.

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
