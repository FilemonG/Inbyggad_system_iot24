#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include <string.h>
#include "esp_log.h"

#define ANSI_RED "\033[0;31m"
#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"

#define UART_NUM UART_NUM_1
#define UART_TX_NUM GPIO_NUM_5
#define UART_RX_NUM GPIO_NUM_22 
#define RTS_IO_NUM -1
#define CTS_IO_NUM -1
#define UART_SEND_PERIOD 2000
#define UART_RECIVE_BUFF_SIZE 128

void app_main(void)
{
    static const int buffer_size = 1024;
    //const int dataLength;
   

    uart_config_t uartConf = {
        .baud_rate = 115200,
        .data_bits  = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        
    };
    ESP_ERROR_CHECK(uart_param_config(UART_NUM, &uartConf));
    ESP_ERROR_CHECK(uart_set_pin(UART_NUM,UART_TX_NUM,UART_RX_NUM,RTS_IO_NUM,CTS_IO_NUM));
    ESP_ERROR_CHECK(uart_driver_install(UART_NUM,buffer_size,buffer_size, 0,NULL,0));
    
    //uint8_t *data = (uint8_t *) malloc(buffer_size);
    TickType_t sentTm = xTaskGetTickCount();
    while (true)
    {
        TickType_t elapsTm = xTaskGetTickCount() - sentTm;
        if (elapsTm > pdMS_TO_TICKS(UART_SEND_PERIOD))
        {
            sentTm+= pdMS_TO_TICKS(UART_SEND_PERIOD);
            char* test = "Hej Världen\n";
            int bytesSent = uart_write_bytes(UART_NUM,(const char*)test, strlen(test));
            if (bytesSent < 0)
            {
                printf("Error writing uart\n");
            }
            else if (bytesSent > 0)
            {
                printf(ANSI_GREEN"Sent %d to uart \n",bytesSent);
            }
            else 
            {
                printf("No bytes sent.\n");
            }
        }

        uint8_t data[UART_RECIVE_BUFF_SIZE] = {0};
        int length = 0;
        ESP_ERROR_CHECK(uart_get_buffered_data_len (UART_NUM,(size_t *)&length));

        if (length > UART_RECIVE_BUFF_SIZE)
        {
            printf(ANSI_RED"Error: to small length\n");
            length = uart_read_bytes(UART_NUM,data, UART_RECIVE_BUFF_SIZE-1,pdMS_TO_TICKS(100));
        }
        else if (length > 0)
        {
            printf("Sent %d to uart:\n",length);
            length = uart_read_bytes(UART_NUM,data, length, pdMS_TO_TICKS(100));
        }
        else 
        {
            vTaskDelay(pdMS_TO_TICKS(10));
            continue;
        }
        if (length < 0)
        {
            printf("Error reading uart.\n");
        }
        else if (length > 0)
        {
            data[length] = 0;
            printf(ANSI_Yellow"Recived %d bytes on uart %s", length,data);
        }
        
    }
}