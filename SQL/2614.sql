SELECT c.name, r.rentals_date FROM customers c
    INNER JOIN rentals r ON c.id = r.id_customers
    WHERE CAST(r.rentals_date as text) like '2016-09%';