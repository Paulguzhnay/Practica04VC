
#include "Modelo.hpp"

#include <iostream>
#include <cstdlib>

// Librerías de OpenCV
#include <opencv2/core/core.hpp> // Contiene las definiciones base de matrices y estructuras
#include <opencv2/highgui/highgui.hpp> // Interfaz gráfica de usuario
#include <opencv2/imgproc/imgproc.hpp> // Procesamiento de imágenes
#include <opencv2/imgcodecs/imgcodecs.hpp> // Códecs para leer los distintos formatos de imágenes (JPG, PNG, etc.)
#include <opencv2/video/video.hpp> // Lectura de vídeos
#include <opencv2/videoio/videoio.hpp> // Lectura y escritura de videos

#include <opencv2/objdetect/objdetect.hpp> // Para realizar detección de objetos


#include <random>

#include <cmath>

//#include <opencv2/opencv.hpp> // Permite cargar todas las librerías de OpenCV

using namespace std;
using namespace cv; // Espacio de nombres de OpenCV para llamar a los métodos de forma más directa

int main(int argc, char *argv[]){

    Mat textura1 = imread("/home/computacion/Documentos/Vision/Boletines/Practica04/Clase2/FotoC2.png");
    Mat textura2 = imread("/home/computacion/Documentos/Vision/Boletines/Practica04/Clase1/FotoC1-2.png");
    
    vector<int> histoC1;
    vector<int> histoC2;
    vector<int> histoC3;
    vector<int> histoC4;
    //----------------------        
    vector<int> histogC1;
    vector<int> histogC2;
    vector<int> histogC3;
    vector<int> histogC4;
    //----------------------        
    vector<int> nuevohistoC1;
    vector<int> nuevohistoC2;
    vector<int> nuevohistoC3;
    vector<int> nuevohistoC4;
    //------------------------
    int valor1;
    int valor2;
    int valor3;
    int valor4;
    //----------------------------
    double resta1;
    double resta2;
    double resta3;        
    //----------------------------
    double restaN1;
    double restaN2;
    double restaN3;            
    double restaN4;
    //----------------------------
    double distancia1;
    double distancia2;
    double distancia3;
    //----------------------------
    double distanciaN1;
    double distanciaN2;
    double distanciaN3;
    double distanciaN4;
    
    string carp1 = "/home/computacion/Documentos/Vision/Boletines/Practica04/Clase1";
    string carp2 = "/home/computacion/Documentos/Vision/Boletines/Practica04/Clase2";
    string carp3 = "/home/computacion/Documentos/Vision/Boletines/Practica04/Clase3";
    Modelo *lbp = new Modelo();

    vector<string> nombresC1 = lbp->listarDir(carp1);
    vector<string> nombresC2 = lbp->listarDir(carp2);
    vector<string> nombresC3 = lbp->listarDir(carp3);

    
    //----------------------------------------------
        string nombC1 = nombresC1[0];
        string nombC2 = nombresC1[1];
        string nombC3 = nombresC2[0];
        string nombC4 = nombresC2[1];
//-----------------------------------------------------------        
        string nuevaC1 = nombresC3[0];
        string nuevaC2 = nombresC3[1];
        string nuevaC3 = nombresC3[2];
        string nuevaC4 = nombresC3[3];


        Mat nomC1=imread(nombC1);
        Mat nomC2=imread(nombC2);
        Mat nomC3=imread(nombC3);
        Mat nomC4=imread(nombC4);
//----------------------------------------------
        Mat nuevaIC1=imread(nuevaC1);
        Mat nuevaIC2=imread(nuevaC2);
        Mat nuevaIC3=imread(nuevaC3);
        Mat nuevaIC4=imread(nuevaC4);


//----------------------------------------------------------

        cvtColor(nomC1,nomC1,COLOR_BGR2Lab);
        cvtColor(nomC2,nomC2,COLOR_BGR2Lab);
        cvtColor(nomC3,nomC3,COLOR_BGR2Lab);
        cvtColor(nomC4,nomC4,COLOR_BGR2Lab);
//-------------------------------------------------------------


        cvtColor(nuevaIC1,nuevaIC1,COLOR_BGR2Lab);
        cvtColor(nuevaIC2,nuevaIC2,COLOR_BGR2Lab);
        cvtColor(nuevaIC3,nuevaIC3,COLOR_BGR2Lab);
        cvtColor(nuevaIC4,nuevaIC4,COLOR_BGR2Lab);
//----------------------------------------------------------

        histogC1 = lbp->histogramaC1(nomC1);
        histogC2 = lbp->histogramaC1(nomC2);
        histogC3 = lbp->histogramaC1(nomC3);
        histogC4 = lbp->histogramaC1(nomC4);    

//---------------------------------------------------------------    
    
        nuevohistoC1 = lbp->histogramaC1(nuevaIC1);
        nuevohistoC2 = lbp->histogramaC1(nuevaIC2);
        nuevohistoC3 = lbp->histogramaC1(nuevaIC3);
        nuevohistoC4 = lbp->histogramaC1(nuevaIC4);    
    
    
    ofstream MyFile("ReporteHistograma.txt");


    for (int i = 0; i < nombresC1.size(); i++)
    {
        string nomC1 = nombresC1[i];
        string nomC2 = nombresC2[i];
        


        Mat nC1=imread(nomC1);
        Mat nC2=imread(nomC2);

        cvtColor(nC1,nC1,COLOR_BGR2Lab);
        cvtColor(nC2,nC2,COLOR_BGR2Lab);

        histoC1 = lbp->histogramaC1(nC1);
        histoC2 = lbp->histogramaC1(nC2);
        cout<<nomC1<<endl;
        cout<<nomC2<<endl;
        
        MyFile << '\n';
        MyFile << '\n';
        MyFile << "Histograma de la Imagen: "+nomC1;
        MyFile << '\n';
        MyFile << '\n';
        
        
            for(int j=0;j<256;j++){
                valor1=histoC1[j]; 
                MyFile << to_string(valor1)+'|';
            }

        MyFile << '\n';
        MyFile << '\n';            
        MyFile << "Histograma de la Imagen: "+nomC2;
        MyFile << '\n';        
        MyFile << '\n';

            for(int k=0;k<256;k++){
             
                valor2=histoC2[k]; 
                MyFile << to_string(valor2)+'|';

            }            
            cout<<i<<endl;
    }
    MyFile.close();

        
//----------------------------------------------------
   ofstream MyFile2("ReporteHistogramaDistancia.txt");

        for (int j = 0; j < 4; j++)
        {
        MyFile2 << "\n";
        MyFile2 << "-----------------------------------------------------------------------------------------------------------";
        MyFile2 << '\n';
        MyFile2<<"Histograma "<<to_string(j)<<'\n'<<endl;
        //Histograma 0
        if(j==0){
            for(int i=0;i<256;i++){

                valor1=histogC1[i]; 
                MyFile2 << to_string(valor1)+'|';
                //DISTANCIA EUCLIDES IMGC1-1 - IMGC1-2
                resta1=resta1+pow(histogC1[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC1-1 - IMGC2-1
                resta2=resta2+pow(histogC1[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC1-1 - IMGC2-2
                resta3=resta3+pow(histogC1[i]-histogC4[i],2);


                //DISTANCIA EUCLIDES IMGC3-1 - IMGC1-1
                restaN1=restaN1+pow(nuevohistoC1[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC3-1 - IMGC1-2
                restaN2=restaN2+pow(nuevohistoC1[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC3-1 - IMGC2-1
                restaN3=restaN3+pow(nuevohistoC1[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC3-1 - IMGC2-2
                restaN4=restaN4+pow(nuevohistoC1[i]-histogC4[i],2);
            }

            distancia1=sqrt(resta1);
            distancia2=sqrt(resta2);
            distancia3=sqrt(resta3);
            //-------------------------
            distanciaN1=sqrt(restaN1);
            distanciaN2=sqrt(restaN2);
            distanciaN3=sqrt(restaN3);
            distanciaN4=sqrt(restaN4);

            MyFile2 << '\n';
            MyFile2 << '\n';
            MyFile2 << "Distancia entre la Imagen: " + nombresC1[0] + " y "+nombresC1[1] + "es de: "+to_string(distancia1);
            MyFile2 << '\n';
            MyFile2 << '\n';
            MyFile2 << "Distancia entre la Imagen: " + nombresC1[0] + " y "+nombresC2[0] + "es de: "+to_string(distancia2);
            MyFile2 << '\n';
            MyFile2 << '\n';
            MyFile2 << "Distancia entre la Imagen: " + nombresC1[0] + " y "+nombresC2[1] + "es de: "+to_string(distancia3);
            MyFile2 << '\n';

//-----------------------------------------------------------
            if(distancia1<distancia2 && distancia1<distancia3){
                MyFile2<<"Acierto ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[0] +" si tiene parecido a la imagen " + nombresC1[1];                
            }else if(distancia2<distancia1 && distancia2<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[0] +" tiene parecido a la imagen " + nombresC2[0];                
            }else if(distancia3<distancia1 && distancia3<distancia2){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[0] +" tiene parecido a la imagen " + nombresC2[1];                
            }
            //------------------------------------------------
            if(distanciaN1< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC1 +" pertenece a la Clase 1 ";                

            } else if(distanciaN2< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC2 +" pertenece a la Clase 1 ";                

            }else if(distanciaN3< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC3 +" pertenece a la Clase 1 ";                

            }else if(distanciaN4< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC4 +" pertenece a la Clase 1 ";                

            }
        }
//--------------------------------------------------------------------

        MyFile2 << '\n';
        //Histograma 1
        if(j==1){
            for(int i=0;i<256;i++){
                valor2=histogC2[i];
                MyFile2 << to_string(valor2)+'|';
                //DISTANCIA EUCLIDES IMGC1-2 - IMGC1-1
                resta1=resta1+pow(histogC2[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC1-2 - IMGC2-1
                resta2=resta2+pow(histogC2[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC1-2 - IMGC2-2
                resta3=resta3+pow(histogC2[i]-histogC4[i],2);


                //DISTANCIA EUCLIDES IMGC3-2 - IMGC1-1
                restaN1=restaN1+pow(nuevohistoC2[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC3-2 - IMGC1-2
                restaN2=restaN2+pow(nuevohistoC2[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC3-2 - IMGC2-1
                restaN3=restaN3+pow(nuevohistoC2[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC3-2 - IMGC2-2
                restaN4=restaN4+pow(nuevohistoC2[i]-histogC4[i],2);                 
        }
            distancia1=sqrt(resta1);
            distancia2=sqrt(resta2);
            distancia3=sqrt(resta3);
            //-------------------------
            distanciaN1=sqrt(restaN1);
            distanciaN2=sqrt(restaN2);
            distanciaN3=sqrt(restaN3);
            distanciaN4=sqrt(restaN4);


        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC1[1] + " y "+nombresC1[0] + "es de: "+to_string(distancia1);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC1[1] + " y "+nombresC2[0] + "es de: "+to_string(distancia2);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC1[1] + " y "+nombresC2[1] + "es de: "+to_string(distancia3);
        MyFile2 << '\n';
//-----------------------------------------------------------
            if(distancia1<distancia2 && distancia1<distancia3){
                MyFile2<<"Acierto ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[1] +" si tiene parecido a la imagen " + nombresC1[0];                

            }else if(distancia2<distancia1 && distancia2<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[1] +" tiene parecido a la imagen " + nombresC2[0];                
            }else if(distancia3<distancia1 && distancia3<distancia2){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC1[1] +" tiene parecido a la imagen " + nombresC2[1];                
            }

            //------------------------------------------------
            if(distanciaN1< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC1 +" pertenece a la Clase 1 ";                

            } 
            if(distanciaN2< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC2 +" pertenece a la Clase 1 ";                

            }
            if(distanciaN3< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC3 +" pertenece a la Clase 1 ";                

            }
            if(distanciaN4< distancia1 ){
                MyFile2<<"Pertenece a Clase 1";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC4 +" pertenece a la Clase 1 ";                

            }





        }

        //Histograma 2
        if(j==2){
            for(int i=0;i<256;i++){
                valor3=histogC3[i];
                MyFile2 << to_string(valor3)+'|';
                //DISTANCIA EUCLIDES IMGC2-1 - IMGC1-1
                resta1=resta1+pow(histogC3[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC2-1 - IMGC1-2
                resta2=resta2+pow(histogC3[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC2-1 - IMGC2-2
                resta3=resta3+pow(histogC3[i]-histogC4[i],2);

                //DISTANCIA EUCLIDES IMGC3-3 - IMGC1-1
                restaN1=restaN1+pow(nuevohistoC3[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC3-3 - IMGC1-2
                restaN2=restaN2+pow(nuevohistoC3[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC3-3 - IMGC2-1
                restaN3=restaN3+pow(nuevohistoC3[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC3-3 - IMGC2-2
                restaN4=restaN4+pow(nuevohistoC3[i]-histogC4[i],2);    




        }
            distancia1=sqrt(resta1);
            distancia2=sqrt(resta2);
            distancia3=sqrt(resta3);
            //-------------------------
            distanciaN1=sqrt(restaN1);
            distanciaN2=sqrt(restaN2);
            distanciaN3=sqrt(restaN3);
            distanciaN4=sqrt(restaN4);        

        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[0] + " y "+nombresC1[0] + "es de: "+to_string(distancia1);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[0] + " y "+nombresC1[1] + "es de: "+to_string(distancia2);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[0] + " y "+nombresC2[1] + "es de: "+to_string(distancia3);
        MyFile2 << '\n';
//-----------------------------------------------------------
            if(distancia3<distancia2 && distancia3<distancia1){
                MyFile2<<"Acierto ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[0] +" si tiene parecido a la imagen " + nombresC1[0];                

            }else if(distancia2<distancia1 && distancia2<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[0] +" tiene parecido a la imagen " + nombresC1[1];                
            }else if(distancia1<distancia2 && distancia1<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[0] +" tiene parecido a la imagen " + nombresC2[1];                
            }

            //------------------------------------------------
            if(distanciaN1< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC1 +" pertenece a la Clase 2 ";                

            } 
            if(distanciaN2< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC2 +" pertenece a la Clase 2 ";                

            }
            if(distanciaN3< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC3 +" pertenece a la Clase 2 ";                

            }
            if(distanciaN4< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC4 +" pertenece a la Clase 2 ";                

            }

        }



        //Histograma 3
        if(j==3){
            for(int i=0;i<256;i++){
                valor4=histogC4[i];
                MyFile2 << to_string(valor4)+'|';
                //DISTANCIA EUCLIDES IMGC2-2 - IMGC1-1
                resta1=resta1+pow(histogC4[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC2-2 - IMGC1-2
                resta2=resta2+pow(histogC4[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC2-2 - IMGC2-1
                resta3=resta3+pow(histogC4[i]-histogC3[i],2); 

                //DISTANCIA EUCLIDES IMGC3-4 - IMGC1-1
                restaN1=restaN1+pow(nuevohistoC4[i]-histogC1[i],2);
                //DISTANCIA EUCLIDES IMGC3-4 - IMGC1-2
                restaN2=restaN2+pow(nuevohistoC4[i]-histogC2[i],2);
                //DISTANCIA EUCLIDES IMGC3-4 - IMGC2-1
                restaN3=restaN3+pow(nuevohistoC4[i]-histogC3[i],2);
                //DISTANCIA EUCLIDES IMGC3-4 - IMGC2-2
                restaN4=restaN4+pow(nuevohistoC4[i]-histogC4[i],2);  




        }
            distancia1=sqrt(resta1);
            distancia2=sqrt(resta2);
            distancia3=sqrt(resta3);
            //-------------------------
            distanciaN1=sqrt(restaN1);
            distanciaN2=sqrt(restaN2);
            distanciaN3=sqrt(restaN3);
            distanciaN4=sqrt(restaN4);        


        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[1] + " y "+nombresC1[0] + "es de: "+to_string(distancia1);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[1] + " y "+nombresC1[1] + "es de: "+to_string(distancia2);
        MyFile2 << '\n';
        MyFile2 << '\n';
        MyFile2 << "Distancia entre la Imagen: " + nombresC2[1] + " y "+nombresC2[0] + "es de: "+to_string(distancia3);
        MyFile2 << '\n';
        //-----------------------------------------------------------
            if(distancia3<distancia2 && distancia3<distancia1){
                MyFile2<<"Acierto ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[1] +" si tiene parecido a la imagen " + nombresC1[0];                

            }else if(distancia2<distancia1 && distancia2<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[1] +" tiene parecido a la imagen " + nombresC1[1];                
            }else if(distancia1<distancia3 && distancia1<distancia3){
                MyFile2<<"FALLO ";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nombresC2[1] +" tiene parecido a la imagen " + nombresC2[0];                
            }
            //------------------------------------------------
            if(distanciaN1< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC1 +" pertenece a la Clase 2 ";                

            }
            if(distanciaN2< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC2 +" pertenece a la Clase 2 ";                

            }
            if(distanciaN3< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC3 +" pertenece a la Clase 2 ";                

            }
            if(distanciaN4< distancia3){
                MyFile2<<"Pertenece a Clase 2";
                MyFile2 << '\n';
                MyFile2<<"La imagen "+ nuevaC4 +" pertenece a la Clase 2 ";                

            }            
            
        }
        } 

        MyFile2.close();



    delete lbp;

    return 0;
    

}

// pip install --upgrade youtube-dl

