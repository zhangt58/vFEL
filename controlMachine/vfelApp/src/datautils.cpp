#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#ifdef __cplusplus
extern "C"
#endif
void readDataToArray(char *infilename, double *a, int n)
{
    std::ifstream infile;
    infile.open(infilename, std::ifstream::in);
    if (infile.good())
    {
        for(int i = 0; i < n; i++)
        {
            infile >> a[i];
        }
        infile.close();
    }
    else
    {
        std::cout << infilename << " read ERROR!" << std::endl;
        exit(1);
    }
}
