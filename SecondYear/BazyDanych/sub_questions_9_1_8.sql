-- 9.1.8 Wskaż ten miesiąc w 2019 roku, w którym zamówienia złożyło najwięcej klientów.
-- Podaj nazwę miesiąca oraz liczbę klientów. Zastosuj aliasy Month i #Customers do
-- opisu poszczególnych kolumn.

SELECT
    TO_CHAR(OrderDate, 'Month') AS "Month",
    COUNT(DISTINCT CustomerKey) AS "#Customers"
FROM OrderHeader 
WHERE TO_CHAR(OrderDate, 'YYYY') = 2019
GROUP BY
    TO_CHAR(OrderDate, 'Month')
HAVING
    COUNT(DISTINCT CustomerKey) = (
        SELECT MAX(COUNT(DISTINCT CustomerKey))
        FROM OrderHeader
        WHERE TO_CHAR(OrderDate, 'YYYY') = 2019
        GROUP BY TO_CHAR(OrderDate, 'Month')
        );
