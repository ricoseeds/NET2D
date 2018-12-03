#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <math.h>

//glm working
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/vec2.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <CGAL/Simple_cartesian.h>

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

vector<vector<vector<double>>> all_positions;
vector<vector<double>> positions;
static void cursorPositionCallback( GLFWwindow *window, double xpos, double ypos );

void cursorEnterCallback( GLFWwindow *window, int entered );
void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods );
void scrollCallback( GLFWwindow *window, double xoffset, double yoffset );
GLfloat adjustY(double);// y coordinate adjustment
void freeHandSketch(vector<vector<double>> positions);
void drawPoint(double xpos, double ypos);
vector<vector<double>> getGuidingCurve();
void renderGuidingCurve(vector<vector<double>>);
float calculateDistanceOfPointFromStraightLine(float, float, float, float, float);
void createGridVertical(int, int);
void createGridHorizontal(int, int);

int main( void )
{
    GLFWwindow *window;
    // Initialize the library
    if ( !glfwInit( ) )
    {
        return -1;
    }
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "NET2d", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    // Make the window's context current
    glfwMakeContextCurrent( window );
    
    // Setup callbacks
    glfwSetCursorPosCallback( window, cursorPositionCallback );
    glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL );
    glfwSetCursorEnterCallback( window, cursorEnterCallback );
    glfwSetMouseButtonCallback( window, mouseButtonCallback );
    glfwSetInputMode( window, GLFW_STICKY_MOUSE_BUTTONS, 1 );
    glfwSetScrollCallback( window, scrollCallback );

    // OpenGL specifics
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity(); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    vector<vector<double>> guiding_curve = getGuidingCurve();
    // Loop until the user closes the window
    double xpos, ypos;
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        glfwGetCursorPos( window, &xpos, &ypos);

        // Render the guiding curve
        renderGuidingCurve(guiding_curve);
        
        //Draw the grid
        createGridVertical(SCREEN_WIDTH, SCREEN_HEIGHT);
        createGridHorizontal(SCREEN_HEIGHT, SCREEN_WIDTH);
        
        // Draw freehand
        freeHandSketch(positions);
        for( size_t i = 0; i < all_positions.size(); i += 1 ) {
            freeHandSketch(all_positions[i]);
        }
        
        // Swap front and back buffers
        glfwSwapBuffers( window );
    
        // Poll for and process events
        glfwPollEvents( );
    }
    glfwTerminate( );
    return 0;
}

GLfloat adjustY(double yVal){
    return (GLfloat)(-yVal + SCREEN_HEIGHT);
}

void drawPoint(double xpos, double ypos){
    glEnable( GL_POINT_SMOOTH );
    glPointSize( 5 );
    glBegin(GL_POINTS);
    glColor3ub( 255, 0, 0 );
    glVertex2f((GLfloat)xpos, adjustY(ypos));
    glEnd();
}

void freeHandSketch(vector<vector<double>> positions){
    glEnable( GL_POINT_SMOOTH );
//    glBegin(GL_POINTS);
    glBegin(GL_LINE_STRIP);
//    glPointSize( 50 );
//    glLineWidth(10);
    glBegin( GL_POINT );
    glColor3ub( 255, 0, 0 );
    for( size_t i = 0; i < positions.size(); i += 1 ) {
        glVertex2f( (GLfloat)positions[i][0], adjustY(positions[i][1]));
    }
    glEnd();
}

//Render guiding curve
void renderGuidingCurve(vector<vector<double>> curve){
    glEnable( GL_POINT_SMOOTH );
    glBegin(GL_LINE_STRIP);
//    glBegin(GL_POINTS);
//    glBegin( GL_POINT );
//    glPointSize( 100 );
    glColor3ub( 0, 255, 0 );
    for( size_t i = 0; i < curve.size(); i += 1 ) {
        glVertex2f( (GLfloat)(curve[i][0] * 10), adjustY((curve[i][1] * 10)));
    }
    glEnd();
}


static void cursorPositionCallback( GLFWwindow *window, double xpos, double ypos )
{
    std::cout << xpos << " : " << ypos << std::endl;
    // drag positions
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        vector <double> tmppos;
        tmppos.push_back(xpos);
        tmppos.push_back(ypos);
        positions.push_back(tmppos);
        if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
            all_positions.push_back(positions);
            positions.clear();
        }
    }
}

void createGridVertical(int cols, int widthInPixel){
    for( size_t i = 0; i < cols; i += 10 ) {
        glEnable( GL_POINT_SMOOTH );
        glBegin(GL_LINE_STRIP);
        glColor3ub( 0, 0, 255 );
        glVertex2f( (GLfloat) i, adjustY(0.0));
        glVertex2f( (GLfloat) i, adjustY(widthInPixel));
        glEnd();
    }
}

void createGridHorizontal(int rows, int widthInPixel){
    for( size_t i = 0; i < rows; i += 10 ) {
        glEnable( GL_POINT_SMOOTH );
        glBegin(GL_LINE_STRIP);
        glColor3ub( 0, 0, 255 );
        glVertex2f( (GLfloat) 0.0, adjustY(i));
        glVertex2f( (GLfloat) widthInPixel, adjustY(i));
        glEnd();
    }
}
vector<vector<double>> getGuidingCurve(){
    vector<vector<double>> guiding_c;
    const int n = 7;
    double points[n][2] = {
        {10.0, 10.0},
        {15.0, 20.0},
        {20.0, 20.0},
        {25.0, 10.0},
        {30.0, 5.0},
        {35.0, 5.0},
        {40.0, 10.0}
    };
    for (size_t i = 0; i < n; i++) {
        vector<double> each_point;
        for (size_t j = 0; j < 2; j++) {
            each_point.push_back(points[i][j]);
        }
        guiding_c.push_back(each_point);
    }
    return guiding_c;
}

float calculateDistanceOfPointFromStraightLine(float a, float b, float c, float x0, float y0){ // Takes ax + by + c = 0 and (x0, y0)
    // Calculates the distance of a point from a given straight line
    return (float)(a * x0 + b * y0 + c) / sqrt(a * a + b * b);
}



// Callback functions
void cursorEnterCallback( GLFWwindow *window, int entered )
{
    if ( entered ) {
        std::cout << "Entered Window" << std::endl;
    } else {
        std::cout << "Left window" << std::endl;
    }
}

void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods )
{

}

void scrollCallback( GLFWwindow *window, double xoffset, double yoffset )
{
    std::cout << xoffset << " : " << yoffset << std::endl;
}
