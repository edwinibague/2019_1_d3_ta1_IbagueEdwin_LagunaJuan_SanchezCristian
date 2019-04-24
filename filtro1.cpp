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
//#ifdef _OPENMP
#include <omp.h>
//#define TRUE 1
//#define FALSE 0
//#else
//#define omp_get_thread_num()  0
//#define omp_get_num_threads() 1
//#endif

using namespace std;

void Filtrar(void);


int main(int argc, char const *argv[])
{ 	
    Filtrar();   
}

void Filtrar(void)
{
    cout<<"INGRESE EL NOMBRE DE LA IMAGEN A FILTRAR: "<<endl;
    string nombre;
   	cin >> nombre;
    Image  Imagen_de_entrada;
    string cadena="/home/david/Escritorio/Digitales/Tarea/2019_1_d3_hmw1_CasaguaJohan_CaicedoDavid_CardenasBrayan/"+nombre;
    char *in_path = strdup(cadena.c_str());
    int bandera = Imagen_de_entrada.fromFile(in_path);
    int threads=4;

     if(bandera==-1){
         cout<<"ERROR EN LA ESCRITURA ERROR EN EL TIPO DE IMAGEN\n";
         exit(1);
    }

     string cadena2="/home/david/Escritorio/Digitales/Tarea/2019_1_d3_hmw1_CasaguaJohan_CaicedoDavid_CardenasBrayan/"+nombre+"_filtrada.pgm";
     char *out_path= strdup(cadena2.c_str());
     Image Imagen_filtrada;
     Imagen_filtrada=Image(Imagen_de_entrada.width,Imagen_de_entrada.height);
     unsigned char *filtrico = new unsigned char [Imagen_de_entrada.width*Imagen_de_entrada.height];

     int center,tamano,acum_convx,acum_convy,x,y,nx,ny; 
     int newpixel;
     double Kernelx [5][5] = {
     				 {0, 0   , 0 , 0  , 0},
                     {0, 0.5 , 0 ,-0.5, 0},
                     {0, 1   , 0 ,-1  , 0},
                     {0, 0.5 , 0 ,-0.5, 0},
                     {0, 0   , 0 , 0  , 0}
                 };

     double Kernely[5][5] = {
     				 {0   , 0  , 0 , 0  , 0},
                     {0   ,0.5 , 1 , 0.5, 0},
                     {0   , 0  , 0 ,  0 , 0},
                     {0   ,-0.5,-1 ,-0.5, 0},
                     {0   , 0  , 0 , 0  , 0}
                 };

     tamano=sqrt(sizeof(Kernelx)/sizeof(Kernelx[0][0]));
     center=tamano/2;
     int a= Imagen_de_entrada.width;
     cout<<a<<endl;
     int b= Imagen_de_entrada.height;
     cout<<b<<endl;

        //Se barre la imagen
      
         for(int i=0;i<Imagen_de_entrada.height;i++){ 

            for(int j=0;j<Imagen_de_entrada.width;j++){

                 x=i-1;
                 y=j-1;

                 #pragma omp parallel for num_threads(threads)    
                 for(int k=0;k<tamano;k++){                 
                        
                            for(int l=0;l<tamano;l++){
                            nx=x+k;
                            ny=y+l;

                            	if(nx >= 0 && ny >= 0 && nx < Imagen_de_entrada.height && ny < Imagen_de_entrada.width){
                            	acum_convx+=Imagen_de_entrada[nx][ny]*Kernelx[k][l];
                            	acum_convy+=Imagen_de_entrada[nx][ny]*Kernely[k][l];
                            	}
                                
                            }
                        //int thread = omp_get_thread_num();
                        //cout<<thread<<endl;
                }



                //Se crea los pixeles de la imagen que fue filtrada 

            newpixel=sqrt((acum_convx*acum_convx)+(acum_convy*acum_convy));// el nuevo pixel pagina en el pdf
            if(newpixel<0){
                 newpixel=0;
            }
            if(newpixel>255){
                 newpixel=255;
            }
            filtrico[i*Imagen_de_entrada.width+j]=newpixel;
            acum_convx=0;
            acum_convy=0;
            }

        }
        
     Imagen_filtrada.data=filtrico;
     bandera=Imagen_filtrada.toFile(out_path);
}