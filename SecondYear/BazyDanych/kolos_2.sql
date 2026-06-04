SELECT *
FROM (
    SELECT oc.channelname,
        COUNT(oh.customerKey)
    FROM orderheader oh
    INNER JOIN orderchannel oc
        on oc.channelkey = oh.channelkey
    INNER JOIN orderdetail od
        on od.orderkey = oh.orderkey
    INNER JOIN product p
        on p.productkey = od.productkey
    INNER JOIN productsubcategory psc
        on psc.productsubcategorykey = p.productsubcategorykey
    INNER JOIN productcategory pc
        on pc.productcategorykey = psc.productcategorykey
    WHERE pc.productcategoryname = 'Accessories'
    GROUP BY oc.channelname
)
WHERE ROWNUM = 1