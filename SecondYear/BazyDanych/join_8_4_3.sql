-- 8.4.3 Oblicz wartość zamówień dla kolejnych miesięcy w poszczególnych latach dla
-- poszczególnych kategorii produktowych. W odpowiedzi podaj zarówno wartość dla
-- każdej kategorii (ProductCategoryName), wartość dla całego roku jak i wartość dla
-- kolejnych miesięcy danego roku. Zastosuj czytelne aliasy do opisu kolumn w zbiorze
-- wynikowym, tj. Product category, Year, Month i Total Value. Uporządkuj wynik
-- według nazwy kategorii, roku i miesiąca.

select 
    pc.productcategoryname as "Product category", 
    to_char(orderdate, "YYYY") as "Year", 
    to_char(orderdate, "MM") as "Month", 
    sum(od.quantity * od.transactionprice) as "Total Value"
from orderheader oh
inner join orderdetail od
    on od.orderkey = oh.orderkey
inner join product pr
    on pr.productkey = oh.productkey
inner join productsubcategory psc
    on psc.productsubcategorykey = pr.productsubcategorykey
inner join productcategory pc
    on pc.productcategorykey = psc.productcategorykey
    
    

