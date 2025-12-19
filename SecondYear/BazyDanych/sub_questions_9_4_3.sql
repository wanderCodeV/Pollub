-- 9.4.3 Wskaż w kolejnych latach ten produkt dla każdej kategorii produktowej, który został
-- zakupiony przez największą liczbę klientów. Wyświetl w zbiorze wynikowym rok
-- (cztery cyfry), nazwę kategorii (ProductCategoryName), nazwę produktu
-- (ProductName) i liczbę klientów. Opisz kolumny następującymi aliasami: Year,
-- Product i #Customers.

SELECT TO_CHAR(oh.OrderDate, 'YYYY') AS "Year",
    pc.productcategoryname AS "Category",
    p.productname AS "Product",
    COUNT(DISTINCT oh.customerKey) AS "#Customers"
FROM orderheader oh
INNER JOIN orderdetail od
    on od.orderkey = oh.orderkey
INNER JOIN product p
    on p.productkey = od.productkey
INNER JOIN productsubcategory psc
    on psc.productsubcategorykey = p.productsubcategorykey
INNER JOIN productcategory pc
    on pc.productcategorykey = psc.productcategorykey
GROUP BY
    TO_CHAR(oh.OrderDate, 'YYYY'),
    pc.productcategoryname,
    pc.ProductCategoryKey,
    p.productname
HAVING COUNT(DISTINCT oh.customerKey) = (
        SELECT 
            MAX(COUNT(DISTINCT oh2.CustomerKey))
        FROM
            OrderHeader oh2
        INNER JOIN OrderDetail od2 
            ON oh2.OrderKey = od2.OrderKey
        INNER JOIN Product p2 
            ON od2.ProductKey = p2.ProductKey
        INNER JOIN ProductSubcategory ps2 
            ON p2.ProductSubcategoryKey = ps2.ProductSubcategoryKey
        WHERE
            TO_CHAR(oh2.OrderDate, 'YYYY') = TO_CHAR(oh.OrderDate, 'YYYY')
            AND
            ps2.ProductCategoryKey = pc.ProductCategoryKey
        GROUP BY
            p2.ProductKey
    )
ORDER BY
    "Year" ASC,
    "Category" ASC;