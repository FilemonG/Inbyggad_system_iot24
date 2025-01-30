#include <stdio.h>
#include "esp_log.h"

const static char *TAG = "MAIN";

#define ANSI_RED "\033[0;31m"    // macro för färg röd
#define ANSI_GREEN "\033[0;32m"
#define ANSI_Yellow "\033[0;33m"
#define ANSI_BLUE "\033[0;34m"
#define ANSI_MAGENTA "\033[0;35m"
#define ANSI_CYAN "\033[0;36m"
#define ANSI_RESET "\033[0m"
#define NEW_LINE "\n"
#define NEW_WORLD_COUNT 10
#define PRINTF_COLOR(color, format_string,...) \
    printf("%s" format_string "%s", color, ##__VA_ARGS__, ANSI_RESET)  // ANSI_RESET är för att återställa färgen

#define PRINTF_GROUP_1(format,...) \
    PRINTF_COLOR(ANSI_BLUE, "GROUP 1 "); \
    PRINTF_COLOR(ANSI_RESET, format, ##__VA_ARGS__)


#define PRINTF_COLOR_WITH_LINE(color, format_string,...) \
    PRINTF_COLOR(ANSI_MAGENTA, "[%s:%d] ", __FILE__, __LINE__); \
    PRINTF_COLOR(color, format_string, ##__VA_ARGS__)

void app_main(void)
{
    ESP_LOGI(TAG,"Hello world for my %d time!", NEW_WORLD_COUNT);

    const char* test_string = "Test";

    PRINTF_COLOR(ANSI_Yellow,"%s" NEW_LINE, test_string);

    PRINTF_GROUP_1("Hello World %d"NEW_LINE, NEW_WORLD_COUNT);
    for (int i = 0; i < 5; i++)
    {
         PRINTF_COLOR_WITH_LINE(ANSI_Yellow, "Round %d" NEW_LINE, i);
        
    }
    
}