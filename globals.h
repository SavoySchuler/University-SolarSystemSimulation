#include "Planet.h"

// function prototypes
void OpenGLInit( void );
void Animate( void );
void Key_r( void );
void Key_s( void );
void Key_up( void );
void Key_down( void );
void ResizeWindow( int w, int h );
void KeyPressFunc( unsigned char Key, int x, int y );
void SpecialKeyFunc( int Key, int x, int y );
void DrawSun();
void SetLightModel();
void HandleRotate();
void DrawMoon(int DayOfYear);
void DrawPlanet(Planet *plant);
void DrawSun(Planet *sun);

int loadTextureFromFile( char *filename );
void initTextureMap( char *filename );
void makeTexture( GLubyte image[64][64][3] );
void DrawTextString( string str, double radius);
char * stringToChar (string str);

// these three variables control the animation's state and speed.
const float DistScale = 1.0/37.5;
const float SizeScale = 1.0/15945.0;


typedef unsigned char byte;

bool LoadBmpFile( const char* filename, int &nrows, int &ncols, byte* &image );
void skipChars( FILE* infile, int numChars );
short readShort( FILE* infile );
static inline int GetNumBytesPerRow( int NumCols );
int setTexture( byte* image, int rows, int ncols );



// global variables
extern GLenum spinMode;
extern GLenum singleStep;

extern float HourOfDay;
extern float DayOfYear;
extern float MercuryHour;
extern float MercuryDay;
extern float AnimateIncrement;  // Time step for animation (hours)
extern float Xpan;
extern float Ypan;
extern float Zpan;
extern float Xrot;
extern float Yrot;
extern float Zrot;
