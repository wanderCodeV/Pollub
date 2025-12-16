-- 7.3.4 Wskaż te produkty, które nie zostały dotychczas zamówione przez żadnego klienta.
-- Podaj kod (ProductCode) i nazwę produktu (ProductName). Uporządkuj wynik
-- według kodu produktu.

select pd.ProductCode, pd.ProductName
from product pd
left join OrderDetail od 
    on pd.ProductKey = od.ProductKey
where
    od.OrderKey is null
order by  pd.ProductCode;