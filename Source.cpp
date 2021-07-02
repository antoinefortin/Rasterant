#include <iostream>
#include <fstream>


// Images
const int image_width = 256;
const int image_height = 256;

struct Color
{

public:
    int r, g, b;
    Color()
    {
        r = 0;
        g = 0;
        b = 0;
    }
    Color(int _r, int _g, int _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
};

Color red = Color(255, 0, 0);
Color blue = Color(0, 0, 255);
Color green = Color(0, 255, 0);
Color black = Color(0, 0, 0);

struct Pixel
{
public:
    int x, y;
    Color color;

    Pixel()
    {
        color = black;
        x = 0; 
        y = 0;
    }
    Pixel(int _x, int _y, Color _color)
    {
        x = _x;
        y = _y;
        color = _color;
    }
    
};

class Vertex
{
public:
    int x, y, z;
    Vertex()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vertex(int _x, int _y, int _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

class FrameBuffer
{

public:
    Pixel buffer[256][256];
    FrameBuffer()
    {
        
    }
    void PutPixel(int _locationx, int _locationy, Color _color)
    {
        buffer[_locationx][_locationy].color = _color;
    }

    void InitBuffer()
    {
        for (int i = 0; i < 256; i++)
        {
            for (int j = 0; j < 256; j++)
            {
                buffer[i][j].x = i;
                buffer[i][j].y = j;
                buffer[i][j].color = black;
            }
        }
    }

    void debugBufferIndex(int x, int y)
    {
        std::cout << "Pixel at : " << x << " " << y << std::endl;
        std::cout << "r : " << buffer[x][y].color.r;
        std::cout << " g : " << buffer[x][y].color.g;
        std::cout << " b : " << buffer[x][y].color.b;
    }
};

void ComposeFrame(FrameBuffer *theFrameBuffer)
{
    theFrameBuffer->PutPixel(100, 100, blue);
    theFrameBuffer->PutPixel(101, 100, blue);
    theFrameBuffer->PutPixel(102, 100, blue);
    theFrameBuffer->PutPixel(103, 100, blue);
    theFrameBuffer->PutPixel(104, 100, blue);
    theFrameBuffer->PutPixel(105, 100, blue);
    theFrameBuffer->PutPixel(106, 100, blue);
    // theFrameBuffer->buffer[100][100].color = blue;
}

void Render(FrameBuffer *theFrameBuffer, std::string filePath)
{
    // Create and open a text file
    std::ofstream outputFile(filePath);

    // Write to the file
     "Files can be tricky, but it is fun enough!";
    if (true)
    {
        outputFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";
        for (int j = image_height - 1; j >= 0; --j) {
            for (int i = 0; i < image_width; ++i)
            {
                outputFile << theFrameBuffer->buffer[i][j].color.r << ' '
                           << theFrameBuffer->buffer[i][j].color.g << ' '
                           << theFrameBuffer->buffer[i][j].color.b << '\n';
            }
        }
    }


    // Close the file
    outputFile.close();
}


int main() 
{

    // Init the FrameBuffer
    FrameBuffer *fb = new FrameBuffer();
    fb->InitBuffer();
    ComposeFrame(fb);
    


    // Render Call
    /*
        (0,0) -> Bottom-Left
        (1,1) -> Top-Right
    */

    Render(fb, "outputthing.ppm");

}