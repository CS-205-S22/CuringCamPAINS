create table contact (
      contactId         INT NOT NULL UNIQUE,
      treatmentId         INT NOT NULL ,
      userId     INT NOT NULL,
      firstName     CHAR NOT NULL,
      lastName     CHAR NOT NULL,
      phoneNumber     CHAR NOT NULL,
      emailAddress     CHAR NOT NULL,
      homeAddress     CHAR NOT NULL,
      age INT NOT NULL
       );



.separator ","
.mode csv
.import "database_sqlite/00_build_db/contacts.csv"  contact
