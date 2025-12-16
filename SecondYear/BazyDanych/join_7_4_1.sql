-- 7.4.1 Wskaż kanały sprzedaży (ChannelName) dla każdego kraju (CountryName), z którego
-- można dokonywać zamówień. W odpowiedzi uwzględnij wszystkie kraje. Uporządkuj
-- zbiór wynikowy według kraju. Zastosuj czytelne aliasy dla poszczególnych kolumn,
-- tj. Country dla pierwszej kolumny i Order Channel dla drugiej kolumny.

select distinct CountryName, ChannelName
from orderchannel oc
inner join orderheader oh
	on oc.channelkey = oh.channelkey
right join country cy
	on cy.countrykey = oh.countrykey
order by 1 ; 