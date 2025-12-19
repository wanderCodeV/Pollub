-- 9.3.8 Oblicz największą i średnią wartość zamówienia złożonego w kolejnych latach
-- z wykorzystaniem poszczególnych kanałów sprzedaży. Przedstaw w zbiorze
-- wynikowym dane o roku zamówienia (w postaci Y2019, Y2020), sposobie złożenia
-- zamówienia (ChannelName) oraz największej i średniej wartości zamówienia. Opisz
-- kolumny tego zbioru czytelnymi aliasami, tj. Year, Channel, Max Order Value i Avg
-- Order Value. Posortuj zbiór wynikowy według roku i kanału sprzedaży

SELECT
    'Y' || Year  AS "Year",
    Channel,
    MAX("Order Value") AS "MAX Order Value",
    ROUND(AVG("Order Value"), 2)      AS "AVG Order Value"
FROM (
    SELECT
        TO_CHAR(oh.OrderDate, 'YYYY') AS Year,
        od.OrderKey  AS "Nr zamowienia",
        SUM(od.Quantity * od.TransactionPrice) AS "Order Value",
        oc.ChannelName  AS Channel
    FROM OrderHeader oh
    JOIN OrderDetail od
        ON od.OrderKey = oh.OrderKey
    JOIN OrderChannel oc
        ON oh.ChannelKey = oc.ChannelKey
    GROUP BY
        TO_CHAR(oh.OrderDate, 'YYYY'),
        od.OrderKey,
        oc.ChannelName
)
GROUP BY
    Year,
    Channel
ORDER BY
    Year,
    Channel;