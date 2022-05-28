#ifndef TEXTURES_H_INCLUDED
#define TEXTURES_H_INCLUDED
#include <windows.h>
#include <stdio.h>
#include <GL\gl.h>		// GL Header File
#include <GL\glu.h>		// GL Utility Library(GLU)Header File
#include <GL\glut.h>	// GL Utility Toolkit(GlUT)Header File

float textures[6][4][2]=
{
//текстурные координаты 1-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
//текстурные координаты 2-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
//текстурные координаты 3-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
//текстурные координаты 4-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
//текстурные координаты 5-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
//текстурные координаты 6-й грани
0.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0,
};

//координаты граней куба(квадратов)
float cube[6][4][3]=
{
-1.0, -1.0, -1.0,
-1.0, -1.0, 1.0,
-1.0, 1.0, 1.0,
-1.0, 1.0, -1.0,

-1.0, -1.0, -1.0,
-1.0, 1.0, -1.0,
1.0, 1.0, -1.0,
1.0, -1.0, -1.0,

-1.0, -1.0, -1.0,
1.0, -1.0, -1.0,
1.0, -1.0, 1.0,
-1.0, -1.0, 1.0,

-1.0, -1.0, 1.0,
1.0, -1.0, 1.0,
1.0, 1.0, 1.0,
-1.0, 1.0, 1.0,

-1.0, 1.0, -1.0,
-1.0, 1.0, 1.0,
1.0, 1.0, 1.0,
1.0, 1.0, -1.0,

1.0, -1.0, -1.0,
1.0, 1.0, -1.0,
1.0, 1.0, 1.0,
1.0, -1.0, 1.0,
};

void drawCube()
{
int i,j;
//glEnable(GL_TEXTURE_2D);
for(i = 0; i < 6; i++)
    {
    glBindTexture(GL_TEXTURE_2D, i+1);
    //если текстуры разные
    //glBindTexture(GL_TEXTURE_2D, i);
    glBegin(GL_QUADS);
    for(j = 0; j < 4; j++)
        {
        glTexCoord2f(textures[i][j][0], textures[i][j][1]);
        glVertex3f(cube[i][j][0], cube[i][j][1], cube[i][j][2]);
        }
    glEnd();
    }
//glDisable(GL_TEXTURE_2D);
//glDisable(GL_TEXTURE_2D);
}


GLuint LoadTexture(GLuint tex, const char * filename, int width, int height)
{
//стандартный bmp 24 бит
unsigned char * data;
unsigned char R,G,B;
FILE * file;

//загрузка изображения из .bmp файла
file = fopen(filename, "rb");

if(file == NULL)return 0;
//выделяем память под переменную data
data =(unsigned char *)malloc(width * height * 3);
//смещение для пропуска служебных данных
fseek(file,128,0);
//читаем весь файл file в одну переменную data
fread(data, width * height * 3, 1, file);
//закрываем файл
fclose(file);

//переставляем местами R,G,B значения для правильного отображения цвета
int index;
for(int i = 0; i < width * height ; ++i)
	{
	index = i*3;
	B = data[index]; G = data[index+1]; R = data[index+2];
	data[index] = R; data[index+1] = G; data[index+2] = B;
	}

//создаем текстуру из загруженного изображения
glGenTextures(1, &tex);
glBindTexture(GL_TEXTURE_2D, tex);

// фильтрация текстуры

gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

//текстура создана и поэтому теперь можно
//освобождить память от загруженного изображения
free(data);
return 0;

}

#endif // TEXTURES_H_INCLUDED
