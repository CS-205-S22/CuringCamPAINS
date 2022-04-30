create table logForm (
    logId             INT NOT NULL UNIQUE,
    userId             INT NOT NULL ,
    fullName          CHAR NOT NULL,
    age               INT NOT NULL,
    phoneNumber       CHAR NOT NULL,
    numOfAttempts     INT NOT NULL,
    methodOfContact   CHAR NOT NULL,
    reaction          CHAR NOT NULL,
    dateContacted     CHAR NOT NULL,
    isCommitted          BOOLEAN NOT NULL
);

.separator ","
.mode csv
.import "database_sqlite/00_build_db/logForm.csv"  logForm
