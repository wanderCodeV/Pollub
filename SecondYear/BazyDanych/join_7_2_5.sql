-- 7.2.5 Wskaż produkty, które zostały zamówione w poszczególnych regionach sprzedaży
-- w kolejnych latach. Dla każdego roku i regionu, opisanego przez jego nazwę
-- (SalesTerritoryName), podaj kod (ProductCode) i nazwę produktu (ProductName).
-- Zbiór wynikowy powinien zawierać trzy kolumny: rok, nazwę regionu sprzedaży
-- i produkt, opisany jako złączenie jego kodu i nazwy oddzielonych znakiem myślnika.
-- Uporządkuj zbiór wynikowy malejąco według roku, regionu sprzedaży i produktu.

SELECT distinct TO_CHAR(oh.orderdate, 'YYYY') YEAR, SalesTerritoryName, pr.productname || '-' || pr.productcode AS PRODUCT
from salesterritory st 
inner join country co
    on co.salesterritorykey = st.salesterritorykey
inner join orderheader oh
	on oh.countrykey = co.countrykey
inner join orderdetail od
	on od.orderkey = oh.orderkey
inner join product pr
    on pr.productkey = od.productkey
order by 1 DESC, 2 DESC, 3 DESC;