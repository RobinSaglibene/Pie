/* Bring in gd library functions */
#include "gd.h"
#include "gdfontl.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NULL 0

void DrawText(gdImagePtr im, double radius,long angle,int color,int center,float min,float max, char* arg,float value);

void help();

int main( int argc, char *argv[]) {

  /* Declare the image */
  gdImagePtr im;
  /* Declare output files */
  FILE *pngout;

  /* Allocate the image: 1000 pixels across by 1000 pixels tall */
  im = gdImageCreateTrueColor(800, 800);


  /* Allocate the color white for the background */
  int white = gdImageColorAllocate(im, 255, 255, 255);
  // Allocate the color black to write text
  int black = gdImageColorAllocate(im, 0, 0, 0);

  gdImageAlphaBlending(im,gdEffectAlphaBlend);
  gdImageFill(im, 0,0,white);

  //Variable for the
  char *filepng="filepng.png";

  //Draw a white ectangle
  gdImageFilledRectangle(im,0,0,800,800,white);


  //if there is at least one argument
  if(argv[1])
  {
      // variables to get the arguments
      /*char *ch_arg=(char*)malloc(255);
      strcpy(ch_arg,argv[1]);*/
      char d []= "/";

      //Variable for the while
      char *data;
      char *arg;
      int i=0;
      int r=0,g=0,b=100;
      int purcent;
      int center=400,outerCircle=500;
      double radius=305;
      float min=0,max=0;
      float argument;

      int k=1;
      while (argc !=k)
      { 
          if(strcmp(argv[k],"-Size")==0)
          {
              outerCircle=center+strtol(argv[k+1],NULL,10);
          }
          else if(strcmp(argv[k],"-Data")==0)
          {
              data=argv[k+1];
          }
          else if(strcmp(argv[k],"-File")==0)
          {
              filepng=argv[k+1];
          }
          else if(strcmp(argv[k],"-Help")==0)
          {
              help();
          }
          k++;
      }
       arg=strtok(data,d);

      //While to draw filled arc and text
      while(arg !=NULL)
      {
              if(i%2==0)
              {
                  argument =(float)strtol(arg,NULL,10);
                  purcent=(argument/100)*360;

                  max=min+purcent;
                  r+=(255/5);
                  b+=(255/5);
                  g+=(255/5);

                  int r =rand()%256+1,g=rand()%256+1,b=rand()%256+1; // g??n??ration couleurs al??atoires

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

  /*
  FILE* file = popen(command, "r");
  // do something with program output.
  while (fgets(data, sizeof(data)-1, file) != NULL)
  {
      printf("%s", data);
  }
  pclose(file);*/
  return(0);
}

void afficheEtiquetteLabel(gdImagePtr im,double* posX, double* posY, char * label)
{
    int padding = 2;


    int length = strlen(label);
    int color = gdImageColorAllocateAlpha(im, 200,200,200, 30);

    int offsetX = length*8;
    int offsetY =  18 ;
    int max_X = *(posX) + offsetX;

    if (max_X > 1000) // si notre affichage d??passe de l'image, on d??cale l'affichage et on modifie posX et posY pour l'affichage du label
    {
        *posX = *(posX) - ( max_X - 1000);
    }
    gdImageFilledRectangle(im, *(posX)-padding, *posY, *(posX) +offsetX, *(posY) + offsetY, color);
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
    afficheEtiquetteLabel(im,&x, &y,text);
    gdImageString(im,gdFontLarge,x,y,text,color);
}

void help(){
    printf("# PIE \n# Installation \nProject created with QTcreator \nInstall gdlib first \
\n```bash"
       "\napt-get install libgd-dev"
       "\n```"

       "\n# Usage"

       "\n-Size suivi d'une valeur pour mettre la taille du cercle exemple 70"

       "\n-File suivi d'un nom de fichier pour enregistrer le fichier de sortie exemple monfichier.png"

       "\n-Data suivi des pourcentages et titres pour rentrer les donn??es exemple 50/usa/50/uk"

       "\n-Help"

       "\nIn project setting, "
       "\nadd arguement in the command line arguments field for exemple :"

       "\n```bash"
       "\n-Size 70 -File Monfichier1.png -Data 60/USA/15/UK/10/Canada/10/Other/5/Australia"
       "\n```");
}
