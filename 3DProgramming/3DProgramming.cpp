#include <chrono>
#include <thread>
#include <string>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "GameObjects.hpp"

#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
MagicCircle* f;

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    startRenderTimePoint = chrono::system_clock::now();
    f = new MagicCircle();
}

void Release()
{
    delete(f);

    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);

        ////90도와 같이 각도로 연산하고 싶으면
        ////glm의 삼각함수는 radian 형식으로 입력을 받기 때문에 변환해서 넣어주어야한다.
        //glm::sin(glm::radians(90.0));  

        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        f->draw();

        /* glLineWidth(7.0f);

         float x, y;
         glBegin(GL_LINE_STRIP);
         for (float theta = 0; theta < 360; theta++)
         {
             x = glm::sin(glm::radians(theta)) * 0.5;
             y = glm::cos(glm::radians(theta)) * 0.5;

             glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
             glVertex3f(x, y, 0.0f);

         }
         glEnd();*/

        glfwSwapBuffers(window);
        glfwPollEvents();

        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();
        string fps = "FPS : " + to_string(1.0 / renderDuration.count());
        cRenderer.DrawString(fps);

        this_thread::sleep_for(chrono::milliseconds(20));
    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init(); 
    Update();
    Release();    
    
    exit(EXIT_SUCCESS);
}