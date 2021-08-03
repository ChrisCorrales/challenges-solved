select substr(np.cpf, 1, 3) || '.' ||
       substr(np.cpf, 4, 3) || '.' ||
       substr(np.cpf, 7, 3) || '-' ||
       substr(np.cpf, 10) as cpf
       from natural_person np;