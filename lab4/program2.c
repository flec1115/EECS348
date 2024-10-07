#include <stdio.h>
#include <string.h>

// Function to categorize temperature
void categorize_temp(float temp, char status[], char advisory[]) {
    if (temp <= 0) {
        strcpy(status, "Freezing");
        strcpy(advisory, "Wear your winter coat");
    } else if (temp <= 10) {
        strcpy(status, "Cold");
        strcpy(advisory, "Wear a jacket");
    } else if (temp <= 25) {
        strcpy(status, "Comfortable");
        strcpy(advisory, "You should feel comfortable");
    } else if (temp <= 35) {
        strcpy(status, "Hot");
        strcpy(advisory, "Wear cool clothes and drink water");
    } else {
        strcpy(status, "Extreme Heat");
        strcpy(advisory, "Avoid outdoors if you can");
    }
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

int main() {
    float temperature, converted_temperature;
    int current_scale, convert;
    char status[20], advisory[100];  // Buffers for storing status and advisory
    char unit[3];  // Buffer to store temperature unit

    // Getting the temperature from the user
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Getting the current scale of the temperature
    printf("\nChoose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &current_scale);

    // Validating that Kelvin temperature is not negative
    if (current_scale == 3 && temperature < 0) {
        printf("Error: Temperature in Kelvin cannot be negative!\n");
        return 1;  // Exit the program if invalid Kelvin temperature
    }

    // Getting the target scale to convert to
    printf("\nConvert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &convert);

    // Performing the conversion based on user input
    if (current_scale == convert) {
        // No conversion needed if the scales are the same
        converted_temperature = temperature;
    } else {
        if (current_scale == 1) {  // Celsius
            if (convert == 2) {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else if (convert == 3) {
                converted_temperature = celsius_to_kelvin(temperature);
            }
        } else if (current_scale == 2) {  // Fahrenheit
            if (convert == 1) {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else if (convert == 3) {
                converted_temperature = fahrenheit_to_kelvin(temperature);
                strcpy(unit, "K");
            }
        } else if (current_scale == 3) {  // Kelvin
            if (convert == 1) {
                converted_temperature = kelvin_to_celsius(temperature);
            } else if (convert == 2) {
                converted_temperature = kelvin_to_fahrenheit(temperature);
            }
        }
    }


    // Ensure converted temperature isn't negative Kelvin
    if (convert == 3 && converted_temperature < 0) {
        printf("Error: Converted temperature in Kelvin cannot be negative!\n");
        return 1;
    }

    // Categorizing the converted temperature
    categorize_temp(converted_temperature, status, advisory);

    // Displaying the result
    printf("\nConverted Temperature: %.2f\n", converted_temperature);
    printf("Temperature category: %s\n", status);
    printf("Weather advisory: %s\n", advisory);

    return 0;
}

