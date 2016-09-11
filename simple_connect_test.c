// Test connecting to a SQLite database

#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>

int callback(void* unused_arg, int argc, char** argv, char** col_name) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s => %s\n", col_name[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

int main() {
  sqlite3* db = NULL;
  char* err_mesg = NULL;
  int rc = 0;

  // Open connection to test.db, or create test.db if it doesn't exist.
  rc = sqlite3_open("test.db", &db);
  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    // Close connection after failure to deconstruct the object.
    sqlite3_close(db);
    return rc;
  }
  // Run a SQL command.
  rc = sqlite3_exec(db, "SELECT tbl_name FROM sqlite_master WHERE type = 'table'",
      callback, NULL, &err_mesg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", err_mesg);
    sqlite3_free(err_mesg);
  }
  sqlite3_close(db);
  return 0;
}
