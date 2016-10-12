# PSoC 4S and Analog Coprocessor Nokia5110 Custom Macro

Custom Macro for Nokia5110 displays (based on the custom component), this macro is  based on the SPI (implemented on the SCB block) present on PSoC 4 devices.

PSoC 4S and Analog Coprocessor doesn't have UDBs so i can't use Control Registers to control the RST and DC pins inside a component, so those pins are controlled in firmware.

Internal driver of the Nokia5110 display works at 4MHz so SPI must work at that freq. aswell.

I removed the MISO line on both projects, the NOKIA 5110 display doesn't need it, but if you want to use it enable it on the SCB customizer.

Improvements are welcome.

PSoC Rocks!