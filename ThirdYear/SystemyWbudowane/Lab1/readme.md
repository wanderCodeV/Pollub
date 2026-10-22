# Symulator Kalkulatora Czterodziałaniowego



Zawiera implementację oraz symulację prostego kalkulatora czterodziałaniowego.

Program umożliwia wprowadzenie dwóch liczb całkowitych, wybór podstawowej operacji arytmetycznej oraz wyświetlenie ostatecznego wyniku na wyświetlaczu 7-segmentowym.



## Pliki projektu



- **klawiatura_2.c** – główny kod źródłowy programu w języku C.

- **Lab1.2_Klawiatura.sim1** – plik symulacji układu.



## Przypisanie przycisków (Klawiatura)



Do obsługi kalkulatora wykorzystywana jest klawiatura matrycowa, w której przyciskom przypisano następujące funkcje:



| Przycisk | Funkcja |

| :--- | :--- |

| **S1 – S10** | Cyfry wprowadzanej liczby (0-9) |

| **S12** | Operacja „/” (dzielenie) |

| **S13** | Operacja „+” (dodawanie) |

| **S14** | Operacja „-” (odejmowanie) |

| **S15** | Operacja „x” (mnożenie) |

| **S16** | Operacja „=” (równa się / oblicz wynik) |



\## Wyświetlanie wyników



Wynik każdej operacji matematycznej prezentowany jest bezpośrednio na podłączonym \*\*wyświetlaczu LED 7SEG\*\*.

