-- 9.4.4 Wskaż dla każdego roku tego klienta, który złożył zamówienie o najwyższej wartości.
-- Wyświetl w zbiorze wynikowym rok (cztery cyfry), identyfikator klienta
-- (CustomerKey), nazwisko (LastName) połączone z imieniem (FirstName) oraz
-- wartość zamówienia. Opisz kolejne kolumny następującymi aliasami: Year, Customer
-- ID, Customer Name i Max Order Value.

select 
    extract(year from orderdate) Year, 
    cs.customerkey "Customer ID", 
    lastname || ' ' || firstname "Customer Name", 
    oh.orderkey, sum(transactionprice*quantity) "Max Order Value"
from orderheader oh inner join orderdetail od
    on oh.orderkey = od.orderkey
inner join customer cs
    on cs.customerkey = oh.customerkey
group by 
    extract(year from orderdate), 
    oh.orderkey, 
    cs.customerkey, 
    lastname || ' ' || firstname
having sum(transactionprice*quantity) = (select 
                                            max(sum(transactionprice*quantity))
                                        from orderheader oh2 inner join orderdetail od2
                                            on oh2.orderkey = od2.orderkey
                                        where 
                                            extract(year from oh2.orderdate) = extract(year from oh.orderdate)
                                        group by oh2.customerkey, oh2.orderkey
                                        )
order by 1, 2, 3 ; 