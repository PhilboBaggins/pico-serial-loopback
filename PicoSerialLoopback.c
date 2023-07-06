#include <stdio.h>

#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"

void loopbackCdcPort(uint8_t itfIncoming, uint8_t itfOutgoing)
{
    if (tud_cdc_n_available(itfIncoming))
    {
        // Read
        uint8_t buf[64];
        uint32_t count = tud_cdc_n_read(itfIncoming, buf, sizeof(buf));

        // Write
        for (uint32_t i = 0; i < count; i++)
        {
            tud_cdc_n_write_char(itfOutgoing, buf[i]);
        }
        tud_cdc_n_write_flush(itfOutgoing);
    }
}

void cdc_task(void)
{
    // Loopback port 0 to port 1 and vice versa
    loopbackCdcPort(0, 1);
    loopbackCdcPort(1, 0);

    // Loopback ports 2 and 3 to themselves
    loopbackCdcPort(2, 2);
    loopbackCdcPort(3, 3);
}

int main()
{
    board_init();
    tusb_init();

    while (1)
    {
        tud_task(); // tinyusb device task
        cdc_task();
    }

    return 0;
}
