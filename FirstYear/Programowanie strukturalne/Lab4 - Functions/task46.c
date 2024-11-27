#include <stdio.h>
#include <stdlib.h>

float kilometr_to_mile(float data);
float mile_to_kilometr(float data);
float horsepower_to_watt(float data);
float kilometr_hours_to_metrs_sekunds(float data);
float farenheit_to_celsjusz(float data);

int main()
{
    float dane, answer;
    printf("Podaj mili:");
    scanf("%f", &dane);
    printf("%f mili = %f kilometry\nPodaj kilometry: ", dane, mile_to_kilometr(dane));
    scanf("%f", &dane);
    printf("%f kilometry = %f mili\nPodaj konie mechaniczne : ",dane,  kilometr_to_mile(dane));
    scanf("%f", &dane);
    printf("%f konie mechaniczne = %f waty\nPodaj kilometry na godzine: ",dane,  horsepower_to_watt(dane));
    scanf("%f", &dane);
    printf("%f kilometry na godzine = %f metry na sekunde\nPodaj Fahrenheita: ",dane,  kilometr_hours_to_metrs_sekunds(dane));
    scanf("%f", &dane);
    printf("%f Fahrenheita = %f Celsjusza\n",dane,  farenheit_to_celsjusz(dane));
    return 0;
}

float kilometr_to_mile(float data)
{
    return 1.6*data;
}
float mile_to_kilometr(float data)
{
    return 0.625*data;
}
float horsepower_to_watt(float data)
{
    return 735*data;
}
float kilometr_hours_to_metrs_sekunds(float data)
{
    return 1000 * data / 3600;
}

float farenheit_to_celsjusz(float data)
{
    return 5 * (data - 32) / 9;
}
