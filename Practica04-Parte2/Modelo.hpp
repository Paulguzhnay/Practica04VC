#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <time.h>
// Librerías de OpenCV
#include <opencv2/core/core.hpp> // Contiene las definiciones base de matrices y estructuras
#include <opencv2/highgui/highgui.hpp> // Interfaz gráfica de usuario
#include <opencv2/imgproc/imgproc.hpp> // Procesamiento de imágenes
#include <opencv2/imgcodecs/imgcodecs.hpp> // Códecs para leer los distintos formatos de imágenes (JPG, PNG, etc.)
#include <opencv2/video/video.hpp> // Lectura de vídeos
#include <opencv2/videoio/videoio.hpp> // Lectura y escritura de videos
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace cv;

#define compab_mask_inc(ptr,shift) \
{ value |= ((unsigned int)(cntr - *ptr) & 0x80000000) \
>> (31-shift); ptr++; }

class Modelo{

    private:
        int* LBP8(const int*, int , int);

    public:
        Modelo();
        vector<int> histogramaLBP(Mat);
        vector<int>histogramaC1(Mat);
        vector<int>histogramaC2(Mat);
        vector<string> listarDir(string d);
};