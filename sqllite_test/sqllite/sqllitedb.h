#include <sqlite3.h>
#include <string>
#include <iostream>

class SQLliteDB {
public:
    SQLliteDB() {
        pDB = nullptr;
    }

    ~SQLliteDB() {
        if (pDB) {
		    sqlite3_close(pDB);
		    pDB = nullptr;
	    }
    }

    bool CreateSqlFile(const std::string& path) {
        if (!sqlite3_open(path.c_str(), &pDB)) {
            sqlite3_log(1, "Open Sql File Error");
            return false;
        }
        return true;
    }

    bool CreateTable(const std::string& sql) {
        char* msg = nullptr;
        int res = sqlite3_exec(pDB, sql.c_str(), NULL, NULL, &msg);
        if (res != SQLITE_OK) {
            std::cout << "Create Table Error" << std::endl;
            sqlite3_log(2, "Create Table Error");
            sqlite3_free(msg);
            return false;
        } else {
            std::cout << "Create Table Right" << std::endl;
            return true;
        }
    }

    bool DeleteTable(const std::string& table) {
        char* msg = nullptr;
        std::string sql = "DROP TABLE " + table + ";";
        int res = sqlite3_exec(pDB, sql.c_str(), NULL, NULL, &msg);
        if (res != SQLITE_OK) {
            std::cout << "Drop Table Error" << std::endl;
            sqlite3_log(3, "Create Table Error");
            sqlite3_free(msg);
            return false;
        } else {
            std::cout << "Drop Table Right" << std::endl;
            return true;
        }
    }

    bool Insert(const std::string& sql) {
        char* msg = nullptr;
        int res = sqlite3_exec(pDB, sql.c_str(), NULL, NULL, &msg);
        if (res != SQLITE_OK) {
            std::cout << "Insert Error" << std::endl;
            sqlite3_log(4, "Insert Error");
            sqlite3_free(msg);
            return false;
        } else {
            std::cout << "Insert Right" << std::endl;
            return true;
        }
    }

    static int select_callback(void *data, int num, char **fileds, char **names) {
        for (int i=0; i<num; i++) {
            std::cout << names[i] << " : " << fileds[i] << std::endl;
        }
        std::cout << std::endl;
        return 0;
    }

    bool Select(const std::string& sql) {
        char* msg = nullptr;
        int res = sqlite3_exec(pDB, sql.c_str(), select_callback, NULL, &msg);
        if (res != SQLITE_OK) {
            std::cout << "Insert Error" << std::endl;
            sqlite3_log(4, "Insert Error");
            sqlite3_free(msg);
            return false;
        } else {
            std::cout << "Insert Right" << std::endl;
            return true;
        }
    }



private:
    sqlite3 *pDB;
};