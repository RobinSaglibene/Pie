/* Bring in gd library functions */
#include "gd.h"
#include "gdfontl.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void DrawText(gdImagePtr im, double radius,long angle,int color,int center,float min,float max, char* arg,float value);

int main( int argc, char *argv[]) {

  /* Declare the image */
  gdImagePtr im;
  /* Declare output files */
  FILE *pngout;

  /* Allocate the image: 1000 pixels across by 1000 pixels tall */
  im = gdImageCreate(800, 800);

  /* Allocate the color white for the background */
  int white = gdImageColorAllocate(im, 255, 255, 255);
  // Allocate the color black to write text
  int black = gdImageColorAllocate(im, 0, 0, 0);

  //Variable for the
  char *filepng="filepng.png";

  //Draw a white ectangle
  gdImageFilledRectangle(im,0,0,800,800,white);

  //if there is at least one argument
  if(argv[1])
  {
      // variables to get the arguments
      char *ch_arg=(char*)malloc(255);
      strcpy(ch_arg,argv[1]);
      char d []= "/";
      char *arg_nbr= strtok(ch_arg,d);

      // count number of arguments
      int nbr_arg=0;
      while (arg_nbr != NULL)
      {
          arg_nbr= strtok(NULL,d);
          nbr_arg++;
      }

      //Variable for the while
      char *arg=strtok(argv[1],d);
      int i=0;
      int r=0,g=0,b=100;
      int purcent;
      int center=400,outerCircle=500;
      double radius=305;
      float min=0,max=0;
      float argument;

      //While to draw filled arc and text
      while(arg !=NULL)
      {
          if(i<(nbr_arg-1))
          {
              if(i%2==0)
              {
                  argument =(float)strtol(arg,NULL,10);
                  purcent=(argument/100)*360;

                  max=min+purcent;
                  r+=(255/nbr_arg);
                  b+=(255/nbr_arg);
                  g+=(255/nbr_arg);

                  int r =rand()%256+1,g=rand()%256+1,b=rand()%256+1; // génération couleurs aléatoires

                  int color=gdImageColorAllocate(im, r, g, b);
                  gdImageFilledArc(im,center,center,outerCircle,outerCircle,min,max,color,0);
              }
              else
              {
                  DrawText(im,radius,140,black,center,min,max,arg,argument);
                  min=max;
              }
              arg= strtok(NULL,d);
              i++;
          }
          else
          {
              filepng=arg;
              arg= strtok(NULL,d);
          }
      }
  }

  pngout = fopen(filepng, "wb");
  /* Output the image to the disk file in PNG format. */
  gdImagePng(im, pngout);

  /* Close the file. */
  fclose(pngout);

  /* Destroy the image in memory. */
  gdImageDestroy(im);

  char command[32];
  char data[1024];
  sprintf(command, "display %s",filepng);
  //Open the process with given 'command' for reading
  FILE* file = popen(command, "r");
  // do something with program output.
  while (fgets(data, sizeof(data)-1, file) != NULL)
  {
      printf("%s", data);
  }
  pclose(file);
  return(0);
}

void DrawText(gdImagePtr im, double radius,long angle,int color,int center,float min,float max,char* arg,float value)
{
    double halfangles;
    if(min>max)halfangles=angle+(360-min)+max;
    else halfangles=min+((max-min)/2);
    double x=center+((radius)*cos(M_PI*(halfangles)/180));
    if(x<400) x-=80;
    else x-=40;
    double y=center+((radius)*sin(M_PI*(halfangles)/180));
    char *text=(char*)malloc(255);
    char *ch_value=(char*)malloc(7);
    gcvt(value,7,ch_value);
    strcat(text,arg);
    strcat(text," : ");
    strcat(text,ch_value);
    strcat(text,"%");
    gdImageString(im,gdFontLarge,x,y,text,color);
}

