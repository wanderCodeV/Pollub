-- 9.1.4 Wskaż ten produkt (lub produkty), który najczęściej zamawiano w 2019 roku, tzn. na
-- który złożono największą liczbę zamówień. Podaj nazwę produktu (ProductName)
-- oraz liczbę zamówień, w których ten produkt wystąpił. Zastosuj czytelne następujące
-- aliasy: Product i #Orders. Jeśli to konieczne, posortuj zbiór wynikowy według nazwy
-- produktu.

SELECT
    p.ProductName  AS "Product",
    COUNT(oh.OrderKey) AS "#Orders"
FROM OrderHeader oh
INNER JOIN OrderDetail od
    ON od.OrderKey = oh.OrderKey
INNER JOIN Product p
    ON p.ProductKey = od.ProductKey
WHERE TO_CHAR(oh.OrderDate, 'YYYY') = 2019
GROUP BY 
    p.ProductName
HAVING COUNT(oh.OrderKey) = (SELECT MAX(COUNT(oh2.OrderKey))
                            FROM OrderHeader oh2
                            INNER JOIN OrderDetail od2
                                on od2.OrderKey = oh2.OrderKey
                            WHERE TO_CHAR(oh2.OrderDate, 'YYYY') = 2019
                            GROUP BY od2.ProductKey
                            )
ORDER BY
    "Product";