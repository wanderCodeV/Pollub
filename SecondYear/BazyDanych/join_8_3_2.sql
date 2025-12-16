-- 8.3.2 Wyznacz liczbę zamówień złożonych przez klientów w 2019 roku. W odpowiedzi
-- uwzględnij każdego klienta. Podaj jego identyfikator (CustomerKey), nazwisko
-- (LastName) i imię (FirstName) oraz liczbę zamówień. Zastosuj czytelny alias do opisu
-- ostatniej danej, np. #Orders. Uporządkuj malejąco zbiór wynikowy według liczby
-- zamówień

select cs.customerkey, LastName, FirstName, count(*) "#Orders"
from customer cs
left join orderheader oh
	on cs.customerkey = oh.customerkey
where extract(year from orderdate) = 2019
group by cs.customerkey, LastName, FirstName
order by 4 desc ;  