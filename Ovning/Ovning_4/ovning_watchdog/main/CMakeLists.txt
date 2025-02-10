idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "include"
                    REQUIRE driver
                    REQUIRES freertos)