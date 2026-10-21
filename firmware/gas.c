/*
 * 8051 Gas Leakage Detection System
 * Target: AT89C51 (Keil C51)
 * Sensor: MQ-6 module using its digital output (D0)
 * Clock: 11.0592 MHz, as shown in the schematic
 *
 * Pin mapping from the supplied schematic:
 *   P3.2 / pin 12 -> MQ-6 digital output (active LOW)
 *   P2.0 / pin 21 -> LED through 220 ohm resistor
 *   P2.1 / pin 22 -> NPN transistor driver for buzzer
 *
 * The supplied HEX was inspected and shows this behavior:
 *   P3.2 LOW  -> P2.0 HIGH and P2.1 HIGH
 *   P3.2 HIGH -> P2.0 LOW  and P2.1 LOW
 *
 * This source reconstructs that behavior; it is not claimed to be the
 * original source code. Delay duration depends on compiler settings.
 */

#include <REGX51.H>

sbit GAS_SENSOR = P3^2;  /* AT89C51 physical pin 12 */
sbit LED_OUT    = P2^0;  /* AT89C51 physical pin 21 */
sbit BUZZER_OUT = P2^1;  /* AT89C51 physical pin 22 */

/* Approximate polling delay. It is not a calibrated millisecond delay. */
static void delay_poll(void)
{
    volatile unsigned int i;
    for (i = 0; i < 1000; i++)
    {
        ;
    }
}

void main(void)
{
    /* On 8051 ports, write 1 to release P3.2 for use as an input. */
    GAS_SENSOR = 1;

    /* Start with the alarm outputs off. */
    LED_OUT = 0;
    BUZZER_OUT = 0;

    while (1)
    {
        /* MQ-6 module's digital output is treated as active LOW. */
        if (GAS_SENSOR == 0)
        {
            LED_OUT = 1;
            BUZZER_OUT = 1;
        }
        else
        {
            LED_OUT = 0;
            BUZZER_OUT = 0;
        }

        delay_poll();
    }
}
