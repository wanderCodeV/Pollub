-- 8.8.4 Wskaż te produkty, które zostały zamówione przez więcej niż 1000 klientów
-- w poszczególnych latach. Umieść w zbiorze wynikowym dane o roku (cztery cyfry),
-- nazwie produktu (ProductName) i liczbie klientów. Opisz kolumny czytelnymi
-- aliasami, tj. Year, Product i #Customers. Uporządkuj zbiór wynikowy malejąco
-- według roku i malejąco według liczby klientów.

SELECT
    TO_CHAR(oh.OrderDate, 'YYYY') AS "Year",
    p.ProductName  AS "Product",
    COUNT(DISTINCT oh.CustomerKey) AS "#Customers"
FROM OrderHeader oh
INNER JOIN OrderDetail od
    ON od.OrderKey = oh.OrderKey
INNER JOIN Product p
    ON p.ProductKey = od.ProductKey
GROUP BY
    TO_CHAR(oh.OrderDate, 'YYYY'),
    p.ProductName
HAVING COUNT(DISTINCT oh.CustomerKey) > 1000
ORDER BY
    "Year" DESC,
    "#Customers" DESC;
