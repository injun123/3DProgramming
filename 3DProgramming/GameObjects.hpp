#pragma once

struct vertex
{
    float x, y;
    float r, g, b, a;
};


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



class MagicCircle
{
public:
    MagicCircle() {}
    ~MagicCircle() {}

    vertex star[5];

    void Init()
    {
        
        /// Star(오망성) 생성
        int i = 0;
        for (float theta = 0; theta < 360; theta += 72)
        {

            star[i].x = -glm::sin(glm::radians(theta)) * 0.5;
            star[i].y = glm::cos(glm::radians(theta)) * 0.5;

            star[i].r = 0.3f;
            star[i].g = 0.0f;
            star[i].b = 1.0f;
            star[i].a = 0.7f;

            i++;
        }
    }

    void Update()
    {}

    //drawCircle로 그린 원이 외접하도록 오망성을 그리시오
    void drawStar()
    {
        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);
        
        
        int a = 0;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        a = 3;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        a = 1;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        a = 4;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        a = 2;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        
        a = 0;
        glColor4f(v[a].r, v[a].g, v[a].b, v[a].a);
        glVertex3f(v[a].x, v[a].y, 0.0f);
        glEnd();
    }


    void drawEffect()
    {
        glLineWidth(3.0f);
        glBegin(GL_TRIANGLE_STRIP);
        
        vertex v[4][36];
        
        for (int layer = 0; layer < 4; layer++)
        {
            int i = 0;
            for (float theta = 180; theta < 360; theta += 5)
            {

                v[layer][i].x = -glm::sin(glm::radians(theta)) * 0.5;
                v[layer][i].y = glm::cos(glm::radians(theta)) * 0.5;

                v[layer][i].r = 0.3f;
                v[layer][i].g = 0.0f;
                v[layer][i].b = 1.0f;
                v[layer][i].a = 0.3f;

                i++;
            }
        }

        glEnd();
    }

    // 지름이 0.5인 원을 그리시오. 중점은 0,0 입니다.
    void drawCircle()
    {
        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);
        
        float x, y;
        for (float theta = 0; theta < 360; theta++)
        {
            x = - glm::sin(glm::radians(theta)) * 0.5;
            y = glm::cos(glm::radians(theta)) * 0.5;

            glColor4f(0.3f, 0.0f, 1.0f, 0.7f);
            glVertex3f(x, y, 0.0f);

        }
        glEnd();
    }

    void draw()
    {
        drawCircle();
        drawStar();
    }
};