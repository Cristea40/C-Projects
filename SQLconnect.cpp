#include <iostream>
#include <mysql/mysql.h>
#include <stdio.h>



int main() {

    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    
    conn = mysql_init(NULL);

    
    if (mysql_real_connect(conn, "your_host", "your_username", "your_password", "your_database", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Failed to connect to MySQL: %s\n", mysql_error(conn));
        return 1;
    }

    
    if (mysql_query(conn, "your_query") != 0) {
        fprintf(stderr, "Failed to execute query: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    
    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "Error fetching result set: %s\n", mysql_error(conn));
        mysql_close(conn);
        return 1;
    }

    
    while ((row = mysql_fetch_row(res)) != NULL) {
        for (unsigned int i = 0; i < mysql_num_fields(res); i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    
    mysql_free_result(res);

    
    mysql_close(conn);

    

    return 0;
}

