

opendbms:
	sqlite3 ./database.sqlite

drop_user_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/drop_user_tables.sql

build_user_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/build_user_tables.sql

drop_contact_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/drop_contact_tables.sql

build_contact_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/build_contact_tables.sql

drop_savedmessages_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/drop_savedmessages_tables.sql

build_savedmessages_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/build_savedmessages_tables.sql

drop_logForm_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/drop_logForm_tables.sql

build_logForm_table:
	sqlite3 ./database.sqlite < database_sqlite/00_build_db/build_logForm_tables.sql
