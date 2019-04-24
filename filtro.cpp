#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <climits>
#include <cstring>
#include <typeinfo>
#include <cstdlib>
#include <sys/stat.h>
#include <cmath>
#include "image.h"
//#include <Image.cpp>
#include <omp.h>

using namespace std;

int main (){
                                                                                                                       
    string name;
    cout<<"Ingrese el nombre de la imagen que desea filtrar: ";
    cin >> name;
    Image Imagen_in;
    string cadena="/home/giovanny/Digitales/tarea_digitales/"+name+".pgm";
    char *in_path = strdup(cadena.c_str());
    int bandera = Imagen_in.fromFile(in_path);
    int threads = 2;

     if(bandera==-1){
         cout<<"Error en la escritura de la imagen\n";
         exit(1);
    }

     string cadena2="/home/giovanny/Digitales/tarea_digitales/"+name+"_filtrada.pgm";
     char *out_path= strdup(cadena2.c_str());
     Image Imagen_filtrada;
     Imagen_filtrada=Image(Imagen_in.width,Imagen_in.height);
     unsigned char *filt=new unsigned char [Imagen_in.width*Imagen_in.height];

     int center,tamano,acum_convx,acum_convy,x,y,nx,ny;
     int newpixel;
     double Gx [5][5] = {
     				 {0 , 0   , 0 , 0   , 0},
                     {0 , 0.5 , 0 ,-0.5 , 0},
                     {0 , 1   , 0 , -1  , 0},
                     {0 , 0.5 , 0 , -0.5, 0},
                     {0 , 0   , 0 , 0   , 0}
                 };

     double Gy [5][5] = {
     				 {0 , 0   , 0 , 0   ,0},
                     {0 , 0.5 , 1 , 0.5 ,0},
                     {0 , 0   , 0 , 0   ,0},
                     {0 ,-0.5 , -1, -0.5,0},
                     {0 , 0   , 0 , 0   ,0}
                 };

     tamano=sqrt(sizeof(Gx)/sizeof(Gx[0][0]));
     center=tamano/2;
     int a= Imagen_in.width;
     cout<<a<<endl;
     int b= Imagen_in.height;
     cout<<b<<endl;
    // cout << sizeof(myImage.data) << endl;
    // printf("%d\n",(int)myImage.data[4143*a+3912]);
    // //printf("%d\n",myImage[4143][3912]);
    // cout << "aaa" << endl;

		//omp_set_num_threads(4);
    	//int height = 0;
        //#pragma omp parallel for reduction(+:height)

        //{

         for(int i=0;i<Imagen_in.height;i++){

            for(int j=0;j<Imagen_in.width;j++){

                 x=i-1;
                 y=j-1;

                 #pragma omp parallel for num_threads(threads) 

                 for(int k=0;k<tamano;k++){                    
                        
                            for(int l=0;l<tamano;l++){
                            nx=x+k;
                            ny=y+l;

                            	if(nx >= 0 && ny >= 0 && nx < Imagen_in.height && ny < Imagen_in.width){
                            	acum_convx+=Imagen_in[nx][ny]*Gx[k][l];
                            	acum_convy+=Imagen_in[nx][ny]*Gy[k][l];
                            	}
                            }
                        
                }

            newpixel=sqrt((acum_convx*acum_convx)+(acum_convy*acum_convy));// el nuevo pixel
            if(newpixel<0){
                 newpixel=0;
            }
            if(newpixel>255){
                 newpixel=255;
            }
            filt[i*Imagen_in.width+j]=newpixel;
            acum_convx=0;
            acum_convy=0;
            }

        }

        //}// Fin pragma

        //height *= 0; 


     Imagen_filtrada.data=filt;
     bandera=Imagen_filtrada.toFile(out_path);

}