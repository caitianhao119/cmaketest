#include "sqllitedb.h"
#include "config.h"
#include <string>

int main() {
    SQLliteDB q;
    
    std::string db_path = std::string(FILE_ROOT_PATH) + "/testDB";
    q.CreateSqlFile(db_path);

    std::string error_input = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";
    

    q.CreateTable(error_input);
    q.Insert("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 );");
    q.Select("SELECT * from COMPANY;");
    q.DeleteTable("COMPANY");
}