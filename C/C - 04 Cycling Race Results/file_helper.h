#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/********************************************************/
/* Define the missing members for the RiderInfo data    */
/* used to store Rider information read from a file     */
/********************************************************/
struct RiderInfo
{
    char name[31];
    int age;
    char raceLength;
    double startTime;
    double mountainTime;
    double finishTime;
    int withdrawn;
};


/********************************************************/
/* Read all the information on one rider from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info);

#endif
