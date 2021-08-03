SELECT p.name, pr.name FROM products p
    INNER JOIN providers pr on p.id_providers = pr.id
    WHERE pr.name = 'Ajax SA';