#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

using namespace std;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static void cursorPositionCallback( GLFWwindow *window, double xpos, double ypos );
void cursorEnterCallback( GLFWwindow *window, int entered );
void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods );
void scrollCallback( GLFWwindow *window, double xoffset, double yoffset );


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
    //
    glfwSetCursorPosCallback( window, cursorPositionCallback );
    glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_NORMAL );
    
    glfwSetCursorEnterCallback( window, cursorEnterCallback );
    
    glfwSetMouseButtonCallback( window, mouseButtonCallback );
    glfwSetInputMode( window, GLFW_STICKY_MOUSE_BUTTONS, 1 );
    
    glfwSetScrollCallback( window, scrollCallback );
    //
    
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT ); // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode( GL_PROJECTION ); // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity( ); // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 ); // essentially set coordinate system
    glMatrixMode( GL_MODELVIEW ); // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    //glLoadIdentity( ); // same as above comment
    
//    GLfloat pointVertex[] = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
//    GLfloat pointVertex2[] = {};
    vector<vector<double>> postions;
    // Loop until the user closes the window
    while ( !glfwWindowShouldClose( window ) )
    {
        glClear( GL_COLOR_BUFFER_BIT );
        
        // Render OpenGL here
        //glEnable( GL_POINT_SMOOTH ); // make the point circular
        //glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
//        glPointSize( 5 ); // must be added before glDrawArrays is called
//        glVertexPointer( 2, GL_FLOAT, 0, pointVertex ); // point to the vertices to be used
//        glDrawArrays( GL_POINTS, 0, 1 ); // draw the vertixes
//        glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
//        glDisable( GL_POINT_SMOOTH ); // stop the smoothing to make the points circular
//
        double xpos, ypos;
        glfwGetCursorPos( window, &xpos, &ypos);
        
        vector <double> tmppos;
        tmppos.push_back(xpos);
        tmppos.push_back(ypos);
        postions.push_back(tmppos);
        
        std::cout << tmppos[0] << " : " << tmppos[1] << std::endl;
        glEnable( GL_POINT_SMOOTH );
        //glEnableClientState( GL_VERTEX_ARRAY );
//        glVertexPointer(<#GLint size#>, <#GLenum type#>, <#GLsizei stride#>, <#const void *pointer#>)
//        glDrawArrays(<#GLenum mode#>, <#GLint first#>, <#GLsizei count#>)
        //glVertexPointer(2, GL_FLOAT, 0, pointVertex2);
        
        
        glPointSize( 5 );
        
        glBegin(GL_POINTS);
        glColor4f(1,1,1,1);
        glVertex2f((GLfloat)xpos,(GLfloat) ( -ypos + SCREEN_HEIGHT));
        glEnd();
        
        glBegin( GL_LINE_STRIP );
        glColor3ub( 255, 0, 0 );
        for( size_t i = 0; i < postions.size(); i += 2 )
        {
            glVertex2f( (GLfloat)postions[i][0], (GLfloat)postions[i][1]);
        }
        glEnd();
        // glVertex3f(<#GLfloat x#>, <#GLfloat y#>, <#GLfloat z#>)
        //glDrawArrays(GL_POINTS, 0, 2);
        //glDisableClientState( GL_VERTEX_ARRAY );
//        glEnableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're using a vertex array for fixed-function attribute
//        glVertexPointer( 2, GL_FLOAT, 0, pointVertex2 ); // point to the vertices to be used
//        glPointSize( 10 ); // must be added before glDrawArrays is called
//        glDrawArrays( GL_POINTS, 0, 1 ); // draw the vertixes
//        glDisableClientState( GL_VERTEX_ARRAY ); // tell OpenGL that you're finished using the vertex arrayattribute
//
//        // Swap front and back buffers
        glfwSwapBuffers( window );
        
        // Poll for and process events
        glfwPollEvents( );
    }
    
    glfwTerminate( );
    
    return 0;
}

static void cursorPositionCallback( GLFWwindow *window, double xpos, double ypos )
{
    //std::cout << xpos << " : " << ypos << std::endl;
}

void cursorEnterCallback( GLFWwindow *window, int entered )
{
    if ( entered )
    {
        std::cout << "Entered Window" << std::endl;
    }
    else
    {
        std::cout << "Left window" << std::endl;
    }
}

void mouseButtonCallback( GLFWwindow *window, int button, int action, int mods )
{
    if ( button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS )
    {
        std::cout << "Right button pressed" << std::endl;
    }
}

void scrollCallback( GLFWwindow *window, double xoffset, double yoffset )
{
    std::cout << xoffset << " : " << yoffset << std::endl;
}
