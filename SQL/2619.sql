SELECT p."name",p2."name",p.price FROM products p
	inner join providers p2 on p.id_providers = p2.id 
	inner join categories c on p.id_categories = c.id 
	where p.price > 1000 and c."name" = 'Super Luxury';