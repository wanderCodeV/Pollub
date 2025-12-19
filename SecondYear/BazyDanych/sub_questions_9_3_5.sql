-- 9.3.5 Oblicz dla każdego roku największą liczbę zamówień, jakie zostały złożone w ciągu
-- jednego miesiąca danego roku. Przedstaw w zbiorze wynikowym nazwę roku
-- (w postaci Y2019, Y2020) oraz liczbę zamówień. Opisz kolumny następującymi
-- czytelnymi aliasami: Year i #Max Monthly Orders. Posortuj zbiór wynikowy według
-- roku.

SELECT 
    Year, 
    MAX(Liczba_zamowien) AS "#Max Monthly Orders"
FROM (
    SELECT 
        TO_CHAR(OrderDate,'YYYY') AS Year, 
        COUNT(DISTINCT OrderKey) AS Liczba_zamowien
    FROM OrderHeader
    GROUP BY 
        TO_CHAR(OrderDate, 'YYYY'),
        TO_CHAR(OrderDate, 'MM') )
GROUP BY
    Year
Order By
    Year; 
    