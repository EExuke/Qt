/**************************************************************************** **
 * Copyright (C) 2010-2011 Cameo Communications, Inc.
 **************************************************************************** **/

/* ************************************************************************** **
 *     MODULE NAME            : system
 *     LANGUAGE               : C
 *     TARGET ENVIRONMENT     : Any
 *     FILE NAME              : sqlite_test.c
 *     FIRST CREATION DATE    : 2020/04/13
 * --------------------------------------------------------------------------
 *     Version                : 1.0
 *     Author                 : EExuke
 *     Last Change            : 2020/04/13
 *     FILE DESCRIPTION       :
** ************************************************************************** */

#include <stdio.h>
#include <sqlite3.h>
#include "/home/xuke/bin/dbg.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

/****************************************************************************
 *  Function Name : main
 *  Description   : The Main Function.
 *  Input(s)      : argc - The numbers of input value.
 *                : argv - The pointer to input specific parameters.
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
int main(int argc, char *argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		exit(1);
	}
	rc = sqlite3_open(argv[1], &db);
	if (rc)
	{
		fprintf(stderr, "Cant't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}
	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
    return 0;
}

/****************************************************************************
 *  Function Name : callback
 *  Description   : The callback Function.
 *  Input(s)      : argc
 *                : *argv
 *                : *azColName
 *  Output(s)     : NULL
 *  Returns       : 0
 ****************************************************************************/
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i]?argv[i]:"NULL");
	}
	printf("\n");
	return 0;
}

