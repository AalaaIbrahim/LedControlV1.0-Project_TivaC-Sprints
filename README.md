# LED Control V1.0
#### ARM
#### Author: Team 1 - Sub team A
- #### Members:
    - Alaa Hisham
    - Hossam Elwahsh

## Brief
> Develop the GPIO Driver and use it to control RGB LED on the TivaC board based using the push button.


## Quick Links
- `Video` 👉 Youtube - in progress
- `Project Hex` 👉 [Build/LED_Control.hex](Build/LED_Control.hex)
- `Documentation` 👉 [Google Docs](https://docs.google.com/document/d/15XCq7KhCA17o89rHl8B3dAgSLqRwxgf1_SmRaluHrGM/edit?usp=sharing) 👉 PDF - in progress 

----
## Requirements
### Hardware Requirements
- Use the TivaC board
- Use SW1 as an input button
- Use the RGB LED
### Software Requirements
**The RGB LED is OFF initially**
- Pressing SW1:
  - After the first press, the Red led is on
  - After the second press, the Green Led is on
  - After the third press, the Blue led is on
  - After the fourth press, all LEDs are on
  - After the fifth press, should disable all LEDs
  - After the sixth press, repeat steps from 1 to 6
### Implement your drivers
- Implement GPIO driver
- Implement LED driver
- Implement Button driver
