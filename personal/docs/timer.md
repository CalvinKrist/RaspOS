# Timers

## Types of Timers

There are two types of timers on the Raspberry Pi 3+: a Pi-specific timer and the ARM generic timer. 

# ARM Generic Timer

Documentation for the timer is sparse. Much of it can be found in the [ARM Architecture Reference Manual](https://static.docs.arm.com/ddi0487/ca/DDI0487C_a_armv8_arm.pdf?_ga=2.157161080.2134896525.1554409804-1120894666.1554134283)
	* Chapter D8 (page 2321) describes the Generic Timer in AArch64
	* Chapter 12 (page 5993) describes the system level implementation of the Generic Timer
	
## Generic Timer in AArch64

All information is from a mix of the [ARM Architecture Reference Manual](https://static.docs.arm.com/ddi0487/ca/DDI0487C_a_armv8_arm.pdf?_ga=2.157161080.2134896525.1554409804-1120894666.1554134283) chapter D8 and my own experience sin trying to implement the timer.

### Processing Element implementation overview

Each core, or processing element (referred to as a PE), implements the generic timer.The implementation provides the following components:

* A physical counter, which has the count value of the system counter
* A virtual counter, which gives access to virtual time. The `CNTVOFF_EL2` register defines offset between physical and virtual time
* A number of timers, none of which are required to be implemented 
	* EL1 physical timer
	* EL2 physical timer
	* EL3 physical timer
	* Virtual timer
	
### System level memory-mapped implementation overview

Memory-mapped registers that control the system level implementation are grouped into *frames*, where each register is accessed through offset to a frame and each frame has a base value. That base value is IMPLEMENTATION DEFINED, and defined by the system. Each system level component has one or two component frames. The possible components are:

**Memory-mapped counter module (required)**

* Controls the system counter. Has two frames:
	* Control frame, `CNTControlBase`
	* Status frame, `CNTReadBase`
* Described on page 5996
	
**Memory-mapped timer control module (required)**

* The system level implementation of the Generic Timer can provide up to eight timers. The timer control module identifies:
	* Which timers are implemented
	* The features of each implemented timer
	* Has a single frame: `CNTCTLBase`
* Described on page 6001
	
**Memory-mapped timers (optional)**:

* An implemented memory-mapped timer must:
	* Provide a privileged view of the timer in the `CNTBaseN` frame
	* Optionally, provide an unprivileged view of the timer in the `CNTEL0BaseN` frame
* N is the timer number, in the range 0-7
* Descibed on pahe 6002

### The System Counter

* **Width**: at least 56 bits wide. The value returned by a 64-bit read of the counter is zero-extended to 64 bits
* **Frequency**: a fixed frequency, typically in the range of 1-50MHz. Can support one or more alternative operating modes in which it increments by larger amounts at lower frequency, generally to save power
* **Roll-over**: Roll-over time of not less that 40 years
* **Accuracy**: ARM has no required accuracy, but recommends that the timer not be off by more than 10 seconds per 24 hours
* **Start up**: operation starts at 0

The `CNTFRQ_EL0` register is intended to hold a copy of the current clock frequency. This is done during the boot process by using the System register interface, and can only be done by software executing at the highest implemented exception level.

### System-level components of Generic Timer



### Registers

* `CNTVOFF_EL2`: defines offset between physical and virtual time
* `CNTFRQ_EL0`: holds a copy of the current clock frequency
* `CNTPCT_EL0`: holds the 64-bit physical count value. See page 2954 of the ARM Architecture Reference Manual.
	* `MRS <Xt>, <systemreg>`