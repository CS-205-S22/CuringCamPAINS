create table logForm (
    logId             INT NOT NULL UNIQUE,
    fullName          CHAR NOT NULL,
    age               INT NOT NULL,
    phoneNumber       CHAR NOT NULL,
    numOfAttempts     INT NOT NULL,
    methodOfContact   CHAR NOT NULL,
    reaction          CHAR NOT NULL,
    dateContacted     CHAR NOT NULL,
    isCommitted          BOOLEAN NOT NULL 
);
