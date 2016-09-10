// Test connecting to a SQLite database

#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>

int main() {
  sqlite3* db = NULL;
  char* err_msg = NULL;
  int rc = 0;

  // Open connection to test.db, or create test.db if it doesn't exist.
  rc = sqlite_open("test.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    // Close connection after failure to deconstruct the object.
    sqlite_close(db);
    return rc;
  }
  // Run a SQL command.
  rc = sqlite_exec(db, "SELECT tbl_name FROM sqlite_master", callback, arg, &err_mesg);
  return 0;
}
