
#include <stdio.h>
#include <math.h>
#include "sinetable.h"


int main (int argc, char *argv[])
{
  int xcor;
  int ycor;
  int idx;
  int xsize = 160;
  int ysize = 120;
  float xradius = 40;
  float yradius = 50;
  int csize = 4;
  float scanspeed = 1.f/500.f;
  float phs = 0.f;
  int n = 500;
  int k;

  for (k=0; k<n; k++) {
    //xcor = sinelu(phs, xradius) + ((int)(xsize/2));
    //ycor = coslu(phs, yradius) + ((int)(ysize/2));
    xcor = sinelu(phs, xradius);
    ycor = coslu(phs, yradius) ;
    idx = (xcor + ycor * xsize) * csize;
    fprintf(stdout, "%d %d\n", xcor, ycor);
    phs += scanspeed;
  }



  return 0;
}
