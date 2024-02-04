#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    // open syslog -> openlog (const char *ident, int option, int facility) 
    // ident is arbitrary identification string which will be prefixed to each future syslog invocation
    // default ident is program name taken from argv[0]

    // options is bit string
    // facility is default facility code for this connection -> default is 0 -> LOG_USER
    openlog("assignment2-writer.c", LOG_PID, LOG_USER);

    // argc represents argument count -> 1 plus the number of arguments
    if (argc != 3)
    {
        syslog(LOG_ERR, "Provided %d arguments. Exactly 2 arguments needed to proceed.", argc - 1);
        closelog();
        return 1;
    }

    // assign inputs, argv[0] is program name so start from 1
    const char *writefile = argv[1];
    const char *writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    FILE *file = fopen(writefile, "w");

    if (file != NULL) 
    {
        fputs(writestr, file);
        fclose(file);
        closelog();
        return 0;
    }
    else
    {
        syslog(LOG_ERR, "unable to write to file");
        closelog();
        return 1;
    }
}