-- 7.3.2 Wskaż te metody płatności, które dotychczas nie zostały wykorzystane podczas
-- płatności za zamówienia. Podaj nazwę metody płatności (PaymentMehodName).
-- Zastosuj w rozwiązaniu złączenie typu RIGHT JOIN

select paymentmethodname
from orderheader oh
right join paymentmethod pm
	on oh.paymentmethodkey = pm.paymentmethodkey
where oh.orderkey is null ; 