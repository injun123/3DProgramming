#pragma once

class FireBall
{
public:
    FireBall() {}
    ~FireBall() {}

    void draw()
    {
        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);

        /*glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, -0.75f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.5f, 0.25f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f, 0.25f, 0.0f);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, -0.75f, 0.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);*/

        float x, y;
        for (float theta = 0; theta < 360; theta++)
        {
            x = glm::sin(glm::radians(theta)) * 0.5;
            y = glm::cos(glm::radians(theta)) * 0.5;

            glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            glVertex3f(x, y, 0.0f);

        }
        glEnd();
    }
};