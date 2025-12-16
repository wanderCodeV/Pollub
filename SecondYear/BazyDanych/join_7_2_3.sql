-- 7.2.3 Wskaż produkty, które zostały zamówione przez klienta (klientów) o nazwisku Alan.
-- Dla każdego klienta o podanym nazwisku, który dokonał już zakupu, podaj dane
-- opisujące produkt. Umieść w zbiorze wynikowym informacje o identyfikatorze klienta
-- (CustomerKey), jego nazwisku (LastName) i imieniu (FirstName) oraz kodzie
-- (ProductKey) i nazwie produktu (ProductName). Uporządkuj otrzymany wynik
-- według identyfikatora klienta oraz kodu produktu

SELECT distinct cus.CustomerKey, LastName, FirstName, pd.ProductKey,  ProductName
from product pd 
inner join orderdetail od
	on pd.productkey = od.productkey
inner join orderheader oh
	on od.orderkey = oh.orderkey
inner join customer cus
	on oh.customerkey = cus.customerkey
where upper(LastName) = 'ALAN'
order by 1, 4 ;