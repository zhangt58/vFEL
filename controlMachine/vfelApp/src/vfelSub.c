#include <stdio.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <aSubRecord.h>
#include <epicsExport.h>

extern void readDataToArray(char*, double*, int);
void handleLatticeAndRun(double*, int, char*, char*);

int vfelSubDebug = 0; // if 1, printf debug information.

// initialization function
static long vfelSimulatorAsubInit(aSubRecord *precord)
{
    if (vfelSubDebug)
        printf("Record %s called vfelSimulatorAsubInit(%p)\n",
                precord->name, (void*)precord);

    return 0;
}

// processing function
static long vfelSimulatorAsubProcess(aSubRecord *precord)
{
    if (vfelSubDebug)
        printf("Record %s called vfelSimulatorAsubProcess(%p)\n",
                precord->name, (void*)precord);

    // main processing routine goes below
    //
    // use as virtual machine trigger, could do somthing
    // before every machine run case
    //int *u = (int *) precord->u;
    //printf("%d\n", u[0]);
      
    // lattice generation
    double *paramlat = (double *) precord->e;
    // paramlat: {Q09, Q10}
    
    /* debug only
    int i;
    for(i = 0; i < precord->nee-1; i++)
        printf("%f ", e[i]);
    printf("%f\n", e[i]);
    */

    // parepare files/path for virtual machine running
    const char *envSim = getenv("SIM_ROOT");

    char **a = (char **) precord->a;
    char **b = (char **) precord->b;
    char **c = (char **) precord->c;
    char **d = (char **) precord->d;

    char *elefile  = (char *) calloc (100, sizeof(char));
    char *ltefile  = (char *) calloc (100, sizeof(char));
    char *sfh      = (char *) calloc (40,  sizeof(char));
    char *outdata1 = (char *) calloc (100, sizeof(char));

    strcpy(elefile,  a);
    strcpy(ltefile,  b);
    strcpy(sfh,      c);
    strcpy(outdata1, d);
    
    char *fullelefilename = (char *) calloc (200, sizeof(char));
    char *fullsimfolder   = (char *) calloc (200, sizeof(char));

    strcat(fullsimfolder, envSim);
    strcat(fullsimfolder, "/");
    strcat(fullsimfolder, sfh);
    strcat(fullsimfolder, "/");

    strcat(fullelefilename, fullsimfolder);
    strcat(fullelefilename, elefile);

    //printf("print %s\n", fullsimfolder);
    
    // handle lattice and
    // run virtual machine to generate data
    handleLatticeAndRun(paramlat, precord->nee, fullsimfolder, ltefile);
    
    // resolve data streams
    char *outfilename1 = (char *) calloc(100, sizeof(char));
    strcat(outfilename1, fullsimfolder);
    strcat(outfilename1, outdata1);
    
    // feed prof1 with data1
    double *vala = (double *) precord->vala;
    readDataToArray(outfilename1, vala, precord->neva);
    
    return 0;
}

static long vfelLatticeAsubInit(aSubRecord *precord)
{
    if (vfelSubDebug)
        printf("Record %s called vfelLatticeAsubInit(%p)\n",
                precord->name, (void*)precord);

    return 0;
}

static long vfelLatticeAsubProcess(aSubRecord *precord)
{
    if (vfelSubDebug)
        printf("Record %s called vfelLatticeAsubProcess(%p)\n",
                precord->name, (void*)precord);

    double *Q09 = (double *) precord->a;
    //printf("Q09: %f\n", Q09[0]);

    double *Q10 = (double *) precord->b;
    //printf("Q10: %f\n", Q10[0]);

    double *vala = (double *) precord->vala;
    vala[0] = Q09[0];
    vala[1] = Q10[0];

    return 0;
}

void handleLatticeAndRun(double *paramlat, int n, char *fullsimfolder, char *ltefile)
{
    char tmpstr[10] = {0};
    char *paramstr = (char *) calloc (200, sizeof(char));
    int i;
    for(i = 0; i < n; i++)
    {
        sprintf(tmpstr, " %.4f", paramlat[i]);
        strcat(paramstr, tmpstr);
    }
    //printf("%s\n", paramstr);

    char cmdline[200] = {0};
    strcat(cmdline, "cd ");
    strcat(cmdline, fullsimfolder);
    strcat(cmdline, ";bash run.sh ");
    strcat(cmdline, ltefile);
    strcat(cmdline, paramstr);
    strcat(cmdline, "> /dev/null");

    // start run instance
    system(cmdline);
}

epicsExportAddress(int, vfelSubDebug);
epicsRegisterFunction(vfelSimulatorAsubInit);
epicsRegisterFunction(vfelSimulatorAsubProcess);
epicsRegisterFunction(vfelLatticeAsubInit);
epicsRegisterFunction(vfelLatticeAsubProcess);
