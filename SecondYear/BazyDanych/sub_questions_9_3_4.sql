-- 9.3.6 Oblicz średnią wartość zamówienia złożonego w poszczególnych latach. Wyświetl
-- w zbiorze wynikowym czterocyfrowy numer roku i średnią wartość zamówienia,
-- wyznaczoną na podstawie ceny transakcyjnej (TransactioPrice) i liczby sztuk
-- produktu (Quantity). Zaokrąglij obliczoną wartość do dwóch miejsc po przecinku.
-- Zastosuj czytelne aliasy do opisu kolumn, tj. Year i Avg Order Value. Posortuj zbiór
-- wynikowy według roku.

SELECT
    "Year",
    ROUND(AVG("Order Value"),2) AS "AVG Order Value"
FROM
    (SELECT
        TO_CHAR(oh.OrderDate, 'YYYY') AS "Year",
        od.orderKey as "Nr zamowienia",
        SUM(od.Quantity * od.TransactionPrice) AS "Order Value"
    FROM OrderHeader oh
    INNER JOIN OrderDetail od
        ON od.OrderKey = oh.OrderKey
    GROUP BY
        TO_CHAR(oh.OrderDate, 'YYYY'),
        od.orderKey)
GROUP BY "Year"
ORDER BY "Year";
