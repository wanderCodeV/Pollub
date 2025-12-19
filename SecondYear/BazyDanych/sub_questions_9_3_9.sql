-- 9.3.9 Wskaż tych klientów, którzy złożyli zamówienia w kraju Australia i ich wartość jest
-- większa od średniej wartości zamówienia złożonego w tym kraju. Oblicz wartość
-- zamówienia na podstawie danych zgromadzonych w kolumnach TransactionPrice
-- i Quantity. Umieść w zbiorze wynikowym dane o kliencie, tj. jego identyfikatorze
-- (CustomerKey), nazwisku (LastName) i imieniu (FirstName). Opisz czytelnie
-- kolumny, używając aliasów Customer ID, Last Name i First Name. Uporządkuj zbiór
-- wynikowy według nazwiska klienta.

SELECT DISTINCT
    c.CustomerKey AS "Customer ID",
    c.LastName AS "Last Name",
    c.FirstName AS "First Name"
FROM
    Customer c
INNER JOIN
    OrderHeader oh ON c.CustomerKey = oh.CustomerKey
INNER JOIN
    Country co ON oh.CountryKey = co.CountryKey
INNER JOIN
    OrderDetail od ON oh.OrderKey = od.OrderKey
WHERE
    co.CountryName = 'Australia'
GROUP BY
    c.CustomerKey, c.LastName, c.FirstName, oh.OrderKey
HAVING
    SUM(od.Quantity * od.TransactionPrice) > (
    SELECT
        AVG(OrderValue)
    FROM (
        SELECT SUM(od2.Quantity * od2.TransactionPrice) AS OrderValue
        FROM OrderHeader oh2 
        INNER JOIN OrderDetail od2
            on od2.OrderKey = oh2.OrderKey
        INNER JOIN Country co2
            on co2.CountryKey = oh2.CountryKey
        WHERE 
            co2.CountryName = 'Australia'
        GROUP BY 
            oh2.OrderKey
        )
    )
ORDER BY
    "Last Name" ASC;