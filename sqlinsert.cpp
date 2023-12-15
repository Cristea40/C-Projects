#include <mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;

    
    conn = mysql_init(NULL);

    
    if (mysql_real_connect(conn, "alice.home.server.paul.grozav.info", "root", "Giveme123", "Produse", 6373, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        return 1;
    }

    
    int Masina_id = 7;
    const char *Marca = "Mercedes";
    const char *Model = "E-Class";
    int AnProductie = 2023;
    float Pret = 65000.00;

   
    char query[200];
    sprintf(query, "INSERT INTO Produse (Masina_id, Marca, Model, AnProductie, Pret) VALUES (%d, '%s', '%s', %d, %.2f)",
            Masina_id, Marca, Model, AnProductie, Pret);

    
    if (mysql_query(conn, query) != 0) {
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    printf("Data inserted successfully!\n");

    
    mysql_close(conn);

    return 0;
}
