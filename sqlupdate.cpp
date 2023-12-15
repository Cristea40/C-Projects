#include <iostream>
#include <mysql.h>
#include <stdio.h>

int main() {
    MYSQL *conn;

    
    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init failed\n");
        return 1;
    }

    
    if (mysql_real_connect(conn, "alice.home.server.paul.grozav.info", "root", "Giveme123", "Produse", 6373, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    
    if (mysql_query(conn, "UPDATE Produse SET Pret = 99.999 WHERE Masina_id = 2;") != 0) {
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    
    if (mysql_affected_rows(conn) > 0) {
        std::cout << "The item was updated.\n";
    } else {
        std::cout << "No matching items found for update.\n";
    }

    
    mysql_close(conn);

    return 0;
}
