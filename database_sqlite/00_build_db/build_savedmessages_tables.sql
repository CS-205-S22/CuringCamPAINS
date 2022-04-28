create table savedmessages (
      messageId         INT NOT NULL UNIQUE,
      userId         INT NOT NULL ,
      messageTitle      TEXT NOT NULL,
      messageText       TEXT NOT NULL
       );
       
.separator ","
.mode csv
.import "database_sqlite/00_build_db/savedmessages.csv"  savedmessages
