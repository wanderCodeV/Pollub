#include <stdio.h>
#include <stdlib.h>


int main()
{
    float dane, answer;
    printf("Podaj mili:");
    scanf("%f", &dane);
    answer = 0.625 * dane;
    printf("%f mili = %f kilometry\nPodaj kilometry: ", dane, answer);
    scanf("%f", &dane);
    answer = 1.6 * dane;
    printf("%f kilometry = %f mili\nPodaj konie mechaniczne : ",dane,  answer);
    scanf("%f", &dane);
    answer = 735 * dane;
    printf("%f konie mechaniczne = %f waty\nPodaj kilometry na godzine: ",dane,  answer);
    scanf("%f", &dane);
    answer = 1000  * dane / 3600;
    printf("%f kilometry na godzine = %f metry na sekunde\nPodaj Fahrenheita: ",dane,  answer);
    scanf("%f", &dane);
    answer = 5 * (dane - 32) / 9;
    printf("%f Fahrenheita = %f Celsjusza\n",dane,  answer);
    return 0;
}
