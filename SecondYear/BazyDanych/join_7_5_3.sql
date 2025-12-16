-- 7.5.3 Wskaż klientów, którzy dotychczas nie złożyli zamówienia poprzez jakikolwiek kanał
-- sprzedaży oraz kanał sprzedaży, który nie został użyty przez żadnego klienta. 
-- Wyświetl identyfikator klienta (CustomerKey), jego nazwisko (LastName), imię
-- (FirstName) oraz nazwę kanału sprzedaży (ChannelName). Uporządkuj zbiór
-- wynikowy według nazwiska klienta oraz kanału sprzedaży.

select distinct c.customerkey, lastname, firstname, channelname
from customer c 
left join orderheader oh 
	on c.customerkey=oh.customerkey
full join orderchannel oc 
	on oc.channelkey=oh.channelkey
order by 2, 4;