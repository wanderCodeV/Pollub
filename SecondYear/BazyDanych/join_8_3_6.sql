-- 8.3.6 Podaj liczbę zamówień złożonych w poszczególnych regionach sprzedaży
-- w poszczególnych miesiącach kolejnych lat. Dla każdego regionu sprzedaży,
-- opisanego jego nazwą (SalesTerritoryName), wyświetl liczbę zamówień dla każdego
-- miesiąca w poszczególnych latach. Zastosuj czytelne aliasy do opisu kolumn, tj.
-- Region, Year, Month i #Orders. Uporządkuj zbiór wynikowy według region, roku
-- i miesiąca

select 
    salesterritoryname as "Region", 
    to_char(oh.orderdate, 'YYYY') as "Year", 
    to_char(oh.orderdate, 'MM') as "Month", 
    count(*) "#Orders"
from  salesterritory st
inner join country co
    on st.salesterritorykey = co.salesterritorykey
inner join orderheader oh
    on oh.countrykey = co.countrykey
group by 
    salesterritoryname, 
    to_char(oh.orderdate, 'YYYY'), 
    to_char(oh.orderdate, 'MM')
order by
    "Region" ASC,
    "Year" ASC,
    "Month" ASC;