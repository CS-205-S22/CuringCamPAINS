create table user (
      userId         INT NOT NULL UNIQUE,
      name      CHAR NOT NULL,
      password       CHAR NOT NULL,
      userName     INT NOT NULL,
      isResearcher   INT NOT NULL     );


.separator ","
.mode csv
.import "database_sqlite/00_build_db/users.csv"  user
